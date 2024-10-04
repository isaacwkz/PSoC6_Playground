#include "common.h"

#include "USB.h"
#include "USB_HID.h"

#define VENDOR_ID  0x058B /* For Infineon Technologies */
#define PRODUCT_ID 0x0274 /* Procured PID for HID Generic device */

#define INPUT_REPORT_SIZE  64   /* Defines the input (device -> host) report size */
#define OUTPUT_REPORT_SIZE 64   /* Defines the output (Host -> device) report size */
#define VENDOR_PAGE_ID     0x12 /* Defines the vendor specific page that */
																/* shall be used, allowed values 0x00 - 0xff */
																/* This value must be identical to HOST application */

static void usbd_hid_init(void);
static void usbd_hid_echo_task(void);

static const USB_DEVICE_INFO device_info = {
	VENDOR_ID,                          /* VendorId */
	PRODUCT_ID,                         /* ProductId */
	"Infineon Technologies",            /* VendorName */
	"HID 64-byte Generic emUSB device", /* ProductName */
	"12345678"                          /* SerialNumber */
};

static const U8 usb_hid_generic_report[] = {
	0x06, VENDOR_PAGE_ID,
	0xFF,       /* USAGE_PAGE (Vendor Defined Page 1) */
	0x09, 0x01, /* USAGE (Vendor Usage 1) */
	0xa1, 0x01, /* COLLECTION (Application) */
	0x05, 0x06, /* USAGE_PAGE (Generic Device) */
	0x09, 0x00, /* USAGE (Undefined) */
	0x15, 0x00, /* LOGICAL_MINIMUM (0) */
	0x26, 0xFF,
	0x00,                    /* LOGICAL_MAXIMUM (255) */
	0x95, INPUT_REPORT_SIZE, /* REPORT_COUNT (64) -- Number of packets */
	0x75, 0x08,              /* REPORT_SIZE (8) -- Size of each packet */
	0x81, 0x02,              /* INPUT (Data,Var,Abs) */
	0x05, 0x06,              /* USAGE_PAGE (Generic Device) */
	0x09, 0x00,              /* USAGE (Undefined) */
	0x15, 0x00,              /* LOGICAL_MINIMUM (0) */
	0x26, 0xFF,
	0x00,                     /* LOGICAL_MAXIMUM (255) */
	0x95, OUTPUT_REPORT_SIZE, /* REPORT_COUNT (64) */
	0x75, 0x08,               /* REPORT_SIZE (8) */
	0x91, 0x02,               /* OUTPUT (Data,Var,Abs) */
	0xc0                      /* END_COLLECTION */
};

static int8_t         hid_data_buffer[USB_HS_INT_MAX_PACKET_SIZE];
static USB_HID_HANDLE hid_instance_handle;

void usb_stack_init(void) {
	/* Initialize the emUSB device stack */
	USBD_Init();
	/* Initialize the endpoint for HID class */
	usbd_hid_init();
	/* Set the device info for enumeration*/
	USBD_SetDeviceInfo(&device_info);
	/* Start the USB stack*/
	USBD_Start();

	usbd_hid_echo_task();
}

static void usbd_hid_init(void) {
	static uint8_t       out_buffer[USB_HS_INT_MAX_PACKET_SIZE];
	USB_HID_INIT_DATA_EX init_data;
	USB_ADD_EP_INFO      ep_int_in;
	USB_ADD_EP_INFO      ep_int_out;

	memset(&init_data, 0, sizeof(init_data));
	ep_int_in.Flags         = 0;                          /* Flags not used. */
	ep_int_in.InDir         = USB_DIR_IN;                 /* IN direction (Device to Host) */
	ep_int_in.Interval      = 1;                          /* Interval of 125 us (1 ms in full-speed) */
	ep_int_in.MaxPacketSize = USB_HS_INT_MAX_PACKET_SIZE; /* Maximum packet size (64 for Interrupt). */
	ep_int_in.TransferType  = USB_TRANSFER_TYPE_INT;      /* Endpoint type - Interrupt. */
	init_data.EPIn          = USBD_AddEPEx(&ep_int_in, NULL, 0);

	ep_int_out.Flags         = 0;                          /* Flags not used. */
	ep_int_out.InDir         = USB_DIR_OUT;                /* OUT direction (Host to Device) */
	ep_int_out.Interval      = 1;                          /* Interval of 125 us (1 ms in full-speed) */
	ep_int_out.MaxPacketSize = USB_HS_INT_MAX_PACKET_SIZE; /* Maximum packet size (64 for Interrupt). */
	ep_int_out.TransferType  = USB_TRANSFER_TYPE_INT;      /* Endpoint type - Interrupt. */
	init_data.EPOut          = USBD_AddEPEx(&ep_int_out, out_buffer, sizeof(out_buffer));

	init_data.pReport        = usb_hid_generic_report;
	init_data.NumBytesReport = sizeof(usb_hid_generic_report);
	init_data.pInterfaceName = "HID raw";
	hid_instance_handle      = USBD_HID_AddEx(&init_data);
}

static void usbd_hid_echo_task(void) {
	int8_t check_read  = 0;
	int8_t check_write = 0;

	for (uint32_t i = 0; i < USB_HS_INT_MAX_PACKET_SIZE; i++) {
		/* Wait for configuration */
		while ((USBD_GetState() & USB_STAT_CONFIGURED) != USB_STAT_CONFIGURED) {
			/* Ready to Read and Write HID messages. */
			/* Waiting for USB_STAT_CONFIGURED */

			cyhal_system_delay_ms(500);
			cyhal_gpio_write(CYBSP_USER_LED, CYBSP_LED_STATE_ON);

			cyhal_system_delay_ms(500);
			cyhal_gpio_write(CYBSP_USER_LED, CYBSP_LED_STATE_OFF);

			LOG_INFO("Waiting for connection...\n");
		}

		check_read = USBD_HID_Read(hid_instance_handle, &hid_data_buffer, OUTPUT_REPORT_SIZE, 0);

		if (OUTPUT_REPORT_SIZE == check_read) {
			LOG_INFO("\nRequested data was successfully read within the given timeout\n\n");
		} else if ((check_read >= 0) && (check_read < OUTPUT_REPORT_SIZE)) {
			LOG_INFO("Timeout has occurred. Number of bytes that have been read within the given timeout: %d", check_read);
		} else {
			LOG_INFO("Failed to read\n\n");
		}
		check_write = USBD_HID_Write(hid_instance_handle, &hid_data_buffer, INPUT_REPORT_SIZE, 0);

		if (INPUT_REPORT_SIZE == check_write) {
			LOG_INFO("Write transfer successfully completed\n\n");
		} else if (0 == check_write) {
			LOG_INFO(
				"Successful started an asynchronous write transfer or a timeout has occurred and no data was written.\n\n");
		} else if ((check_write > 0) && (check_write < INPUT_REPORT_SIZE)) {
			LOG_INFO(
				"Timeout has occurred. Number of bytes that have been written within the given timeout: %d", check_write);
		} else {
			LOG_INFO("Failed to write\n\n");
		}
	}
}
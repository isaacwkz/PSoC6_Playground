#include "common.h"
#include "USB_CDC.h"

USB_CDC_HANDLE usb_cdc_dev;

static TX_SEMAPHORE usb_read_done;
static uint16_t     usb_read_sz = 0;

#define VENDOR_ID  0x058B
#define PRODUCT_ID 0x0274

static const USB_DEVICE_INFO device_info = {
	0xCAFE,             /* VendorId */
	0xF00D,             /* ProductId */
	"isaacwkz",         /* VendorName */
	"PSoC6 AI DK Demo", /* ProductName */
	"1234567890"        /* SerialNumber */
};

static void add_cdc(void);

void usb_stack_init(void) {
	LOG_INFO("Init USB\n\r");
	USBD_Init();
	LOG_INFO("Enable IAD\n\r");
	USBD_EnableIAD();
	add_cdc();
	LOG_INFO("Setting device info\n\r");
	USBD_SetDeviceInfo(&device_info);
	LOG_INFO("Start USB stack!\n\r");
	USBD_Start();
}

//------------------------- USB CDC Stuffs ------------------------//
static uint8_t OutBuffer[USB_FS_BULK_MAX_PACKET_SIZE];

static void add_cdc(void) {
	USB_CDC_INIT_DATA cdc_info = {0};

	USB_ADD_EP_INFO ep_int_in;
	USB_ADD_EP_INFO ep_int_int;
	USB_ADD_EP_INFO ep_int_out;
	ep_int_in.Flags         = 0;
	ep_int_in.InDir         = USB_DIR_IN;
	ep_int_in.Interval      = 0;
	ep_int_in.MaxPacketSize = USB_FS_BULK_MAX_PACKET_SIZE;
	ep_int_in.TransferType  = USB_TRANSFER_TYPE_BULK;
	cdc_info.EPIn           = USBD_AddEPEx(&ep_int_in, NULL, 0);

	ep_int_out.Flags         = 0;
	ep_int_out.InDir         = USB_DIR_OUT;
	ep_int_out.Interval      = 0;
	ep_int_out.MaxPacketSize = USB_FS_BULK_MAX_PACKET_SIZE;
	ep_int_out.TransferType  = USB_TRANSFER_TYPE_BULK;
	cdc_info.EPOut           = USBD_AddEPEx(&ep_int_out, OutBuffer, sizeof(OutBuffer));

	ep_int_int.Flags         = 0;
	ep_int_int.InDir         = USB_DIR_IN;
	ep_int_int.Interval      = 40;
	ep_int_int.MaxPacketSize = USB_FS_INT_MAX_PACKET_SIZE;
	ep_int_int.TransferType  = USB_TRANSFER_TYPE_INT;
	cdc_info.EPInt           = USBD_AddEPEx(&ep_int_int, NULL, 0);

	if (!(cdc_info.EPIn && cdc_info.EPOut && cdc_info.EPInt)) {
		LOG_INFO("Endpoint allocation failed\n\r");
	}
	LOG_INFO("Adding CDC iface\n\r");
	usb_cdc_dev = USBD_CDC_Add(&cdc_info);

	tx_semaphore_create(&usb_read_done, "USB read done", 0);
}

static void USBD_CDC_ReadDoneCB(USB_ASYNC_IO_CONTEXT_POI pContext) {
	usb_read_sz = pContext->NumBytesTransferred;
	tx_semaphore_put(pContext->pContext);
}

void usb_cdc_echo(void) {
	char rx_buf[USB_FS_BULK_MAX_PACKET_SIZE] = {0};

	USB_ASYNC_IO_CONTEXT rd_ctx;
	rd_ctx.NumBytesToTransfer = USB_FS_BULK_MAX_PACKET_SIZE;
	rd_ctx.pData              = rx_buf;
	rd_ctx.pContext           = &usb_read_done;
	rd_ctx.pfOnComplete       = USBD_CDC_ReadDoneCB;

	USBD_CDC_ReadAsync(usb_cdc_dev, &rd_ctx, 1);
	if (tx_semaphore_get(&usb_read_done, TX_WAIT_FOREVER) == TX_SUCCESS) {
		if (usb_read_sz > 0) {
			USBD_CDC_Write(usb_cdc_dev, rx_buf, usb_read_sz, -1);
		}
	}
}
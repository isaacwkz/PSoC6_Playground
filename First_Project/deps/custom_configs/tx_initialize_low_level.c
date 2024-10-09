// #include "core_cm4.h"
// #include "cy8c624abzi_d44.h"

extern void *_tx_thread_system_stack_ptr;
extern void *_tx_initialize_unused_memory;

extern void *__ramVectors;
extern void *__Vectors;
extern void *__RAM_segment_used_end__;

extern void *__StackTop;

void *stack_ptr;

#define SYSTEM_CLOCK   144000000
#define TX_TICK_RATE   1000
#define SYSTICK_CYCLES ((SYSTEM_CLOCK / TX_TICK_RATE) - 1)

extern void _tx_timer_interrupt(void);

void SysTick_Handler(void);

void _tx_initialize_low_level(void) {
	// Disable all the interrupts
	__asm volatile("cpsid i" : : : "memory");
	// Setup first unused memory pointer
	unsigned int ram_segment_used_end_address = (unsigned int)&__RAM_segment_used_end__;
	ram_segment_used_end_address += 4;
	_tx_initialize_unused_memory = (void *)ram_segment_used_end_address;

	// Set vector table address
	// SCB->VTOR = __ramVectors;
	*((volatile unsigned int *)0xE000ED08) = (unsigned int)(void *)&__ramVectors;
	// Save system stack pointer
	stack_ptr                   = (void *)&__ramVectors;
	_tx_thread_system_stack_ptr = &stack_ptr;

	// Set the CYCCNTENA bit
	// Enable the cycle count register
	// DWT->CTRL |= 1;
	*((volatile unsigned int *)0xE0001000) |= 1;
	// Setup SysTick Reload Value
	// SysTick->LOAD = SYSTICK_CYCLES;
	*((volatile unsigned int *)0xE000E014) = SYSTICK_CYCLES;
	// 2:   0 = SysTick uses the implementation defined external reference clock.
	//      1 = SysTick uses the processor clock.
	// 1:   0 = Count to 0 does not affect the SysTick exception status.
	//      1 = Count to 0 changes the SysTick exception status to pending.
	// 0:   0 = Counter is disabled
	//      1 = Counter is operating.
	// SysTick->CTRL |= 7;
	*((volatile unsigned int *)0xE000E010) |= 7;

	// Configure handler priorities
	*((volatile unsigned int *)0xE000ED18) = 0;
	*((volatile unsigned int *)0xE000ED1C) = 0xFF000000;
	*((volatile unsigned int *)0xE000ED20) = 0x40FF0000;

	// Redirect Systick_Handler to TX implementation
	// NVIC_SetVector(SysTick_IRQn, SysTick_Handler);
	unsigned int *vectors        = (unsigned int *)*((volatile unsigned int *)0xE000ED08);
	vectors[(signed int)-1 + 16] = (unsigned int)SysTick_Handler;
}

void InterruptHandler(void) {
#ifdef TX_ENABLE_EXECUTION_CHANGE_NOTIFY
	_tx_execution_isr_enter();
#endif
#ifdef TX_ENABLE_EXECUTION_CHANGE_NOTIFY
	_tx_execution_isr_exit();
#endif
}

void __tx_IntHandler(void) {
#ifdef TX_ENABLE_EXECUTION_CHANGE_NOTIFY
	_tx_execution_isr_enter();
#endif
#ifdef TX_ENABLE_EXECUTION_CHANGE_NOTIFY
	_tx_execution_isr_exit();
#endif
}

// System Tick timer interrupt handler

extern void        _tx_timer_interrupt();
static inline void SystickHandlerHelper(void) {
#ifdef TX_ENABLE_EXECUTION_CHANGE_NOTIFY
	_tx_execution_isr_enter();
#endif

	// See tx_timer_interrupt.S in threadx/ports/cortex_m4/gnu/src
	_tx_timer_interrupt();

#ifdef TX_ENABLE_EXECUTION_CHANGE_NOTIFY
	_tx_execution_isr_exit();
#endif
}

void __tx_SysTickHandler(void) { SystickHandlerHelper(); }
void SysTick_Handler(void) { SystickHandlerHelper(); }

void __tx_BadHandler(void) {
	while (1) {
	}
}

void __tx_HardfaultHandler(void) {
	while (1) {
	}
}

void __tx_SVCallHandler(void) {
	while (1) {
	}
}

void __tx_NMIHandler(void) {
	while (1) {
	}
}

void __tx_DBGHandler(void) {
	while (1) {
	}
}
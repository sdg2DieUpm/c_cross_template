/**
 ******************************************************************************
 * @file           : interr.c
 * @brief          : Interrupt Service Routines (ISR) for STM32F4xx microcontrollers.
 ******************************************************************************
 */


// Include headers of different port elements:
#include "port_system.h"
#include "stm32f4xx.h"

// Preprocessor directives to mark the following function as an ISR
#define STRINGIFY(a) #a
#define ISR(a) \
_Pragma( STRINGIFY(GCC push_options)) \
_Pragma( STRINGIFY(GCC target("general-regs-only"))) \
void a(void) __attribute__((isr)); \
_Pragma( STRINGIFY(GCC pop_options))

/**
 * @brief Interrupt service routine for the System tick timer (SysTick).
 * 
 * @note This ISR is called when the SysTick timer generates an interrupt.
 * The program flow jumps to this ISR and increments the tick counter by one millisecond.
 * 
 * @warning You must mark this function as an ISR, otherwise the program can
 * potentially crash under very specific circumstances.
 */
ISR(SysTick_Handler)
void SysTick_Handler(void)
{
  port_system_set_millis(port_system_get_millis() + 1);
}

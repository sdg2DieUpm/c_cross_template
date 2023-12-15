/**
 ******************************************************************************
 * @file           : interr.c
 * @brief          : Interrupt Service Routines (ISR) for STM32F4xx microcontrollers.
 ******************************************************************************
 */


// Include headers of different port elements:
#include "port_system.h"
#include "stm32f4xx.h"

/**
 * @brief Interrupt service routine for the System tick timer (SysTick).
 * 
 * @note This ISR is called when the SysTick timer generates an interrupt.
 * The program flow jumps to this ISR and increments the tick counter by one millisecond.
 */
void SysTick_Handler(void)
{
  port_system_set_millis(port_system_get_millis() + 1);
}

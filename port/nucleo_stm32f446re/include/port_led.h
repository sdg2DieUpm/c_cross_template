/**
 ******************************************************************************
 * @file           : port_led.h
 * @brief          : Header for port_led.c file.
 ******************************************************************************
 * @attention
 *
 * Román Cárdenas Rodríguez (r.cardenas@upm.es)
 * Sistemas Digitales II
 *
 ******************************************************************************
 */

#ifndef PORT_LED_H_
#define PORT_LED_H_

#include <stdbool.h>

/**
 * @brief  Configures the GPIO port connected to the LED.
 * @retval 0 if OK, -1 otherwise
 */
int port_led_gpio_setup(void);

/**
 * @brief  Gets the current state of the LED.
 * @retval true if the LED is on, false otherwise
*/
bool port_led_get(void);

/**
 * @brief  Sets the LED state.
 * @param  state: true to turn the LED on, false to turn it off
 * @retval 0 if OK, -1 otherwise
 */
int port_led_on(void);

/**
 * @brief  Sets the LED state.
 * @param  state: true to turn the LED on, false to turn it off
 * @retval 0 if OK, -1 otherwise
 */
int port_led_off(void);

/**
 * @brief  Toggles the LED state.
 * @retval 0 if OK, -1 otherwise
 */
int port_led_toggle(void);

#endif // PORT_LED_H_

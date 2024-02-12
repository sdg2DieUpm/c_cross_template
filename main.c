/**
 * @file main.c
 * @author Josué Pagán (j.pagan@upm.es)
 * @author Román Cárdenas (r.cardenas@upm.es)
 * @brief Main file of the program.
 * @date 01-01-2024
 *
 */

/* Standard C includes */
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

/* HW dependent includes */
#include "port_system.h"
#include "port_led.h"

/* Other includes */
#include <fsm.h>

#define BLINK_T_MS 2000 /*!< Blink LED period in ms */

/**
 * @brief Main function. Entry point of the program.
 *
 * @return int Status of the execution.
 */
int main()
{
    port_system_init();    // Initialize the system
    port_led_gpio_setup(); // Configure the LED GPIO

    uint32_t t = port_system_get_millis(); // t is the current time in milliseconds
    while (1)
    {
        port_led_toggle();                              // Blink the LED
        port_system_delay_until_ms(&t, BLINK_T_MS / 2); // Wait for the period of the FSM
    }
    return 0;
}

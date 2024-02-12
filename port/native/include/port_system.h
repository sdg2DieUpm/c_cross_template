/**
 * @file port_system.h
 * @author Josué Pagán Ortiz (j.pagan@upm.es)
 * @brief Header for port_system.c file.
 * @date 01-01-2024
 */

#ifndef PORT_SYSTEM_H_
#define PORT_SYSTEM_H_

/* Includes ------------------------------------------------------------------*/
/* Standard C includes */
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/time.h>

/* Function prototypes and explanation -------------------------------------------------*/
/**
 * @brief Initializes the system.
 *
 * @return uint32_t 0 if the system was initialized successfully, a non-zero value otherwise.
 */
size_t port_system_init(void);

/**
 * @brief Gets the current time in milliseconds.
 *
 * @return uint32_t The current time in milliseconds.
 */
uint32_t port_system_get_millis(void);

/**
 * @brief Delays the program execution for the specified number of milliseconds.
 *
 * @param ms Number of milliseconds to delay.
 */
void port_system_delay_ms(uint32_t ms);

/**
 * @brief Delays the program execution until the specified number of milliseconds since the system started.
 *
 * @param t Pointer to the variable that stores the number of milliseconds to delay until.
 * @param ms Number of milliseconds to delay until.
 *
 * @note This function modifies the value of the variable pointed by t to the number of milliseconds to delay until.
 * @note This function is useful to implement periodic tasks.
 */
void port_system_delay_until_ms(uint32_t *t, uint32_t ms);

#endif // PORT_SYSTEM_H_

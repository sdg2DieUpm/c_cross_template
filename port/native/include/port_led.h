#ifndef PORT_LED_H_
#define PORT_LED_H_

/* Includes del sistema */
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

/* Includes del sistema */
#include "port_system.h"

/**
 * @brief Configura el GPIO para el LED
 * 
 * @return int 0 si todo fue bien, -1 si hubo un error
 */
int port_led_gpio_setup(void);

/**
 * @brief Devuelve el estado del LED
 * 
 * @return true si el LED está encendido
 * @return false si el LED está apagado
 */
bool port_led_get(void);

/**
 * @brief Enciende el LED
 * 
 * @return int 0 si todo fue bien, -1 si hubo un error
 */
int port_led_on(void);

/**
 * @brief Apaga el LED
 * 
 * @return int 0 si todo fue bien, -1 si hubo un error
 */
int port_led_off(void);

/**
 * @brief Invierte el estado del LED
 * 
 * @return int 0 si todo fue bien, -1 si hubo un error
 */
int port_led_toggle(void);

#endif // PORT_LED_H_

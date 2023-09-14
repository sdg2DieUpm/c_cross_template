/**
 ******************************************************************************
 * @file           : port_retina.h
 * @brief          : Header for port_retina.c file. Lo que tenga que ver con HW externo que controle la FSM principal del proyecto RETINA.
 ******************************************************************************
 * @attention
 *
 * Josue Pagán Ortiz (j.pagan@upm.es)
 * Sistemas Digitales II
 * All rights reserved.
 *
 *
 ******************************************************************************
 */

#ifndef PORT_BLINK_H_
#define PORT_BLINK_H_

/* Includes del sistema */
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

/* Includes del sistema */
#include "port_system.h"

size_t port_blink_gpio_setup(void);
void port_blink_toggle_board_led(void);

#endif

#ifndef PORT_BLINK_H_
#define PORT_BLINK_H_

/* Includes del sistema */
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

/* Includes del sistema */
#include "port_system.h"

int port_led_gpio_setup(void);
bool port_led_get(void);
int port_led_on(void);
int port_led_off(void);
int port_led_toggle(void);

#endif

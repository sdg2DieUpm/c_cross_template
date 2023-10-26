#ifndef PORT_LED_H_
#define PORT_LED_H_

#include <stdbool.h>

int port_led_gpio_setup(void);
bool port_led_get(void);
int port_led_on(void);
int port_led_off(void);
int port_led_toggle(void);

#endif // PORT_LED_H_

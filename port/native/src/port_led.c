#include "port_led.h"

typedef enum
{
    UNCONFIGURED = -1,
    OUTPUT = 0,
    INPUT = 1,
} LED_GPIO_CONFIG;

typedef struct
{
    LED_GPIO_CONFIG config;
    bool status;
} led_gpio_t;

static led_gpio_t led_gpio = {
    .config = UNCONFIGURED,
    .status = false,
};

void port_led_gpio_setup()
{
    if (led_gpio.config == UNCONFIGURED)
    {
        printf("[%lld] LED clock enabled\n", (long long)port_system_get_millis());
    }
    if (led_gpio.config != OUTPUT)
    {
        led_gpio.config = OUTPUT;
        printf("[%lld] LED pin mode configured mode as output\n", (long long)port_system_get_millis());
        printf("[%lld] LED pin pull up/down configuration as no PUPD\n", (long long)port_system_get_millis());
    }
    fflush(stdout);
}

bool port_led_get()
{
    return led_gpio.status;
}

void port_led_on()
{
    if (led_gpio.config == OUTPUT)
    {
        led_gpio.status = true;
        printf("[%lld] LED ON\n", (long long)port_system_get_millis());
        fflush(stdout);
    }
    else
    {
        printf("[%lld] LED not configured as output\n", (long long)port_system_get_millis());
        fflush(stdout);
    }
}

void port_led_off()
{
    if (led_gpio.config == OUTPUT)
    {
        printf("[%lld] LED OFF\n", (long long)port_system_get_millis());
        fflush(stdout);
        led_gpio.status = false;
    }
    else
    {
        printf("[%lld] LED not configured as output\n", (long long)port_system_get_millis());
        fflush(stdout);
    }
}

/**
 * @brief Board toggle led
 *
 */
void port_led_toggle()
{
    (port_led_get()) ? port_led_off() : port_led_on();
}

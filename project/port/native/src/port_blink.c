#include "port_blink.h"

/**
 * @brief Board toggle led
 *
 */
void port_blink_toggle_board_led()
{
    static bool led_status = false;
    if (!led_status)
    {
        led_status = true;
        printf("[%lld] LED ON\n", (long long)port_system_get_millis());
    }
    else 
    {
        led_status = false;
        printf("[%lld] LED OFF\n", (long long)port_system_get_millis());
    }

    fflush(stdout); // Force output
}

size_t port_blink_gpio_setup()
{
    return 0;
}

#include <stdio.h>
#include "port_led.h"
#include "port_system.h"

/* HW dependent includes */
#include "stm32f4xx.h"
#include "stm32f4_system.h"

// HW Nucleo-STM32F446RE:


#define LD2_PIN 5
#define LD2_GPIO_PORT GPIOA

#define MODER5_MASK (GPIO_MODER_MODE0 << LD2_PIN * 2) /* Cada pin ocupa 2 bits */
#define PUPDR5_MASK (GPIO_PUPDR_PUPD0 << LD2_PIN * 2) /* Cada pin ocupa 2 bits */

#define MODER5_AS_OUTPUT (GPIO_MODE_OUT << LD2_PIN * 2) /* Cada pin ocupa 2 bits */
#define PUPDR5_AS_NOPUPD (GPIO_PUPDR_NOPULL << LD2_PIN * 2) /* Cada pin ocupa 2 bits */

#define IDR5_MASK (GPIO_IDR_ID0 << LD2_PIN) /* Cada pin ocupa 1 bit */
#define ODR5_MASK (GPIO_ODR_OD0 << LD2_PIN) /* Cada pin ocupa 1 bit */


void port_led_gpio_setup(void)
{
    /* Primero , habilitamos siempre el reloj de los perifericos */
    RCC -> AHB1ENR |= RCC_AHB1ENR_GPIOAEN ;
    /* Luego , limpiamos los registros MODER y PUPDR correspondientes */
    LD2_GPIO_PORT -> MODER &= ~ MODER5_MASK ;
    LD2_GPIO_PORT -> PUPDR &= ~ PUPDR5_MASK ;
    /* Finalmente , configuramos el LED como salida sin pull up/ pull down */
    LD2_GPIO_PORT -> MODER |= MODER5_AS_OUTPUT ;
    LD2_GPIO_PORT -> PUPDR |= PUPDR5_AS_NOPUPD ;
}

bool port_led_get(void)
{
    return (LD2_GPIO_PORT->IDR & IDR5_MASK) != 0;
}

void port_led_on(void)
{
    LD2_GPIO_PORT->ODR |= ODR5_MASK;
    printf("[%ld] LED ON\n", port_system_get_millis());
}

void port_led_off(void)
{
    LD2_GPIO_PORT->ODR &= ~ODR5_MASK;
    printf("[%ld] LED OFF\n", port_system_get_millis());
}

void port_led_toggle(void)
{
    LD2_GPIO_PORT->ODR ^= ODR5_MASK;

    if (port_led_get())
        printf("[%ld] LED ON\n", port_system_get_millis());
    else
        printf("[%ld] LED OFF\n", port_system_get_millis());
}

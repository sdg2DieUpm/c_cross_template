#include <stdio.h>
#include "port_led.h"
#include "port_system.h"

/* HW dependent includes */
#include "stm32f4xx.h"


// HW Nucleo-STM32F446RE:


#define GPIO_MODE_OUT 0x01       /*!< GPIO as output */
#define GPIO_PUPDR_NOPULL 0x00 /*!< GPIO no pull up or down */

#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA

#define MODER5_MASK (0x03 << 5 * 2) /* Cada pin ocupa 2 bits */
#define PUPDR5_MASK (0x03 << 5 * 2) /* Cada pin ocupa 2 bits */

#define MODER5_AS_OUTPUT (GPIO_MODE_OUT << 5 * 2) /* Cada pin ocupa 2 bits */
#define PUPDR5_AS_NOPUPD (GPIO_PUPDR_NOPULL << 5 * 2) /* Cada pin ocupa 2 bits */

#define IDR5_MASK (0x01 << 5) /* Cada pin ocupa 1 bit */
#define ODR5_MASK (0x01 << 5) /* Cada pin ocupa 1 bit */


void port_led_gpio_setup(void)
{
    /* Primero , habilitamos siempre el reloj de los perifericos */
    RCC -> AHB1ENR |= RCC_AHB1ENR_GPIOAEN ;
    /* Luego , limpiamos los registros MODER y PUPDR correspondientes */
    GPIOA -> MODER &= ~ MODER5_MASK ;
    GPIOA -> PUPDR &= ~ PUPDR5_MASK ;
    /* Finalmente , configuramos el LED como salida sin pull up/ pull down */
    GPIOA -> MODER |= MODER5_AS_OUTPUT ;
    GPIOA -> PUPDR |= PUPDR5_AS_NOPUPD ;
}

bool port_led_get(void)
{
    return (GPIOA->IDR & IDR5_MASK) != 0;
}

void port_led_on(void)
{
    GPIOA->ODR |= ODR5_MASK;
    printf("[%ld] LED ON\n", port_system_get_millis());
}

void port_led_off(void)
{
    GPIOA->ODR &= ~ODR5_MASK;
    printf("[%ld] LED OFF\n", port_system_get_millis());
}

void port_led_toggle(void)
{
    GPIOA->ODR ^= ODR5_MASK;

    if (port_led_get())
        printf("[%ld] LED ON\n", port_system_get_millis());
    else
        printf("[%ld] LED OFF\n", port_system_get_millis());
}

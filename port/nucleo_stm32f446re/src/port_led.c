#include "port_led.h"
#include "port_system.h"
#include "stm32f4xx_hal.h"

// HW Nucleo-STM32F446RE:
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA

#define MODER5_MASK (0x03 << 5 * 2) /* Cada pin ocupa 2 bits */
#define PUPDR5_MASK (0x03 << 5 * 2) /* Cada pin ocupa 2 bits */

#define MODER5_AS_OUTPUT (GPIO_MODE_OUT << 5 * 2) /* Cada pin ocupa 2 bits */
#define PUPDR5_AS_NOPUPD (GPIO_PUPDR_NOPULL << 5 * 2) /* Cada pin ocupa 2 bits */

#define IDR5_MASK (0x01 << 5) /* Cada pin ocupa 1 bit */
#define ODR5_MASK (0x01 << 5) /* Cada pin ocupa 1 bit */

int port_led_gpio_setup(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();

    /*Configure GPIO pin : LD2_Pin */
    GPIO_InitStruct.Pin = LD2_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

    HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

    return 0;
}

bool port_led_get(void)
{
    return (GPIOA->IDR & IDR5_MASK) != 0;
}

int port_led_on(void)
{
    GPIOA->ODR |= ODR5_MASK;
    return 0;
}

int port_led_off(void)
{
    GPIOA->ODR &= ~ODR5_MASK;
    return 0;
}

int port_led_toggle(void)
{
    GPIOA->ODR ^= ODR5_MASK;
    return 0;
}
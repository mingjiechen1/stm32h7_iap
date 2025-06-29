#include "bsp_led.h"

void BSP_LED_Toggle(void)
{
    HAL_GPIO_TogglePin(LED_PORT, LED_PIN);
}

void BSP_LED_Set(void)
{
    HAL_GPIO_WritePin(LED_PORT, LED_PIN, GPIO_PIN_SET);
}

void BSP_LED_Clear(void)
{
    HAL_GPIO_WritePin(LED_PORT, LED_PIN, GPIO_PIN_RESET);
}

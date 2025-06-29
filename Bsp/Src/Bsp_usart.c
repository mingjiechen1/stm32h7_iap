#include "bsp_usart.h"


int fputc(int ch, FILE *f)
{
    HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
    // HAL_UART_Transmit_DMA(&huart1, (uint8_t *)&ch, 1);
    return ch;
}


void BSP_USART_SendChar(char ch)
{
    HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
}

void BSP_USART_SendString(const char *str)
{
    while (*str)
    {
        BSP_USART_SendChar(*str++);
    }
}

void BSP_USART_Printf(const char *fmt, ...)
{
    char buffer[256];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);
    BSP_USART_SendString(buffer);
}


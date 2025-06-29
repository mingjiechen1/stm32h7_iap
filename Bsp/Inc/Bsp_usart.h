#ifndef __BSP_USART_H__
#define __BSP_USART_H__

#include "main.h"
#include <stdio.h>
#include <stdarg.h>

extern UART_HandleTypeDef huart1;

void BSP_USART_SendChar(char ch);
void BSP_USART_SendString(const char *str);
void BSP_USART_Printf(const char *fmt, ...);

#endif // __BSP_USART_H__
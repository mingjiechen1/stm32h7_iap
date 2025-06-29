#ifndef __COMMON_H__
#define __COMMON_H__

#include    "Boot_include.h"

extern UART_HandleTypeDef huart1; 

#define COM_UART_PORT   huart1

#define COM_USART       USART1

void    Boot_COM_Init(void);
uint8_t Boot_Get_ComStr(uint8_t *u8Str);

#endif
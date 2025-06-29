#include    "Common.h"
#include    <string.h>
#include    <stdlib.h>

static uint8_t uartRxByte;
static uint8_t u8_ComStr[CMD_STRING_SIZE] = {0};
static volatile uint8_t g_cmd_ready = 0;
static uint32_t u32_ComIndex = 0;

void Boot_COM_Init(void)
{
    HAL_UART_Receive_IT(&COM_UART_PORT, &uartRxByte, 1); 
}

uint8_t Boot_Get_ComStr(uint8_t *u8Str)
{
    if (g_cmd_ready)
    {
        memcpy(u8Str, u8_ComStr, u32_ComIndex);
        u8Str[u32_ComIndex] = '\0'; 

        g_cmd_ready = 0;
        u32_ComIndex = 0;
        memset(u8_ComStr, 0, CMD_STRING_SIZE);

        return 1;
    }
    return 0;
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == COM_USART) 
    {
        if (g_cmd_ready == 0) 
        {
            if (uartRxByte == '\b')  
            {
                if (u32_ComIndex > 0) u32_ComIndex--;
            }
            else if (uartRxByte == '\r') 
            {
                u8_ComStr[u32_ComIndex++] = '\0';  
                g_cmd_ready = 1;  
            }
            else if (uartRxByte >= 0x20 && uartRxByte <= 0x7E)
            {
                if (u32_ComIndex < CMD_STRING_SIZE - 1)
                {
                    u8_ComStr[u32_ComIndex++] = uartRxByte;
                }
            }
        }
        HAL_UART_Receive_IT(&COM_UART_PORT, &uartRxByte, 1);
    }
}

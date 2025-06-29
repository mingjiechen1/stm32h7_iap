#ifndef __BSP_LED_H__
#define __BSP_LED_H__

#include "main.h"  

#define LED_PORT    LED_GPIO_Port
#define LED_PIN     LED_Pin

void BSP_LED_Toggle(void);
void BSP_LED_Set(void);
void BSP_LED_Clear(void);

#endif // __BSP_LED_H__

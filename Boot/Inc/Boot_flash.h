#ifndef __BOOT_FLASH_H__
#define __BOOT_FLASH_H__

#include "Boot_include.h"
#include "stm32h7xx_hal_flash.h"

#define FLASH_WAITETIME  50000  

#define STM32_FLASH_BASE     0x08000000 
#define BOOT_PAGE_SIZE      (0x20000U)   /* 128 Kbyte */
#define BOOT_FLASH_SIZE     (0x100000U) /* 1MB */

uint32_t FLASH_ReadWord(uint32_t Flash_Add);
void FLASH_Read(uint32_t ReadAddr, uint32_t *pBuffer, uint32_t NumToRead);
void FLASH_Write(uint32_t WriteAddr, uint32_t *pBuffer, uint32_t NumToWrite);
void Boot_Write_flag(uint32_t WriteAddr, uint32_t u32_flag);

#endif
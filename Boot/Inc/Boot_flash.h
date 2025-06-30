#ifndef __BOOT_FLASH_H__
#define __BOOT_FLASH_H__

#include    "Boot_include.h"


 #define BOOT_PAGE_SIZE                         (0x20000U)    /* 128 Kbyte */
 #define BOOT_FLASH_SIZE                        (0x100000U)   /* 1MB */

uint16_t FLASH_ReadHalfWord(uint32_t Flash_Add);
uint32_t FLASH_ReadWord(uint32_t Flash_Add);
void STMFLASH_Write_NoCheck(uint32_t WriteAddr,uint16_t *pBuffer,uint16_t NumToWrite)   ;
void FLASH_Read(uint32_t ReadAddr, uint16_t *pBuffer, uint16_t NumToRead);


// HAL_StatusTypeDef HAL_FLASH_Unlock(void);
// HAL_StatusTypeDef HAL_FLASH_Lock(void);
// HAL_StatusTypeDef HAL_FLASH_OB_Unlock(void);
// HAL_StatusTypeDef HAL_FLASH_OB_Lock(void);
/* Program operation functions  ***********************************************/
// HAL_StatusTypeDef HAL_FLASH_Program(uint32_t TypeProgram, uint32_t FlashAddress, uint32_t DataAddress);
// HAL_StatusTypeDef HAL_FLASH_Program_IT(uint32_t TypeProgram, uint32_t FlashAddress, uint32_t DataAddress);
// /* FLASH IRQ handler method */
// void HAL_FLASH_IRQHandler(void);
// /* Callbacks in non blocking modes */
// void HAL_FLASH_EndOfOperationCallback(uint32_t ReturnValue);
// void HAL_FLASH_OperationErrorCallback(uint32_t ReturnValue);


#endif
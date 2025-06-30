#include    "Boot_flash.h"

uint16_t FLASH_ReadHalfWord(uint32_t Flash_Add)
{
	return *(__IO uint16_t*)( Flash_Add );
}

uint32_t FLASH_ReadWord(uint32_t Flash_Add)
{
	return *(__IO uint32_t*)( Flash_Add );
}

void FLASH_Read(uint32_t ReadAddr, uint16_t *pBuffer, uint16_t NumToRead)
{
    uint16_t i;
    for (i = 0; i < NumToRead; i++)
    {
        pBuffer[i] = FLASH_ReadHalfWord(ReadAddr + i * 2);
    }
}

void STMFLASH_Write_NoCheck(uint32_t WriteAddr,uint16_t *pBuffer,uint16_t NumToWrite)   
{ 			 		 
	uint16_t i;
	for(i=0;i<NumToWrite;i++)
	{
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_FLASHWORD, WriteAddr, pBuffer[i]);
	    WriteAddr+=2;//add addr 2.
	}  
} 

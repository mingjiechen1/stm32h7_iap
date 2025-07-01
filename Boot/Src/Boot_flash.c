#include "Boot_flash.h"

uint32_t FLASH_ReadWord(uint32_t Flash_Add)
{
	return *(uint32_t *)Flash_Add;
}

static uint32_t FLASH_GetFlashSector(uint32_t Address)
{
	uint32_t sector = 0;

	if ((Address < FLASH_SECTOR_1) && (Address >= FLASH_SECTOR_0))
	{
		sector = FLASH_SECTOR_0;
	}
	else if ((Address < FLASH_SECTOR_2) && (Address >= FLASH_SECTOR_1))
	{
		sector = FLASH_SECTOR_1;
	}
	else if ((Address < FLASH_SECTOR_3) && (Address >= FLASH_SECTOR_2))
	{
		sector = FLASH_SECTOR_2;
	}
	else if ((Address < FLASH_SECTOR_4) && (Address >= FLASH_SECTOR_3))
	{
		sector = FLASH_SECTOR_3;
	}
	else if ((Address < FLASH_SECTOR_5) && (Address >= FLASH_SECTOR_4))
	{
		sector = FLASH_SECTOR_4;
	}
	else if ((Address < FLASH_SECTOR_6) && (Address >= FLASH_SECTOR_5))
	{
		sector = FLASH_SECTOR_5;
	}
	else if ((Address < FLASH_SECTOR_7) && (Address >= FLASH_SECTOR_6))
	{
		sector = FLASH_SECTOR_6;
	}
	else
	{ /*(Address < FLASH_END_ADDR) && (Address >= FLASH_SECTOR_23))*/
		sector = FLASH_SECTOR_7;
	}
	return sector;
}


void FLASH_Read(uint32_t ReadAddr, uint32_t *pBuffer, uint32_t NumToRead)
{
	uint32_t i;
	for (i = 0; i < NumToRead; i++)
	{
		pBuffer[i] = FLASH_ReadWord(ReadAddr);
		ReadAddr += 4;
	}
}

// FLASH写入数据
void FLASH_Write(uint32_t WriteAddr, uint32_t *pBuffer, uint32_t NumToWrite)
{
    FLASH_EraseInitTypeDef FlashEraseInit;
    HAL_StatusTypeDef FlashStatus = HAL_OK;
    uint32_t SectorError = 0;
    uint32_t addrx = 0;
    uint32_t endaddr = WriteAddr + NumToWrite * 4;

    if (WriteAddr < STM32_FLASH_BASE || WriteAddr % 16 != 0)
        return;

    HAL_FLASH_Unlock();					  
    addrx = WriteAddr;
    
    while (addrx < endaddr) 
    {
        if (FLASH_ReadWord(addrx) != 0xFFFFFFFF) 
        {
            FlashEraseInit.TypeErase = FLASH_TYPEERASE_SECTORS;		
            FlashEraseInit.Sector = FLASH_GetFlashSector(addrx); 
            FlashEraseInit.NbSectors = 1;							
            FlashEraseInit.VoltageRange = FLASH_VOLTAGE_RANGE_3;

            if (HAL_FLASHEx_Erase(&FlashEraseInit, &SectorError) != HAL_OK)
            {
                printf("erase error\r\n");
                break;
            }
        }
        addrx += 0x20000;  
        FLASH_WaitForLastOperation(FLASH_WAITETIME, FLASH_BANK_1);
    }

    FlashStatus = FLASH_WaitForLastOperation(FLASH_WAITETIME, FLASH_BANK_1); 
    if (FlashStatus == HAL_OK)
    {
        while (WriteAddr < endaddr) 
        {
            if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_FLASHWORD, WriteAddr, (uint32_t )pBuffer) != HAL_OK) 
            {
                printf("program error\r\n");
                break; 
            }

            WriteAddr += 16; 
            pBuffer += 4;     
        }
    }

    HAL_FLASH_Lock(); 
}

void Boot_Write_flag(uint32_t WriteAddr, uint32_t u32_flag)
{
    FLASH_EraseInitTypeDef FlashEraseInit;
    HAL_StatusTypeDef FlashStatus = HAL_OK;
    uint32_t SectorError = 0;

    // 写入缓冲区（16字节）
    uint32_t write_str[4] = {
        u32_flag,
        0xFFFFFFFF,
        0xFFFFFFFF,
        0xFFFFFFFF
    };

    if (WriteAddr < STM32_FLASH_BASE || (WriteAddr % 16) != 0)
        return;

    HAL_FLASH_Unlock();

    // 若该地址已经写过，则擦除
    if (FLASH_ReadWord(WriteAddr) != 0xFFFFFFFF)
    {
        FlashEraseInit.TypeErase = FLASH_TYPEERASE_SECTORS;
        FlashEraseInit.Sector = FLASH_GetFlashSector(WriteAddr);
        FlashEraseInit.NbSectors = 1;
        FlashEraseInit.VoltageRange = FLASH_VOLTAGE_RANGE_3;

        if (HAL_FLASHEx_Erase(&FlashEraseInit, &SectorError) != HAL_OK)
        {
            printf("erase error\r\n");
            HAL_FLASH_Lock();
            return;
        }

        FLASH_WaitForLastOperation(FLASH_WAITETIME, FLASH_BANK_1);
    }

    FlashStatus = FLASH_WaitForLastOperation(FLASH_WAITETIME, FLASH_BANK_1);

    if (FlashStatus == HAL_OK)
    {
        if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_FLASHWORD, WriteAddr, (uint32_t)(uintptr_t)write_str) != HAL_OK)
        {
            printf("program error\r\n");
        }
    }

    HAL_FLASH_Lock();
}


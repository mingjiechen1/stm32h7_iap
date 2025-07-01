#ifndef __BOOT_H__
#define __BOOT_H__

/*                 flash   distribution                               */
/*0x0800 0000 - 0x0800 FF7F   boot addr                               */
/*0x0800 FF80 - 0x0800 FFFF   boot flag                               */
/*0x0801 0000 - 0x080F FFFF   bank1 app1 addr  size = 960KB           */
/*0x0810 0000 - 0x081F FFFF   bank2 app1 addr  size = 1024KB          */

/* Define if use bkp save flag  -------------------------------*/
#define USE_BKP_SAVE_FLAG     1

/* Define the APP start address -------------------------------*/
#define ApplicationAddress    0x8010000

/* Define the boot loader flag address -------------------------------*/
#define BootFlagAddress       0x800FF80

/* Output printer switch --------------------------------------*/
#define ENABLE_PUTSTR         1

/* Bootloader command -----------------------------------------*/
#define CMD_UPDATE_STR        "update"
#define CMD_UPLOAD_STR        "upload"
#define CMD_ERASE_STR		      "erase"
#define CMD_MENU_STR          "menu"
#define CMD_RUNAPP_STR        "runapp"
#define CMD_ERROR_STR         "error"
#define CMD_DISWP_STR         "diswp"

#if (USE_BKP_SAVE_FLAG == 1)
  #define IAP_FLAG_ADDR    BKP_DR1
#else
  #define IAP_FLAG_ADDR   (uint32_t)(ApplicationAddress - 1024 * 2)//App区域和Bootloader区域共享信息的地址(暂定大小为2K)
#endif

#if (USE_BKP_SAVE_FLAG == 1)
  #define INIT_FLAG_DATA      0x00000000  //默认标志的数据(空片子的情况)
#else
  #define INIT_FLAG_DATA      0xFFFFFFFF   //默认标志的数据(空片子的情况)
#endif
#define UPDATE_FLAG_DATA      0xEEEEEEEE   //下载标志的数据
#define UPLOAD_FLAG_DATA      0xDDDDDDDD   //上传标志的数据
#define ERASE_FLAG_DATA       0xCCCCCCCC   //擦除标志的数据
#define APPRUN_FLAG_DATA      0x5A5A5A5A   //APP不需要做任何处理，直接运行状态


/* Compute the FLASH upload image size --------------------------*/  
#define FLASH_IMAGE_SIZE  (uint32_t) (FLASH_SIZE - (ApplicationAddress - 0x08000000))

/* The maximum length of the command string -------------------*/
#define CMD_STRING_SIZE       128





#endif
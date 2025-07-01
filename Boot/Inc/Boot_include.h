#ifndef __BOOT_INCLUDE_H__
#define __BOOT_INCLUDE_H__

#include    "main.h"
#include    "Bsp_include.h"

typedef void (*boot_cmd_handler_t)(void);

typedef enum
{   
    CMD_INVALID_ID,
    CMD_UPDATE_STR_ID,
    CMD_UPLOAD_STR_ID,
    CMD_MENU_STR_ID,
    CMD_ERASE_STR_ID,
    CMD_RUNAPP_STR_ID,
    CMD_ERROR_STR_ID,
    CMD_DISWP_STR_ID,
} boot_cmd__type_e;

typedef struct
{
    uint8_t u8Dtype;             /**< Data type ID */
    boot_cmd_handler_t tHandler; /**<  function */
} boot_cmd_entry_t;


/*boot include */
#include    "Boot_config.h"
#include    "Boot_common.h"
#include    "Boot_cmd.h"
#include    "Boot_iap.h"
#include    "Boot_flash.h"




#endif
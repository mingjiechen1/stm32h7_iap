#include    "Boot_cmd.h"

 /*local vari*/

/* locol function */
static void handle_cmd_invalid(void);
static void handle_cmd_update_str(void);
static void handle_cmd_upload_str(void);
static void handle_cmd_menu_str(void);
static void handle_cmd_erase_str(void);
static void handle_cmd_runapp_str(void);
static void handle_cmd_error_str(void);
static void handle_cmd_diswp_str(void);

const boot_cmd_entry_t boot_cmd_table[] =
{
    {CMD_INVALID_ID    ,   handle_cmd_invalid      }   ,
    {CMD_UPDATE_STR_ID ,   handle_cmd_update_str   }   ,
    {CMD_UPLOAD_STR_ID ,   handle_cmd_upload_str   }   ,
    {CMD_MENU_STR_ID   ,   handle_cmd_menu_str     }   ,
    {CMD_ERASE_STR_ID  ,   handle_cmd_erase_str    }   ,
    {CMD_RUNAPP_STR_ID ,   handle_cmd_runapp_str   }   ,
    {CMD_ERROR_STR_ID  ,   handle_cmd_error_str    }   ,
    {CMD_DISWP_STR_ID  ,   handle_cmd_diswp_str    }   ,
};

void Boot_regist_init(void)
{
    cmd_regist_handler((const boot_cmd_entry_t*)boot_cmd_table,
                            (sizeof(boot_cmd_table)/ sizeof(boot_cmd_entry_t)) );
}

static void handle_cmd_invalid(void)
{
    printf(" Error cmd!!!   \r\n");
    printf(" Please input <menu> \r\n");
    printf(" Send valid cmd  \r\n");
}

static void handle_cmd_update_str(void)
{
    printf("handle_cmd_update_str\r\n");
}

static void handle_cmd_upload_str(void)
{
    printf("handle_cmd_upload_str\r\n");
}

static void handle_cmd_menu_str(void)
{
    Boot_menu_log();
}   

static void handle_cmd_erase_str(void)
{
    printf("handle_cmd_erase_str\r\n");
}

static void handle_cmd_runapp_str(void)
{
    printf("handle_cmd_runapp_str\r\n");
}

static void handle_cmd_error_str(void)
{
    printf("handle_cmd_error_str\r\n");
}

static void handle_cmd_diswp_str(void)
{
    printf("handle_cmd_diswp_str\r\n");
}

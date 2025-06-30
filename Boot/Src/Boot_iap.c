#include    "Boot_iap.h"

/*local vari*/
static uint8_t                      s_u8CmdTableCount ; 
static const boot_cmd_entry_t*      s_boot_cmd_table;
static uint8_t  cmdStr[CMD_STRING_SIZE];


/*local func*/
static void Boot_start_log(void)    ;
static void Boot_table_handler(uint8_t CmdId)   ;
static uint8_t Boot_get_cmdId(uint8_t *u8_CmdStr);


void Boot_iap_main(void)
{
    if (Boot_Get_ComStr(cmdStr))
    {
        Boot_table_handler(Boot_get_cmdId(cmdStr));
        memset(cmdStr, 0, CMD_STRING_SIZE);
    }
}

void Boot_iap_init(void)
{   
    Boot_COM_Init();
    Boot_menu_log();
    Boot_regist_init();
}

static void Boot_table_handler(uint8_t CmdId)
{
    for (int i = 0; i < s_u8CmdTableCount; i++)
    {
        if (s_boot_cmd_table[i].u8Dtype == CmdId && s_boot_cmd_table[i].tHandler != NULL )
        {
            s_boot_cmd_table[i].tHandler();
        }
    }
}

uint8_t cmd_regist_handler(const boot_cmd_entry_t *boot_cmd_table, uint8_t u8tableCnt)
{
    uint8_t ret = 0;
    do
    {
        if (NULL == boot_cmd_table || 0 == u8tableCnt)
        {
            break;
        }
        s_boot_cmd_table = boot_cmd_table;
        s_u8CmdTableCount = u8tableCnt;
        ret = 1;

    } while (0);

    return ret;
}

void Boot_menu_log(void)
{
    printf("\r\n IAP Main Menu \r\n");
    printf(" 1. update\r\n");
    printf(" 2. upload\r\n");
    printf(" 3. erase\r\n");
    printf(" 4. menu\r\n");
    printf(" 5. runapp\r\n");
}



static uint8_t Boot_get_cmdId(uint8_t *u8_CmdStr)
{
    if (strcmp((char *)u8_CmdStr, CMD_UPDATE_STR) == 0)
    {
        return CMD_UPDATE_STR_ID;
    }
    else if (strcmp((char *)u8_CmdStr, CMD_UPLOAD_STR) == 0)
    {
        return CMD_UPLOAD_STR_ID;
    }
    else if (strcmp((char *)u8_CmdStr, CMD_MENU_STR) == 0)
    {
        return CMD_MENU_STR_ID;
    }
    else if (strcmp((char *)u8_CmdStr, CMD_ERASE_STR) == 0)
    {
        return CMD_ERASE_STR_ID;
    }
    else if (strcmp((char *)u8_CmdStr, CMD_RUNAPP_STR) == 0)
    {

        return CMD_RUNAPP_STR_ID;
    }
    else if (strcmp((char *)u8_CmdStr, CMD_DISWP_STR) == 0)
    {
        return CMD_DISWP_STR_ID;
    }
    else
    {
        printf("\r\n Invalid CMD !\r\n");
    }
    return CMD_INVALID_ID;
}
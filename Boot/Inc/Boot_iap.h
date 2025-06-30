#ifndef __BOOT_IAP_H__
#define __BOOT_IAP_H__

#include    "Boot_include.h"


/*regist boot cmd table*/
uint8_t cmd_regist_handler(const boot_cmd_entry_t *boot_cmd_table, uint8_t u8tableCnt);

void Boot_menu_log(void);
void Boot_iap_init(void);
void Boot_iap_main(void);

#endif
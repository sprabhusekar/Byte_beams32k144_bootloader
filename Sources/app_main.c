/*
 * app_main.c
 *
 *  Created on: 22-Jul-2022
 *      Author: bhaar
 */


#include "core_main.h"
#include "bootloader_app.h"
#include "internal_flash_app.h"

void app_main(void)
{
	U8 app_run_sts_u8 = 0;
	bootloader_app_sts_te bootloader_current_status_e =  BOOT_LOADER_STATUS_UNKNOWN;
	app_run_sts_u8 =  core_main_u8();
	if(app_run_sts_u8 == 0)
	{
		bootloader_current_status_e = boot_loader_app_check_new_firmware_e();
		if(bootloader_current_status_e == BOOT_LOADER_RUN_OLD_FIRMWARE)
		{
			boot_loader_app_run_old_firmware_e();
			//in_flash_app_erase_e(0x0000E000,0x0007FBF0);
			bootloader_app_failure_v();
		}
		else if(bootloader_current_status_e == BOOT_LOADER_UPDATE_NEW_FIRMWARE)
		{
			bootloader_update_new_firmware();
			bootloader_app_failure_v();
		}
		else
		{
			bootloader_app_uart_cmd_ack_send_v(BOOTLOADER_MODE_ENABLE_CMD_ACK_STATUS, BAPP_UART_SUCCESS_STS);
			bootloader_app_failure_v();
		}
	}

}


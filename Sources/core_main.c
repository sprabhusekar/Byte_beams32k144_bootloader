/*
 * core_main.c
 *
 *  Created on: 01-Aug-2022
 *      Author: Prabhu
 */


#include <nvic.h>
#include "core_main.h"
#include "clock.h"
#include "gpio.h"
#include "uart.h"
#include "can.h"
#include "timer.h"
#include "clock.h"
#include "internal_flash.h"

uint8_t core_main_u8(void)
{
	uint8_t core_sts_u8 = 0;
	core_sts_u8 = clock_init_u8();
	core_sts_u8 += gpio_init_u8();
    //can_init();
    core_sts_u8 += timer_init_u8();
    core_sts_u8 += uart_init();
    core_sts_u8 += internal_flash_init();
    nvic_init_v();
    nvic_enable_all_Interrupts_v();
    timer_start_base_v();
    uart_rx_data_queue();
    return core_sts_u8;
}



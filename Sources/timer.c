/*
 * timer.c
 *
 *  Created on: 11-Jun-2022
 *      Author: bhaar
 */

#include "s32k144.h"
#include "Cpu.h"
#include "common_header.h"
#include "uart_state_machine.h"
#include "can_app.h"
#include "timer.h"

#define N58_COMMUNICATION_TIMEOUT   20

volatile U8 timer_pal_chan0_2ms_timer_call_back_vu8 = 0;

volatile U8 timer_pal_chan2_10ms_timer_call_back_vu8 = 0;

volatile U8 timer_pal_chan4_5ms_timer_call_back_vu8 = 0;

volatile U8 timer_one_seconds_eplased_vu8 = 0;

uint32_t timeout_uart_ack_flag_counter_u32 = 0;

volatile U8 n58_communication_start_vu8 = 0;
uint32_t ftm_tim_sys_freq_u32[FTM_INSTANCE_COUNT];
uint8_t  timer_init_u8(void)
{
	uint8_t return_value_u8 = 0;
    if(TIMING_Init(&timing_pal1_instance, &timing_pal1_InitConfig))
    {
    	return_value_u8= 1;
    }
   ftm_tim_sys_freq_u32[timing_pal1_instance.instIdx] = FTM_DRV_GetFrequency(timing_pal1_instance.instIdx);
   return return_value_u8;
}

void timer_start_base_v(void)
{
	TIMING_StartChannel(&timing_pal1_instance,0, (1000* ftm_tim_sys_freq_u32[timing_pal1_instance.instIdx])/1000);
}



void timer_pal_chan0_callback_1000ms_v(void *userdata)
{
	COM_HDR_UNUSED(userdata);
	timer_one_seconds_eplased_vu8 = 1;
}






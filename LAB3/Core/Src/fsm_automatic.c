/*
 * fsm_automatic.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Thanh Phu
 */

#include "fsm_automatic.h"

void fsm_automatic_run()
{
	switch(status)
	{
		case INIT:
			HAL_GPIO_WritePin(GPIOA, LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_4_Pin | LED_5_Pin | LED_6_Pin, RESET);
			status = AUTO_RED_GREEN;
			setTimer(3000);
			break;
		case AUTO_RED_GREEN:
			led_red_and_green();
			if(timer_flag == 1)
			{
				setTimer1(2000);
				status = AUTO_RED_YELLOW;
			}
			break;
		case AUTO_RED_YELLOW:
			led_red_and_yellow();
			if(timer1_flag == 1)
			{
				status = AUTO_GREEN_RED;
				setTimer2(3000);
			}
			break;
		case AUTO_GREEN_RED:
			led_green_and_red();
			if(timer2_flag == 1)
			{
				status = AUTO_YELLOW_RED;
				setTimer3(2000);
			}
			break;
		case AUTO_YELLOW_RED:
			led_yellow_and_red();
			if(timer3_flag == 1)
			{
				status = AUTO_RED_GREEN;
				setTimer(3000);
			}
			break;
		default:
			break;

	}
}

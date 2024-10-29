/*
 * fsm_manual.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Thanh Phu
 */

#include "fsm_manual.h"
int temp_red = 5;
int temp_yellow = 2;
int temp_green = 3;
int led_blinky1 = 0;

void fsm_manual_run()
{
	//HAL_GPIO_WritePin(GPIOA, LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_4_Pin | LED_5_Pin | LED_6_Pin, RESET);
	switch(status)
	{
		case NORMAL_MODE:
			if(timer2_flag == 1)
			{
				status = INIT;
			}
			if(isButtonPressed1() == 1)
			{
				status = MODE_LED_RED;
				setTimer2(10000);
				setTimer3(500);
				setTimer4(250);
			}
			break;
		case MODE_LED_RED:
			if(timer3_flag == 1)
			{
				HAL_GPIO_TogglePin(GPIOA, LED_1_Pin | LED_4_Pin);

				setTimer3(500);
			}
			if(isButtonPressed2() == 1)
			{
				temp_red++;
			}
			if(isButtonPressed3() == 1)
			{
				if(temp_red >= 1 && temp_red <= 99)
				{
					led7_seg[0] = temp_red;
					led7_seg[1] = temp_red - 3;
					led7_seg[2] = temp_red - 2;
				}
			}
			if(timer4_flag == 1)
			{
				display7SEG_MAN();
				setTimer4(250);
			}

			if(timer2_flag == 1)
			{
				status = INIT;
			}
			if(isButtonPressed1() == 1)
			{
				status = MODE_LED_YELLOW;
				setTimer2(10000);
				setTimer3(500);
				setTimer4(250);
			}
			break;
		case MODE_LED_YELLOW:
			if(timer3_flag == 1)
			{
				HAL_GPIO_TogglePin(GPIOA, LED_2_Pin | LED_5_Pin);
				HAL_GPIO_WritePin(GPIOA, LED_1_Pin | LED_3_Pin | LED_4_Pin | LED_6_Pin, RESET);
				setTimer3(500);
			}
			if(isButtonPressed2() == 1)
			{
				temp_yellow++;
			}
			if(isButtonPressed3() == 1)
			{
				if(temp_yellow >= 1 && temp_yellow <= 99)
				{
					led7_seg[1] = temp_yellow;
					led7_seg[0] = temp_yellow + 3;
					led7_seg[2] = temp_yellow + 1;
				}
			}
			if(timer4_flag == 1)
			{
				display7SEG_MAN();
				setTimer4(250);
			}

			if(timer2_flag == 1)
			{
				status = INIT;
			}
			if(isButtonPressed1() == 1)
			{
				status = MODE_LED_GREEN;
				setTimer2(10000);
				setTimer3(500);
				setTimer4(250);
			}
			break;
		case MODE_LED_GREEN:
			if(timer3_flag == 1)
			{
				HAL_GPIO_TogglePin(GPIOA, LED_3_Pin | LED_6_Pin);
				HAL_GPIO_WritePin(GPIOA, LED_1_Pin | LED_2_Pin | LED_4_Pin | LED_5_Pin, RESET);
				setTimer3(500);
			}
			if(isButtonPressed2() == 1)
			{
				temp_green++;
			}
			if(isButtonPressed3() == 1)
			{
				if(temp_green >= 1 && temp_green <= 99)
				{
					led7_seg[2] = temp_green;
					led7_seg[0] = temp_green + 2;
					led7_seg[1] = temp_green - 1;
				}
			}
			if(timer4_flag == 1)
			{
				display7SEG_MAN();
				setTimer4(250);
			}

			if(timer2_flag == 1)
			{
				status = INIT;
			}
			if(isButtonPressed1() == 1)
			{
				status = NORMAL_MODE;
				setTimer2(10000);
//				setTimer3(500);
//				setTimer4(250);
			}
			break;
		default:
			break;
	}
}

void display7SEG_MAN()
{
	if(status == MODE_LED_RED)
	    {
			switch(led_blinky1)
			{
				case 0:
					HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN2_Pin, RESET);
					HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN3_Pin, SET);
					display7SEG1(led7_seg[0] / 10);
					display7SEG2(0);
					led_blinky1 = 1;
					break;
				case 1:
					HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN2_Pin, SET);
					HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN3_Pin, RESET);
					display7SEG1(led7_seg[0] % 10);
					display7SEG2(2);
					led_blinky1 = 0;
					break;
			}
	    }
		if(status == MODE_LED_YELLOW)
		{
			switch(led_blinky1)
			{
				case 0:
					HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN2_Pin, RESET);
					HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN3_Pin, SET);
					display7SEG1(led7_seg[1] / 10);
					display7SEG2(0);
					led_blinky1 = 1;
					break;
				case 1:
					HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN2_Pin, SET);
					HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN3_Pin, RESET);
					display7SEG1(led7_seg[1] % 10);
					display7SEG2(3);
					led_blinky1 = 0;
					break;
			}
		}
		if(status == MODE_LED_GREEN)
		{
			switch(led_blinky1)
			{
				case 0:
					HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN2_Pin, RESET);
					HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN3_Pin, SET);
					display7SEG1(led7_seg[2] / 10);
					display7SEG2(0);
					led_blinky1 = 1;
					break;
				case 1:
					HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN2_Pin, SET);
					HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN3_Pin, RESET);
					display7SEG1(led7_seg[2] % 10);
					display7SEG2(4);
					led_blinky1 = 0;
					break;
			}
		}
}


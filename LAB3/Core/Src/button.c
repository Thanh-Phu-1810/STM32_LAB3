/*
 * button.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Thanh Phu
 */

#include "button.h"

int KeyReg0_Button1 = NORMAL_STATE;
int KeyReg1_Button1 = NORMAL_STATE;
int KeyReg2_Button1 = NORMAL_STATE;
int KeyReg3_Button1 = NORMAL_STATE;

int KeyReg0_Button2 = NORMAL_STATE;
int KeyReg1_Button2 = NORMAL_STATE;
int KeyReg2_Button2 = NORMAL_STATE;
int KeyReg3_Button2 = NORMAL_STATE;

int KeyReg0_Button3 = NORMAL_STATE;
int KeyReg1_Button3 = NORMAL_STATE;
int KeyReg2_Button3 = NORMAL_STATE;
int KeyReg3_Button3 = NORMAL_STATE;

int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;
int isButtonPressed()
{
	if(button1_flag == 1)
	{
		button1_flag = 0;
		return 1;
	}
	if(button2_flag == 1)
	{
		button2_flag = 0;
		return 1;
	}
	if(button3_flag == 1)
	{
		button3_flag = 0;
		return 1;
	}
	return 0;
}
void subKeyProcess1()
{
	button1_flag = 1;
}
void subKeyProcess2()
{
	button2_flag = 1;
}
void subKeyProcess3()
{
	button3_flag = 1;
}
void getKeyInput() //Tối ưu code chổ này sao cho thành một máy trạng thái trong đây là dùng một cái mảng để lưu các giá trị KeyReg và không dùng for để gọi hàm HAL_GPIO_ReadPin
{
	//Button1
	KeyReg0_Button1= KeyReg1_Button1;
	KeyReg1_Button1 = KeyReg2_Button1;
	KeyReg2_Button1 = HAL_GPIO_ReadPin(GPIOA, Button1_Pin);
	if((KeyReg0_Button1== KeyReg1_Button1) && (KeyReg1_Button1 == KeyReg2_Button1))
	{
		if(KeyReg3_Button1 != KeyReg2_Button1)
		{
			KeyReg3_Button1 = KeyReg2_Button1;
			if(KeyReg2_Button1 == PRESSED_STATE)
			{
				subKeyProcess1();
				setTimer(2000);
			}
		}
		else
		{
			timer_counter--;
			if(timer_counter <= 0)
			{
				if(KeyReg2_Button1 == PRESSED_STATE)
                subKeyProcess1();
				setTimer(50);
			}
		}
	}

	//Button2
	KeyReg0_Button2= KeyReg1_Button2;
	KeyReg1_Button2 = KeyReg2_Button2;
	KeyReg2_Button2 = HAL_GPIO_ReadPin(GPIOA, Button2_Pin);
	if((KeyReg0_Button2 == KeyReg1_Button2) && (KeyReg1_Button2 == KeyReg2_Button2))
	{
		if(KeyReg3_Button2 != KeyReg2_Button2)
		{
			KeyReg3_Button2 = KeyReg2_Button2;
			if(KeyReg2_Button2 == PRESSED_STATE)
			{
				subKeyProcess2();
				setTimer(2000);
			}
		}
		else
		{
			timer_counter--;
			if(timer_counter <= 0)
			{
				if(KeyReg2_Button2 == PRESSED_STATE)
				subKeyProcess2();
				setTimer(50);
			}
		}
	}

	//Button3
	KeyReg0_Button3 = KeyReg1_Button3;
	KeyReg1_Button3 = KeyReg2_Button3;
	KeyReg2_Button3 = HAL_GPIO_ReadPin(GPIOA, Button3_Pin);
	if((KeyReg0_Button3 == KeyReg1_Button3) && (KeyReg1_Button3 == KeyReg2_Button3))
	{
		if(KeyReg3_Button3 != KeyReg2_Button3)
		{
			KeyReg3_Button3 = KeyReg2_Button3;
			if(KeyReg2_Button3 == PRESSED_STATE)
			{
				subKeyProcess3();
				setTimer(2000);
			}
		}
		else
		{
			timer_counter--;
			if(timer_counter <= 0)
			{
				if(KeyReg2_Button3 == PRESSED_STATE)
				subKeyProcess3();
				setTimer(50);
			}
		}
	}
}


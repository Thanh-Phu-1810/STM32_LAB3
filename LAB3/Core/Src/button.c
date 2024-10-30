/*
 * button.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Thanh Phu
 */

#include "button.h"

//int KeyReg0_Button1 = NORMAL_STATE;
//int KeyReg1_Button1 = NORMAL_STATE;
//int KeyReg2_Button1 = NORMAL_STATE;
//int KeyReg3_Button1 = NORMAL_STATE;
//
//int KeyReg0_Button2 = NORMAL_STATE;
//int KeyReg1_Button2 = NORMAL_STATE;
//int KeyReg2_Button2 = NORMAL_STATE;
//int KeyReg3_Button2 = NORMAL_STATE;
//
//int KeyReg0_Button3 = NORMAL_STATE;
//int KeyReg1_Button3 = NORMAL_STATE;
//int KeyReg2_Button3 = NORMAL_STATE;
//int KeyReg3_Button3 = NORMAL_STATE;
//
//int button1_flag = 0;
//int button2_flag = 0;
//int button3_flag = 0;
//
//int timer_counter_button1;
//int timer_counter_button2;
//int timer_counter_button3;
//int isButtonPressed1()
//{
//	if(button1_flag == 1)
//	{
//		button1_flag = 0;
//		return 1;
//	}
//    return 0;
//}
//int isButtonPressed2()
//{
//	if(button2_flag == 1)
//	{
//		button2_flag = 0;
//		return 1;
//	}
//	return 0;
//}
//int isButtonPressed3()
//{
//	if(button3_flag == 1)
//	{
//		button3_flag = 0;
//		return 1;
//	}
//	return 0;
//}
//void subKeyProcess1()
//{
//	button1_flag = 1;
//}
//void subKeyProcess2()
//{
//	button2_flag = 1;
//}
//void subKeyProcess3()
//{
//	button3_flag = 1;
//}
//void getKeyInput() //Tối ưu code chổ này sao cho thành một máy trạng thái trong đây là dùng một cái mảng để lưu các giá trị KeyReg và không dùng for để gọi hàm HAL_GPIO_ReadPin
//{
//	//Button1
//	KeyReg0_Button1= KeyReg1_Button1;
//	KeyReg1_Button1 = KeyReg2_Button1;
//	KeyReg2_Button1 = HAL_GPIO_ReadPin(GPIOA, Button1_Pin);
//	if((KeyReg0_Button1== KeyReg1_Button1) && (KeyReg1_Button1 == KeyReg2_Button1))
//	{
//		if(KeyReg3_Button1 != KeyReg2_Button1)
//		{
//			KeyReg3_Button1 = KeyReg2_Button1;
//			if(KeyReg2_Button1 == PRESSED_STATE)
//			{
//				subKeyProcess1();
//				timer_counter_button1 = 2000;
//			}
//		}
//		else
//		{
//			timer_counter_button1--;
//			if(timer_counter_button1 <= 0)
//			{
//				if(KeyReg2_Button1 == PRESSED_STATE)
//                subKeyProcess1();
//				timer_counter_button1 = 50;
//			}
//		}
//	}
//
//	//Button2
//	KeyReg0_Button2= KeyReg1_Button2;
//	KeyReg1_Button2 = KeyReg2_Button2;
//	KeyReg2_Button2 = HAL_GPIO_ReadPin(GPIOA, Button2_Pin);
//	if((KeyReg0_Button2 == KeyReg1_Button2) && (KeyReg1_Button2 == KeyReg2_Button2))
//	{
//		if(KeyReg3_Button2 != KeyReg2_Button2)
//		{
//			KeyReg3_Button2 = KeyReg2_Button2;
//			if(KeyReg2_Button2 == PRESSED_STATE)
//			{
//				subKeyProcess2();
//				timer_counter_button2 = 2000;
//			}
//		}
//		else
//		{
//			timer_counter_button2--;
//			if(timer_counter_button2 <= 0)
//			{
//				if(KeyReg2_Button2 == PRESSED_STATE)
//				subKeyProcess2();
//				timer_counter_button2 = 50;
//			}
//		}
//	}
//
//	//Button3
//	KeyReg0_Button3 = KeyReg1_Button3;
//	KeyReg1_Button3 = KeyReg2_Button3;
//	KeyReg2_Button3 = HAL_GPIO_ReadPin(GPIOA, Button3_Pin);
//	if((KeyReg0_Button3 == KeyReg1_Button3) && (KeyReg1_Button3 == KeyReg2_Button3))
//	{
//		if(KeyReg3_Button3 != KeyReg2_Button3)
//		{
//			KeyReg3_Button3 = KeyReg2_Button3;
//			if(KeyReg2_Button3 == PRESSED_STATE)
//			{
//				subKeyProcess3();
//				timer_counter_button3 = 2000;
//			}
//		}
//		else
//		{
//			timer_counter_button3--;
//			if(timer_counter_button3 <= 0)
//			{
//				if(KeyReg2_Button3 == PRESSED_STATE)
//				subKeyProcess3();
//				timer_counter_button3 = 50;
//			}
//		}
//	}
//}


int KeyReg0[NUM_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg1[NUM_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg2[NUM_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg3[NUM_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int button_flag[NUM_BUTTONS] = {0, 0, 0};
int timer_counter_button[NUM_BUTTONS] = {0, 0, 0};

// Assign pins for each button
uint16_t ButtonPin[NUM_BUTTONS] = {Button1_Pin, Button2_Pin, Button3_Pin};

void subKeyProcess(int button_id)
{
    button_flag[button_id] = 1;
}

// Separate isButtonPressed functions
int isButtonPressed1()
{
    if(button_flag[0] == 1)
    {
        button_flag[0] = 0;
        return 1;
    }
    return 0;
}

int isButtonPressed2()
{
    if(button_flag[1] == 1)
    {
        button_flag[1] = 0;
        return 1;
    }
    return 0;
}

int isButtonPressed3()
{
    if(button_flag[2] == 1)
    {
        button_flag[2] = 0;
        return 1;
    }
    return 0;
}

void getKeyInput()
{
    for (int i = 0; i < NUM_BUTTONS; i++)
    {
        KeyReg0[i] = KeyReg1[i];
        KeyReg1[i] = KeyReg2[i];
        KeyReg2[i] = HAL_GPIO_ReadPin(GPIOA, ButtonPin[i]);

        if ((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i]))
        {
            if (KeyReg3[i] != KeyReg2[i])
            {
                KeyReg3[i] = KeyReg2[i];
                if (KeyReg2[i] == PRESSED_STATE)
                {
                    subKeyProcess(i);
                    timer_counter_button[i] = 2000;
                }
            }
            else
            {
                timer_counter_button[i]--;
                if (timer_counter_button[i] <= 0)
                {
                    if (KeyReg2[i] == PRESSED_STATE)
                        subKeyProcess(i);
                    timer_counter_button[i] = 50;
                }
            }
        }
    }
}

/*
 * button.h
 *
 *  Created on: Oct 28, 2024
 *      Author: Thanh Phu
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "software_timer.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

extern int button1_flag;
extern int button2_flag;
extern int button3_flag;

void getKeyInput();
int isButtonPressed();
void subKeyProcess1();
void subKeyProcess2();
void subKeyProcess3();


#endif /* INC_BUTTON_H_ */

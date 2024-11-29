
/**********************************************************************************************/
/* Author       : Mostafa Zween                                                               */
/* Date         : 14/8/2021 11:50:30 AM                                                       */
/* version      : 01                                                                          */
/**********************************************************************************************/
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO_interface.h"
#include "LCD_config.h"
#include "power.h"

void LCD_Init(void);
void LCD_Enable(void);
void LCD_SendCommand(unsigned char cmd);
void LCD_SendChar(unsigned char data);
void LCD_SendNumber(unsigned int num);
void LCD_SendFloatingNumber(double num);
void LCD_SendString(char *str);
void LCD_ClearScreen(void);
void LCD_MoveCursor(unsigned char row,unsigned char coloumn);

#define CLR_SCREEN            0x01  // clear lcd
#define CURSOR_ON_DISPLAY_OFF 0x0C  //0x0E Cursor on
#define CURSOR_ON_DISPLAY_ON  0x0E  //0x0E Cursor on
#define RETURN_HOME           0x02
#define ENTRY_MODE            0x06
#define EIGHT_BIT             0X38
#define FOUR_BIT              0X28
#define NUMBER_DIGITS         10
#define DIGITS                3
#endif /* LCD_INTERFACE_H_ */
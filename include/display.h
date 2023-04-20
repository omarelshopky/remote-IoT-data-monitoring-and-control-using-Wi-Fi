#ifndef DISPLAY_H_
#define DISPLAY_H_

/**
 ** Includes
 **/
#include <LiquidCrystal.h>

/**
 ** Defines
 **/
#define RS 13
#define EN 12
#define D4 11
#define D5 10
#define D6 9
#define D7 8

/**
 ** Globals
 **/
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

/**
 ** Function definitions
 **/
// Initialize the LCD
void initialize_display();

// Display sensors data
void display(unsigned char temperature, bool smoke_rate, bool motion_detection);

#endif /* DISPLAY_H_ */
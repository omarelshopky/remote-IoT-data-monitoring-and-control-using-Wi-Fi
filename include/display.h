#ifndef DISPLAY_H_
#define DISPLAY_H_

/*
 * Includes
 */
#include <LiquidCrystal.h>

/*
 * Defines
 */
#define RS 8
#define EN 9
#define D4 10
#define D5 11
#define D6 12
#define D7 13
#define TEMP_SYMBOL (unsigned char)0
#define SMOKE_SYMBOL (unsigned char)1
#define MOTION_SYMBOL (unsigned char)2

/*
 * Globals
 */
static LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

/*
 * Consts
 */
const unsigned char temp_symbol_map[] = {
  0b00111,
  0b00101,
  0b00111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

const unsigned char smoke_symbol_map[] = {
  0b00100,
  0b00010,
  0b10100,
  0b10101,
  0b01011,
  0b10101,
  0b01110,
  0b00100
};

const unsigned char motion_symbol_map[] = {
  0b01110,
  0b01110,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010,
  0b01010
};

/*
 * Function definitions
 */
void initialize_display();
void create_symbols();
void display_sensors_data(unsigned char temperature, bool smoke_detected, bool motion_detected);

#endif /* DISPLAY_H_ */
/*
 * leds.h
 *
 * Created: 4/20/2023 5:26:57 AM
 *  Author: Omar Elshopky
 */ 


#ifndef LEDS_H_
#define LEDS_H_

/**
 ** Includes
 **/
#include <avr/io.h>

/**
 ** Defines
 **/
#define LEDS_PORT_DIRECTION DDRD
#define LEDS_PORT PORTD
#define LED1_PIN 7
#define LED2_PIN 6

/**
 ** Enumerates
 **/
enum LED { FIRST_LED = LED1_PIN, SECOND_LED = LED2_PIN };
enum MODE { TURN_OFF, TURN_ON };

/**
 ** Function definitions
 **/
// Initialize the two LEDs
void initialize_leds();

// Switch specific led on/off
void switch_led(enum LED led, enum MODE mode);

#endif /* LEDS_H_ */
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
#define FIRST_LED LED1_PIN
#define SECOND_LED LED2_PIN
#define TURN_OFF 0x0
#define TURN_ON 0x1

/**
 ** Function definitions
 **/
// Initialize the two LEDs
void initialize_leds();

// Switch specific led on/off
void switch_led(unsigned char led, unsigned char mode);


#endif /* LEDS_H_ */
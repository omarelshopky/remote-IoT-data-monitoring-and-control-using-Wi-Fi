/*
 * leds.c
 *
 * Created: 4/20/2023 5:27:08 AM
 *  Author: Omar Elshopky
 */ 
#include "../include/leds.h"


void initialize_leds() {
	LEDS_PORT_DIRECTION |= (1 << LED1_PIN | 1 << LED2_PIN);
}

void switch_led(enum LED led, enum MODE mode) {
	if (mode == TURN_ON) {
		LEDS_PORT |= (1 << led);
	} else {
		LEDS_PORT &= ~(1 << led);
	}
};
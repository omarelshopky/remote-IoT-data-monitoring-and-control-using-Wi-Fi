#include "../include/leds.h"


void initialize_leds() {
	LEDS_PORT_DIRECTION |= (1 << LED1_PIN | 1 << LED2_PIN);

	switch_led(FIRST_LED, TURN_ON);
	switch_led(SECOND_LED, TURN_ON);
}

void switch_led(unsigned char led, unsigned char mode) {
	if (mode == TURN_ON) {
		LEDS_PORT |= (1 << led);
	} else {
		LEDS_PORT &= ~(1 << led);
	}
};
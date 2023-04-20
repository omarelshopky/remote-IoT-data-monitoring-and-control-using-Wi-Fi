#include "../include/driver.h"
#include "../include/leds.h"

void initialize_device() {
	initialize_leds();
}

void run_device() {
	switch_led(FIRST_LED, TURN_ON);
	switch_led(SECOND_LED, TURN_ON);
}
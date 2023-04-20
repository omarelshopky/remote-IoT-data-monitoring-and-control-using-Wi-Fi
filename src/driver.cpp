#include "../include/driver.h"
#include "../include/leds.h"
#include "../include/display.h"


void initialize_device() {
	initialize_leds();
	initialize_display();
}

void run_device() {
	switch_led(FIRST_LED, TURN_ON);
	switch_led(SECOND_LED, TURN_ON);
	display_sensors_data(100, true, true);
}
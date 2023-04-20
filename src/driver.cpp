#include "../include/driver.h"
#include "../include/leds.h"
#include "../include/display.h"
#include "../include/timer.h"

void initialize_device() {
	initialize_leds();
	initialize_display();
	start_2s_timer();
}

void run_device() {
	switch_led(FIRST_LED, TURN_ON);
	switch_led(SECOND_LED, TURN_ON);
}

ISR(TIMER1_COMPA_vect) {
	display_sensors_data(100, true, true);
}
#include "../include/driver.h"
#include "../include/leds.h"
#include "../include/display.h"
#include "../include/timer.h"
#include "../include/sensors.h"

void initialize_device() {
	initialize_leds();
	initialize_display();
	initialize_sensors();
	start_2s_timer();
}

void run_device() {
	switch_led(FIRST_LED, TURN_ON);
	switch_led(SECOND_LED, TURN_ON);
}

ISR(TIMER1_COMPA_vect) {
	unsigned char temperature = read_temperature();
	bool smoke_detected = detect_smoke_existence();
	bool motion_detected = detect_motion_existence();

	display_sensors_data(temperature, smoke_detected, motion_detected);
}
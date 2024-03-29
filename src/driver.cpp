#include "../include/driver.h"
#include "../include/leds.h"
#include "../include/display.h"
#include "../include/timer.h"
#include "../include/sensors.h"
#include "../include/webserver.h"

void initialize_device() {
	initialize_leds();
	initialize_display();
	initialize_sensors();
	initialize_webserver();
	start_2s_timer();
}

void run_device() {
	handle_clients();
}

ISR(TIMER1_COMPA_vect) {
	read_temperature();
	detect_smoke_existence();

	display_sensors_data(temperature, smoke_detected, motion_detected);
}
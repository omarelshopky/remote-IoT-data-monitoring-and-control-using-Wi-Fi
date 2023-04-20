/*
 * driver.cpp
 *
 * Created: 4/20/2023 5:28:27 AM
 * Author: Omar Elshopky
 */ 
#include "../include/driver.h"
#include "../include/leds.h"

void initialize_device() {
	initialize_leds();
}

void run_device() {
	switch_led(FIRST_LED, TURN_OFF);
	switch_led(SECOND_LED, TURN_ON);
}
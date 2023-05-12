#include "../include/sensors.h"

unsigned char temperature = 0;
bool smoke_detected = false, motion_detected = true;

void initialize_sensors() {
    initialize_temperature_sensor();
    initialize_smoke_sensor();
    initialize_motion_sensor();
}

void initialize_temperature_sensor() {
    // TODO: Eslam & Nabeel
    // Should use ADC for data read
}

void initialize_smoke_sensor() {
    // TODO: Eslam & Nabeel
    // Should use ADC for data read
}

void initialize_motion_sensor() {
    EIMSK = (1 << INT0); // Enable INT0 interrupt
    EICRA = (1 << ISC00); // Falling edge trigger
    sei();
}

void read_temperature() {
    // TODO: Eslam & Nabeel
    temperature = 45;
}

void detect_smoke_existence() {
    // TODO: Eslam & Nabeel
    smoke_detected = true;
}

// Detect motion existence
ISR(INT0_vect) {
    motion_detected = !motion_detected;
}

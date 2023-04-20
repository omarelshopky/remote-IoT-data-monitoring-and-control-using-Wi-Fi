#include "../include/sensors.h"


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
    // TODO: Ahmed
    // Should use interrupt (INT0) for data read
}

unsigned char read_temperature() {
    // TODO: Eslam & Nabeel
    return 45;
}

bool detect_smoke_existence() {
    // TODO: Eslam & Nabeel
    return false;
}

bool detect_motion_existence() {
    // TODO: Ahmed
    return true;
}

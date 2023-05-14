#include "../include/sensors.h"
#include <Arduino.h>

float temperature = 0;
bool smoke_detected = false, motion_detected = true;

void initialize_sensors() {
    initialize_adc();
    initialize_motion_sensor();
}

void initialize_adc() {
    ADMUX |= (1 << REFS0); // Vref = Vcc
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0) | (1 << ADEN); // set prescaller 128 and enable ADC
}

void initialize_motion_sensor() {
    EIMSK = (1 << INT0); // Enable INT0 interrupt
    EICRA = (1 << ISC00); // Falling edge trigger
    sei();
}

float analog_read(unsigned char pin_num) {
    ADMUX |= pin_num;
    ADCSRA |= (1 << ADSC);

    while (ADCSRA & (1 << ADIF) == 0);

    return ADC; // ADCH:ADCL
}

void read_temperature() {
    temperature = (analog_read(TEMPERATURE_SENSOR_PIN) * (500.0 / 1024.0)) / 10.0;
}

void detect_smoke_existence() {
    smoke_detected = (analog_read(SMOKE_SENSOR_PIN) > SMOKE_DETECTION_LIMIT);
}

// Detect motion existence
ISR(INT0_vect) {
    motion_detected = !motion_detected;
}

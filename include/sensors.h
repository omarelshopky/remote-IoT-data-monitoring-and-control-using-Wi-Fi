#ifndef SENSORS_H_
#define SENSORS_H_

/*
 * Includes
 */
#include <avr/io.h>
#include <avr/interrupt.h>

/*
 * Defines
 */
#define TEMPERATURE_SENSOR_PIN 0    // A0
#define SMOKE_SENSOR_PIN 1          // A1
#define MOTION_SENSOR_PIN INT0      // D2

/*
 * Globals
 */
extern unsigned char temperature;
extern bool smoke_detected, motion_detected;

/*
 * Function definitions
 */
void initialize_sensors();
void initialize_temperature_sensor();
void initialize_smoke_sensor();
void initialize_motion_sensor();
void read_temperature();
void detect_smoke_existence();

#endif /* SENSORS_H_ */
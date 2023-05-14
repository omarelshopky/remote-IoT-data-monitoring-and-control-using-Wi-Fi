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
#define SMOKE_DETECTION_LIMIT 400

/*
 * Globals
 */
extern float temperature;
extern bool smoke_detected, motion_detected;

/*
 * Function definitions
 */
void initialize_sensors();
void initialize_adc();
void initialize_motion_sensor();
float analog_read(unsigned char pin_num);
void read_temperature();
void detect_smoke_existence();

#endif /* SENSORS_H_ */
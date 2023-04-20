#ifndef WEBSERVER_H_
#define WEBSERVER_H_

/*
 * Includes
 */
#include <SoftwareSerial.h>

/*
 * Defines
 */
#define TEMPERATURE_SENSOR_PIN 0    // A0
#define SMOKE_SENSOR_PIN 1          // A1
#define MOTION_SENSOR_PIN 2         // INT0

/*
 * Function definitions
 */
void initialize_sensors();
void initialize_temperature_sensor();
void initialize_smoke_sensor();
void initialize_motion_sensor();
unsigned char read_temperature();
bool detect_smoke_existence();
bool detect_motion_existence();

#endif /* WEBSERVER_H_ */
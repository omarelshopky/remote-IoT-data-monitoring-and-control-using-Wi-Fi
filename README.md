# Remote IoT data monitoring and control using Wi-Fi

## 1. Project description
In this project, the Arduino board is connected to Wi-Fi module and both act as a server. The Arduino Board is connected to 2 LEDs, 3 sensors (temperature, smoke, motion). The client which is a web browser - running on any computer connected to the same network as the Arduino - communicates to the server and controls it.

The project must do the following **2 processes**:

I. The Arduino board must monitor and display sensors data periodically (Temp, Motion,
smoke) on LCD every 2 seconds (using timers).

II. The webpage will send a command to the Wi-Fi module to control the Arduino board and
switch each of the LEDs on/off.

_______

## 2. List of hardware requirements:
- Arduino UNO
- Wi-Fi Serial TTL Module ESP-01S (Ram Electronics)
- LCD
- Sensors
- Temperature sensor: LM35
- Smoke sensor MQ2 (Digital/Analog) (Future Electronics)
- PIR Motion sensor module (Adjustable Range) (Future Electronics)
- LEDs, Wires

_______

## 3. Notes:
1. You need to use Timers to implement the 2 seconds (any timer with any mode).
2. You need to use external interrupts (INT0 or NT1) to detect and read the motion sensor.
3. You need to use ADC functions for reading an analogue value from the sensors

Note: Please keep in mind that this project Can be implemented using the Arduino IDE,
and that only Software Serial (UART) and LCD Arduino built-in library are permitted to
be used.

_______

## 4. Bouns
 The Arduino board must detect abnormal conditions and report a notification alert to
the web page. The abnormal conditions are:
1. Tempertesure value exceeding 30 degrees.
2. Detecting an existence of smoke.
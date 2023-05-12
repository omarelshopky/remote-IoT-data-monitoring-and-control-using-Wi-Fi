#ifndef WEBSERVER_H_
#define WEBSERVER_H_

/*
 * Includes
 */
#include <Arduino.h>
#include <SoftwareSerial.h>

/*
 * Defines
 */
#define WEBSERVER_RX 4
#define WEBSERVER_TX 5
#define TIMEOUT 8000 // ms
#define CHUNK_SIZE 1024
#define WIFI_NAME "YOUR_WIFI_NAME"
#define WIFI_PASS "YOUR_WIFI_PASS"
#define WEBSERVER_PORT 80

/*
 * Globals
 */
static SoftwareSerial server(WEBSERVER_RX, WEBSERVER_TX);

/*
 * Function definitions
 */
void initialize_webserver();
void handle_clients();
bool send_command(String command, String acknowledge);
bool wait_acknowledge(String acknowledge);
String extract_client_id(String request);
String extract_path(String request);
String prepare_response(String content_type, String content);
void send_response(String response);
void handle_control_panel_page_request(String client_id);
void handle_fetch_sensor_data_request(String client_id);

#endif /* WEBSERVER_H_ */
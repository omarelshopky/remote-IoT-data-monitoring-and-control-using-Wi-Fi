#include "../include/webserver.h"
#include "../include/control_page.h"
#include "../include/leds.h"


void initialize_webserver() {
    Serial.begin(9600);
    server.begin(9600);

    send_command("AT+RST", "ready");
    //delay(5000);
    send_command("AT+CWJAP=\"" + String(WIFI_NAME) + "\",\"" + String(WIFI_PASS) + "\"", "OK");
    send_command("AT+CWMODE=1", "OK");
    send_command("AT+CIFSR", "OK");
    send_command("AT+CIPMUX=1", "OK");
    send_command("AT+CIPSERVER=1," + String(WEBSERVER_PORT), "OK");
}

void handle_clients() {
    while (server.available()) {
        String client_request = server.readString();
        //Serial.println(client_request);
        String client_id = extract_client_id(client_request);

        if (client_id != "" && client_request.indexOf("GET") != -1) {
            String path = extract_path(client_request);

            if (path == "/") {
                handle_control_panel_page_request(client_id);
            }
            else if (path.indexOf("/leds") != -1) {
                handle_control_leds_request(client_id, path);
            }
            else if (path == "/fetch") {
                handle_fetch_sensor_data_request(client_id);
            }
        }
    }
}

bool send_command(String command, String acknowledge) {
    server.println(command);

    return wait_acknowledge(acknowledge);
}

bool wait_acknowledge(String acknowledge) {
    byte current_char_index = 0;
    byte acknowledge_length = acknowledge.length();
    long deadline = millis() + TIMEOUT;

    while (millis() < deadline) {
        if (server.available()) {
            char ch = server.read();
            Serial.write(ch);

            if (ch == acknowledge[current_char_index])
                if (++current_char_index == acknowledge_length) {
                    Serial.println();
                    return true;
                }
        }
    }

    return false; // Timed out
}

String extract_client_id(String request) {
    int index = request.indexOf("+IPD,");

    if (index == -1)
        return "";

    String client_id = "";
    index += 5;

    while (true) {
        if (request[index] == ',')
        return client_id;

        client_id += request[index++];
    }
}

String extract_path(String request) {
    int index = request.indexOf("/"), end_index = request.indexOf(" HTTP");
    String path = "";

    if (index == -1 || end_index == -1)
        return "";

    while (index != end_index) {
        path += request[index++];
    }

    return path;
}

String prepare_response(String content_type, String content) {
    String response = "HTTP/1.1 200 OK\r\n";
    response += "Content-Type: " + content_type + "\r\n";
    response += "Content-Length: " + String(content.length())  + "\r\n";
    response += "Connection: close\r\n";
    response += "\r\n";
    response += content;

    return response;
}

void send_response(String client_id, String content_type, String content) {
    String response = prepare_response(content_type, content);
    send_command("AT+CIPSEND=" + client_id + "," + String(response.length()), ">");
    send_command(response, "SEND OK");
    //send_command("AT+CIPCLOSE=" + client_id, "OK");
}

void handle_control_panel_page_request(String client_id) {
    int total_length = strlen_P(control_page_html), chunk_length;
    const char* control_page_html_byte = control_page_html;

    while (pgm_read_byte(control_page_html_byte)) {
        chunk_length = min(total_length, CHUNK_SIZE);
        total_length -= chunk_length;

        send_command("AT+CIPSEND=" + client_id + "," + String(chunk_length), ">");

        for (int chunk_iteration = 0; chunk_iteration < chunk_length; chunk_iteration++) {
            server.write(pgm_read_byte(control_page_html_byte++));
        }

        wait_acknowledge("SEND OK");
    }

    //send_command("AT+CIPCLOSE=" + client_id, "OK");
}

void handle_fetch_sensor_data_request(String client_id) {
    send_response(client_id, "text/plain", "45,1,1");
}

void handle_control_leds_request(String client_id, String control_order) {
    bool is_turn_on_order = control_order.indexOf("turn_on") != -1 ? true : false;

    switch(control_order[6]) {
        case '1':
            switch_led(FIRST_LED, is_turn_on_order ? TURN_ON : TURN_OFF);
            break;
        case '2':
            switch_led(SECOND_LED, is_turn_on_order ? TURN_ON : TURN_OFF);
            break;
    }

    send_response(client_id, "text/plain", "Done");
}
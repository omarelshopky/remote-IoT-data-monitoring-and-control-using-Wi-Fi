#include "../include/display.h"


void initialize_display() {
	lcd.begin(16, 2);
	create_symbols();
	print_init_message();
}

void create_symbols() {
	lcd.createChar(TEMP_SYMBOL, temp_symbol_map);
	lcd.createChar(SMOKE_SYMBOL, smoke_symbol_map);
	lcd.createChar(MOTION_SYMBOL, motion_symbol_map);
}

void print_init_message() {
	lcd.setCursor(0, 0);
	lcd.print("IoT Data Monitor");

	lcd.setCursor(0, 1);
	lcd.print("Initializing...");
}

void display_sensors_data(float temperature, bool smoke_detected, bool motion_detected) {
	lcd.clear();
	lcd.print("Temp: ");
	lcd.print(temperature);
	lcd.write(TEMP_SYMBOL);
	lcd.print("C");

	if (smoke_detected) {
		lcd.setCursor(0, 1);
		lcd.write(SMOKE_SYMBOL);
		lcd.print(" Smoke");
	}

	if (motion_detected) {
		lcd.setCursor(8, 1);
		lcd.write(MOTION_SYMBOL);
		lcd.print(" Motion");
	}
}
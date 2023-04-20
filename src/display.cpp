#include "../include/display.h"


void initialize_display() {
	lcd.begin(16, 2);
}

void display(unsigned char temperature, bool smoke_detected, bool motion_detected) {
	lcd.clear();
	lcd.print("T: ");
	lcd.print(temperature);
	lcd.print("'C ");
	
	lcd.setCursor(1, 0);
	
	if (smoke_detected && motion_detected) {
		lcd.print("Smoke & Motion Detected");
	} 
	else if (smoke_detected) {
		lcd.print("Smoke Detected");
	} 
	else if (motion_detected) {
		lcd.print("Motion Detected");
	}
}
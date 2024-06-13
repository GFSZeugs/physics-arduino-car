#include <Arduino.h>
#include "engine.h"
#include "constants.h"

// Engine *e;

void setup() {
	pinMode(PWM_PIN, OUTPUT);
	// pinMode(DIR_PIN, OUTPUT);

	// e = new Engine{PWM_PIN, DIR_PIN};
	// (*e).kickstart(150);
	// delay(2500);
	// (*e).setThrust(170);
	Serial.begin(9600);
	delay(5000);
}

void loop() {
	for (int i = 150; i < 250; i++) {
		analogWrite(PWM_PIN, i);
		Serial.println(i);
		delay(500);
	}


	analogWrite(PWM_PIN, 0);
	delay(60000);
}

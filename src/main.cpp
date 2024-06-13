#include <Arduino.h>
#include "engine.h"
#include "constants.h"

// Engine *e;

void setup() {
	pinMode(5, OUTPUT);
	// pinMode(DIR_PIN, OUTPUT);

	// e = new Engine{PWM_PIN, DIR_PIN};
	// (*e).kickstart(150);
	// delay(2500);
	// (*e).setThrust(170);
}

void loop() {
	analogWrite(5, 160);
	delay(10000);
	analogWrite(5, 0);
	delay(60000);
}

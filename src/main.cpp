#include <Arduino.h>
#include "engine.h"
#include "constants.h"

Engine *e;

void setup() {
	pinMode(PWM_PIN, OUTPUT);
	// pinMode(DIR_PIN, OUTPUT);

	e = new Engine{PWM_PIN, DIR_PIN};
	delay(5000);
	(*e).kickstart(190);
	delay(10000);
	(*e).setThrust(0);
}

void loop() {
}

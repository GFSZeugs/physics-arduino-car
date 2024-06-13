#include <Arduino.h>
#include "engine.h"
#include "constants.h"

Engine e;

void setup() {
	pinMode(PWM_PIN, OUTPUT);
	pinMode(DIR_PIN, OUTPUT);

	e = Engine{PWM_PIN, DIR_PIN};
	e.kickstart(150);
	delay(5000);
	e.setThrust(0);
}

void loop() {
}

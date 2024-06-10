#include <Arduino.h>
#include "engine.h"

Engine *e;

const int pwmPin = 3;
const int dirPin = 5;

int direction = 0;

void setup() {
	pinMode(pwmPin, OUTPUT);
	pinMode(dirPin, OUTPUT);

	e = new Engine(pwmPin, dirPin);
}

void loop() {
	for (float thrust = 0.1; thrust < 1.0; thrust += 0.1) {
		(*e).setThrust(thrust);
		delay(1000);
	}

	digitalWrite(pwmPin, 0);
	delay(5000);
	direction = direction == 0 ? 1 : 0;
	digitalWrite(dirPin, direction);
}

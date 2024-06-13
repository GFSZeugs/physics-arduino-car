#include <Arduino.h>
#include "engine.h"
#include "constants.h"

Engine *e;

void setup() {
	pinMode(PWM_PIN, OUTPUT);
	pinMode(DIR_PIN, OUTPUT);

	e = new Engine{PWM_PIN, DIR_PIN};
	// (*e).kickstart(150);
	// delay(2500);
	// (*e).setThrust(170);
	Serial.begin(9600);
}

void loop() {
	Serial.println("Hola mi amigo");
	delay(1000);
	// analogWrite(PWM_PIN, 200);
	// delay(10000);
	// analogWrite(PWM_PIN, 0);
	// delay(60000);
}

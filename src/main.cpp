#include <Arduino.h>
#include <Servo.h>
#include "constants.h"

volatile bool active = false;
int timeSinceISR = 0;

enum Lenkrichtung {
	GERADE = 80,
	LINKS = 130,
	RECHTS = 40
};

Servo lenkung;
Servo motor;

void taster_isr() {
	int currentTime = millis();
	if (currentTime - timeSinceISR < 1000) {
		return;
	}
	timeSinceISR = currentTime;
	Serial.println(active);
	active = !active;
}

void setup() {
	pinMode(PWM_PIN, OUTPUT);
	pinMode(LENKUNG_PIN, OUTPUT);
	pinMode(TASTER_PIN, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(TASTER_PIN), taster_isr, FALLING);
	
	Serial.begin(9600);

	motor.attach(PWM_PIN);
	motor.writeMicroseconds(2000);
	delay(100);
	motor.writeMicroseconds(1500);

	lenkung.attach(LENKUNG_PIN);
	lenkung.write(GERADE);
}

void loop() {
	while (!active) { 
		Serial.println("Nothing");
	}

	motor.writeMicroseconds(1600);
	for (int i = 0; i < 100; i++) {
		if (!active) goto cleanup;
		delay(10);
	}

	motor.writeMicroseconds(0);

	lenkung.write(LINKS);
	for (int i = 0; i < 100; i++) {
		if (!active) goto cleanup;
		delay(10);
	}

	motor.writeMicroseconds(1600);
	for (int i = 0; i < 200; i++) {
		if (!active) goto cleanup;
		delay(10);
	}

	motor.writeMicroseconds(0);
	lenkung.write(GERADE);
	for (int i = 0; i < 100; i++) {
		if (!active) goto cleanup;
		delay(10);
	}

	motor.writeMicroseconds(1600);
	for (int i = 0; i < 100; i++) {
		if (!active) goto cleanup;
		delay(10);
	}


cleanup:
	Serial.println("cleanup");
	active = false;
	motor.writeMicroseconds(0);
	delay(3000);
}

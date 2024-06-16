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
	pinMode(TASTER_PIN, INPUT_PULLUP);

	attachInterrupt(digitalPinToInterrupt(TASTER_PIN), taster_isr, FALLING);

	lenkung.attach(LENKUNG_PIN);

	Serial.begin(9600);
}

void loop() {
	while (!active) { 
		Serial.println("Nothing");
	}

	delay(500);
	// Warmup motor
	for (int i = 240; i < 255; i++) {
		if (!active) { goto cleanup; }
		Serial.println(i);
		analogWrite(PWM_PIN, i);
		delay(750);
	}

	lenkung.write(RECHTS);

	// Drive for
	for (int i = 0; i < 1000; i++) {
		if (!active) { goto cleanup; }
		delay(1);
	}

	lenkung.write(GERADE);

cleanup:
	Serial.println("GME auf 3000");
	active = false;
	analogWrite(PWM_PIN, 0);
	delay(3000);
}

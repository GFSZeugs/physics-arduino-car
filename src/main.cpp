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
	lenkung.write(GERADE);

	Serial.begin(9600);
}

int warmupMotor(int target) {
	// Warmup motor
	for (int i = 200; i < target; i++) {
		if (!active) { return -1; }
		Serial.println(i);
		analogWrite(PWM_PIN, i);
		delay(750);
	}

	return 0;
}

void loop() {
	while (!active) { 
		Serial.println("Nothing");
	}

	digitalWrite(PWM_PIN, HIGH);

	delay(500);

	if (warmupMotor(220) == -1) {
		goto cleanup;
	}

	delay(3000);

	if (warmupMotor(220) == -1) {
		goto cleanup;
	}

	delay(1000);

cleanup:
	Serial.println("GME auf 3000");
	active = false;
	analogWrite(PWM_PIN, 0);
	delay(3000);
}

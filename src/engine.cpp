#include <Arduino.h>
#include "engine.h"
#include "utility.h"

Engine::Engine(int pwmPin, int dirPin) {
    this->pwmPin = pwmPin;
    this->dirPin = dirPin;

    this->thrust = 0.0f;
    this->dir = FORWARD;
}

float Engine::getThrust() {
    return this->thrust;
}

void Engine::setThrust(float thrust) {
    this->thrust = clamp(thrust, 0.0f, 1.0f);
    analogWrite(this->pwmPin, (int) thrust * 255);
}

Direction Engine::getDirection() {
    return this->dir;
}

void Engine::setDirection(Direction dir) {
    this->dir = dir;
    digitalWrite(this->dirPin, dir == BACKWARD ? HIGH : LOW);
}

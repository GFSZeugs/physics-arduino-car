#include <Arduino.h>
#include "constants.h"
#include "engine.h"
#include "utility.h"

Engine::Engine(int pwmPin, int dirPin) {
    this->pwmPin = pwmPin;
    this->dirPin = dirPin;

    this->thrust = 0;
    this->dir = FORWARD;
}

int Engine::getThrust() {
    return this->thrust;
}

void Engine::setThrust(int thrust) {
    analogWrite(this->pwmPin, thrust);
}

void Engine::kickstart(int thrustAfter) {
    analogWrite(this->pwmPin, KICKSTART_PWM_MOD);
    delay(KICKSTART_DELAY);
    analogWrite(this->pwmPin, thrustAfter);
}

Direction Engine::getDirection() {
    return this->dir;
}

void Engine::setDirection(Direction dir) {
    this->dir = dir;
    digitalWrite(this->dirPin, dir == BACKWARD ? HIGH : LOW);
}

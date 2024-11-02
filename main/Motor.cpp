
//#include "main.h"
#include "Motor.h"

// Constructor: Initialize motor control pins
MOTOR::MOTOR(uint8_t portA_pin1, uint8_t portB_pin2, uint8_t pwmPin) {
    this->portA_pin1 = portA_pin1;
    this->portB_pin2 = portA_pin1;
    this->pwmPin = pwmPin;
}

// Motor initialization (sets pin modes)
void MOTOR::motor_init() {
    pinMode(portA_pin1, OUTPUT);
    pinMode(portB_pin2, OUTPUT);
    pinMode(pwmPin, OUTPUT);
}

// Rotate motor clockwise
void MOTOR::clockwise(int pwm) {
    digitalWrite(portA_pin1, HIGH);
    digitalWrite(portB_pin2, LOW);
    analogWrite(pwmPin, pwm);  // Write PWM value to pwmPin
}

// Rotate motor anti-clockwise
void MOTOR::anti_clockwise(int pwm) {
    digitalWrite(portA_pin1, LOW);
    digitalWrite(portB_pin2, HIGH);
    analogWrite(pwmPin, pwm);  // Write PWM value to pwmPin
}

// Stop the motor
void MOTOR::brake() {
    digitalWrite(portA_pin1, LOW);
    digitalWrite(portB_pin2, LOW);
    analogWrite(pwmPin, 0);  // Set PWM to zero to stop motor
}
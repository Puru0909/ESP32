#ifndef MOTOR_H_
#define MOTOR_H_

#include <Arduino.h>
//#include "main.h"
#include "Motor.h"

class MOTOR {
protected:
    uint8_t portA_pin1, portB_pin2;  
    uint8_t pwmPin;                  

public:
    MOTOR(uint8_t portA_pin1, uint8_t portB_pin2, uint8_t pwmPin);
    void motor_init();
    void clockwise(int pwm);
    void anti_clockwise(int pwm);
    void brake();
};

#endif
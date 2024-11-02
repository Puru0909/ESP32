 
// #include "main.h"
 #include "Motor.h"


// Define pins for the motor control
// const uint8_t portA_pin1 = 9;   // Direction control pin 1
// const uint8_t portB_pin2 = 10;   // Direction control pin 2
// const uint8_t pwmPin = 21;       // PWM control pin

// MOTOR object
MOTOR motor(8, 9, 10);


// MOTOR motor_1(GPIOB,GPIO_PIN_9,GPIOB, GPIO_PIN_8 );

// MOTOR motor_2(GPIOB,GPIO_PIN_4,GPIOB, GPIO_PIN_3);

// MOTOR motor_3(GPIOA,GPIO_PIN_6,GPIOA, GPIO_PIN_7);

void setup() {
    Serial.begin(115200);
    motor.motor_init();
}

void loop() {
    
    motor.clockwise(128);
    delay(2000);

    
    motor.brake();
    delay(1000);

    
    motor.anti_clockwise(192);  
    delay(2000);

    
    motor.brake();
    delay(1000);
}

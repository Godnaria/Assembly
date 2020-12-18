#include <HCSR04.h>
#include "motor.h"

UltraSonicDistanceSensor distanceSensor_middle(MIDDLE_TRIG, MIDDLE_ECHO);
UltraSonicDistanceSensor distanceSensor_left(LEFT_TRIG, LEFT_ECHO);
UltraSonicDistanceSensor distanceSensor_right(RIGHT_TRIG, RIGHT_ECHO);

void setup () 
{
    Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
    pinMode(MIDDLE_TRIG,INPUT);
    pinMode(MIDDLE_ECHO,INPUT);
    pinMode(LEFT_TRIG,INPUT);
    pinMode(LEFT_ECHO,INPUT);
    pinMode(RIGHT_TRIG,INPUT);
    pinMode(RIGHT_ECHO,INPUT);
    pinMode(MOTOR_A1,OUTPUT);
    pinMode(MOTOR_A2,OUTPUT);
    pinMode(MOTOR_B1,OUTPUT);
    pinMode(MOTOR_B2,OUTPUT);
}

void loop () 
{
    digitalWrite(MOTOR_B1,255);
    digitalWrite(MOTOR_B2,255);
    // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters.
    double distance = distanceSensor_middle.measureDistanceCm();
    if(distance <= 20)
    {
        if(distanceSensor_left.measureDistanceCm() <= 20)
            turn_right(200);
        else 
            turn_left(200);
    }
    Serial.println(distance);
    delay(500);
}
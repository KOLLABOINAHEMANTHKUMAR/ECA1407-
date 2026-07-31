#include "pid_controller.h"

float Kp = 2.0;
float Ki = 0.5;
float Kd = 1.0;

float previousError = 0;
float integral = 0;

float calculatePID(float setPoint, float currentTemp)
{
    float error;
    float derivative;
    float output;

    error = currentTemp - setPoint;

    integral = integral + error;

    derivative = error - previousError;

    output = (Kp * error) +
             (Ki * integral) +
             (Kd * derivative);

    previousError = error;

    if(output < 0)
        output = 0;

    if(output > 100)
        output = 100;

    return output;
}
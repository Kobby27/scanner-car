#include <ESP32Servo.h>

Servo myservo; // An object called myservo using the preexisting class "Servo"

int pos = 0;
unsigned long lastServoMove = 0;
const int servoInterval = 15;
bool sweepingUp = true;

void radar_setup()
{

    myservo.attach(32);
}

void radar()
{

    unsigned long now = millis();
    if (now - lastServoMove >= servoInterval)
    {
        lastServoMove = now;

        if (sweepingUp)
        {
            pos++;
            if (pos >= 180)
                sweepingUp = false;
        }
        else
        {
            pos--;
            if (pos <= 0)
                sweepingUp = true;
        }

        myservo.write(pos);
    }
}
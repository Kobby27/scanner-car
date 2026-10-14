#include <UltrasonicSensor.h>
#include "lcd.h"
#include <Wire.h>
#include "servo.h"

UltrasonicSensor ultrasonic(18, 19);
int distance;
const int Red_LED = 23;
const int Yellow_LED = 2;
const int Green_LED = 5;
const int Buzzer = 4;

void setup()
{
   Serial.begin(115200);
   pinMode(Red_LED, OUTPUT);
   pinMode(Yellow_LED, OUTPUT);
   pinMode(Green_LED, OUTPUT);
   pinMode(Buzzer, OUTPUT);

   lcdSetup();
   radar_setup();

   int temperature = 21.5;
   ultrasonic.setTemperature(temperature);
}

void proximity(){
 distance = ultrasonic.distanceInMillimeters();

if(distance < 100)
{
digitalWrite(Red_LED, HIGH);
digitalWrite(Yellow_LED, LOW);
digitalWrite(Green_LED, LOW);
}
else if (distance >= 100 && distance < 250)
{
  digitalWrite(Red_LED, LOW);
  digitalWrite(Yellow_LED, HIGH);
  digitalWrite(Green_LED, LOW);
}

else {
  digitalWrite(Red_LED, LOW);
  digitalWrite(Yellow_LED, LOW);
  digitalWrite(Green_LED, HIGH); 
}

}


void loop()
{
  radar();
  proximity();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" mm");

  displayDistance();
  delay(200);
}

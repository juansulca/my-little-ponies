#include <Servo.h>

int SERVO_PIN = 9;
int LIGHT_SENSOR = A0;
int lightSensorValue;
bool isActive = false;
unsigned long time = 0;
unsigned long prevTime = 0;
Servo mainAxis;

void setup()
{
  Serial.begin(9600);
  mainAxis.attach(SERVO_PIN);
  prevTime = millis();
}

void loop()
{
  time = millis();

  if (time - prevTime > 1000)
  {
    if (isActive)
    {
      mainAxis.write(105);
    }
    else
    {
      mainAxis.write(92);
    }

    lightSensorValue = analogRead(LIGHT_SENSOR);
    if (lightSensorValue <= 880)
    {
      isActive = true;
    }
    else
    {
      isActive = false;
    }
    Serial.println(lightSensorValue);
    prevTime = time;
  }
}

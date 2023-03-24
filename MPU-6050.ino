// Basic demo for accelerometer readings from Adafruit MPU6050

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
int buzzer = 7;
int incomingByte = 0;

Adafruit_MPU6050 mpu;

void setup(void) {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);

  while (!Serial)
    delay(10); 

  Serial.println("MPU6050 test!");

  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");
}

void loop() {

  if (Serial.available() > 0) 
    {
    // read the incoming byte:
    incomingByte = Serial.read();
    
      int x1 = a.acceleration.x;
      int y1 = a.acceleration.y;
      int z1 = a.acceleration.z;
      if (y1 < -2)
      {
        Serial.println("w");
      else if (y1 > 2)
        Serial.println("s");
      else if (x1 < -2)
        Serial.println("d");
      else if (x1 > 2)
        Serial.println("a");
    }
  if (incomingByte == 'B')
    { digitalWrite(buzzer, HIGH);
      delay(500);
      digitalWrite(buzzer, LOW);
    }
  }
  delay(500);
}

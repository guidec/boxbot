#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"
#include "math.h"

#define leftMotorPWMPin   2
#define leftMotorDirPin   3
#define rightMotorPWMPin  4
#define rightMotorDirPin  5

MPU6050 mpu;

int16_t accY, accZ;
float accAngle;

void setup() {  
  mpu.initialize();
  Serial.begin(9600);
  pinMode(leftMotorPWMPin, OUTPUT);
  pinMode(leftMotorDirPin, OUTPUT);
  pinMode(rightMotorPWMPin, OUTPUT);
  pinMode(rightMotorDirPin, OUTPUT);
}

void loop() {  

  accZ = mpu.getAccelerationZ();
  accY = mpu.getAccelerationY();
   
  accAngle = atan2(accY, accZ)*RAD_TO_DEG;
  
  analogWrite(leftMotorPWMPin,(abs(accAngle*3)));
  digitalWrite(leftMotorDirPin, LOW);
  analogWrite(rightMotorPWMPin, abs(accAngle*3));
  digitalWrite(rightMotorDirPin, LOW);

  
  if(isnan(accAngle));
  else
    Serial.println(static_cast<int>(accAngle));
}

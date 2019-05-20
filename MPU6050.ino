//This is an example of mpu6050, connect vcc to vcc, gnd to gnd and scl to a5 and sda to a4
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"


MPU6050 sensor;


int ax, ay, az;
int gx, gy, gz;

void setup() {
  
  Serial.begin(57600);    
  Wire.begin();            
  sensor.initialize();    

  if (sensor.testConnection()) Serial.println("Sensor started correctly");
  else Serial.println("Error when starting sensor");
}

void loop() {
  
 
  sensor.getAcceleration(&ax, &ay, &az);
  sensor.getRotation(&gx, &gy, &gz);
  
  Serial.print("a[x y z] g[x y z]:\t");
  Serial.print(ax); Serial.print("\t");
  Serial.print(ay); Serial.print("\t");
  Serial.print(az); Serial.print("\t");
  Serial.print(gx); Serial.print("\t");
  Serial.print(gy); Serial.print("\t");
  Serial.println(gz);

  delay(100);
}

// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Re-writed by Arbi Abdul Jabbaar
// Using Arduino IDE 1.8.7
// Using HC-SR04 Module
// Tested on 17 September 2019
// ---------------------------------------------------------------- //
#include <Arduino.h>

#include "Sensor.h"
#include "NewPing.h"
NewPing X_tengely(6,7, 37);
NewPing Y_tengely(2,3,30);
//Sensor X_tengely(6, 7, 10);
//Sensor Y_tengely(2,3,9);
int iterations = 3;
float x_duration, x_distance, x_mapped;
float y_duration, y_distance, y_mapped;

void setup() {
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  //X_tengely.init(2,25);
  //Y_tengely.init(4,29);
}
void loop() {
  delay(29); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  
  x_duration = X_tengely.ping_median(iterations);
  x_distance = (x_duration / 2) * 0.0343;

  //analogWrite(9,map(x_distance,2,30,0,255));
  y_duration = Y_tengely.ping_median(iterations);
  y_distance = (y_duration / 2) * 0.0343;

  //analogWrite(10,map(y_distance,4,30,0,255));
  x_mapped = map(x_distance,2,37,0,255);
  y_mapped = map(y_distance,4,30,0,255);

  analogWrite(9,x_mapped);
  analogWrite(10,y_mapped);
  Serial.println(y_mapped);
  //  X_tengely.Value();
    //Y_tengely.Value();

    //X_tengely.Serial_Print_Value();
    //Y_tengely.Serial_Print_Value();
}
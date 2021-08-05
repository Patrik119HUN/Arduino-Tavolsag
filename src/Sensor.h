
#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

class Sensor {
   private:
    long duration;
    int distance;
    long AnalogValue;
    
    int m_min;
    int m_max;
    int m_trigger;
    int m_echo;
    int m_output;

   public:
    Sensor(int trigger, int echo, int output);
    void init(int min,int max);
    long Value();
    void Serial_Print_Value();
};

Sensor::Sensor(int trigger, int echo, int output) {
    this->m_trigger = trigger;
    this->m_echo = echo;
    this->m_output = output;
}
void Sensor::init(int min, int max){

    this->m_min = min;
    this->m_max = max;
    pinMode(m_trigger, OUTPUT);  // Sets the trigPin as an OUTPUT
    pinMode(m_echo, INPUT);   // Sets the echoPin as an INPUT
    pinMode(m_output, OUTPUT);
    Serial.begin(9600);
}

long Sensor::Value() {
    digitalWrite(m_trigger, LOW);
    delayMicroseconds(2);
    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(m_trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(m_trigger, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(m_echo, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;  // Speed of sound wave divided by 2 (go and back)
    // Displays the distance on the Serial Monitor
    AnalogValue = map(distance, m_min, m_max, 0, 255);
    analogWrite(m_output, AnalogValue);
}
void Sensor::Serial_Print_Value() {
    Serial.println("");
    Serial.print(distance);
    Serial.print("   ");
    Serial.print(AnalogValue);
}


#endif
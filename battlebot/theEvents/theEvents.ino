#include <WiFi.h>
#include <analogWrite.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Adafruit_VL53L0X.h"
#include <Wire.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <sstream>


// Motor Directions
#define RF 18
#define RB 5
#define LF 16
#define LB 17

//left Sensor pin(LSP) on analogPin 34
int LSP = 34;
//right Sensor pin(RSP) on analogPin 39
int RSP = 39;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

// Sensor pins are INPUT
  pinMode(LSP, INPUT);
  pinMode(RSP, INPUT);

  //Motor pins are OUTPUT
  pinMode(RF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(LF, OUTPUT);
  pinMode(LB, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  followTheLine();
}

void forward(){
  analogWrite(RF, 140);//150 - 145 - 135 - 140
  analogWrite(LF, 130);//165 - 155 - 145 - 130
  analogWrite(RB, 0);
  analogWrite(LB, 0);
  //delay(30);
  }

  void backward(){
  analogWrite(RF, 0);
  analogWrite(LF, 0);
  analogWrite(RB, 130);
  analogWrite(LB, 140);
  }  

  void leftTurn(){
  analogWrite(RF, 150);//120 - 140
  analogWrite(LF, 0);
  analogWrite(RB, 0);
  analogWrite(LB, 150);//105 
  //delay(30);
}

void rightTurn(){
  analogWrite(RF, 0);
  analogWrite(LF, 155);//120 - 140 - 150
  analogWrite(RB, 165);//105 - 150
  analogWrite(LB, 0);
  //delay(30);
  
}

void stopRobot(){
  analogWrite(RF, 0);
  analogWrite(LF, 0);
  analogWrite(RB, 0);
  analogWrite(LB, 0);
}


  //Follow the line event
 void followTheLine(){

  int leftSensor = digitalRead(LSP);
  int RightSensor = digitalRead(RSP);

if (leftSensor == 0 && RightSensor == 0 )
  {
        forward();
  }
  
  else if (leftSensor == 0 && RightSensor == 1)
  {
        leftTurn();
  }
  
  else if (leftSensor == 1 && RightSensor == 0)
  {
        rightTurn();
   }
  
  else if (leftSensor == 1 && RightSensor == 1)
  {
  stopRobot();
  }
    
}

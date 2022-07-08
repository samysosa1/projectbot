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

  //Motor pins are OUTPUT
  pinMode(RF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(LF, OUTPUT);
  pinMode(LB, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  uniqueSkill();
}

void stopRobot() {
  digitalWrite(RF, LOW);
  digitalWrite(LF, LOW);
  digitalWrite(RB, LOW);
  digitalWrite(LB, LOW);
}

void leftTurn() {
  digitalWrite(RF, HIGH);//120
  digitalWrite(LF, LOW);
  digitalWrite(RB, LOW);
  digitalWrite(LB, HIGH);//105  
}

void rightTurn() {
  digitalWrite(RF, LOW);
  digitalWrite(LF, HIGH);//120
  digitalWrite(RB, HIGH);//105
  digitalWrite(LB, LOW);  
}

void forward() {
  digitalWrite(RF, HIGH);//150
  digitalWrite(LF, HIGH);//165
  digitalWrite(RB, LOW);
  digitalWrite(LB, LOW);
}

void backward() {
  digitalWrite(RB, HIGH);
  digitalWrite(LB, HIGH);
  digitalWrite(RF, LOW);
  digitalWrite(LF, LOW);
}


void uniqueSkill(){
  
//  stopRobot();
//  delay(5000);
//  forward();
//  delay(5000);
//  rightTurn();
//  delay(1000);
//  forward();
//  delay(2500);
//  rightTurn();
//  delay(1000);

  stopRobot();
  delay(2000);
  forward();
  delay(500);
  stopRobot();
  delay(1000);
  rightTurn();
  delay(240);
  stopRobot();
  delay(1000);
  forward();
  delay(500);
  stopRobot();
  delay(1000);
  rightTurn();
  delay(230);
  stopRobot();
  delay(1000);
  forward();
  delay(500);
  stopRobot();
  delay(1000);
  rightTurn();
  delay(230);
  stopRobot();
  delay(1000);
  forward();
  delay(500);
  
//reverse
  stopRobot();
  delay(2000);
  backward();
  delay(500);
  stopRobot();
  delay(1000);
  leftTurn();
  delay(230);
  stopRobot();
  delay(1000);
  backward();
  delay(500);
  stopRobot();
  delay(1000);
  leftTurn();
  delay(230);
  stopRobot();
  delay(1000);
  backward();
  delay(500);
  stopRobot();
  delay(1000);
  leftTurn();
  delay(230);
  stopRobot();
  

}

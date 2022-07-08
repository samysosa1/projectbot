#include <WiFi.h>
#include <analogWrite.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Adafruit_VL53L0X.h"
#include <Wire.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <sstream>

////WI-FI
//const char* ssid = "Sambal";
//const char* pass = "";

////set web server
//WiFiServer server (80); 


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
//  WiFi.begin(ssid, pass);
//  server.begin();

// Sensor pins are INPUT
  pinMode(LSP, INPUT);
  pinMode(RSP, INPUT);

  //Motor pins are OUTPUT
  pinMode(RF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(LF, OUTPUT);
  pinMode(LB, OUTPUT);

}

//  String payload="";
//  int payloadInt= payload.toInt(); 

void loop() {
  // put your main code here, to run repeatedly:

//  HTTPClient http;
//  http.begin("http://10.110.110.158/battlebot/index.php");
//  int httpCode = http.GET(); 
//
//  if (httpCode > 0) { // if code is returning 
//    
//         payloadInt= payload.toInt();
//         payload = http.getString();
//         Serial.println(httpCode);
//         Serial.println(payload);
//      }

  
  maze();

}

void stopRobot() {
  digitalWrite(RF, LOW);
  digitalWrite(LF, LOW);
  digitalWrite(RB, LOW);
  digitalWrite(LB, LOW);
}

void leftTurn() {
  digitalWrite(RF, HIGH);
  digitalWrite(LF, LOW);
  digitalWrite(RB, LOW);
  digitalWrite(LB, HIGH); 
}

void rightTurn() {
  digitalWrite(RF, LOW);
  digitalWrite(LF, HIGH);
  digitalWrite(RB, HIGH);
  digitalWrite(LB, LOW);  
}

void forward() {
  digitalWrite(RF, HIGH);
  digitalWrite(LF, HIGH);
  digitalWrite(RB, LOW);
  digitalWrite(LB, LOW);
}

void backward() {
  digitalWrite(RB, HIGH);
  digitalWrite(LB, HIGH);
  digitalWrite(RF, LOW);
  digitalWrite(LF, LOW);
}

void maze(){
  
  int leftSensor = digitalRead(LSP);
  int RightSensor = digitalRead(RSP);


  if (leftSensor == 0 && RightSensor == 0 )
  {
    
        stopRobot();
        delay(1000);
        backward();
        delay(200);
        rightTurn();
        delay(100);
        forward();
        delay(250);
        
    

//        if(leftSensor == 0 && RightSensor == 0 ){
//          stopRobot();
//          delay(1000);
//          backward();
//          delay(200);
//          leftTurn();
//          delay(600);
//          forward();
//          delay(250);
//        }
  }
  
  else if (leftSensor == 0 && RightSensor == 1)
  {
        stopRobot();
        delay(1000);
        backward();
        delay(100);
        leftTurn();
        delay(100);
        
  }
  else if (leftSensor == 1 && RightSensor == 0)
  {
        stopRobot();
        delay(1000);
        backward();
        delay(100);
        rightTurn();
        delay(100);
   }
  
  else if (leftSensor == 1 && RightSensor == 1)
  {
        stopRobot();
        delay(1000);
        forward();
        delay(120);
        stopRobot();
        delay(200);   
  }
  
}

/* 
 * Project Self_Control_Through_Automation
 * Author: Benjamin Brown
 * Date: 06282025
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */


#include "Particle.h"
#include "IoTTimer.h"


const int therm_PIN = D5;
const int potPin = A5;
int potPos;
bool HOT;
int newState;
int oldState;

IoTTimer timer;
Servo myServo;


SYSTEM_MODE(SEMI_AUTOMATIC);

void setup() {
  Serial.begin(9600);
  waitFor(Serial.isConnected,10000);
  pinMode(therm_PIN,INPUT);
  myServo.attach(potPin);
  Serial.printf("Wait for Calibration");
  timer.startTimer(1000*10);
  if(timer.isTimerReady()){
    Serial.printf("Calibrated!");
  }
  oldState=digitalRead(therm_PIN);
}

void loop() {
 // newState=digitalRead(therm_PIN);
  //detect=detect/16;
  //f(timer.isTimerReady()){
    //   if(oldState!=newState){
    //     if(newState==TRUE){
    //   Serial.printf("DETECTED%i\n",newState);
    //   }else{
    //     Serial.printf("NOT NOT NOT %i\n",newState);
    //   }
    //   oldState=newState;
    //   //timer.startTimer(1000);
    // }

    potPos = analogRead(potPin);
    potPos = potPos/16;
if (timer.isTimerReady()){
    myServo.write(45);
    Serial.printf("Servo direction 1 == 45\n");
    delay(2500);
    myServo.write(95);
    Serial.printf(" Servo Stopped 2 = 85\n");
    delay(2500);
    myServo.write(180);
    Serial.printf(" Servo direction 2 = 180\n");
    delay(2500);
    timer.startTimer(2500);
}

}


void dispense(int p_per_msec){
  myServo.write(p_per_msec);
  int currentSec=millis();
  int currentSec != int lastSecond;


  

}

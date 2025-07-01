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
int dispenseTime = 1000;
static unsigned int disableTimerStart = 0;
int waitTime = 1000*30;
bool detected;

int newState;
int oldState;

unsigned int msec;
static unsigned int startTime=0;

int rotate = 60;
int stop = 191;

//Objects
IoTTimer timer;
Servo myServo;

//myFunctons
//void dispense(unsigned int msec);
bool detectionCheck();
SYSTEM_MODE(SEMI_AUTOMATIC);

void setup() {
  Serial.begin(9600);
  waitFor(Serial.isConnected,10000);
  pinMode(therm_PIN,INPUT);
  pinMode(potPin,OUTPUT);
  disableTimerStart = millis();
  oldState=digitalRead(therm_PIN);
}

void loop() {
  detected=detectionCheck();
  if (millis() - disableTimerStart > waitTime){
    if (detected){
      startTime=millis();
      analogWrite(potPin,rotate);
      Serial.printf("Dispensing%i\n",dispenseTime);
      disableTimerStart=millis();
    }
  }
  if (millis()-startTime>dispenseTime){
    analogWrite(potPin,stop);
  }
}


// void dispense(unsigned int msec){
//   static bool started = FALSE;
//   static unsigned int startTime=0;

//   int rotate = 60;
//   int stop = 192;
//   if (!started){
//     startTime=millis();
//     analogWrite(potPin,rotate);
//     started = TRUE;
//   }
//   if (millis()-startTime>msec){
//      analogWrite(potPin,stop);
//      started = FALSE;
//   }
//}
  
bool detectionCheck(){
 newState=digitalRead(therm_PIN);
    if(oldState!=newState){
      if(newState==TRUE){
    Serial.printf("DETECTED\n",newState);
    }else{
      Serial.printf("COLD\n",newState);
    }
    oldState=newState;
   
  } 
  return newState;
}



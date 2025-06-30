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
int dispenseTime = 50;
static bool disableTimerStarted = FALSE;
static unsigned int disableTimerStart = 0;
int waitTime = 1000*15;
bool detected;

int newState;
int oldState;

//Objects
IoTTimer timer;
Servo myServo;

//myFunctons
void dispense(unsigned int msec);
bool detectionCheck();;
SYSTEM_MODE(SEMI_AUTOMATIC);

void setup() {
  Serial.begin(9600);
  waitFor(Serial.isConnected,10000);
  pinMode(therm_PIN,INPUT);
  pinMode(potPin,OUTPUT);
  disableTimerStart = millis();
  // Serial.printf("Wait for Calibration");
  // timer.startTimer(1000*10);
  // if(timer.isTimerReady()){
  //   Serial.printf("Calibrated!");
  // }
  oldState=digitalRead(therm_PIN);
}

void loop() {
  detected=detectionCheck();
  if (millis() + waitTime > disableTimerStart){
  if (detected){
    disableTimerStart=millis();
    dispense(dispenseTime);
    //Serial.printf("Dispensing%i\n",dispenseTime);
    disableTimerStarted = TRUE;
  }
  if(!detected){
    analogWrite(potPin,191);
    //Serial.printf("Waiting\n");
    }
  if(waitTime+disableTimerStart>millis()){
    disableTimerStarted=FALSE;
  }

  }
}
  //  potPos = analogRead(potPin);
   // potPos = potPos/16;
// if (timer.isTimerReady()){
//     nalogWrite(potPin,180);
//     //myServo.write(45);
//     Serial.printf("Servo direction = 750\n");
//     delay(2500);
//     analogWrite(potPin,191);
//     //myServo.write(90);
//     Serial.printf(" Servo Stopped  = 1500\n");
//     delay(7500);
//     analogWrite(potPin,200);
//     //myServo.write(180);
//     Serial.printf(" Servo direction 2 = 2000\n");
//     delay(2500);
//     timer.startTimer(2500);
// }
 


void dispense(unsigned int msec){
  static bool started = FALSE;
  static unsigned int startTime=0;

  int rotate = 60;
  int stop = 192;
  if (!started){
    startTime=millis();
    analogWrite(potPin,rotate);
    started = TRUE;
  }
  if (millis()-startTime>msec){
     analogWrite(potPin,stop);
     started = FALSE;
  }
}
  
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



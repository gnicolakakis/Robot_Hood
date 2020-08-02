/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 2.4.3 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.5.1 or later version;
     - for iOS 1.4.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP8266_HARDSERIAL_POINT

#include <RemoteXY.h>

#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;
Servo servo8;
//arm
Servo servo9;
Servo servo10;
Servo servo11;

// RemoteXY connection settings 
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 115200
#define REMOTEXY_WIFI_SSID "RemoteXY"
#define REMOTEXY_WIFI_PASSWORD "123456789"
#define REMOTEXY_SERVER_PORT 6377


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,12,0,0,0,198,1,10,13,5,
  129,0,34,4,14,6,1,17,87,97,
  108,107,0,2,1,34,10,22,11,1,
  2,26,31,31,79,78,0,79,70,70,
  0,2,1,1,10,22,11,1,2,26,
  31,31,79,78,0,79,70,70,0,129,
  0,1,4,25,6,1,17,67,97,108,
  105,98,114,97,116,101,0,129,0,1,
  23,11,6,1,17,76,101,102,116,0,
  2,1,1,29,22,11,1,2,26,31,
  31,79,78,0,79,70,70,0,2,1,
  34,29,22,11,1,2,26,31,31,79,
  78,0,79,70,70,0,129,0,34,23,
  15,6,1,17,82,105,103,104,116,0,
  129,0,1,43,31,6,1,17,83,116,
  97,116,105,99,32,119,97,108,107,0,
  2,1,1,49,22,11,1,2,26,31,
  31,79,78,0,79,70,70,0,129,0,
  33,43,30,6,1,17,72,105,100,101,
  47,82,101,108,97,120,0,2,1,34,
  49,22,11,1,2,26,31,31,79,78,
  0,79,70,70,0,129,0,1,62,22,
  6,1,17,65,114,109,32,40,76,41,
  0,129,0,34,62,21,6,1,17,65,
  114,109,32,40,82,41,0,2,1,34,
  68,22,11,1,2,26,31,31,79,78,
  0,79,70,70,0,129,0,1,80,20,
  6,1,17,70,97,108,108,32,40,76,
  41,0,129,0,36,80,22,6,1,17,
  70,97,108,108,32,40,82,41,0,2,
  1,34,86,22,11,1,2,26,31,31,
  79,78,0,79,70,70,0,2,1,2,
  68,22,11,1,2,26,31,31,79,78,
  0,79,70,70,0,2,1,1,86,22,
  11,1,2,26,31,31,79,78,0,79,
  70,70,0,131,1,3,-1,16,6,1,
  2,31,77,111,118,101,115,0,131,0,
  38,-1,15,6,2,2,31,83,99,101,
  116,99,104,101,115,0,129,0,12,8,
  32,6,2,17,70,97,108,108,105,110,
  103,32,97,114,109,0,2,1,18,14,
  22,11,2,2,26,31,31,79,78,0,
  79,70,70,0,2,1,18,33,22,11,
  2,2,26,31,31,79,78,0,79,70,
  70,0,129,0,12,27,32,6,2,17,
  65,114,109,32,109,111,118,105,110,103,
  0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t switch_walk; // =1 if switch ON and =0 if OFF 
  uint8_t switch_calibration; // =1 if switch ON and =0 if OFF 
  uint8_t switch_left; // =1 if switch ON and =0 if OFF 
  uint8_t switch_right; // =1 if switch ON and =0 if OFF 
  uint8_t switch_static; // =1 if switch ON and =0 if OFF 
  uint8_t switch_ksaplwse; // =1 if switch ON and =0 if OFF 
  uint8_t switch_arm_right; // =1 if switch ON and =0 if OFF 
  uint8_t switch_fall_right; // =1 if switch ON and =0 if OFF 
  uint8_t switch_arm_left; // =1 if switch ON and =0 if OFF 
  uint8_t switch_fall_left; // =1 if switch ON and =0 if OFF 
  uint8_t switch_scetch; // =1 if switch ON and =0 if OFF 
  uint8_t switch_scetch2; // =1 if switch ON and =0 if OFF 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define PIN_SWITCH_WALK 13
#define PIN_SWITCH_CALIBRATION 13
#define PIN_SWITCH_LEFT 13
#define PIN_SWITCH_RIGHT 13
#define PIN_SWITCH_STATIC 13
#define PIN_SWITCH_KSAPLWSE 13
#define PIN_SWITCH_ARM_RIGHT 13
#define PIN_SWITCH_FALL_RIGHT 13
#define PIN_SWITCH_ARM_LEFT 13
#define PIN_SWITCH_FALL_LEFT 13
#define PIN_SWITCH_SCETCH 13
#define PIN_SWITCH_SCETCH2 13


void setup() 
{
  RemoteXY_Init (); 
  
  pinMode (PIN_SWITCH_WALK, OUTPUT);
  pinMode (PIN_SWITCH_CALIBRATION, OUTPUT);
  pinMode (PIN_SWITCH_LEFT, OUTPUT);
  pinMode (PIN_SWITCH_RIGHT, OUTPUT);
  pinMode (PIN_SWITCH_STATIC, OUTPUT);
  pinMode (PIN_SWITCH_KSAPLWSE, OUTPUT);
  pinMode (PIN_SWITCH_ARM_RIGHT, OUTPUT);
  pinMode (PIN_SWITCH_FALL_RIGHT, OUTPUT);
  pinMode (PIN_SWITCH_ARM_LEFT, OUTPUT);
  pinMode (PIN_SWITCH_FALL_LEFT, OUTPUT);
  pinMode (PIN_SWITCH_SCETCH, OUTPUT);
  pinMode (PIN_SWITCH_SCETCH2, OUTPUT);
  
  // TODO you setup code
  servo1.attach(12);
  servo2.attach(2);
  servo3.attach(3);
  servo4.attach(4);
  servo5.attach(5);
  servo6.attach(6);
  servo7.attach(7);
  servo8.attach(8);
  servo9.attach(9);
  servo10.attach(10);
  servo11.attach(11);
  calibration();
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
//  digitalWrite(PIN_SWITCH_WALK, (RemoteXY.switch_walk==0)?LOW:HIGH);
//  digitalWrite(PIN_SWITCH_CALIBRATION, (RemoteXY.switch_calibration==0)?LOW:HIGH);
//  digitalWrite(PIN_SWITCH_LEFT, (RemoteXY.switch_left==0)?LOW:HIGH);
//  digitalWrite(PIN_SWITCH_RIGHT, (RemoteXY.switch_right==0)?LOW:HIGH);
//  digitalWrite(PIN_SWITCH_STATIC, (RemoteXY.switch_static==0)?LOW:HIGH);
//  digitalWrite(PIN_SWITCH_KSAPLWSE, (RemoteXY.switch_ksaplwse==0)?LOW:HIGH);
//  digitalWrite(PIN_SWITCH_ARM_RIGHT, (RemoteXY.switch_arm_right==0)?LOW:HIGH);
//  digitalWrite(PIN_SWITCH_FALL_RIGHT, (RemoteXY.switch_fall_right==0)?LOW:HIGH);
//  digitalWrite(PIN_SWITCH_ARM_LEFT, (RemoteXY.switch_arm_left==0)?LOW:HIGH);
//  digitalWrite(PIN_SWITCH_FALL_LEFT, (RemoteXY.switch_fall_left==0)?LOW:HIGH);
//  digitalWrite(PIN_SWITCH_SCETCH, (RemoteXY.switch_scetch==0)?LOW:HIGH);
//  digitalWrite(PIN_SWITCH_SCETCH2, (RemoteXY.switch_scetch2==0)?LOW:HIGH);
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 
  if (RemoteXY.switch_walk == 1) vadisma2();
  //else ksaplwse(); 
  else if (RemoteXY.switch_calibration == 1) calibration();
  //else ksaplwse(); 
  else if (RemoteXY.switch_left == 1) stripse_aristera();
  //else ksaplwse(); 
  else if (RemoteXY.switch_right == 1) stripse_deksia();
  //else ksaplwse(); 
  else if (RemoteXY.switch_static == 1) staticVadisma();
  //else ksaplwse(); 
  else if (RemoteXY.switch_ksaplwse == 1) ksaplwse();
  //else ksaplwse(); 
  else if (RemoteXY.switch_arm_right == 1) arm_right();
  //else ksaplwse(); 
  else if (RemoteXY.switch_fall_right == 1) pese_right();
  //else ksaplwse(); 
  else if (RemoteXY.switch_arm_left == 1) arm_left();
  //else ksaplwse(); 
  else if (RemoteXY.switch_fall_left == 1) pese_left();
  //else ksaplwse(); 
  else if (RemoteXY.switch_scetch == 1) scetch1();
  //else ksaplwse();
  else if (RemoteXY.switch_scetch2 == 1) scetch2_arm();
  //else ksaplwse();

  //calibration();
  //vadisma2();
  //stripse_aristera(); //fixed (metrio)
  //stripse_deksia(); //kalo
  
  //staticVadisma();
  //ksaplwse();
  //arm_right(); 
  //arm_left(); 
  //pese_right();
  //pese_left();
  //scetch1();
  //scetch2_arm();
}

void ba_pd_EP(){ //OK NEW
  servo3.write(90+55);
  servo7.write(90-70); 
  servo4.write(90-5);//
  servo8.write(90+10);//

}
void pa_bd_EP(){
  servo1.write(90+70);
  servo5.write(90-60);
  servo2.write(90);//
  servo6.write(90+10);//
}
//BROSTA THESI TWN PODIWN- KA8E ENA KSEXWRISTA::=====
void pd_test(){
  servo7.write(90-90);
  delay(300);
  servo8.write(90-45);
  delay(300);
  servo7.write(90+10);
  delay(100);
  servo8.write(90+60);
  //delay(2000);
}
void pa_test(){
  servo1.write(90+90);
  delay(300);
  servo2.write(90+45);
  delay(300);
  servo1.write(90-10);
  delay(100);
  servo2.write(90-60);
  //delay(2000);
}
void ba(){ //OK NEW
  servo4.write(90+45);
  delay(190);
  servo3.write(90-55);//20
  servo4.write(90-90);//60
}
void bd(){
  servo6.write(90-45);
  delay(190);
  servo5.write(90+40);//20
  servo6.write(90+80);//60
  //delay(1000);
}
//==================================================================================================
//============================::PROGRAMMATA::=======================================================
//==================================================================================================
void calibration(){ 
  servo3.write(90+55); //55 (skypsimo 10 moires sta aristera-isio teleiws)
  servo4.write(90-5);
  servo5.write(90-60);
  servo6.write(90+10);

//  servo1.write(90+30);
//  servo2.write(90-32);
//  servo7.write(90-45);
//  servo8.write(90+30);

  servo1.write(90+70);
  servo2.write(90);
  servo7.write(90-70);
  servo8.write(90+10);

  servo9.write(90+90);
  servo10.write(90+90);
  servo11.write(90+90);
}

void arm_right(){
  ksaplwse();
  delay(1000);
  servo9.write(90);
  servo11.write(90-90);
  servo10.write(90+90);
  delay(1000);
  calibration();
  delay(1000);
}
void arm_left(){
  ksaplwse();
  delay(1000);
  servo9.write(90);
  servo11.write(90-90);
  servo10.write(90-90);
  delay(1000);
  calibration();
  delay(1000);
}

void vadisma2(){
  bd();
  pa_test();
  delay(500);
  pa_bd_EP();

  ba();
  pd_test();
  delay(500);
  ba_pd_EP();
}
void staticVadisma(){
  calibration();
  delay(300);
  servo2.write(90+45);
  servo6.write(90-45);
  delay(300); 
  calibration();
  delay(300);
  servo4.write(90+45);
  servo8.write(90-45);  
  delay(300);
}
void stripse_aristera(){
  bd();
  delay(300);
  servo4.write(90+45);
  delay(500);
  pd_test();
  delay(300);
  
  //bd,pd epistrofi
  servo7.write(90);
  servo8.write(90+35);
  delay(300);
  servo7.write(90-70);
  servo5.write(90-60);
  delay(300);
  servo8.write(90+10);
  servo6.write(90+10);
  
  servo4.write(90-5);
  
  delay(800);
}
void stripse_deksia(){
  ba();
  delay(300);
  servo6.write(90-45);
  delay(500);
  pa_test();
  delay(300);

  //pa,ba epistrofi
  servo1.write(90);
  servo2.write(90-35);
  delay(300);
  servo1.write(90+70);
  servo3.write(90+40);
  delay(300);
  servo2.write(90);
  servo4.write(90-15);

  servo6.write(90+20);
 
  delay(800);
}
void ksaplwse(){
  servo2.write(90+55);
  servo4.write(90+70);
  servo6.write(90-70);
  servo8.write(90-55);
  delay(200);
  servo3.write(90+70);
  servo5.write(90-70);
}
void pese_right(){
  ksaplwse();
  delay(800);
  servo3.write(90); 
  servo4.write(90-90);
  servo1.write(90);
  servo2.write(90-90);
}
void pese_left(){
  ksaplwse();
  delay(800);
  servo5.write(90);
  servo6.write(90+90);
  servo7.write(90);
  servo8.write(90+90);
}
void scetch1(){
pese_right();
delay(5000);
arm_right();
delay(5000);
pese_left();
delay(5000);
arm_left();
delay(10000);
}
void scetch2_arm(){
servo9.write(90);
servo10.write(90+45);
delay(2000);
servo11.write(90);
servo9.write(90+90);
servo10.write(90);
delay(2000);
servo9.write(90);
servo10.write(90+45);
servo11.write(90+90);
delay(3000);
for (int i=0; i<=8; i++){
staticVadisma();  
}
delay(10000);
}

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
//const int trigPin = 12;
//const int echoPin = 13;

//float duration, distance;
void setup()
{
  servo1.attach(1);
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
  delay(8000);
  //pinMode(trigPin, OUTPUT);
  //pinMode(echoPin, INPUT);
}
void loop(){
  //calibration();
  vadisma2();
  //stripse_aristera(); //fixed (metrio)
  //stripse_deksia(); //kalo
  
  //staticVadisma();
  //ksaplwse();
  //arm_right(); 
  //arm_left(); 
  //pese_right();
  //pese_left();
  

//SCETCH
//pese_right();
//delay(5000);
//arm_right();
//delay(5000);
//pese_left();
//delay(5000);
//arm_left();
//delay(10000);

//SCETCH2-arm
//servo9.write(90);
//servo10.write(90+45);
//delay(2000);
//servo11.write(90);
//servo9.write(90+90);
//servo10.write(90);
//delay(2000);
//servo9.write(90);
//servo10.write(90+45);
//servo11.write(90+90);
//delay(3000);
//for (int i=0; i<=8; i++){
//staticVadisma();  
//}
//delay(10000);








}

//EPISTROFH ANA 2 PODIWN  ======== 
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

void total1(){
  calibration();
delay(3000);
for (int i=0; i<8; i++){
  vadisma2();
}
delay(4000);
//rixnw to robot sthn deksia plevra toy
arm_right();
delay(1000);
//rixnw to robot sthn aristeri plevra toy
arm_left();
delay(1000);

for (int i=0; i<8; i++){
  staticVadisma();
}
delay(1000);
for (int i=0; i<8; i++){
  stripse_deksia();
}
delay(1000);
for (int i=0; i<8; i++){
  stripse_aristera();
}
delay(500);
ksaplwse();
delay(1000);
exit(0);
}

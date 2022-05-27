#include <Servo.h>
#include <Arduino.h>
#include "WonderCam.h"
#include <U8g2lib.h>
#include <Wire.h>

Servo myservo;
int light_pin = 11;
int servo_port = 12;
int a;
const int dirpin = 46;
const int steppin = 44;
const int sec = 500;
const int stepnum1 = 0;
const int stepnum2 = 800;
const int stepnum3 = 1600;
const int stepnum4 = 2400;
int angle = 90;


WonderCam wc;
U8G2_SSD1306_128X32_UNIVISION_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);   // Adafruit ESP8266/32u4/ARM Boards + FeatherWing OLED

void setup() 
{
  // put your setup code here, to run once:
 
  wc.begin();//IIC通信启动
  
  wc.changeFunc(APPLICATION_CLASSIFICATION);//选择模式
  wc.setLed(true);//不知
  
  pinMode(servo_port,OUTPUT);
  myservo.attach(servo_port);
  myservo.write(servo_port);
  
  
  u8g2.begin();
  u8g2.enableUTF8Print();    // enablze UTF8 support for the Arduino print() function
  
  pinMode(30,OUTPUT);
  pinMode(32,OUTPUT);  
  pinMode(dirpin,OUTPUT);// 电机方向
  pinMode(steppin,OUTPUT);// 电机步数
  pinMode(light_pin,INPUT); // 光电门
  
}


void loop() 
{  
  wc.updateResult();
  digitalWrite(30,HIGH);
  digitalWrite(32,HIGH); 
  int class_id = wc.classIdOfMaxProb();    
  float prob = wc.classMaxProb(); 
 
    digitalWrite(dirpin,LOW);              
    for(int x=0;x<3200;x++)
   {  a = digitalRead(light_pin);
      if(a == 1) break;
      digitalWrite(steppin,HIGH);
      delayMicroseconds(1500);
      digitalWrite(steppin,LOW);
      delayMicroseconds(1500);
    }

    
    
 
  while(1)
  {  wc.updateResult();
     int class_id = wc.classIdOfMaxProb();    
     float prob = wc.classMaxProb(); 
     if(class_id != 11) break;
   }
   
   wc.updateResult();
   class_id = wc.classIdOfMaxProb();    
   prob = wc.classMaxProb();
  if (prob > 0.4) 
  {  
    if ( class_id < 2 ) 
    {           
      u8g2.setFont(u8g2_font_unifont_t_chinese2);//设置字体
      u8g2.setFontDirection(0);//显示的方向
      u8g2.firstPage();
      do 
      {
        u8g2.setCursor(0, 15);//显示的位置坐标
        u8g2.print("None");//显示输出
      } 
      while ( u8g2.nextPage() );
     } 
    
    
    else if (class_id == 2) 
    { 
       digitalWrite(dirpin,LOW);              
       for(int x=0;x<stepnum1;x++)
      {  digitalWrite(steppin,HIGH);
        delayMicroseconds(sec);
        digitalWrite(steppin,LOW);
        delayMicroseconds(sec);
       }
       delay(500);           
       myservo.write(angle);                        
       delay(1000);
       myservo.write(0);
       digitalWrite(dirpin,HIGH);
       for(int x=0;x<stepnum1;x++)
      {  digitalWrite(steppin,HIGH);
        delayMicroseconds(sec);
        digitalWrite(steppin,LOW);
        delayMicroseconds(sec);
       }    
       delay(1000);                   
      u8g2.setFont(u8g2_font_unifont_t_chinese2);
      u8g2.setFontDirection(0);
      u8g2.firstPage();
      do 
      {
        u8g2.setCursor(0, 15);
        u8g2.print("Harmful Waste");
      } 
      while ( u8g2.nextPage() );
    } 
   
    
    else if (class_id == 5 ) 
    { 
      digitalWrite(dirpin,LOW);              
       for(int x=0;x<stepnum2;x++)
      {  digitalWrite(steppin,HIGH);
        delayMicroseconds(sec);
        digitalWrite(steppin,LOW);
        delayMicroseconds(sec);
       }
       delay(500);           
       myservo.write(angle);                        
       delay(1000);
       myservo.write(0);
       digitalWrite(dirpin,HIGH);
      for(int x=0;x<stepnum2;x++)
     {  digitalWrite(steppin,HIGH);
        delayMicroseconds(sec);
        digitalWrite(steppin,LOW);
        delayMicroseconds(sec);
      }    
       delay(1000);                   
       Serial.println("YHY");
       u8g2.setFont(u8g2_font_unifont_t_chinese2);
       u8g2.setFontDirection(0);
       u8g2.firstPage();
       do 
      {
        u8g2.setCursor(0, 15);
        u8g2.print("Recyclable waste");
      } 
      while ( u8g2.nextPage() );
    } 
    
    
    else if (class_id == 7 ) 
    {  
       digitalWrite(dirpin,LOW);              
       for(int x=0;x<stepnum3;x++)
     {  digitalWrite(steppin,HIGH);
        delayMicroseconds(sec);
        digitalWrite(steppin,LOW);
        delayMicroseconds(sec);
      }
      delay(500);           
      myservo.write(angle);                        
      delay(1000);
      myservo.write(0);
      digitalWrite(dirpin,HIGH);
      for(int x=0;x<stepnum3;x++)
     {  digitalWrite(steppin,HIGH);
        delayMicroseconds(sec);
        digitalWrite(steppin,LOW);
        delayMicroseconds(sec);
      }    
      delay(1000);                         
      u8g2.setFont(u8g2_font_unifont_t_chinese2);
      u8g2.setFontDirection(0);
      u8g2.firstPage();
      do 
      {
        u8g2.setCursor(0, 15);
        //u8g2.print("Wet garbage");
      }
      while ( u8g2.nextPage() );
    } 
    
    
    else if(class_id > 11) 
    { 
      digitalWrite(dirpin,LOW);              
       for(int x=0;x<stepnum4;x++)
     {  digitalWrite(steppin,HIGH);
        delayMicroseconds(sec);
        digitalWrite(steppin,LOW);
        delayMicroseconds(sec);
      }
      delay(500);           
      myservo.write(angle);                        
      delay(1000);
      myservo.write(0);
      digitalWrite(dirpin,HIGH);
      for(int x=0;x<stepnum4;x++)
     {  digitalWrite(steppin,HIGH);
        delayMicroseconds(sec);
        digitalWrite(steppin,LOW);
        delayMicroseconds(sec);
      }    
      delay(1000);                   
      u8g2.setFont(u8g2_font_unifont_t_chinese2);
      u8g2.setFontDirection(0);
      u8g2.firstPage();
      do 
      { 
        u8g2.setCursor(0, 15);
        //u8g2.print("Dry garbage");
      } 
      while( u8g2.nextPage() );
    }
  }
}


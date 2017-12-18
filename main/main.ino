
/*
last change: 02.11.2017
version: 1.0
*/

//Includes
#include "Arduino.h"
#include "compute.h"
#include "read.h"
#include "safe.h"
#include "rtc.h"
#include "send.h"
#include "TimerOne.h" 
//#include "logger.h"
#define FASTADC 1

// defines for setting and clearing register bits
#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

//Variables
volatile long actual_current = 0;
volatile long actual_voltage = 0;
volatile unsigned int count_additions = 0;
volatile int temp = 0;
File myFile;

//ISR
void sumup()
{
  /*
  if(temp == 0)
  {
    digitalWrite(13, HIGH);
    temp = 1;
  }
  else
  {
    digitalWrite(13, LOW);
    temp = 0;
  }*/
//  actual_voltage += readin_voltage() - 496;
//  actual_current += readin_current3() - 496;
//  count_additions += 1;
}

//INIT
void setup() 
{
  //set prescale of ADC to 16
  #if FASTADC
 // 
 sbi(ADCSRA,ADPS2) ;
 cbi(ADCSRA,ADPS1) ;
 cbi(ADCSRA,ADPS0) ;
  #endif

  void setup_SD();
  delay(1000);
  init_bluetooth();
  delay(1000);
  init_rtc();
  delay(1000);
  //Timer1.initialize(100);
  //Timer1.attachInterrupt(sumup);
  Serial.begin(9600);
  setup_SD();
}

//MAIN Programm
void loop() 
{


//  //Wait for measurment
//  while(count_additions < 32768){}
//
//  //Stop Interupts extract values and reset
//  noInterrupts();
//  count_additions = 0;
//  long current = actual_current;
//  long voltage = actual_voltage;
//  actual_current = 0;
//  actual_voltage = 0;
//  count_additions = 0;
//  interrupts();
//  
//  
//  //Compute
//  current = current >> 15;
//  float c_real = (float) current * (3.3/1024.0) *(1.222 * 20000.2 /6.2) ;
//  voltage = voltage >> 15;
//  float v_real = (float) current * (3.3/1024.0) *(1.0/0.1) ;
//  float power = compute_power(c_real, v_real);
//

  //Get Date etc. 
    char* weekday = getDay();
    char* timee = getTimee();
    char* datee = getDate();

  //Speichern
  delay(5000);
  sd_write(datee, timee, weekday, 10.0, 10.0, 10.0);
  delay(5000);
  
  sd_send();
  //Senden
  
}


//Notes/////////////////////////////////Notes/////////////////////////////////Notes/////////////////////////////////Notes///////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
if(Serial.available() > 0)
  {
    
  }  

        Serial.print(a);
        Serial.print("it works");
      Serial.print('\n');
 */
 
  //Einlesen und berechnen
  //int startTime = millis();                                   
    
 //  int elapsedTime =   millis() - startTime;
//  Serial.print(elapsedTime);
//  Serial.print('\n');
//  Serial.print('*actual_power');
//  Serial.print('\n'); 
  
//  for (int i = 0; i < 1024; ++i)
//  {
//    compute_voltage(&actual_voltage);
//    compute_current(&actual_current);
//    delayMicroseconds(195);
//  }
//  actual_voltage = (actual_voltage >> 10);
//  float voltage = (((float)vactual_voltage) / 1.222) * (3.3/1024) //*faktor shunt
//  
//  actual_current = actual_current >> 10;
//  compute_power(&actual_power, &actual_current, &actual_voltage);


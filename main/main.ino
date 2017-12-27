
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
#include "TimerOne.h" //Quelle: Arduiono, Online Available: https://playground.arduino.cc/Code/Timer1, Licence: CC BY 3.0 US



//Defines

#define FASTADC 1

#ifndef cbi   // defines for setting and clearing register bits
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif



//Variables
volatile long current = 0;
volatile long power = 0;
volatile unsigned int count_additions = 0;
//volatile int temp = 0;


//ISR
void sumup()
{
    
  int actual_voltage = readin_voltage()  - 496;
  int actual_current = readin_current3() - 496;
  power += (long) (actual_voltage * actual_current);
  //current += actual_current;
  count_additions += 1;
  
//  Speedtesting
//  if(temp == 0)
//  {
//    digitalWrite(13, HIGH);
//    temp = 1;
//  }
//  else
//  {
//    digitalWrite(13, LOW);
//    temp = 0;
//  }

//
  //Test Overflow
//  int actual_voltage = 1024  - 496;
//  int actual_current = 1024 - 496;
//  power += (long) (actual_voltage * actual_current);
//  count_additions += 1;


//  long actual_voltage = readin_voltage();
//  long actual_current = readin_current3();
//  Serial.print(actual_voltage);
//  Serial.print('\n');
//  Serial.print(actual_current);
//  Serial.print('\n');
//  Serial.print('\n');
}

//INIT
void setup() 
{
  //Init SD
  void setup_SD();
  delay(1000);
  
  //Init Bluetooth
  init_bluetooth();
  delay(1000);
  
  //Init Real time clock
  init_rtc();
  delay(1000);
  
  //Init ADC set Prescaler to 16
  ADMUX = _BV(REFS0);
  sbi(ADCSRA,ADPS2) ;
  cbi(ADCSRA,ADPS1) ;
  cbi(ADCSRA,ADPS0) ;
  
  //Init Timer for ISR
  Timer1.initialize();
  Timer1.attachInterrupt(sumup, 100);
  Serial.begin(9600);
  
  //Init SD-Card
  setup_SD();
}

//MAIN Programm
void loop() 
{


  //Wait for measurments
  while(count_additions < 50000){}

  //Stop Interupts extract values and reset
  noInterrupts();
  long power_sum = power;
  long current_sum = current;
  int addition = count_additions;
  current = 0;
  power = 0;
  count_additions = 0;
  interrupts();
  
  
  //Compute the power in Watt and the current
  power_sum = power_sum / count_additions;
  current_sum = current_sum / count_additions;
  float power_real = compute_power(power_sum);
  
  //current_sum = current_sum / count_additions;
  //float current_real = compute_current(current_sum);
  float current_real = 10.0;
  
  //Get Date etc. 
  char* weekday = getDay();
  char* timee = getTimee();
  char* datee = getDate();

  //Safe and Send if requested
  sd_write(datee, timee, weekday, power_real, current_real);
  sd_send();
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


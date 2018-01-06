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

//Variables
volatile long current = 0;
volatile long power = 0;
volatile unsigned int count_additions = 0;
volatile int temp = 0;


//ISR
void sumup()
{
    
      int actual_voltage = readin_voltage()  - 496;
      int actual_current = readin_current3() - 496;
      power += (((long)actual_voltage) * ((long)actual_current));
      current += (long) actual_current;
      count_additions += 1;
    
      //Speedtesting
//      if(temp == 0)
//      {
//        digitalWrite(13, HIGH);
//        temp = 1;
//      }
//      else
//      {
//        digitalWrite(13, LOW);
//        temp = 0;
//      }
    
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
    
    delay(1000);
    
    //Init Bluetooth
    init_bluetooth();
    delay(1000);
    
    //Init Real time clock
    //init_rtc();
    delay(1000);

    //Init ADC
    init_adc();
    
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
    Serial.write("Main Programm");
    Serial.print('\n');

    //TEST ADC Values
//    delay(3000);
//    int t1 = readin_voltage();
//    int t2 = readin_current3();
//    Serial.print(t1);
//    Serial.print('\n');
//    Serial.print(t2);
//    Serial.print('\n');
//    delay(3000);
    
    //Stop Interupts extract values and reset
    noInterrupts();
    long power_sum = power;
    long current_sum = current;
    unsigned int addition = count_additions;
    current = 0;
    power = 0;
    count_additions = 0;

    //Test sum
//    Serial.print("power_sum: ");
//    Serial.print(power_sum);
//    Serial.print('\n');
//    Serial.print("current_sum: ");
//    Serial.print(current_sum);
//    Serial.print('\n');
//    Serial.print("count_additions: ");
//    Serial.print(addition);
//    Serial.print('\n');

    interrupts();
    
    
    //Compute the power in Watt and the current
    power_sum = power_sum / ((long) addition);
    current_sum = current_sum / ((long) addition);
    float power_real = compute_power(power_sum);
    float current_real = compute_current(current_sum);

    //Testing computation
    char power_c[15];
    char current_c[15];
    dtostrf(power_real,5, 2, power_c);
    dtostrf(current_real,5, 2, current_c);
    Serial.print("power_real: ");
    Serial.print(power_c);
    Serial.print('\n');
    Serial.print("current_real: ");
    Serial.print(current_c);
    Serial.print('\n');   
   
    
    
    //Get Date etc.
//    char* weekday = getDay();
//    char* timee = getTimee();
//    char* datee = getDate();
    
    //Safe and Send if requested
//    sd_write(datee, timee, weekday, power_real, current_real);
//    sd_send();
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



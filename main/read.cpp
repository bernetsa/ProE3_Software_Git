/*
last change: 02.11.2017
version: 1.0
*/

#include "Arduino.h"
#include "read.h"
#define channel_voltage 0b0111
#define channel_current3 0b0100



//long readin_voltage()
//{
//   return (long) analogRead(0);
//}
int readin_voltage()
{
  ADMUX = (ADMUX & channel_voltage) ; // select analog input for voltage

  // write '1' to ADSC to start single convertion
  ADCSRA |= _BV(ADSC);

  // wait for conversion to complete
  while (ADCSRA & _BV(ADSC));

  return (int)(ADC);
}


long readin_current1()
{
  return (long) analogRead(1);
}

long readin_current2()
{
  return  (long) analogRead(2);
}

//long readin_current3()
//{
// return  (long) analogRead(3);
//}

int readin_current3()
{
   ADMUX = (ADMUX & channel_current3) ; // select analog input for voltage

  // write '1' to ADSC to start single convertion
  ADCSRA |= _BV(ADSC);

  // wait for conversion to complete
  while (ADCSRA & _BV(ADSC));

  return (int)(ADC);
}



//Notes/////////////////////////////////Notes/////////////////////////////////Notes/////////////////////////////////Notes///////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*analogRead(pin)
gives back a integer from 0 to 1023 (5V)
pin =the number of the analog input pin to read from (0 to 5 on most boards, 0 to 7 on the Mini and Nano, 0 to 15 on the Mega)
*/



//
//float spannungsteiler = 1;
//float stromteiler = 1;
//
//float readin_voltage()
//{
//  int in = analogRead(0);
//  float out = (float) in;
//  out = (5.0/1024.0) * out * spannungsteiler;
//  return out;
//}
//
//float readin_current1()
//{
//  int in = analogRead(1);
//  float out = (float) in;
//  out = (5.0/1024.0) * out * spannungsteiler;
//  return out;
//}
//
//float readin_current2()
//{
//  int in = analogRead(2);
//  float out = (float) in;
//  out = (5.0/1024.0) * out * spannungsteiler;
//  return out;
//}
//
//float readin_current3()
//{
//  int in = analogRead(3);
//  float out = (float) in;
//  out = (5.0/1024.0) * out * spannungsteiler;
//  return out;
//}



/*
last change: 02.11.2017
version: 1.0
*/

#include "Arduino.h"
#include "read.h"




/*analogRead(pin)
gives back a integer from 0 to 1023 (5V)
pin =the number of the analog input pin to read from (0 to 5 on most boards, 0 to 7 on the Mini and Nano, 0 to 15 on the Mega)
*/

float spannungsteiler = 1;
float stromteiler = 1;

float readin_voltage()
{
  int in = analogRead(0);
  float out = (float) in;
  out = (5.0/1024.0) * out * spannungsteiler;
  return out;
}

float readin_current1()
{
  int in = analogRead(1);
  float out = (float) in;
  out = (5.0/1024.0) * out * spannungsteiler;
  return out;
}

float readin_current2()
{
  int in = analogRead(2);
  float out = (float) in;
  out = (5.0/1024.0) * out * spannungsteiler;
  return out;
}

float readin_current3()
{
  int in = analogRead(3);
  float out = (float) in;
  out = (5.0/1024.0) * out * spannungsteiler;
  return out;
}

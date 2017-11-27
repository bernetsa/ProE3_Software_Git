// Code from the Demo Example of the DS3231 Library

#include "Arduino.h"
#include "rtc.h"
#include <DS3231.h>

DS3231  rtc(SDA, SCL);

void init_rtc()
{

  // Setup Serial connection
  Serial.begin(115200);
  // Uncomment the next line if you are using an Arduino Leonardo
  while (!Serial) {}
  
  // Initialize the rtc object
  rtc.begin();
  
  // The following lines can be uncommented to set the date and time
  rtc.setDOW(WEDNESDAY);     // Set Day-of-Week to SUNDAY
  rtc.setTime(12, 0, 0);     // Set the time to 12:00:00 (24hr format)
  rtc.setDate(1, 1, 2014);   // Set the date to January 1st, 2014
}

char* getDay() 
{
 
  char* a =  rtc.getDOWStr();
  return a;
}

char* getDate() 
{
  char* a  =  rtc.getDateStr();
  return a;
}

char* getTimee()
{
  char* a  = rtc.getTimeStr();
  return a;
}


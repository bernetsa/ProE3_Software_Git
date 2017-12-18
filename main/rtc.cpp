// Code from the Demo Example of the DS3231 Library

#include "Arduino.h"
#include "rtc.h"
#include <DS3231.h>


DS3231  rtc(SDA, SCL);


void init_rtc()
{
  
  // Initialize the rtc object
  rtc.begin();
  
  // The following lines can be uncommented to set the date and time
//  rtc.setDOW(THURSDAY);     // Set Day-of-Week to SUNDAY
//  rtc.setTime(16, 51, 20);     // Set the time to 12:00:00 (24hr format)
//  rtc.setDate(7, 12, 2017);   // Set the date to January 1st, 2014   
}

char* getDay() 
{
 
  return rtc.getDOWStr();
  
}

char* getDate() 
{
  return  rtc.getDateStr();
}

char* getTimee()
{
  return rtc.getTimeStr();
}



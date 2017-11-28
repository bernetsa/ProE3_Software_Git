
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
#include "system.h"
#include "send.h"


//#include "logger.h"


void setup() 
{
  delay(5000);
  init_bluetooth();
  //init_rtc();

}

void loop() 
{
  //Variable initialication 
  long actual_power = 0;
  long actual_current = 0;
  long actual_voltage = 0;

  //called functions
  senddata();
}

//Notes
//
/*
if(Serial.available() > 0)
  {
    
  }  

        Serial.print(a);
        Serial.print("it works");
      Serial.print('\n');
 */


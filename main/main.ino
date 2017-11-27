
/*
last change: 02.11.2017
version: 1.0
*/


//Includes
#include "Arduino.h"
#include "compute.h"
#include "init.h"
#include "read.h"
#include "safe.h"
#include "rtc.h"
#include "system.h"


//#include "logger.h"


void setup() 
{
   //init_bluetooth();
  init_rtc();
}

void loop() 
{
      

}

//Notes
//Serial.print("it works");
/*
if(Serial.available() > 0)
  {
    
  }  

        Serial.print(a);
      Serial.print('\n');
 */

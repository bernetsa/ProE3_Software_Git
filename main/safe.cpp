/*
last change: 02.11.2017
version: 1.0
*/

#include "Arduino.h"
#include "safe.h"

//
//#include <SPI.h>
//#include <SD.h>

//
//File myFile;
//int pinCS = 53; // Pin 10 on Arduino Uno
//void setup() {
//    
//  Serial.begin(9600);
//  pinMode(pinCS, OUTPUT);
//  
//  // SD Card Initialization
//  if (SD.begin())
//  {
//    Serial.println("SD card is ready to use.");
//  } else
//  {
//    Serial.println("SD card initialization failed");
//    return;
//  }
//  rtc.begin();    
//}
//void loop() {
//  Serial.print(rtc.getTimeStr());
//  Serial.print(",");
//  Serial.println(int(rtc.getTemp()));
// 
//  myFile = SD.open("test.txt", FILE_WRITE);
//  if (myFile) {    
//    myFile.print(rtc.getTimeStr());
//    myFile.print(",");    
//    myFile.println(int(rtc.getTemp()));
//    myFile.close(); // close the file
//  }
//  // if the file didn't open, print an error:
//  else {
//    Serial.println("error opening test.txt");
//  }
//  delay(3000);
//}
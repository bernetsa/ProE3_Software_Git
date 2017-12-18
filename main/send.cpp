/*
last change: 02.11.2017
version: 1.0
*/

#include "Arduino.h"
#include "send.h"
#include <SoftwareSerial.h>
#include <SPI.h>
#include <SD.h>

SoftwareSerial bluetoothSerial(0, 1);
File myFile;


int statesend = 1;

void init_bluetooth()
{
  /*
  bluetoothSerial.begin(38400); // Default communication rate of the Bluetooth module
   // HC-05 auf Defaultwere setzen -> Slave mode, Baudrate 38400, Passwort:1234,   Device-Name: "hc01.com HC-05"
  bluetoothSerial.println("AT+ORGL"); delay(500);
    // Setze Name
  bluetoothSerial.println("AT+NAME=JewelsPerSecond"); delay(500);
    // Setze Pin auf 1234
  bluetoothSerial.println("AT+PSWD=4321"); delay(500);
    // Setze Baudrate auf 19200
  //bluetoothSerial.println("AT+UART=19200,1,0"); delay(500);
 bluetoothSerial.println("AT+UART=19200,1,0"); delay(500);
 
  // Modul neustarten und eventuelle Verbindungen resetten
  bluetoothSerial.println("AT+RESET"); delay(1000);

  // SPP Profile Lib initialisieren und disconnecten
  bluetoothSerial.println("AT+INIT"); delay(500);
  bluetoothSerial.println("AT+DISC"); delay(500);
 */
 bluetoothSerial.begin(19200);
}

void sd_send()
{
  char a = 'n';
  if(bluetoothSerial.available())
  {
    char a = bluetoothSerial.read();
  }

  if (a == 'r')
  {
    myFile = SD.open("jps.txt");
    if (myFile) 
    {
      // read from the file until there's nothing else in it:
      while (myFile.available()) 
      {
        bluetoothSerial.write(myFile.read());
      }
    // close the file:
      myFile.close();
    }
  }
 
}

  /*
  if(bluetoothSerial.available() > 0)
    { // Checks whether data is comming from the serial port
      statesend = bluetoothSerial.read(); // Reads the data from the serial port
    }
    
  if (statesend == '1') 
    {
      bluetoothSerial.write("HEllO\n");
      delay(1000);
      statesend = 0;
    }*/
    







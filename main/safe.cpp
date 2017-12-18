/*
last change: 02.11.2017
version: 1.0
*/

#include "Arduino.h"
#include "safe.h"
#include "rtc.h"
#include <SPI.h>
#include <SD.h>
#include <SoftwareSerial.h>


//SoftwareSerial bluetoothSerial(0, 1);

File myFile;
int pinCS = 17;

void setup_SD() 
{
    Serial.print("Initializing SD card...");
    if (!SD.begin(pinCS)) 
    {
      Serial.println("initialization failed!");
      return;
    }
    Serial.println("initialization done.");
    SD.remove("jps.txt");
    
}

void sd_write(char* datee, char* timee, char* weekday, float power, float current, float voltage) 
{
  char power_c[15];
  char current_c[15];
  char voltage_c[15];
  dtostrf(power,5, 2, power_c);
  dtostrf(current,5, 2, current_c);
  dtostrf(voltage,5, 2, voltage_c);
  
  //File mode append?
  myFile = SD.open("jps.txt", FILE_WRITE);
  
  if (myFile)
  {    
    //Möglicher Fehler. Datee timee, etc nicht null-terminiert
    myFile.print(datee);
    myFile.print('\t'); 
    myFile.print(timee);
    myFile.print('\t'); 
    myFile.print(weekday);
    myFile.print('\t');
    myFile.print(power_c);
    myFile.print('\t');
    myFile.print(current_c);
    myFile.print('\t');    
    myFile.print(voltage_c);
    myFile.print("\r\n"); 
    myFile.close(); // close the file
  }
}



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
 Serial1.begin(19200);
}

void sd_send()
{
  char a = '0';
  if(Serial1.available())
  {
    a = Serial1.read();
  }

  if (a > '0')
  {
    myFile = SD.open("jps.txt");
    if (myFile) 
    {
      // read from the file until there's nothing else in it:
      while (myFile.available()) 
      {
        Serial1.write(myFile.read());
      }
    // close the file:
      myFile.close();
    }
  }
 
}



//Notes/////////////////////////////////Notes/////////////////////////////////Notes/////////////////////////////////Notes///////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
    


/*
  SD card test 
   
This example shows how use the utility libraries on which the'
SD library is based in order to get info about your SD card.
Very useful for testing a card when you're not sure whether its working or not.
  
The circuit:
  * SD card attached to SPI bus as follows:
** MOSI - pin 11 on Arduino Uno/Duemilanove/Diecimila
** MISO - pin 12 on Arduino Uno/Duemilanove/Diecimila
** CLK - pin 13 on Arduino Uno/Duemilanove/Diecimila
** CS - depends on your SD card shield or module. 
    Pin 4 used here for consistency with other Arduino examples


created  28 Mar 2011
by Limor Fried 
modified 9 Apr 2012
by Tom Igoe
*/
// include the SD library:
//#include <SD.h>

// set up variables using the SD utility library functions:
//Sd2Card card;
//SdVolume volume;
//SdFile root;

// change this to match your SD shield or module;
// Arduino Ethernet shield: pin 4
// Adafruit SD shields and modules: pin 10
// Sparkfun SD shield: pin 8
//const int chipSelect = 4;    

//void setup()
//{
//// Open serial communications and wait for port to open:
//  Serial.begin(9600);
//   while (!Serial) {
//    ; // wait for serial port to connect. Needed for Leonardo only
//}


//  Serial.print("\nInitializing SD card...");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin 
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output 
  // or the SD library functions will not work. 


  //pinMode(17, OUTPUT);     //Here, zintiger changed this to 17 for Leonardo as you mentioned.


  // we'll use the initialization code from the utility libraries
  // since we're just testing if the card is working!
//  if (!card.init(SPI_HALF_SPEED, chipSelect)) {
//    Serial.println("initialization failed. Things to check:");
//    Serial.println("* is a card is inserted?");
//    Serial.println("* Is your wiring correct?");
//    Serial.println("* did you change the chipSelect pin to match your shield or module?");
//    return;
//  } else {
//   Serial.println("Wiring is correct and a card is present."); 
//  }
//
//  // print the type of card
//  Serial.print("\nCard type: ");
//  switch(card.type()) {
//    case SD_CARD_TYPE_SD1:
//      Serial.println("SD1");
//      break;
//    case SD_CARD_TYPE_SD2:
//      Serial.println("SD2");
//      break;
//    case SD_CARD_TYPE_SDHC:
//      Serial.println("SDHC");
//      break;
//    default:
//      Serial.println("Unknown");
//  }
//
//  // Now we will try to open the 'volume'/'partition' - it should be FAT16 or FAT32
//  if (!volume.init(card)) {
//    Serial.println("Could not find FAT16/FAT32 partition.\nMake sure you've formatted the card");
//    return;
//  }
//
//
//  // print the type and size of the first FAT-type volume
//  uint32_t volumesize;
//  Serial.print("\nVolume type is FAT");
//  Serial.println(volume.fatType(), DEC);
//  Serial.println();
//  
//  volumesize = volume.blocksPerCluster();    // clusters are collections of blocks
//  volumesize *= volume.clusterCount();       // we'll have a lot of clusters
//  volumesize *= 512;                            // SD card blocks are always 512 bytes
//  Serial.print("Volume size (bytes): ");
//  Serial.println(volumesize);
//  Serial.print("Volume size (Kbytes): ");
//  volumesize /= 1024;
//  Serial.println(volumesize);
//  Serial.print("Volume size (Mbytes): ");
//  volumesize /= 1024;
//  Serial.println(volumesize);
//
//  
//  Serial.println("\nFiles found on the card (name, date and size in bytes): ");
//  root.openRoot(volume);
//  
//  // list all files in the card with date and size
//  root.ls(LS_R | LS_DATE | LS_SIZE);
//}
//
//
//void loop(void) {
//  
//}


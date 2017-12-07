/*
last change: 02.11.2017
version: 1.0
*/

#include "Arduino.h"
#include "send.h"
#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(0, 1);


int statesend = 1;

void init_bluetooth() {
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

void senddata() 
{
    
    bluetoothSerial.write("HEllO\n");
    delay(1000);
    
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
    
}

/* SKETCH (nicht von mir) um HC-05 in den Programmiermodus zu versetzen und per Serial auslesen zu können 
Ohne Änderungen kompatibel mit YUN und UNO und wahrscheinlich sogar Leonardo, Ethernet usw.

Zunächst YUN und UNO so anschließen: 

VCC -> 3.3V, 
GND -> GND, 
TX-> D9 (=SoftSerial RX), 
RX ->D10 (=SoftSerial TX). 

Für den Programmiermodus ist wichtig: 
1. Bei der mySerial-Initialisierung im Setup des Sketches ist die 38400 baud-rate nötig.
2. Der KEY-Pin des HC-05 muss für den AT-Kommando-Programmiermodus an 3.3V angesteckt werden 
(Ja, "VCC" UND "KEY" an 3.3V. Nehmt dafür eine Klemme oder ein Breadboard), ALLERDINGS ist der Zeitpunkt wichtig:

Beim Yun (und vermutlich Leonardo) den "KEY"-Pin BEVOR man den Yun per USB an den Computer steckt mit 3.3V verbinden. Beim Uno NACHDEM man den UNO per USB mit dem PC verbunden hat. Wenn Ihr erfolgreich im Programmiermodus seid, blinkt das HC-05 in langen Intervallen und Ihr könnt den Serial Monitor der IDE öffnen, den Serial Monitor auf "BL + CR" und baud-rate 9600 schalten und testweise "AT" eingeben. Es sollte "OK" erscheinen. Die restlichen zahlreichen Kommandos bitte dem HC-05-datasheet entnehmen.

*/




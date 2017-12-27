/*
last change: 02.11.2017
version: 1.0
*/

#ifndef safe_h
#define safe_h

//Initilacies the SD deletes old files
void setup_SD();

//Writes the arguments as a string to a txt file on the SD card
void sd_write(char* datee, char* timee, char* weekday, float power, float current);

//Reads the whole file from the SD card
void sd_read();

//Initilacies the HC-05 
void init_bluetooth();

//Sends the Data from the file via the HC-05
void sd_send();
#endif


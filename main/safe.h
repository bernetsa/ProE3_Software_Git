/*
last change: 02.11.2017
version: 1.0
*/

#ifndef safe_h
#define safe_h

void setup_SD();
void sd_write(char* datee, char* timee, char* weekday, float power, float current, float voltage);
void sd_read();

#endif


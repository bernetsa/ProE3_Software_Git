/*
 last change: 02.11.2017
 version: 1.0
 */

#include "Arduino.h"
#include "read.h"
#define channel_voltage 0b0111
#define channel_current3 0b0100

#define FASTADC 1

#ifndef cbi   // defines for setting and clearing register bits
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

void init_adc()
{
    //ADMUX |= (1<<REFS0);
    cbi(ADCSRA, ADEN); //Disable ADC
    cbi(ADMUX, MUX0);  //Set Input for ADC
    cbi(ADMUX, MUX1);
    sbi(ADMUX, MUX2);
    sbi(ADCSRA, ADEN);  //Enable ADC
    
    ADCSRA |= (1<<ADSC);        // Start a conversion
    while(ADCSRA & (1<<ADSC));  // What until the bit is reset by the
    return (int) ADC;
    
    ADMUX |= (1<<REFS0);
    cbi(ADCSRA, ADEN); //Disable ADC
    cbi(ADMUX, MUX0);  //Set Input for ADC
    cbi(ADMUX, MUX1);
    sbi(ADMUX, MUX2);
    sbi(ADCSRA, ADEN);  //Enable ADC
    sbi(ADCSRA, ADPS2); //set prescaler to 16
    
    ADCSRA |= (1<<ADSC);        // Start a conversion
    while(ADCSRA & (1<<ADSC));  // What until the bit is reset by the
}

int readin_voltage()
{
    cbi(ADCSRB,MUX5);
    cbi(ADCSRA, ADEN); //Disable ADC
    cbi(ADMUX, MUX0);  //Set Input for ADC
    cbi(ADMUX, MUX1);
    cbi(ADMUX, MUX2);
    sbi(ADCSRA, ADEN);  //Enable ADC
    
    ADCSRA |= (1<<ADSC);        // Start a conversion
    while(ADCSRA & (1<<ADSC));  // What until the bit is reset by the
    return (int) ADC;
}


long readin_current1()
{
    return (long) analogRead(1);
}

long readin_current2()
{
    return  (long) analogRead(2);
}



int readin_current3()
{
    cbi(ADCSRB,MUX5);
    cbi(ADCSRA, ADEN); //Disable ADC
    cbi(ADMUX, MUX0);  //Set Input for ADC
    cbi(ADMUX, MUX1);
    sbi(ADMUX, MUX2);
    sbi(ADCSRA, ADEN);  //Enable ADC
    
    ADCSRA |= (1<<ADSC);        // Start a conversion
    while(ADCSRA & (1<<ADSC));  // What until the bit is reset by the
    return (int) ADC;
}



//Notes/////////////////////////////////Notes/////////////////////////////////Notes/////////////////////////////////Notes///////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*analogRead(pin)
 gives back a integer from 0 to 1023 (5V)
 pin =the number of the analog input pin to read from (0 to 5 on most boards, 0 to 7 on the Mini and Nano, 0 to 15 on the Mega)
 */
//long readin_voltage()
//{
//   return (long) analogRead(0);
//}

//long readin_current3()
//{
// return  (long) analogRead(3);
//}

//
//float spannungsteiler = 1;
//float stromteiler = 1;
//
//float readin_voltage()
//{
//  int in = analogRead(0);
//  float out = (float) in;
//  out = (5.0/1024.0) * out * spannungsteiler;
//  return out;
//}
//
//float readin_current1()
//{
//  int in = analogRead(1);
//  float out = (float) in;
//  out = (5.0/1024.0) * out * spannungsteiler;
//  return out;
//}
//
//float readin_current2()
//{
//  int in = analogRead(2);
//  float out = (float) in;
//  out = (5.0/1024.0) * out * spannungsteiler;
//  return out;
//}
//
//float readin_current3()
//{
//  int in = analogRead(3);
//  float out = (float) in;
//  out = (5.0/1024.0) * out * spannungsteiler;
//  return out;
//}


/*
last change: 02.11.2017
version: 1.0
*/

#include "Arduino.h"
#include "compute.h"
#include "read.h"





float compute_power(float power, float current)
{
  return power * current;
}
//
//void compute_voltage(&actual_voltage)
//{
//  *actual_voltage += readin_voltage();
//}
//void compute_current(&actual_current)
//{
//  //Messung I3
//  //if not == (0 oder 0 3.3) -> Faktor gewichtung
//  //else: messung I2
//  long current = readin_current3();
//  if (current != (0 || 1024))
//    {
//      current -= 496;
//      //Anpassung verstärkung
//    }
//   else
//   {
//     current = readin_current2();
//   }
//}



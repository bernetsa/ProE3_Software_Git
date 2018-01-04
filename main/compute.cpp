#include "Arduino.h"
#include "compute.h"
#include "read.h"

float compute_power(long power)
{
    float power_r = ((float)power) * (3.3/1024.0) * (3.3/1024.0) * (1.0/0.1) * (1 / 2.111 * 0.000282);
    return power_r;
}

float compute_current(long current)
{
    float current_r = ((float) current) * (3.3/1024.0) /  0.1;
    return current_r;
}


//Notes/////////////////////////////////Notes/////////////////////////////////Notes/////////////////////////////////Notes///////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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


/*
last change: 02.11.2017
version: 1.0
*/

#include "Arduino.h"
#include "compute.h"

void compute_power(long *actualpower, long *actualcurrent, long *actualvoltage)
{
  *actualpower = (*actualcurrent) * (*actualvoltage);
  //shiften
}


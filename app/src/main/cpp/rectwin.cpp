/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rectwin.cpp
 *
 * Code generation for function 'rectwin'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "rectwin.h"
#include <string.h>

/* Function Definitions */
void rectwin(double w_data[], int w_size[1])
{
  int i13;
  w_size[0] = 125;
  for (i13 = 0; i13 < 125; i13++) {
    w_data[i13] = 1.0;
  }
}

/* End of code generation (rectwin.cpp) */

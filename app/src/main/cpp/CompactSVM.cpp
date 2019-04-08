/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CompactSVM.cpp
 *
 * Code generation for function 'CompactSVM'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "CompactSVM.h"
#include "Gaussian.h"
#include "dot.h"
#include <string.h>

/* Function Definitions */
double CompactSVM_score(const double obj_Alpha[1342], const double
  obj_SupportVectorsT[9394], const double Xin[7])
{
  double dv7[1342];
  double dv8[1342];
  double d5;
  int i77;
  dot(obj_SupportVectorsT, obj_SupportVectorsT, dv7);
  Gaussian(obj_SupportVectorsT, dv7, Xin, dv8);
  d5 = 0.0;
  for (i77 = 0; i77 < 1342; i77++) {
    d5 += dv8[i77] * obj_Alpha[i77];
  }

  return d5 + -0.54871226567710851;
}

/* End of code generation (CompactSVM.cpp) */

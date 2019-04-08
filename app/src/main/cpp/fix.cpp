/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fix.cpp
 *
 * Code generation for function 'fix'
 *
 */

/* Include files */
#include <cmath>
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "fix.h"
#include <string.h>

/* Function Definitions */
void b_fix(double *x)
{
  if (*x < 0.0) {
    *x = std::ceil(*x);
  } else {
    *x = std::floor(*x);
  }
}

/* End of code generation (fix.cpp) */

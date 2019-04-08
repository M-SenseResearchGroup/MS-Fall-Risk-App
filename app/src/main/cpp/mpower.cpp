/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mpower.cpp
 *
 * Code generation for function 'mpower'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "mpower.h"
#include "calc_fall_risk_rtwutil.h"
#include <string.h>

/* Function Definitions */
double mpower(double b)
{
  return rt_powd_snf(2.0, b);
}

/* End of code generation (mpower.cpp) */

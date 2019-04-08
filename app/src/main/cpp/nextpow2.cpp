/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nextpow2.cpp
 *
 * Code generation for function 'nextpow2'
 *
 */

/* Include files */
#include <cmath>
#include <math.h>
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "nextpow2.h"
#include <string.h>

/* Function Definitions */
double nextpow2(double n)
{
  double p;
  boolean_T b4;
  boolean_T b5;
  double f;
  int eint;
  p = std::abs(n);
  b4 = !rtIsInf(p);
  b5 = !rtIsNaN(p);
  if (b4 && b5) {
    f = frexp(p, &eint);
    p = eint;
    if (f == 0.5) {
      p = static_cast<double>(eint) - 1.0;
    }
  }

  return p;
}

/* End of code generation (nextpow2.cpp) */

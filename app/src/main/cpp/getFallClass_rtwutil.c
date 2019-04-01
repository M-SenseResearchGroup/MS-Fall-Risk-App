/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * getFallClass_rtwutil.c
 *
 * Code generation for function 'getFallClass_rtwutil'
 *
 */

/* Include files */
#include <math.h>
#include "rt_nonfinite.h"
#include "getFallClass_rtwutil.h"
#include <string.h>

/* Function Definitions */
double rt_hypotd_snf(double u0, double u1)
{
  double y;
  double a;
  double b;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = b * sqrt(a * a + 1.0);
  } else if (a > b) {
    b /= a;
    y = a * sqrt(b * b + 1.0);
  } else if (rtIsNaN(b)) {
    y = b;
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

/* End of code generation (getFallClass_rtwutil.c) */

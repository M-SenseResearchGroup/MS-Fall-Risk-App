/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * dot.cpp
 *
 * Code generation for function 'dot'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "dot.h"
#include <string.h>

/* Function Definitions */
void dot(const double a[9394], const double b[9394], double c[1342])
{
  int i2;
  int ic;
  int i;
  int ix;
  int iy;
  double b_c;
  int k;
  i2 = 1;
  ic = -1;
  for (i = 0; i < 1342; i++) {
    ic++;
    ix = i2 - 1;
    i2 += 7;
    iy = ix;
    b_c = 0.0;
    for (k = 0; k < 7; k++) {
      b_c += a[ix] * b[iy];
      ix++;
      iy++;
    }

    c[ic] = b_c;
  }
}

/* End of code generation (dot.cpp) */

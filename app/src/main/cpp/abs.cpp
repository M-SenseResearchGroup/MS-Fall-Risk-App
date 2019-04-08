/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * abs.cpp
 *
 * Code generation for function 'abs'
 *
 */

/* Include files */
#include <cmath>
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "abs.h"
#include "calc_fall_risk_emxutil.h"
#include "sign1.h"
#include "calc_fall_risk_rtwutil.h"
#include <string.h>

/* Function Definitions */
void b_abs(const creal_T x_data[], const int x_size[1], double y_data[], int
           y_size[1])
{
  int nx;
  int k;
  nx = x_size[0];
  y_size[0] = static_cast<short>(x_size[0]);
  for (k = 0; k < nx; k++) {
    y_data[k] = rt_hypotd_snf(x_data[k].re, x_data[k].im);
  }
}

void c_abs(const emxArray_real_T *x, emxArray_real_T *y)
{
  int nx;
  int k;
  nx = x->size[1];
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = x->size[1];
  emxEnsureCapacity_real_T(y, k);
  for (k = 0; k < nx; k++) {
    y->data[k] = std::abs(x->data[k]);
  }
}

/* End of code generation (abs.cpp) */

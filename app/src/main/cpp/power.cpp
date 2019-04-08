/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * power.cpp
 *
 * Code generation for function 'power'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "power.h"
#include "mpower.h"
#include "calc_fall_risk_emxutil.h"
#include "calc_fall_risk_rtwutil.h"
#include <string.h>

/* Function Definitions */
void b_power(const double a_data[], const int a_size[1], double y_data[], int
             y_size[1])
{
  int nx;
  int k;
  y_size[0] = static_cast<short>(a_size[0]);
  nx = static_cast<short>(a_size[0]);
  for (k = 0; k < nx; k++) {
    y_data[k] = rt_powd_snf(a_data[k], 2.0);
  }
}

void c_power(const emxArray_real_T *a, emxArray_real_T *y)
{
  short unnamed_idx_0;
  short unnamed_idx_1;
  int nx;
  int k;
  unnamed_idx_0 = static_cast<short>(a->size[0]);
  unnamed_idx_1 = static_cast<short>(a->size[1]);
  nx = y->size[0] * y->size[1];
  y->size[0] = unnamed_idx_0;
  y->size[1] = unnamed_idx_1;
  emxEnsureCapacity_real_T(y, nx);
  nx = unnamed_idx_0 * unnamed_idx_1;
  for (k = 0; k < nx; k++) {
    y->data[k] = rt_powd_snf(a->data[k], 2.0);
  }
}

void power(const double a_data[], const int a_size[2], double y_data[], int
           y_size[2])
{
  int nx;
  int k;
  y_size[0] = 1;
  y_size[1] = static_cast<short>(a_size[1]);
  nx = static_cast<short>(a_size[1]);
  for (k = 0; k < nx; k++) {
    y_data[k] = rt_powd_snf(a_data[k], 1.5);
  }
}

/* End of code generation (power.cpp) */

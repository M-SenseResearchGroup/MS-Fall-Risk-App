/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * kurtosis.cpp
 *
 * Code generation for function 'kurtosis'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "kurtosis.h"
#include "rdivide_helper.h"
#include "calc_fall_risk_emxutil.h"
#include "nanmean.h"
#include "bsxfun.h"
#include "nan_sum_or_mean.h"
#include <string.h>

/* Function Definitions */
void b_kurtosis(const emxArray_real_T *x, double k_data[], int k_size[2])
{
  emxArray_real_T *x0;
  double s2_data[313];
  int s2_size[2];
  int n_data[313];
  int n_size[2];
  int i12;
  int loop_ub;
  double m4_data[313];
  double b_s2_data[313];
  emxInit_real_T(&x0, 2);
  b_nan_sum_or_mean(x, s2_data, s2_size, n_data, n_size);
  b_bsxfun(x, s2_data, s2_size, x0);
  i12 = x0->size[0] * x0->size[1];
  loop_ub = x0->size[0] * x0->size[1];
  emxEnsureCapacity_real_T(x0, loop_ub);
  loop_ub = i12 - 1;
  for (i12 = 0; i12 <= loop_ub; i12++) {
    x0->data[i12] *= x0->data[i12];
  }

  b_nanmean(x0, s2_data, s2_size);
  i12 = x0->size[0] * x0->size[1];
  loop_ub = x0->size[0] * x0->size[1];
  emxEnsureCapacity_real_T(x0, loop_ub);
  loop_ub = i12 - 1;
  for (i12 = 0; i12 <= loop_ub; i12++) {
    x0->data[i12] *= x0->data[i12];
  }

  b_nanmean(x0, m4_data, n_size);
  loop_ub = s2_size[0] * s2_size[1];
  emxFree_real_T(&x0);
  for (i12 = 0; i12 < loop_ub; i12++) {
    b_s2_data[i12] = s2_data[i12] * s2_data[i12];
  }

  rdivide_helper(m4_data, n_size, b_s2_data, k_data, k_size);
}

double kurtosis(const double x_data[], const int x_size[2])
{
  double s2;
  int n;
  double x0_data[313];
  int x0_size[2];
  int loop_ub;
  nan_sum_or_mean(x_data, x_size, &s2, &n);
  bsxfun(x_data, x_size, s2, x0_data, x0_size);
  n = x0_size[0] * x0_size[1];
  x0_size[0] = 1;
  loop_ub = n - 1;
  for (n = 0; n <= loop_ub; n++) {
    x0_data[n] *= x0_data[n];
  }

  s2 = nanmean(x0_data, x0_size);
  x0_size[0] = 1;
  loop_ub = x0_size[1] - 1;
  for (n = 0; n <= loop_ub; n++) {
    x0_data[n] *= x0_data[n];
  }

  return nanmean(x0_data, x0_size) / (s2 * s2);
}

/* End of code generation (kurtosis.cpp) */

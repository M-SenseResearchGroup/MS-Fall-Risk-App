/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * skewness.cpp
 *
 * Code generation for function 'skewness'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "skewness.h"
#include "sum.h"
#include "calc_fall_risk_emxutil.h"
#include "rdivide_helper.h"
#include "power.h"
#include "nanmean.h"
#include "bsxfun.h"
#include "nan_sum_or_mean.h"
#include "mpower.h"
#include "calc_fall_risk_rtwutil.h"
#include <string.h>

/* Function Definitions */
void b_skewness(const emxArray_real_T *x, double s_data[], int s_size[2])
{
  emxArray_real_T *x0;
  double tmp_data[313];
  int tmp_size[2];
  emxArray_real_T *xp;
  short unnamed_idx_1;
  double s2_data[313];
  int s2_size[2];
  int n_data[313];
  int n_size[2];
  int i8;
  int loop_ub;
  double m3_data[313];
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    sum(x, tmp_data, tmp_size);
    unnamed_idx_1 = static_cast<short>(tmp_size[1]);
    s_size[0] = 1;
    s_size[1] = unnamed_idx_1;
    loop_ub = static_cast<short>(tmp_size[0]) * unnamed_idx_1;
    for (i8 = 0; i8 < loop_ub; i8++) {
      s_data[i8] = rtNaN;
    }
  } else {
    emxInit_real_T(&x0, 2);
    emxInit_real_T(&xp, 2);
    b_nan_sum_or_mean(x, s2_data, s2_size, n_data, n_size);
    b_bsxfun(x, s2_data, s2_size, x0);
    i8 = xp->size[0] * xp->size[1];
    xp->size[0] = x0->size[0];
    xp->size[1] = x0->size[1];
    emxEnsureCapacity_real_T(xp, i8);
    loop_ub = x0->size[0] * x0->size[1];
    for (i8 = 0; i8 < loop_ub; i8++) {
      xp->data[i8] = x0->data[i8] * x0->data[i8];
    }

    b_nanmean(xp, s2_data, s2_size);
    i8 = xp->size[0] * xp->size[1];
    loop_ub = xp->size[0] * xp->size[1];
    emxEnsureCapacity_real_T(xp, loop_ub);
    loop_ub = i8 - 1;
    for (i8 = 0; i8 <= loop_ub; i8++) {
      xp->data[i8] *= x0->data[i8];
    }

    emxFree_real_T(&x0);
    b_nanmean(xp, m3_data, n_size);
    power(s2_data, s2_size, tmp_data, tmp_size);
    rdivide_helper(m3_data, n_size, tmp_data, s_data, s_size);
    emxFree_real_T(&xp);
  }
}

double skewness(const double x_data[], const int x_size[2])
{
  double s;
  double m1;
  int n;
  double x0_data[313];
  int x0_size[2];
  int xp_size[2];
  int i6;
  double xp_data[313];
  if (x_size[1] == 0) {
    s = rtNaN;
  } else {
    nan_sum_or_mean(x_data, x_size, &m1, &n);
    bsxfun(x_data, x_size, m1, x0_data, x0_size);
    xp_size[0] = 1;
    xp_size[1] = x0_size[1];
    n = x0_size[0] * x0_size[1];
    for (i6 = 0; i6 < n; i6++) {
      xp_data[i6] = x0_data[i6] * x0_data[i6];
    }

    m1 = nanmean(xp_data, xp_size);
    xp_size[0] = 1;
    n = x0_size[1] - 1;
    for (i6 = 0; i6 <= n; i6++) {
      xp_data[i6] *= x0_data[i6];
    }

    s = nanmean(xp_data, xp_size) / rt_powd_snf(m1, 1.5);
  }

  return s;
}

/* End of code generation (skewness.cpp) */

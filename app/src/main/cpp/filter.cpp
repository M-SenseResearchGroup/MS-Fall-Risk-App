/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * filter.cpp
 *
 * Code generation for function 'filter'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "filter.h"
#include "calc_fall_risk_emxutil.h"
#include <string.h>

/* Function Definitions */
void b_filter(double b[3], double a[3], const double x[6], const double zi[2],
              double y[6], double zf[2])
{
  int k;
  int j;
  int naxpy;
  int y_tmp;
  double as;
  if ((!rtIsInf(a[0])) && (!rtIsNaN(a[0])) && (!(a[0] == 0.0)) && (a[0] != 1.0))
  {
    b[0] /= a[0];
    b[1] /= a[0];
    b[2] /= a[0];
    a[1] /= a[0];
    a[2] /= a[0];
    a[0] = 1.0;
  }

  zf[0] = 0.0;
  y[0] = zi[0];
  zf[1] = 0.0;
  y[1] = zi[1];
  y[2] = 0.0;
  y[3] = 0.0;
  y[4] = 0.0;
  y[5] = 0.0;
  for (k = 0; k < 6; k++) {
    if (6 - k < 3) {
      naxpy = 5 - k;
    } else {
      naxpy = 2;
    }

    for (j = 0; j <= naxpy; j++) {
      y_tmp = k + j;
      y[y_tmp] += x[k] * b[j];
    }

    if (5 - k < 2) {
      naxpy = 4 - k;
    } else {
      naxpy = 1;
    }

    as = -y[k];
    for (j = 0; j <= naxpy; j++) {
      y_tmp = (k + j) + 1;
      y[y_tmp] += as * a[1 + j];
    }
  }

  for (j = 0; j < 1; j++) {
    zf[0] += x[4] * b[2];
  }

  for (j = 0; j < 2; j++) {
    zf[j] += x[5] * b[j + 1];
  }

  for (j = 0; j < 1; j++) {
    zf[0] += -y[4] * a[2];
  }

  for (j = 0; j < 2; j++) {
    zf[j] += -y[5] * a[j + 1];
  }
}

void filter(double b[3], double a[3], const emxArray_real_T *x, const double zi
            [2], emxArray_real_T *y)
{
  unsigned int x_idx_0;
  int i5;
  int nx;
  int k;
  int a_tmp;
  int naxpy;
  int j;
  double as;
  if ((!rtIsInf(a[0])) && (!rtIsNaN(a[0])) && (!(a[0] == 0.0)) && (a[0] != 1.0))
  {
    b[0] /= a[0];
    b[1] /= a[0];
    b[2] /= a[0];
    a[1] /= a[0];
    a[2] /= a[0];
    a[0] = 1.0;
  }

  x_idx_0 = static_cast<unsigned int>(x->size[0]);
  i5 = y->size[0];
  y->size[0] = static_cast<int>(x_idx_0);
  emxEnsureCapacity_real_T(y, i5);
  nx = x->size[0];
  y->data[0] = zi[0];
  y->data[1] = zi[1];
  for (k = 3; k <= nx; k++) {
    y->data[k - 1] = 0.0;
  }

  for (k = 0; k < nx; k++) {
    a_tmp = nx - k;
    if (a_tmp < 3) {
      naxpy = a_tmp;
    } else {
      naxpy = 3;
    }

    for (j = 0; j < naxpy; j++) {
      i5 = k + j;
      y->data[i5] += x->data[k] * b[j];
    }

    naxpy = a_tmp - 1;
    if (naxpy >= 2) {
      naxpy = 2;
    }

    as = -y->data[k];
    for (j = 0; j < naxpy; j++) {
      i5 = (k + j) + 1;
      y->data[i5] += as * a[1 + j];
    }
  }
}

/* End of code generation (filter.cpp) */

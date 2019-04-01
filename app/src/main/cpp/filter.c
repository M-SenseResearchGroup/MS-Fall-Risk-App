/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * filter.c
 *
 * Code generation for function 'filter'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "calibrate.h"
#include "get_calibration.h"
#include "get_classification.h"
#include "get_fall_class.h"
#include "get_features.h"
#include "get_strides.h"
#include "pre_process_feats.h"
#include "filter.h"

/* Function Definitions */
void b_filter(double b[3], double a[3], const double x[512], const double zi[2],
              double y[512])
{
  int k;
  int naxpy;
  int j;
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

  y[0] = zi[0];
  y[1] = zi[1];
  memset(&y[2], 0, 510U * sizeof(double));
  for (k = 0; k < 512; k++) {
    if (512 - k < 3) {
      naxpy = 511 - k;
    } else {
      naxpy = 2;
    }

    for (j = 0; j <= naxpy; j++) {
      y_tmp = k + j;
      y[y_tmp] += x[k] * b[j];
    }

    if (511 - k < 2) {
      naxpy = 510 - k;
    } else {
      naxpy = 1;
    }

    as = -y[k];
    for (j = 0; j <= naxpy; j++) {
      y_tmp = (k + j) + 1;
      y[y_tmp] += as * a[1 + j];
    }
  }
}

void filter(double b[3], double a[3], const double x[137], const double zi[2],
            double y[137])
{
  int k;
  int naxpy;
  int j;
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

  y[0] = zi[0];
  y[1] = zi[1];
  memset(&y[2], 0, 135U * sizeof(double));
  for (k = 0; k < 137; k++) {
    if (137 - k < 3) {
      naxpy = 136 - k;
    } else {
      naxpy = 2;
    }

    for (j = 0; j <= naxpy; j++) {
      y_tmp = k + j;
      y[y_tmp] += x[k] * b[j];
    }

    if (136 - k < 2) {
      naxpy = 135 - k;
    } else {
      naxpy = 1;
    }

    as = -y[k];
    for (j = 0; j <= naxpy; j++) {
      y_tmp = (k + j) + 1;
      y[y_tmp] += as * a[1 + j];
    }
  }
}

/* End of code generation (filter.c) */

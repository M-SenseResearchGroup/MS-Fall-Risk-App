/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mean.c
 *
 * Code generation for function 'mean'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calibrate.h"
#include "get_calibration.h"
#include "get_classification.h"
#include "get_fall_class.h"
#include "get_features.h"
#include "get_strides.h"
#include "pre_process_feats.h"
#include "mean.h"
#include <string.h>

/* Function Definitions */
double b_mean(const double x[125])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 124; k++) {
    y += x[k + 1];
  }

  y /= 125.0;
  return y;
}

double c_mean(const double x[500])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 499; k++) {
    y += x[k + 1];
  }

  y /= 500.0;
  return y;
}

double mean(const emxArray_real_T *x)
{
  double y;
  int vlen;
  int k;
  vlen = x->size[1];
  if (x->size[1] == 0) {
    y = 0.0;
  } else {
    y = x->data[0];
    for (k = 2; k <= vlen; k++) {
      y += x->data[k - 1];
    }
  }

  y /= (double)x->size[1];
  return y;
}

/* End of code generation (mean.c) */

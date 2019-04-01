/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * vvarstd.c
 *
 * Code generation for function 'vvarstd'
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
#include "vvarstd.h"
#include <string.h>

/* Function Definitions */
double vvarstd(const double v[125])
{
  double s;
  double xbar;
  int k;
  double t;
  xbar = v[0];
  for (k = 0; k < 124; k++) {
    xbar += v[k + 1];
  }

  xbar /= 125.0;
  s = 0.0;
  for (k = 0; k < 125; k++) {
    t = v[k] - xbar;
    s += t * t;
  }

  s /= 124.0;
  return s;
}

/* End of code generation (vvarstd.c) */

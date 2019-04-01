/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sum.c
 *
 * Code generation for function 'sum'
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
#include "sum.h"
#include <string.h>

/* Function Definitions */
double b_sum(void)
{
  double y;
  int k;
  y = 1.0;
  for (k = 0; k < 62; k++) {
    y++;
  }

  return y;
}

double sum(const double x[125])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 124; k++) {
    y += x[k + 1];
  }

  return y;
}

/* End of code generation (sum.c) */

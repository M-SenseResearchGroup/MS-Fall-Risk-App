/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * kurtosis.c
 *
 * Code generation for function 'kurtosis'
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
#include "kurtosis.h"
#include <string.h>

/* Function Definitions */
double kurtosis(const double x[125])
{
  double m4;
  int c;
  int b_k;
  double s2;
  double d6;
  double x0[125];
  m4 = 0.0;
  c = 0;
  for (b_k = 0; b_k < 125; b_k++) {
    if (!rtIsNaN(x[b_k])) {
      m4 += x[b_k];
      c++;
    }
  }

  if (c == 0) {
    m4 = rtNaN;
  } else {
    m4 /= (double)c;
  }

  s2 = 0.0;
  c = 0;
  for (b_k = 0; b_k < 125; b_k++) {
    d6 = x[b_k] - m4;
    d6 *= d6;
    x0[b_k] = d6;
    if (!rtIsNaN(d6)) {
      s2 += d6;
      c++;
    }
  }

  if (c == 0) {
    s2 = rtNaN;
  } else {
    s2 /= (double)c;
  }

  m4 = 0.0;
  c = 0;
  for (b_k = 0; b_k < 125; b_k++) {
    d6 = x0[b_k] * x0[b_k];
    x0[b_k] = d6;
    if (!rtIsNaN(d6)) {
      m4 += d6;
      c++;
    }
  }

  if (c == 0) {
    m4 = rtNaN;
  } else {
    m4 /= (double)c;
  }

  return m4 / (s2 * s2);
}

/* End of code generation (kurtosis.c) */

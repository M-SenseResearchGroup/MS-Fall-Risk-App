/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * skewness.c
 *
 * Code generation for function 'skewness'
 *
 */

/* Include files */
#include <math.h>
#include "rt_nonfinite.h"
#include "calibrate.h"
#include "get_calibration.h"
#include "get_classification.h"
#include "get_fall_class.h"
#include "get_features.h"
#include "get_strides.h"
#include "pre_process_feats.h"
#include "skewness.h"
#include <string.h>

/* Function Declarations */
static double rt_powd_snf(double u0, double u1);

/* Function Definitions */
static double rt_powd_snf(double u0, double u1)
{
  double y;
  double d9;
  double d10;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else {
    d9 = fabs(u0);
    d10 = fabs(u1);
    if (rtIsInf(u1)) {
      if (d9 == 1.0) {
        y = 1.0;
      } else if (d9 > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d10 == 0.0) {
      y = 1.0;
    } else if (d10 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = rtNaN;
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

double skewness(const double x[125])
{
  double m1;
  int c;
  int k;
  double s2;
  double d5;
  double x0[125];
  double xp[125];
  m1 = 0.0;
  c = 0;
  for (k = 0; k < 125; k++) {
    if (!rtIsNaN(x[k])) {
      m1 += x[k];
      c++;
    }
  }

  if (c == 0) {
    m1 = rtNaN;
  } else {
    m1 /= (double)c;
  }

  s2 = 0.0;
  c = 0;
  for (k = 0; k < 125; k++) {
    d5 = x[k] - m1;
    x0[k] = d5;
    d5 *= d5;
    xp[k] = d5;
    if (!rtIsNaN(d5)) {
      s2 += d5;
      c++;
    }
  }

  if (c == 0) {
    m1 = rtNaN;
  } else {
    m1 = s2 / (double)c;
  }

  s2 = 0.0;
  c = 0;
  for (k = 0; k < 125; k++) {
    d5 = xp[k] * x0[k];
    xp[k] = d5;
    if (!rtIsNaN(d5)) {
      s2 += d5;
      c++;
    }
  }

  if (c == 0) {
    s2 = rtNaN;
  } else {
    s2 /= (double)c;
  }

  return s2 / rt_powd_snf(m1, 1.5);
}

/* End of code generation (skewness.c) */

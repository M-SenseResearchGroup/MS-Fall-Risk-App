/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * vvarstd.cpp
 *
 * Code generation for function 'vvarstd'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "vvarstd.h"
#include <string.h>

/* Function Definitions */
double vvarstd(const double v_data[], const int v_size[1], int n)
{
  double s;
  double xbar;
  int k;
  double t;
  if (n == 0) {
    s = rtNaN;
  } else if (n == 1) {
    if ((!rtIsInf(v_data[0])) && (!rtIsNaN(v_data[0]))) {
      s = 0.0;
    } else {
      s = rtNaN;
    }
  } else {
    if (v_size[0] == 0) {
      xbar = 0.0;
    } else {
      xbar = v_data[0];
      for (k = 2; k <= n; k++) {
        xbar += v_data[k - 1];
      }
    }

    xbar /= static_cast<double>(n);
    s = 0.0;
    for (k = 0; k < n; k++) {
      t = v_data[k] - xbar;
      s += t * t;
    }

    s /= static_cast<double>((n - 1));
  }

  return s;
}

/* End of code generation (vvarstd.cpp) */

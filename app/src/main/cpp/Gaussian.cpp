/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Gaussian.cpp
 *
 * Code generation for function 'Gaussian'
 *
 */

/* Include files */
#include <cmath>
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "Gaussian.h"
#include <string.h>

/* Function Definitions */
void Gaussian(const double svT[9394], const double svInnerProduct[1342], const
              double x[7], double kernelProduct[1342])
{
  int k;
  double b_x;
  int i78;
  double y[1342];
  for (k = 0; k < 1342; k++) {
    b_x = 0.0;
    for (i78 = 0; i78 < 7; i78++) {
      b_x += -2.0 * x[i78] * svT[i78 + 7 * k];
    }

    y[k] = b_x;
  }

  b_x = 0.0;
  for (k = 0; k < 7; k++) {
    b_x += x[k] * x[k];
  }

  for (k = 0; k < 1342; k++) {
    kernelProduct[k] = std::exp(-((y[k] + b_x) + svInnerProduct[k]));
  }
}

/* End of code generation (Gaussian.cpp) */

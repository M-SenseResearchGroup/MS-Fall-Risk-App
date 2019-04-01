/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Gaussian.c
 *
 * Code generation for function 'Gaussian'
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
#include "Gaussian.h"
#include <string.h>

/* Function Definitions */
void Gaussian(const double svT[9394], const double svInnerProduct[1342], const
              double x[7], double kernelProduct[1342])
{
  int k;
  double b_x;
  int i7;
  double y[1342];
  for (k = 0; k < 1342; k++) {
    b_x = 0.0;
    for (i7 = 0; i7 < 7; i7++) {
      b_x += -2.0 * x[i7] * svT[i7 + 7 * k];
    }

    y[k] = b_x;
  }

  b_x = 0.0;
  for (k = 0; k < 7; k++) {
    b_x += x[k] * x[k];
  }

  for (k = 0; k < 1342; k++) {
    kernelProduct[k] = exp(-((y[k] + b_x) + svInnerProduct[k]));
  }
}

/* End of code generation (Gaussian.c) */

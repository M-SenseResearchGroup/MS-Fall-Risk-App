/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * poly1.c
 *
 * Code generation for function 'poly1'
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
#include "poly1.h"
#include <string.h>

/* Function Definitions */
void poly(const creal_T x[2], creal_T c[3])
{
  int k;
  c[0].re = 1.0;
  c[0].im = 0.0;
  c[1].re = -x[0].re - -x[0].im * 0.0;
  c[1].im = -x[0].re * 0.0 + -x[0].im;
  c[2].re = -x[1].re * c[1].re - -x[1].im * c[1].im;
  c[2].im = -x[1].re * c[1].im + -x[1].im * c[1].re;
  for (k = 2; k >= 2; k--) {
    c[1].re -= x[1].re - x[1].im * 0.0;
    c[1].im -= x[1].re * 0.0 + x[1].im;
  }
}

/* End of code generation (poly1.c) */

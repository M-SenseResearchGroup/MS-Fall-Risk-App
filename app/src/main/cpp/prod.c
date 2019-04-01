/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * prod.c
 *
 * Code generation for function 'prod'
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
#include "prod.h"
#include <string.h>

/* Function Definitions */
creal_T prod(const creal_T x[2])
{
  creal_T y;
  y.re = x[0].re * x[1].re - x[0].im * x[1].im;
  y.im = x[0].re * x[1].im + x[0].im * x[1].re;
  return y;
}

/* End of code generation (prod.c) */

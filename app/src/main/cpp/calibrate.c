/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calibrate.c
 *
 * Code generation for function 'calibrate'
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
#include <string.h>

/* Function Definitions */
void calibrate(const double x[375], const double r[9], double g, double y[375])
{
  int i0;
  int i1;

  /*  input: */
  /*    x - data to calibrate */
  /*    r - sensor 2 body dcm */
  /*    g - gravity magnitude */
  /*  output: */
  /*    y - calibrated data */
  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 125; i1++) {
      y[i0 + 3 * i1] = ((r[i0] * x[3 * i1] + r[i0 + 3] * x[1 + 3 * i1]) + r[i0 +
                        6] * x[2 + 3 * i1]) / g;
    }
  }
}

/* End of code generation (calibrate.c) */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * vecnorm.c
 *
 * Code generation for function 'vecnorm'
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
#include "vecnorm.h"
#include <string.h>

/* Function Definitions */
void vecnorm(const double x[250], double y[125])
{
  int j;
  int ix0;
  double b_y;
  double scale;
  int kend;
  int k;
  double absxk;
  double t;
  for (j = 0; j < 125; j++) {
    ix0 = j << 1;
    b_y = 0.0;
    scale = 3.3121686421112381E-170;
    kend = ix0 + 2;
    for (k = ix0 + 1; k <= kend; k++) {
      absxk = fabs(x[k - 1]);
      if (absxk > scale) {
        t = scale / absxk;
        b_y = 1.0 + b_y * t * t;
        scale = absxk;
      } else {
        t = absxk / scale;
        b_y += t * t;
      }
    }

    y[j] = scale * sqrt(b_y);
  }
}

/* End of code generation (vecnorm.c) */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sign1.c
 *
 * Code generation for function 'sign1'
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
#include "sign1.h"
#include "sortLE.h"
#include "getFallClass_rtwutil.h"
#include <string.h>

/* Function Definitions */
void c_sign(creal_T *x)
{
  double xr;
  double xi;
  double absx;
  xr = x->re;
  xi = x->im;
  if (xi == 0.0) {
    if (xr < 0.0) {
      xr = -1.0;
    } else if (xr > 0.0) {
      xr = 1.0;
    } else {
      if (xr == 0.0) {
        xr = 0.0;
      }
    }

    x->re = xr;
    x->im = 0.0;
  } else {
    if ((fabs(xr) > 8.9884656743115785E+307) || (fabs(xi) >
         8.9884656743115785E+307)) {
      xr /= 2.0;
      xi /= 2.0;
    }

    absx = rt_hypotd_snf(xr, xi);
    if (absx == 0.0) {
      x->re = 0.0;
      x->im = 0.0;
    } else {
      x->re = xr / absx;
      x->im = xi / absx;
    }
  }
}

/* End of code generation (sign1.c) */

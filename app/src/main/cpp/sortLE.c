/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sortLE.c
 *
 * Code generation for function 'sortLE'
 *
 */

/* Include files */
#include <math.h>
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "calibrate.h"
#include "get_calibration.h"
#include "get_classification.h"
#include "get_fall_class.h"
#include "get_features.h"
#include "get_strides.h"
#include "pre_process_feats.h"
#include "sortLE.h"
#include "relop.h"
#include "getFallClass_rtwutil.h"
#include <string.h>

/* Function Declarations */
static double rt_atan2d_snf(double u0, double u1);

/* Function Definitions */
static double rt_atan2d_snf(double u0, double u1)
{
  double y;
  int b_u0;
  int b_u1;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      b_u0 = 1;
    } else {
      b_u0 = -1;
    }

    if (u1 > 0.0) {
      b_u1 = 1;
    } else {
      b_u1 = -1;
    }

    y = atan2(b_u0, b_u1);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

boolean_T sortLE(const emxArray_creal_T *v, int idx1, int idx2)
{
  boolean_T p;
  boolean_T SCALEA;
  boolean_T SCALEB;
  double x;
  double y;
  creal_T b_v;
  creal_T c_v;
  if (rtIsNaN(v->data[idx2 - 1].re) || rtIsNaN(v->data[idx2 - 1].im)) {
    p = (rtIsNaN(v->data[idx1 - 1].re) || rtIsNaN(v->data[idx1 - 1].im));
  } else if (rtIsNaN(v->data[idx1 - 1].re) || rtIsNaN(v->data[idx1 - 1].im)) {
    p = true;
  } else {
    if ((fabs(v->data[idx1 - 1].re) > 8.9884656743115785E+307) || (fabs(v->
          data[idx1 - 1].im) > 8.9884656743115785E+307)) {
      SCALEA = true;
    } else {
      SCALEA = false;
    }

    if ((fabs(v->data[idx2 - 1].re) > 8.9884656743115785E+307) || (fabs(v->
          data[idx2 - 1].im) > 8.9884656743115785E+307)) {
      SCALEB = true;
    } else {
      SCALEB = false;
    }

    if (SCALEA || SCALEB) {
      x = rt_hypotd_snf(v->data[idx1 - 1].re / 2.0, v->data[idx1 - 1].im / 2.0);
      y = rt_hypotd_snf(v->data[idx2 - 1].re / 2.0, v->data[idx2 - 1].im / 2.0);
    } else {
      x = rt_hypotd_snf(v->data[idx1 - 1].re, v->data[idx1 - 1].im);
      y = rt_hypotd_snf(v->data[idx2 - 1].re, v->data[idx2 - 1].im);
    }

    if (iseq(x, y)) {
      b_v = v->data[idx1 - 1];
      c_v = v->data[idx2 - 1];
      roundOffMitigatedAbsProxies(b_v, c_v, &x, &y);
      if (iseq(x, y)) {
        x = rt_atan2d_snf(v->data[idx1 - 1].im, v->data[idx1 - 1].re);
        y = rt_atan2d_snf(v->data[idx2 - 1].im, v->data[idx2 - 1].re);
        if (iseq(x, y)) {
          b_v = v->data[idx1 - 1];
          c_v = v->data[idx2 - 1];
          c_roundOffMitigatedPhaseAnglePr(b_v, c_v, &x, &y);
          if (iseq(x, y)) {
            x = 0.0;
            y = 0.0;
          }
        }
      }
    }

    p = (x >= y);
  }

  return p;
}

/* End of code generation (sortLE.c) */

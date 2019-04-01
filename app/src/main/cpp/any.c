/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * any.c
 *
 * Code generation for function 'any'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "calibrate.h"
#include "get_calibration.h"
#include "get_classification.h"
#include "get_fall_class.h"
#include "get_features.h"
#include "get_strides.h"
#include "pre_process_feats.h"
#include "any.h"

/* Function Definitions */
boolean_T any(const boolean_T x[2])
{
  boolean_T y;
  int k;
  boolean_T exitg1;
  y = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (x[k]) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return y;
}

void b_any(const emxArray_creal_T *x, boolean_T y_data[], int y_size[3])
{
  short outsize_idx_1;
  int npages;
  int i2;
  int iy;
  int i;
  int i1;
  boolean_T exitg1;
  boolean_T b_x;
  outsize_idx_1 = (short)x->size[1];
  y_size[0] = 1;
  y_size[1] = outsize_idx_1;
  y_size[2] = 1;
  if (0 <= outsize_idx_1 - 1) {
    memset(&y_data[0], 0, (unsigned int)(outsize_idx_1 * (int)sizeof(boolean_T)));
  }

  npages = x->size[1];
  i2 = 0;
  iy = -1;
  for (i = 0; i < npages; i++) {
    i1 = i2 - 1;
    i2 = (i2 + x->size[0]) - 1;
    i1++;
    i2++;
    iy++;
    exitg1 = false;
    while ((!exitg1) && (i1 + 1 <= i2)) {
      b_x = ((x->data[i1].re == 0.0) && (x->data[i1].im == 0.0));
      if (b_x || (rtIsNaN(x->data[i1].re) || rtIsNaN(x->data[i1].im))) {
        i1++;
      } else {
        y_data[iy] = true;
        exitg1 = true;
      }
    }
  }
}

boolean_T c_any(const double x_data[], const int x_size[2])
{
  boolean_T y;
  int ix;
  boolean_T exitg1;
  y = false;
  ix = 0;
  exitg1 = false;
  while ((!exitg1) && (ix + 1 <= x_size[1])) {
    if ((x_data[ix] == 0.0) || rtIsNaN(x_data[ix])) {
      ix++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  return y;
}

boolean_T d_any(const double x_data[], const int x_size[1])
{
  boolean_T y;
  int ix;
  boolean_T exitg1;
  y = false;
  ix = 0;
  exitg1 = false;
  while ((!exitg1) && (ix + 1 <= x_size[0])) {
    if ((x_data[ix] == 0.0) || rtIsNaN(x_data[ix])) {
      ix++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  return y;
}

boolean_T e_any(const double x[499])
{
  boolean_T y;
  int k;
  boolean_T exitg1;
  y = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 499)) {
    if ((x[k] == 0.0) || rtIsNaN(x[k])) {
      k++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  return y;
}

/* End of code generation (any.c) */

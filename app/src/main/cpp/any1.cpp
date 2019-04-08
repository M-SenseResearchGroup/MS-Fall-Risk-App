/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * any1.cpp
 *
 * Code generation for function 'any1'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "any1.h"

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
  short x_size[3];
  int npages;
  int i2;
  int iy;
  int i;
  int i1;
  boolean_T exitg1;
  boolean_T b_x;
  outsize_idx_1 = static_cast<short>(x->size[1]);
  y_size[0] = 1;
  y_size[1] = outsize_idx_1;
  y_size[2] = 1;
  if (0 <= outsize_idx_1 - 1) {
    memset(&y_data[0], 0, (unsigned int)(outsize_idx_1 * static_cast<int>(sizeof
             (boolean_T))));
  }

  x_size[1] = static_cast<short>(x->size[1]);
  npages = x_size[1];
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

boolean_T c_any(const emxArray_real_T *x)
{
  boolean_T y;
  int ix;
  boolean_T exitg1;
  y = false;
  ix = 0;
  exitg1 = false;
  while ((!exitg1) && (ix + 1 <= x->size[1])) {
    if ((x->data[ix] == 0.0) || rtIsNaN(x->data[ix])) {
      ix++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  return y;
}

boolean_T d_any(const emxArray_real_T *x)
{
  boolean_T y;
  int ix;
  boolean_T exitg1;
  y = false;
  ix = 0;
  exitg1 = false;
  while ((!exitg1) && (ix + 1 <= x->size[0])) {
    if ((x->data[ix] == 0.0) || rtIsNaN(x->data[ix])) {
      ix++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  return y;
}

void e_any(const emxArray_real_T *x, boolean_T y_data[], int y_size[2])
{
  int a;
  int ix;
  boolean_T exitg1;
  y_size[0] = 1;
  y_size[1] = 1;
  y_data[0] = false;
  a = x->size[0];
  ix = 0;
  exitg1 = false;
  while ((!exitg1) && (ix + 1 <= a)) {
    if ((x->data[ix] == 0.0) || rtIsNaN(x->data[ix])) {
      ix++;
    } else {
      y_size[0] = 1;
      y_size[1] = 1;
      y_data[0] = true;
      exitg1 = true;
    }
  }
}

/* End of code generation (any1.cpp) */

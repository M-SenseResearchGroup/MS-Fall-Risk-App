/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fft.cpp
 *
 * Code generation for function 'fft'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "fft.h"
#include "calc_fall_risk_emxutil.h"
#include "fft1.h"
#include <string.h>

/* Function Definitions */
void b_fft(const double x_data[], const int x_size[2], emxArray_creal_T *y)
{
  emxArray_creal_T *b_y;
  emxArray_real_T *costab;
  int i35;
  emxArray_real_T *sintab;
  emxArray_real_T *sintabinv;
  emxArray_real_T b_x_data;
  int loop_ub;
  int b_loop_ub;
  int i36;
  emxInit_creal_T(&b_y, 2);
  if (x_size[0] == 0) {
    i35 = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 4096;
    b_y->size[1] = 1;
    emxEnsureCapacity_creal_T(b_y, i35);
    loop_ub = b_y->size[1];
    for (i35 = 0; i35 < loop_ub; i35++) {
      b_loop_ub = b_y->size[0];
      for (i36 = 0; i36 < b_loop_ub; i36++) {
        b_y->data[i36 + b_y->size[0] * i35].re = 0.0;
        b_y->data[i36 + b_y->size[0] * i35].im = 0.0;
      }
    }

    i35 = y->size[0] * y->size[1];
    y->size[0] = b_y->size[0];
    y->size[1] = b_y->size[1];
    emxEnsureCapacity_creal_T(y, i35);
    loop_ub = b_y->size[0] * b_y->size[1];
    for (i35 = 0; i35 < loop_ub; i35++) {
      y->data[i35] = b_y->data[i35];
    }
  } else {
    emxInit_real_T(&costab, 2);
    emxInit_real_T(&sintab, 2);
    emxInit_real_T(&sintabinv, 2);
    generate_twiddle_tables(4096, true, costab, sintab, sintabinv);
    b_x_data.data = const_cast<double *>(&x_data[0]);
    b_x_data.size = const_cast<int *>(&x_size[0]);
    b_x_data.allocatedSize = -1;
    b_x_data.numDimensions = 2;
    b_x_data.canFreeData = false;
    c_r2br_r2dit_trig(&b_x_data, 4096, costab, sintab, b_y);
    i35 = y->size[0] * y->size[1];
    y->size[0] = b_y->size[0];
    y->size[1] = b_y->size[1];
    emxEnsureCapacity_creal_T(y, i35);
    loop_ub = b_y->size[0] * b_y->size[1];
    emxFree_real_T(&sintabinv);
    emxFree_real_T(&sintab);
    emxFree_real_T(&costab);
    for (i35 = 0; i35 < loop_ub; i35++) {
      y->data[i35] = b_y->data[i35];
    }
  }

  emxFree_creal_T(&b_y);
}

void c_fft(const emxArray_real_T *x, double varargin_1, emxArray_creal_T *y)
{
  emxArray_real_T *costab;
  emxArray_real_T *sintab;
  emxArray_real_T *sintabinv;
  boolean_T guard1 = false;
  int N2blue;
  boolean_T useRadix2;
  int nRows;
  emxInit_real_T(&costab, 2);
  emxInit_real_T(&sintab, 2);
  emxInit_real_T(&sintabinv, 2);
  guard1 = false;
  if (x->size[0] == 0) {
    guard1 = true;
  } else {
    N2blue = static_cast<int>(varargin_1);
    if (N2blue == 0) {
      guard1 = true;
    } else {
      useRadix2 = ((N2blue & (N2blue - 1)) == 0);
      get_algo_sizes((int)varargin_1, useRadix2, &N2blue, &nRows);
      generate_twiddle_tables(nRows, useRadix2, costab, sintab, sintabinv);
      if (useRadix2) {
        r2br_r2dit_trig(x, (int)varargin_1, costab, sintab, y);
      } else {
        dobluesteinfft(x, N2blue, (int)varargin_1, costab, sintab, sintabinv, y);
      }
    }
  }

  if (guard1) {
    N2blue = y->size[0];
    y->size[0] = static_cast<int>(varargin_1);
    emxEnsureCapacity_creal_T(y, N2blue);
    if (static_cast<int>(varargin_1) > x->size[0]) {
      nRows = y->size[0];
      N2blue = y->size[0];
      y->size[0] = nRows;
      emxEnsureCapacity_creal_T(y, N2blue);
      for (N2blue = 0; N2blue < nRows; N2blue++) {
        y->data[N2blue].re = 0.0;
        y->data[N2blue].im = 0.0;
      }
    }
  }

  emxFree_real_T(&sintabinv);
  emxFree_real_T(&sintab);
  emxFree_real_T(&costab);
}

void d_fft(const emxArray_real_T *x, double varargin_1, emxArray_creal_T *y)
{
  emxArray_real_T *costab;
  emxArray_real_T *sintab;
  emxArray_real_T *sintabinv;
  boolean_T guard1 = false;
  int N2blue;
  boolean_T useRadix2;
  int nRows;
  int loop_ub;
  int i57;
  emxInit_real_T(&costab, 2);
  emxInit_real_T(&sintab, 2);
  emxInit_real_T(&sintabinv, 2);
  guard1 = false;
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    guard1 = true;
  } else {
    N2blue = static_cast<int>(varargin_1);
    if (N2blue == 0) {
      guard1 = true;
    } else {
      useRadix2 = ((N2blue & (N2blue - 1)) == 0);
      get_algo_sizes((int)varargin_1, useRadix2, &N2blue, &nRows);
      generate_twiddle_tables(nRows, useRadix2, costab, sintab, sintabinv);
      if (useRadix2) {
        c_r2br_r2dit_trig(x, (int)varargin_1, costab, sintab, y);
      } else {
        b_dobluesteinfft(x, N2blue, (int)varargin_1, costab, sintab, sintabinv,
                         y);
      }
    }
  }

  if (guard1) {
    N2blue = y->size[0] * y->size[1];
    y->size[0] = static_cast<int>(varargin_1);
    y->size[1] = static_cast<short>(x->size[1]);
    emxEnsureCapacity_creal_T(y, N2blue);
    if (static_cast<int>(varargin_1) > x->size[0]) {
      N2blue = y->size[0] * y->size[1];
      emxEnsureCapacity_creal_T(y, N2blue);
      nRows = y->size[1];
      for (N2blue = 0; N2blue < nRows; N2blue++) {
        loop_ub = y->size[0];
        for (i57 = 0; i57 < loop_ub; i57++) {
          y->data[i57 + y->size[0] * N2blue].re = 0.0;
          y->data[i57 + y->size[0] * N2blue].im = 0.0;
        }
      }
    }
  }

  emxFree_real_T(&sintabinv);
  emxFree_real_T(&sintab);
  emxFree_real_T(&costab);
}

void fft(const double x_data[], const int x_size[1], emxArray_creal_T *y)
{
  emxArray_creal_T *b_y;
  emxArray_real_T *costab;
  int i19;
  emxArray_real_T *sintab;
  emxArray_real_T *sintabinv;
  int loop_ub;
  emxArray_real_T b_x_data;
  emxInit_creal_T(&b_y, 1);
  if (x_size[0] == 0) {
    i19 = b_y->size[0];
    b_y->size[0] = 4096;
    emxEnsureCapacity_creal_T(b_y, i19);
    loop_ub = b_y->size[0];
    i19 = b_y->size[0];
    b_y->size[0] = loop_ub;
    emxEnsureCapacity_creal_T(b_y, i19);
    for (i19 = 0; i19 < loop_ub; i19++) {
      b_y->data[i19].re = 0.0;
      b_y->data[i19].im = 0.0;
    }

    i19 = y->size[0];
    y->size[0] = b_y->size[0];
    emxEnsureCapacity_creal_T(y, i19);
    loop_ub = b_y->size[0];
    for (i19 = 0; i19 < loop_ub; i19++) {
      y->data[i19] = b_y->data[i19];
    }
  } else {
    emxInit_real_T(&costab, 2);
    emxInit_real_T(&sintab, 2);
    emxInit_real_T(&sintabinv, 2);
    generate_twiddle_tables(4096, true, costab, sintab, sintabinv);
    b_x_data.data = const_cast<double *>(&x_data[0]);
    b_x_data.size = const_cast<int *>(&x_size[0]);
    b_x_data.allocatedSize = -1;
    b_x_data.numDimensions = 1;
    b_x_data.canFreeData = false;
    r2br_r2dit_trig(&b_x_data, 4096, costab, sintab, b_y);
    i19 = y->size[0];
    y->size[0] = b_y->size[0];
    emxEnsureCapacity_creal_T(y, i19);
    loop_ub = b_y->size[0];
    emxFree_real_T(&sintabinv);
    emxFree_real_T(&sintab);
    emxFree_real_T(&costab);
    for (i19 = 0; i19 < loop_ub; i19++) {
      y->data[i19] = b_y->data[i19];
    }
  }

  emxFree_creal_T(&b_y);
}

/* End of code generation (fft.cpp) */

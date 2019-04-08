/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ifft.cpp
 *
 * Code generation for function 'ifft'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "ifft.h"
#include "calc_fall_risk_emxutil.h"
#include "fft1.h"
#include <string.h>

/* Function Definitions */
void b_ifft(const emxArray_creal_T *x, emxArray_creal_T *y)
{
  emxArray_creal_T *b_y;
  emxArray_real_T *costab;
  emxArray_real_T *sintab;
  int N2blue;
  emxArray_real_T *sintabinv;
  boolean_T useRadix2;
  int nRows;
  emxInit_creal_T(&b_y, 1);
  if (x->size[0] == 0) {
    b_y->size[0] = 0;
    N2blue = y->size[0];
    y->size[0] = b_y->size[0];
    emxEnsureCapacity_creal_T(y, N2blue);
    nRows = b_y->size[0];
    for (N2blue = 0; N2blue < nRows; N2blue++) {
      y->data[N2blue] = b_y->data[N2blue];
    }
  } else {
    emxInit_real_T(&costab, 2);
    emxInit_real_T(&sintab, 2);
    emxInit_real_T(&sintabinv, 2);
    useRadix2 = ((x->size[0] & (x->size[0] - 1)) == 0);
    get_algo_sizes(x->size[0], useRadix2, &N2blue, &nRows);
    c_generate_twiddle_tables(nRows, useRadix2, costab, sintab, sintabinv);
    if (useRadix2) {
      b_r2br_r2dit_trig(x, x->size[0], costab, sintab, b_y);
      N2blue = y->size[0];
      y->size[0] = b_y->size[0];
      emxEnsureCapacity_creal_T(y, N2blue);
      nRows = b_y->size[0];
      for (N2blue = 0; N2blue < nRows; N2blue++) {
        y->data[N2blue] = b_y->data[N2blue];
      }
    } else {
      f_dobluesteinfft(x, N2blue, x->size[0], costab, sintab, sintabinv, y);
    }

    emxFree_real_T(&sintabinv);
    emxFree_real_T(&sintab);
    emxFree_real_T(&costab);
  }

  emxFree_creal_T(&b_y);
}

void ifft(const double x_data[], const int x_size[1], creal_T y_data[], int
          y_size[1])
{
  boolean_T useRadix2;
  emxArray_creal_T *y;
  int N2blue;
  int nRows;
  static double costab_data[2499];
  int costab_size[2];
  double sintab_data[2499];
  int sintab_size[2];
  double sintabinv_data[2499];
  int sintabinv_size[2];
  if (x_size[0] == 0) {
    emxInit_creal_T(&y, 1);
    y->size[0] = 0;
    y_size[0] = y->size[0];
    N2blue = y->size[0];
    for (nRows = 0; nRows < N2blue; nRows++) {
      y_data[nRows] = y->data[nRows];
    }

    emxFree_creal_T(&y);
  } else {
    useRadix2 = ((x_size[0] & (x_size[0] - 1)) == 0);
    get_algo_sizes(x_size[0], useRadix2, &N2blue, &nRows);
    b_generate_twiddle_tables(nRows, useRadix2, costab_data, costab_size,
      sintab_data, sintab_size, sintabinv_data, sintabinv_size);
    if (useRadix2) {
      d_r2br_r2dit_trig(x_data, x_size, x_size[0], costab_data, sintab_data,
                        y_data, y_size);
    } else {
      c_dobluesteinfft(x_data, x_size, N2blue, x_size[0], costab_data,
                       costab_size, sintab_data, sintab_size, sintabinv_data,
                       sintabinv_size, y_data, y_size);
    }
  }
}

/* End of code generation (ifft.cpp) */

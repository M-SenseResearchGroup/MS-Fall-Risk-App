/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fft1.c
 *
 * Code generation for function 'fft1'
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
#include "fft1.h"
#include "getFallClass_emxutil.h"
#include <string.h>

/* Function Declarations */
static void r2br_r2dit_trig_impl(const double x_data[], const int x_size[2],
  const double costab_data[], const double sintab_data[], emxArray_creal_T *y);

/* Function Definitions */
static void r2br_r2dit_trig_impl(const double x_data[], const int x_size[2],
  const double costab_data[], const double sintab_data[], emxArray_creal_T *y)
{
  int nRowsM1;
  int iy;
  int ix;
  int ju;
  int i;
  boolean_T tst;
  double temp_re;
  double temp_im;
  int istart;
  int temp_re_tmp;
  int j;
  double twid_re;
  double twid_im;
  int ihi;
  nRowsM1 = x_size[0];
  iy = y->size[0];
  y->size[0] = 4096;
  emxEnsureCapacity_creal_T(y, iy);
  for (iy = 0; iy < 4096; iy++) {
    y->data[iy].re = 0.0;
    y->data[iy].im = 0.0;
  }

  ix = 0;
  ju = 0;
  iy = 0;
  for (i = 0; i <= nRowsM1 - 2; i++) {
    y->data[iy].re = x_data[ix];
    y->data[iy].im = 0.0;
    iy = 4096;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }

    iy = ju;
    ix++;
  }

  y->data[iy].re = x_data[ix];
  y->data[iy].im = 0.0;
  for (i = 0; i <= 4094; i += 2) {
    temp_re = y->data[i + 1].re;
    temp_im = y->data[i + 1].im;
    y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
    y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
    y->data[i].re += temp_re;
    y->data[i].im += temp_im;
  }

  iy = 2;
  ix = 4;
  ju = 1024;
  nRowsM1 = 4093;
  while (ju > 0) {
    for (i = 0; i < nRowsM1; i += ix) {
      temp_re_tmp = i + iy;
      temp_re = y->data[temp_re_tmp].re;
      temp_im = y->data[temp_re_tmp].im;
      y->data[temp_re_tmp].re = y->data[i].re - temp_re;
      y->data[temp_re_tmp].im = y->data[i].im - temp_im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }

    istart = 1;
    for (j = ju; j < 2048; j += ju) {
      twid_re = costab_data[j];
      twid_im = sintab_data[j];
      i = istart;
      ihi = istart + nRowsM1;
      while (i < ihi) {
        temp_re_tmp = i + iy;
        temp_re = twid_re * y->data[temp_re_tmp].re - twid_im * y->
          data[temp_re_tmp].im;
        temp_im = twid_re * y->data[temp_re_tmp].im + twid_im * y->
          data[temp_re_tmp].re;
        y->data[temp_re_tmp].re = y->data[i].re - temp_re;
        y->data[temp_re_tmp].im = y->data[i].im - temp_im;
        y->data[i].re += temp_re;
        y->data[i].im += temp_im;
        i += ix;
      }

      istart++;
    }

    ju /= 2;
    iy = ix;
    ix += ix;
    nRowsM1 -= iy;
  }
}

void b_r2br_r2dit_trig(const double x_data[], const int x_size[2], const double
  costab_data[], const double sintab_data[], emxArray_creal_T *y)
{
  int k;
  emxArray_creal_T *rwork;
  int l;
  k = y->size[0] * y->size[1];
  y->size[0] = 4096;
  y->size[1] = 1;
  emxEnsureCapacity_creal_T(y, k);
  for (k = 0; k < 4096; k++) {
    y->data[k].re = 0.0;
    y->data[k].im = 0.0;
  }

#pragma omp parallel \
 num_threads(omp_get_max_threads()) \
 private(rwork,l)

  {
    emxInit_creal_T(&rwork, 1);

#pragma omp for nowait

    for (k = 0; k < 1; k++) {
      r2br_r2dit_trig_impl(x_data, x_size, costab_data, sintab_data, rwork);
      for (l = 0; l < 4096; l++) {
        y->data[l] = rwork->data[l];
      }
    }

    emxFree_creal_T(&rwork);
  }
}

void generate_twiddle_tables(double costab_data[], int costab_size[2], double
  sintab_data[], int sintab_size[2], int sintabinv_size[2])
{
  double costab1q_data[1025];
  int k;
  double costab_data_tmp;
  double sintab_data_tmp;
  costab1q_data[0] = 1.0;
  for (k = 0; k < 512; k++) {
    costab1q_data[1 + k] = cos(0.0015339807878856412 * (1.0 + (double)k));
  }

  for (k = 0; k < 511; k++) {
    costab1q_data[k + 513] = sin(0.0015339807878856412 * (1024.0 - ((double)k +
      513.0)));
  }

  costab1q_data[1024] = 0.0;
  costab_size[0] = 1;
  costab_size[1] = 2049;
  sintab_size[0] = 1;
  sintab_size[1] = 2049;
  costab_data[0] = 1.0;
  sintab_data[0] = 0.0;
  for (k = 0; k < 1024; k++) {
    costab_data_tmp = costab1q_data[1 + k];
    costab_data[1 + k] = costab_data_tmp;
    sintab_data_tmp = -costab1q_data[1023 - k];
    sintab_data[1 + k] = sintab_data_tmp;
    costab_data[k + 1025] = sintab_data_tmp;
    sintab_data[k + 1025] = -costab_data_tmp;
  }

  sintabinv_size[0] = 1;
  sintabinv_size[1] = 0;
}

void r2br_r2dit_trig(const double x_data[], const int x_size[1], const double
                     costab_data[], const double sintab_data[], emxArray_creal_T
                     *y)
{
  int nRowsM1;
  int iy;
  int ix;
  int ju;
  int i;
  boolean_T tst;
  double temp_re;
  double temp_im;
  int istart;
  int temp_re_tmp;
  int j;
  double twid_re;
  double twid_im;
  int ihi;
  nRowsM1 = x_size[0];
  iy = y->size[0];
  y->size[0] = 4096;
  emxEnsureCapacity_creal_T(y, iy);
  for (iy = 0; iy < 4096; iy++) {
    y->data[iy].re = 0.0;
    y->data[iy].im = 0.0;
  }

  ix = 0;
  ju = 0;
  iy = 0;
  for (i = 0; i <= nRowsM1 - 2; i++) {
    y->data[iy].re = x_data[ix];
    y->data[iy].im = 0.0;
    iy = 4096;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }

    iy = ju;
    ix++;
  }

  y->data[iy].re = x_data[ix];
  y->data[iy].im = 0.0;
  for (i = 0; i <= 4094; i += 2) {
    temp_re = y->data[i + 1].re;
    temp_im = y->data[i + 1].im;
    y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
    y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
    y->data[i].re += temp_re;
    y->data[i].im += temp_im;
  }

  iy = 2;
  ix = 4;
  ju = 1024;
  nRowsM1 = 4093;
  while (ju > 0) {
    for (i = 0; i < nRowsM1; i += ix) {
      temp_re_tmp = i + iy;
      temp_re = y->data[temp_re_tmp].re;
      temp_im = y->data[temp_re_tmp].im;
      y->data[temp_re_tmp].re = y->data[i].re - temp_re;
      y->data[temp_re_tmp].im = y->data[i].im - temp_im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }

    istart = 1;
    for (j = ju; j < 2048; j += ju) {
      twid_re = costab_data[j];
      twid_im = sintab_data[j];
      i = istart;
      ihi = istart + nRowsM1;
      while (i < ihi) {
        temp_re_tmp = i + iy;
        temp_re = twid_re * y->data[temp_re_tmp].re - twid_im * y->
          data[temp_re_tmp].im;
        temp_im = twid_re * y->data[temp_re_tmp].im + twid_im * y->
          data[temp_re_tmp].re;
        y->data[temp_re_tmp].re = y->data[i].re - temp_re;
        y->data[temp_re_tmp].im = y->data[i].im - temp_im;
        y->data[i].re += temp_re;
        y->data[i].im += temp_im;
        i += ix;
      }

      istart++;
    }

    ju /= 2;
    iy = ix;
    ix += ix;
    nRowsM1 -= iy;
  }
}

/* End of code generation (fft1.c) */

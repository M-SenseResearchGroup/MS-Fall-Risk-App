/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeperiodogram.c
 *
 * Code generation for function 'computeperiodogram'
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
#include "computeperiodogram.h"
#include "getFallClass_emxutil.h"
#include "sum.h"
#include "any.h"
#include "strcmp.h"
#include "psdfreqvec.h"
#include "fft.h"
#include "bsxfun.h"

/* Function Declarations */
static void validateinputs(const double x_data[], const int x_size[2], double
  x1_data[], int x1_size[2], double *Lx);

/* Function Definitions */
static void validateinputs(const double x_data[], const int x_size[2], double
  x1_data[], int x1_size[2], double *Lx)
{
  int loop_ub;
  x1_size[0] = x_size[0];
  x1_size[1] = 1;
  loop_ub = x_size[0] * x_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&x1_data[0], &x_data[0], (unsigned int)(loop_ub * (int)sizeof(double)));
  }

  *Lx = x_size[0];
}

void b_computeperiodogram(const double x_data[], const int x_size[2], const
  double win[125], const char esttype_data[], const int esttype_size[2], double
  Fs, emxArray_creal_T *Pxx, double F_data[], int F_size[1])
{
  double x1_data[125];
  int x1_size[2];
  double unusedU0;
  double tmp_data[125];
  int tmp_size[2];
  boolean_T bv3[2];
  int i24;
  double Pxx_re;
  double Pxx_im;
  double b_Pxx_re;
  if (rtIsNaN(Fs)) {
    Fs = 6.2831853071795862;
  }

  validateinputs(x_data, x_size, x1_data, x1_size, &unusedU0);
  b_bsxfun(x1_data, x1_size, tmp_data, tmp_size);
  b_fft(tmp_data, tmp_size, Pxx);
  psdfreqvec(Fs, F_data, F_size);
  b_strcmp(esttype_data, esttype_size, bv3);
  if (any(bv3)) {
    unusedU0 = sum(win);
    unusedU0 *= unusedU0;
  } else {
    unusedU0 = 0.0;
    for (i24 = 0; i24 < 125; i24++) {
      unusedU0 += win[i24] * win[i24];
    }
  }

  i24 = Pxx->size[0] * Pxx->size[1];
  Pxx->size[0] = 4096;
  Pxx->size[1] = 1;
  emxEnsureCapacity_creal_T(Pxx, i24);
  for (i24 = 0; i24 < 4096; i24++) {
    Pxx_re = Pxx->data[i24].re;
    Pxx_im = -Pxx->data[i24].im;
    b_Pxx_re = Pxx->data[i24].re * Pxx_re - Pxx->data[i24].im * Pxx_im;
    Pxx_im = Pxx->data[i24].re * Pxx_im + Pxx->data[i24].im * Pxx_re;
    if (Pxx_im == 0.0) {
      Pxx->data[i24].re = b_Pxx_re / unusedU0;
      Pxx->data[i24].im = 0.0;
    } else if (b_Pxx_re == 0.0) {
      Pxx->data[i24].re = 0.0;
      Pxx->data[i24].im = Pxx_im / unusedU0;
    } else {
      Pxx->data[i24].re = b_Pxx_re / unusedU0;
      Pxx->data[i24].im = Pxx_im / unusedU0;
    }
  }
}

void c_computeperiodogram(const double x_data[], const int x_size[1], const
  double win[63], const char esttype_data[], const int esttype_size[2], double
  Fs, emxArray_creal_T *Pxx, double F_data[], int F_size[1])
{
  double dv9[63];
  static int iv2[1] = { 63 };

  boolean_T bv4[2];
  double b_win;
  int i39;
  double Pxx_re;
  double Pxx_im;
  double b_Pxx_re;
  if (rtIsNaN(Fs)) {
    Fs = 6.2831853071795862;
  }

  c_bsxfun(x_data, x_size, dv9);
  fft(dv9, iv2, Pxx);
  psdfreqvec(Fs, F_data, F_size);
  b_strcmp(esttype_data, esttype_size, bv4);
  if (any(bv4)) {
    b_win = b_sum();
    b_win *= b_win;
  } else {
    b_win = 0.0;
    for (i39 = 0; i39 < 63; i39++) {
      b_win += win[i39] * win[i39];
    }
  }

  i39 = Pxx->size[0];
  Pxx->size[0] = 4096;
  emxEnsureCapacity_creal_T(Pxx, i39);
  for (i39 = 0; i39 < 4096; i39++) {
    Pxx_re = Pxx->data[i39].re;
    Pxx_im = -Pxx->data[i39].im;
    b_Pxx_re = Pxx->data[i39].re * Pxx_re - Pxx->data[i39].im * Pxx_im;
    Pxx_im = Pxx->data[i39].re * Pxx_im + Pxx->data[i39].im * Pxx_re;
    if (Pxx_im == 0.0) {
      Pxx->data[i39].re = b_Pxx_re / b_win;
      Pxx->data[i39].im = 0.0;
    } else if (b_Pxx_re == 0.0) {
      Pxx->data[i39].re = 0.0;
      Pxx->data[i39].im = Pxx_im / b_win;
    } else {
      Pxx->data[i39].re = b_Pxx_re / b_win;
      Pxx->data[i39].im = Pxx_im / b_win;
    }
  }
}

void computeperiodogram(const double x_data[], const int x_size[1], const double
  win[125], const char esttype_data[], const int esttype_size[2], double Fs,
  emxArray_creal_T *Pxx, double F_data[], int F_size[1])
{
  double dv8[125];
  static int iv1[1] = { 125 };

  boolean_T bv0[2];
  double b_win;
  int i14;
  double Pxx_re;
  double Pxx_im;
  double b_Pxx_re;
  if (rtIsNaN(Fs)) {
    Fs = 6.2831853071795862;
  }

  bsxfun(x_data, x_size, dv8);
  fft(dv8, iv1, Pxx);
  psdfreqvec(Fs, F_data, F_size);
  b_strcmp(esttype_data, esttype_size, bv0);
  if (any(bv0)) {
    b_win = sum(win);
    b_win *= b_win;
  } else {
    b_win = 0.0;
    for (i14 = 0; i14 < 125; i14++) {
      b_win += win[i14] * win[i14];
    }
  }

  i14 = Pxx->size[0];
  Pxx->size[0] = 4096;
  emxEnsureCapacity_creal_T(Pxx, i14);
  for (i14 = 0; i14 < 4096; i14++) {
    Pxx_re = Pxx->data[i14].re;
    Pxx_im = -Pxx->data[i14].im;
    b_Pxx_re = Pxx->data[i14].re * Pxx_re - Pxx->data[i14].im * Pxx_im;
    Pxx_im = Pxx->data[i14].re * Pxx_im + Pxx->data[i14].im * Pxx_re;
    if (Pxx_im == 0.0) {
      Pxx->data[i14].re = b_Pxx_re / b_win;
      Pxx->data[i14].im = 0.0;
    } else if (b_Pxx_re == 0.0) {
      Pxx->data[i14].re = 0.0;
      Pxx->data[i14].im = Pxx_im / b_win;
    } else {
      Pxx->data[i14].re = b_Pxx_re / b_win;
      Pxx->data[i14].im = Pxx_im / b_win;
    }
  }
}

void d_computeperiodogram(const double x_data[], const int x_size[2], const
  double win[63], const char esttype_data[], const int esttype_size[2], double
  Fs, emxArray_creal_T *Pxx, double F_data[], int F_size[1])
{
  double x1_data[500];
  int x1_size[2];
  double unusedU0;
  double tmp_data[63];
  int tmp_size[2];
  boolean_T bv5[2];
  int i44;
  double Pxx_re;
  double Pxx_im;
  double b_Pxx_re;
  if (rtIsNaN(Fs)) {
    Fs = 6.2831853071795862;
  }

  validateinputs(x_data, x_size, x1_data, x1_size, &unusedU0);
  d_bsxfun(x1_data, x1_size, tmp_data, tmp_size);
  b_fft(tmp_data, tmp_size, Pxx);
  psdfreqvec(Fs, F_data, F_size);
  b_strcmp(esttype_data, esttype_size, bv5);
  if (any(bv5)) {
    unusedU0 = b_sum();
    unusedU0 *= unusedU0;
  } else {
    unusedU0 = 0.0;
    for (i44 = 0; i44 < 63; i44++) {
      unusedU0 += win[i44] * win[i44];
    }
  }

  i44 = Pxx->size[0] * Pxx->size[1];
  Pxx->size[0] = 4096;
  Pxx->size[1] = 1;
  emxEnsureCapacity_creal_T(Pxx, i44);
  for (i44 = 0; i44 < 4096; i44++) {
    Pxx_re = Pxx->data[i44].re;
    Pxx_im = -Pxx->data[i44].im;
    b_Pxx_re = Pxx->data[i44].re * Pxx_re - Pxx->data[i44].im * Pxx_im;
    Pxx_im = Pxx->data[i44].re * Pxx_im + Pxx->data[i44].im * Pxx_re;
    if (Pxx_im == 0.0) {
      Pxx->data[i44].re = b_Pxx_re / unusedU0;
      Pxx->data[i44].im = 0.0;
    } else if (b_Pxx_re == 0.0) {
      Pxx->data[i44].re = 0.0;
      Pxx->data[i44].im = Pxx_im / unusedU0;
    } else {
      Pxx->data[i44].re = b_Pxx_re / unusedU0;
      Pxx->data[i44].im = Pxx_im / unusedU0;
    }
  }
}

/* End of code generation (computeperiodogram.c) */

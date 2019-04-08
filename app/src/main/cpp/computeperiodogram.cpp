/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeperiodogram.cpp
 *
 * Code generation for function 'computeperiodogram'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "computeperiodogram.h"
#include "calc_fall_risk_emxutil.h"
#include "strcmp.h"
#include "psdfreqvec.h"
#include "fft.h"
#include "bsxfun.h"
#include "sum.h"
#include "any1.h"
#include "computeDFT.h"

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
    memcpy(&x1_data[0], &x_data[0], (unsigned int)(loop_ub * static_cast<int>
            (sizeof(double))));
  }

  *Lx = x_size[0];
}

void b_computeperiodogram(const double x_data[], const int x_size[2], const
  double win_data[], const char esttype_data[], const int esttype_size[2],
  double Fs, emxArray_creal_T *Pxx, double F_data[], int F_size[1])
{
  double x1_data[313];
  int x1_size[2];
  double unusedU0;
  double tmp_data[125];
  int tmp_size[2];
  boolean_T bv3[2];
  int i33;
  double Pxx_re;
  double Pxx_im;
  double b_Pxx_re;
  if (rtIsNaN(Fs)) {
    Fs = 6.2831853071795862;
  }

  validateinputs(x_data, x_size, x1_data, x1_size, &unusedU0);
  d_bsxfun(x1_data, x1_size, tmp_data, tmp_size);
  b_computeDFT(tmp_data, tmp_size, Fs, Pxx, F_data, F_size);
  b_strcmp(esttype_data, esttype_size, bv3);
  if (any(bv3)) {
    unusedU0 = b_sum(win_data);
    unusedU0 *= unusedU0;
  } else {
    unusedU0 = 0.0;
    for (i33 = 0; i33 < 125; i33++) {
      unusedU0 += win_data[i33] * win_data[i33];
    }
  }

  i33 = Pxx->size[0] * Pxx->size[1];
  Pxx->size[0] = 4096;
  Pxx->size[1] = 1;
  emxEnsureCapacity_creal_T(Pxx, i33);
  for (i33 = 0; i33 < 4096; i33++) {
    Pxx_re = Pxx->data[i33].re;
    Pxx_im = -Pxx->data[i33].im;
    b_Pxx_re = Pxx->data[i33].re * Pxx_re - Pxx->data[i33].im * Pxx_im;
    Pxx_im = Pxx->data[i33].re * Pxx_im + Pxx->data[i33].im * Pxx_re;
    if (Pxx_im == 0.0) {
      Pxx->data[i33].re = b_Pxx_re / unusedU0;
      Pxx->data[i33].im = 0.0;
    } else if (b_Pxx_re == 0.0) {
      Pxx->data[i33].re = 0.0;
      Pxx->data[i33].im = Pxx_im / unusedU0;
    } else {
      Pxx->data[i33].re = b_Pxx_re / unusedU0;
      Pxx->data[i33].im = Pxx_im / unusedU0;
    }
  }
}

void c_computeperiodogram(const emxArray_real_T *x, const double win[63], const
  char esttype_data[], const int esttype_size[2], double Fs, emxArray_creal_T
  *Pxx, double F_data[], int F_size[1])
{
  double dv9[63];
  static int iv0[1] = { 63 };

  boolean_T b_x[2];
  boolean_T y;
  int k;
  boolean_T exitg1;
  double b_win;
  double Pxx_re;
  double Pxx_im;
  double b_Pxx_re;
  if (rtIsNaN(Fs)) {
    Fs = 6.2831853071795862;
  }

  g_bsxfun(x, dv9);
  fft(dv9, iv0, Pxx);
  psdfreqvec(Fs, F_data, F_size);
  b_strcmp(esttype_data, esttype_size, b_x);
  y = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (b_x[k]) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (y) {
    b_win = 1.0;
    for (k = 0; k < 62; k++) {
      b_win++;
    }

    b_win *= b_win;
  } else {
    b_win = 0.0;
    for (k = 0; k < 63; k++) {
      b_win += win[k] * win[k];
    }
  }

  k = Pxx->size[0];
  Pxx->size[0] = 4096;
  emxEnsureCapacity_creal_T(Pxx, k);
  for (k = 0; k < 4096; k++) {
    Pxx_re = Pxx->data[k].re;
    Pxx_im = -Pxx->data[k].im;
    b_Pxx_re = Pxx->data[k].re * Pxx_re - Pxx->data[k].im * Pxx_im;
    Pxx_im = Pxx->data[k].re * Pxx_im + Pxx->data[k].im * Pxx_re;
    if (Pxx_im == 0.0) {
      Pxx->data[k].re = b_Pxx_re / b_win;
      Pxx->data[k].im = 0.0;
    } else if (b_Pxx_re == 0.0) {
      Pxx->data[k].re = 0.0;
      Pxx->data[k].im = Pxx_im / b_win;
    } else {
      Pxx->data[k].re = b_Pxx_re / b_win;
      Pxx->data[k].im = Pxx_im / b_win;
    }
  }
}

void computeperiodogram(const double x_data[], const int x_size[1], const double
  win_data[], const char esttype_data[], const int esttype_size[2], double Fs,
  emxArray_creal_T *Pxx, double F_data[], int F_size[1])
{
  double tmp_data[125];
  int tmp_size[1];
  boolean_T bv0[2];
  double win;
  int i17;
  double Pxx_re;
  double Pxx_im;
  double b_Pxx_re;
  if (rtIsNaN(Fs)) {
    Fs = 6.2831853071795862;
  }

  c_bsxfun(x_data, x_size, tmp_data, tmp_size);
  computeDFT(tmp_data, tmp_size, Fs, Pxx, F_data, F_size);
  b_strcmp(esttype_data, esttype_size, bv0);
  if (any(bv0)) {
    win = b_sum(win_data);
    win *= win;
  } else {
    win = 0.0;
    for (i17 = 0; i17 < 125; i17++) {
      win += win_data[i17] * win_data[i17];
    }
  }

  i17 = Pxx->size[0];
  Pxx->size[0] = 4096;
  emxEnsureCapacity_creal_T(Pxx, i17);
  for (i17 = 0; i17 < 4096; i17++) {
    Pxx_re = Pxx->data[i17].re;
    Pxx_im = -Pxx->data[i17].im;
    b_Pxx_re = Pxx->data[i17].re * Pxx_re - Pxx->data[i17].im * Pxx_im;
    Pxx_im = Pxx->data[i17].re * Pxx_im + Pxx->data[i17].im * Pxx_re;
    if (Pxx_im == 0.0) {
      Pxx->data[i17].re = b_Pxx_re / win;
      Pxx->data[i17].im = 0.0;
    } else if (b_Pxx_re == 0.0) {
      Pxx->data[i17].re = 0.0;
      Pxx->data[i17].im = Pxx_im / win;
    } else {
      Pxx->data[i17].re = b_Pxx_re / win;
      Pxx->data[i17].im = Pxx_im / win;
    }
  }
}

/* End of code generation (computeperiodogram.cpp) */

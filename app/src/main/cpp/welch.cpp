/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * welch.cpp
 *
 * Code generation for function 'welch'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include <cmath>
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "welch.h"
#include "calc_fall_risk_emxutil.h"
#include "computepsd.h"
#include "psdfreqvec.h"
#include "computeperiodogram.h"
#include "fft.h"
#include "strcmp.h"
#include "welchparse.h"
#include "fix.h"

/* Function Declarations */
static void b_localComputeSpectra(const double x_data[], const emxArray_real_T
  *xStart, const emxArray_real_T *xEnd, const double win_data[], double
  options_Fs, const char options_range[8], const char esttype_data[], const int
  esttype_size[2], double k, const double cmethod_tunableEnvironment[1], double
  Pxx_data[], int Pxx_size[2], double w_data[], int w_size[1], char units_data[],
  int units_size[2]);
static void c_localComputeSpectra(const double Sxx_data[], const double x_data[],
  const emxArray_real_T *xStart, const emxArray_real_T *xEnd, const double
  win_data[], double options_Fs, const char options_range[8], const char
  esttype_data[], const int esttype_size[2], double k, emxArray_creal_T *Pxx,
  double w_data[], int w_size[1], char units_data[], int units_size[2]);
static void d_localComputeSpectra(const double Sxx_data[], const double x_data[],
  const emxArray_real_T *xStart, const emxArray_real_T *xEnd, const double
  win_data[], double options_Fs, const char options_range[8], const char
  esttype_data[], const int esttype_size[2], double k, emxArray_creal_T *Pxx,
  double w_data[], int w_size[1], char units_data[], int units_size[2]);
static void e_localComputeSpectra(const emxArray_real_T *x, const
  emxArray_real_T *xStart, const emxArray_real_T *xEnd, const double win[63],
  double options_Fs, const char options_range[8], const char esttype_data[],
  const int esttype_size[2], double k, const double cmethod_tunableEnvironment[1],
  double Pxx_data[], int Pxx_size[2], double w_data[], int w_size[1], char
  units_data[], int units_size[2]);
static void f_localComputeSpectra(const emxArray_real_T *x, const
  emxArray_real_T *xStart, const emxArray_real_T *xEnd, const double win[63],
  double options_Fs, const char options_range[8], const char esttype_data[],
  const int esttype_size[2], double k, const double cmethod_tunableEnvironment[1],
  double Pxx_data[], int Pxx_size[2], double w_data[], int w_size[1], char
  units_data[], int units_size[2]);
static void g_localComputeSpectra(const double Sxx_data[], const emxArray_real_T
  *x, const emxArray_real_T *xStart, const emxArray_real_T *xEnd, const double
  win[63], double options_Fs, const char options_range[8], const char
  esttype_data[], const int esttype_size[2], double k, emxArray_creal_T *Pxx,
  double w_data[], int w_size[1], char units_data[], int units_size[2]);
static void h_localComputeSpectra(const double Sxx_data[], const emxArray_real_T
  *x, const emxArray_real_T *xStart, const emxArray_real_T *xEnd, const double
  win[63], double options_Fs, const char options_range[8], const char
  esttype_data[], const int esttype_size[2], double k, emxArray_creal_T *Pxx,
  double w_data[], int w_size[1], char units_data[], int units_size[2]);
static void localComputeSpectra(const double x_data[], const emxArray_real_T
  *xStart, const emxArray_real_T *xEnd, const double win_data[], double
  options_Fs, const char options_range[8], const char esttype_data[], const int
  esttype_size[2], double k, const double cmethod_tunableEnvironment[1], double
  Pxx_data[], int Pxx_size[2], double w_data[], int w_size[1], char units_data[],
  int units_size[2]);

/* Function Definitions */
static void b_localComputeSpectra(const double x_data[], const emxArray_real_T
  *xStart, const emxArray_real_T *xEnd, const double win_data[], double
  options_Fs, const char options_range[8], const char esttype_data[], const int
  esttype_size[2], double k, const double cmethod_tunableEnvironment[1], double
  Pxx_data[], int Pxx_size[2], double w_data[], int w_size[1], char units_data[],
  int units_size[2])
{
  int Sxx1_size[2];
  int i24;
  emxArray_creal_T *Sxxk;
  int ii;
  int nx;
  int b_k;
  static double b_w_data[4096];
  static double Sxx1_data[4096];
  int x_size_tmp;
  int w[2];
  int x_size[1];
  double b_x_data[313];
  short i25;
  static double varargin_2_data[4096];
  Sxx1_size[0] = 0;
  Sxx1_size[1] = 0;
  i24 = static_cast<int>(k);
  emxInit_creal_T(&Sxxk, 1);
  for (ii = 0; ii < i24; ii++) {
    if (xStart->data[ii] > xEnd->data[ii]) {
      nx = 1;
      b_k = 0;
    } else {
      nx = static_cast<int>(xStart->data[ii]);
      b_k = static_cast<int>(xEnd->data[ii]);
    }

    x_size_tmp = b_k - nx;
    x_size[0] = x_size_tmp + 1;
    for (b_k = 0; b_k <= x_size_tmp; b_k++) {
      b_x_data[b_k] = x_data[(nx + b_k) - 1];
    }

    computeperiodogram(b_x_data, x_size, win_data, esttype_data, esttype_size,
                       options_Fs, Sxxk, b_w_data, w_size);
    if (1U + ii == 1U) {
      for (nx = 0; nx < 4096; nx++) {
        varargin_2_data[nx] = cmethod_tunableEnvironment[0] * Sxxk->data[nx].re;
      }

      Sxx1_size[0] = 4096;
      Sxx1_size[1] = 1;
      for (b_k = 0; b_k < 4096; b_k++) {
        if (rtIsNaN(varargin_2_data[b_k])) {
          Sxx1_data[b_k] = rtInf;
        } else {
          Sxx1_data[b_k] = varargin_2_data[b_k];
        }
      }
    } else {
      for (nx = 0; nx < 4096; nx++) {
        varargin_2_data[nx] = cmethod_tunableEnvironment[0] * Sxxk->data[nx].re;
      }

      i25 = static_cast<short>(Sxx1_size[0]);
      w_size[0] = Sxx1_size[0];
      nx = Sxx1_size[0];
      for (b_k = 0; b_k < nx; b_k++) {
        if ((Sxx1_data[b_k] < varargin_2_data[b_k]) || rtIsNaN
            (varargin_2_data[b_k])) {
          b_w_data[b_k] = Sxx1_data[b_k];
        } else {
          b_w_data[b_k] = varargin_2_data[b_k];
        }
      }

      Sxx1_size[0] = i25;
      Sxx1_size[1] = 1;
      if (0 <= i25 - 1) {
        memcpy(&Sxx1_data[0], &b_w_data[0], (unsigned int)(i25 * static_cast<int>
                (sizeof(double))));
      }
    }
  }

  emxFree_creal_T(&Sxxk);
  nx = Sxx1_size[0] * Sxx1_size[1] - 1;
  for (i24 = 0; i24 <= nx; i24++) {
    Sxx1_data[i24] /= k;
  }

  psdfreqvec(options_Fs, b_w_data, w_size);
  w[0] = w_size[0];
  w[1] = 1;
  computepsd(Sxx1_data, Sxx1_size, b_w_data, w, options_range, options_Fs,
             esttype_data, esttype_size, Pxx_data, Pxx_size, w_data, w_size,
             units_data, units_size);
}

static void c_localComputeSpectra(const double Sxx_data[], const double x_data[],
  const emxArray_real_T *xStart, const emxArray_real_T *xEnd, const double
  win_data[], double options_Fs, const char options_range[8], const char
  esttype_data[], const int esttype_size[2], double k, emxArray_creal_T *Pxx,
  double w_data[], int w_size[1], char units_data[], int units_size[2])
{
  emxArray_creal_T *Sxx1;
  int i26;
  emxArray_creal_T *Sxxk;
  int ii;
  int i27;
  int loop_ub;
  int x_size_tmp;
  int x_size[1];
  static double b_w_data[4096];
  int b_w_size[1];
  double Sxx1_re;
  int w[2];
  double Sxx1_im;
  double b_x_data[313];
  emxInit_creal_T(&Sxx1, 2);
  Sxx1->size[0] = 0;
  Sxx1->size[1] = 0;
  i26 = static_cast<int>(k);
  emxInit_creal_T(&Sxxk, 1);
  for (ii = 0; ii < i26; ii++) {
    if (xStart->data[ii] > xEnd->data[ii]) {
      i27 = 1;
      loop_ub = 0;
    } else {
      i27 = static_cast<int>(xStart->data[ii]);
      loop_ub = static_cast<int>(xEnd->data[ii]);
    }

    x_size_tmp = loop_ub - i27;
    x_size[0] = x_size_tmp + 1;
    for (loop_ub = 0; loop_ub <= x_size_tmp; loop_ub++) {
      b_x_data[loop_ub] = x_data[(i27 + loop_ub) - 1];
    }

    computeperiodogram(b_x_data, x_size, win_data, esttype_data, esttype_size,
                       options_Fs, Sxxk, b_w_data, b_w_size);
    if (1U + ii == 1U) {
      i27 = Sxx1->size[0] * Sxx1->size[1];
      Sxx1->size[0] = 4096;
      Sxx1->size[1] = 1;
      emxEnsureCapacity_creal_T(Sxx1, i27);
      for (i27 = 0; i27 < 4096; i27++) {
        Sxx1->data[i27].re = Sxx_data[i27] + Sxxk->data[i27].re;
        Sxx1->data[i27].im = Sxxk->data[i27].im;
      }
    } else {
      loop_ub = Sxx1->size[0];
      x_size_tmp = Sxx1->size[0];
      i27 = Sxxk->size[0];
      Sxxk->size[0] = loop_ub;
      emxEnsureCapacity_creal_T(Sxxk, i27);
      for (i27 = 0; i27 < loop_ub; i27++) {
        Sxxk->data[i27].re += Sxx1->data[i27].re;
        Sxxk->data[i27].im += Sxx1->data[i27].im;
      }

      i27 = Sxx1->size[0] * Sxx1->size[1];
      Sxx1->size[0] = x_size_tmp;
      Sxx1->size[1] = 1;
      emxEnsureCapacity_creal_T(Sxx1, i27);
      for (i27 = 0; i27 < x_size_tmp; i27++) {
        Sxx1->data[i27] = Sxxk->data[i27];
      }
    }
  }

  emxFree_creal_T(&Sxxk);
  i26 = Sxx1->size[0] * Sxx1->size[1];
  i27 = Sxx1->size[0] * Sxx1->size[1];
  emxEnsureCapacity_creal_T(Sxx1, i27);
  loop_ub = i26 - 1;
  for (i26 = 0; i26 <= loop_ub; i26++) {
    Sxx1_re = Sxx1->data[i26].re;
    Sxx1_im = Sxx1->data[i26].im;
    if (Sxx1_im == 0.0) {
      Sxx1->data[i26].re = Sxx1_re / k;
      Sxx1->data[i26].im = 0.0;
    } else if (Sxx1_re == 0.0) {
      Sxx1->data[i26].re = 0.0;
      Sxx1->data[i26].im = Sxx1_im / k;
    } else {
      Sxx1->data[i26].re = Sxx1_re / k;
      Sxx1->data[i26].im = Sxx1_im / k;
    }
  }

  psdfreqvec(options_Fs, b_w_data, b_w_size);
  w[0] = b_w_size[0];
  w[1] = 1;
  b_computepsd(Sxx1, b_w_data, w, options_range, options_Fs, esttype_data,
               esttype_size, Pxx, w_data, w_size, units_data, units_size);
  emxFree_creal_T(&Sxx1);
}

static void d_localComputeSpectra(const double Sxx_data[], const double x_data[],
  const emxArray_real_T *xStart, const emxArray_real_T *xEnd, const double
  win_data[], double options_Fs, const char options_range[8], const char
  esttype_data[], const int esttype_size[2], double k, emxArray_creal_T *Pxx,
  double w_data[], int w_size[1], char units_data[], int units_size[2])
{
  emxArray_creal_T *Sxx1;
  int i31;
  emxArray_creal_T *Sxxk;
  int ii;
  int i32;
  int loop_ub;
  int x_size_tmp;
  int x_size[2];
  static double b_w_data[4096];
  int b_w_size[1];
  double Sxx1_re;
  double Sxx1_im;
  double b_x_data[313];
  emxInit_creal_T(&Sxx1, 2);
  Sxx1->size[0] = 0;
  Sxx1->size[1] = 0;
  i31 = static_cast<int>(k);
  emxInit_creal_T(&Sxxk, 2);
  for (ii = 0; ii < i31; ii++) {
    if (xStart->data[ii] > xEnd->data[ii]) {
      i32 = 1;
      loop_ub = 0;
    } else {
      i32 = static_cast<int>(xStart->data[ii]);
      loop_ub = static_cast<int>(xEnd->data[ii]);
    }

    x_size_tmp = loop_ub - i32;
    x_size[0] = x_size_tmp + 1;
    x_size[1] = 1;
    for (loop_ub = 0; loop_ub <= x_size_tmp; loop_ub++) {
      b_x_data[loop_ub] = x_data[(i32 + loop_ub) - 1];
    }

    b_computeperiodogram(b_x_data, x_size, win_data, esttype_data, esttype_size,
                         options_Fs, Sxxk, b_w_data, b_w_size);
    if (1U + ii == 1U) {
      i32 = Sxx1->size[0] * Sxx1->size[1];
      Sxx1->size[0] = 4096;
      Sxx1->size[1] = 1;
      emxEnsureCapacity_creal_T(Sxx1, i32);
      for (i32 = 0; i32 < 4096; i32++) {
        Sxx1->data[i32].re = Sxx_data[i32] + Sxxk->data[i32].re;
        Sxx1->data[i32].im = Sxxk->data[i32].im;
      }
    } else {
      i32 = Sxx1->size[0] * Sxx1->size[1];
      loop_ub = Sxx1->size[0] * Sxx1->size[1];
      emxEnsureCapacity_creal_T(Sxx1, loop_ub);
      loop_ub = i32 - 1;
      for (i32 = 0; i32 <= loop_ub; i32++) {
        Sxx1->data[i32].re += Sxxk->data[i32].re;
        Sxx1->data[i32].im += Sxxk->data[i32].im;
      }
    }
  }

  emxFree_creal_T(&Sxxk);
  i31 = Sxx1->size[0] * Sxx1->size[1];
  i32 = Sxx1->size[0] * Sxx1->size[1];
  emxEnsureCapacity_creal_T(Sxx1, i32);
  loop_ub = i31 - 1;
  for (i31 = 0; i31 <= loop_ub; i31++) {
    Sxx1_re = Sxx1->data[i31].re;
    Sxx1_im = Sxx1->data[i31].im;
    if (Sxx1_im == 0.0) {
      Sxx1->data[i31].re = Sxx1_re / k;
      Sxx1->data[i31].im = 0.0;
    } else if (Sxx1_re == 0.0) {
      Sxx1->data[i31].re = 0.0;
      Sxx1->data[i31].im = Sxx1_im / k;
    } else {
      Sxx1->data[i31].re = Sxx1_re / k;
      Sxx1->data[i31].im = Sxx1_im / k;
    }
  }

  psdfreqvec(options_Fs, b_w_data, b_w_size);
  x_size[0] = b_w_size[0];
  x_size[1] = 1;
  b_computepsd(Sxx1, b_w_data, x_size, options_range, options_Fs, esttype_data,
               esttype_size, Pxx, w_data, w_size, units_data, units_size);
  emxFree_creal_T(&Sxx1);
}

static void e_localComputeSpectra(const emxArray_real_T *x, const
  emxArray_real_T *xStart, const emxArray_real_T *xEnd, const double win[63],
  double options_Fs, const char options_range[8], const char esttype_data[],
  const int esttype_size[2], double k, const double cmethod_tunableEnvironment[1],
  double Pxx_data[], int Pxx_size[2], double w_data[], int w_size[1], char
  units_data[], int units_size[2])
{
  int Sxx1_size[2];
  int i81;
  emxArray_creal_T *Sxxk;
  emxArray_real_T *b_x;
  int ii;
  int nx;
  int loop_ub;
  int b_k;
  int i82;
  static double b_w_data[4096];
  double Sxx1_data[4096];
  int w[2];
  short i83;
  double varargin_2_data[4096];
  Sxx1_size[0] = 0;
  Sxx1_size[1] = 0;
  i81 = static_cast<int>(k);
  emxInit_creal_T(&Sxxk, 1);
  emxInit_real_T(&b_x, 1);
  for (ii = 0; ii < i81; ii++) {
    if (xStart->data[ii] > xEnd->data[ii]) {
      nx = 1;
      b_k = 0;
    } else {
      nx = static_cast<int>(xStart->data[ii]);
      b_k = static_cast<int>(xEnd->data[ii]);
    }

    i82 = b_x->size[0];
    loop_ub = b_k - nx;
    b_x->size[0] = loop_ub + 1;
    emxEnsureCapacity_real_T(b_x, i82);
    for (b_k = 0; b_k <= loop_ub; b_k++) {
      b_x->data[b_k] = x->data[(nx + b_k) - 1];
    }

    c_computeperiodogram(b_x, win, esttype_data, esttype_size, options_Fs, Sxxk,
                         b_w_data, w_size);
    if (1U + ii == 1U) {
      for (nx = 0; nx < 4096; nx++) {
        varargin_2_data[nx] = cmethod_tunableEnvironment[0] * Sxxk->data[nx].re;
      }

      Sxx1_size[0] = 4096;
      Sxx1_size[1] = 1;
      for (b_k = 0; b_k < 4096; b_k++) {
        if (rtIsNaN(varargin_2_data[b_k])) {
          Sxx1_data[b_k] = rtMinusInf;
        } else {
          Sxx1_data[b_k] = varargin_2_data[b_k];
        }
      }
    } else {
      for (nx = 0; nx < 4096; nx++) {
        varargin_2_data[nx] = cmethod_tunableEnvironment[0] * Sxxk->data[nx].re;
      }

      i83 = static_cast<short>(Sxx1_size[0]);
      w_size[0] = Sxx1_size[0];
      nx = Sxx1_size[0];
      for (b_k = 0; b_k < nx; b_k++) {
        if ((Sxx1_data[b_k] > varargin_2_data[b_k]) || rtIsNaN
            (varargin_2_data[b_k])) {
          b_w_data[b_k] = Sxx1_data[b_k];
        } else {
          b_w_data[b_k] = varargin_2_data[b_k];
        }
      }

      Sxx1_size[0] = i83;
      Sxx1_size[1] = 1;
      if (0 <= i83 - 1) {
        memcpy(&Sxx1_data[0], &b_w_data[0], (unsigned int)(i83 * static_cast<int>
                (sizeof(double))));
      }
    }
  }

  emxFree_real_T(&b_x);
  emxFree_creal_T(&Sxxk);
  loop_ub = Sxx1_size[0] * Sxx1_size[1] - 1;
  for (i81 = 0; i81 <= loop_ub; i81++) {
    Sxx1_data[i81] /= k;
  }

  psdfreqvec(options_Fs, b_w_data, w_size);
  w[0] = w_size[0];
  w[1] = 1;
  computepsd(Sxx1_data, Sxx1_size, b_w_data, w, options_range, options_Fs,
             esttype_data, esttype_size, Pxx_data, Pxx_size, w_data, w_size,
             units_data, units_size);
}

static void f_localComputeSpectra(const emxArray_real_T *x, const
  emxArray_real_T *xStart, const emxArray_real_T *xEnd, const double win[63],
  double options_Fs, const char options_range[8], const char esttype_data[],
  const int esttype_size[2], double k, const double cmethod_tunableEnvironment[1],
  double Pxx_data[], int Pxx_size[2], double w_data[], int w_size[1], char
  units_data[], int units_size[2])
{
  int Sxx1_size[2];
  int i84;
  emxArray_creal_T *Sxxk;
  emxArray_real_T *b_x;
  int ii;
  int nx;
  int loop_ub;
  int b_k;
  int i85;
  static double b_w_data[4096];
  double Sxx1_data[4096];
  int w[2];
  short i86;
  double varargin_2_data[4096];
  Sxx1_size[0] = 0;
  Sxx1_size[1] = 0;
  i84 = static_cast<int>(k);
  emxInit_creal_T(&Sxxk, 1);
  emxInit_real_T(&b_x, 1);
  for (ii = 0; ii < i84; ii++) {
    if (xStart->data[ii] > xEnd->data[ii]) {
      nx = 1;
      b_k = 0;
    } else {
      nx = static_cast<int>(xStart->data[ii]);
      b_k = static_cast<int>(xEnd->data[ii]);
    }

    i85 = b_x->size[0];
    loop_ub = b_k - nx;
    b_x->size[0] = loop_ub + 1;
    emxEnsureCapacity_real_T(b_x, i85);
    for (b_k = 0; b_k <= loop_ub; b_k++) {
      b_x->data[b_k] = x->data[(nx + b_k) - 1];
    }

    c_computeperiodogram(b_x, win, esttype_data, esttype_size, options_Fs, Sxxk,
                         b_w_data, w_size);
    if (1U + ii == 1U) {
      for (nx = 0; nx < 4096; nx++) {
        varargin_2_data[nx] = cmethod_tunableEnvironment[0] * Sxxk->data[nx].re;
      }

      Sxx1_size[0] = 4096;
      Sxx1_size[1] = 1;
      for (b_k = 0; b_k < 4096; b_k++) {
        if (rtIsNaN(varargin_2_data[b_k])) {
          Sxx1_data[b_k] = rtInf;
        } else {
          Sxx1_data[b_k] = varargin_2_data[b_k];
        }
      }
    } else {
      for (nx = 0; nx < 4096; nx++) {
        varargin_2_data[nx] = cmethod_tunableEnvironment[0] * Sxxk->data[nx].re;
      }

      i86 = static_cast<short>(Sxx1_size[0]);
      w_size[0] = Sxx1_size[0];
      nx = Sxx1_size[0];
      for (b_k = 0; b_k < nx; b_k++) {
        if ((Sxx1_data[b_k] < varargin_2_data[b_k]) || rtIsNaN
            (varargin_2_data[b_k])) {
          b_w_data[b_k] = Sxx1_data[b_k];
        } else {
          b_w_data[b_k] = varargin_2_data[b_k];
        }
      }

      Sxx1_size[0] = i86;
      Sxx1_size[1] = 1;
      if (0 <= i86 - 1) {
        memcpy(&Sxx1_data[0], &b_w_data[0], (unsigned int)(i86 * static_cast<int>
                (sizeof(double))));
      }
    }
  }

  emxFree_real_T(&b_x);
  emxFree_creal_T(&Sxxk);
  loop_ub = Sxx1_size[0] * Sxx1_size[1] - 1;
  for (i84 = 0; i84 <= loop_ub; i84++) {
    Sxx1_data[i84] /= k;
  }

  psdfreqvec(options_Fs, b_w_data, w_size);
  w[0] = w_size[0];
  w[1] = 1;
  computepsd(Sxx1_data, Sxx1_size, b_w_data, w, options_range, options_Fs,
             esttype_data, esttype_size, Pxx_data, Pxx_size, w_data, w_size,
             units_data, units_size);
}

static void g_localComputeSpectra(const double Sxx_data[], const emxArray_real_T
  *x, const emxArray_real_T *xStart, const emxArray_real_T *xEnd, const double
  win[63], double options_Fs, const char options_range[8], const char
  esttype_data[], const int esttype_size[2], double k, emxArray_creal_T *Pxx,
  double w_data[], int w_size[1], char units_data[], int units_size[2])
{
  emxArray_creal_T *Sxx1;
  int i87;
  emxArray_creal_T *Sxxk;
  emxArray_real_T *b_x;
  int ii;
  int i88;
  int loop_ub;
  int i89;
  int b_loop_ub;
  double b_w_data[4096];
  int b_w_size[1];
  double Sxx1_re;
  int w[2];
  double Sxx1_im;
  emxInit_creal_T(&Sxx1, 2);
  Sxx1->size[0] = 0;
  Sxx1->size[1] = 0;
  i87 = static_cast<int>(k);
  emxInit_creal_T(&Sxxk, 1);
  emxInit_real_T(&b_x, 1);
  for (ii = 0; ii < i87; ii++) {
    if (xStart->data[ii] > xEnd->data[ii]) {
      i88 = 1;
      loop_ub = 0;
    } else {
      i88 = static_cast<int>(xStart->data[ii]);
      loop_ub = static_cast<int>(xEnd->data[ii]);
    }

    i89 = b_x->size[0];
    b_loop_ub = loop_ub - i88;
    b_x->size[0] = b_loop_ub + 1;
    emxEnsureCapacity_real_T(b_x, i89);
    for (loop_ub = 0; loop_ub <= b_loop_ub; loop_ub++) {
      b_x->data[loop_ub] = x->data[(i88 + loop_ub) - 1];
    }

    c_computeperiodogram(b_x, win, esttype_data, esttype_size, options_Fs, Sxxk,
                         b_w_data, b_w_size);
    if (1U + ii == 1U) {
      i88 = Sxx1->size[0] * Sxx1->size[1];
      Sxx1->size[0] = 4096;
      Sxx1->size[1] = 1;
      emxEnsureCapacity_creal_T(Sxx1, i88);
      for (i88 = 0; i88 < 4096; i88++) {
        Sxx1->data[i88].re = Sxx_data[i88] + Sxxk->data[i88].re;
        Sxx1->data[i88].im = Sxxk->data[i88].im;
      }
    } else {
      b_loop_ub = Sxx1->size[0];
      loop_ub = Sxx1->size[0];
      i88 = Sxxk->size[0];
      Sxxk->size[0] = b_loop_ub;
      emxEnsureCapacity_creal_T(Sxxk, i88);
      for (i88 = 0; i88 < b_loop_ub; i88++) {
        Sxxk->data[i88].re += Sxx1->data[i88].re;
        Sxxk->data[i88].im += Sxx1->data[i88].im;
      }

      i88 = Sxx1->size[0] * Sxx1->size[1];
      Sxx1->size[0] = loop_ub;
      Sxx1->size[1] = 1;
      emxEnsureCapacity_creal_T(Sxx1, i88);
      for (i88 = 0; i88 < loop_ub; i88++) {
        Sxx1->data[i88] = Sxxk->data[i88];
      }
    }
  }

  emxFree_real_T(&b_x);
  emxFree_creal_T(&Sxxk);
  i87 = Sxx1->size[0] * Sxx1->size[1];
  i88 = Sxx1->size[0] * Sxx1->size[1];
  emxEnsureCapacity_creal_T(Sxx1, i88);
  b_loop_ub = i87 - 1;
  for (i87 = 0; i87 <= b_loop_ub; i87++) {
    Sxx1_re = Sxx1->data[i87].re;
    Sxx1_im = Sxx1->data[i87].im;
    if (Sxx1_im == 0.0) {
      Sxx1->data[i87].re = Sxx1_re / k;
      Sxx1->data[i87].im = 0.0;
    } else if (Sxx1_re == 0.0) {
      Sxx1->data[i87].re = 0.0;
      Sxx1->data[i87].im = Sxx1_im / k;
    } else {
      Sxx1->data[i87].re = Sxx1_re / k;
      Sxx1->data[i87].im = Sxx1_im / k;
    }
  }

  psdfreqvec(options_Fs, b_w_data, b_w_size);
  w[0] = b_w_size[0];
  w[1] = 1;
  b_computepsd(Sxx1, b_w_data, w, options_range, options_Fs, esttype_data,
               esttype_size, Pxx, w_data, w_size, units_data, units_size);
  emxFree_creal_T(&Sxx1);
}

static void h_localComputeSpectra(const double Sxx_data[], const emxArray_real_T
  *x, const emxArray_real_T *xStart, const emxArray_real_T *xEnd, const double
  win[63], double options_Fs, const char options_range[8], const char
  esttype_data[], const int esttype_size[2], double k, emxArray_creal_T *Pxx,
  double w_data[], int w_size[1], char units_data[], int units_size[2])
{
  emxArray_creal_T *Sxx1;
  int i90;
  emxArray_creal_T *Xx;
  emxArray_creal_T *z;
  boolean_T b_x[2];
  int ii;
  int i91;
  int loop_ub;
  int xw_size[2];
  int acoef_tmp;
  int acoef;
  double b_w_data[4096];
  int b_w_size[1];
  double b_win;
  int b_k;
  double Xx_re;
  double xw_data[63];
  boolean_T y;
  boolean_T exitg1;
  double Xx_im;
  double b_Xx_re;
  emxInit_creal_T(&Sxx1, 2);
  Sxx1->size[0] = 0;
  Sxx1->size[1] = 0;
  i90 = static_cast<int>(k);
  emxInit_creal_T(&Xx, 2);
  emxInit_creal_T(&z, 2);
  if (0 <= i90 - 1) {
    b_strcmp(esttype_data, esttype_size, b_x);
  }

  for (ii = 0; ii < i90; ii++) {
    if (xStart->data[ii] > xEnd->data[ii]) {
      i91 = -1;
      loop_ub = -1;
    } else {
      i91 = static_cast<int>(xStart->data[ii]) - 2;
      loop_ub = static_cast<int>(xEnd->data[ii]) - 1;
    }

    xw_size[0] = 63;
    xw_size[1] = 1;
    acoef_tmp = loop_ub - i91;
    acoef = (acoef_tmp != 1);
    for (b_k = 0; b_k < 63; b_k++) {
      loop_ub = acoef * b_k;
      xw_data[b_k] = x->data[((i91 + loop_ub % acoef_tmp) + x->size[0] *
        (loop_ub / acoef_tmp)) + 1];
    }

    b_fft(xw_data, xw_size, Xx);
    y = false;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k < 2)) {
      if (b_x[b_k]) {
        y = true;
        exitg1 = true;
      } else {
        b_k++;
      }
    }

    if (y) {
      b_win = 1.0;
      for (b_k = 0; b_k < 62; b_k++) {
        b_win++;
      }

      b_win *= b_win;
    } else {
      b_win = 0.0;
      for (i91 = 0; i91 < 63; i91++) {
        b_win += win[i91] * win[i91];
      }
    }

    i91 = z->size[0] * z->size[1];
    z->size[0] = 4096;
    z->size[1] = 1;
    emxEnsureCapacity_creal_T(z, i91);
    for (i91 = 0; i91 < 4096; i91++) {
      Xx_re = Xx->data[i91].re;
      Xx_im = -Xx->data[i91].im;
      b_Xx_re = Xx->data[i91].re * Xx_re - Xx->data[i91].im * Xx_im;
      Xx_im = Xx->data[i91].re * Xx_im + Xx->data[i91].im * Xx_re;
      if (Xx_im == 0.0) {
        z->data[i91].re = b_Xx_re / b_win;
        z->data[i91].im = 0.0;
      } else if (b_Xx_re == 0.0) {
        z->data[i91].re = 0.0;
        z->data[i91].im = Xx_im / b_win;
      } else {
        z->data[i91].re = b_Xx_re / b_win;
        z->data[i91].im = Xx_im / b_win;
      }
    }

    if (1U + ii == 1U) {
      i91 = Sxx1->size[0] * Sxx1->size[1];
      Sxx1->size[0] = 4096;
      Sxx1->size[1] = 1;
      emxEnsureCapacity_creal_T(Sxx1, i91);
      for (i91 = 0; i91 < 4096; i91++) {
        Sxx1->data[i91].re = Sxx_data[i91] + z->data[i91].re;
        Sxx1->data[i91].im = z->data[i91].im;
      }
    } else {
      i91 = Sxx1->size[0] * Sxx1->size[1];
      loop_ub = Sxx1->size[0] * Sxx1->size[1];
      emxEnsureCapacity_creal_T(Sxx1, loop_ub);
      loop_ub = i91 - 1;
      for (i91 = 0; i91 <= loop_ub; i91++) {
        Sxx1->data[i91].re += z->data[i91].re;
        Sxx1->data[i91].im += z->data[i91].im;
      }
    }
  }

  emxFree_creal_T(&z);
  emxFree_creal_T(&Xx);
  i90 = Sxx1->size[0] * Sxx1->size[1];
  i91 = Sxx1->size[0] * Sxx1->size[1];
  emxEnsureCapacity_creal_T(Sxx1, i91);
  loop_ub = i90 - 1;
  for (i90 = 0; i90 <= loop_ub; i90++) {
    b_win = Sxx1->data[i90].re;
    Xx_re = Sxx1->data[i90].im;
    if (Xx_re == 0.0) {
      Sxx1->data[i90].re = b_win / k;
      Sxx1->data[i90].im = 0.0;
    } else if (b_win == 0.0) {
      Sxx1->data[i90].re = 0.0;
      Sxx1->data[i90].im = Xx_re / k;
    } else {
      Sxx1->data[i90].re = b_win / k;
      Sxx1->data[i90].im = Xx_re / k;
    }
  }

  psdfreqvec(options_Fs, b_w_data, b_w_size);
  xw_size[0] = b_w_size[0];
  xw_size[1] = 1;
  b_computepsd(Sxx1, b_w_data, xw_size, options_range, options_Fs, esttype_data,
               esttype_size, Pxx, w_data, w_size, units_data, units_size);
  emxFree_creal_T(&Sxx1);
}

static void localComputeSpectra(const double x_data[], const emxArray_real_T
  *xStart, const emxArray_real_T *xEnd, const double win_data[], double
  options_Fs, const char options_range[8], const char esttype_data[], const int
  esttype_size[2], double k, const double cmethod_tunableEnvironment[1], double
  Pxx_data[], int Pxx_size[2], double w_data[], int w_size[1], char units_data[],
  int units_size[2])
{
  int Sxx1_size[2];
  int i15;
  emxArray_creal_T *Sxxk;
  int ii;
  int nx;
  int b_k;
  static double b_w_data[4096];
  static double Sxx1_data[4096];
  int x_size_tmp;
  int w[2];
  int x_size[1];
  double b_x_data[313];
  short i16;
  static double varargin_2_data[4096];
  Sxx1_size[0] = 0;
  Sxx1_size[1] = 0;
  i15 = static_cast<int>(k);
  emxInit_creal_T(&Sxxk, 1);
  for (ii = 0; ii < i15; ii++) {
    if (xStart->data[ii] > xEnd->data[ii]) {
      nx = 1;
      b_k = 0;
    } else {
      nx = static_cast<int>(xStart->data[ii]);
      b_k = static_cast<int>(xEnd->data[ii]);
    }

    x_size_tmp = b_k - nx;
    x_size[0] = x_size_tmp + 1;
    for (b_k = 0; b_k <= x_size_tmp; b_k++) {
      b_x_data[b_k] = x_data[(nx + b_k) - 1];
    }

    computeperiodogram(b_x_data, x_size, win_data, esttype_data, esttype_size,
                       options_Fs, Sxxk, b_w_data, w_size);
    if (1U + ii == 1U) {
      for (nx = 0; nx < 4096; nx++) {
        varargin_2_data[nx] = cmethod_tunableEnvironment[0] * Sxxk->data[nx].re;
      }

      Sxx1_size[0] = 4096;
      Sxx1_size[1] = 1;
      for (b_k = 0; b_k < 4096; b_k++) {
        if (rtIsNaN(varargin_2_data[b_k])) {
          Sxx1_data[b_k] = rtMinusInf;
        } else {
          Sxx1_data[b_k] = varargin_2_data[b_k];
        }
      }
    } else {
      for (nx = 0; nx < 4096; nx++) {
        varargin_2_data[nx] = cmethod_tunableEnvironment[0] * Sxxk->data[nx].re;
      }

      i16 = static_cast<short>(Sxx1_size[0]);
      w_size[0] = Sxx1_size[0];
      nx = Sxx1_size[0];
      for (b_k = 0; b_k < nx; b_k++) {
        if ((Sxx1_data[b_k] > varargin_2_data[b_k]) || rtIsNaN
            (varargin_2_data[b_k])) {
          b_w_data[b_k] = Sxx1_data[b_k];
        } else {
          b_w_data[b_k] = varargin_2_data[b_k];
        }
      }

      Sxx1_size[0] = i16;
      Sxx1_size[1] = 1;
      if (0 <= i16 - 1) {
        memcpy(&Sxx1_data[0], &b_w_data[0], (unsigned int)(i16 * static_cast<int>
                (sizeof(double))));
      }
    }
  }

  emxFree_creal_T(&Sxxk);
  nx = Sxx1_size[0] * Sxx1_size[1] - 1;
  for (i15 = 0; i15 <= nx; i15++) {
    Sxx1_data[i15] /= k;
  }

  psdfreqvec(options_Fs, b_w_data, w_size);
  w[0] = w_size[0];
  w[1] = 1;
  computepsd(Sxx1_data, Sxx1_size, b_w_data, w, options_range, options_Fs,
             esttype_data, esttype_size, Pxx_data, Pxx_size, w_data, w_size,
             units_data, units_size);
}

void b_welch(const emxArray_real_T *x, const char esttype_data[], const int
             esttype_size[2], const double varargin_1[63], double varargin_4,
             emxArray_creal_T *varargout_1, double varargout_2_data[], int
             varargout_2_size[1])
{
  double options_nfft;
  double options_Fs;
  boolean_T options_maxhold;
  boolean_T options_minhold;
  char options_range[8];
  static double Sxx_data[4096];
  emxArray_real_T *y;
  int b;
  int i80;
  emxArray_real_T *xEnd;
  boolean_T b_bool;
  int exitg1;
  emxArray_creal_T *Pxx;
  static const char varargin_1_f1[2] = { 'm', 's' };

  double cmethod2_tunableEnvironment[1];
  emxArray_real_T *b_x;
  emxArray_real_T c_x;
  static const char varargin_1_f2[5] = { 'p', 'o', 'w', 'e', 'r' };

  int d_x[1];
  int e_x[1];
  int f_x[1];
  int g_x[1];
  char units_data[10];
  int units_size[2];
  static const char varargin_1_f3[3] = { 'p', 's', 'd' };

  int Pxx_size[2];
  static const char cv7[4] = { 'c', 'p', 's', 'd' };

  static const char cv8[3] = { 't', 'f', 'e' };

  static const char cv9[5] = { 't', 'f', 'e', 'h', '2' };

  welch_options(63.0, varargin_4, &options_nfft, &options_Fs, &options_maxhold,
                &options_minhold, options_range);
  options_nfft = (static_cast<double>(x->size[1]) - 31.0) / 32.0;
  if (options_nfft < 0.0) {
    options_nfft = -0.0;
  } else {
    options_nfft = std::floor(options_nfft);
  }

  memset(&Sxx_data[0], 0, sizeof(double) << 12);
  emxInit_real_T(&y, 2);
  b = static_cast<int>(options_nfft) << 5;
  if (b < 1) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else {
    i80 = y->size[0] * y->size[1];
    y->size[0] = 1;
    b = static_cast<int>(std::floor((static_cast<double>(b) - 1.0) / 32.0));
    y->size[1] = b + 1;
    emxEnsureCapacity_real_T(y, i80);
    for (i80 = 0; i80 <= b; i80++) {
      y->data[i80] = 1.0 + 32.0 * static_cast<double>(i80);
    }
  }

  emxInit_real_T(&xEnd, 2);
  i80 = xEnd->size[0] * xEnd->size[1];
  xEnd->size[0] = 1;
  xEnd->size[1] = y->size[1];
  emxEnsureCapacity_real_T(xEnd, i80);
  b = y->size[0] * y->size[1];
  for (i80 = 0; i80 < b; i80++) {
    xEnd->data[i80] = (y->data[i80] + 63.0) - 1.0;
  }

  b_bool = false;
  if (esttype_size[1] == 2) {
    b = 0;
    do {
      exitg1 = 0;
      if (b < 2) {
        if (esttype_data[b] != varargin_1_f1[b]) {
          exitg1 = 1;
        } else {
          b++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  if (b_bool) {
    b = 0;
  } else {
    b_bool = false;
    if (esttype_size[1] == 5) {
      b = 0;
      do {
        exitg1 = 0;
        if (b < 5) {
          if (esttype_data[b] != varargin_1_f2[b]) {
            exitg1 = 1;
          } else {
            b++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }

    if (b_bool) {
      b = 0;
    } else {
      b_bool = false;
      if (esttype_size[1] == 3) {
        b = 0;
        do {
          exitg1 = 0;
          if (b < 3) {
            if (esttype_data[b] != varargin_1_f3[b]) {
              exitg1 = 1;
            } else {
              b++;
            }
          } else {
            b_bool = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }

      if (b_bool) {
        b = 0;
      } else {
        b_bool = false;
        if (esttype_size[1] == 4) {
          b = 0;
          do {
            exitg1 = 0;
            if (b < 4) {
              if (esttype_data[b] != cv7[b]) {
                exitg1 = 1;
              } else {
                b++;
              }
            } else {
              b_bool = true;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }

        if (b_bool) {
          b = 1;
        } else {
          b_bool = false;
          if (esttype_size[1] == 3) {
            b = 0;
            do {
              exitg1 = 0;
              if (b < 3) {
                if (esttype_data[b] != cv8[b]) {
                  exitg1 = 1;
                } else {
                  b++;
                }
              } else {
                b_bool = true;
                exitg1 = 1;
              }
            } while (exitg1 == 0);
          }

          if (b_bool) {
            b = 2;
          } else {
            b_bool = false;
            if (esttype_size[1] == 5) {
              b = 0;
              do {
                exitg1 = 0;
                if (b < 5) {
                  if (esttype_data[b] != cv9[b]) {
                    exitg1 = 1;
                  } else {
                    b++;
                  }
                } else {
                  b_bool = true;
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
            }

            if (b_bool) {
              b = 3;
            } else {
              b = -1;
            }
          }
        }
      }
    }
  }

  emxInit_creal_T(&Pxx, 2);
  switch (b) {
   case 0:
    if (options_maxhold) {
      cmethod2_tunableEnvironment[0] = options_nfft;
      b = x->size[1];
      c_x = *x;
      f_x[0] = b;
      c_x.size = &f_x[0];
      c_x.numDimensions = 1;
      e_localComputeSpectra(&c_x, y, xEnd, varargin_1, options_Fs, options_range,
                            esttype_data, esttype_size, options_nfft,
                            cmethod2_tunableEnvironment, Sxx_data, Pxx_size,
                            varargout_2_data, varargout_2_size, units_data,
                            units_size);
      i80 = Pxx->size[0] * Pxx->size[1];
      Pxx->size[0] = Pxx_size[0];
      Pxx->size[1] = Pxx_size[1];
      emxEnsureCapacity_creal_T(Pxx, i80);
      b = Pxx_size[0] * Pxx_size[1];
      for (i80 = 0; i80 < b; i80++) {
        Pxx->data[i80].re = Sxx_data[i80];
        Pxx->data[i80].im = 0.0;
      }
    } else if (options_minhold) {
      cmethod2_tunableEnvironment[0] = options_nfft;
      b = x->size[1];
      c_x = *x;
      g_x[0] = b;
      c_x.size = &g_x[0];
      c_x.numDimensions = 1;
      f_localComputeSpectra(&c_x, y, xEnd, varargin_1, options_Fs, options_range,
                            esttype_data, esttype_size, options_nfft,
                            cmethod2_tunableEnvironment, Sxx_data, Pxx_size,
                            varargout_2_data, varargout_2_size, units_data,
                            units_size);
      i80 = Pxx->size[0] * Pxx->size[1];
      Pxx->size[0] = Pxx_size[0];
      Pxx->size[1] = Pxx_size[1];
      emxEnsureCapacity_creal_T(Pxx, i80);
      b = Pxx_size[0] * Pxx_size[1];
      for (i80 = 0; i80 < b; i80++) {
        Pxx->data[i80].re = Sxx_data[i80];
        Pxx->data[i80].im = 0.0;
      }
    } else {
      b = x->size[1];
      c_x = *x;
      e_x[0] = b;
      c_x.size = &e_x[0];
      c_x.numDimensions = 1;
      g_localComputeSpectra(Sxx_data, &c_x, y, xEnd, varargin_1, options_Fs,
                            options_range, esttype_data, esttype_size,
                            options_nfft, Pxx, varargout_2_data,
                            varargout_2_size, units_data, units_size);
    }
    break;

   case 1:
    memset(&Sxx_data[0], 0, sizeof(double) << 12);
    emxInit_real_T(&b_x, 2);
    b = x->size[1];
    i80 = b_x->size[0] * b_x->size[1];
    b_x->size[0] = b;
    b_x->size[1] = 1;
    emxEnsureCapacity_real_T(b_x, i80);
    for (i80 = 0; i80 < b; i80++) {
      b_x->data[i80] = x->data[i80];
    }

    h_localComputeSpectra(Sxx_data, b_x, y, xEnd, varargin_1, options_Fs,
                          options_range, esttype_data, esttype_size,
                          options_nfft, Pxx, varargout_2_data, varargout_2_size,
                          units_data, units_size);
    emxFree_real_T(&b_x);
    break;

   case 2:
    b = x->size[1];
    c_x = *x;
    d_x[0] = b;
    c_x.size = &d_x[0];
    c_x.numDimensions = 1;
    g_localComputeSpectra(Sxx_data, &c_x, y, xEnd, varargin_1, options_Fs,
                          options_range, esttype_data, esttype_size,
                          options_nfft, Pxx, varargout_2_data, varargout_2_size,
                          units_data, units_size);
    Pxx->size[0] = 0;
    Pxx->size[1] = 0;
    break;

   case 3:
    varargout_2_size[0] = 0;
    Pxx->size[0] = 0;
    Pxx->size[1] = 0;
    break;

   default:
    Pxx->size[0] = 0;
    Pxx->size[1] = 0;
    varargout_2_size[0] = 0;
    break;
  }

  emxFree_real_T(&y);
  emxFree_real_T(&xEnd);
  i80 = varargout_1->size[0] * varargout_1->size[1] * varargout_1->size[2];
  varargout_1->size[0] = Pxx->size[0];
  varargout_1->size[1] = Pxx->size[1];
  varargout_1->size[2] = 1;
  emxEnsureCapacity_creal_T(varargout_1, i80);
  b = Pxx->size[0] * Pxx->size[1];
  for (i80 = 0; i80 < b; i80++) {
    varargout_1->data[i80] = Pxx->data[i80];
  }

  emxFree_creal_T(&Pxx);
}

void welch(const double x_data[], const int x_size[2], const char esttype_data[],
           const int esttype_size[2], const double varargin_1_data[], double
           varargin_4, emxArray_creal_T *varargout_1, double varargout_2_data[],
           int varargout_2_size[1])
{
  double b_x_data[313];
  int b_x_size[1];
  double M;
  char winName_data[12];
  int winName_size[2];
  int winParam_size[2];
  double opts[2];
  double L;
  double ndbl;
  double cdiff;
  double options_Fs;
  boolean_T options_maxhold;
  boolean_T options_minhold;
  char options_range[8];
  double k1_tmp;
  double k1;
  static double Sxx_data[4096];
  emxArray_real_T *xStart;
  int k;
  double apnd;
  emxArray_real_T *xEnd;
  int nm1d2;
  double u1;
  boolean_T b_bool;
  int n;
  int exitg1;
  emxArray_creal_T *Pxx;
  static const char varargin_1_f1[2] = { 'm', 's' };

  char units_data[10];
  double cmethod2_tunableEnvironment[1];
  static const char varargin_1_f2[5] = { 'p', 'o', 'w', 'e', 'r' };

  double c_x_data[313];
  static const char varargin_1_f3[3] = { 'p', 's', 'd' };

  static const char cv1[4] = { 'c', 'p', 's', 'd' };

  static const char cv2[3] = { 't', 'f', 'e' };

  static const char cv3[5] = { 't', 'f', 'e', 'h', '2' };

  parse_inputs(x_data, x_size, varargin_4, b_x_data, b_x_size, &M, winName_data,
               winName_size, winParam_size, opts);
  segment_info(&L, &ndbl);
  welch_options(L, opts[1], &cdiff, &options_Fs, &options_maxhold,
                &options_minhold, options_range);
  k1_tmp = L - ndbl;
  k1 = (M - ndbl) / k1_tmp;
  b_fix(&k1);
  memset(&Sxx_data[0], 0, sizeof(double) << 12);
  M = k1 * k1_tmp;
  emxInit_real_T(&xStart, 2);
  if (rtIsNaN(k1_tmp) || rtIsNaN(M)) {
    k = xStart->size[0] * xStart->size[1];
    xStart->size[0] = 1;
    xStart->size[1] = 1;
    emxEnsureCapacity_real_T(xStart, k);
    xStart->data[0] = rtNaN;
  } else if ((k1_tmp == 0.0) || ((1.0 < M) && (k1_tmp < 0.0)) || ((M < 1.0) &&
              (k1_tmp > 0.0))) {
    xStart->size[0] = 1;
    xStart->size[1] = 0;
  } else if (rtIsInf(M) && (rtIsInf(k1_tmp) || (1.0 == M))) {
    k = xStart->size[0] * xStart->size[1];
    xStart->size[0] = 1;
    xStart->size[1] = 1;
    emxEnsureCapacity_real_T(xStart, k);
    xStart->data[0] = rtNaN;
  } else if (rtIsInf(k1_tmp)) {
    k = xStart->size[0] * xStart->size[1];
    xStart->size[0] = 1;
    xStart->size[1] = 1;
    emxEnsureCapacity_real_T(xStart, k);
    xStart->data[0] = 1.0;
  } else if (std::floor(k1_tmp) == k1_tmp) {
    k = xStart->size[0] * xStart->size[1];
    xStart->size[0] = 1;
    nm1d2 = static_cast<int>(std::floor((M - 1.0) / k1_tmp));
    xStart->size[1] = nm1d2 + 1;
    emxEnsureCapacity_real_T(xStart, k);
    for (k = 0; k <= nm1d2; k++) {
      xStart->data[k] = 1.0 + k1_tmp * static_cast<double>(k);
    }
  } else {
    ndbl = std::floor((M - 1.0) / k1_tmp + 0.5);
    apnd = 1.0 + ndbl * k1_tmp;
    if (k1_tmp > 0.0) {
      cdiff = apnd - M;
    } else {
      cdiff = M - apnd;
    }

    u1 = std::abs(M);
    if ((1.0 > u1) || rtIsNaN(u1)) {
      u1 = 1.0;
    }

    if (std::abs(cdiff) < 4.4408920985006262E-16 * u1) {
      ndbl++;
      apnd = M;
    } else if (cdiff > 0.0) {
      apnd = 1.0 + (ndbl - 1.0) * k1_tmp;
    } else {
      ndbl++;
    }

    if (ndbl >= 0.0) {
      n = static_cast<int>(ndbl);
    } else {
      n = 0;
    }

    k = xStart->size[0] * xStart->size[1];
    xStart->size[0] = 1;
    xStart->size[1] = n;
    emxEnsureCapacity_real_T(xStart, k);
    if (n > 0) {
      xStart->data[0] = 1.0;
      if (n > 1) {
        xStart->data[n - 1] = apnd;
        nm1d2 = (n - 1) / 2;
        for (k = 0; k <= nm1d2 - 2; k++) {
          cdiff = (1.0 + static_cast<double>(k)) * k1_tmp;
          xStart->data[1 + k] = 1.0 + cdiff;
          xStart->data[(n - k) - 2] = apnd - cdiff;
        }

        if (nm1d2 << 1 == n - 1) {
          xStart->data[nm1d2] = (1.0 + apnd) / 2.0;
        } else {
          cdiff = static_cast<double>(nm1d2) * k1_tmp;
          xStart->data[nm1d2] = 1.0 + cdiff;
          xStart->data[nm1d2 + 1] = apnd - cdiff;
        }
      }
    }
  }

  emxInit_real_T(&xEnd, 2);
  k = xEnd->size[0] * xEnd->size[1];
  xEnd->size[0] = 1;
  xEnd->size[1] = xStart->size[1];
  emxEnsureCapacity_real_T(xEnd, k);
  nm1d2 = xStart->size[0] * xStart->size[1];
  for (k = 0; k < nm1d2; k++) {
    xEnd->data[k] = (xStart->data[k] + L) - 1.0;
  }

  b_bool = false;
  if (esttype_size[1] == 2) {
    nm1d2 = 0;
    do {
      exitg1 = 0;
      if (nm1d2 < 2) {
        if (esttype_data[nm1d2] != varargin_1_f1[nm1d2]) {
          exitg1 = 1;
        } else {
          nm1d2++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  if (b_bool) {
    nm1d2 = 0;
  } else {
    b_bool = false;
    if (esttype_size[1] == 5) {
      nm1d2 = 0;
      do {
        exitg1 = 0;
        if (nm1d2 < 5) {
          if (esttype_data[nm1d2] != varargin_1_f2[nm1d2]) {
            exitg1 = 1;
          } else {
            nm1d2++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }

    if (b_bool) {
      nm1d2 = 0;
    } else {
      b_bool = false;
      if (esttype_size[1] == 3) {
        nm1d2 = 0;
        do {
          exitg1 = 0;
          if (nm1d2 < 3) {
            if (esttype_data[nm1d2] != varargin_1_f3[nm1d2]) {
              exitg1 = 1;
            } else {
              nm1d2++;
            }
          } else {
            b_bool = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }

      if (b_bool) {
        nm1d2 = 0;
      } else {
        b_bool = false;
        if (esttype_size[1] == 4) {
          nm1d2 = 0;
          do {
            exitg1 = 0;
            if (nm1d2 < 4) {
              if (esttype_data[nm1d2] != cv1[nm1d2]) {
                exitg1 = 1;
              } else {
                nm1d2++;
              }
            } else {
              b_bool = true;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }

        if (b_bool) {
          nm1d2 = 1;
        } else {
          b_bool = false;
          if (esttype_size[1] == 3) {
            nm1d2 = 0;
            do {
              exitg1 = 0;
              if (nm1d2 < 3) {
                if (esttype_data[nm1d2] != cv2[nm1d2]) {
                  exitg1 = 1;
                } else {
                  nm1d2++;
                }
              } else {
                b_bool = true;
                exitg1 = 1;
              }
            } while (exitg1 == 0);
          }

          if (b_bool) {
            nm1d2 = 2;
          } else {
            b_bool = false;
            if (esttype_size[1] == 5) {
              nm1d2 = 0;
              do {
                exitg1 = 0;
                if (nm1d2 < 5) {
                  if (esttype_data[nm1d2] != cv3[nm1d2]) {
                    exitg1 = 1;
                  } else {
                    nm1d2++;
                  }
                } else {
                  b_bool = true;
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
            }

            if (b_bool) {
              nm1d2 = 3;
            } else {
              nm1d2 = -1;
            }
          }
        }
      }
    }
  }

  emxInit_creal_T(&Pxx, 2);
  switch (nm1d2) {
   case 0:
    if (options_maxhold) {
      cmethod2_tunableEnvironment[0] = k1;
      localComputeSpectra(b_x_data, xStart, xEnd, varargin_1_data, options_Fs,
                          options_range, esttype_data, esttype_size, k1,
                          cmethod2_tunableEnvironment, Sxx_data, winParam_size,
                          varargout_2_data, varargout_2_size, units_data,
                          winName_size);
      k = Pxx->size[0] * Pxx->size[1];
      Pxx->size[0] = winParam_size[0];
      Pxx->size[1] = winParam_size[1];
      emxEnsureCapacity_creal_T(Pxx, k);
      nm1d2 = winParam_size[0] * winParam_size[1];
      for (k = 0; k < nm1d2; k++) {
        Pxx->data[k].re = Sxx_data[k];
        Pxx->data[k].im = 0.0;
      }
    } else if (options_minhold) {
      cmethod2_tunableEnvironment[0] = k1;
      b_localComputeSpectra(b_x_data, xStart, xEnd, varargin_1_data, options_Fs,
                            options_range, esttype_data, esttype_size, k1,
                            cmethod2_tunableEnvironment, Sxx_data, winParam_size,
                            varargout_2_data, varargout_2_size, units_data,
                            winName_size);
      k = Pxx->size[0] * Pxx->size[1];
      Pxx->size[0] = winParam_size[0];
      Pxx->size[1] = winParam_size[1];
      emxEnsureCapacity_creal_T(Pxx, k);
      nm1d2 = winParam_size[0] * winParam_size[1];
      for (k = 0; k < nm1d2; k++) {
        Pxx->data[k].re = Sxx_data[k];
        Pxx->data[k].im = 0.0;
      }
    } else {
      c_localComputeSpectra(Sxx_data, b_x_data, xStart, xEnd, varargin_1_data,
                            options_Fs, options_range, esttype_data,
                            esttype_size, k1, Pxx, varargout_2_data,
                            varargout_2_size, units_data, winName_size);
    }
    break;

   case 1:
    memset(&Sxx_data[0], 0, sizeof(double) << 12);
    if (0 <= b_x_size[0] - 1) {
      memcpy(&c_x_data[0], &b_x_data[0], (unsigned int)(b_x_size[0] *
              static_cast<int>(sizeof(double))));
    }

    d_localComputeSpectra(Sxx_data, c_x_data, xStart, xEnd, varargin_1_data,
                          options_Fs, options_range, esttype_data, esttype_size,
                          k1, Pxx, varargout_2_data, varargout_2_size,
                          units_data, winName_size);
    break;

   case 2:
    c_localComputeSpectra(Sxx_data, b_x_data, xStart, xEnd, varargin_1_data,
                          options_Fs, options_range, esttype_data, esttype_size,
                          k1, Pxx, varargout_2_data, varargout_2_size,
                          units_data, winName_size);
    Pxx->size[0] = 0;
    Pxx->size[1] = 0;
    break;

   case 3:
    varargout_2_size[0] = 0;
    Pxx->size[0] = 0;
    Pxx->size[1] = 0;
    break;

   default:
    Pxx->size[0] = 0;
    Pxx->size[1] = 0;
    varargout_2_size[0] = 0;
    break;
  }

  emxFree_real_T(&xEnd);
  emxFree_real_T(&xStart);
  k = varargout_1->size[0] * varargout_1->size[1] * varargout_1->size[2];
  varargout_1->size[0] = Pxx->size[0];
  varargout_1->size[1] = Pxx->size[1];
  varargout_1->size[2] = 1;
  emxEnsureCapacity_creal_T(varargout_1, k);
  nm1d2 = Pxx->size[0] * Pxx->size[1];
  for (k = 0; k < nm1d2; k++) {
    varargout_1->data[k] = Pxx->data[k];
  }

  emxFree_creal_T(&Pxx);
}

/* End of code generation (welch.cpp) */

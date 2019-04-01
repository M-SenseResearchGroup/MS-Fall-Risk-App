/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * welch.c
 *
 * Code generation for function 'welch'
 *
 */

/* Include files */
#include <math.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "calibrate.h"
#include "get_calibration.h"
#include "get_classification.h"
#include "get_fall_class.h"
#include "get_features.h"
#include "get_strides.h"
#include "pre_process_feats.h"
#include "welch.h"
#include "getFallClass_emxutil.h"
#include "computepsd.h"
#include "psdfreqvec.h"
#include "computeperiodogram.h"
#include "welchparse.h"

/* Type Definitions */
#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct {
  double nfft;
  double Fs;
  double conflevel;
  boolean_T average;
  boolean_T maxhold;
  boolean_T minhold;
  boolean_T MIMO;
  boolean_T centerdc;
  char range[8];
} struct_T;

#endif                                 /*typedef_struct_T*/

/* Function Declarations */
static void b_localComputeSpectra(const double x[125], const double xStart_data[],
  const double xEnd_data[], const double win[125], const struct_T options, const
  char esttype_data[], const int esttype_size[2], const double
  cmethod_tunableEnvironment[1], double Pxx_data[], int Pxx_size[2], double
  w_data[], int w_size[1], char units_data[], int units_size[2]);
static void c_localComputeSpectra(const double Sxx_data[], const double x[125],
  const double xStart_data[], const double xEnd_data[], const double win[125],
  const struct_T options, const char esttype_data[], const int esttype_size[2],
  emxArray_creal_T *Pxx, double w_data[], int w_size[1], char units_data[], int
  units_size[2]);
static void d_localComputeSpectra(const double Sxx_data[], const double x_data[],
  const double xStart_data[], const double xEnd_data[], const double win[125],
  const struct_T options, const char esttype_data[], const int esttype_size[2],
  emxArray_creal_T *Pxx, double w_data[], int w_size[1], char units_data[], int
  units_size[2]);
static void e_localComputeSpectra(const double x[500], const double xStart_data[],
  const double xEnd_data[], const double win[63], const struct_T options, const
  char esttype_data[], const int esttype_size[2], const double
  cmethod_tunableEnvironment[1], double Pxx_data[], int Pxx_size[2], double
  w_data[], int w_size[1], char units_data[], int units_size[2]);
static void f_localComputeSpectra(const double x[500], const double xStart_data[],
  const double xEnd_data[], const double win[63], const struct_T options, const
  char esttype_data[], const int esttype_size[2], const double
  cmethod_tunableEnvironment[1], double Pxx_data[], int Pxx_size[2], double
  w_data[], int w_size[1], char units_data[], int units_size[2]);
static void g_localComputeSpectra(const double Sxx_data[], const double x[500],
  const double xStart_data[], const double xEnd_data[], const double win[63],
  const struct_T options, const char esttype_data[], const int esttype_size[2],
  emxArray_creal_T *Pxx, double w_data[], int w_size[1], char units_data[], int
  units_size[2]);
static void h_localComputeSpectra(const double Sxx_data[], const double x_data[],
  const double xStart_data[], const double xEnd_data[], const double win[63],
  const struct_T options, const char esttype_data[], const int esttype_size[2],
  emxArray_creal_T *Pxx, double w_data[], int w_size[1], char units_data[], int
  units_size[2]);
static void localComputeSpectra(const double x[125], const double xStart_data[],
  const double xEnd_data[], const double win[125], const struct_T options, const
  char esttype_data[], const int esttype_size[2], const double
  cmethod_tunableEnvironment[1], double Pxx_data[], int Pxx_size[2], double
  w_data[], int w_size[1], char units_data[], int units_size[2]);

/* Function Definitions */
static void b_localComputeSpectra(const double x[125], const double xStart_data[],
  const double xEnd_data[], const double win[125], const struct_T options, const
  char esttype_data[], const int esttype_size[2], const double
  cmethod_tunableEnvironment[1], double Pxx_data[], int Pxx_size[2], double
  w_data[], int w_size[1], char units_data[], int units_size[2])
{
  emxArray_creal_T *Sxxk;
  int k;
  int i18;
  int loop_ub_tmp;
  int Sxx1_size[2];
  int x_size[1];
  double x_data[125];
  double varargin_2_data[4096];
  double Sxx1_data[4096];
  int w[2];
  emxInit_creal_T(&Sxxk, 1);
  if (xStart_data[0] > xEnd_data[0]) {
    k = 0;
    i18 = 0;
  } else {
    k = (int)xStart_data[0] - 1;
    i18 = (int)xEnd_data[0];
  }

  loop_ub_tmp = i18 - k;
  Sxx1_size[0] = 4096;
  Sxx1_size[1] = 1;
  x_size[0] = loop_ub_tmp;
  for (i18 = 0; i18 < loop_ub_tmp; i18++) {
    x_data[i18] = x[k + i18];
  }

  computeperiodogram(x_data, x_size, win, esttype_data, esttype_size, options.Fs,
                     Sxxk, varargin_2_data, w_size);
  for (k = 0; k < 4096; k++) {
    varargin_2_data[k] = cmethod_tunableEnvironment[0] * Sxxk->data[k].re;
  }

  for (k = 0; k < 4096; k++) {
    Sxx1_data[k] = fmin(rtInf, varargin_2_data[k]);
  }

  emxFree_creal_T(&Sxxk);
  psdfreqvec(options.Fs, varargin_2_data, w_size);
  w[0] = w_size[0];
  w[1] = 1;
  computepsd(Sxx1_data, Sxx1_size, varargin_2_data, w, options.range, options.Fs,
             esttype_data, esttype_size, Pxx_data, Pxx_size, w_data, w_size,
             units_data, units_size);
}

static void c_localComputeSpectra(const double Sxx_data[], const double x[125],
  const double xStart_data[], const double xEnd_data[], const double win[125],
  const struct_T options, const char esttype_data[], const int esttype_size[2],
  emxArray_creal_T *Pxx, double w_data[], int w_size[1], char units_data[], int
  units_size[2])
{
  emxArray_creal_T *Sxx1;
  emxArray_creal_T *Sxxk;
  int i19;
  int loop_ub;
  int loop_ub_tmp;
  int x_size[1];
  double x_data[125];
  double b_w_data[4096];
  int b_w_size[1];
  double Sxx1_re;
  int w[2];
  double Sxx1_im;
  emxInit_creal_T(&Sxx1, 2);
  Sxx1->size[0] = 0;
  Sxx1->size[1] = 0;
  emxInit_creal_T(&Sxxk, 1);
  if (xStart_data[0] > xEnd_data[0]) {
    i19 = 0;
    loop_ub = 0;
  } else {
    i19 = (int)xStart_data[0] - 1;
    loop_ub = (int)xEnd_data[0];
  }

  loop_ub_tmp = loop_ub - i19;
  x_size[0] = loop_ub_tmp;
  for (loop_ub = 0; loop_ub < loop_ub_tmp; loop_ub++) {
    x_data[loop_ub] = x[i19 + loop_ub];
  }

  computeperiodogram(x_data, x_size, win, esttype_data, esttype_size, options.Fs,
                     Sxxk, b_w_data, b_w_size);
  i19 = Sxx1->size[0] * Sxx1->size[1];
  Sxx1->size[0] = 4096;
  Sxx1->size[1] = 1;
  emxEnsureCapacity_creal_T(Sxx1, i19);
  for (i19 = 0; i19 < 4096; i19++) {
    Sxx1->data[i19].re = Sxx_data[i19] + Sxxk->data[i19].re;
    Sxx1->data[i19].im = Sxxk->data[i19].im;
  }

  emxFree_creal_T(&Sxxk);
  i19 = Sxx1->size[0] * Sxx1->size[1];
  loop_ub = Sxx1->size[0] * Sxx1->size[1];
  emxEnsureCapacity_creal_T(Sxx1, loop_ub);
  loop_ub = i19 - 1;
  for (i19 = 0; i19 <= loop_ub; i19++) {
    Sxx1_re = Sxx1->data[i19].re;
    Sxx1_im = Sxx1->data[i19].im;
    if (Sxx1_im == 0.0) {
      Sxx1->data[i19].re = Sxx1_re;
      Sxx1->data[i19].im = 0.0;
    } else if (Sxx1_re == 0.0) {
      Sxx1->data[i19].re = 0.0;
      Sxx1->data[i19].im = Sxx1_im;
    } else {
      Sxx1->data[i19].re = Sxx1_re;
      Sxx1->data[i19].im = Sxx1_im;
    }
  }

  psdfreqvec(options.Fs, b_w_data, b_w_size);
  w[0] = b_w_size[0];
  w[1] = 1;
  b_computepsd(Sxx1, b_w_data, w, options.range, options.Fs, esttype_data,
               esttype_size, Pxx, w_data, w_size, units_data, units_size);
  emxFree_creal_T(&Sxx1);
}

static void d_localComputeSpectra(const double Sxx_data[], const double x_data[],
  const double xStart_data[], const double xEnd_data[], const double win[125],
  const struct_T options, const char esttype_data[], const int esttype_size[2],
  emxArray_creal_T *Pxx, double w_data[], int w_size[1], char units_data[], int
  units_size[2])
{
  emxArray_creal_T *Sxx1;
  emxArray_creal_T *Sxxk;
  int i23;
  int loop_ub;
  int loop_ub_tmp;
  int x_size[2];
  double b_x_data[125];
  double b_w_data[4096];
  int b_w_size[1];
  double Sxx1_re;
  double Sxx1_im;
  emxInit_creal_T(&Sxx1, 2);
  Sxx1->size[0] = 0;
  Sxx1->size[1] = 0;
  emxInit_creal_T(&Sxxk, 2);
  if (xStart_data[0] > xEnd_data[0]) {
    i23 = 0;
    loop_ub = 0;
  } else {
    i23 = (int)xStart_data[0] - 1;
    loop_ub = (int)xEnd_data[0];
  }

  loop_ub_tmp = loop_ub - i23;
  x_size[0] = loop_ub_tmp;
  x_size[1] = 1;
  for (loop_ub = 0; loop_ub < loop_ub_tmp; loop_ub++) {
    b_x_data[loop_ub] = x_data[i23 + loop_ub];
  }

  b_computeperiodogram(b_x_data, x_size, win, esttype_data, esttype_size,
                       options.Fs, Sxxk, b_w_data, b_w_size);
  i23 = Sxx1->size[0] * Sxx1->size[1];
  Sxx1->size[0] = 4096;
  Sxx1->size[1] = 1;
  emxEnsureCapacity_creal_T(Sxx1, i23);
  for (i23 = 0; i23 < 4096; i23++) {
    Sxx1->data[i23].re = Sxx_data[i23] + Sxxk->data[i23].re;
    Sxx1->data[i23].im = Sxxk->data[i23].im;
  }

  emxFree_creal_T(&Sxxk);
  i23 = Sxx1->size[0] * Sxx1->size[1];
  loop_ub = Sxx1->size[0] * Sxx1->size[1];
  emxEnsureCapacity_creal_T(Sxx1, loop_ub);
  loop_ub = i23 - 1;
  for (i23 = 0; i23 <= loop_ub; i23++) {
    Sxx1_re = Sxx1->data[i23].re;
    Sxx1_im = Sxx1->data[i23].im;
    if (Sxx1_im == 0.0) {
      Sxx1->data[i23].re = Sxx1_re;
      Sxx1->data[i23].im = 0.0;
    } else if (Sxx1_re == 0.0) {
      Sxx1->data[i23].re = 0.0;
      Sxx1->data[i23].im = Sxx1_im;
    } else {
      Sxx1->data[i23].re = Sxx1_re;
      Sxx1->data[i23].im = Sxx1_im;
    }
  }

  psdfreqvec(options.Fs, b_w_data, b_w_size);
  x_size[0] = b_w_size[0];
  x_size[1] = 1;
  b_computepsd(Sxx1, b_w_data, x_size, options.range, options.Fs, esttype_data,
               esttype_size, Pxx, w_data, w_size, units_data, units_size);
  emxFree_creal_T(&Sxx1);
}

static void e_localComputeSpectra(const double x[500], const double xStart_data[],
  const double xEnd_data[], const double win[63], const struct_T options, const
  char esttype_data[], const int esttype_size[2], const double
  cmethod_tunableEnvironment[1], double Pxx_data[], int Pxx_size[2], double
  w_data[], int w_size[1], char units_data[], int units_size[2])
{
  int Sxx1_size[2];
  emxArray_creal_T *Sxxk;
  int ii;
  int nx;
  int i37;
  static double b_w_data[4096];
  static double Sxx1_data[4096];
  int x_size_tmp;
  int w[2];
  int x_size[1];
  double x_data[500];
  short i38;
  static double varargin_2_data[4096];
  Sxx1_size[0] = 0;
  Sxx1_size[1] = 0;
  emxInit_creal_T(&Sxxk, 1);
  for (ii = 0; ii < 14; ii++) {
    if (xStart_data[ii] > xEnd_data[ii]) {
      i37 = 1;
      nx = 0;
    } else {
      i37 = (int)xStart_data[ii];
      nx = (int)xEnd_data[ii];
    }

    x_size_tmp = nx - i37;
    x_size[0] = x_size_tmp + 1;
    for (nx = 0; nx <= x_size_tmp; nx++) {
      x_data[nx] = x[(i37 + nx) - 1];
    }

    c_computeperiodogram(x_data, x_size, win, esttype_data, esttype_size,
                         options.Fs, Sxxk, b_w_data, w_size);
    if (1 + ii == 1) {
      for (i37 = 0; i37 < 4096; i37++) {
        varargin_2_data[i37] = cmethod_tunableEnvironment[0] * Sxxk->data[i37].
          re;
      }

      Sxx1_size[0] = 4096;
      Sxx1_size[1] = 1;
      for (x_size_tmp = 0; x_size_tmp < 4096; x_size_tmp++) {
        Sxx1_data[x_size_tmp] = fmax(rtMinusInf, varargin_2_data[x_size_tmp]);
      }
    } else {
      for (i37 = 0; i37 < 4096; i37++) {
        varargin_2_data[i37] = 14.0 * Sxxk->data[i37].re;
      }

      i38 = (short)Sxx1_size[0];
      w_size[0] = Sxx1_size[0];
      nx = Sxx1_size[0];
      for (x_size_tmp = 0; x_size_tmp < nx; x_size_tmp++) {
        b_w_data[x_size_tmp] = fmax(Sxx1_data[x_size_tmp],
          varargin_2_data[x_size_tmp]);
      }

      Sxx1_size[0] = i38;
      Sxx1_size[1] = 1;
      if (0 <= i38 - 1) {
        memcpy(&Sxx1_data[0], &b_w_data[0], (unsigned int)(i38 * (int)sizeof
                (double)));
      }
    }
  }

  emxFree_creal_T(&Sxxk);
  nx = Sxx1_size[0] * Sxx1_size[1] - 1;
  for (i37 = 0; i37 <= nx; i37++) {
    Sxx1_data[i37] /= 14.0;
  }

  psdfreqvec(options.Fs, b_w_data, w_size);
  w[0] = w_size[0];
  w[1] = 1;
  computepsd(Sxx1_data, Sxx1_size, b_w_data, w, options.range, options.Fs,
             esttype_data, esttype_size, Pxx_data, Pxx_size, w_data, w_size,
             units_data, units_size);
}

static void f_localComputeSpectra(const double x[500], const double xStart_data[],
  const double xEnd_data[], const double win[63], const struct_T options, const
  char esttype_data[], const int esttype_size[2], const double
  cmethod_tunableEnvironment[1], double Pxx_data[], int Pxx_size[2], double
  w_data[], int w_size[1], char units_data[], int units_size[2])
{
  int Sxx1_size[2];
  emxArray_creal_T *Sxxk;
  int ii;
  int nx;
  int i40;
  static double b_w_data[4096];
  static double Sxx1_data[4096];
  int x_size_tmp;
  int w[2];
  int x_size[1];
  double x_data[500];
  short i41;
  static double varargin_2_data[4096];
  Sxx1_size[0] = 0;
  Sxx1_size[1] = 0;
  emxInit_creal_T(&Sxxk, 1);
  for (ii = 0; ii < 14; ii++) {
    if (xStart_data[ii] > xEnd_data[ii]) {
      i40 = 1;
      nx = 0;
    } else {
      i40 = (int)xStart_data[ii];
      nx = (int)xEnd_data[ii];
    }

    x_size_tmp = nx - i40;
    x_size[0] = x_size_tmp + 1;
    for (nx = 0; nx <= x_size_tmp; nx++) {
      x_data[nx] = x[(i40 + nx) - 1];
    }

    c_computeperiodogram(x_data, x_size, win, esttype_data, esttype_size,
                         options.Fs, Sxxk, b_w_data, w_size);
    if (1 + ii == 1) {
      for (i40 = 0; i40 < 4096; i40++) {
        varargin_2_data[i40] = cmethod_tunableEnvironment[0] * Sxxk->data[i40].
          re;
      }

      Sxx1_size[0] = 4096;
      Sxx1_size[1] = 1;
      for (x_size_tmp = 0; x_size_tmp < 4096; x_size_tmp++) {
        Sxx1_data[x_size_tmp] = fmin(rtInf, varargin_2_data[x_size_tmp]);
      }
    } else {
      for (i40 = 0; i40 < 4096; i40++) {
        varargin_2_data[i40] = 14.0 * Sxxk->data[i40].re;
      }

      i41 = (short)Sxx1_size[0];
      w_size[0] = Sxx1_size[0];
      nx = Sxx1_size[0];
      for (x_size_tmp = 0; x_size_tmp < nx; x_size_tmp++) {
        b_w_data[x_size_tmp] = fmin(Sxx1_data[x_size_tmp],
          varargin_2_data[x_size_tmp]);
      }

      Sxx1_size[0] = i41;
      Sxx1_size[1] = 1;
      if (0 <= i41 - 1) {
        memcpy(&Sxx1_data[0], &b_w_data[0], (unsigned int)(i41 * (int)sizeof
                (double)));
      }
    }
  }

  emxFree_creal_T(&Sxxk);
  nx = Sxx1_size[0] * Sxx1_size[1] - 1;
  for (i40 = 0; i40 <= nx; i40++) {
    Sxx1_data[i40] /= 14.0;
  }

  psdfreqvec(options.Fs, b_w_data, w_size);
  w[0] = w_size[0];
  w[1] = 1;
  computepsd(Sxx1_data, Sxx1_size, b_w_data, w, options.range, options.Fs,
             esttype_data, esttype_size, Pxx_data, Pxx_size, w_data, w_size,
             units_data, units_size);
}

static void g_localComputeSpectra(const double Sxx_data[], const double x[500],
  const double xStart_data[], const double xEnd_data[], const double win[63],
  const struct_T options, const char esttype_data[], const int esttype_size[2],
  emxArray_creal_T *Pxx, double w_data[], int w_size[1], char units_data[], int
  units_size[2])
{
  emxArray_creal_T *Sxx1;
  emxArray_creal_T *Sxxk;
  int ii;
  int i42;
  int loop_ub;
  int x_size_tmp;
  int x_size[1];
  static double b_w_data[4096];
  int b_w_size[1];
  double Sxx1_re;
  int w[2];
  double Sxx1_im;
  double x_data[500];
  emxInit_creal_T(&Sxx1, 2);
  Sxx1->size[0] = 0;
  Sxx1->size[1] = 0;
  emxInit_creal_T(&Sxxk, 1);
  for (ii = 0; ii < 14; ii++) {
    if (xStart_data[ii] > xEnd_data[ii]) {
      i42 = 1;
      loop_ub = 0;
    } else {
      i42 = (int)xStart_data[ii];
      loop_ub = (int)xEnd_data[ii];
    }

    x_size_tmp = loop_ub - i42;
    x_size[0] = x_size_tmp + 1;
    for (loop_ub = 0; loop_ub <= x_size_tmp; loop_ub++) {
      x_data[loop_ub] = x[(i42 + loop_ub) - 1];
    }

    c_computeperiodogram(x_data, x_size, win, esttype_data, esttype_size,
                         options.Fs, Sxxk, b_w_data, b_w_size);
    if (1 + ii == 1) {
      i42 = Sxx1->size[0] * Sxx1->size[1];
      Sxx1->size[0] = 4096;
      Sxx1->size[1] = 1;
      emxEnsureCapacity_creal_T(Sxx1, i42);
      for (i42 = 0; i42 < 4096; i42++) {
        Sxx1->data[i42].re = Sxx_data[i42] + Sxxk->data[i42].re;
        Sxx1->data[i42].im = Sxxk->data[i42].im;
      }
    } else {
      loop_ub = Sxx1->size[0];
      x_size_tmp = Sxx1->size[0];
      i42 = Sxxk->size[0];
      Sxxk->size[0] = loop_ub;
      emxEnsureCapacity_creal_T(Sxxk, i42);
      for (i42 = 0; i42 < loop_ub; i42++) {
        Sxxk->data[i42].re += Sxx1->data[i42].re;
        Sxxk->data[i42].im += Sxx1->data[i42].im;
      }

      i42 = Sxx1->size[0] * Sxx1->size[1];
      Sxx1->size[0] = x_size_tmp;
      Sxx1->size[1] = 1;
      emxEnsureCapacity_creal_T(Sxx1, i42);
      for (i42 = 0; i42 < x_size_tmp; i42++) {
        Sxx1->data[i42] = Sxxk->data[i42];
      }
    }
  }

  emxFree_creal_T(&Sxxk);
  i42 = Sxx1->size[0] * Sxx1->size[1];
  loop_ub = Sxx1->size[0] * Sxx1->size[1];
  emxEnsureCapacity_creal_T(Sxx1, loop_ub);
  loop_ub = i42 - 1;
  for (i42 = 0; i42 <= loop_ub; i42++) {
    Sxx1_re = Sxx1->data[i42].re;
    Sxx1_im = Sxx1->data[i42].im;
    if (Sxx1_im == 0.0) {
      Sxx1->data[i42].re = Sxx1_re / 14.0;
      Sxx1->data[i42].im = 0.0;
    } else if (Sxx1_re == 0.0) {
      Sxx1->data[i42].re = 0.0;
      Sxx1->data[i42].im = Sxx1_im / 14.0;
    } else {
      Sxx1->data[i42].re = Sxx1_re / 14.0;
      Sxx1->data[i42].im = Sxx1_im / 14.0;
    }
  }

  psdfreqvec(options.Fs, b_w_data, b_w_size);
  w[0] = b_w_size[0];
  w[1] = 1;
  b_computepsd(Sxx1, b_w_data, w, options.range, options.Fs, esttype_data,
               esttype_size, Pxx, w_data, w_size, units_data, units_size);
  emxFree_creal_T(&Sxx1);
}

static void h_localComputeSpectra(const double Sxx_data[], const double x_data[],
  const double xStart_data[], const double xEnd_data[], const double win[63],
  const struct_T options, const char esttype_data[], const int esttype_size[2],
  emxArray_creal_T *Pxx, double w_data[], int w_size[1], char units_data[], int
  units_size[2])
{
  emxArray_creal_T *Sxx1;
  emxArray_creal_T *Sxxk;
  int ii;
  int i43;
  int loop_ub;
  int x_size_tmp;
  int x_size[2];
  static double b_w_data[4096];
  int b_w_size[1];
  double Sxx1_re;
  double Sxx1_im;
  double b_x_data[500];
  emxInit_creal_T(&Sxx1, 2);
  Sxx1->size[0] = 0;
  Sxx1->size[1] = 0;
  emxInit_creal_T(&Sxxk, 2);
  for (ii = 0; ii < 14; ii++) {
    if (xStart_data[ii] > xEnd_data[ii]) {
      i43 = 1;
      loop_ub = 0;
    } else {
      i43 = (int)xStart_data[ii];
      loop_ub = (int)xEnd_data[ii];
    }

    x_size_tmp = loop_ub - i43;
    x_size[0] = x_size_tmp + 1;
    x_size[1] = 1;
    for (loop_ub = 0; loop_ub <= x_size_tmp; loop_ub++) {
      b_x_data[loop_ub] = x_data[(i43 + loop_ub) - 1];
    }

    d_computeperiodogram(b_x_data, x_size, win, esttype_data, esttype_size,
                         options.Fs, Sxxk, b_w_data, b_w_size);
    if (1 + ii == 1) {
      i43 = Sxx1->size[0] * Sxx1->size[1];
      Sxx1->size[0] = 4096;
      Sxx1->size[1] = 1;
      emxEnsureCapacity_creal_T(Sxx1, i43);
      for (i43 = 0; i43 < 4096; i43++) {
        Sxx1->data[i43].re = Sxx_data[i43] + Sxxk->data[i43].re;
        Sxx1->data[i43].im = Sxxk->data[i43].im;
      }
    } else {
      i43 = Sxx1->size[0] * Sxx1->size[1];
      loop_ub = Sxx1->size[0] * Sxx1->size[1];
      emxEnsureCapacity_creal_T(Sxx1, loop_ub);
      loop_ub = i43 - 1;
      for (i43 = 0; i43 <= loop_ub; i43++) {
        Sxx1->data[i43].re += Sxxk->data[i43].re;
        Sxx1->data[i43].im += Sxxk->data[i43].im;
      }
    }
  }

  emxFree_creal_T(&Sxxk);
  i43 = Sxx1->size[0] * Sxx1->size[1];
  loop_ub = Sxx1->size[0] * Sxx1->size[1];
  emxEnsureCapacity_creal_T(Sxx1, loop_ub);
  loop_ub = i43 - 1;
  for (i43 = 0; i43 <= loop_ub; i43++) {
    Sxx1_re = Sxx1->data[i43].re;
    Sxx1_im = Sxx1->data[i43].im;
    if (Sxx1_im == 0.0) {
      Sxx1->data[i43].re = Sxx1_re / 14.0;
      Sxx1->data[i43].im = 0.0;
    } else if (Sxx1_re == 0.0) {
      Sxx1->data[i43].re = 0.0;
      Sxx1->data[i43].im = Sxx1_im / 14.0;
    } else {
      Sxx1->data[i43].re = Sxx1_re / 14.0;
      Sxx1->data[i43].im = Sxx1_im / 14.0;
    }
  }

  psdfreqvec(options.Fs, b_w_data, b_w_size);
  x_size[0] = b_w_size[0];
  x_size[1] = 1;
  b_computepsd(Sxx1, b_w_data, x_size, options.range, options.Fs, esttype_data,
               esttype_size, Pxx, w_data, w_size, units_data, units_size);
  emxFree_creal_T(&Sxx1);
}

static void localComputeSpectra(const double x[125], const double xStart_data[],
  const double xEnd_data[], const double win[125], const struct_T options, const
  char esttype_data[], const int esttype_size[2], const double
  cmethod_tunableEnvironment[1], double Pxx_data[], int Pxx_size[2], double
  w_data[], int w_size[1], char units_data[], int units_size[2])
{
  emxArray_creal_T *Sxxk;
  int k;
  int i13;
  int loop_ub_tmp;
  int Sxx1_size[2];
  int x_size[1];
  double x_data[125];
  double varargin_2_data[4096];
  double Sxx1_data[4096];
  int w[2];
  emxInit_creal_T(&Sxxk, 1);
  if (xStart_data[0] > xEnd_data[0]) {
    k = 0;
    i13 = 0;
  } else {
    k = (int)xStart_data[0] - 1;
    i13 = (int)xEnd_data[0];
  }

  loop_ub_tmp = i13 - k;
  Sxx1_size[0] = 4096;
  Sxx1_size[1] = 1;
  x_size[0] = loop_ub_tmp;
  for (i13 = 0; i13 < loop_ub_tmp; i13++) {
    x_data[i13] = x[k + i13];
  }

  computeperiodogram(x_data, x_size, win, esttype_data, esttype_size, options.Fs,
                     Sxxk, varargin_2_data, w_size);
  for (k = 0; k < 4096; k++) {
    varargin_2_data[k] = cmethod_tunableEnvironment[0] * Sxxk->data[k].re;
  }

  for (k = 0; k < 4096; k++) {
    Sxx1_data[k] = fmax(rtMinusInf, varargin_2_data[k]);
  }

  emxFree_creal_T(&Sxxk);
  psdfreqvec(options.Fs, varargin_2_data, w_size);
  w[0] = w_size[0];
  w[1] = 1;
  computepsd(Sxx1_data, Sxx1_size, varargin_2_data, w, options.range, options.Fs,
             esttype_data, esttype_size, Pxx_data, Pxx_size, w_data, w_size,
             units_data, units_size);
}

void b_welch(const double x[125], const char esttype_data[], const int
             esttype_size[2], const double varargin_1[125], double varargin_4,
             emxArray_creal_T *varargout_1, double varargout_2_data[], int
             varargout_2_size[1])
{
  double k1;
  double L;
  struct_T options;
  double Sxx_data[4096];
  double xEnd_data[2];
  boolean_T b_bool;
  int kstr;
  int exitg1;
  emxArray_creal_T *Pxx;
  static const char varargin_1_f1[2] = { 'm', 's' };

  double tmp_data[2];
  double cmethod2_tunableEnvironment[1];
  char units_data[10];
  int units_size[2];
  static const char varargin_1_f2[5] = { 'p', 'o', 'w', 'e', 'r' };

  double x_data[125];
  int Pxx_size[2];
  int i25;
  static const char varargin_1_f3[3] = { 'p', 's', 'd' };

  static const char cv7[4] = { 'c', 'p', 's', 'd' };

  static const char cv8[3] = { 't', 'f', 'e' };

  static const char cv9[5] = { 't', 'f', 'e', 'h', '2' };

  c_welchparse(varargin_4, &k1, &L, &options.nfft, &options.Fs, &options.maxhold,
               &options.minhold, options.range);
  options.nfft = 4096.0;
  memset(&Sxx_data[0], 0, sizeof(double) << 12);
  xEnd_data[0] = 125.0;
  b_bool = false;
  if (esttype_size[1] == 2) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 2) {
        if (esttype_data[kstr] != varargin_1_f1[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  if (b_bool) {
    kstr = 0;
  } else {
    b_bool = false;
    if (esttype_size[1] == 5) {
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr < 5) {
          if (esttype_data[kstr] != varargin_1_f2[kstr]) {
            exitg1 = 1;
          } else {
            kstr++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }

    if (b_bool) {
      kstr = 0;
    } else {
      b_bool = false;
      if (esttype_size[1] == 3) {
        kstr = 0;
        do {
          exitg1 = 0;
          if (kstr < 3) {
            if (esttype_data[kstr] != varargin_1_f3[kstr]) {
              exitg1 = 1;
            } else {
              kstr++;
            }
          } else {
            b_bool = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }

      if (b_bool) {
        kstr = 0;
      } else {
        b_bool = false;
        if (esttype_size[1] == 4) {
          kstr = 0;
          do {
            exitg1 = 0;
            if (kstr < 4) {
              if (esttype_data[kstr] != cv7[kstr]) {
                exitg1 = 1;
              } else {
                kstr++;
              }
            } else {
              b_bool = true;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }

        if (b_bool) {
          kstr = 1;
        } else {
          b_bool = false;
          if (esttype_size[1] == 3) {
            kstr = 0;
            do {
              exitg1 = 0;
              if (kstr < 3) {
                if (esttype_data[kstr] != cv8[kstr]) {
                  exitg1 = 1;
                } else {
                  kstr++;
                }
              } else {
                b_bool = true;
                exitg1 = 1;
              }
            } while (exitg1 == 0);
          }

          if (b_bool) {
            kstr = 2;
          } else {
            b_bool = false;
            if (esttype_size[1] == 5) {
              kstr = 0;
              do {
                exitg1 = 0;
                if (kstr < 5) {
                  if (esttype_data[kstr] != cv9[kstr]) {
                    exitg1 = 1;
                  } else {
                    kstr++;
                  }
                } else {
                  b_bool = true;
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
            }

            if (b_bool) {
              kstr = 3;
            } else {
              kstr = -1;
            }
          }
        }
      }
    }
  }

  emxInit_creal_T(&Pxx, 2);
  switch (kstr) {
   case 0:
    if (options.maxhold) {
      cmethod2_tunableEnvironment[0] = 1.0;
      tmp_data[0] = 1.0;
      localComputeSpectra(x, tmp_data, xEnd_data, varargin_1, options,
                          esttype_data, esttype_size,
                          cmethod2_tunableEnvironment, Sxx_data, Pxx_size,
                          varargout_2_data, varargout_2_size, units_data,
                          units_size);
      i25 = Pxx->size[0] * Pxx->size[1];
      Pxx->size[0] = Pxx_size[0];
      Pxx->size[1] = Pxx_size[1];
      emxEnsureCapacity_creal_T(Pxx, i25);
      kstr = Pxx_size[0] * Pxx_size[1];
      for (i25 = 0; i25 < kstr; i25++) {
        Pxx->data[i25].re = Sxx_data[i25];
        Pxx->data[i25].im = 0.0;
      }
    } else if (options.minhold) {
      cmethod2_tunableEnvironment[0] = 1.0;
      tmp_data[0] = 1.0;
      b_localComputeSpectra(x, tmp_data, xEnd_data, varargin_1, options,
                            esttype_data, esttype_size,
                            cmethod2_tunableEnvironment, Sxx_data, Pxx_size,
                            varargout_2_data, varargout_2_size, units_data,
                            units_size);
      i25 = Pxx->size[0] * Pxx->size[1];
      Pxx->size[0] = Pxx_size[0];
      Pxx->size[1] = Pxx_size[1];
      emxEnsureCapacity_creal_T(Pxx, i25);
      kstr = Pxx_size[0] * Pxx_size[1];
      for (i25 = 0; i25 < kstr; i25++) {
        Pxx->data[i25].re = Sxx_data[i25];
        Pxx->data[i25].im = 0.0;
      }
    } else {
      tmp_data[0] = 1.0;
      c_localComputeSpectra(Sxx_data, x, tmp_data, xEnd_data, varargin_1,
                            options, esttype_data, esttype_size, Pxx,
                            varargout_2_data, varargout_2_size, units_data,
                            units_size);
    }
    break;

   case 1:
    memset(&Sxx_data[0], 0, sizeof(double) << 12);
    tmp_data[0] = 1.0;
    memcpy(&x_data[0], &x[0], 125U * sizeof(double));
    d_localComputeSpectra(Sxx_data, x_data, tmp_data, xEnd_data, varargin_1,
                          options, esttype_data, esttype_size, Pxx,
                          varargout_2_data, varargout_2_size, units_data,
                          units_size);
    break;

   case 2:
    tmp_data[0] = 1.0;
    c_localComputeSpectra(Sxx_data, x, tmp_data, xEnd_data, varargin_1, options,
                          esttype_data, esttype_size, Pxx, varargout_2_data,
                          varargout_2_size, units_data, units_size);
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

  i25 = varargout_1->size[0] * varargout_1->size[1] * varargout_1->size[2];
  varargout_1->size[0] = Pxx->size[0];
  varargout_1->size[1] = Pxx->size[1];
  varargout_1->size[2] = 1;
  emxEnsureCapacity_creal_T(varargout_1, i25);
  kstr = Pxx->size[0] * Pxx->size[1];
  for (i25 = 0; i25 < kstr; i25++) {
    varargout_1->data[i25] = Pxx->data[i25];
  }

  emxFree_creal_T(&Pxx);
}

void c_welch(const double x[500], const char esttype_data[], const int
             esttype_size[2], const double varargin_1[63], double varargin_4,
             emxArray_creal_T *varargout_1, double varargout_2_data[], int
             varargout_2_size[1])
{
  double x1[500];
  double win1[63];
  double k1;
  double L;
  struct_T options;
  static double Sxx_data[4096];
  int i36;
  boolean_T b_bool;
  double xEnd_data[15];
  int kstr;
  int exitg1;
  emxArray_creal_T *Pxx;
  static const char varargin_1_f1[2] = { 'm', 's' };

  double cmethod2_tunableEnvironment[1];
  static const char varargin_1_f2[5] = { 'p', 'o', 'w', 'e', 'r' };

  double tmp_data[14];
  char units_data[10];
  int units_size[2];
  int Pxx_size[2];
  static const char varargin_1_f3[3] = { 'p', 's', 'd' };

  static const char cv10[4] = { 'c', 'p', 's', 'd' };

  static const char cv11[3] = { 't', 'f', 'e' };

  static const char cv12[5] = { 't', 'f', 'e', 'h', '2' };

  welchparse(x, varargin_1, varargin_4, x1, win1, &k1, &L, &options.nfft,
             &options.Fs, &options.maxhold, &options.minhold, options.range);
  options.nfft = 4096.0;
  memset(&Sxx_data[0], 0, sizeof(double) << 12);
  for (i36 = 0; i36 < 14; i36++) {
    xEnd_data[i36] = ((1.0 + 32.0 * (double)i36) + 63.0) - 1.0;
  }

  b_bool = false;
  if (esttype_size[1] == 2) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 2) {
        if (esttype_data[kstr] != varargin_1_f1[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  if (b_bool) {
    kstr = 0;
  } else {
    b_bool = false;
    if (esttype_size[1] == 5) {
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr < 5) {
          if (esttype_data[kstr] != varargin_1_f2[kstr]) {
            exitg1 = 1;
          } else {
            kstr++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }

    if (b_bool) {
      kstr = 0;
    } else {
      b_bool = false;
      if (esttype_size[1] == 3) {
        kstr = 0;
        do {
          exitg1 = 0;
          if (kstr < 3) {
            if (esttype_data[kstr] != varargin_1_f3[kstr]) {
              exitg1 = 1;
            } else {
              kstr++;
            }
          } else {
            b_bool = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }

      if (b_bool) {
        kstr = 0;
      } else {
        b_bool = false;
        if (esttype_size[1] == 4) {
          kstr = 0;
          do {
            exitg1 = 0;
            if (kstr < 4) {
              if (esttype_data[kstr] != cv10[kstr]) {
                exitg1 = 1;
              } else {
                kstr++;
              }
            } else {
              b_bool = true;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }

        if (b_bool) {
          kstr = 1;
        } else {
          b_bool = false;
          if (esttype_size[1] == 3) {
            kstr = 0;
            do {
              exitg1 = 0;
              if (kstr < 3) {
                if (esttype_data[kstr] != cv11[kstr]) {
                  exitg1 = 1;
                } else {
                  kstr++;
                }
              } else {
                b_bool = true;
                exitg1 = 1;
              }
            } while (exitg1 == 0);
          }

          if (b_bool) {
            kstr = 2;
          } else {
            b_bool = false;
            if (esttype_size[1] == 5) {
              kstr = 0;
              do {
                exitg1 = 0;
                if (kstr < 5) {
                  if (esttype_data[kstr] != cv12[kstr]) {
                    exitg1 = 1;
                  } else {
                    kstr++;
                  }
                } else {
                  b_bool = true;
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
            }

            if (b_bool) {
              kstr = 3;
            } else {
              kstr = -1;
            }
          }
        }
      }
    }
  }

  emxInit_creal_T(&Pxx, 2);
  switch (kstr) {
   case 0:
    if (options.maxhold) {
      cmethod2_tunableEnvironment[0] = 14.0;
      for (i36 = 0; i36 < 14; i36++) {
        tmp_data[i36] = 1.0 + 32.0 * (double)i36;
      }

      e_localComputeSpectra(x1, tmp_data, xEnd_data, win1, options, esttype_data,
                            esttype_size, cmethod2_tunableEnvironment, Sxx_data,
                            Pxx_size, varargout_2_data, varargout_2_size,
                            units_data, units_size);
      i36 = Pxx->size[0] * Pxx->size[1];
      Pxx->size[0] = Pxx_size[0];
      Pxx->size[1] = Pxx_size[1];
      emxEnsureCapacity_creal_T(Pxx, i36);
      kstr = Pxx_size[0] * Pxx_size[1];
      for (i36 = 0; i36 < kstr; i36++) {
        Pxx->data[i36].re = Sxx_data[i36];
        Pxx->data[i36].im = 0.0;
      }
    } else if (options.minhold) {
      cmethod2_tunableEnvironment[0] = 14.0;
      for (i36 = 0; i36 < 14; i36++) {
        tmp_data[i36] = 1.0 + 32.0 * (double)i36;
      }

      f_localComputeSpectra(x1, tmp_data, xEnd_data, win1, options, esttype_data,
                            esttype_size, cmethod2_tunableEnvironment, Sxx_data,
                            Pxx_size, varargout_2_data, varargout_2_size,
                            units_data, units_size);
      i36 = Pxx->size[0] * Pxx->size[1];
      Pxx->size[0] = Pxx_size[0];
      Pxx->size[1] = Pxx_size[1];
      emxEnsureCapacity_creal_T(Pxx, i36);
      kstr = Pxx_size[0] * Pxx_size[1];
      for (i36 = 0; i36 < kstr; i36++) {
        Pxx->data[i36].re = Sxx_data[i36];
        Pxx->data[i36].im = 0.0;
      }
    } else {
      for (i36 = 0; i36 < 14; i36++) {
        tmp_data[i36] = 1.0 + 32.0 * (double)i36;
      }

      g_localComputeSpectra(Sxx_data, x1, tmp_data, xEnd_data, win1, options,
                            esttype_data, esttype_size, Pxx, varargout_2_data,
                            varargout_2_size, units_data, units_size);
    }
    break;

   case 1:
    memset(&Sxx_data[0], 0, sizeof(double) << 12);
    for (i36 = 0; i36 < 14; i36++) {
      tmp_data[i36] = 1.0 + 32.0 * (double)i36;
    }

    h_localComputeSpectra(Sxx_data, x1, tmp_data, xEnd_data, win1, options,
                          esttype_data, esttype_size, Pxx, varargout_2_data,
                          varargout_2_size, units_data, units_size);
    break;

   case 2:
    for (i36 = 0; i36 < 14; i36++) {
      tmp_data[i36] = 1.0 + 32.0 * (double)i36;
    }

    g_localComputeSpectra(Sxx_data, x1, tmp_data, xEnd_data, win1, options,
                          esttype_data, esttype_size, Pxx, varargout_2_data,
                          varargout_2_size, units_data, units_size);
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

  i36 = varargout_1->size[0] * varargout_1->size[1] * varargout_1->size[2];
  varargout_1->size[0] = Pxx->size[0];
  varargout_1->size[1] = Pxx->size[1];
  varargout_1->size[2] = 1;
  emxEnsureCapacity_creal_T(varargout_1, i36);
  kstr = Pxx->size[0] * Pxx->size[1];
  for (i36 = 0; i36 < kstr; i36++) {
    varargout_1->data[i36] = Pxx->data[i36];
  }

  emxFree_creal_T(&Pxx);
}

void welch(const double x[125], const char esttype_data[], const int
           esttype_size[2], const double varargin_1[125], double varargin_4,
           emxArray_creal_T *varargout_1, double varargout_2_data[], int
           varargout_2_size[1])
{
  double x1[125];
  double k1;
  double L;
  struct_T options;
  double Sxx_data[4096];
  double xEnd_data[2];
  boolean_T b_bool;
  int kstr;
  int exitg1;
  emxArray_creal_T *Pxx;
  static const char varargin_1_f1[2] = { 'm', 's' };

  double tmp_data[2];
  double cmethod2_tunableEnvironment[1];
  char units_data[10];
  int units_size[2];
  static const char varargin_1_f2[5] = { 'p', 'o', 'w', 'e', 'r' };

  int Pxx_size[2];
  int i12;
  static const char varargin_1_f3[3] = { 'p', 's', 'd' };

  static const char cv1[4] = { 'c', 'p', 's', 'd' };

  static const char cv2[3] = { 't', 'f', 'e' };

  static const char cv3[5] = { 't', 'f', 'e', 'h', '2' };

  b_welchparse(x, varargin_4, x1, &k1, &L, &options.nfft, &options.Fs,
               &options.maxhold, &options.minhold, options.range);
  options.nfft = 4096.0;
  memset(&Sxx_data[0], 0, sizeof(double) << 12);
  xEnd_data[0] = 125.0;
  b_bool = false;
  if (esttype_size[1] == 2) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 2) {
        if (esttype_data[kstr] != varargin_1_f1[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  if (b_bool) {
    kstr = 0;
  } else {
    b_bool = false;
    if (esttype_size[1] == 5) {
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr < 5) {
          if (esttype_data[kstr] != varargin_1_f2[kstr]) {
            exitg1 = 1;
          } else {
            kstr++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }

    if (b_bool) {
      kstr = 0;
    } else {
      b_bool = false;
      if (esttype_size[1] == 3) {
        kstr = 0;
        do {
          exitg1 = 0;
          if (kstr < 3) {
            if (esttype_data[kstr] != varargin_1_f3[kstr]) {
              exitg1 = 1;
            } else {
              kstr++;
            }
          } else {
            b_bool = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }

      if (b_bool) {
        kstr = 0;
      } else {
        b_bool = false;
        if (esttype_size[1] == 4) {
          kstr = 0;
          do {
            exitg1 = 0;
            if (kstr < 4) {
              if (esttype_data[kstr] != cv1[kstr]) {
                exitg1 = 1;
              } else {
                kstr++;
              }
            } else {
              b_bool = true;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }

        if (b_bool) {
          kstr = 1;
        } else {
          b_bool = false;
          if (esttype_size[1] == 3) {
            kstr = 0;
            do {
              exitg1 = 0;
              if (kstr < 3) {
                if (esttype_data[kstr] != cv2[kstr]) {
                  exitg1 = 1;
                } else {
                  kstr++;
                }
              } else {
                b_bool = true;
                exitg1 = 1;
              }
            } while (exitg1 == 0);
          }

          if (b_bool) {
            kstr = 2;
          } else {
            b_bool = false;
            if (esttype_size[1] == 5) {
              kstr = 0;
              do {
                exitg1 = 0;
                if (kstr < 5) {
                  if (esttype_data[kstr] != cv3[kstr]) {
                    exitg1 = 1;
                  } else {
                    kstr++;
                  }
                } else {
                  b_bool = true;
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
            }

            if (b_bool) {
              kstr = 3;
            } else {
              kstr = -1;
            }
          }
        }
      }
    }
  }

  emxInit_creal_T(&Pxx, 2);
  switch (kstr) {
   case 0:
    if (options.maxhold) {
      cmethod2_tunableEnvironment[0] = 1.0;
      tmp_data[0] = 1.0;
      localComputeSpectra(x1, tmp_data, xEnd_data, varargin_1, options,
                          esttype_data, esttype_size,
                          cmethod2_tunableEnvironment, Sxx_data, Pxx_size,
                          varargout_2_data, varargout_2_size, units_data,
                          units_size);
      i12 = Pxx->size[0] * Pxx->size[1];
      Pxx->size[0] = Pxx_size[0];
      Pxx->size[1] = Pxx_size[1];
      emxEnsureCapacity_creal_T(Pxx, i12);
      kstr = Pxx_size[0] * Pxx_size[1];
      for (i12 = 0; i12 < kstr; i12++) {
        Pxx->data[i12].re = Sxx_data[i12];
        Pxx->data[i12].im = 0.0;
      }
    } else if (options.minhold) {
      cmethod2_tunableEnvironment[0] = 1.0;
      tmp_data[0] = 1.0;
      b_localComputeSpectra(x1, tmp_data, xEnd_data, varargin_1, options,
                            esttype_data, esttype_size,
                            cmethod2_tunableEnvironment, Sxx_data, Pxx_size,
                            varargout_2_data, varargout_2_size, units_data,
                            units_size);
      i12 = Pxx->size[0] * Pxx->size[1];
      Pxx->size[0] = Pxx_size[0];
      Pxx->size[1] = Pxx_size[1];
      emxEnsureCapacity_creal_T(Pxx, i12);
      kstr = Pxx_size[0] * Pxx_size[1];
      for (i12 = 0; i12 < kstr; i12++) {
        Pxx->data[i12].re = Sxx_data[i12];
        Pxx->data[i12].im = 0.0;
      }
    } else {
      tmp_data[0] = 1.0;
      c_localComputeSpectra(Sxx_data, x1, tmp_data, xEnd_data, varargin_1,
                            options, esttype_data, esttype_size, Pxx,
                            varargout_2_data, varargout_2_size, units_data,
                            units_size);
    }
    break;

   case 1:
    memset(&Sxx_data[0], 0, sizeof(double) << 12);
    tmp_data[0] = 1.0;
    d_localComputeSpectra(Sxx_data, x1, tmp_data, xEnd_data, varargin_1, options,
                          esttype_data, esttype_size, Pxx, varargout_2_data,
                          varargout_2_size, units_data, units_size);
    break;

   case 2:
    tmp_data[0] = 1.0;
    c_localComputeSpectra(Sxx_data, x1, tmp_data, xEnd_data, varargin_1, options,
                          esttype_data, esttype_size, Pxx, varargout_2_data,
                          varargout_2_size, units_data, units_size);
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

  i12 = varargout_1->size[0] * varargout_1->size[1] * varargout_1->size[2];
  varargout_1->size[0] = Pxx->size[0];
  varargout_1->size[1] = Pxx->size[1];
  varargout_1->size[2] = 1;
  emxEnsureCapacity_creal_T(varargout_1, i12);
  kstr = Pxx->size[0] * Pxx->size[1];
  for (i12 = 0; i12 < kstr; i12++) {
    varargout_1->data[i12] = Pxx->data[i12];
  }

  emxFree_creal_T(&Pxx);
}

/* End of code generation (welch.c) */

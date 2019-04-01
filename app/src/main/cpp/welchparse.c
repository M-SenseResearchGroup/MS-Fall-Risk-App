/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * welchparse.c
 *
 * Code generation for function 'welchparse'
 *
 */

/* Include files */
#include <string.h>
#include <math.h>
#include "rt_nonfinite.h"
#include "calibrate.h"
#include "get_calibration.h"
#include "get_classification.h"
#include "get_fall_class.h"
#include "get_features.h"
#include "get_strides.h"
#include "pre_process_feats.h"
#include "welchparse.h"

/* Function Declarations */
static void parse_inputs(const double x1[500], double varargin_4, double x[500],
  double opts[2]);
static void welch_options(double N, double varargin_2, double *options1_nfft,
  double *options1_Fs, boolean_T *options1_maxhold, boolean_T *options1_minhold,
  char options1_range[8]);

/* Function Definitions */
static void parse_inputs(const double x1[500], double varargin_4, double x[500],
  double opts[2])
{
  memcpy(&x[0], &x1[0], 500U * sizeof(double));
  opts[0] = 4096.0;
  opts[1] = varargin_4;
}

static void welch_options(double N, double varargin_2, double *options1_nfft,
  double *options1_Fs, boolean_T *options1_maxhold, boolean_T *options1_minhold,
  char options1_range[8])
{
  double absn;
  boolean_T b0;
  boolean_T b1;
  int eint;
  static const char options_range[8] = { 'o', 'n', 'e', 's', 'i', 'd', 'e', 'd'
  };

  absn = fabs(N);
  b0 = !rtIsInf(absn);
  b1 = !rtIsNaN(absn);
  if (b0 && b1) {
    frexp(absn, &eint);
  }

  *options1_nfft = 4096.0;
  *options1_Fs = varargin_2;
  *options1_maxhold = false;
  *options1_minhold = false;
  for (eint = 0; eint < 8; eint++) {
    options1_range[eint] = options_range[eint];
  }
}

void b_welchparse(const double x1[125], double varargin_4, double x[125], double
                  *k, double *L, double *options_nfft, double *options_Fs,
                  boolean_T *options_maxhold, boolean_T *options_minhold, char
                  options_range[8])
{
  memcpy(&x[0], &x1[0], 125U * sizeof(double));
  *L = 125.0;
  welch_options(125.0, varargin_4, options_nfft, options_Fs, options_maxhold,
                options_minhold, options_range);
  *k = 1.0;
}

void c_welchparse(double varargin_4, double *k, double *L, double *options_nfft,
                  double *options_Fs, boolean_T *options_maxhold, boolean_T
                  *options_minhold, char options_range[8])
{
  *L = 125.0;
  welch_options(125.0, varargin_4, options_nfft, options_Fs, options_maxhold,
                options_minhold, options_range);
  *k = 1.0;
}

void welchparse(const double x1[500], const double varargin_1[63], double
                varargin_4, double x[500], double win[63], double *k, double *L,
                double *options_nfft, double *options_Fs, boolean_T
                *options_maxhold, boolean_T *options_minhold, char
                options_range[8])
{
  double opts[2];
  memcpy(&win[0], &varargin_1[0], 63U * sizeof(double));
  parse_inputs(x1, varargin_4, x, opts);
  *L = 63.0;
  welch_options(63.0, opts[1], options_nfft, options_Fs, options_maxhold,
                options_minhold, options_range);
  *k = 14.0;
}

/* End of code generation (welchparse.c) */

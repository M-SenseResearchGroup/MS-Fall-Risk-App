/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * welchparse.h
 *
 * Code generation for function 'welchparse'
 *
 */

#ifndef WELCHPARSE_H
#define WELCHPARSE_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "getFallClass_types.h"

/* Function Declarations */
extern void b_welchparse(const double x1[125], double varargin_4, double x[125],
  double *k, double *L, double *options_nfft, double *options_Fs, boolean_T
  *options_maxhold, boolean_T *options_minhold, char options_range[8]);
extern void c_welchparse(double varargin_4, double *k, double *L, double
  *options_nfft, double *options_Fs, boolean_T *options_maxhold, boolean_T
  *options_minhold, char options_range[8]);
extern void welchparse(const double x1[500], const double varargin_1[63], double
  varargin_4, double x[500], double win[63], double *k, double *L, double
  *options_nfft, double *options_Fs, boolean_T *options_maxhold, boolean_T
  *options_minhold, char options_range[8]);

#endif

/* End of code generation (welchparse.h) */

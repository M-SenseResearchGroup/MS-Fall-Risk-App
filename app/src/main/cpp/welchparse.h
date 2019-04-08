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
#include "calc_fall_risk_types.h"

/* Function Declarations */
extern void parse_inputs(const double x1_data[], const int x1_size[2], double
  varargin_4, double x_data[], int x_size[1], double *Lx, char winName_data[],
  int winName_size[2], int winParam_size[2], double opts[2]);
extern void segment_info(double *L, double *noverlap);
extern void welch_options(double N, double varargin_2, double *options1_nfft,
  double *options1_Fs, boolean_T *options1_maxhold, boolean_T *options1_minhold,
  char options1_range[8]);

#endif

/* End of code generation (welchparse.h) */

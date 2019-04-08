/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeDFT.h
 *
 * Code generation for function 'computeDFT'
 *
 */

#ifndef COMPUTEDFT_H
#define COMPUTEDFT_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "calc_fall_risk_types.h"

/* Function Declarations */
extern void b_computeDFT(const double xin_data[], const int xin_size[2], double
  varargin_1, emxArray_creal_T *Xx, double f_data[], int f_size[1]);
extern void computeDFT(const double xin_data[], const int xin_size[1], double
  varargin_1, emxArray_creal_T *Xx, double f_data[], int f_size[1]);

#endif

/* End of code generation (computeDFT.h) */

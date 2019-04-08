/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeperiodogram.h
 *
 * Code generation for function 'computeperiodogram'
 *
 */

#ifndef COMPUTEPERIODOGRAM_H
#define COMPUTEPERIODOGRAM_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "calc_fall_risk_types.h"

/* Function Declarations */
extern void b_computeperiodogram(const double x_data[], const int x_size[2],
  const double win_data[], const char esttype_data[], const int esttype_size[2],
  double Fs, emxArray_creal_T *Pxx, double F_data[], int F_size[1]);
extern void c_computeperiodogram(const emxArray_real_T *x, const double win[63],
  const char esttype_data[], const int esttype_size[2], double Fs,
  emxArray_creal_T *Pxx, double F_data[], int F_size[1]);
extern void computeperiodogram(const double x_data[], const int x_size[1], const
  double win_data[], const char esttype_data[], const int esttype_size[2],
  double Fs, emxArray_creal_T *Pxx, double F_data[], int F_size[1]);

#endif

/* End of code generation (computeperiodogram.h) */

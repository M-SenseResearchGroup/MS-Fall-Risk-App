/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xcorr.h
 *
 * Code generation for function 'xcorr'
 *
 */

#ifndef XCORR_H
#define XCORR_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "calc_fall_risk_types.h"

/* Function Declarations */
extern void c_xcorr(const emxArray_real_T *x, emxArray_real_T *c, double
                    lags_data[], int lags_size[2]);
extern void d_xcorr(const double x_data[], const int x_size[2], const
                    emxArray_real_T *varargin_1, emxArray_real_T *c,
                    emxArray_real_T *lags);
extern void xcorr(const double x_data[], const int x_size[2], double c_data[],
                  int c_size[2], double lags_data[], int lags_size[2]);

#endif

/* End of code generation (xcorr.h) */

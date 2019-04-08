/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nan_sum_or_mean.h
 *
 * Code generation for function 'nan_sum_or_mean'
 *
 */

#ifndef NAN_SUM_OR_MEAN_H
#define NAN_SUM_OR_MEAN_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "calc_fall_risk_types.h"

/* Function Declarations */
extern void b_nan_sum_or_mean(const emxArray_real_T *x, double y_data[], int
  y_size[2], int c_data[], int c_size[2]);
extern void nan_sum_or_mean(const double x_data[], const int x_size[2], double
  *y, int *c);

#endif

/* End of code generation (nan_sum_or_mean.h) */

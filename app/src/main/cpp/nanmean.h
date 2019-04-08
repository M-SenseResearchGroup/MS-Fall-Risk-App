/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nanmean.h
 *
 * Code generation for function 'nanmean'
 *
 */

#ifndef NANMEAN_H
#define NANMEAN_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "calc_fall_risk_types.h"

/* Function Declarations */
extern void b_nanmean(const emxArray_real_T *varargin_1, double y_data[], int
                      y_size[2]);
extern double nanmean(const double varargin_1_data[], const int varargin_1_size
                      [2]);

#endif

/* End of code generation (nanmean.h) */

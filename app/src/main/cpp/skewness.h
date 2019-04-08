/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * skewness.h
 *
 * Code generation for function 'skewness'
 *
 */

#ifndef SKEWNESS_H
#define SKEWNESS_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "calc_fall_risk_types.h"

/* Function Declarations */
extern void b_skewness(const emxArray_real_T *x, double s_data[], int s_size[2]);
extern double skewness(const double x_data[], const int x_size[2]);

#endif

/* End of code generation (skewness.h) */

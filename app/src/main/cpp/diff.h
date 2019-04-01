/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * diff.h
 *
 * Code generation for function 'diff'
 *
 */

#ifndef DIFF_H
#define DIFF_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "getFallClass_types.h"

/* Function Declarations */
extern void b_diff(const double x_data[], const int x_size[2], double y_data[],
                   int y_size[2]);
extern void c_diff(const double x_data[], const int x_size[1], double y_data[],
                   int y_size[1]);
extern void d_diff(const double x[500], double y[499]);
extern void diff(const emxArray_creal_T *x, emxArray_creal_T *y);

#endif

/* End of code generation (diff.h) */

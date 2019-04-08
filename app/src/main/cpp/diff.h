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
#include "calc_fall_risk_types.h"

/* Function Declarations */
extern void b_diff(const emxArray_real_T *x, emxArray_real_T *y);
extern void c_diff(const emxArray_real_T *x, emxArray_real_T *y);
extern void d_diff(const emxArray_real_T *x, emxArray_real_T *y);
extern void diff(const emxArray_creal_T *x, emxArray_creal_T *y);

#endif

/* End of code generation (diff.h) */

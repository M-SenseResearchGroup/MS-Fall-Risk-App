/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * extrema.h
 *
 * Code generation for function 'extrema'
 *
 */

#ifndef EXTREMA_H
#define EXTREMA_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "calc_fall_risk_types.h"

/* Function Declarations */
extern void b_extrema(const emxArray_real_T *x, emxArray_real_T *b_max,
                      emxArray_real_T *imax);
extern void c_extrema(const emxArray_real_T *x, emxArray_real_T *b_max,
                      emxArray_real_T *imax);
extern void d_extrema(const emxArray_real_T *x, emxArray_real_T *b_max,
                      emxArray_real_T *imax, emxArray_real_T *b_min,
                      emxArray_real_T *imin);
extern void e_extrema(const emxArray_real_T *x, emxArray_real_T *b_max,
                      emxArray_real_T *imax);
extern void extrema(const emxArray_creal_T *x, emxArray_creal_T *b_max,
                    emxArray_real_T *imax);

#endif

/* End of code generation (extrema.h) */

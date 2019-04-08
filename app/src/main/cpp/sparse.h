/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sparse.h
 *
 * Code generation for function 'sparse'
 *
 */

#ifndef SPARSE_H
#define SPARSE_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "calc_fall_risk_types.h"

/* Function Declarations */
extern void sparse(const double varargin_3[4], emxArray_real_T *y_d,
                   emxArray_int32_T *y_colidx, emxArray_int32_T *y_rowidx);

#endif

/* End of code generation (sparse.h) */

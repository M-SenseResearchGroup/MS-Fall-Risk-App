/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sparse1.h
 *
 * Code generation for function 'sparse1'
 *
 */

#ifndef SPARSE1_H
#define SPARSE1_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "calc_fall_risk_types.h"

/* Type Definitions */
#include "cs.h"

/* Function Declarations */
extern void sparse_mldivide(const emxArray_real_T *A_d, const emxArray_int32_T
  *A_colidx, const emxArray_int32_T *A_rowidx, double b[2]);

#endif

/* End of code generation (sparse1.h) */

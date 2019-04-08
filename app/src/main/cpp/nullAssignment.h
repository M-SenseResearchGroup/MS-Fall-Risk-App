/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nullAssignment.h
 *
 * Code generation for function 'nullAssignment'
 *
 */

#ifndef NULLASSIGNMENT_H
#define NULLASSIGNMENT_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "calc_fall_risk_types.h"

/* Function Declarations */
extern void b_nullAssignment(emxArray_real_T *x, const emxArray_int32_T *idx);
extern void c_nullAssignment(emxArray_real_T *x, const emxArray_boolean_T *idx);
extern void d_nullAssignment(emxArray_real_T *x, const emxArray_int32_T *idx);
extern void e_nullAssignment(emxArray_real_T *x, const emxArray_int32_T *idx);
extern void f_nullAssignment(emxArray_creal_T *x, const emxArray_boolean_T *idx);
extern void g_nullAssignment(emxArray_real_T *x, const emxArray_boolean_T *idx);
extern void h_nullAssignment(emxArray_real_T *x, int idx);
extern void i_nullAssignment(emxArray_real_T *x, int idx);
extern void j_nullAssignment(emxArray_real_T *x);
extern void nullAssignment(const emxArray_creal_T *x, const boolean_T idx_data[],
  const int idx_size[1], emxArray_creal_T *b_x);

#endif

/* End of code generation (nullAssignment.h) */

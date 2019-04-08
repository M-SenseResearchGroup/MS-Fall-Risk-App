/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * any1.h
 *
 * Code generation for function 'any1'
 *
 */

#ifndef ANY1_H
#define ANY1_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "calc_fall_risk_types.h"

/* Function Declarations */
extern boolean_T any(const boolean_T x[2]);
extern void b_any(const emxArray_creal_T *x, boolean_T y_data[], int y_size[3]);
extern boolean_T c_any(const emxArray_real_T *x);
extern boolean_T d_any(const emxArray_real_T *x);
extern void e_any(const emxArray_real_T *x, boolean_T y_data[], int y_size[2]);

#endif

/* End of code generation (any1.h) */

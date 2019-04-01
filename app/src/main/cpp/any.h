/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * any.h
 *
 * Code generation for function 'any'
 *
 */

#ifndef ANY_H
#define ANY_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "getFallClass_types.h"

/* Function Declarations */
extern boolean_T any(const boolean_T x[2]);
extern void b_any(const emxArray_creal_T *x, boolean_T y_data[], int y_size[3]);
extern boolean_T c_any(const double x_data[], const int x_size[2]);
extern boolean_T d_any(const double x_data[], const int x_size[1]);
extern boolean_T e_any(const double x[499]);

#endif

/* End of code generation (any.h) */

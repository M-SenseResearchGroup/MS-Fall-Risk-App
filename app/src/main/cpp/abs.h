/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * abs.h
 *
 * Code generation for function 'abs'
 *
 */

#ifndef ABS_H
#define ABS_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "calc_fall_risk_types.h"

/* Function Declarations */
extern void b_abs(const creal_T x_data[], const int x_size[1], double y_data[],
                  int y_size[1]);
extern void c_abs(const emxArray_real_T *x, emxArray_real_T *y);

#endif

/* End of code generation (abs.h) */

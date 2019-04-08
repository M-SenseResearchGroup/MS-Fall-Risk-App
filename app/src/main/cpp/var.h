/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * var.h
 *
 * Code generation for function 'var'
 *
 */

#ifndef VAR_H
#define VAR_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "calc_fall_risk_types.h"

/* Function Declarations */
extern void b_var(const emxArray_real_T *x, double y_data[], int y_size[2]);
extern double var(const double x_data[], const int x_size[2]);

#endif

/* End of code generation (var.h) */

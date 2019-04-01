/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sign.h
 *
 * Code generation for function 'sign'
 *
 */

#ifndef SIGN_H
#define SIGN_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "getFallClass_types.h"

/* Function Declarations */
extern void b_sign(emxArray_creal_T *x);
extern void d_sign(double x_data[], int x_size[2]);
extern void e_sign(double *x);
extern void f_sign(double x_data[], int x_size[1]);

#endif

/* End of code generation (sign.h) */

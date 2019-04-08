/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ifft.h
 *
 * Code generation for function 'ifft'
 *
 */

#ifndef IFFT_H
#define IFFT_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "calc_fall_risk_types.h"

/* Function Declarations */
extern void b_ifft(const emxArray_creal_T *x, emxArray_creal_T *y);
extern void ifft(const double x_data[], const int x_size[1], creal_T y_data[],
                 int y_size[1]);

#endif

/* End of code generation (ifft.h) */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fft.h
 *
 * Code generation for function 'fft'
 *
 */

#ifndef FFT_H
#define FFT_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "getFallClass_types.h"

/* Function Declarations */
extern void b_fft(const double x_data[], const int x_size[2], emxArray_creal_T
                  *y);
extern void fft(const double x_data[], const int x_size[1], emxArray_creal_T *y);

#endif

/* End of code generation (fft.h) */

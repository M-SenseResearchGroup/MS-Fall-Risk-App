/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fft1.h
 *
 * Code generation for function 'fft1'
 *
 */

#ifndef FFT1_H
#define FFT1_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "getFallClass_types.h"

/* Function Declarations */
extern void b_r2br_r2dit_trig(const double x_data[], const int x_size[2], const
  double costab_data[], const double sintab_data[], emxArray_creal_T *y);
extern void generate_twiddle_tables(double costab_data[], int costab_size[2],
  double sintab_data[], int sintab_size[2], int sintabinv_size[2]);
extern void r2br_r2dit_trig(const double x_data[], const int x_size[1], const
  double costab_data[], const double sintab_data[], emxArray_creal_T *y);

#endif

/* End of code generation (fft1.h) */

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
#include "calc_fall_risk_types.h"

/* Function Declarations */
extern void b_dobluesteinfft(const emxArray_real_T *x, int N2, int n1, const
  emxArray_real_T *costab, const emxArray_real_T *sintab, const emxArray_real_T *
  sintabinv, emxArray_creal_T *y);
extern void b_generate_twiddle_tables(int nRows, boolean_T useRadix2, double
  costab_data[], int costab_size[2], double sintab_data[], int sintab_size[2],
  double sintabinv_data[], int sintabinv_size[2]);
extern void b_r2br_r2dit_trig(const emxArray_creal_T *x, int n1_unsigned, const
  emxArray_real_T *costab, const emxArray_real_T *sintab, emxArray_creal_T *y);
extern void c_dobluesteinfft(const double x_data[], const int x_size[1], int N2,
  int n1, const double costab_data[], const int costab_size[2], const double
  sintab_data[], const int sintab_size[2], const double sintabinv_data[], const
  int sintabinv_size[2], creal_T y_data[], int y_size[1]);
extern void c_generate_twiddle_tables(int nRows, boolean_T useRadix2,
  emxArray_real_T *costab, emxArray_real_T *sintab, emxArray_real_T *sintabinv);
extern void c_r2br_r2dit_trig(const emxArray_real_T *x, int n1_unsigned, const
  emxArray_real_T *costab, const emxArray_real_T *sintab, emxArray_creal_T *y);
extern void d_dobluesteinfft(const emxArray_real_T *x, int N2, int n1, const
  double costab_data[], const int costab_size[2], const double sintab_data[],
  const int sintab_size[2], const double sintabinv_data[], const int
  sintabinv_size[2], emxArray_creal_T *y);
extern void d_r2br_r2dit_trig(const double x_data[], const int x_size[1], int
  n1_unsigned, const double costab_data[], const double sintab_data[], creal_T
  y_data[], int y_size[1]);
extern void dobluesteinfft(const emxArray_real_T *x, int N2, int n1, const
  emxArray_real_T *costab, const emxArray_real_T *sintab, const emxArray_real_T *
  sintabinv, emxArray_creal_T *y);
extern void e_dobluesteinfft(const emxArray_creal_T *x, int N2, int n1, const
  double costab_data[], const int costab_size[2], const double sintab_data[],
  const int sintab_size[2], const double sintabinv_data[], const int
  sintabinv_size[2], emxArray_creal_T *y);
extern void e_r2br_r2dit_trig(const emxArray_real_T *x, int n1_unsigned, const
  double costab_data[], const double sintab_data[], emxArray_creal_T *y);
extern void f_dobluesteinfft(const emxArray_creal_T *x, int N2, int n1, const
  emxArray_real_T *costab, const emxArray_real_T *sintab, const emxArray_real_T *
  sintabinv, emxArray_creal_T *y);
extern void f_r2br_r2dit_trig(const emxArray_creal_T *x, int n1_unsigned, const
  double costab_data[], const double sintab_data[], emxArray_creal_T *y);
extern void generate_twiddle_tables(int nRows, boolean_T useRadix2,
  emxArray_real_T *costab, emxArray_real_T *sintab, emxArray_real_T *sintabinv);
extern void get_algo_sizes(int n1, boolean_T useRadix2, int *N2blue, int *nRows);
extern void r2br_r2dit_trig(const emxArray_real_T *x, int n1_unsigned, const
  emxArray_real_T *costab, const emxArray_real_T *sintab, emxArray_creal_T *y);

#endif

/* End of code generation (fft1.h) */

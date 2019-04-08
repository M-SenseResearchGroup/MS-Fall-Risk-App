/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * bsxfun.h
 *
 * Code generation for function 'bsxfun'
 *
 */

#ifndef BSXFUN_H
#define BSXFUN_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "calc_fall_risk_types.h"

/* Function Declarations */
extern void b_bsxfun(const emxArray_real_T *a, const double b_data[], const int
                     b_size[2], emxArray_real_T *c);
extern void bsxfun(const double a_data[], const int a_size[2], double b, double
                   c_data[], int c_size[2]);
extern void c_bsxfun(const double a_data[], const int a_size[1], double c_data[],
                     int c_size[1]);
extern void d_bsxfun(const double a_data[], const int a_size[2], double c_data[],
                     int c_size[2]);
extern void e_bsxfun(const emxArray_real_T *a, const emxArray_real_T *b,
                     emxArray_real_T *c);
extern void f_bsxfun(const emxArray_real_T *a, const double b_data[], const int
                     b_size[1], emxArray_real_T *c);
extern void g_bsxfun(const emxArray_real_T *a, double c[63]);

#endif

/* End of code generation (bsxfun.h) */

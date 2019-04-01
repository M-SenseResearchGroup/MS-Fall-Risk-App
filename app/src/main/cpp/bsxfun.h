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
#include "getFallClass_types.h"

/* Function Declarations */
extern void b_bsxfun(const double a_data[], const int a_size[2], double c_data[],
                     int c_size[2]);
extern void bsxfun(const double a_data[], const int a_size[1], double c[125]);
extern void c_bsxfun(const double a_data[], const int a_size[1], double c[63]);
extern void d_bsxfun(const double a_data[], const int a_size[2], double c_data[],
                     int c_size[2]);

#endif

/* End of code generation (bsxfun.h) */

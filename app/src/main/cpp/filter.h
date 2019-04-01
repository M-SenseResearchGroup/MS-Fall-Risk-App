/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * filter.h
 *
 * Code generation for function 'filter'
 *
 */

#ifndef FILTER_H
#define FILTER_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "getFallClass_types.h"

/* Function Declarations */
extern void b_filter(double b[3], double a[3], const double x[512], const double
                     zi[2], double y[512]);
extern void filter(double b[3], double a[3], const double x[137], const double
                   zi[2], double y[137]);

#endif

/* End of code generation (filter.h) */

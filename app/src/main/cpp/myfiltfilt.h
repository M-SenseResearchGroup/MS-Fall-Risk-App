/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * myfiltfilt.h
 *
 * Code generation for function 'myfiltfilt'
 *
 */

#ifndef MYFILTFILT_H
#define MYFILTFILT_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "calc_fall_risk_types.h"

/* Function Declarations */
extern void myfiltfilt(const double b[3], const double a[3], emxArray_real_T *x,
  emxArray_real_T *y);

#endif

/* End of code generation (myfiltfilt.h) */

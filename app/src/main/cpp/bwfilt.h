/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * bwfilt.h
 *
 * Code generation for function 'bwfilt'
 *
 */

#ifndef BWFILT_H
#define BWFILT_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "calc_fall_risk_types.h"

/* Function Declarations */
extern void b_bwfilt(const emxArray_real_T *in, const emxArray_real_T *cf,
                     double sf, emxArray_real_T *out);
extern void bwfilt(const double in_data[], const int in_size[2], double sf,
                   emxArray_real_T *out);

#endif

/* End of code generation (bwfilt.h) */

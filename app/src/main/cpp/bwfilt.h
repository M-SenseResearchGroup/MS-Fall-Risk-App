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
#include "getFallClass_types.h"

/* Function Declarations */
extern void b_bwfilt(const double in[500], const emxArray_real_T *cf, double sf,
                     double out[500]);
extern void bwfilt(const double in[125], double sf, double out[125]);

#endif

/* End of code generation (bwfilt.h) */

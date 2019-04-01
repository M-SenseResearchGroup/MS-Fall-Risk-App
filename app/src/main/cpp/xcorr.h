/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xcorr.h
 *
 * Code generation for function 'xcorr'
 *
 */

#ifndef XCORR_H
#define XCORR_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "getFallClass_types.h"

/* Function Declarations */
extern void b_xcorr(const double x[125], const double varargin_1[125], double c
                    [249], double lags[249]);
extern void xcorr(const double x[125], double c[249], double lags[249]);

#endif

/* End of code generation (xcorr.h) */

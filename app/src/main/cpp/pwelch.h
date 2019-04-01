/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pwelch.h
 *
 * Code generation for function 'pwelch'
 *
 */

#ifndef PWELCH_H
#define PWELCH_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "getFallClass_types.h"

/* Function Declarations */
extern void b_pwelch(const double x[125], double varargin_4, emxArray_creal_T
                     *varargout_1, double varargout_2_data[], int
                     varargout_2_size[1]);
extern void c_pwelch(const double x[500], double varargin_4, emxArray_creal_T
                     *varargout_1, double varargout_2_data[], int
                     varargout_2_size[1]);
extern void pwelch(const double x[125], double varargin_4, emxArray_creal_T
                   *varargout_1, double varargout_2_data[], int
                   varargout_2_size[1]);

#endif

/* End of code generation (pwelch.h) */

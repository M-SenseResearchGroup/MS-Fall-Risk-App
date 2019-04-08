/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * welch.h
 *
 * Code generation for function 'welch'
 *
 */

#ifndef WELCH_H
#define WELCH_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "calc_fall_risk_types.h"

/* Function Declarations */
extern void b_welch(const emxArray_real_T *x, const char esttype_data[], const
                    int esttype_size[2], const double varargin_1[63], double
                    varargin_4, emxArray_creal_T *varargout_1, double
                    varargout_2_data[], int varargout_2_size[1]);
extern void welch(const double x_data[], const int x_size[2], const char
                  esttype_data[], const int esttype_size[2], const double
                  varargin_1_data[], double varargin_4, emxArray_creal_T
                  *varargout_1, double varargout_2_data[], int varargout_2_size
                  [1]);

#endif

/* End of code generation (welch.h) */

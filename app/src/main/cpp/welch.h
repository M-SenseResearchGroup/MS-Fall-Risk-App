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
#include "getFallClass_types.h"

/* Function Declarations */
extern void b_welch(const double x[125], const char esttype_data[], const int
                    esttype_size[2], const double varargin_1[125], double
                    varargin_4, emxArray_creal_T *varargout_1, double
                    varargout_2_data[], int varargout_2_size[1]);
extern void c_welch(const double x[500], const char esttype_data[], const int
                    esttype_size[2], const double varargin_1[63], double
                    varargin_4, emxArray_creal_T *varargout_1, double
                    varargout_2_data[], int varargout_2_size[1]);
extern void welch(const double x[125], const char esttype_data[], const int
                  esttype_size[2], const double varargin_1[125], double
                  varargin_4, emxArray_creal_T *varargout_1, double
                  varargout_2_data[], int varargout_2_size[1]);

#endif

/* End of code generation (welch.h) */

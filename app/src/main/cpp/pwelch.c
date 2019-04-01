/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pwelch.c
 *
 * Code generation for function 'pwelch'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calibrate.h"
#include "get_calibration.h"
#include "get_classification.h"
#include "get_fall_class.h"
#include "get_features.h"
#include "get_strides.h"
#include "pre_process_feats.h"
#include "pwelch.h"
#include "welch.h"
#include "psdesttype.h"
#include <string.h>

/* Type Definitions */
#ifndef typedef_cell_29
#define typedef_cell_29

typedef struct {
  double f1[125];
  double f3;
  double f4;
} cell_29;

#endif                                 /*typedef_cell_29*/

#ifndef typedef_cell_48
#define typedef_cell_48

typedef struct {
  double f1[63];
  double f3;
  double f4;
} cell_48;

#endif                                 /*typedef_cell_48*/

/* Function Definitions */
void b_pwelch(const double x[125], double varargin_4, emxArray_creal_T
              *varargout_1, double varargout_2_data[], int varargout_2_size[1])
{
  int i;
  char esttype_data[5];
  int esttype_size[2];
  cell_29 inputArgs;
  for (i = 0; i < 125; i++) {
    inputArgs.f1[i] = 1.0;
  }

  psdesttype(esttype_data, esttype_size);
  b_welch(x, esttype_data, esttype_size, inputArgs.f1, varargin_4, varargout_1,
          varargout_2_data, varargout_2_size);
}

void c_pwelch(const double x[500], double varargin_4, emxArray_creal_T
              *varargout_1, double varargout_2_data[], int varargout_2_size[1])
{
  int i;
  char esttype_data[5];
  int esttype_size[2];
  cell_48 inputArgs;
  for (i = 0; i < 63; i++) {
    inputArgs.f1[i] = 1.0;
  }

  psdesttype(esttype_data, esttype_size);
  c_welch(x, esttype_data, esttype_size, inputArgs.f1, varargin_4, varargout_1,
          varargout_2_data, varargout_2_size);
}

void pwelch(const double x[125], double varargin_4, emxArray_creal_T
            *varargout_1, double varargout_2_data[], int varargout_2_size[1])
{
  int i;
  char esttype_data[5];
  int esttype_size[2];
  cell_29 inputArgs;
  for (i = 0; i < 125; i++) {
    inputArgs.f1[i] = 1.0;
  }

  psdesttype(esttype_data, esttype_size);
  welch(x, esttype_data, esttype_size, inputArgs.f1, varargin_4, varargout_1,
        varargout_2_data, varargout_2_size);
}

/* End of code generation (pwelch.c) */

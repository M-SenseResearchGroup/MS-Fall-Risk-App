/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pwelch.cpp
 *
 * Code generation for function 'pwelch'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "pwelch.h"
#include "welch.h"
#include "psdesttype.h"

/* Type Definitions */
struct emxArray_real_T_125
{
  double data[125];
  int size[1];
};

struct s0ZMlmVpmTV2MKrY7r5n1I_tag
{
  emxArray_real_T_125 f1;
  double f3;
  double f4;
};

typedef s0ZMlmVpmTV2MKrY7r5n1I_tag cell_7;

/* Function Definitions */
void pwelch(const double x_data[], const int x_size[2], const double
            varargin_1_data[], double varargin_4, emxArray_creal_T *varargout_1,
            double varargout_2_data[], int varargout_2_size[1])
{
  cell_7 inputArgs;
  char esttype_data[5];
  int esttype_size[2];
  memcpy(&inputArgs.f1.data[0], &varargin_1_data[0], 125U * sizeof(double));
  psdesttype(esttype_data, esttype_size);
  welch(x_data, x_size, esttype_data, esttype_size, inputArgs.f1.data,
        varargin_4, varargout_1, varargout_2_data, varargout_2_size);
}

/* End of code generation (pwelch.cpp) */

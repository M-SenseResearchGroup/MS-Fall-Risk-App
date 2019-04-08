/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeDFT.cpp
 *
 * Code generation for function 'computeDFT'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "computeDFT.h"
#include "psdfreqvec.h"
#include "fft.h"
#include <string.h>

/* Function Definitions */
void b_computeDFT(const double xin_data[], const int xin_size[2], double
                  varargin_1, emxArray_creal_T *Xx, double f_data[], int f_size
                  [1])
{
  b_fft(xin_data, xin_size, Xx);
  psdfreqvec(varargin_1, f_data, f_size);
}

void computeDFT(const double xin_data[], const int xin_size[1], double
                varargin_1, emxArray_creal_T *Xx, double f_data[], int f_size[1])
{
  fft(xin_data, xin_size, Xx);
  psdfreqvec(varargin_1, f_data, f_size);
}

/* End of code generation (computeDFT.cpp) */

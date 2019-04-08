/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * welchparse.cpp
 *
 * Code generation for function 'welchparse'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "welchparse.h"
#include "nextpow2.h"

/* Function Definitions */
void parse_inputs(const double x1_data[], const int x1_size[2], double
                  varargin_4, double x_data[], int x_size[1], double *Lx, char
                  winName_data[], int winName_size[2], int winParam_size[2],
                  double opts[2])
{
  int i100;
  static const char cv10[12] = { 'U', 's', 'e', 'r', ' ', 'D', 'e', 'f', 'i',
    'n', 'e', 'd' };

  x_size[0] = x1_size[1];
  if (0 <= x1_size[1] - 1) {
    memcpy(&x_data[0], &x1_data[0], (unsigned int)(x1_size[1] * static_cast<int>
            (sizeof(double))));
  }

  *Lx = x1_size[1];
  opts[0] = 4096.0;
  opts[1] = varargin_4;
  winName_size[0] = 1;
  winName_size[1] = 12;
  for (i100 = 0; i100 < 12; i100++) {
    winName_data[i100] = cv10[i100];
  }

  winParam_size[0] = 1;
  winParam_size[1] = 0;
}

void segment_info(double *L, double *noverlap)
{
  *L = 125.0;
  *noverlap = 62.0;
}

void welch_options(double N, double varargin_2, double *options1_nfft, double
                   *options1_Fs, boolean_T *options1_maxhold, boolean_T
                   *options1_minhold, char options1_range[8])
{
  int i14;
  static const char options_range[8] = { 'o', 'n', 'e', 's', 'i', 'd', 'e', 'd'
  };

  nextpow2(N);
  *options1_nfft = 4096.0;
  *options1_Fs = varargin_2;
  *options1_maxhold = false;
  *options1_minhold = false;
  for (i14 = 0; i14 < 8; i14++) {
    options1_range[i14] = options_range[i14];
  }
}

/* End of code generation (welchparse.cpp) */

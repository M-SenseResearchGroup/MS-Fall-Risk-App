/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * psdfreqvec.c
 *
 * Code generation for function 'psdfreqvec'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "calibrate.h"
#include "get_calibration.h"
#include "get_classification.h"
#include "get_fall_class.h"
#include "get_features.h"
#include "get_strides.h"
#include "pre_process_feats.h"
#include "psdfreqvec.h"

/* Function Definitions */
void psdfreqvec(double varargin_4, double w_data[], int w_size[1])
{
  double Fs;
  double freq_res;
  int i15;
  double w1_data[4096];
  Fs = varargin_4;
  if (rtIsNaN(varargin_4)) {
    Fs = 6.2831853071795862;
  }

  freq_res = Fs / 4096.0;
  for (i15 = 0; i15 < 4096; i15++) {
    w1_data[i15] = freq_res * (double)i15;
  }

  w1_data[2048] = Fs / 2.0;
  w1_data[4095] = Fs - freq_res;
  w_size[0] = 4096;
  memcpy(&w_data[0], &w1_data[0], sizeof(double) << 12);
}

/* End of code generation (psdfreqvec.c) */

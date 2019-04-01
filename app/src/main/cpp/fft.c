/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fft.c
 *
 * Code generation for function 'fft'
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
#include "fft.h"
#include "fft1.h"
#include <string.h>

/* Function Definitions */
void b_fft(const double x_data[], const int x_size[2], emxArray_creal_T *y)
{
  double costab_data[2049];
  int costab_size[2];
  double sintab_data[2049];
  int sintab_size[2];
  int sintabinv_size[2];
  generate_twiddle_tables(costab_data, costab_size, sintab_data, sintab_size,
    sintabinv_size);
  b_r2br_r2dit_trig(x_data, x_size, costab_data, sintab_data, y);
}

void fft(const double x_data[], const int x_size[1], emxArray_creal_T *y)
{
  double costab_data[2049];
  int costab_size[2];
  double sintab_data[2049];
  int sintab_size[2];
  int sintabinv_size[2];
  generate_twiddle_tables(costab_data, costab_size, sintab_data, sintab_size,
    sintabinv_size);
  r2br_r2dit_trig(x_data, x_size, costab_data, sintab_data, y);
}

/* End of code generation (fft.c) */

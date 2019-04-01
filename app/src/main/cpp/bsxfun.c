/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * bsxfun.c
 *
 * Code generation for function 'bsxfun'
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
#include "bsxfun.h"
#include <string.h>

/* Function Definitions */
void b_bsxfun(const double a_data[], const int a_size[2], double c_data[], int
              c_size[2])
{
  int acoef;
  int k;
  c_size[0] = 125;
  c_size[1] = 1;
  acoef = (a_size[0] != 1);
  for (k = 0; k < 125; k++) {
    c_data[k] = a_data[acoef * k];
  }
}

void bsxfun(const double a_data[], const int a_size[1], double c[125])
{
  int acoef;
  int k;
  acoef = (a_size[0] != 1);
  for (k = 0; k < 125; k++) {
    c[k] = a_data[acoef * k];
  }
}

void c_bsxfun(const double a_data[], const int a_size[1], double c[63])
{
  int acoef;
  int k;
  acoef = (a_size[0] != 1);
  for (k = 0; k < 63; k++) {
    c[k] = a_data[acoef * k];
  }
}

void d_bsxfun(const double a_data[], const int a_size[2], double c_data[], int
              c_size[2])
{
  int acoef;
  int k;
  c_size[0] = 63;
  c_size[1] = 1;
  acoef = (a_size[0] != 1);
  for (k = 0; k < 63; k++) {
    c_data[k] = a_data[acoef * k];
  }
}

/* End of code generation (bsxfun.c) */

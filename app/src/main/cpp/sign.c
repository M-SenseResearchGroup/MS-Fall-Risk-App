/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sign.c
 *
 * Code generation for function 'sign'
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
#include "sign.h"
#include "sign1.h"
#include <string.h>

/* Function Definitions */
void b_sign(emxArray_creal_T *x)
{
  int nx;
  int k;
  nx = x->size[0];
  for (k = 0; k < nx; k++) {
    c_sign(&x->data[k]);
  }
}

void d_sign(double x_data[], int x_size[2])
{
  int nx;
  int k;
  double x;
  nx = x_size[1];
  for (k = 0; k < nx; k++) {
    x = x_data[k];
    if (x_data[k] < 0.0) {
      x = -1.0;
    } else if (x_data[k] > 0.0) {
      x = 1.0;
    } else {
      if (x_data[k] == 0.0) {
        x = 0.0;
      }
    }

    x_data[k] = x;
  }
}

void e_sign(double *x)
{
  if (*x < 0.0) {
    *x = -1.0;
  } else if (*x > 0.0) {
    *x = 1.0;
  } else {
    if (*x == 0.0) {
      *x = 0.0;
    }
  }
}

void f_sign(double x_data[], int x_size[1])
{
  int nx;
  int k;
  double x;
  nx = x_size[0];
  for (k = 0; k < nx; k++) {
    x = x_data[k];
    if (x_data[k] < 0.0) {
      x = -1.0;
    } else if (x_data[k] > 0.0) {
      x = 1.0;
    } else {
      if (x_data[k] == 0.0) {
        x = 0.0;
      }
    }

    x_data[k] = x;
  }
}

/* End of code generation (sign.c) */

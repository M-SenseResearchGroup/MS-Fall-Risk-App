/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sign.cpp
 *
 * Code generation for function 'sign'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
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

void d_sign(emxArray_real_T *x)
{
  int nx;
  int k;
  double b_x;
  nx = x->size[1];
  for (k = 0; k < nx; k++) {
    b_x = x->data[k];
    if (x->data[k] < 0.0) {
      b_x = -1.0;
    } else if (x->data[k] > 0.0) {
      b_x = 1.0;
    } else {
      if (x->data[k] == 0.0) {
        b_x = 0.0;
      }
    }

    x->data[k] = b_x;
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

void f_sign(emxArray_real_T *x)
{
  int nx;
  int k;
  double b_x;
  nx = x->size[0];
  for (k = 0; k < nx; k++) {
    b_x = x->data[k];
    if (x->data[k] < 0.0) {
      b_x = -1.0;
    } else if (x->data[k] > 0.0) {
      b_x = 1.0;
    } else {
      if (x->data[k] == 0.0) {
        b_x = 0.0;
      }
    }

    x->data[k] = b_x;
  }
}

/* End of code generation (sign.cpp) */

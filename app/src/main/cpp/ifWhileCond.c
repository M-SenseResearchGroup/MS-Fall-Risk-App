/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ifWhileCond.c
 *
 * Code generation for function 'ifWhileCond'
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
#include "ifWhileCond.h"
#include <string.h>

/* Function Definitions */
boolean_T b_ifWhileCond(const emxArray_boolean_T *x)
{
  boolean_T y;
  int k;
  boolean_T exitg1;
  y = (x->size[0] != 0);
  if (y) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= x->size[0] - 1)) {
      if (!x->data[k]) {
        y = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return y;
}

boolean_T c_ifWhileCond(const boolean_T x_data[], const int x_size[2])
{
  boolean_T y;
  int k;
  boolean_T exitg1;
  y = (x_size[1] != 0);
  if (y) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= x_size[1] - 1)) {
      if (!x_data[k]) {
        y = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return y;
}

boolean_T ifWhileCond(const boolean_T x_data[], const int x_size[3])
{
  boolean_T y;
  int k;
  boolean_T exitg1;
  y = (x_size[1] != 0);
  if (y) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= x_size[1] - 1)) {
      if (!x_data[k]) {
        y = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return y;
}

/* End of code generation (ifWhileCond.c) */

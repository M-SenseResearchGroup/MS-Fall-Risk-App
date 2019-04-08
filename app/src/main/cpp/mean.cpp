/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mean.cpp
 *
 * Code generation for function 'mean'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "mean.h"
#include "calc_fall_risk_emxutil.h"
#include "combineVectorElements.h"
#include <string.h>

/* Function Definitions */
void b_mean(const emxArray_real_T *x, double y_data[], int y_size[2])
{
  emxArray_real_T *r14;
  int b_x;
  int loop_ub;
  int i39;
  emxInit_real_T(&r14, 2);
  combineVectorElements(x, r14);
  y_size[0] = 1;
  y_size[1] = r14->size[1];
  b_x = x->size[0];
  loop_ub = r14->size[0] * r14->size[1];
  for (i39 = 0; i39 < loop_ub; i39++) {
    y_data[i39] = r14->data[i39] / static_cast<double>(b_x);
  }

  emxFree_real_T(&r14);
}

double mean(const emxArray_real_T *x)
{
  double y;
  int vlen;
  int k;
  vlen = x->size[1];
  if (x->size[1] == 0) {
    y = 0.0;
  } else {
    y = x->data[0];
    for (k = 2; k <= vlen; k++) {
      y += x->data[k - 1];
    }
  }

  y /= static_cast<double>(x->size[1]);
  return y;
}

/* End of code generation (mean.cpp) */

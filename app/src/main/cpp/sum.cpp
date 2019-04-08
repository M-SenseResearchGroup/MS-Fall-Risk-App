/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sum.cpp
 *
 * Code generation for function 'sum'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "sum.h"

/* Function Definitions */
double b_sum(const double x_data[])
{
  double y;
  int k;
  y = x_data[0];
  for (k = 0; k < 124; k++) {
    y += x_data[k + 1];
  }

  return y;
}

void sum(const emxArray_real_T *x, double y_data[], int y_size[2])
{
  int vlen;
  int npages;
  short sz_idx_1;
  int i;
  int xpageoffset;
  int k;
  vlen = x->size[0];
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    sz_idx_1 = static_cast<short>(x->size[1]);
    y_size[0] = 1;
    y_size[1] = sz_idx_1;
    if (0 <= sz_idx_1 - 1) {
      memset(&y_data[0], 0, (unsigned int)(sz_idx_1 * static_cast<int>(sizeof
               (double))));
    }
  } else {
    npages = x->size[1];
    y_size[0] = 1;
    y_size[1] = static_cast<short>(x->size[1]);
    for (i = 0; i < npages; i++) {
      xpageoffset = i * x->size[0];
      y_data[i] = x->data[xpageoffset];
      for (k = 2; k <= vlen; k++) {
        y_data[i] += x->data[(xpageoffset + k) - 1];
      }
    }
  }
}

/* End of code generation (sum.cpp) */

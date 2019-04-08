/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * combineVectorElements.cpp
 *
 * Code generation for function 'combineVectorElements'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "combineVectorElements.h"
#include "calc_fall_risk_emxutil.h"
#include <string.h>

/* Function Definitions */
void combineVectorElements(const emxArray_real_T *x, emxArray_real_T *y)
{
  int vlen;
  int npages;
  unsigned int sz_idx_1;
  int xpageoffset;
  int i;
  int k;
  vlen = x->size[0];
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    sz_idx_1 = static_cast<unsigned int>(x->size[1]);
    xpageoffset = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = static_cast<int>(sz_idx_1);
    emxEnsureCapacity_real_T(y, xpageoffset);
    i = static_cast<int>(sz_idx_1);
    for (xpageoffset = 0; xpageoffset < i; xpageoffset++) {
      y->data[xpageoffset] = 0.0;
    }
  } else {
    npages = x->size[1];
    xpageoffset = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = x->size[1];
    emxEnsureCapacity_real_T(y, xpageoffset);
    for (i = 0; i < npages; i++) {
      xpageoffset = i * x->size[0];
      y->data[i] = x->data[xpageoffset];
      for (k = 2; k <= vlen; k++) {
        y->data[i] += x->data[(xpageoffset + k) - 1];
      }
    }
  }
}

/* End of code generation (combineVectorElements.cpp) */

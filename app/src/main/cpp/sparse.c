/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sparse.c
 *
 * Code generation for function 'sparse'
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
#include "sparse.h"
#include "getFallClass_emxutil.h"
#include "introsort.h"
#include <string.h>

/* Function Definitions */
void sparse(const double varargin_3[4], emxArray_real_T *y_d, emxArray_int32_T
            *y_colidx, emxArray_int32_T *y_rowidx)
{
  int sortedIndices[4];
  cell_wrap_28 this_tunableEnvironment[2];
  signed char cidxInt[4];
  static const signed char a[4] = { 1, 1, 2, 2 };

  signed char ridxInt[4];
  static const signed char b[4] = { 1, 2, 2, 1 };

  int cptr;
  int ridx;
  double val;
  int currRowIdx;
  sortedIndices[0] = 1;
  this_tunableEnvironment[0].f1[0] = 1;
  this_tunableEnvironment[1].f1[0] = 1;
  sortedIndices[1] = 2;
  this_tunableEnvironment[0].f1[1] = 1;
  this_tunableEnvironment[1].f1[1] = 2;
  sortedIndices[2] = 3;
  this_tunableEnvironment[0].f1[2] = 2;
  this_tunableEnvironment[1].f1[2] = 2;
  sortedIndices[3] = 4;
  this_tunableEnvironment[0].f1[3] = 2;
  this_tunableEnvironment[1].f1[3] = 1;
  introsort(sortedIndices, this_tunableEnvironment);
  cidxInt[0] = a[sortedIndices[0] - 1];
  ridxInt[0] = b[sortedIndices[0] - 1];
  cidxInt[1] = a[sortedIndices[1] - 1];
  ridxInt[1] = b[sortedIndices[1] - 1];
  cidxInt[2] = a[sortedIndices[2] - 1];
  ridxInt[2] = b[sortedIndices[2] - 1];
  cidxInt[3] = a[sortedIndices[3] - 1];
  ridxInt[3] = b[sortedIndices[3] - 1];
  cptr = y_d->size[0];
  y_d->size[0] = 4;
  emxEnsureCapacity_real_T(y_d, cptr);
  y_d->data[0] = 0.0;
  y_d->data[1] = 0.0;
  y_d->data[2] = 0.0;
  y_d->data[3] = 0.0;
  cptr = y_colidx->size[0];
  y_colidx->size[0] = 3;
  emxEnsureCapacity_int32_T(y_colidx, cptr);
  y_colidx->data[0] = 1;
  cptr = y_rowidx->size[0];
  y_rowidx->size[0] = 4;
  emxEnsureCapacity_int32_T(y_rowidx, cptr);
  y_rowidx->data[0] = 0;
  y_rowidx->data[1] = 0;
  y_rowidx->data[2] = 0;
  y_rowidx->data[3] = 0;
  cptr = 0;
  while ((cptr + 1 <= 4) && (cidxInt[cptr] == 1)) {
    y_rowidx->data[cptr] = ridxInt[cptr];
    cptr++;
  }

  y_colidx->data[1] = cptr + 1;
  while ((cptr + 1 <= 4) && (cidxInt[cptr] == 2)) {
    y_rowidx->data[cptr] = ridxInt[cptr];
    cptr++;
  }

  y_colidx->data[2] = cptr + 1;
  y_d->data[0] = varargin_3[sortedIndices[0] - 1];
  y_d->data[1] = varargin_3[sortedIndices[1] - 1];
  y_d->data[2] = varargin_3[sortedIndices[2] - 1];
  y_d->data[3] = varargin_3[sortedIndices[3] - 1];
  cptr = 1;
  ridx = y_colidx->data[0];
  y_colidx->data[0] = 1;
  while (ridx < y_colidx->data[1]) {
    val = 0.0;
    currRowIdx = y_rowidx->data[ridx - 1];
    while ((ridx < y_colidx->data[1]) && (y_rowidx->data[ridx - 1] == currRowIdx))
    {
      val += y_d->data[ridx - 1];
      ridx++;
    }

    if (val != 0.0) {
      y_d->data[cptr - 1] = val;
      y_rowidx->data[cptr - 1] = currRowIdx;
      cptr++;
    }
  }

  ridx = y_colidx->data[1];
  y_colidx->data[1] = cptr;
  while (ridx < y_colidx->data[2]) {
    val = 0.0;
    currRowIdx = y_rowidx->data[ridx - 1];
    while ((ridx < y_colidx->data[2]) && (y_rowidx->data[ridx - 1] == currRowIdx))
    {
      val += y_d->data[ridx - 1];
      ridx++;
    }

    if (val != 0.0) {
      y_d->data[cptr - 1] = val;
      y_rowidx->data[cptr - 1] = currRowIdx;
      cptr++;
    }
  }

  y_colidx->data[2] = cptr;
}

/* End of code generation (sparse.c) */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * diff.cpp
 *
 * Code generation for function 'diff'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "diff.h"
#include "calc_fall_risk_emxutil.h"
#include <string.h>

/* Function Definitions */
void b_diff(const emxArray_real_T *x, emxArray_real_T *y)
{
  int dimSize;
  int orderForDim;
  int iyLead;
  double work_data_idx_0;
  int m;
  double tmp1;
  double tmp2;
  dimSize = x->size[1];
  if (x->size[1] == 0) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else {
    orderForDim = x->size[1] - 1;
    if (orderForDim >= 1) {
      orderForDim = 1;
    }

    if (orderForDim < 1) {
      y->size[0] = 1;
      y->size[1] = 0;
    } else {
      orderForDim = x->size[1] - 1;
      iyLead = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = orderForDim;
      emxEnsureCapacity_real_T(y, iyLead);
      if (y->size[1] != 0) {
        orderForDim = 1;
        iyLead = 0;
        work_data_idx_0 = x->data[0];
        for (m = 2; m <= dimSize; m++) {
          tmp1 = x->data[orderForDim];
          tmp2 = work_data_idx_0;
          work_data_idx_0 = tmp1;
          tmp1 -= tmp2;
          orderForDim++;
          y->data[iyLead] = tmp1;
          iyLead++;
        }
      }
    }
  }
}

void c_diff(const emxArray_real_T *x, emxArray_real_T *y)
{
  int dimSize;
  int orderForDim;
  int iyLead;
  double work_data_idx_0;
  int m;
  double tmp1;
  double tmp2;
  dimSize = x->size[0];
  if (x->size[0] == 0) {
    y->size[0] = 0;
  } else {
    orderForDim = x->size[0] - 1;
    if (orderForDim >= 1) {
      orderForDim = 1;
    }

    if (orderForDim < 1) {
      y->size[0] = 0;
    } else {
      orderForDim = x->size[0] - 1;
      iyLead = y->size[0];
      y->size[0] = orderForDim;
      emxEnsureCapacity_real_T(y, iyLead);
      if (y->size[0] != 0) {
        orderForDim = 1;
        iyLead = 0;
        work_data_idx_0 = x->data[0];
        for (m = 2; m <= dimSize; m++) {
          tmp1 = x->data[orderForDim];
          tmp2 = work_data_idx_0;
          work_data_idx_0 = tmp1;
          tmp1 -= tmp2;
          orderForDim++;
          y->data[iyLead] = tmp1;
          iyLead++;
        }
      }
    }
  }
}

void d_diff(const emxArray_real_T *x, emxArray_real_T *y)
{
  int dimSize;
  int ySize_idx_0;
  int iyLead;
  double work_data_idx_0;
  int m;
  double tmp1;
  double tmp2;
  dimSize = x->size[0];
  ySize_idx_0 = x->size[0] - 1;
  iyLead = y->size[0] * y->size[1];
  y->size[0] = ySize_idx_0;
  y->size[1] = 1;
  emxEnsureCapacity_real_T(y, iyLead);
  ySize_idx_0 = 1;
  iyLead = 0;
  work_data_idx_0 = x->data[0];
  for (m = 2; m <= dimSize; m++) {
    tmp1 = x->data[ySize_idx_0];
    tmp2 = work_data_idx_0;
    work_data_idx_0 = tmp1;
    tmp1 -= tmp2;
    ySize_idx_0++;
    y->data[iyLead] = tmp1;
    iyLead++;
  }
}

void diff(const emxArray_creal_T *x, emxArray_creal_T *y)
{
  int dimSize;
  int orderForDim;
  short ySize_idx_0;
  int ixStart;
  int iyStart;
  int r;
  int ixLead;
  int iyLead;
  creal_T work_data[1];
  int m;
  double tmp1_re;
  double tmp1_im;
  double tmp2_re;
  double tmp2_im;
  dimSize = x->size[0];
  if (x->size[0] == 0) {
    ySize_idx_0 = static_cast<short>(x->size[1]);
    y->size[0] = 0;
    y->size[1] = ySize_idx_0;
    y->size[2] = 1;
  } else {
    orderForDim = x->size[0] - 1;
    if (orderForDim >= 1) {
      orderForDim = 1;
    }

    if (orderForDim < 1) {
      ySize_idx_0 = static_cast<short>(x->size[1]);
      y->size[0] = 0;
      y->size[1] = ySize_idx_0;
      y->size[2] = 1;
    } else {
      ySize_idx_0 = static_cast<short>((x->size[0] - 1));
      orderForDim = y->size[0] * y->size[1] * y->size[2];
      y->size[0] = ySize_idx_0;
      y->size[1] = static_cast<short>(x->size[1]);
      y->size[2] = 1;
      emxEnsureCapacity_creal_T(y, orderForDim);
      if ((y->size[0] != 0) && (y->size[1] != 0)) {
        orderForDim = x->size[1];
        ixStart = 0;
        iyStart = 1;
        for (r = 0; r < orderForDim; r++) {
          ixLead = ixStart + 1;
          iyLead = iyStart - 1;
          work_data[0] = x->data[ixStart];
          for (m = 2; m <= dimSize; m++) {
            tmp1_re = x->data[ixLead].re;
            tmp1_im = x->data[ixLead].im;
            tmp2_re = work_data[0].re;
            tmp2_im = work_data[0].im;
            work_data[0].re = tmp1_re;
            work_data[0].im = tmp1_im;
            tmp1_re -= tmp2_re;
            tmp1_im -= tmp2_im;
            ixLead++;
            y->data[iyLead].re = tmp1_re;
            y->data[iyLead].im = tmp1_im;
            iyLead++;
          }

          ixStart += dimSize;
          iyStart = (iyStart + dimSize) - 1;
        }
      }
    }
  }
}

/* End of code generation (diff.cpp) */

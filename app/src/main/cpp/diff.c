/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * diff.c
 *
 * Code generation for function 'diff'
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
#include "diff.h"
#include "getFallClass_emxutil.h"
#include <string.h>

/* Function Definitions */
void b_diff(const double x_data[], const int x_size[2], double y_data[], int
            y_size[2])
{
  int dimSize;
  int ixLead;
  int iyLead;
  double work_data_idx_0;
  int m;
  double tmp1;
  dimSize = x_size[1];
  if (x_size[1] == 0) {
    y_size[0] = 1;
    y_size[1] = 0;
  } else {
    ixLead = x_size[1] - 1;
    if (ixLead >= 1) {
      ixLead = 1;
    }

    if (ixLead < 1) {
      y_size[0] = 1;
      y_size[1] = 0;
    } else {
      y_size[0] = 1;
      y_size[1] = (unsigned char)(x_size[1] - 1);
      if ((unsigned char)(x_size[1] - 1) != 0) {
        ixLead = 1;
        iyLead = 0;
        work_data_idx_0 = x_data[0];
        for (m = 2; m <= dimSize; m++) {
          tmp1 = work_data_idx_0;
          work_data_idx_0 = x_data[ixLead];
          tmp1 = x_data[ixLead] - tmp1;
          ixLead++;
          y_data[iyLead] = tmp1;
          iyLead++;
        }
      }
    }
  }
}

void c_diff(const double x_data[], const int x_size[1], double y_data[], int
            y_size[1])
{
  int dimSize;
  int ixLead;
  int iyLead;
  double work_data_idx_0;
  int m;
  double tmp1;
  dimSize = x_size[0];
  if (x_size[0] == 0) {
    y_size[0] = 0;
  } else {
    ixLead = x_size[0] - 1;
    if (ixLead >= 1) {
      ixLead = 1;
    }

    if (ixLead < 1) {
      y_size[0] = 0;
    } else {
      y_size[0] = (short)(x_size[0] - 1);
      if ((short)(x_size[0] - 1) != 0) {
        ixLead = 1;
        iyLead = 0;
        work_data_idx_0 = x_data[0];
        for (m = 2; m <= dimSize; m++) {
          tmp1 = work_data_idx_0;
          work_data_idx_0 = x_data[ixLead];
          tmp1 = x_data[ixLead] - tmp1;
          ixLead++;
          y_data[iyLead] = tmp1;
          iyLead++;
        }
      }
    }
  }
}

void d_diff(const double x[500], double y[499])
{
  int ixLead;
  int iyLead;
  double work;
  int m;
  double tmp2;
  ixLead = 1;
  iyLead = 0;
  work = x[0];
  for (m = 0; m < 499; m++) {
    tmp2 = work;
    work = x[ixLead];
    y[iyLead] = x[ixLead] - tmp2;
    ixLead++;
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
    ySize_idx_0 = (short)x->size[1];
    y->size[0] = 0;
    y->size[1] = ySize_idx_0;
    y->size[2] = 1;
  } else {
    orderForDim = x->size[0] - 1;
    if (orderForDim >= 1) {
      orderForDim = 1;
    }

    if (orderForDim < 1) {
      ySize_idx_0 = (short)x->size[1];
      y->size[0] = 0;
      y->size[1] = ySize_idx_0;
      y->size[2] = 1;
    } else {
      ySize_idx_0 = (short)(x->size[0] - 1);
      orderForDim = y->size[0] * y->size[1] * y->size[2];
      y->size[0] = ySize_idx_0;
      y->size[1] = (short)x->size[1];
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

/* End of code generation (diff.c) */

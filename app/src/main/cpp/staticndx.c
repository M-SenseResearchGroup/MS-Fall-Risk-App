/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * staticndx.c
 *
 * Code generation for function 'staticndx'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "calibrate.h"
#include "get_calibration.h"
#include "get_classification.h"
#include "get_fall_class.h"
#include "get_features.h"
#include "get_strides.h"
#include "pre_process_feats.h"
#include "staticndx.h"
#include "getFallClass_emxutil.h"

/* Function Definitions */
void staticndx(const double data[939], double nsamples, double indices[2])
{
  int i3;
  emxArray_real_T *variance;
  int j;
  double d[939];
  int k;
  emxArray_real_T *tv;
  double xbar;
  int vstride;
  int xoffset;
  short tunableEnvironment_idx_0;
  int loop_ub;
  int n;
  int p;
  double y[3];
  short b_tunableEnvironment_idx_0;
  double xv_data[313];
  int b_k;
  boolean_T exitg1;
  double yv;
  double t;

  /* Reed Gurchiek, 2017 */
  /*    staticndx finds the start and end indices of the interval of length */
  /*    nsamples with the smallest variance for the data in data. */
  /*  */
  /* ------------------------------INPUTS-------------------------------------- */
  /*  */
  /*    data: */
  /*        m x n matrix.  staticndx assumes the largest dimension (m or n) */
  /*        represents indices of observations for different variables, the */
  /*        number of which is equal to the lesser dimension (m or n).  The */
  /*        larger must be greater than nsamples */
  /*  */
  /*    nsamples: */
  /*        the number of samples in the static interval desired */
  /*  */
  /* ------------------------------OUTPUTS------------------------------------- */
  /*  */
  /*    indices: */
  /*        1 x 2.  indices(1) = start index.  indices(2) = end index. */
  /*  */
  /* -------------------------------------------------------------------------- */
  /*  staticndx */
  /* get dims */
  /* determine dimension of observation indices and number of observations */
  /* verify correct input */
  /* if observation indices are columns */
  /* force time/observation series to be column arrays */
  for (i3 = 0; i3 < 3; i3++) {
    for (j = 0; j < 313; j++) {
      d[j + 313 * i3] = data[i3 + 3 * j];
    }
  }

  emxInit_real_T(&variance, 2);

  /* get number of variables */
  /* if observation indices are rows     */
  /* determine number of intervals of length nsamples */
  /* for each interval of length nsamples */
  i3 = (int)((313.0 - nsamples) + 1.0);
  j = variance->size[0] * variance->size[1];
  variance->size[0] = i3;
  variance->size[1] = 3;
  emxEnsureCapacity_real_T(variance, j);
  for (k = 0; k < i3; k++) {
    /* get variance of each variable for each interval of length nsamples */
    xbar = ((1.0 + (double)k) + nsamples) - 1.0;
    if (1.0 + (double)k > xbar) {
      j = -1;
      xoffset = -1;
    } else {
      j = k - 1;
      xoffset = (int)xbar - 1;
    }

    vstride = xoffset - j;
    tunableEnvironment_idx_0 = (short)vstride;
    loop_ub = (short)vstride;
    n = tunableEnvironment_idx_0;
    for (p = 0; p < 3; p++) {
      y[p] = 0.0;
      b_tunableEnvironment_idx_0 = (short)(p * vstride + 1);
      if (0 <= loop_ub - 1) {
        memset(&xv_data[0], 0, (unsigned int)(loop_ub * (int)sizeof(double)));
      }

      for (b_k = 0; b_k < vstride; b_k++) {
        xoffset = b_tunableEnvironment_idx_0 + b_k;
        xv_data[b_k] = d[((j + (xoffset - 1) % vstride) + 313 * ((xoffset - 1) /
          vstride)) + 1];
      }

      if (tunableEnvironment_idx_0 == 0) {
        y[p] = rtNaN;
      } else if (tunableEnvironment_idx_0 == 1) {
        if ((!rtIsInf(xv_data[0])) && (!rtIsNaN(xv_data[0]))) {
          y[p] = 0.0;
        } else {
          y[p] = rtNaN;
        }
      } else {
        if ((short)vstride == 0) {
          xbar = 0.0;
        } else {
          xbar = xv_data[0];
          for (b_k = 2; b_k <= n; b_k++) {
            xbar += xv_data[b_k - 1];
          }
        }

        xbar /= (double)tunableEnvironment_idx_0;
        yv = 0.0;
        for (b_k = 0; b_k < n; b_k++) {
          t = xv_data[b_k] - xbar;
          yv += t * t;
        }

        y[p] = yv / ((double)tunableEnvironment_idx_0 - 1.0);
      }
    }

    variance->data[k] = y[0];
    variance->data[k + variance->size[0]] = y[1];
    variance->data[k + (variance->size[0] << 1)] = y[2];
  }

  emxInit_real_T(&tv, 1);

  /* get total variance for each interval */
  vstride = variance->size[0];
  i3 = tv->size[0];
  tv->size[0] = variance->size[0];
  emxEnsureCapacity_real_T(tv, i3);
  for (j = 0; j < vstride; j++) {
    tv->data[j] = variance->data[j];
  }

  for (j = 0; j < vstride; j++) {
    tv->data[j] += variance->data[vstride + j];
  }

  xoffset = 2 * vstride;
  for (j = 0; j < vstride; j++) {
    tv->data[j] += variance->data[xoffset + j];
  }

  emxFree_real_T(&variance);

  /* get starting index for the most static interval */
  n = tv->size[0];
  if (tv->size[0] <= 2) {
    if ((tv->data[0] > tv->data[1]) || (rtIsNaN(tv->data[0]) && (!rtIsNaN
          (tv->data[1])))) {
      j = 2;
    } else {
      j = 1;
    }
  } else {
    if (!rtIsNaN(tv->data[0])) {
      j = 1;
    } else {
      j = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= tv->size[0])) {
        if (!rtIsNaN(tv->data[k - 1])) {
          j = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (j == 0) {
      j = 1;
    } else {
      xbar = tv->data[j - 1];
      i3 = j + 1;
      for (k = i3; k <= n; k++) {
        if (xbar > tv->data[k - 1]) {
          xbar = tv->data[k - 1];
          j = k;
        }
      }
    }
  }

  emxFree_real_T(&tv);

  /* get ending index for most static interval */
  indices[0] = j;
  indices[1] = ((double)j + nsamples) - 1.0;
}

/* End of code generation (staticndx.c) */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mergesort.c
 *
 * Code generation for function 'mergesort'
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
#include "mergesort.h"
#include "sortLE.h"
#include "getFallClass_emxutil.h"
#include <string.h>

/* Function Definitions */
void b_mergesort(int idx_data[], emxArray_creal_T *x, int n)
{
  int i;
  int k;
  emxArray_creal_T *xwork;
  int i2;
  short x_idx_0;
  int j;
  int pEnd;
  int p;
  int q;
  int qEnd;
  int kEnd;
  int iwork_data[12285];
  i = n - 1;
  for (k = 1; k <= i; k += 2) {
    if (sortLE(x, k, k + 1)) {
      idx_data[k - 1] = k;
      idx_data[k] = k + 1;
    } else {
      idx_data[k - 1] = k + 1;
      idx_data[k] = k;
    }
  }

  if ((n & 1) != 0) {
    idx_data[n - 1] = n;
  }

  i = 2;
  while (i < n) {
    i2 = i << 1;
    j = 1;
    for (pEnd = 1 + i; pEnd < n + 1; pEnd = qEnd + i) {
      p = j;
      q = pEnd;
      qEnd = j + i2;
      if (qEnd > n + 1) {
        qEnd = n + 1;
      }

      k = 0;
      kEnd = qEnd - j;
      while (k + 1 <= kEnd) {
        if (sortLE(x, idx_data[p - 1], idx_data[q - 1])) {
          iwork_data[k] = idx_data[p - 1];
          p++;
          if (p == pEnd) {
            while (q < qEnd) {
              k++;
              iwork_data[k] = idx_data[q - 1];
              q++;
            }
          }
        } else {
          iwork_data[k] = idx_data[q - 1];
          q++;
          if (q == qEnd) {
            while (p < pEnd) {
              k++;
              iwork_data[k] = idx_data[p - 1];
              p++;
            }
          }
        }

        k++;
      }

      for (k = 0; k < kEnd; k++) {
        idx_data[(j + k) - 1] = iwork_data[k];
      }

      j = qEnd;
    }

    i = i2;
  }

  emxInit_creal_T(&xwork, 1);
  x_idx_0 = (short)x->size[0];
  i = xwork->size[0];
  xwork->size[0] = x_idx_0;
  emxEnsureCapacity_creal_T(xwork, i);
  for (k = 0; k < n; k++) {
    xwork->data[k] = x->data[k];
  }

  for (k = 0; k < n; k++) {
    x->data[k] = xwork->data[idx_data[k] - 1];
  }

  emxFree_creal_T(&xwork);
}

/* End of code generation (mergesort.c) */

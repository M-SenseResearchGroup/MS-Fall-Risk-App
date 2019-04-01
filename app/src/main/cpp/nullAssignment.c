/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nullAssignment.c
 *
 * Code generation for function 'nullAssignment'
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
#include "nullAssignment.h"
#include "getFallClass_emxutil.h"
#include <string.h>

/* Function Declarations */
static int b_num_true(const boolean_T b_data[], const int b_size[1]);
static int eml_ndims_varsized(void);
static void make_bitarray(int n, const emxArray_int32_T *idx, emxArray_boolean_T
  *b);
static int num_true(const emxArray_boolean_T *b);

/* Function Definitions */
static int b_num_true(const boolean_T b_data[], const int b_size[1])
{
  int n;
  int i45;
  int k;
  n = 0;
  i45 = b_size[0];
  for (k = 0; k < i45; k++) {
    n += b_data[k];
  }

  return n;
}

static int eml_ndims_varsized(void)
{
  return 2;
}

static void make_bitarray(int n, const emxArray_int32_T *idx, emxArray_boolean_T
  *b)
{
  int i28;
  int k;
  i28 = b->size[0] * b->size[1];
  b->size[0] = 1;
  b->size[1] = n;
  emxEnsureCapacity_boolean_T(b, i28);
  for (i28 = 0; i28 < n; i28++) {
    b->data[i28] = false;
  }

  i28 = idx->size[1];
  for (k = 0; k < i28; k++) {
    b->data[idx->data[k] - 1] = true;
  }
}

static int num_true(const emxArray_boolean_T *b)
{
  int n;
  int i29;
  int k;
  n = 0;
  i29 = b->size[1];
  for (k = 0; k < i29; k++) {
    n += b->data[k];
  }

  return n;
}

void b_nullAssignment(emxArray_real_T *x, const emxArray_int32_T *idx)
{
  emxArray_boolean_T *b;
  int nxin;
  int nxout;
  int k0;
  int k;
  emxInit_boolean_T(&b, 2);
  nxin = x->size[0];
  make_bitarray(x->size[0], idx, b);
  nxout = x->size[0] - num_true(b);
  k0 = -1;
  for (k = 0; k < nxin; k++) {
    if ((k + 1 > b->size[1]) || (!b->data[k])) {
      k0++;
      x->data[k0] = x->data[k];
    }
  }

  emxFree_boolean_T(&b);
  if (1 > nxout) {
    x->size[0] = 0;
  } else {
    nxin = x->size[0];
    x->size[0] = nxout;
    emxEnsureCapacity_real_T(x, nxin);
  }
}

void c_nullAssignment(emxArray_real_T *x, const emxArray_boolean_T *idx)
{
  int nxin;
  int nrowx;
  int ncolx;
  int k0;
  int i51;
  int k;
  int nxout;
  int nb;
  emxArray_real_T *b_x;
  nxin = x->size[0] * x->size[1];
  nrowx = x->size[0];
  ncolx = x->size[1];
  k0 = 0;
  i51 = idx->size[0] * idx->size[1];
  for (k = 0; k < i51; k++) {
    k0 += idx->data[k];
  }

  nxout = nxin - k0;
  nb = idx->size[0] * idx->size[1];
  k0 = -1;
  for (k = 0; k < nxin; k++) {
    if ((k + 1 > nb) || (!idx->data[k])) {
      k0++;
      x->data[k0] = x->data[k];
    }
  }

  emxInit_real_T(&b_x, 2);
  if ((nrowx != 1) && (ncolx == 1)) {
    b_x->size[0] = 0;
    b_x->size[1] = 1;
    i51 = x->size[0] * x->size[1];
    x->size[0] = b_x->size[0];
    x->size[1] = b_x->size[1];
    emxEnsureCapacity_real_T(x, i51);
    k0 = b_x->size[1];
    for (i51 = 0; i51 < k0; i51++) {
      nxout = b_x->size[0];
      for (nb = 0; nb < nxout; nb++) {
        x->data[nb + x->size[0] * i51] = b_x->data[nb + b_x->size[0] * i51];
      }
    }
  } else {
    if (1 > nxout) {
      k0 = 0;
    } else {
      k0 = nxout;
    }

    i51 = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = k0;
    emxEnsureCapacity_real_T(b_x, i51);
    for (i51 = 0; i51 < k0; i51++) {
      b_x->data[b_x->size[0] * i51] = x->data[i51];
    }

    i51 = x->size[0] * x->size[1];
    x->size[0] = b_x->size[0];
    x->size[1] = b_x->size[1];
    emxEnsureCapacity_real_T(x, i51);
    k0 = b_x->size[1];
    for (i51 = 0; i51 < k0; i51++) {
      nxout = b_x->size[0];
      for (nb = 0; nb < nxout; nb++) {
        x->data[nb + x->size[0] * i51] = b_x->data[nb + b_x->size[0] * i51];
      }
    }
  }

  emxFree_real_T(&b_x);
}

void d_nullAssignment(double x_data[], int x_size[2], const int idx_data[],
                      const int idx_size[2])
{
  emxArray_boolean_T *b;
  int nxin;
  int k0;
  int nxout;
  int k;
  emxInit_boolean_T(&b, 2);
  nxin = x_size[1];
  k0 = b->size[0] * b->size[1];
  b->size[0] = 1;
  b->size[1] = x_size[1];
  emxEnsureCapacity_boolean_T(b, k0);
  nxout = x_size[1];
  for (k0 = 0; k0 < nxout; k0++) {
    b->data[k0] = false;
  }

  k0 = idx_size[1];
  for (k = 0; k < k0; k++) {
    b->data[idx_data[k] - 1] = true;
  }

  nxout = 0;
  k0 = b->size[1];
  for (k = 0; k < k0; k++) {
    nxout += b->data[k];
  }

  nxout = x_size[1] - nxout;
  k0 = -1;
  for (k = 0; k < nxin; k++) {
    if ((k + 1 > b->size[1]) || (!b->data[k])) {
      k0++;
      x_data[k0] = x_data[k];
    }
  }

  emxFree_boolean_T(&b);
  if (1 > nxout) {
    x_size[1] = 0;
  } else {
    x_size[1] = nxout;
  }
}

void e_nullAssignment(double x_data[], int x_size[1], const boolean_T idx_data[],
                      const int idx_size[1])
{
  int nxin;
  int nxout;
  int k0;
  int k;
  nxin = x_size[0];
  nxout = 0;
  k0 = idx_size[0];
  for (k = 0; k < k0; k++) {
    nxout += idx_data[k];
  }

  nxout = x_size[0] - nxout;
  k0 = -1;
  for (k = 0; k < nxin; k++) {
    if ((k + 1 > idx_size[0]) || (!idx_data[k])) {
      k0++;
      x_data[k0] = x_data[k];
    }
  }

  if (1 > nxout) {
    x_size[0] = 0;
  } else {
    x_size[0] = nxout;
  }
}

void f_nullAssignment(emxArray_creal_T *x, const emxArray_boolean_T *idx)
{
  int nxin;
  int nrowx;
  int ncolx;
  int n;
  int i55;
  int k;
  int nxout;
  int k0;
  emxArray_creal_T *b_x;
  nxin = x->size[0] * x->size[1];
  nrowx = x->size[0];
  ncolx = x->size[1];
  n = 0;
  i55 = idx->size[1];
  for (k = 0; k < i55; k++) {
    n += idx->data[k];
  }

  nxout = nxin - n;
  k0 = -1;
  for (k = 0; k < nxin; k++) {
    if ((k + 1 > idx->size[1]) || (!idx->data[k])) {
      k0++;
      x->data[k0] = x->data[k];
    }
  }

  emxInit_creal_T(&b_x, 2);
  if ((nrowx != 1) && (ncolx == 1)) {
    b_x->size[0] = 0;
    b_x->size[1] = 1;
    i55 = x->size[0] * x->size[1];
    x->size[0] = b_x->size[0];
    x->size[1] = b_x->size[1];
    emxEnsureCapacity_creal_T(x, i55);
    n = b_x->size[1];
    for (i55 = 0; i55 < n; i55++) {
      nxout = b_x->size[0];
      for (k0 = 0; k0 < nxout; k0++) {
        x->data[k0 + x->size[0] * i55] = b_x->data[k0 + b_x->size[0] * i55];
      }
    }
  } else {
    if (1 > nxout) {
      n = 0;
    } else {
      n = nxout;
    }

    i55 = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = n;
    emxEnsureCapacity_creal_T(b_x, i55);
    for (i55 = 0; i55 < n; i55++) {
      b_x->data[b_x->size[0] * i55] = x->data[i55];
    }

    i55 = x->size[0] * x->size[1];
    x->size[0] = b_x->size[0];
    x->size[1] = b_x->size[1];
    emxEnsureCapacity_creal_T(x, i55);
    n = b_x->size[1];
    for (i55 = 0; i55 < n; i55++) {
      nxout = b_x->size[0];
      for (k0 = 0; k0 < nxout; k0++) {
        x->data[k0 + x->size[0] * i55] = b_x->data[k0 + b_x->size[0] * i55];
      }
    }
  }

  emxFree_creal_T(&b_x);
}

void g_nullAssignment(emxArray_real_T *x, const emxArray_boolean_T *idx)
{
  int nxin;
  int nrowx;
  int ncolx;
  int n;
  int i56;
  int k;
  int nxout;
  int k0;
  emxArray_real_T *b_x;
  nxin = x->size[0] * x->size[1];
  nrowx = x->size[0];
  ncolx = x->size[1];
  n = 0;
  i56 = idx->size[1];
  for (k = 0; k < i56; k++) {
    n += idx->data[k];
  }

  nxout = nxin - n;
  k0 = -1;
  for (k = 0; k < nxin; k++) {
    if ((k + 1 > idx->size[1]) || (!idx->data[k])) {
      k0++;
      x->data[k0] = x->data[k];
    }
  }

  emxInit_real_T(&b_x, 2);
  if ((nrowx != 1) && (ncolx == 1)) {
    b_x->size[0] = 0;
    b_x->size[1] = 1;
    i56 = x->size[0] * x->size[1];
    x->size[0] = b_x->size[0];
    x->size[1] = b_x->size[1];
    emxEnsureCapacity_real_T(x, i56);
    n = b_x->size[1];
    for (i56 = 0; i56 < n; i56++) {
      nxout = b_x->size[0];
      for (k0 = 0; k0 < nxout; k0++) {
        x->data[k0 + x->size[0] * i56] = b_x->data[k0 + b_x->size[0] * i56];
      }
    }
  } else {
    if (1 > nxout) {
      n = 0;
    } else {
      n = nxout;
    }

    i56 = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = n;
    emxEnsureCapacity_real_T(b_x, i56);
    for (i56 = 0; i56 < n; i56++) {
      b_x->data[b_x->size[0] * i56] = x->data[i56];
    }

    i56 = x->size[0] * x->size[1];
    x->size[0] = b_x->size[0];
    x->size[1] = b_x->size[1];
    emxEnsureCapacity_real_T(x, i56);
    n = b_x->size[1];
    for (i56 = 0; i56 < n; i56++) {
      nxout = b_x->size[0];
      for (k0 = 0; k0 < nxout; k0++) {
        x->data[k0 + x->size[0] * i56] = b_x->data[k0 + b_x->size[0] * i56];
      }
    }
  }

  emxFree_real_T(&b_x);
}

void h_nullAssignment(emxArray_real_T *x, int idx)
{
  int nxin;
  int nrowx;
  int ncolx;
  int nxout;
  int k;
  emxArray_real_T *b_x;
  nxin = x->size[0] * x->size[1];
  nrowx = x->size[0];
  ncolx = x->size[1];
  nxout = x->size[0] * x->size[1] - 1;
  for (k = idx; k <= nxout; k++) {
    x->data[k - 1] = x->data[k];
  }

  emxInit_real_T(&b_x, 2);
  if ((nrowx != 1) && (ncolx == 1)) {
    b_x->size[0] = 0;
    b_x->size[1] = 1;
    nrowx = x->size[0] * x->size[1];
    x->size[0] = b_x->size[0];
    x->size[1] = b_x->size[1];
    emxEnsureCapacity_real_T(x, nrowx);
    nxin = b_x->size[1];
    for (nrowx = 0; nrowx < nxin; nrowx++) {
      ncolx = b_x->size[0];
      for (nxout = 0; nxout < ncolx; nxout++) {
        x->data[nxout + x->size[0] * nrowx] = b_x->data[nxout + b_x->size[0] *
          nrowx];
      }
    }
  } else {
    if (1 > nxout) {
      nxin = -1;
    } else {
      nxin -= 2;
    }

    nrowx = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = nxin + 1;
    emxEnsureCapacity_real_T(b_x, nrowx);
    for (nrowx = 0; nrowx <= nxin; nrowx++) {
      b_x->data[b_x->size[0] * nrowx] = x->data[nrowx];
    }

    nrowx = x->size[0] * x->size[1];
    x->size[0] = b_x->size[0];
    x->size[1] = b_x->size[1];
    emxEnsureCapacity_real_T(x, nrowx);
    nxin = b_x->size[1];
    for (nrowx = 0; nrowx < nxin; nrowx++) {
      ncolx = b_x->size[0];
      for (nxout = 0; nxout < ncolx; nxout++) {
        x->data[nxout + x->size[0] * nrowx] = b_x->data[nxout + b_x->size[0] *
          nrowx];
      }
    }
  }

  emxFree_real_T(&b_x);
}

void i_nullAssignment(emxArray_real_T *x, int idx)
{
  int nxin;
  int nxout;
  int k;
  emxArray_real_T *b_x;
  nxin = x->size[1] - 2;
  nxout = x->size[1] - 1;
  for (k = idx; k <= nxout; k++) {
    x->data[k - 1] = x->data[k];
  }

  if (1 > nxout) {
    nxin = -1;
  }

  emxInit_real_T(&b_x, 2);
  nxout = b_x->size[0] * b_x->size[1];
  b_x->size[0] = 1;
  b_x->size[1] = nxin + 1;
  emxEnsureCapacity_real_T(b_x, nxout);
  for (nxout = 0; nxout <= nxin; nxout++) {
    b_x->data[nxout] = x->data[nxout];
  }

  nxout = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = b_x->size[1];
  emxEnsureCapacity_real_T(x, nxout);
  nxin = b_x->size[1];
  for (nxout = 0; nxout < nxin; nxout++) {
    x->data[nxout] = b_x->data[nxout];
  }

  emxFree_real_T(&b_x);
}

void j_nullAssignment(emxArray_real_T *x)
{
  int nxin;
  int nxout;
  int k;
  emxArray_real_T *b_x;
  nxin = x->size[1] - 2;
  nxout = x->size[1] - 1;
  for (k = 0; k < nxout; k++) {
    x->data[k] = x->data[k + 1];
  }

  if (1 > nxout) {
    nxin = -1;
  }

  emxInit_real_T(&b_x, 2);
  nxout = b_x->size[0] * b_x->size[1];
  b_x->size[0] = 1;
  b_x->size[1] = nxin + 1;
  emxEnsureCapacity_real_T(b_x, nxout);
  for (nxout = 0; nxout <= nxin; nxout++) {
    b_x->data[nxout] = x->data[nxout];
  }

  nxout = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = b_x->size[1];
  emxEnsureCapacity_real_T(x, nxout);
  nxin = b_x->size[1];
  for (nxout = 0; nxout < nxin; nxout++) {
    x->data[nxout] = b_x->data[nxout];
  }

  emxFree_real_T(&b_x);
}

void nullAssignment(const emxArray_creal_T *x, const boolean_T idx_data[], const
                    int idx_size[1], emxArray_creal_T *b_x)
{
  emxArray_creal_T *c_x;
  int nxin;
  int nxout;
  int k0;
  int k;
  emxArray_creal_T *d_x;
  emxInit_creal_T(&c_x, 3);
  nxin = c_x->size[0] * c_x->size[1] * c_x->size[2];
  c_x->size[0] = x->size[0];
  c_x->size[1] = x->size[1];
  c_x->size[2] = 1;
  emxEnsureCapacity_creal_T(c_x, nxin);
  nxout = x->size[0] * x->size[1] * x->size[2];
  for (nxin = 0; nxin < nxout; nxin++) {
    c_x->data[nxin] = x->data[nxin];
  }

  nxin = x->size[0] * x->size[1];
  nxout = nxin - b_num_true(idx_data, idx_size);
  k0 = -1;
  for (k = 0; k < nxin; k++) {
    if ((k + 1 > idx_size[0]) || (!idx_data[k])) {
      k0++;
      c_x->data[k0] = c_x->data[k];
    }
  }

  emxInit_creal_T(&d_x, 1);
  if ((x->size[0] != 1) && (x->size[1] == 1) && (eml_ndims_varsized() <= 2)) {
    if (1 > nxout) {
      nxout = 0;
    }

    nxin = d_x->size[0];
    d_x->size[0] = nxout;
    emxEnsureCapacity_creal_T(d_x, nxin);
    for (nxin = 0; nxin < nxout; nxin++) {
      d_x->data[nxin] = c_x->data[nxin];
    }

    nxin = b_x->size[0] * b_x->size[1];
    b_x->size[0] = nxout;
    b_x->size[1] = 1;
    emxEnsureCapacity_creal_T(b_x, nxin);
    for (nxin = 0; nxin < nxout; nxin++) {
      b_x->data[nxin] = d_x->data[nxin];
    }
  } else {
    if (1 > nxout) {
      nxout = 0;
    }

    nxin = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = nxout;
    emxEnsureCapacity_creal_T(b_x, nxin);
    for (nxin = 0; nxin < nxout; nxin++) {
      b_x->data[b_x->size[0] * nxin] = c_x->data[nxin];
    }
  }

  emxFree_creal_T(&d_x);
  emxFree_creal_T(&c_x);
}

/* End of code generation (nullAssignment.c) */

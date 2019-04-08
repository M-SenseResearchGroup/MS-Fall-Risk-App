/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nullAssignment.cpp
 *
 * Code generation for function 'nullAssignment'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "nullAssignment.h"
#include "calc_fall_risk_emxutil.h"
#include <string.h>

/* Function Declarations */
static int b_num_true(const boolean_T b_data[], const int b_size[1]);
static int eml_ndims_varsized(const int sz[3]);
static void make_bitarray(int n, const emxArray_int32_T *idx, emxArray_boolean_T
  *b);
static int num_true(const emxArray_boolean_T *b);

/* Function Definitions */
static int b_num_true(const boolean_T b_data[], const int b_size[1])
{
  int n;
  int i92;
  int k;
  n = 0;
  i92 = b_size[0];
  for (k = 0; k < i92; k++) {
    n += b_data[k];
  }

  return n;
}

static int eml_ndims_varsized(const int sz[3])
{
  int n;
  n = 3;
  if (sz[2] == 1) {
    n = 2;
  }

  return n;
}

static void make_bitarray(int n, const emxArray_int32_T *idx, emxArray_boolean_T
  *b)
{
  int i41;
  int k;
  i41 = b->size[0] * b->size[1];
  b->size[0] = 1;
  b->size[1] = n;
  emxEnsureCapacity_boolean_T(b, i41);
  for (i41 = 0; i41 < n; i41++) {
    b->data[i41] = false;
  }

  i41 = idx->size[1];
  for (k = 0; k < i41; k++) {
    b->data[idx->data[k] - 1] = true;
  }
}

static int num_true(const emxArray_boolean_T *b)
{
  int n;
  int i42;
  int k;
  n = 0;
  i42 = b->size[1];
  for (k = 0; k < i42; k++) {
    n += b->data[k];
  }

  return n;
}

void b_nullAssignment(emxArray_real_T *x, const emxArray_int32_T *idx)
{
  emxArray_boolean_T *b;
  int nxin;
  int i101;
  int k0;
  int k;
  int nxout;
  emxInit_boolean_T(&b, 2);
  nxin = x->size[0];
  i101 = b->size[0] * b->size[1];
  b->size[0] = 1;
  b->size[1] = x->size[0];
  emxEnsureCapacity_boolean_T(b, i101);
  k0 = x->size[0];
  for (i101 = 0; i101 < k0; i101++) {
    b->data[i101] = false;
  }

  i101 = idx->size[1];
  for (k = 0; k < i101; k++) {
    b->data[idx->data[k] - 1] = true;
  }

  k0 = 0;
  i101 = b->size[1];
  for (k = 0; k < i101; k++) {
    k0 += b->data[k];
  }

  nxout = x->size[0] - k0;
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
    i101 = x->size[0];
    x->size[0] = nxout;
    emxEnsureCapacity_real_T(x, i101);
  }
}

void c_nullAssignment(emxArray_real_T *x, const emxArray_boolean_T *idx)
{
  int nxin;
  int nrowx;
  int ncolx;
  int k0;
  int i102;
  int k;
  int nxout;
  int nb;
  emxArray_real_T *b_x;
  nxin = x->size[0] * x->size[1];
  nrowx = x->size[0];
  ncolx = x->size[1];
  k0 = 0;
  i102 = idx->size[0] * idx->size[1];
  for (k = 0; k < i102; k++) {
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
    i102 = x->size[0] * x->size[1];
    x->size[0] = b_x->size[0];
    x->size[1] = b_x->size[1];
    emxEnsureCapacity_real_T(x, i102);
    k0 = b_x->size[1];
    for (i102 = 0; i102 < k0; i102++) {
      nxout = b_x->size[0];
      for (nb = 0; nb < nxout; nb++) {
        x->data[nb + x->size[0] * i102] = b_x->data[nb + b_x->size[0] * i102];
      }
    }
  } else {
    if (1 > nxout) {
      k0 = 0;
    } else {
      k0 = nxout;
    }

    i102 = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = k0;
    emxEnsureCapacity_real_T(b_x, i102);
    for (i102 = 0; i102 < k0; i102++) {
      b_x->data[b_x->size[0] * i102] = x->data[i102];
    }

    i102 = x->size[0] * x->size[1];
    x->size[0] = b_x->size[0];
    x->size[1] = b_x->size[1];
    emxEnsureCapacity_real_T(x, i102);
    k0 = b_x->size[1];
    for (i102 = 0; i102 < k0; i102++) {
      nxout = b_x->size[0];
      for (nb = 0; nb < nxout; nb++) {
        x->data[nb + x->size[0] * i102] = b_x->data[nb + b_x->size[0] * i102];
      }
    }
  }

  emxFree_real_T(&b_x);
}

void d_nullAssignment(emxArray_real_T *x, const emxArray_int32_T *idx)
{
  emxArray_boolean_T *b;
  int nxin;
  int i105;
  int k0;
  int k;
  int nxout;
  emxInit_boolean_T(&b, 2);
  nxin = x->size[1];
  i105 = b->size[0] * b->size[1];
  b->size[0] = 1;
  b->size[1] = x->size[1];
  emxEnsureCapacity_boolean_T(b, i105);
  k0 = x->size[1];
  for (i105 = 0; i105 < k0; i105++) {
    b->data[i105] = false;
  }

  i105 = idx->size[1];
  for (k = 0; k < i105; k++) {
    b->data[idx->data[k] - 1] = true;
  }

  k0 = 0;
  i105 = b->size[1];
  for (k = 0; k < i105; k++) {
    k0 += b->data[k];
  }

  nxout = x->size[1] - k0;
  k0 = -1;
  for (k = 0; k < nxin; k++) {
    if ((k + 1 > b->size[1]) || (!b->data[k])) {
      k0++;
      x->data[k0] = x->data[k];
    }
  }

  emxFree_boolean_T(&b);
  if (1 > nxout) {
    x->size[1] = 0;
  } else {
    i105 = x->size[0] * x->size[1];
    x->size[1] = nxout;
    emxEnsureCapacity_real_T(x, i105);
  }
}

void e_nullAssignment(emxArray_real_T *x, const emxArray_int32_T *idx)
{
  emxArray_boolean_T *b;
  emxArray_boolean_T *r43;
  int nxin;
  int nrowx;
  int ncolx;
  int k;
  int loop_ub;
  int nxout;
  int k0;
  emxArray_real_T *b_x;
  double x_data[625];
  emxInit_boolean_T(&b, 2);
  emxInit_boolean_T(&r43, 2);
  nxin = x->size[0] * x->size[1];
  nrowx = x->size[0];
  ncolx = x->size[1];
  make_bitarray(nxin, idx, r43);
  k = b->size[0] * b->size[1];
  b->size[0] = 1;
  b->size[1] = r43->size[1];
  emxEnsureCapacity_boolean_T(b, k);
  loop_ub = r43->size[0] * r43->size[1];
  for (k = 0; k < loop_ub; k++) {
    b->data[k] = r43->data[k];
  }

  emxFree_boolean_T(&r43);
  nxout = nxin - num_true(b);
  k0 = -1;
  for (k = 0; k < nxin; k++) {
    if ((k + 1 > b->size[1]) || (!b->data[k])) {
      k0++;
      x->data[k0] = x->data[k];
    }
  }

  emxFree_boolean_T(&b);
  emxInit_real_T(&b_x, 2);
  if ((nrowx != 1) && (ncolx == 1)) {
    if (1 > nxout) {
      loop_ub = 0;
    } else {
      loop_ub = nxout;
    }

    for (k = 0; k < loop_ub; k++) {
      x_data[k] = x->data[k];
    }

    k = x->size[0] * x->size[1];
    x->size[0] = loop_ub;
    x->size[1] = 1;
    emxEnsureCapacity_real_T(x, k);
    for (k = 0; k < 1; k++) {
      for (k0 = 0; k0 < loop_ub; k0++) {
        x->data[k0] = x_data[k0];
      }
    }
  } else {
    if (1 > nxout) {
      loop_ub = 0;
    } else {
      loop_ub = nxout;
    }

    k = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = loop_ub;
    emxEnsureCapacity_real_T(b_x, k);
    for (k = 0; k < loop_ub; k++) {
      b_x->data[b_x->size[0] * k] = x->data[k];
    }

    k = x->size[0] * x->size[1];
    x->size[0] = b_x->size[0];
    x->size[1] = b_x->size[1];
    emxEnsureCapacity_real_T(x, k);
    loop_ub = b_x->size[1];
    for (k = 0; k < loop_ub; k++) {
      nxout = b_x->size[0];
      for (k0 = 0; k0 < nxout; k0++) {
        x->data[k0 + x->size[0] * k] = b_x->data[k0 + b_x->size[0] * k];
      }
    }
  }

  emxFree_real_T(&b_x);
}

void f_nullAssignment(emxArray_creal_T *x, const emxArray_boolean_T *idx)
{
  int nxin;
  int nrowx;
  int ncolx;
  int n;
  int i106;
  int k;
  int nxout;
  int k0;
  emxArray_creal_T *b_x;
  nxin = x->size[0] * x->size[1];
  nrowx = x->size[0];
  ncolx = x->size[1];
  n = 0;
  i106 = idx->size[1];
  for (k = 0; k < i106; k++) {
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
    i106 = x->size[0] * x->size[1];
    x->size[0] = b_x->size[0];
    x->size[1] = b_x->size[1];
    emxEnsureCapacity_creal_T(x, i106);
    n = b_x->size[1];
    for (i106 = 0; i106 < n; i106++) {
      nxout = b_x->size[0];
      for (k0 = 0; k0 < nxout; k0++) {
        x->data[k0 + x->size[0] * i106] = b_x->data[k0 + b_x->size[0] * i106];
      }
    }
  } else {
    if (1 > nxout) {
      n = 0;
    } else {
      n = nxout;
    }

    i106 = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = n;
    emxEnsureCapacity_creal_T(b_x, i106);
    for (i106 = 0; i106 < n; i106++) {
      b_x->data[b_x->size[0] * i106] = x->data[i106];
    }

    i106 = x->size[0] * x->size[1];
    x->size[0] = b_x->size[0];
    x->size[1] = b_x->size[1];
    emxEnsureCapacity_creal_T(x, i106);
    n = b_x->size[1];
    for (i106 = 0; i106 < n; i106++) {
      nxout = b_x->size[0];
      for (k0 = 0; k0 < nxout; k0++) {
        x->data[k0 + x->size[0] * i106] = b_x->data[k0 + b_x->size[0] * i106];
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
  int i107;
  int k;
  int nxout;
  int k0;
  emxArray_real_T *b_x;
  nxin = x->size[0] * x->size[1];
  nrowx = x->size[0];
  ncolx = x->size[1];
  n = 0;
  i107 = idx->size[1];
  for (k = 0; k < i107; k++) {
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
    i107 = x->size[0] * x->size[1];
    x->size[0] = b_x->size[0];
    x->size[1] = b_x->size[1];
    emxEnsureCapacity_real_T(x, i107);
    n = b_x->size[1];
    for (i107 = 0; i107 < n; i107++) {
      nxout = b_x->size[0];
      for (k0 = 0; k0 < nxout; k0++) {
        x->data[k0 + x->size[0] * i107] = b_x->data[k0 + b_x->size[0] * i107];
      }
    }
  } else {
    if (1 > nxout) {
      n = 0;
    } else {
      n = nxout;
    }

    i107 = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = n;
    emxEnsureCapacity_real_T(b_x, i107);
    for (i107 = 0; i107 < n; i107++) {
      b_x->data[b_x->size[0] * i107] = x->data[i107];
    }

    i107 = x->size[0] * x->size[1];
    x->size[0] = b_x->size[0];
    x->size[1] = b_x->size[1];
    emxEnsureCapacity_real_T(x, i107);
    n = b_x->size[1];
    for (i107 = 0; i107 < n; i107++) {
      nxout = b_x->size[0];
      for (k0 = 0; k0 < nxout; k0++) {
        x->data[k0 + x->size[0] * i107] = b_x->data[k0 + b_x->size[0] * i107];
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
  nxin = x->size[1];
  nxout = x->size[1] - 1;
  for (k = idx; k <= nxout; k++) {
    x->data[k - 1] = x->data[k];
  }

  if (1 > nxout) {
    x->size[1] = 0;
  } else {
    nxout = x->size[0] * x->size[1];
    x->size[1] = nxin - 1;
    emxEnsureCapacity_real_T(x, nxout);
  }
}

void j_nullAssignment(emxArray_real_T *x)
{
  int nxin;
  int nxout;
  int k;
  nxin = x->size[1];
  nxout = x->size[1] - 1;
  for (k = 0; k < nxout; k++) {
    x->data[k] = x->data[k + 1];
  }

  if (1 > nxout) {
    x->size[1] = 0;
  } else {
    nxout = x->size[0] * x->size[1];
    x->size[1] = nxin - 1;
    emxEnsureCapacity_real_T(x, nxout);
  }
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
  if ((x->size[0] != 1) && (x->size[1] == 1) && (eml_ndims_varsized(*(int (*)[3])
        c_x->size) <= 2)) {
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

/* End of code generation (nullAssignment.cpp) */

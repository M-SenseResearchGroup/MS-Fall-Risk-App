/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fft1.cpp
 *
 * Code generation for function 'fft1'
 *
 */

/* Include files */
#include <cmath>
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "fft1.h"
#include "calc_fall_risk_emxutil.h"
#include "bluesteinSetup.h"
#include <string.h>

/* Function Declarations */
static void b_bluestein(const emxArray_real_T *x, int xoffInit, int nfft, int
  nRows, const double costab_data[], const int costab_size[2], const double
  sintab_data[], const int sintab_size[2], const double costabinv_data[], const
  int costabinv_size[2], const double sintabinv_data[], const int
  sintabinv_size[2], const creal_T wwc_data[], const int wwc_size[1], creal_T
  y_data[], int y_size[1]);
static void b_r2br_r2dit_trig_impl(const emxArray_real_T *x, int xoffInit, int
  unsigned_nRows, const emxArray_real_T *costab, const emxArray_real_T *sintab,
  emxArray_creal_T *y);
static void bluestein(const emxArray_real_T *x, int xoffInit, int nfft, int
                      nRows, const emxArray_real_T *costab, const
                      emxArray_real_T *sintab, const emxArray_real_T *costabinv,
                      const emxArray_real_T *sintabinv, const emxArray_creal_T
                      *wwc, emxArray_creal_T *y);
static void c_bluestein(const emxArray_creal_T *x, int xoffInit, int nfft, int
  nRows, const double costab_data[], const int costab_size[2], const double
  sintab_data[], const int sintab_size[2], const double costabinv_data[], const
  int costabinv_size[2], const double sintabinv_data[], const int
  sintabinv_size[2], const creal_T wwc_data[], const int wwc_size[1], creal_T
  y_data[], int y_size[1]);
static void c_r2br_r2dit_trig_impl(const emxArray_real_T *x, int xoffInit, int
  unsigned_nRows, const double costab_data[], const double sintab_data[],
  creal_T y_data[], int y_size[1]);
static void d_r2br_r2dit_trig_impl(const emxArray_creal_T *x, int xoffInit, int
  unsigned_nRows, const double costab_data[], const double sintab_data[],
  creal_T y_data[], int y_size[1]);
static void r2br_r2dit_trig_impl(const emxArray_creal_T *x, int unsigned_nRows,
  const emxArray_real_T *costab, const emxArray_real_T *sintab, emxArray_creal_T
  *y);

/* Function Definitions */
static void b_bluestein(const emxArray_real_T *x, int xoffInit, int nfft, int
  nRows, const double costab_data[], const int costab_size[2], const double
  sintab_data[], const int sintab_size[2], const double costabinv_data[], const
  int costabinv_size[2], const double sintabinv_data[], const int
  sintabinv_size[2], const creal_T wwc_data[], const int wwc_size[1], creal_T
  y_data[], int y_size[1])
{
  int minNrowsNx;
  emxArray_cuint8_T *y;
  int i60;
  int xidx;
  int y_re;
  int y_im;
  double a_re;
  double a_im;
  emxArray_creal_T *fv;
  emxArray_creal_T *r22;
  emxArray_creal_T *r23;
  emxArray_creal_T b_y_data;
  emxArray_real_T b_costab_data;
  emxArray_real_T b_sintab_data;
  emxArray_creal_T b_wwc_data;
  emxArray_real_T c_costab_data;
  emxArray_real_T c_sintab_data;
  emxArray_real_T b_costabinv_data;
  double re;
  double im;
  emxArray_real_T b_sintabinv_data;
  minNrowsNx = x->size[0];
  if (nRows < minNrowsNx) {
    minNrowsNx = nRows;
  }

  emxInit_cuint8_T(&y, 1);
  i60 = y->size[0];
  y->size[0] = nRows;
  emxEnsureCapacity_cuint8_T(y, i60);
  if (nRows > x->size[0]) {
    xidx = y->size[0];
    i60 = y->size[0];
    y->size[0] = xidx;
    emxEnsureCapacity_cuint8_T(y, i60);
    for (i60 = 0; i60 < xidx; i60++) {
      y->data[i60].re = 0U;
      y->data[i60].im = 0U;
    }
  }

  y_size[0] = y->size[0];
  xidx = y->size[0];
  for (i60 = 0; i60 < xidx; i60++) {
    y_re = y->data[i60].re;
    y_im = y->data[i60].im;
    y_data[i60].re = y_re;
    y_data[i60].im = y_im;
  }

  emxFree_cuint8_T(&y);
  xidx = xoffInit;
  for (y_re = 0; y_re < minNrowsNx; y_re++) {
    a_re = wwc_data[(nRows + y_re) - 1].re;
    a_im = wwc_data[(nRows + y_re) - 1].im;
    y_data[y_re].re = a_re * x->data[xidx];
    y_data[y_re].im = a_im * -x->data[xidx];
    xidx++;
  }

  i60 = minNrowsNx + 1;
  for (y_re = i60; y_re <= nRows; y_re++) {
    y_data[y_re - 1].re = 0.0;
    y_data[y_re - 1].im = 0.0;
  }

  emxInit_creal_T(&fv, 1);
  emxInit_creal_T(&r22, 1);
  emxInit_creal_T(&r23, 1);
  b_y_data.data = &y_data[0];
  b_y_data.size = &y_size[0];
  b_y_data.allocatedSize = -1;
  b_y_data.numDimensions = 1;
  b_y_data.canFreeData = false;
  b_costab_data.data = const_cast<double *>(&costab_data[0]);
  b_costab_data.size = const_cast<int *>(&costab_size[0]);
  b_costab_data.allocatedSize = -1;
  b_costab_data.numDimensions = 2;
  b_costab_data.canFreeData = false;
  b_sintab_data.data = const_cast<double *>(&sintab_data[0]);
  b_sintab_data.size = const_cast<int *>(&sintab_size[0]);
  b_sintab_data.allocatedSize = -1;
  b_sintab_data.numDimensions = 2;
  b_sintab_data.canFreeData = false;
  r2br_r2dit_trig_impl(&b_y_data, nfft, &b_costab_data, &b_sintab_data, r22);
  b_wwc_data.data = const_cast<creal_T *>(&wwc_data[0]);
  b_wwc_data.size = const_cast<int *>(&wwc_size[0]);
  b_wwc_data.allocatedSize = -1;
  b_wwc_data.numDimensions = 1;
  b_wwc_data.canFreeData = false;
  c_costab_data.data = const_cast<double *>(&costab_data[0]);
  c_costab_data.size = const_cast<int *>(&costab_size[0]);
  c_costab_data.allocatedSize = -1;
  c_costab_data.numDimensions = 2;
  c_costab_data.canFreeData = false;
  c_sintab_data.data = const_cast<double *>(&sintab_data[0]);
  c_sintab_data.size = const_cast<int *>(&sintab_size[0]);
  c_sintab_data.allocatedSize = -1;
  c_sintab_data.numDimensions = 2;
  c_sintab_data.canFreeData = false;
  r2br_r2dit_trig_impl(&b_wwc_data, nfft, &c_costab_data, &c_sintab_data, r23);
  i60 = fv->size[0];
  fv->size[0] = r22->size[0];
  emxEnsureCapacity_creal_T(fv, i60);
  xidx = r22->size[0];
  for (i60 = 0; i60 < xidx; i60++) {
    a_re = r22->data[i60].re;
    a_im = r22->data[i60].im;
    re = r23->data[i60].re;
    im = r23->data[i60].im;
    fv->data[i60].re = a_re * re - a_im * im;
    fv->data[i60].im = a_re * im + a_im * re;
  }

  emxFree_creal_T(&r23);
  b_costabinv_data.data = const_cast<double *>(&costabinv_data[0]);
  b_costabinv_data.size = const_cast<int *>(&costabinv_size[0]);
  b_costabinv_data.allocatedSize = -1;
  b_costabinv_data.numDimensions = 2;
  b_costabinv_data.canFreeData = false;
  b_sintabinv_data.data = const_cast<double *>(&sintabinv_data[0]);
  b_sintabinv_data.size = const_cast<int *>(&sintabinv_size[0]);
  b_sintabinv_data.allocatedSize = -1;
  b_sintabinv_data.numDimensions = 2;
  b_sintabinv_data.canFreeData = false;
  b_r2br_r2dit_trig(fv, nfft, &b_costabinv_data, &b_sintabinv_data, r22);
  i60 = fv->size[0];
  fv->size[0] = r22->size[0];
  emxEnsureCapacity_creal_T(fv, i60);
  xidx = r22->size[0];
  for (i60 = 0; i60 < xidx; i60++) {
    fv->data[i60] = r22->data[i60];
  }

  emxFree_creal_T(&r22);
  xidx = 0;
  i60 = wwc_size[0];
  for (y_re = nRows; y_re <= i60; y_re++) {
    y_data[xidx].re = wwc_data[y_re - 1].re * fv->data[y_re - 1].re +
      wwc_data[y_re - 1].im * fv->data[y_re - 1].im;
    y_data[xidx].im = wwc_data[y_re - 1].re * fv->data[y_re - 1].im -
      wwc_data[y_re - 1].im * fv->data[y_re - 1].re;
    y_data[xidx].re = wwc_data[y_re - 1].re * fv->data[y_re - 1].re +
      wwc_data[y_re - 1].im * fv->data[y_re - 1].im;
    y_data[xidx].im = wwc_data[y_re - 1].re * fv->data[y_re - 1].im -
      wwc_data[y_re - 1].im * fv->data[y_re - 1].re;
    a_re = y_data[xidx].re;
    a_im = y_data[xidx].im;
    if (a_im == 0.0) {
      y_data[xidx].re = a_re / static_cast<double>(nRows);
      y_data[xidx].im = 0.0;
    } else if (a_re == 0.0) {
      y_data[xidx].re = 0.0;
      y_data[xidx].im = a_im / static_cast<double>(nRows);
    } else {
      y_data[xidx].re = a_re / static_cast<double>(nRows);
      y_data[xidx].im = a_im / static_cast<double>(nRows);
    }

    xidx++;
  }

  emxFree_creal_T(&fv);
}

static void b_r2br_r2dit_trig_impl(const emxArray_real_T *x, int xoffInit, int
  unsigned_nRows, const emxArray_real_T *costab, const emxArray_real_T *sintab,
  emxArray_creal_T *y)
{
  int j;
  int nRowsM2;
  int nRowsD2;
  int nRowsD4;
  int iy;
  int iDelta;
  int ix;
  int ju;
  int i;
  boolean_T tst;
  double temp_re;
  double temp_im;
  int temp_re_tmp;
  double twid_re;
  double twid_im;
  j = x->size[0];
  if (j >= unsigned_nRows) {
    j = unsigned_nRows;
  }

  nRowsM2 = unsigned_nRows - 2;
  nRowsD2 = unsigned_nRows / 2;
  nRowsD4 = nRowsD2 / 2;
  iy = y->size[0];
  y->size[0] = unsigned_nRows;
  emxEnsureCapacity_creal_T(y, iy);
  if (unsigned_nRows > x->size[0]) {
    iDelta = y->size[0];
    iy = y->size[0];
    y->size[0] = iDelta;
    emxEnsureCapacity_creal_T(y, iy);
    for (iy = 0; iy < iDelta; iy++) {
      y->data[iy].re = 0.0;
      y->data[iy].im = 0.0;
    }
  }

  ix = xoffInit;
  ju = 0;
  iy = 0;
  for (i = 0; i <= j - 2; i++) {
    y->data[iy].re = x->data[ix];
    y->data[iy].im = 0.0;
    iDelta = unsigned_nRows;
    tst = true;
    while (tst) {
      iDelta >>= 1;
      ju ^= iDelta;
      tst = ((ju & iDelta) == 0);
    }

    iy = ju;
    ix++;
  }

  y->data[iy].re = x->data[ix];
  y->data[iy].im = 0.0;
  if (unsigned_nRows > 1) {
    for (i = 0; i <= nRowsM2; i += 2) {
      temp_re = y->data[i + 1].re;
      temp_im = y->data[i + 1].im;
      y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
      y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }
  }

  iDelta = 2;
  iy = 4;
  ix = 1 + ((nRowsD4 - 1) << 2);
  while (nRowsD4 > 0) {
    for (i = 0; i < ix; i += iy) {
      temp_re_tmp = i + iDelta;
      temp_re = y->data[temp_re_tmp].re;
      temp_im = y->data[temp_re_tmp].im;
      y->data[temp_re_tmp].re = y->data[i].re - temp_re;
      y->data[temp_re_tmp].im = y->data[i].im - temp_im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }

    ju = 1;
    for (j = nRowsD4; j < nRowsD2; j += nRowsD4) {
      twid_re = costab->data[j];
      twid_im = sintab->data[j];
      i = ju;
      nRowsM2 = ju + ix;
      while (i < nRowsM2) {
        temp_re_tmp = i + iDelta;
        temp_re = twid_re * y->data[temp_re_tmp].re - twid_im * y->
          data[temp_re_tmp].im;
        temp_im = twid_re * y->data[temp_re_tmp].im + twid_im * y->
          data[temp_re_tmp].re;
        y->data[temp_re_tmp].re = y->data[i].re - temp_re;
        y->data[temp_re_tmp].im = y->data[i].im - temp_im;
        y->data[i].re += temp_re;
        y->data[i].im += temp_im;
        i += iy;
      }

      ju++;
    }

    nRowsD4 /= 2;
    iDelta = iy;
    iy += iy;
    ix -= iDelta;
  }
}

static void bluestein(const emxArray_real_T *x, int xoffInit, int nfft, int
                      nRows, const emxArray_real_T *costab, const
                      emxArray_real_T *sintab, const emxArray_real_T *costabinv,
                      const emxArray_real_T *sintabinv, const emxArray_creal_T
                      *wwc, emxArray_creal_T *y)
{
  int minNrowsNx;
  int a_re_tmp;
  int xidx;
  int k;
  double a_re;
  double a_im;
  emxArray_creal_T *fv;
  emxArray_creal_T *b_fv;
  double fv_re;
  double fv_im;
  double wwc_re;
  double wwc_im;
  double b_wwc_re;
  double b_wwc_im;
  minNrowsNx = x->size[0];
  if (nRows < minNrowsNx) {
    minNrowsNx = nRows;
  }

  a_re_tmp = y->size[0];
  y->size[0] = nRows;
  emxEnsureCapacity_creal_T(y, a_re_tmp);
  if (nRows > x->size[0]) {
    xidx = y->size[0];
    a_re_tmp = y->size[0];
    y->size[0] = xidx;
    emxEnsureCapacity_creal_T(y, a_re_tmp);
    for (a_re_tmp = 0; a_re_tmp < xidx; a_re_tmp++) {
      y->data[a_re_tmp].re = 0.0;
      y->data[a_re_tmp].im = 0.0;
    }
  }

  xidx = xoffInit;
  for (k = 0; k < minNrowsNx; k++) {
    a_re_tmp = (nRows + k) - 1;
    a_re = wwc->data[a_re_tmp].re;
    a_im = wwc->data[a_re_tmp].im;
    y->data[k].re = a_re * x->data[xidx];
    y->data[k].im = a_im * -x->data[xidx];
    xidx++;
  }

  a_re_tmp = minNrowsNx + 1;
  for (k = a_re_tmp; k <= nRows; k++) {
    y->data[k - 1].re = 0.0;
    y->data[k - 1].im = 0.0;
  }

  emxInit_creal_T(&fv, 1);
  emxInit_creal_T(&b_fv, 1);
  r2br_r2dit_trig_impl(y, nfft, costab, sintab, fv);
  r2br_r2dit_trig_impl(wwc, nfft, costab, sintab, b_fv);
  a_re_tmp = b_fv->size[0];
  b_fv->size[0] = fv->size[0];
  emxEnsureCapacity_creal_T(b_fv, a_re_tmp);
  xidx = fv->size[0];
  for (a_re_tmp = 0; a_re_tmp < xidx; a_re_tmp++) {
    a_re = fv->data[a_re_tmp].re;
    a_im = fv->data[a_re_tmp].im;
    fv_re = b_fv->data[a_re_tmp].re;
    fv_im = b_fv->data[a_re_tmp].im;
    b_fv->data[a_re_tmp].re = a_re * fv_re - a_im * fv_im;
    b_fv->data[a_re_tmp].im = a_re * fv_im + a_im * fv_re;
  }

  b_r2br_r2dit_trig(b_fv, nfft, costabinv, sintabinv, fv);
  xidx = 0;
  a_re_tmp = wwc->size[0];
  emxFree_creal_T(&b_fv);
  for (k = nRows; k <= a_re_tmp; k++) {
    wwc_re = wwc->data[k - 1].re;
    a_re = fv->data[k - 1].re;
    wwc_im = wwc->data[k - 1].im;
    a_im = fv->data[k - 1].im;
    b_wwc_re = wwc->data[k - 1].re;
    fv_im = fv->data[k - 1].im;
    b_wwc_im = wwc->data[k - 1].im;
    fv_re = fv->data[k - 1].re;
    y->data[xidx].re = wwc_re * a_re + wwc_im * a_im;
    y->data[xidx].im = b_wwc_re * fv_im - b_wwc_im * fv_re;
    xidx++;
  }

  emxFree_creal_T(&fv);
}

static void c_bluestein(const emxArray_creal_T *x, int xoffInit, int nfft, int
  nRows, const double costab_data[], const int costab_size[2], const double
  sintab_data[], const int sintab_size[2], const double costabinv_data[], const
  int costabinv_size[2], const double sintabinv_data[], const int
  sintabinv_size[2], const creal_T wwc_data[], const int wwc_size[1], creal_T
  y_data[], int y_size[1])
{
  int minNrowsNx;
  emxArray_creal_T *y;
  int i66;
  int xidx;
  int k;
  double denom_re;
  double denom_im;
  emxArray_creal_T *fv;
  emxArray_creal_T *r25;
  emxArray_creal_T b_y_data;
  emxArray_real_T b_costab_data;
  emxArray_real_T b_sintab_data;
  emxArray_creal_T b_wwc_data;
  emxArray_real_T c_costab_data;
  emxArray_real_T c_sintab_data;
  emxArray_real_T b_costabinv_data;
  double re;
  double im;
  emxArray_real_T b_sintabinv_data;
  minNrowsNx = x->size[0];
  if (nRows < minNrowsNx) {
    minNrowsNx = nRows;
  }

  emxInit_creal_T(&y, 1);
  i66 = y->size[0];
  y->size[0] = nRows;
  emxEnsureCapacity_creal_T(y, i66);
  if (nRows > x->size[0]) {
    xidx = y->size[0];
    i66 = y->size[0];
    y->size[0] = xidx;
    emxEnsureCapacity_creal_T(y, i66);
    for (i66 = 0; i66 < xidx; i66++) {
      y->data[i66].re = 0.0;
      y->data[i66].im = 0.0;
    }
  }

  y_size[0] = y->size[0];
  xidx = y->size[0];
  for (i66 = 0; i66 < xidx; i66++) {
    y_data[i66] = y->data[i66];
  }

  xidx = xoffInit;
  for (k = 0; k < minNrowsNx; k++) {
    denom_re = wwc_data[(nRows + k) - 1].re;
    denom_im = wwc_data[(nRows + k) - 1].im;
    y_data[k].re = denom_re * x->data[xidx].re + denom_im * x->data[xidx].im;
    y_data[k].im = denom_re * x->data[xidx].im - denom_im * x->data[xidx].re;
    xidx++;
  }

  i66 = minNrowsNx + 1;
  for (k = i66; k <= nRows; k++) {
    y_data[k - 1].re = 0.0;
    y_data[k - 1].im = 0.0;
  }

  emxInit_creal_T(&fv, 1);
  emxInit_creal_T(&r25, 1);
  b_y_data.data = &y_data[0];
  b_y_data.size = &y_size[0];
  b_y_data.allocatedSize = -1;
  b_y_data.numDimensions = 1;
  b_y_data.canFreeData = false;
  b_costab_data.data = const_cast<double *>(&costab_data[0]);
  b_costab_data.size = const_cast<int *>(&costab_size[0]);
  b_costab_data.allocatedSize = -1;
  b_costab_data.numDimensions = 2;
  b_costab_data.canFreeData = false;
  b_sintab_data.data = const_cast<double *>(&sintab_data[0]);
  b_sintab_data.size = const_cast<int *>(&sintab_size[0]);
  b_sintab_data.allocatedSize = -1;
  b_sintab_data.numDimensions = 2;
  b_sintab_data.canFreeData = false;
  r2br_r2dit_trig_impl(&b_y_data, nfft, &b_costab_data, &b_sintab_data, y);
  b_wwc_data.data = const_cast<creal_T *>(&wwc_data[0]);
  b_wwc_data.size = const_cast<int *>(&wwc_size[0]);
  b_wwc_data.allocatedSize = -1;
  b_wwc_data.numDimensions = 1;
  b_wwc_data.canFreeData = false;
  c_costab_data.data = const_cast<double *>(&costab_data[0]);
  c_costab_data.size = const_cast<int *>(&costab_size[0]);
  c_costab_data.allocatedSize = -1;
  c_costab_data.numDimensions = 2;
  c_costab_data.canFreeData = false;
  c_sintab_data.data = const_cast<double *>(&sintab_data[0]);
  c_sintab_data.size = const_cast<int *>(&sintab_size[0]);
  c_sintab_data.allocatedSize = -1;
  c_sintab_data.numDimensions = 2;
  c_sintab_data.canFreeData = false;
  r2br_r2dit_trig_impl(&b_wwc_data, nfft, &c_costab_data, &c_sintab_data, r25);
  i66 = fv->size[0];
  fv->size[0] = y->size[0];
  emxEnsureCapacity_creal_T(fv, i66);
  xidx = y->size[0];
  for (i66 = 0; i66 < xidx; i66++) {
    denom_re = y->data[i66].re;
    denom_im = y->data[i66].im;
    re = r25->data[i66].re;
    im = r25->data[i66].im;
    fv->data[i66].re = denom_re * re - denom_im * im;
    fv->data[i66].im = denom_re * im + denom_im * re;
  }

  emxFree_creal_T(&r25);
  b_costabinv_data.data = const_cast<double *>(&costabinv_data[0]);
  b_costabinv_data.size = const_cast<int *>(&costabinv_size[0]);
  b_costabinv_data.allocatedSize = -1;
  b_costabinv_data.numDimensions = 2;
  b_costabinv_data.canFreeData = false;
  b_sintabinv_data.data = const_cast<double *>(&sintabinv_data[0]);
  b_sintabinv_data.size = const_cast<int *>(&sintabinv_size[0]);
  b_sintabinv_data.allocatedSize = -1;
  b_sintabinv_data.numDimensions = 2;
  b_sintabinv_data.canFreeData = false;
  b_r2br_r2dit_trig(fv, nfft, &b_costabinv_data, &b_sintabinv_data, y);
  i66 = fv->size[0];
  fv->size[0] = y->size[0];
  emxEnsureCapacity_creal_T(fv, i66);
  xidx = y->size[0];
  for (i66 = 0; i66 < xidx; i66++) {
    fv->data[i66] = y->data[i66];
  }

  emxFree_creal_T(&y);
  xidx = 0;
  i66 = wwc_size[0];
  for (k = nRows; k <= i66; k++) {
    y_data[xidx].re = wwc_data[k - 1].re * fv->data[k - 1].re + wwc_data[k - 1].
      im * fv->data[k - 1].im;
    y_data[xidx].im = wwc_data[k - 1].re * fv->data[k - 1].im - wwc_data[k - 1].
      im * fv->data[k - 1].re;
    y_data[xidx].re = wwc_data[k - 1].re * fv->data[k - 1].re + wwc_data[k - 1].
      im * fv->data[k - 1].im;
    y_data[xidx].im = wwc_data[k - 1].re * fv->data[k - 1].im - wwc_data[k - 1].
      im * fv->data[k - 1].re;
    denom_re = y_data[xidx].re;
    denom_im = y_data[xidx].im;
    if (denom_im == 0.0) {
      y_data[xidx].re = denom_re / static_cast<double>(nRows);
      y_data[xidx].im = 0.0;
    } else if (denom_re == 0.0) {
      y_data[xidx].re = 0.0;
      y_data[xidx].im = denom_im / static_cast<double>(nRows);
    } else {
      y_data[xidx].re = denom_re / static_cast<double>(nRows);
      y_data[xidx].im = denom_im / static_cast<double>(nRows);
    }

    xidx++;
  }

  emxFree_creal_T(&fv);
}

static void c_r2br_r2dit_trig_impl(const emxArray_real_T *x, int xoffInit, int
  unsigned_nRows, const double costab_data[], const double sintab_data[],
  creal_T y_data[], int y_size[1])
{
  int j;
  emxArray_cuint8_T *y;
  int nRowsM2;
  int nRowsD2;
  int nRowsD4;
  int iy;
  int iDelta;
  int ix;
  int ju;
  int i;
  boolean_T tst;
  double temp_re;
  double temp_im;
  double twid_re;
  double twid_im;
  int temp_re_tmp;
  j = x->size[0];
  if (j >= unsigned_nRows) {
    j = unsigned_nRows;
  }

  emxInit_cuint8_T(&y, 1);
  nRowsM2 = unsigned_nRows - 2;
  nRowsD2 = unsigned_nRows / 2;
  nRowsD4 = nRowsD2 / 2;
  iy = y->size[0];
  y->size[0] = unsigned_nRows;
  emxEnsureCapacity_cuint8_T(y, iy);
  if (unsigned_nRows > x->size[0]) {
    iDelta = y->size[0];
    iy = y->size[0];
    y->size[0] = iDelta;
    emxEnsureCapacity_cuint8_T(y, iy);
    for (iy = 0; iy < iDelta; iy++) {
      y->data[iy].re = 0U;
      y->data[iy].im = 0U;
    }
  }

  y_size[0] = y->size[0];
  iDelta = y->size[0];
  for (iy = 0; iy < iDelta; iy++) {
    ix = y->data[iy].re;
    ju = y->data[iy].im;
    y_data[iy].re = ix;
    y_data[iy].im = ju;
  }

  emxFree_cuint8_T(&y);
  ix = xoffInit;
  ju = 0;
  iy = 0;
  for (i = 0; i <= j - 2; i++) {
    y_data[iy].re = x->data[ix];
    y_data[iy].im = 0.0;
    iDelta = unsigned_nRows;
    tst = true;
    while (tst) {
      iDelta >>= 1;
      ju ^= iDelta;
      tst = ((ju & iDelta) == 0);
    }

    iy = ju;
    ix++;
  }

  y_data[iy].re = x->data[ix];
  y_data[iy].im = 0.0;
  if (unsigned_nRows > 1) {
    for (i = 0; i <= nRowsM2; i += 2) {
      temp_re = y_data[i + 1].re;
      temp_im = y_data[i + 1].im;
      twid_re = y_data[i].re;
      twid_im = y_data[i].im;
      y_data[i + 1].re = y_data[i].re - y_data[i + 1].re;
      y_data[i + 1].im = y_data[i].im - y_data[i + 1].im;
      twid_re += temp_re;
      twid_im += temp_im;
      y_data[i].re = twid_re;
      y_data[i].im = twid_im;
    }
  }

  iDelta = 2;
  iy = 4;
  ix = 1 + ((nRowsD4 - 1) << 2);
  while (nRowsD4 > 0) {
    for (i = 0; i < ix; i += iy) {
      temp_re_tmp = i + iDelta;
      temp_re = y_data[temp_re_tmp].re;
      temp_im = y_data[i + iDelta].im;
      y_data[temp_re_tmp].re = y_data[i].re - y_data[temp_re_tmp].re;
      y_data[temp_re_tmp].im = y_data[i].im - temp_im;
      y_data[i].re += temp_re;
      y_data[i].im += temp_im;
    }

    ju = 1;
    for (j = nRowsD4; j < nRowsD2; j += nRowsD4) {
      twid_re = costab_data[j];
      twid_im = sintab_data[j];
      i = ju;
      nRowsM2 = ju + ix;
      while (i < nRowsM2) {
        temp_re_tmp = i + iDelta;
        temp_re = twid_re * y_data[temp_re_tmp].re - twid_im * y_data[i + iDelta]
          .im;
        temp_im = twid_re * y_data[i + iDelta].im + twid_im * y_data[i + iDelta]
          .re;
        y_data[temp_re_tmp].re = y_data[i].re - temp_re;
        y_data[temp_re_tmp].im = y_data[i].im - temp_im;
        y_data[i].re += temp_re;
        y_data[i].im += temp_im;
        i += iy;
      }

      ju++;
    }

    nRowsD4 /= 2;
    iDelta = iy;
    iy += iy;
    ix -= iDelta;
  }
}

static void d_r2br_r2dit_trig_impl(const emxArray_creal_T *x, int xoffInit, int
  unsigned_nRows, const double costab_data[], const double sintab_data[],
  creal_T y_data[], int y_size[1])
{
  int j;
  emxArray_cuint8_T *y;
  int nRowsM2;
  int nRowsD2;
  int nRowsD4;
  int iy;
  int iDelta;
  int ix;
  int ju;
  int i;
  boolean_T tst;
  double temp_re;
  double temp_im;
  double twid_re;
  double twid_im;
  int temp_re_tmp;
  j = x->size[0];
  if (j >= unsigned_nRows) {
    j = unsigned_nRows;
  }

  emxInit_cuint8_T(&y, 1);
  nRowsM2 = unsigned_nRows - 2;
  nRowsD2 = unsigned_nRows / 2;
  nRowsD4 = nRowsD2 / 2;
  iy = y->size[0];
  y->size[0] = unsigned_nRows;
  emxEnsureCapacity_cuint8_T(y, iy);
  if (unsigned_nRows > x->size[0]) {
    iDelta = y->size[0];
    iy = y->size[0];
    y->size[0] = iDelta;
    emxEnsureCapacity_cuint8_T(y, iy);
    for (iy = 0; iy < iDelta; iy++) {
      y->data[iy].re = 0U;
      y->data[iy].im = 0U;
    }
  }

  y_size[0] = y->size[0];
  iDelta = y->size[0];
  for (iy = 0; iy < iDelta; iy++) {
    ix = y->data[iy].re;
    ju = y->data[iy].im;
    y_data[iy].re = ix;
    y_data[iy].im = ju;
  }

  emxFree_cuint8_T(&y);
  ix = xoffInit;
  ju = 0;
  iy = 0;
  for (i = 0; i <= j - 2; i++) {
    y_data[iy] = x->data[ix];
    iDelta = unsigned_nRows;
    tst = true;
    while (tst) {
      iDelta >>= 1;
      ju ^= iDelta;
      tst = ((ju & iDelta) == 0);
    }

    iy = ju;
    ix++;
  }

  y_data[iy] = x->data[ix];
  if (unsigned_nRows > 1) {
    for (i = 0; i <= nRowsM2; i += 2) {
      temp_re = y_data[i + 1].re;
      temp_im = y_data[i + 1].im;
      twid_re = y_data[i].re;
      twid_im = y_data[i].im;
      y_data[i + 1].re = y_data[i].re - y_data[i + 1].re;
      y_data[i + 1].im = y_data[i].im - y_data[i + 1].im;
      twid_re += temp_re;
      twid_im += temp_im;
      y_data[i].re = twid_re;
      y_data[i].im = twid_im;
    }
  }

  iDelta = 2;
  iy = 4;
  ix = 1 + ((nRowsD4 - 1) << 2);
  while (nRowsD4 > 0) {
    for (i = 0; i < ix; i += iy) {
      temp_re_tmp = i + iDelta;
      temp_re = y_data[temp_re_tmp].re;
      temp_im = y_data[i + iDelta].im;
      y_data[temp_re_tmp].re = y_data[i].re - y_data[temp_re_tmp].re;
      y_data[temp_re_tmp].im = y_data[i].im - temp_im;
      y_data[i].re += temp_re;
      y_data[i].im += temp_im;
    }

    ju = 1;
    for (j = nRowsD4; j < nRowsD2; j += nRowsD4) {
      twid_re = costab_data[j];
      twid_im = sintab_data[j];
      i = ju;
      nRowsM2 = ju + ix;
      while (i < nRowsM2) {
        temp_re_tmp = i + iDelta;
        temp_re = twid_re * y_data[temp_re_tmp].re - twid_im * y_data[i + iDelta]
          .im;
        temp_im = twid_re * y_data[i + iDelta].im + twid_im * y_data[i + iDelta]
          .re;
        y_data[temp_re_tmp].re = y_data[i].re - temp_re;
        y_data[temp_re_tmp].im = y_data[i].im - temp_im;
        y_data[i].re += temp_re;
        y_data[i].im += temp_im;
        i += iy;
      }

      ju++;
    }

    nRowsD4 /= 2;
    iDelta = iy;
    iy += iy;
    ix -= iDelta;
  }
}

static void r2br_r2dit_trig_impl(const emxArray_creal_T *x, int unsigned_nRows,
  const emxArray_real_T *costab, const emxArray_real_T *sintab, emxArray_creal_T
  *y)
{
  int j;
  int nRowsM2;
  int nRowsD2;
  int nRowsD4;
  int iy;
  int iDelta;
  int ix;
  int ju;
  int i;
  boolean_T tst;
  double temp_re;
  double temp_im;
  int temp_re_tmp;
  double twid_re;
  double twid_im;
  j = x->size[0];
  if (j >= unsigned_nRows) {
    j = unsigned_nRows;
  }

  nRowsM2 = unsigned_nRows - 2;
  nRowsD2 = unsigned_nRows / 2;
  nRowsD4 = nRowsD2 / 2;
  iy = y->size[0];
  y->size[0] = unsigned_nRows;
  emxEnsureCapacity_creal_T(y, iy);
  if (unsigned_nRows > x->size[0]) {
    iDelta = y->size[0];
    iy = y->size[0];
    y->size[0] = iDelta;
    emxEnsureCapacity_creal_T(y, iy);
    for (iy = 0; iy < iDelta; iy++) {
      y->data[iy].re = 0.0;
      y->data[iy].im = 0.0;
    }
  }

  ix = 0;
  ju = 0;
  iy = 0;
  for (i = 0; i <= j - 2; i++) {
    y->data[iy] = x->data[ix];
    iDelta = unsigned_nRows;
    tst = true;
    while (tst) {
      iDelta >>= 1;
      ju ^= iDelta;
      tst = ((ju & iDelta) == 0);
    }

    iy = ju;
    ix++;
  }

  y->data[iy] = x->data[ix];
  if (unsigned_nRows > 1) {
    for (i = 0; i <= nRowsM2; i += 2) {
      temp_re = y->data[i + 1].re;
      temp_im = y->data[i + 1].im;
      y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
      y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }
  }

  iDelta = 2;
  iy = 4;
  ix = 1 + ((nRowsD4 - 1) << 2);
  while (nRowsD4 > 0) {
    for (i = 0; i < ix; i += iy) {
      temp_re_tmp = i + iDelta;
      temp_re = y->data[temp_re_tmp].re;
      temp_im = y->data[temp_re_tmp].im;
      y->data[temp_re_tmp].re = y->data[i].re - temp_re;
      y->data[temp_re_tmp].im = y->data[i].im - temp_im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }

    ju = 1;
    for (j = nRowsD4; j < nRowsD2; j += nRowsD4) {
      twid_re = costab->data[j];
      twid_im = sintab->data[j];
      i = ju;
      nRowsM2 = ju + ix;
      while (i < nRowsM2) {
        temp_re_tmp = i + iDelta;
        temp_re = twid_re * y->data[temp_re_tmp].re - twid_im * y->
          data[temp_re_tmp].im;
        temp_im = twid_re * y->data[temp_re_tmp].im + twid_im * y->
          data[temp_re_tmp].re;
        y->data[temp_re_tmp].re = y->data[i].re - temp_re;
        y->data[temp_re_tmp].im = y->data[i].im - temp_im;
        y->data[i].re += temp_re;
        y->data[i].im += temp_im;
        i += iy;
      }

      ju++;
    }

    nRowsD4 /= 2;
    iDelta = iy;
    iy += iy;
    ix -= iDelta;
  }
}

void b_dobluesteinfft(const emxArray_real_T *x, int N2, int n1, const
                      emxArray_real_T *costab, const emxArray_real_T *sintab,
                      const emxArray_real_T *sintabinv, emxArray_creal_T *y)
{
  short sx_idx_1;
  emxArray_creal_T *wwc;
  int nrows;
  int ub_loop;
  int k;
  int loop_ub;
  emxArray_creal_T *rwork;
  int b_loop_ub;
  int i38;
  int xoff;
  int l;
  sx_idx_1 = static_cast<short>(x->size[1]);
  emxInit_creal_T(&wwc, 1);
  bluesteinSetup(n1, wwc);
  nrows = x->size[0];
  ub_loop = y->size[0] * y->size[1];
  y->size[0] = n1;
  y->size[1] = static_cast<short>(x->size[1]);
  emxEnsureCapacity_creal_T(y, ub_loop);
  if (n1 > x->size[0]) {
    ub_loop = y->size[0] * y->size[1];
    emxEnsureCapacity_creal_T(y, ub_loop);
    loop_ub = y->size[1];
    for (ub_loop = 0; ub_loop < loop_ub; ub_loop++) {
      b_loop_ub = y->size[0];
      for (i38 = 0; i38 < b_loop_ub; i38++) {
        y->data[i38 + y->size[0] * ub_loop].re = 0.0;
        y->data[i38 + y->size[0] * ub_loop].im = 0.0;
      }
    }
  }

  ub_loop = sx_idx_1 - 1;

#pragma omp parallel \
 num_threads(omp_get_max_threads()) \
 private(rwork,xoff,l)

  {
    emxInit_creal_T(&rwork, 1);

#pragma omp for nowait

    for (k = 0; k <= ub_loop; k++) {
      xoff = k * nrows;
      bluestein(x, xoff, N2, n1, costab, sintab, costab, sintabinv, wwc, rwork);
      for (l = 0; l < n1; l++) {
        xoff = 1 + l;
        y->data[(xoff + y->size[0] * k) - 1] = rwork->data[xoff - 1];
      }
    }

    emxFree_creal_T(&rwork);
  }

  emxFree_creal_T(&wwc);
}

void b_generate_twiddle_tables(int nRows, boolean_T useRadix2, double
  costab_data[], int costab_size[2], double sintab_data[], int sintab_size[2],
  double sintabinv_data[], int sintabinv_size[2])
{
  emxArray_real_T *costab1q;
  double e;
  int n;
  int i46;
  int nd2;
  int k;
  emxArray_real_T *costab;
  emxArray_real_T *sintab;
  emxArray_real_T *sintabinv;
  emxInit_real_T(&costab1q, 2);
  e = 6.2831853071795862 / static_cast<double>(nRows);
  n = nRows / 2 / 2;
  i46 = costab1q->size[0] * costab1q->size[1];
  costab1q->size[0] = 1;
  costab1q->size[1] = n + 1;
  emxEnsureCapacity_real_T(costab1q, i46);
  costab1q->data[0] = 1.0;
  nd2 = n / 2 - 1;
  for (k = 0; k <= nd2; k++) {
    costab1q->data[1 + k] = std::cos(e * (1.0 + static_cast<double>(k)));
  }

  i46 = nd2 + 2;
  nd2 = n - 1;
  for (k = i46; k <= nd2; k++) {
    costab1q->data[k] = std::sin(e * static_cast<double>((n - k)));
  }

  costab1q->data[n] = 0.0;
  emxInit_real_T(&costab, 2);
  emxInit_real_T(&sintab, 2);
  if (!useRadix2) {
    emxInit_real_T(&sintabinv, 2);
    n = costab1q->size[1] - 1;
    nd2 = (costab1q->size[1] - 1) << 1;
    i46 = costab->size[0] * costab->size[1];
    costab->size[0] = 1;
    costab->size[1] = nd2 + 1;
    emxEnsureCapacity_real_T(costab, i46);
    i46 = sintab->size[0] * sintab->size[1];
    sintab->size[0] = 1;
    sintab->size[1] = nd2 + 1;
    emxEnsureCapacity_real_T(sintab, i46);
    costab->data[0] = 1.0;
    sintab->data[0] = 0.0;
    i46 = sintabinv->size[0] * sintabinv->size[1];
    sintabinv->size[0] = 1;
    sintabinv->size[1] = nd2 + 1;
    emxEnsureCapacity_real_T(sintabinv, i46);
    for (k = 0; k < n; k++) {
      sintabinv->data[1 + k] = costab1q->data[(n - k) - 1];
    }

    i46 = costab1q->size[1];
    for (k = i46; k <= nd2; k++) {
      sintabinv->data[k] = costab1q->data[k - n];
    }

    for (k = 0; k < n; k++) {
      costab->data[1 + k] = costab1q->data[1 + k];
      sintab->data[1 + k] = -costab1q->data[(n - k) - 1];
    }

    i46 = costab1q->size[1];
    for (k = i46; k <= nd2; k++) {
      costab->data[k] = -costab1q->data[nd2 - k];
      sintab->data[k] = -costab1q->data[k - n];
    }

    costab_size[0] = 1;
    costab_size[1] = costab->size[1];
    nd2 = costab->size[0] * costab->size[1];
    for (i46 = 0; i46 < nd2; i46++) {
      costab_data[i46] = costab->data[i46];
    }

    sintab_size[0] = 1;
    sintab_size[1] = sintab->size[1];
    nd2 = sintab->size[0] * sintab->size[1];
    for (i46 = 0; i46 < nd2; i46++) {
      sintab_data[i46] = sintab->data[i46];
    }

    sintabinv_size[0] = 1;
    sintabinv_size[1] = sintabinv->size[1];
    nd2 = sintabinv->size[0] * sintabinv->size[1];
    for (i46 = 0; i46 < nd2; i46++) {
      sintabinv_data[i46] = sintabinv->data[i46];
    }

    emxFree_real_T(&sintabinv);
  } else {
    n = costab1q->size[1] - 1;
    nd2 = (costab1q->size[1] - 1) << 1;
    i46 = costab->size[0] * costab->size[1];
    costab->size[0] = 1;
    costab->size[1] = nd2 + 1;
    emxEnsureCapacity_real_T(costab, i46);
    i46 = sintab->size[0] * sintab->size[1];
    sintab->size[0] = 1;
    sintab->size[1] = nd2 + 1;
    emxEnsureCapacity_real_T(sintab, i46);
    costab->data[0] = 1.0;
    sintab->data[0] = 0.0;
    for (k = 0; k < n; k++) {
      costab->data[1 + k] = costab1q->data[1 + k];
      sintab->data[1 + k] = costab1q->data[(n - k) - 1];
    }

    i46 = costab1q->size[1];
    for (k = i46; k <= nd2; k++) {
      costab->data[k] = -costab1q->data[nd2 - k];
      sintab->data[k] = costab1q->data[k - n];
    }

    costab_size[0] = 1;
    costab_size[1] = costab->size[1];
    nd2 = costab->size[0] * costab->size[1];
    for (i46 = 0; i46 < nd2; i46++) {
      costab_data[i46] = costab->data[i46];
    }

    sintab_size[0] = 1;
    sintab_size[1] = sintab->size[1];
    nd2 = sintab->size[0] * sintab->size[1];
    for (i46 = 0; i46 < nd2; i46++) {
      sintab_data[i46] = sintab->data[i46];
    }

    sintabinv_size[0] = 1;
    sintabinv_size[1] = 0;
  }

  emxFree_real_T(&costab1q);
  emxFree_real_T(&sintab);
  emxFree_real_T(&costab);
}

void b_r2br_r2dit_trig(const emxArray_creal_T *x, int n1_unsigned, const
  emxArray_real_T *costab, const emxArray_real_T *sintab, emxArray_creal_T *y)
{
  int j;
  int nRowsM2;
  int nRowsD2;
  int nRowsD4;
  int iy;
  int iDelta;
  int ix;
  int ju;
  int i;
  boolean_T tst;
  double temp_re;
  double temp_im;
  int temp_re_tmp;
  double twid_re;
  double twid_im;
  j = x->size[0];
  if (j >= n1_unsigned) {
    j = n1_unsigned;
  }

  nRowsM2 = n1_unsigned - 2;
  nRowsD2 = n1_unsigned / 2;
  nRowsD4 = nRowsD2 / 2;
  iy = y->size[0];
  y->size[0] = n1_unsigned;
  emxEnsureCapacity_creal_T(y, iy);
  if (n1_unsigned > x->size[0]) {
    iDelta = y->size[0];
    iy = y->size[0];
    y->size[0] = iDelta;
    emxEnsureCapacity_creal_T(y, iy);
    for (iy = 0; iy < iDelta; iy++) {
      y->data[iy].re = 0.0;
      y->data[iy].im = 0.0;
    }
  }

  ix = 0;
  ju = 0;
  iy = 0;
  for (i = 0; i <= j - 2; i++) {
    y->data[iy] = x->data[ix];
    iDelta = n1_unsigned;
    tst = true;
    while (tst) {
      iDelta >>= 1;
      ju ^= iDelta;
      tst = ((ju & iDelta) == 0);
    }

    iy = ju;
    ix++;
  }

  y->data[iy] = x->data[ix];
  if (n1_unsigned > 1) {
    for (i = 0; i <= nRowsM2; i += 2) {
      temp_re = y->data[i + 1].re;
      temp_im = y->data[i + 1].im;
      y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
      y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }
  }

  iDelta = 2;
  iy = 4;
  ix = 1 + ((nRowsD4 - 1) << 2);
  while (nRowsD4 > 0) {
    for (i = 0; i < ix; i += iy) {
      temp_re_tmp = i + iDelta;
      temp_re = y->data[temp_re_tmp].re;
      temp_im = y->data[temp_re_tmp].im;
      y->data[temp_re_tmp].re = y->data[i].re - temp_re;
      y->data[temp_re_tmp].im = y->data[i].im - temp_im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }

    ju = 1;
    for (j = nRowsD4; j < nRowsD2; j += nRowsD4) {
      twid_re = costab->data[j];
      twid_im = sintab->data[j];
      i = ju;
      nRowsM2 = ju + ix;
      while (i < nRowsM2) {
        temp_re_tmp = i + iDelta;
        temp_re = twid_re * y->data[temp_re_tmp].re - twid_im * y->
          data[temp_re_tmp].im;
        temp_im = twid_re * y->data[temp_re_tmp].im + twid_im * y->
          data[temp_re_tmp].re;
        y->data[temp_re_tmp].re = y->data[i].re - temp_re;
        y->data[temp_re_tmp].im = y->data[i].im - temp_im;
        y->data[i].re += temp_re;
        y->data[i].im += temp_im;
        i += iy;
      }

      ju++;
    }

    nRowsD4 /= 2;
    iDelta = iy;
    iy += iy;
    ix -= iDelta;
  }

  if (y->size[0] > 1) {
    temp_re = 1.0 / static_cast<double>(y->size[0]);
    iy = y->size[0];
    emxEnsureCapacity_creal_T(y, iy);
    iDelta = y->size[0];
    for (iy = 0; iy < iDelta; iy++) {
      y->data[iy].re *= temp_re;
      y->data[iy].im *= temp_re;
    }
  }
}

void c_dobluesteinfft(const double x_data[], const int x_size[1], int N2, int n1,
                      const double costab_data[], const int costab_size[2],
                      const double sintab_data[], const int sintab_size[2],
                      const double sintabinv_data[], const int sintabinv_size[2],
                      creal_T y_data[], int y_size[1])
{
  static creal_T wwc_data[2497];
  int wwc_size[1];
  int minNrowsNx;
  emxArray_cuint8_T *y;
  int i47;
  int xidx;
  int y_re;
  int y_im;
  double a_re;
  double a_im;
  emxArray_creal_T *fv;
  emxArray_creal_T *r19;
  emxArray_creal_T *r20;
  emxArray_creal_T b_y_data;
  emxArray_real_T b_costab_data;
  emxArray_real_T b_sintab_data;
  emxArray_creal_T b_wwc_data;
  emxArray_real_T c_costab_data;
  emxArray_real_T c_sintab_data;
  emxArray_real_T d_costab_data;
  double re;
  double im;
  emxArray_real_T b_sintabinv_data;
  b_bluesteinSetup(n1, wwc_data, wwc_size);
  minNrowsNx = x_size[0];
  if (n1 < minNrowsNx) {
    minNrowsNx = n1;
  }

  emxInit_cuint8_T(&y, 1);
  i47 = y->size[0];
  y->size[0] = n1;
  emxEnsureCapacity_cuint8_T(y, i47);
  if (n1 > x_size[0]) {
    xidx = y->size[0];
    i47 = y->size[0];
    y->size[0] = xidx;
    emxEnsureCapacity_cuint8_T(y, i47);
    for (i47 = 0; i47 < xidx; i47++) {
      y->data[i47].re = 0U;
      y->data[i47].im = 0U;
    }
  }

  y_size[0] = y->size[0];
  xidx = y->size[0];
  for (i47 = 0; i47 < xidx; i47++) {
    y_re = y->data[i47].re;
    y_im = y->data[i47].im;
    y_data[i47].re = y_re;
    y_data[i47].im = y_im;
  }

  emxFree_cuint8_T(&y);
  xidx = 0;
  for (y_re = 0; y_re < minNrowsNx; y_re++) {
    a_re = wwc_data[(n1 + y_re) - 1].re;
    a_im = wwc_data[(n1 + y_re) - 1].im;
    y_data[y_re].re = a_re * x_data[xidx];
    y_data[y_re].im = a_im * -x_data[xidx];
    xidx++;
  }

  i47 = minNrowsNx + 1;
  for (y_re = i47; y_re <= n1; y_re++) {
    y_data[y_re - 1].re = 0.0;
    y_data[y_re - 1].im = 0.0;
  }

  emxInit_creal_T(&fv, 1);
  emxInit_creal_T(&r19, 1);
  emxInit_creal_T(&r20, 1);
  b_y_data.data = &y_data[0];
  b_y_data.size = &y_size[0];
  b_y_data.allocatedSize = -1;
  b_y_data.numDimensions = 1;
  b_y_data.canFreeData = false;
  b_costab_data.data = const_cast<double *>(&costab_data[0]);
  b_costab_data.size = const_cast<int *>(&costab_size[0]);
  b_costab_data.allocatedSize = -1;
  b_costab_data.numDimensions = 2;
  b_costab_data.canFreeData = false;
  b_sintab_data.data = const_cast<double *>(&sintab_data[0]);
  b_sintab_data.size = const_cast<int *>(&sintab_size[0]);
  b_sintab_data.allocatedSize = -1;
  b_sintab_data.numDimensions = 2;
  b_sintab_data.canFreeData = false;
  r2br_r2dit_trig_impl(&b_y_data, N2, &b_costab_data, &b_sintab_data, r19);
  b_wwc_data.data = &wwc_data[0];
  b_wwc_data.size = &wwc_size[0];
  b_wwc_data.allocatedSize = 2497;
  b_wwc_data.numDimensions = 1;
  b_wwc_data.canFreeData = false;
  c_costab_data.data = const_cast<double *>(&costab_data[0]);
  c_costab_data.size = const_cast<int *>(&costab_size[0]);
  c_costab_data.allocatedSize = -1;
  c_costab_data.numDimensions = 2;
  c_costab_data.canFreeData = false;
  c_sintab_data.data = const_cast<double *>(&sintab_data[0]);
  c_sintab_data.size = const_cast<int *>(&sintab_size[0]);
  c_sintab_data.allocatedSize = -1;
  c_sintab_data.numDimensions = 2;
  c_sintab_data.canFreeData = false;
  r2br_r2dit_trig_impl(&b_wwc_data, N2, &c_costab_data, &c_sintab_data, r20);
  i47 = fv->size[0];
  fv->size[0] = r19->size[0];
  emxEnsureCapacity_creal_T(fv, i47);
  xidx = r19->size[0];
  for (i47 = 0; i47 < xidx; i47++) {
    a_re = r19->data[i47].re;
    a_im = r19->data[i47].im;
    re = r20->data[i47].re;
    im = r20->data[i47].im;
    fv->data[i47].re = a_re * re - a_im * im;
    fv->data[i47].im = a_re * im + a_im * re;
  }

  emxFree_creal_T(&r20);
  d_costab_data.data = const_cast<double *>(&costab_data[0]);
  d_costab_data.size = const_cast<int *>(&costab_size[0]);
  d_costab_data.allocatedSize = -1;
  d_costab_data.numDimensions = 2;
  d_costab_data.canFreeData = false;
  b_sintabinv_data.data = const_cast<double *>(&sintabinv_data[0]);
  b_sintabinv_data.size = const_cast<int *>(&sintabinv_size[0]);
  b_sintabinv_data.allocatedSize = -1;
  b_sintabinv_data.numDimensions = 2;
  b_sintabinv_data.canFreeData = false;
  b_r2br_r2dit_trig(fv, N2, &d_costab_data, &b_sintabinv_data, r19);
  i47 = fv->size[0];
  fv->size[0] = r19->size[0];
  emxEnsureCapacity_creal_T(fv, i47);
  xidx = r19->size[0];
  for (i47 = 0; i47 < xidx; i47++) {
    fv->data[i47] = r19->data[i47];
  }

  emxFree_creal_T(&r19);
  xidx = 0;
  i47 = wwc_size[0];
  for (y_re = n1; y_re <= i47; y_re++) {
    y_data[xidx].re = wwc_data[y_re - 1].re * fv->data[y_re - 1].re +
      wwc_data[y_re - 1].im * fv->data[y_re - 1].im;
    y_data[xidx].im = wwc_data[y_re - 1].re * fv->data[y_re - 1].im -
      wwc_data[y_re - 1].im * fv->data[y_re - 1].re;
    y_data[xidx].re = wwc_data[y_re - 1].re * fv->data[y_re - 1].re +
      wwc_data[y_re - 1].im * fv->data[y_re - 1].im;
    y_data[xidx].im = wwc_data[y_re - 1].re * fv->data[y_re - 1].im -
      wwc_data[y_re - 1].im * fv->data[y_re - 1].re;
    a_re = y_data[xidx].re;
    a_im = y_data[xidx].im;
    if (a_im == 0.0) {
      y_data[xidx].re = a_re / static_cast<double>(n1);
      y_data[xidx].im = 0.0;
    } else if (a_re == 0.0) {
      y_data[xidx].re = 0.0;
      y_data[xidx].im = a_im / static_cast<double>(n1);
    } else {
      y_data[xidx].re = a_re / static_cast<double>(n1);
      y_data[xidx].im = a_im / static_cast<double>(n1);
    }

    xidx++;
  }

  emxFree_creal_T(&fv);
}

void c_generate_twiddle_tables(int nRows, boolean_T useRadix2, emxArray_real_T
  *costab, emxArray_real_T *sintab, emxArray_real_T *sintabinv)
{
  emxArray_real_T *costab1q;
  double e;
  int n;
  int i73;
  int nd2;
  int k;
  emxInit_real_T(&costab1q, 2);
  e = 6.2831853071795862 / static_cast<double>(nRows);
  n = nRows / 2 / 2;
  i73 = costab1q->size[0] * costab1q->size[1];
  costab1q->size[0] = 1;
  costab1q->size[1] = n + 1;
  emxEnsureCapacity_real_T(costab1q, i73);
  costab1q->data[0] = 1.0;
  nd2 = n / 2 - 1;
  for (k = 0; k <= nd2; k++) {
    costab1q->data[1 + k] = std::cos(e * (1.0 + static_cast<double>(k)));
  }

  i73 = nd2 + 2;
  nd2 = n - 1;
  for (k = i73; k <= nd2; k++) {
    costab1q->data[k] = std::sin(e * static_cast<double>((n - k)));
  }

  costab1q->data[n] = 0.0;
  if (!useRadix2) {
    n = costab1q->size[1] - 1;
    nd2 = (costab1q->size[1] - 1) << 1;
    i73 = costab->size[0] * costab->size[1];
    costab->size[0] = 1;
    costab->size[1] = nd2 + 1;
    emxEnsureCapacity_real_T(costab, i73);
    i73 = sintab->size[0] * sintab->size[1];
    sintab->size[0] = 1;
    sintab->size[1] = nd2 + 1;
    emxEnsureCapacity_real_T(sintab, i73);
    costab->data[0] = 1.0;
    sintab->data[0] = 0.0;
    i73 = sintabinv->size[0] * sintabinv->size[1];
    sintabinv->size[0] = 1;
    sintabinv->size[1] = nd2 + 1;
    emxEnsureCapacity_real_T(sintabinv, i73);
    for (k = 0; k < n; k++) {
      sintabinv->data[1 + k] = costab1q->data[(n - k) - 1];
    }

    i73 = costab1q->size[1];
    for (k = i73; k <= nd2; k++) {
      sintabinv->data[k] = costab1q->data[k - n];
    }

    for (k = 0; k < n; k++) {
      costab->data[1 + k] = costab1q->data[1 + k];
      sintab->data[1 + k] = -costab1q->data[(n - k) - 1];
    }

    i73 = costab1q->size[1];
    for (k = i73; k <= nd2; k++) {
      costab->data[k] = -costab1q->data[nd2 - k];
      sintab->data[k] = -costab1q->data[k - n];
    }
  } else {
    n = costab1q->size[1] - 1;
    nd2 = (costab1q->size[1] - 1) << 1;
    i73 = costab->size[0] * costab->size[1];
    costab->size[0] = 1;
    costab->size[1] = nd2 + 1;
    emxEnsureCapacity_real_T(costab, i73);
    i73 = sintab->size[0] * sintab->size[1];
    sintab->size[0] = 1;
    sintab->size[1] = nd2 + 1;
    emxEnsureCapacity_real_T(sintab, i73);
    costab->data[0] = 1.0;
    sintab->data[0] = 0.0;
    for (k = 0; k < n; k++) {
      costab->data[1 + k] = costab1q->data[1 + k];
      sintab->data[1 + k] = costab1q->data[(n - k) - 1];
    }

    i73 = costab1q->size[1];
    for (k = i73; k <= nd2; k++) {
      costab->data[k] = -costab1q->data[nd2 - k];
      sintab->data[k] = costab1q->data[k - n];
    }

    sintabinv->size[0] = 1;
    sintabinv->size[1] = 0;
  }

  emxFree_real_T(&costab1q);
}

void c_r2br_r2dit_trig(const emxArray_real_T *x, int n1_unsigned, const
  emxArray_real_T *costab, const emxArray_real_T *sintab, emxArray_creal_T *y)
{
  short sx_idx_1;
  int n1;
  int nrows;
  int ub_loop;
  int k;
  int loop_ub;
  emxArray_creal_T *rwork;
  int b_loop_ub;
  int i37;
  int xoff;
  int l;
  sx_idx_1 = static_cast<short>(x->size[1]);
  n1 = n1_unsigned;
  nrows = x->size[0];
  ub_loop = y->size[0] * y->size[1];
  y->size[0] = n1_unsigned;
  y->size[1] = static_cast<short>(x->size[1]);
  emxEnsureCapacity_creal_T(y, ub_loop);
  if (n1_unsigned > x->size[0]) {
    ub_loop = y->size[0] * y->size[1];
    emxEnsureCapacity_creal_T(y, ub_loop);
    loop_ub = y->size[1];
    for (ub_loop = 0; ub_loop < loop_ub; ub_loop++) {
      b_loop_ub = y->size[0];
      for (i37 = 0; i37 < b_loop_ub; i37++) {
        y->data[i37 + y->size[0] * ub_loop].re = 0.0;
        y->data[i37 + y->size[0] * ub_loop].im = 0.0;
      }
    }
  }

  ub_loop = sx_idx_1 - 1;

#pragma omp parallel \
 num_threads(omp_get_max_threads()) \
 private(rwork,xoff,l)

  {
    emxInit_creal_T(&rwork, 1);

#pragma omp for nowait

    for (k = 0; k <= ub_loop; k++) {
      xoff = k * nrows;
      b_r2br_r2dit_trig_impl(x, xoff, n1_unsigned, costab, sintab, rwork);
      for (l = 0; l < n1; l++) {
        xoff = 1 + l;
        y->data[(xoff + y->size[0] * k) - 1] = rwork->data[xoff - 1];
      }
    }

    emxFree_creal_T(&rwork);
  }
}

void d_dobluesteinfft(const emxArray_real_T *x, int N2, int n1, const double
                      costab_data[], const int costab_size[2], const double
                      sintab_data[], const int sintab_size[2], const double
                      sintabinv_data[], const int sintabinv_size[2],
                      emxArray_creal_T *y)
{
  short sx_idx_1;
  emxArray_cuint8_T *b_y;
  static creal_T wwc_data[2497];
  int wwc_size[1];
  int nrows;
  int i59;
  int loop_ub;
  int b_loop_ub;
  int y_im;
  int k;
  int xoff;
  creal_T rwork_data[1249];
  int rwork_size[1];
  int l;
  sx_idx_1 = static_cast<short>(x->size[1]);
  emxInit_cuint8_T(&b_y, 2);
  b_bluesteinSetup(n1, wwc_data, wwc_size);
  nrows = x->size[0];
  i59 = b_y->size[0] * b_y->size[1];
  b_y->size[0] = n1;
  b_y->size[1] = static_cast<short>(x->size[1]);
  emxEnsureCapacity_cuint8_T(b_y, i59);
  if (n1 > x->size[0]) {
    i59 = b_y->size[0] * b_y->size[1];
    emxEnsureCapacity_cuint8_T(b_y, i59);
    loop_ub = b_y->size[1];
    for (i59 = 0; i59 < loop_ub; i59++) {
      b_loop_ub = b_y->size[0];
      for (y_im = 0; y_im < b_loop_ub; y_im++) {
        b_y->data[y_im + b_y->size[0] * i59].re = 0U;
        b_y->data[y_im + b_y->size[0] * i59].im = 0U;
      }
    }
  }

  i59 = y->size[0] * y->size[1];
  y->size[0] = b_y->size[0];
  y->size[1] = b_y->size[1];
  emxEnsureCapacity_creal_T(y, i59);
  loop_ub = b_y->size[0] * b_y->size[1];
  for (i59 = 0; i59 < loop_ub; i59++) {
    b_loop_ub = b_y->data[i59].re;
    y_im = b_y->data[i59].im;
    y->data[i59].re = b_loop_ub;
    y->data[i59].im = y_im;
  }

  emxFree_cuint8_T(&b_y);
  b_loop_ub = sx_idx_1 - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(xoff,rwork_data,rwork_size,l)

  for (k = 0; k <= b_loop_ub; k++) {
    xoff = k * nrows;
    b_bluestein(x, xoff, N2, n1, costab_data, costab_size, sintab_data,
                sintab_size, costab_data, costab_size, sintabinv_data,
                sintabinv_size, wwc_data, wwc_size, rwork_data, rwork_size);
    for (l = 0; l < n1; l++) {
      xoff = 1 + l;
      y->data[(xoff + y->size[0] * k) - 1] = rwork_data[xoff - 1];
    }
  }
}

void d_r2br_r2dit_trig(const double x_data[], const int x_size[1], int
  n1_unsigned, const double costab_data[], const double sintab_data[], creal_T
  y_data[], int y_size[1])
{
  int j;
  emxArray_cuint8_T *y;
  int nRowsM2;
  int nRowsD2;
  int nRowsD4;
  int iy;
  int iDelta;
  int ix;
  int ju;
  int i;
  boolean_T tst;
  double temp_re;
  double temp_im;
  double twid_re;
  double twid_im;
  int temp_re_tmp;
  j = x_size[0];
  if (j >= n1_unsigned) {
    j = n1_unsigned;
  }

  emxInit_cuint8_T(&y, 1);
  nRowsM2 = n1_unsigned - 2;
  nRowsD2 = n1_unsigned / 2;
  nRowsD4 = nRowsD2 / 2;
  iy = y->size[0];
  y->size[0] = n1_unsigned;
  emxEnsureCapacity_cuint8_T(y, iy);
  if (n1_unsigned > x_size[0]) {
    iDelta = y->size[0];
    iy = y->size[0];
    y->size[0] = iDelta;
    emxEnsureCapacity_cuint8_T(y, iy);
    for (iy = 0; iy < iDelta; iy++) {
      y->data[iy].re = 0U;
      y->data[iy].im = 0U;
    }
  }

  y_size[0] = y->size[0];
  iDelta = y->size[0];
  for (iy = 0; iy < iDelta; iy++) {
    ix = y->data[iy].re;
    ju = y->data[iy].im;
    y_data[iy].re = ix;
    y_data[iy].im = ju;
  }

  emxFree_cuint8_T(&y);
  ix = 0;
  ju = 0;
  iy = 0;
  for (i = 0; i <= j - 2; i++) {
    y_data[iy].re = x_data[ix];
    y_data[iy].im = 0.0;
    iDelta = n1_unsigned;
    tst = true;
    while (tst) {
      iDelta >>= 1;
      ju ^= iDelta;
      tst = ((ju & iDelta) == 0);
    }

    iy = ju;
    ix++;
  }

  y_data[iy].re = x_data[ix];
  y_data[iy].im = 0.0;
  if (n1_unsigned > 1) {
    for (i = 0; i <= nRowsM2; i += 2) {
      temp_re = y_data[i + 1].re;
      temp_im = y_data[i + 1].im;
      twid_re = y_data[i].re;
      twid_im = y_data[i].im;
      y_data[i + 1].re = y_data[i].re - y_data[i + 1].re;
      y_data[i + 1].im = y_data[i].im - y_data[i + 1].im;
      twid_re += temp_re;
      twid_im += temp_im;
      y_data[i].re = twid_re;
      y_data[i].im = twid_im;
    }
  }

  iDelta = 2;
  iy = 4;
  ix = 1 + ((nRowsD4 - 1) << 2);
  while (nRowsD4 > 0) {
    for (i = 0; i < ix; i += iy) {
      temp_re_tmp = i + iDelta;
      temp_re = y_data[temp_re_tmp].re;
      temp_im = y_data[i + iDelta].im;
      y_data[temp_re_tmp].re = y_data[i].re - y_data[temp_re_tmp].re;
      y_data[temp_re_tmp].im = y_data[i].im - temp_im;
      y_data[i].re += temp_re;
      y_data[i].im += temp_im;
    }

    ju = 1;
    for (j = nRowsD4; j < nRowsD2; j += nRowsD4) {
      twid_re = costab_data[j];
      twid_im = sintab_data[j];
      i = ju;
      nRowsM2 = ju + ix;
      while (i < nRowsM2) {
        temp_re_tmp = i + iDelta;
        temp_re = twid_re * y_data[temp_re_tmp].re - twid_im * y_data[i + iDelta]
          .im;
        temp_im = twid_re * y_data[i + iDelta].im + twid_im * y_data[i + iDelta]
          .re;
        y_data[temp_re_tmp].re = y_data[i].re - temp_re;
        y_data[temp_re_tmp].im = y_data[i].im - temp_im;
        y_data[i].re += temp_re;
        y_data[i].im += temp_im;
        i += iy;
      }

      ju++;
    }

    nRowsD4 /= 2;
    iDelta = iy;
    iy += iy;
    ix -= iDelta;
  }

  if (y_size[0] > 1) {
    twid_re = 1.0 / static_cast<double>(y_size[0]);
    iDelta = y_size[0];
    for (iy = 0; iy < iDelta; iy++) {
      y_data[iy].re *= twid_re;
      y_data[iy].im *= twid_re;
    }
  }
}

void dobluesteinfft(const emxArray_real_T *x, int N2, int n1, const
                    emxArray_real_T *costab, const emxArray_real_T *sintab,
                    const emxArray_real_T *sintabinv, emxArray_creal_T *y)
{
  emxArray_creal_T *wwc;
  int minNrowsNx;
  int a_re_tmp;
  int xidx;
  int k;
  double a_re;
  double a_im;
  emxArray_creal_T *fv;
  emxArray_creal_T *b_fv;
  double fv_re;
  double fv_im;
  double wwc_re;
  double wwc_im;
  double b_wwc_re;
  double b_wwc_im;
  emxInit_creal_T(&wwc, 1);
  bluesteinSetup(n1, wwc);
  minNrowsNx = x->size[0];
  if (n1 < minNrowsNx) {
    minNrowsNx = n1;
  }

  a_re_tmp = y->size[0];
  y->size[0] = n1;
  emxEnsureCapacity_creal_T(y, a_re_tmp);
  if (n1 > x->size[0]) {
    xidx = y->size[0];
    a_re_tmp = y->size[0];
    y->size[0] = xidx;
    emxEnsureCapacity_creal_T(y, a_re_tmp);
    for (a_re_tmp = 0; a_re_tmp < xidx; a_re_tmp++) {
      y->data[a_re_tmp].re = 0.0;
      y->data[a_re_tmp].im = 0.0;
    }
  }

  xidx = 0;
  for (k = 0; k < minNrowsNx; k++) {
    a_re_tmp = (n1 + k) - 1;
    a_re = wwc->data[a_re_tmp].re;
    a_im = wwc->data[a_re_tmp].im;
    y->data[k].re = a_re * x->data[xidx];
    y->data[k].im = a_im * -x->data[xidx];
    xidx++;
  }

  a_re_tmp = minNrowsNx + 1;
  for (k = a_re_tmp; k <= n1; k++) {
    y->data[k - 1].re = 0.0;
    y->data[k - 1].im = 0.0;
  }

  emxInit_creal_T(&fv, 1);
  emxInit_creal_T(&b_fv, 1);
  r2br_r2dit_trig_impl(y, N2, costab, sintab, fv);
  r2br_r2dit_trig_impl(wwc, N2, costab, sintab, b_fv);
  a_re_tmp = b_fv->size[0];
  b_fv->size[0] = fv->size[0];
  emxEnsureCapacity_creal_T(b_fv, a_re_tmp);
  xidx = fv->size[0];
  for (a_re_tmp = 0; a_re_tmp < xidx; a_re_tmp++) {
    a_re = fv->data[a_re_tmp].re;
    a_im = fv->data[a_re_tmp].im;
    fv_re = b_fv->data[a_re_tmp].re;
    fv_im = b_fv->data[a_re_tmp].im;
    b_fv->data[a_re_tmp].re = a_re * fv_re - a_im * fv_im;
    b_fv->data[a_re_tmp].im = a_re * fv_im + a_im * fv_re;
  }

  b_r2br_r2dit_trig(b_fv, N2, costab, sintabinv, fv);
  xidx = 0;
  a_re_tmp = wwc->size[0];
  emxFree_creal_T(&b_fv);
  for (k = n1; k <= a_re_tmp; k++) {
    wwc_re = wwc->data[k - 1].re;
    a_re = fv->data[k - 1].re;
    wwc_im = wwc->data[k - 1].im;
    a_im = fv->data[k - 1].im;
    b_wwc_re = wwc->data[k - 1].re;
    fv_im = fv->data[k - 1].im;
    b_wwc_im = wwc->data[k - 1].im;
    fv_re = fv->data[k - 1].re;
    y->data[xidx].re = wwc_re * a_re + wwc_im * a_im;
    y->data[xidx].im = b_wwc_re * fv_im - b_wwc_im * fv_re;
    xidx++;
  }

  emxFree_creal_T(&fv);
  emxFree_creal_T(&wwc);
}

void e_dobluesteinfft(const emxArray_creal_T *x, int N2, int n1, const double
                      costab_data[], const int costab_size[2], const double
                      sintab_data[], const int sintab_size[2], const double
                      sintabinv_data[], const int sintabinv_size[2],
                      emxArray_creal_T *y)
{
  short sx_idx_1;
  short sx_idx_2;
  emxArray_creal_T *r24;
  int wwc_size[1];
  int loop_ub;
  int i63;
  static creal_T wwc_data[2497];
  int nrows;
  int k;
  int xoff;
  int b_loop_ub;
  int i64;
  int c_loop_ub;
  int i65;
  creal_T rwork_data[1249];
  int rwork_size[1];
  int l;
  int y_idx_0;
  sx_idx_1 = static_cast<short>(x->size[1]);
  sx_idx_2 = static_cast<short>(x->size[2]);
  emxInit_creal_T(&r24, 1);
  c_bluesteinSetup(n1, r24);
  wwc_size[0] = r24->size[0];
  loop_ub = r24->size[0];
  for (i63 = 0; i63 < loop_ub; i63++) {
    wwc_data[i63] = r24->data[i63];
  }

  emxFree_creal_T(&r24);
  nrows = x->size[0];
  i63 = y->size[0] * y->size[1] * y->size[2];
  y->size[0] = n1;
  y->size[1] = static_cast<short>(x->size[1]);
  y->size[2] = static_cast<short>(x->size[2]);
  emxEnsureCapacity_creal_T(y, i63);
  if (n1 > x->size[0]) {
    i63 = y->size[0] * y->size[1] * y->size[2];
    emxEnsureCapacity_creal_T(y, i63);
    loop_ub = y->size[2];
    for (i63 = 0; i63 < loop_ub; i63++) {
      b_loop_ub = y->size[1];
      for (i64 = 0; i64 < b_loop_ub; i64++) {
        c_loop_ub = y->size[0];
        for (i65 = 0; i65 < c_loop_ub; i65++) {
          y->data[(i65 + y->size[0] * i64) + y->size[0] * y->size[1] * i63].re =
            0.0;
          y->data[(i65 + y->size[0] * i64) + y->size[0] * y->size[1] * i63].im =
            0.0;
        }
      }
    }
  }

  loop_ub = sx_idx_1 * sx_idx_2 - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(xoff,rwork_data,rwork_size,l,y_idx_0)

  for (k = 0; k <= loop_ub; k++) {
    xoff = k * nrows;
    c_bluestein(x, xoff, N2, n1, costab_data, costab_size, sintab_data,
                sintab_size, costab_data, costab_size, sintabinv_data,
                sintabinv_size, wwc_data, wwc_size, rwork_data, rwork_size);
    for (l = 0; l < n1; l++) {
      xoff = 1 + l;
      y_idx_0 = y->size[0];
      y->data[(xoff + y_idx_0 * k) - 1] = rwork_data[xoff - 1];
    }
  }
}

void e_r2br_r2dit_trig(const emxArray_real_T *x, int n1_unsigned, const double
  costab_data[], const double sintab_data[], emxArray_creal_T *y)
{
  short sx_idx_1;
  emxArray_cuint8_T *b_y;
  int n1;
  int nrows;
  int i58;
  int loop_ub;
  int b_loop_ub;
  int y_im;
  int k;
  double b;
  int xoff;
  creal_T rwork_data[1249];
  int rwork_size[1];
  int l;
  sx_idx_1 = static_cast<short>(x->size[1]);
  emxInit_cuint8_T(&b_y, 2);
  n1 = n1_unsigned;
  nrows = x->size[0];
  i58 = b_y->size[0] * b_y->size[1];
  b_y->size[0] = n1_unsigned;
  b_y->size[1] = static_cast<short>(x->size[1]);
  emxEnsureCapacity_cuint8_T(b_y, i58);
  if (n1_unsigned > x->size[0]) {
    i58 = b_y->size[0] * b_y->size[1];
    emxEnsureCapacity_cuint8_T(b_y, i58);
    loop_ub = b_y->size[1];
    for (i58 = 0; i58 < loop_ub; i58++) {
      b_loop_ub = b_y->size[0];
      for (y_im = 0; y_im < b_loop_ub; y_im++) {
        b_y->data[y_im + b_y->size[0] * i58].re = 0U;
        b_y->data[y_im + b_y->size[0] * i58].im = 0U;
      }
    }
  }

  i58 = y->size[0] * y->size[1];
  y->size[0] = b_y->size[0];
  y->size[1] = b_y->size[1];
  emxEnsureCapacity_creal_T(y, i58);
  loop_ub = b_y->size[0] * b_y->size[1];
  for (i58 = 0; i58 < loop_ub; i58++) {
    b_loop_ub = b_y->data[i58].re;
    y_im = b_y->data[i58].im;
    y->data[i58].re = b_loop_ub;
    y->data[i58].im = y_im;
  }

  emxFree_cuint8_T(&b_y);
  b_loop_ub = sx_idx_1 - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(xoff,rwork_data,rwork_size,l)

  for (k = 0; k <= b_loop_ub; k++) {
    xoff = k * nrows;
    c_r2br_r2dit_trig_impl(x, xoff, n1_unsigned, costab_data, sintab_data,
      rwork_data, rwork_size);
    for (l = 0; l < n1; l++) {
      xoff = 1 + l;
      y->data[(xoff + y->size[0] * k) - 1] = rwork_data[xoff - 1];
    }
  }

  if (y->size[0] > 1) {
    b = 1.0 / static_cast<double>(y->size[0]);
    i58 = y->size[0] * y->size[1];
    y_im = y->size[0] * y->size[1];
    emxEnsureCapacity_creal_T(y, y_im);
    loop_ub = i58 - 1;
    for (i58 = 0; i58 <= loop_ub; i58++) {
      y->data[i58].re *= b;
      y->data[i58].im *= b;
    }
  }
}

void f_dobluesteinfft(const emxArray_creal_T *x, int N2, int n1, const
                      emxArray_real_T *costab, const emxArray_real_T *sintab,
                      const emxArray_real_T *sintabinv, emxArray_creal_T *y)
{
  emxArray_creal_T *wwc;
  int minNrowsNx;
  emxArray_creal_T *fv;
  int denom_re_tmp;
  int xidx;
  int k;
  double denom_re;
  double denom_im;
  emxArray_creal_T *b_fv;
  double x_re;
  double x_im;
  double b_x_im;
  double b_x_re;
  double wwc_re;
  double wwc_im;
  emxInit_creal_T(&wwc, 1);
  c_bluesteinSetup(n1, wwc);
  minNrowsNx = x->size[0];
  if (n1 < minNrowsNx) {
    minNrowsNx = n1;
  }

  emxInit_creal_T(&fv, 1);
  denom_re_tmp = fv->size[0];
  fv->size[0] = n1;
  emxEnsureCapacity_creal_T(fv, denom_re_tmp);
  if (n1 > x->size[0]) {
    xidx = fv->size[0];
    denom_re_tmp = fv->size[0];
    fv->size[0] = xidx;
    emxEnsureCapacity_creal_T(fv, denom_re_tmp);
    for (denom_re_tmp = 0; denom_re_tmp < xidx; denom_re_tmp++) {
      fv->data[denom_re_tmp].re = 0.0;
      fv->data[denom_re_tmp].im = 0.0;
    }
  }

  denom_re_tmp = y->size[0];
  y->size[0] = fv->size[0];
  emxEnsureCapacity_creal_T(y, denom_re_tmp);
  xidx = fv->size[0];
  for (denom_re_tmp = 0; denom_re_tmp < xidx; denom_re_tmp++) {
    y->data[denom_re_tmp] = fv->data[denom_re_tmp];
  }

  xidx = 0;
  for (k = 0; k < minNrowsNx; k++) {
    denom_re_tmp = (n1 + k) - 1;
    denom_re = wwc->data[denom_re_tmp].re;
    denom_im = wwc->data[denom_re_tmp].im;
    x_re = x->data[xidx].re;
    x_im = x->data[xidx].im;
    b_x_im = x->data[xidx].im;
    b_x_re = x->data[xidx].re;
    y->data[k].re = denom_re * x_re + denom_im * x_im;
    y->data[k].im = denom_re * b_x_im - denom_im * b_x_re;
    xidx++;
  }

  denom_re_tmp = minNrowsNx + 1;
  for (k = denom_re_tmp; k <= n1; k++) {
    y->data[k - 1].re = 0.0;
    y->data[k - 1].im = 0.0;
  }

  emxInit_creal_T(&b_fv, 1);
  r2br_r2dit_trig_impl(y, N2, costab, sintab, fv);
  r2br_r2dit_trig_impl(wwc, N2, costab, sintab, b_fv);
  denom_re_tmp = b_fv->size[0];
  b_fv->size[0] = fv->size[0];
  emxEnsureCapacity_creal_T(b_fv, denom_re_tmp);
  xidx = fv->size[0];
  for (denom_re_tmp = 0; denom_re_tmp < xidx; denom_re_tmp++) {
    denom_re = fv->data[denom_re_tmp].re;
    denom_im = fv->data[denom_re_tmp].im;
    x_re = b_fv->data[denom_re_tmp].re;
    x_im = b_fv->data[denom_re_tmp].im;
    b_fv->data[denom_re_tmp].re = denom_re * x_re - denom_im * x_im;
    b_fv->data[denom_re_tmp].im = denom_re * x_im + denom_im * x_re;
  }

  b_r2br_r2dit_trig(b_fv, N2, costab, sintabinv, fv);
  xidx = 0;
  denom_re_tmp = wwc->size[0];
  emxFree_creal_T(&b_fv);
  for (k = n1; k <= denom_re_tmp; k++) {
    b_x_im = wwc->data[k - 1].re;
    denom_re = fv->data[k - 1].re;
    b_x_re = wwc->data[k - 1].im;
    denom_im = fv->data[k - 1].im;
    wwc_re = wwc->data[k - 1].re;
    x_im = fv->data[k - 1].im;
    wwc_im = wwc->data[k - 1].im;
    x_re = fv->data[k - 1].re;
    y->data[xidx].re = b_x_im * denom_re + b_x_re * denom_im;
    y->data[xidx].im = wwc_re * x_im - wwc_im * x_re;
    b_x_im = wwc->data[k - 1].re;
    denom_re = fv->data[k - 1].re;
    b_x_re = wwc->data[k - 1].im;
    denom_im = fv->data[k - 1].im;
    wwc_re = wwc->data[k - 1].re;
    x_im = fv->data[k - 1].im;
    wwc_im = wwc->data[k - 1].im;
    x_re = fv->data[k - 1].re;
    y->data[xidx].re = b_x_im * denom_re + b_x_re * denom_im;
    y->data[xidx].im = wwc_re * x_im - wwc_im * x_re;
    denom_re = y->data[xidx].re;
    denom_im = y->data[xidx].im;
    if (denom_im == 0.0) {
      y->data[xidx].re = denom_re / static_cast<double>(n1);
      y->data[xidx].im = 0.0;
    } else if (denom_re == 0.0) {
      y->data[xidx].re = 0.0;
      y->data[xidx].im = denom_im / static_cast<double>(n1);
    } else {
      y->data[xidx].re = denom_re / static_cast<double>(n1);
      y->data[xidx].im = denom_im / static_cast<double>(n1);
    }

    xidx++;
  }

  emxFree_creal_T(&fv);
  emxFree_creal_T(&wwc);
}

void f_r2br_r2dit_trig(const emxArray_creal_T *x, int n1_unsigned, const double
  costab_data[], const double sintab_data[], emxArray_creal_T *y)
{
  short sx_idx_1;
  short sx_idx_2;
  int n1;
  int nrows;
  int ub_loop;
  int k;
  int loop_ub;
  double b;
  int b_loop_ub;
  int xoff;
  int i61;
  int c_loop_ub;
  int i62;
  creal_T rwork_data[1249];
  int rwork_size[1];
  int l;
  int y_idx_0;
  sx_idx_1 = static_cast<short>(x->size[1]);
  sx_idx_2 = static_cast<short>(x->size[2]);
  n1 = n1_unsigned;
  nrows = x->size[0];
  ub_loop = y->size[0] * y->size[1] * y->size[2];
  y->size[0] = n1_unsigned;
  y->size[1] = static_cast<short>(x->size[1]);
  y->size[2] = static_cast<short>(x->size[2]);
  emxEnsureCapacity_creal_T(y, ub_loop);
  if (n1_unsigned > x->size[0]) {
    ub_loop = y->size[0] * y->size[1] * y->size[2];
    emxEnsureCapacity_creal_T(y, ub_loop);
    loop_ub = y->size[2];
    for (ub_loop = 0; ub_loop < loop_ub; ub_loop++) {
      b_loop_ub = y->size[1];
      for (i61 = 0; i61 < b_loop_ub; i61++) {
        c_loop_ub = y->size[0];
        for (i62 = 0; i62 < c_loop_ub; i62++) {
          y->data[(i62 + y->size[0] * i61) + y->size[0] * y->size[1] * ub_loop].
            re = 0.0;
          y->data[(i62 + y->size[0] * i61) + y->size[0] * y->size[1] * ub_loop].
            im = 0.0;
        }
      }
    }
  }

  ub_loop = sx_idx_1 * sx_idx_2 - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(xoff,rwork_data,rwork_size,l,y_idx_0)

  for (k = 0; k <= ub_loop; k++) {
    xoff = k * nrows;
    d_r2br_r2dit_trig_impl(x, xoff, n1_unsigned, costab_data, sintab_data,
      rwork_data, rwork_size);
    for (l = 0; l < n1; l++) {
      xoff = 1 + l;
      y_idx_0 = y->size[0];
      y->data[(xoff + y_idx_0 * k) - 1] = rwork_data[xoff - 1];
    }
  }

  if (y->size[0] > 1) {
    b = 1.0 / static_cast<double>(y->size[0]);
    ub_loop = y->size[0] * y->size[1] * y->size[2];
    i61 = y->size[0] * y->size[1] * y->size[2];
    emxEnsureCapacity_creal_T(y, i61);
    loop_ub = ub_loop - 1;
    for (ub_loop = 0; ub_loop <= loop_ub; ub_loop++) {
      y->data[ub_loop].re *= b;
      y->data[ub_loop].im *= b;
    }
  }
}

void generate_twiddle_tables(int nRows, boolean_T useRadix2, emxArray_real_T
  *costab, emxArray_real_T *sintab, emxArray_real_T *sintabinv)
{
  emxArray_real_T *costab1q;
  double e;
  int n;
  int i20;
  int nd2;
  int k;
  emxInit_real_T(&costab1q, 2);
  e = 6.2831853071795862 / static_cast<double>(nRows);
  n = nRows / 2 / 2;
  i20 = costab1q->size[0] * costab1q->size[1];
  costab1q->size[0] = 1;
  costab1q->size[1] = n + 1;
  emxEnsureCapacity_real_T(costab1q, i20);
  costab1q->data[0] = 1.0;
  nd2 = n / 2 - 1;
  for (k = 0; k <= nd2; k++) {
    costab1q->data[1 + k] = std::cos(e * (1.0 + static_cast<double>(k)));
  }

  i20 = nd2 + 2;
  nd2 = n - 1;
  for (k = i20; k <= nd2; k++) {
    costab1q->data[k] = std::sin(e * static_cast<double>((n - k)));
  }

  costab1q->data[n] = 0.0;
  if (!useRadix2) {
    n = costab1q->size[1] - 1;
    nd2 = (costab1q->size[1] - 1) << 1;
    i20 = costab->size[0] * costab->size[1];
    costab->size[0] = 1;
    costab->size[1] = nd2 + 1;
    emxEnsureCapacity_real_T(costab, i20);
    i20 = sintab->size[0] * sintab->size[1];
    sintab->size[0] = 1;
    sintab->size[1] = nd2 + 1;
    emxEnsureCapacity_real_T(sintab, i20);
    costab->data[0] = 1.0;
    sintab->data[0] = 0.0;
    i20 = sintabinv->size[0] * sintabinv->size[1];
    sintabinv->size[0] = 1;
    sintabinv->size[1] = nd2 + 1;
    emxEnsureCapacity_real_T(sintabinv, i20);
    for (k = 0; k < n; k++) {
      sintabinv->data[1 + k] = costab1q->data[(n - k) - 1];
    }

    i20 = costab1q->size[1];
    for (k = i20; k <= nd2; k++) {
      sintabinv->data[k] = costab1q->data[k - n];
    }

    for (k = 0; k < n; k++) {
      costab->data[1 + k] = costab1q->data[1 + k];
      sintab->data[1 + k] = -costab1q->data[(n - k) - 1];
    }

    i20 = costab1q->size[1];
    for (k = i20; k <= nd2; k++) {
      costab->data[k] = -costab1q->data[nd2 - k];
      sintab->data[k] = -costab1q->data[k - n];
    }
  } else {
    n = costab1q->size[1] - 1;
    nd2 = (costab1q->size[1] - 1) << 1;
    i20 = costab->size[0] * costab->size[1];
    costab->size[0] = 1;
    costab->size[1] = nd2 + 1;
    emxEnsureCapacity_real_T(costab, i20);
    i20 = sintab->size[0] * sintab->size[1];
    sintab->size[0] = 1;
    sintab->size[1] = nd2 + 1;
    emxEnsureCapacity_real_T(sintab, i20);
    costab->data[0] = 1.0;
    sintab->data[0] = 0.0;
    for (k = 0; k < n; k++) {
      costab->data[1 + k] = costab1q->data[1 + k];
      sintab->data[1 + k] = -costab1q->data[(n - k) - 1];
    }

    i20 = costab1q->size[1];
    for (k = i20; k <= nd2; k++) {
      costab->data[k] = -costab1q->data[nd2 - k];
      sintab->data[k] = -costab1q->data[k - n];
    }

    sintabinv->size[0] = 1;
    sintabinv->size[1] = 0;
  }

  emxFree_real_T(&costab1q);
}

void get_algo_sizes(int n1, boolean_T useRadix2, int *N2blue, int *nRows)
{
  int n;
  int pmax;
  int pmin;
  boolean_T exitg1;
  int p;
  int pow2p;
  *N2blue = 1;
  if (useRadix2) {
    *nRows = n1;
  } else {
    n = (n1 + n1) - 1;
    pmax = 31;
    if (n <= 1) {
      pmax = 0;
    } else {
      pmin = 0;
      exitg1 = false;
      while ((!exitg1) && (pmax - pmin > 1)) {
        p = (pmin + pmax) >> 1;
        pow2p = 1 << p;
        if (pow2p == n) {
          pmax = p;
          exitg1 = true;
        } else if (pow2p > n) {
          pmax = p;
        } else {
          pmin = p;
        }
      }
    }

    *N2blue = 1 << pmax;
    *nRows = *N2blue;
  }
}

void r2br_r2dit_trig(const emxArray_real_T *x, int n1_unsigned, const
                     emxArray_real_T *costab, const emxArray_real_T *sintab,
                     emxArray_creal_T *y)
{
  int j;
  int nRowsM2;
  int nRowsD2;
  int nRowsD4;
  int iy;
  int iDelta;
  int ix;
  int ju;
  int i;
  boolean_T tst;
  double temp_re;
  double temp_im;
  int temp_re_tmp;
  double twid_re;
  double twid_im;
  j = x->size[0];
  if (j >= n1_unsigned) {
    j = n1_unsigned;
  }

  nRowsM2 = n1_unsigned - 2;
  nRowsD2 = n1_unsigned / 2;
  nRowsD4 = nRowsD2 / 2;
  iy = y->size[0];
  y->size[0] = n1_unsigned;
  emxEnsureCapacity_creal_T(y, iy);
  if (n1_unsigned > x->size[0]) {
    iDelta = y->size[0];
    iy = y->size[0];
    y->size[0] = iDelta;
    emxEnsureCapacity_creal_T(y, iy);
    for (iy = 0; iy < iDelta; iy++) {
      y->data[iy].re = 0.0;
      y->data[iy].im = 0.0;
    }
  }

  ix = 0;
  ju = 0;
  iy = 0;
  for (i = 0; i <= j - 2; i++) {
    y->data[iy].re = x->data[ix];
    y->data[iy].im = 0.0;
    iDelta = n1_unsigned;
    tst = true;
    while (tst) {
      iDelta >>= 1;
      ju ^= iDelta;
      tst = ((ju & iDelta) == 0);
    }

    iy = ju;
    ix++;
  }

  y->data[iy].re = x->data[ix];
  y->data[iy].im = 0.0;
  if (n1_unsigned > 1) {
    for (i = 0; i <= nRowsM2; i += 2) {
      temp_re = y->data[i + 1].re;
      temp_im = y->data[i + 1].im;
      y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
      y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }
  }

  iDelta = 2;
  iy = 4;
  ix = 1 + ((nRowsD4 - 1) << 2);
  while (nRowsD4 > 0) {
    for (i = 0; i < ix; i += iy) {
      temp_re_tmp = i + iDelta;
      temp_re = y->data[temp_re_tmp].re;
      temp_im = y->data[temp_re_tmp].im;
      y->data[temp_re_tmp].re = y->data[i].re - temp_re;
      y->data[temp_re_tmp].im = y->data[i].im - temp_im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }

    ju = 1;
    for (j = nRowsD4; j < nRowsD2; j += nRowsD4) {
      twid_re = costab->data[j];
      twid_im = sintab->data[j];
      i = ju;
      nRowsM2 = ju + ix;
      while (i < nRowsM2) {
        temp_re_tmp = i + iDelta;
        temp_re = twid_re * y->data[temp_re_tmp].re - twid_im * y->
          data[temp_re_tmp].im;
        temp_im = twid_re * y->data[temp_re_tmp].im + twid_im * y->
          data[temp_re_tmp].re;
        y->data[temp_re_tmp].re = y->data[i].re - temp_re;
        y->data[temp_re_tmp].im = y->data[i].im - temp_im;
        y->data[i].re += temp_re;
        y->data[i].im += temp_im;
        i += iy;
      }

      ju++;
    }

    nRowsD4 /= 2;
    iDelta = iy;
    iy += iy;
    ix -= iDelta;
  }
}

/* End of code generation (fft1.cpp) */

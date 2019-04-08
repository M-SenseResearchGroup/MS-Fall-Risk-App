/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xcorr.cpp
 *
 * Code generation for function 'xcorr'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include <cmath>
#include <string.h>
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "xcorr.h"
#include "calc_fall_risk_emxutil.h"
#include "bsxfun.h"
#include "abs.h"
#include "ifft.h"
#include "fft.h"
#include "mpower.h"
#include "nextpow2.h"
#include "fft1.h"
#include "power.h"
#include "sign1.h"
#include "calc_fall_risk_rtwutil.h"

/* Function Declarations */
static double OpCountForAutocorrTD(double maxlag, double m);
static double OpCountForXcorrTD(double maxlag, double n1);
static void autocorr(const double x_data[], const int x_size[1], double maxlag,
                     double c_data[], int c_size[1]);
static void autocorrTD(const double x_data[], const int x_size[1], double maxlag,
  double c_data[], int c_size[1]);
static void b_autocorr(const emxArray_real_T *x, double maxlag, emxArray_real_T *
  c);
static void b_autocorrTD(const emxArray_real_T *x, double maxlag, double c_data[],
  int c_size[1]);
static void b_xcorr(const double x_data[], const int x_size[1], double c_data[],
                    int c_size[1], double lags_data[], int lags_size[2]);
static void crosscorr(const double x_data[], const int x_size[2], const
                      emxArray_real_T *y, double maxlag, emxArray_real_T *c);
static void crosscorrTD(const double x_data[], const emxArray_real_T *y, double
  maxlag, emxArray_real_T *c);
static void padOutput(const emxArray_real_T *c1, double maxlag, double
                      defaultMaxlag, emxArray_real_T *c);
static void scaleXcorr(double c_data[], int c_size[1], const int x_size[1]);

/* Function Definitions */
static double OpCountForAutocorrTD(double maxlag, double m)
{
  double c0;
  c0 = 2.0 * m - 1.0;
  return c0 + maxlag * ((c0 - maxlag) - 1.0);
}

static double OpCountForXcorrTD(double maxlag, double n1)
{
  double c;
  double m;
  double n;
  double c0;
  double Sn;
  if ((125.0 > n1) || rtIsNaN(n1)) {
    m = 125.0;
  } else {
    m = n1;
  }

  if ((125.0 < n1) || rtIsNaN(n1)) {
    n = 125.0;
  } else {
    n = n1;
  }

  c0 = 2.0 * n - 1.0;
  if (maxlag <= n - 1.0) {
    Sn = 124.0 * ((c0 - 124.0) - 1.0);
    if (124.0 <= m - n) {
      c = (c0 + 124.0 * c0) + Sn;
    } else {
      c = ((c0 + (m - n) * c0) + (124.0 - (m - n)) * (((m - 124.0) + n) - 2.0))
        + Sn;
    }
  } else if (maxlag <= m - 1.0) {
    Sn = (n - 1.0) * (n - 1.0);
    if (maxlag <= m - n) {
      c = (c0 + maxlag * c0) + Sn;
    } else {
      c = ((c0 + (m - n) * c0) + (maxlag - (m - n)) * (((m - maxlag) + n) - 2.0))
        + Sn;
    }
  } else {
    c = 2.0 * m * n - ((m + n) - 1.0);
  }

  return c;
}

static void autocorr(const double x_data[], const int x_size[1], double maxlag,
                     double c_data[], int c_size[1])
{
  double mxl;
  double ceilLog2;
  double m2;
  emxArray_creal_T *r18;
  emxArray_real_T b_x_data;
  double c1_data[1249];
  int c1_size[1];
  double tmp_data[1249];
  int tmp_size[1];
  static creal_T b_tmp_data[1249];
  int loop_ub;
  int i44;
  emxArray_real_T *y;
  int b_loop_ub;
  mxl = static_cast<double>(x_size[0]) - 1.0;
  if (maxlag < mxl) {
    mxl = maxlag;
  }

  ceilLog2 = nextpow2(2.0 * static_cast<double>(x_size[0]) - 1.0);
  m2 = mpower(ceilLog2);
  if (OpCountForAutocorrTD(mxl, (double)x_size[0]) < m2 * (15.0 * ceilLog2 + 6.0))
  {
    autocorrTD(x_data, x_size, mxl, c_data, c_size);
  } else {
    emxInit_creal_T(&r18, 1);
    b_x_data.data = const_cast<double *>(&x_data[0]);
    b_x_data.size = const_cast<int *>(&x_size[0]);
    b_x_data.allocatedSize = -1;
    b_x_data.numDimensions = 1;
    b_x_data.canFreeData = false;
    c_fft(&b_x_data, m2, r18);
    b_abs(r18->data, r18->size, c1_data, c1_size);
    b_power(c1_data, c1_size, tmp_data, tmp_size);
    ifft(tmp_data, tmp_size, b_tmp_data, c1_size);
    loop_ub = c1_size[0];
    emxFree_creal_T(&r18);
    for (i44 = 0; i44 < loop_ub; i44++) {
      c1_data[i44] = b_tmp_data[i44].re;
    }

    if (1.0 > mxl + 1.0) {
      loop_ub = 0;
    } else {
      loop_ub = static_cast<int>((mxl + 1.0));
    }

    emxInit_real_T(&y, 2);
    if (mxl < 1.0) {
      y->size[0] = 1;
      y->size[1] = 0;
    } else {
      i44 = y->size[0] * y->size[1];
      y->size[0] = 1;
      b_loop_ub = static_cast<int>(std::floor(mxl - 1.0));
      y->size[1] = b_loop_ub + 1;
      emxEnsureCapacity_real_T(y, i44);
      for (i44 = 0; i44 <= b_loop_ub; i44++) {
        y->data[i44] = 1.0 + static_cast<double>(i44);
      }
    }

    m2 -= mxl;
    c_size[0] = y->size[1] + loop_ub;
    b_loop_ub = y->size[1];
    for (i44 = 0; i44 < b_loop_ub; i44++) {
      c_data[i44] = c1_data[static_cast<int>((m2 + y->data[i44])) - 1];
    }

    for (i44 = 0; i44 < loop_ub; i44++) {
      c_data[i44 + y->size[1]] = c1_data[i44];
    }

    emxFree_real_T(&y);
  }
}

static void autocorrTD(const double x_data[], const int x_size[1], double maxlag,
  double c_data[], int c_size[1])
{
  double mxl;
  int c_size_tmp;
  int k;
  double s;
  int i45;
  int i;
  mxl = static_cast<double>(x_size[0]) - 1.0;
  if (maxlag < mxl) {
    mxl = maxlag;
  }

  c_size_tmp = static_cast<int>((2.0 * mxl + 1.0));
  c_size[0] = c_size_tmp;
  if (0 <= c_size_tmp - 1) {
    memset(&c_data[0], 0, (unsigned int)(c_size_tmp * static_cast<int>(sizeof
             (double))));
  }

  c_size_tmp = static_cast<int>((mxl + 1.0));
  for (k = 0; k < c_size_tmp; k++) {
    s = 0.0;
    i45 = x_size[0] - k;
    for (i = 0; i < i45; i++) {
      s += x_data[i] * x_data[k + i];
    }

    c_data[static_cast<int>(((mxl - static_cast<double>(k)) + 1.0)) - 1] = s;
    c_data[static_cast<int>(((mxl + static_cast<double>(k)) + 1.0)) - 1] = s;
  }
}

static void b_autocorr(const emxArray_real_T *x, double maxlag, emxArray_real_T *
  c)
{
  double mxl;
  double ceilLog2;
  double m2;
  emxArray_real_T *Cr;
  emxArray_real_T *c1;
  emxArray_creal_T *C;
  emxArray_real_T *b_c1;
  emxArray_creal_T *b;
  emxArray_creal_T *y;
  emxArray_real_T *b_y;
  emxArray_creal_T *c_y;
  emxArray_creal_T *X_tmp;
  emxArray_real_T *c_c1;
  emxArray_real_T *d_c1;
  boolean_T guard1 = false;
  int c0;
  double c_data[625];
  int c_size[1];
  int i53;
  int loop_ub;
  int b_loop_ub;
  short csz_idx_0;
  short csz_idx_1;
  int k;
  int i54;
  boolean_T useRadix2;
  short csz_idx_2;
  static double costab_data[2499];
  int costab_size[2];
  double sintab_data[2499];
  int sintab_size[2];
  double sintabinv_data[2499];
  int sintabinv_size[2];
  int bcoef;
  int varargin_5;
  int acoef_tmp;
  int acoef;
  int b_bcoef;
  int i55;
  int b_k;
  int X_tmp_re_tmp;
  double X_tmp_im;
  double b_re;
  double b_im;
  boolean_T guard2 = false;
  mxl = static_cast<double>(x->size[0]) - 1.0;
  if (maxlag < mxl) {
    mxl = maxlag;
  }

  ceilLog2 = nextpow2(2.0 * static_cast<double>(x->size[0]) - 1.0);
  m2 = mpower(ceilLog2);
  emxInit_real_T(&Cr, 2);
  emxInit_real_T(&c1, 3);
  emxInit_creal_T(&C, 3);
  emxInit_real_T(&b_c1, 2);
  emxInit_creal_T(&b, 2);
  emxInit_creal_T(&y, 3);
  emxInit_real_T(&b_y, 2);
  emxInit_creal_T(&c_y, 2);
  emxInit_creal_T(&X_tmp, 2);
  emxInit_real_T(&c_c1, 2);
  emxInit_real_T(&d_c1, 2);
  guard1 = false;
  if (x->size[1] == 1) {
    c0 = (x->size[0] << 1) - 1;
    if (static_cast<double>(c0) + mxl * ((static_cast<double>(c0) - mxl) - 1.0) <
        m2 * (15.0 * ceilLog2 + 6.0)) {
      b_autocorrTD(x, mxl, c_data, c_size);
      i53 = c->size[0] * c->size[1];
      c->size[0] = c_size[0];
      c->size[1] = 1;
      emxEnsureCapacity_real_T(c, i53);
      loop_ub = c_size[0];
      for (i53 = 0; i53 < loop_ub; i53++) {
        c->data[i53] = c_data[i53];
      }
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    if (x->size[1] == 1) {
      d_fft(x, m2, c_y);
      i53 = X_tmp->size[0] * X_tmp->size[1];
      X_tmp->size[0] = c_y->size[0];
      X_tmp->size[1] = c_y->size[1];
      emxEnsureCapacity_creal_T(X_tmp, i53);
      loop_ub = c_y->size[0] * c_y->size[1];
      for (i53 = 0; i53 < loop_ub; i53++) {
        X_tmp->data[i53] = c_y->data[i53];
      }

      c0 = X_tmp->size[0] * X_tmp->size[1];
      csz_idx_0 = static_cast<short>(X_tmp->size[0]);
      csz_idx_1 = static_cast<short>(X_tmp->size[1]);
      i53 = b_c1->size[0] * b_c1->size[1];
      b_c1->size[0] = csz_idx_0;
      b_c1->size[1] = csz_idx_1;
      emxEnsureCapacity_real_T(b_c1, i53);
      for (k = 0; k < c0; k++) {
        b_c1->data[k] = rt_hypotd_snf(X_tmp->data[k].re, X_tmp->data[k].im);
      }

      c_power(b_c1, Cr);
      if ((Cr->size[0] == 0) || (Cr->size[1] == 0)) {
        csz_idx_0 = static_cast<short>(Cr->size[0]);
        i53 = c_y->size[0] * c_y->size[1];
        c_y->size[0] = csz_idx_0;
        c_y->size[1] = static_cast<short>(Cr->size[1]);
        emxEnsureCapacity_creal_T(c_y, i53);
        i53 = X_tmp->size[0] * X_tmp->size[1];
        X_tmp->size[0] = c_y->size[0];
        X_tmp->size[1] = c_y->size[1];
        emxEnsureCapacity_creal_T(X_tmp, i53);
        loop_ub = c_y->size[0] * c_y->size[1];
        for (i53 = 0; i53 < loop_ub; i53++) {
          X_tmp->data[i53] = c_y->data[i53];
        }
      } else {
        useRadix2 = ((Cr->size[0] & (Cr->size[0] - 1)) == 0);
        get_algo_sizes(Cr->size[0], useRadix2, &c0, &b_loop_ub);
        b_generate_twiddle_tables(b_loop_ub, useRadix2, costab_data, costab_size,
          sintab_data, sintab_size, sintabinv_data, sintabinv_size);
        if (useRadix2) {
          e_r2br_r2dit_trig(Cr, Cr->size[0], costab_data, sintab_data, X_tmp);
        } else {
          d_dobluesteinfft(Cr, c0, Cr->size[0], costab_data, costab_size,
                           sintab_data, sintab_size, sintabinv_data,
                           sintabinv_size, X_tmp);
        }
      }

      i53 = b_c1->size[0] * b_c1->size[1];
      b_c1->size[0] = X_tmp->size[0];
      b_c1->size[1] = X_tmp->size[1];
      emxEnsureCapacity_real_T(b_c1, i53);
      loop_ub = X_tmp->size[0] * X_tmp->size[1];
      for (i53 = 0; i53 < loop_ub; i53++) {
        b_c1->data[i53] = X_tmp->data[i53].re;
      }

      if (1.0 > mxl + 1.0) {
        loop_ub = 0;
      } else {
        loop_ub = static_cast<int>((mxl + 1.0));
      }

      if (mxl < 1.0) {
        b_y->size[0] = 1;
        b_y->size[1] = 0;
      } else {
        i53 = b_y->size[0] * b_y->size[1];
        b_y->size[0] = 1;
        b_loop_ub = static_cast<int>(std::floor(mxl - 1.0));
        b_y->size[1] = b_loop_ub + 1;
        emxEnsureCapacity_real_T(b_y, i53);
        for (i53 = 0; i53 <= b_loop_ub; i53++) {
          b_y->data[i53] = 1.0 + static_cast<double>(i53);
        }
      }

      ceilLog2 = m2 - mxl;
      c_size[0] = b_y->size[1] + loop_ub;
      b_loop_ub = b_y->size[1];
      for (i53 = 0; i53 < b_loop_ub; i53++) {
        c_data[i53] = b_c1->data[static_cast<int>((ceilLog2 + b_y->data[i53])) -
          1];
      }

      for (i53 = 0; i53 < loop_ub; i53++) {
        c_data[i53 + b_y->size[1]] = b_c1->data[i53];
      }

      i53 = c->size[0] * c->size[1];
      c->size[0] = c_size[0];
      c->size[1] = 1;
      emxEnsureCapacity_real_T(c, i53);
      loop_ub = c_size[0];
      for (i53 = 0; i53 < loop_ub; i53++) {
        c->data[i53] = c_data[i53];
      }
    } else {
      d_fft(x, m2, c_y);
      i53 = X_tmp->size[0] * X_tmp->size[1];
      X_tmp->size[0] = c_y->size[0];
      X_tmp->size[1] = c_y->size[1];
      emxEnsureCapacity_creal_T(X_tmp, i53);
      loop_ub = c_y->size[0] * c_y->size[1];
      for (i53 = 0; i53 < loop_ub; i53++) {
        X_tmp->data[i53] = c_y->data[i53];
      }

      loop_ub = X_tmp->size[0];
      b_loop_ub = X_tmp->size[1];
      i53 = b->size[0] * b->size[1];
      b->size[0] = loop_ub;
      b->size[1] = b_loop_ub;
      emxEnsureCapacity_creal_T(b, i53);
      for (i53 = 0; i53 < b_loop_ub; i53++) {
        for (i54 = 0; i54 < loop_ub; i54++) {
          b->data[i54 + b->size[0] * i53].re = X_tmp->data[i54 + X_tmp->size[0] *
            i53].re;
          b->data[i54 + b->size[0] * i53].im = -X_tmp->data[i54 + X_tmp->size[0]
            * i53].im;
        }
      }

      if (b->size[0] == 1) {
        csz_idx_0 = static_cast<short>(static_cast<int>(m2));
      } else if (static_cast<int>(m2) == 1) {
        csz_idx_0 = static_cast<short>(b->size[0]);
      } else if (static_cast<int>(m2) == b->size[0]) {
        csz_idx_0 = static_cast<short>(static_cast<int>(m2));
      } else if (b->size[0] < static_cast<int>(m2)) {
        csz_idx_0 = static_cast<short>(b->size[0]);
      } else {
        csz_idx_0 = static_cast<short>(static_cast<int>(m2));
      }

      csz_idx_1 = static_cast<short>(b->size[1]);
      csz_idx_2 = static_cast<short>(x->size[1]);
      i53 = C->size[0] * C->size[1] * C->size[2];
      C->size[0] = csz_idx_0;
      C->size[1] = csz_idx_1;
      C->size[2] = csz_idx_2;
      emxEnsureCapacity_creal_T(C, i53);
      if ((C->size[0] != 0) && (C->size[1] != 0) && (C->size[2] != 0)) {
        c0 = (x->size[1] != 1);
        i53 = C->size[2] - 1;
        for (k = 0; k <= i53; k++) {
          b_loop_ub = c0 * k;
          bcoef = (b->size[1] != 1);
          i54 = C->size[1] - 1;
          for (loop_ub = 0; loop_ub <= i54; loop_ub++) {
            varargin_5 = bcoef * loop_ub;
            acoef_tmp = static_cast<int>(m2);
            acoef = (acoef_tmp != 1);
            b_bcoef = (b->size[0] != 1);
            i55 = C->size[0] - 1;
            for (b_k = 0; b_k <= i55; b_k++) {
              X_tmp_re_tmp = acoef * b_k + acoef_tmp * b_loop_ub;
              ceilLog2 = X_tmp->data[X_tmp_re_tmp].re;
              X_tmp_im = X_tmp->data[X_tmp_re_tmp].im;
              b_re = b->data[b_bcoef * b_k + b->size[0] * varargin_5].re;
              b_im = b->data[b_bcoef * b_k + b->size[0] * varargin_5].im;
              C->data[(b_k + C->size[0] * loop_ub) + C->size[0] * C->size[1] * k]
                .re = ceilLog2 * b_re - X_tmp_im * b_im;
              C->data[(b_k + C->size[0] * loop_ub) + C->size[0] * C->size[1] * k]
                .im = ceilLog2 * b_im + X_tmp_im * b_re;
            }
          }
        }
      }

      if ((C->size[0] == 0) || (C->size[1] == 0) || (C->size[2] == 0)) {
        csz_idx_0 = static_cast<short>(C->size[0]);
        i53 = y->size[0] * y->size[1] * y->size[2];
        y->size[0] = csz_idx_0;
        y->size[1] = static_cast<short>(C->size[1]);
        y->size[2] = static_cast<short>(C->size[2]);
        emxEnsureCapacity_creal_T(y, i53);
      } else {
        useRadix2 = ((C->size[0] & (C->size[0] - 1)) == 0);
        get_algo_sizes(C->size[0], useRadix2, &c0, &b_loop_ub);
        b_generate_twiddle_tables(b_loop_ub, useRadix2, costab_data, costab_size,
          sintab_data, sintab_size, sintabinv_data, sintabinv_size);
        if (useRadix2) {
          f_r2br_r2dit_trig(C, C->size[0], costab_data, sintab_data, y);
        } else {
          e_dobluesteinfft(C, c0, C->size[0], costab_data, costab_size,
                           sintab_data, sintab_size, sintabinv_data,
                           sintabinv_size, y);
        }
      }

      i53 = c1->size[0] * c1->size[1] * c1->size[2];
      c1->size[0] = y->size[0];
      c1->size[1] = y->size[1];
      c1->size[2] = y->size[2];
      emxEnsureCapacity_real_T(c1, i53);
      loop_ub = y->size[0] * y->size[1] * y->size[2];
      for (i53 = 0; i53 < loop_ub; i53++) {
        c1->data[i53] = y->data[i53].re;
      }

      if (1.0 > mxl + 1.0) {
        loop_ub = 0;
      } else {
        loop_ub = static_cast<int>((mxl + 1.0));
      }

      if (mxl < 1.0) {
        b_y->size[0] = 1;
        b_y->size[1] = 0;
      } else {
        i53 = b_y->size[0] * b_y->size[1];
        b_y->size[0] = 1;
        b_y->size[1] = static_cast<int>(std::floor(mxl - 1.0)) + 1;
        emxEnsureCapacity_real_T(b_y, i53);
        b_loop_ub = static_cast<int>(std::floor(mxl - 1.0));
        for (i53 = 0; i53 <= b_loop_ub; i53++) {
          b_y->data[i53] = 1.0 + static_cast<double>(i53);
        }
      }

      i53 = c1->size[1] * c1->size[2];
      c0 = b_y->size[1];
      if ((c0 != 0) && (i53 != 0)) {
        varargin_5 = c1->size[1] * c1->size[2];
      } else {
        i53 = c1->size[1] * c1->size[2];
        if ((loop_ub != 0) && (i53 != 0)) {
          varargin_5 = c1->size[1] * c1->size[2];
        } else {
          i53 = c1->size[1] * c1->size[2];
          if (i53 > 0) {
            varargin_5 = c1->size[1] * c1->size[2];
          } else {
            varargin_5 = 0;
          }

          i53 = c1->size[1] * c1->size[2];
          if (i53 > varargin_5) {
            varargin_5 = c1->size[1] * c1->size[2];
          }
        }
      }

      useRadix2 = (varargin_5 == 0);
      guard2 = false;
      if (useRadix2) {
        guard2 = true;
      } else {
        i53 = c1->size[1] * c1->size[2];
        c0 = b_y->size[1];
        if ((c0 != 0) && (i53 != 0)) {
          guard2 = true;
        } else {
          csz_idx_0 = 0;
        }
      }

      if (guard2) {
        c0 = b_y->size[1];
        csz_idx_0 = static_cast<short>(c0);
      }

      if (useRadix2) {
        csz_idx_1 = static_cast<short>(loop_ub);
      } else {
        i53 = c1->size[1] * c1->size[2];
        if ((loop_ub != 0) && (i53 != 0)) {
          csz_idx_1 = static_cast<short>(loop_ub);
        } else {
          csz_idx_1 = 0;
        }
      }

      bcoef = c1->size[0];
      m2 -= mxl;
      b_loop_ub = c1->size[1] * c1->size[2];
      i53 = c_c1->size[0] * c_c1->size[1];
      c_c1->size[0] = b_y->size[1];
      c_c1->size[1] = b_loop_ub;
      emxEnsureCapacity_real_T(c_c1, i53);
      for (i53 = 0; i53 < b_loop_ub; i53++) {
        c0 = b_y->size[1];
        for (i54 = 0; i54 < c0; i54++) {
          c_c1->data[i54 + c_c1->size[0] * i53] = c1->data[(static_cast<int>((m2
            + b_y->data[i54])) + bcoef * i53) - 1];
        }
      }

      c0 = csz_idx_0;
      bcoef = c1->size[0];
      b_loop_ub = c1->size[1] * c1->size[2];
      i53 = d_c1->size[0] * d_c1->size[1];
      d_c1->size[0] = loop_ub;
      d_c1->size[1] = b_loop_ub;
      emxEnsureCapacity_real_T(d_c1, i53);
      for (i53 = 0; i53 < b_loop_ub; i53++) {
        for (i54 = 0; i54 < loop_ub; i54++) {
          d_c1->data[i54 + d_c1->size[0] * i53] = c1->data[i54 + bcoef * i53];
        }
      }

      bcoef = csz_idx_1;
      i53 = c->size[0] * c->size[1];
      c->size[0] = csz_idx_0 + csz_idx_1;
      c->size[1] = varargin_5;
      emxEnsureCapacity_real_T(c, i53);
      for (i53 = 0; i53 < varargin_5; i53++) {
        for (i54 = 0; i54 < c0; i54++) {
          c->data[i54 + c->size[0] * i53] = c_c1->data[i54 + csz_idx_0 * i53];
        }
      }

      for (i53 = 0; i53 < varargin_5; i53++) {
        for (i54 = 0; i54 < bcoef; i54++) {
          c->data[(i54 + csz_idx_0) + c->size[0] * i53] = d_c1->data[i54 +
            csz_idx_1 * i53];
        }
      }
    }
  }

  emxFree_real_T(&d_c1);
  emxFree_real_T(&c_c1);
  emxFree_creal_T(&X_tmp);
  emxFree_creal_T(&c_y);
  emxFree_real_T(&b_y);
  emxFree_creal_T(&y);
  emxFree_creal_T(&b);
  emxFree_real_T(&b_c1);
  emxFree_creal_T(&C);
  emxFree_real_T(&c1);
  emxFree_real_T(&Cr);
}

static void b_autocorrTD(const emxArray_real_T *x, double maxlag, double c_data[],
  int c_size[1])
{
  double mxl;
  int c_size_tmp;
  int k;
  double s;
  int i56;
  int i;
  mxl = static_cast<double>(x->size[0]) - 1.0;
  if (maxlag < mxl) {
    mxl = maxlag;
  }

  c_size_tmp = static_cast<int>((2.0 * mxl + 1.0));
  c_size[0] = c_size_tmp;
  if (0 <= c_size_tmp - 1) {
    memset(&c_data[0], 0, (unsigned int)(c_size_tmp * static_cast<int>(sizeof
             (double))));
  }

  c_size_tmp = static_cast<int>((mxl + 1.0));
  for (k = 0; k < c_size_tmp; k++) {
    s = 0.0;
    i56 = x->size[0] - k;
    for (i = 0; i < i56; i++) {
      s += x->data[i] * x->data[k + i];
    }

    c_data[static_cast<int>(((mxl - static_cast<double>(k)) + 1.0)) - 1] = s;
    c_data[static_cast<int>(((mxl + static_cast<double>(k)) + 1.0)) - 1] = s;
  }
}

static void b_xcorr(const double x_data[], const int x_size[1], double c_data[],
                    int c_size[1], double lags_data[], int lags_size[2])
{
  double tmp_data[625];
  int tmp_size[1];
  int c1_size[1];
  static double c1_data[4408];
  emxArray_real_T *r17;
  emxArray_real_T b_c1_data;
  int loop_ub;
  int i43;
  emxArray_real_T *y;
  autocorr(x_data, x_size, static_cast<double>(x_size[0]) - 1.0, tmp_data,
           tmp_size);
  c1_size[0] = tmp_size[0];
  if (0 <= tmp_size[0] - 1) {
    memcpy(&c1_data[0], &tmp_data[0], (unsigned int)(tmp_size[0] * static_cast<
            int>(sizeof(double))));
  }

  emxInit_real_T(&r17, 1);
  scaleXcorr(c1_data, c1_size, x_size);
  b_c1_data.data = &c1_data[0];
  b_c1_data.size = &c1_size[0];
  b_c1_data.allocatedSize = 4408;
  b_c1_data.numDimensions = 1;
  b_c1_data.canFreeData = false;
  padOutput(&b_c1_data, static_cast<double>(x_size[0]) - 1.0, static_cast<double>
            (x_size[0]) - 1.0, r17);
  c_size[0] = r17->size[0];
  loop_ub = r17->size[0];
  for (i43 = 0; i43 < loop_ub; i43++) {
    c_data[i43] = r17->data[i43];
  }

  emxFree_real_T(&r17);
  emxInit_real_T(&y, 2);
  if (x_size[0] - 1 < 1 - x_size[0]) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else {
    i43 = y->size[0] * y->size[1];
    y->size[0] = 1;
    loop_ub = static_cast<short>((x_size[0] - 1)) - static_cast<short>((1 -
      x_size[0]));
    y->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(y, i43);
    for (i43 = 0; i43 <= loop_ub; i43++) {
      y->data[i43] = static_cast<short>((static_cast<short>((1 - x_size[0])) +
        static_cast<short>(i43)));
    }
  }

  lags_size[0] = 1;
  lags_size[1] = y->size[1];
  loop_ub = y->size[0] * y->size[1];
  for (i43 = 0; i43 < loop_ub; i43++) {
    lags_data[i43] = y->data[i43];
  }

  emxFree_real_T(&y);
}

static void crosscorr(const double x_data[], const int x_size[2], const
                      emxArray_real_T *y, double maxlag, emxArray_real_T *c)
{
  int m;
  double mxl;
  double ceilLog2;
  double m2;
  emxArray_creal_T *X;
  emxArray_creal_T *r27;
  emxArray_real_T b_x_data;
  int i71;
  emxArray_creal_T *r28;
  emxArray_creal_T *b_X;
  emxArray_real_T *c1;
  double im;
  double X_re;
  double X_im;
  emxArray_real_T *b_y;
  int loop_ub_tmp;
  m = y->size[0];
  if (125 > m) {
    m = 125;
  }

  mxl = static_cast<double>(m) - 1.0;
  if (maxlag < mxl) {
    mxl = maxlag;
  }

  ceilLog2 = nextpow2(2.0 * static_cast<double>(m) - 1.0);
  m2 = mpower(ceilLog2);
  if (OpCountForXcorrTD(mxl, (double)y->size[0]) < m2 * (15.0 * ceilLog2 + 6.0))
  {
    crosscorrTD(x_data, y, mxl, c);
  } else {
    emxInit_creal_T(&X, 2);
    emxInit_creal_T(&r27, 2);
    b_x_data.data = const_cast<double *>(&x_data[0]);
    b_x_data.size = const_cast<int *>(&x_size[0]);
    b_x_data.allocatedSize = -1;
    b_x_data.numDimensions = 2;
    b_x_data.canFreeData = false;
    d_fft(&b_x_data, m2, r27);
    i71 = X->size[0] * X->size[1];
    X->size[0] = r27->size[0];
    X->size[1] = r27->size[1];
    emxEnsureCapacity_creal_T(X, i71);
    m = r27->size[0] * r27->size[1];
    for (i71 = 0; i71 < m; i71++) {
      X->data[i71] = r27->data[i71];
    }

    emxFree_creal_T(&r27);
    emxInit_creal_T(&r28, 1);
    emxInit_creal_T(&b_X, 1);
    c_fft(y, m2, r28);
    m = X->size[0];
    i71 = b_X->size[0];
    b_X->size[0] = m;
    emxEnsureCapacity_creal_T(b_X, i71);
    for (i71 = 0; i71 < m; i71++) {
      ceilLog2 = r28->data[i71].re;
      im = -r28->data[i71].im;
      X_re = X->data[i71].re;
      X_im = X->data[i71].im;
      b_X->data[i71].re = X_re * ceilLog2 - X_im * im;
      b_X->data[i71].im = X_re * im + X_im * ceilLog2;
    }

    emxFree_creal_T(&X);
    emxInit_real_T(&c1, 1);
    b_ifft(b_X, r28);
    i71 = c1->size[0];
    c1->size[0] = r28->size[0];
    emxEnsureCapacity_real_T(c1, i71);
    m = r28->size[0];
    emxFree_creal_T(&b_X);
    for (i71 = 0; i71 < m; i71++) {
      c1->data[i71] = r28->data[i71].re;
    }

    emxFree_creal_T(&r28);
    emxInit_real_T(&b_y, 2);
    if (mxl < 1.0) {
      b_y->size[0] = 1;
      b_y->size[1] = 0;
    } else {
      i71 = b_y->size[0] * b_y->size[1];
      b_y->size[0] = 1;
      m = static_cast<int>(std::floor(mxl - 1.0));
      b_y->size[1] = m + 1;
      emxEnsureCapacity_real_T(b_y, i71);
      for (i71 = 0; i71 <= m; i71++) {
        b_y->data[i71] = 1.0 + static_cast<double>(i71);
      }
    }

    m2 -= mxl;
    loop_ub_tmp = static_cast<int>((mxl + 1.0));
    i71 = c->size[0];
    c->size[0] = b_y->size[1] + loop_ub_tmp;
    emxEnsureCapacity_real_T(c, i71);
    m = b_y->size[1];
    for (i71 = 0; i71 < m; i71++) {
      c->data[i71] = c1->data[static_cast<int>((m2 + b_y->data[i71])) - 1];
    }

    for (i71 = 0; i71 < loop_ub_tmp; i71++) {
      c->data[i71 + b_y->size[1]] = c1->data[i71];
    }

    emxFree_real_T(&b_y);
    emxFree_real_T(&c1);
  }
}

static void crosscorrTD(const double x_data[], const emxArray_real_T *y, double
  maxlag, emxArray_real_T *c)
{
  int n;
  int maxmn;
  double mxl;
  int i72;
  int ihi;
  double s;
  int i;
  n = y->size[0];
  maxmn = y->size[0];
  if (125 > maxmn) {
    maxmn = 125;
  }

  mxl = static_cast<double>(maxmn) - 1.0;
  if (maxlag < mxl) {
    mxl = maxlag;
  }

  i72 = c->size[0];
  maxmn = static_cast<int>((2.0 * mxl + 1.0));
  c->size[0] = maxmn;
  emxEnsureCapacity_real_T(c, i72);
  for (i72 = 0; i72 < maxmn; i72++) {
    c->data[i72] = 0.0;
  }

  i72 = static_cast<int>((mxl + 1.0));
  for (maxmn = 0; maxmn < i72; maxmn++) {
    ihi = 125 - maxmn;
    if (ihi >= n) {
      ihi = n;
    }

    s = 0.0;
    for (i = 0; i < ihi; i++) {
      s += y->data[i] * x_data[maxmn + i];
    }

    c->data[static_cast<int>(((mxl + static_cast<double>(maxmn)) + 1.0)) - 1] =
      s;
  }

  i72 = static_cast<int>(mxl);
  for (maxmn = 0; maxmn < i72; maxmn++) {
    ihi = (n - maxmn) - 1;
    if (125 < ihi) {
      ihi = 125;
    }

    s = 0.0;
    for (i = 0; i < ihi; i++) {
      s += y->data[(maxmn + i) + 1] * x_data[i];
    }

    c->data[static_cast<int>(((mxl - (1.0 + static_cast<double>(maxmn))) + 1.0))
      - 1] = s;
  }
}

static void padOutput(const emxArray_real_T *c1, double maxlag, double
                      defaultMaxlag, emxArray_real_T *c)
{
  int i49;
  int loop_ub;
  double offset;
  i49 = c->size[0];
  loop_ub = static_cast<int>((2.0 * maxlag + 1.0));
  c->size[0] = loop_ub;
  emxEnsureCapacity_real_T(c, i49);
  for (i49 = 0; i49 < loop_ub; i49++) {
    c->data[i49] = 0.0;
  }

  if (maxlag > defaultMaxlag) {
    offset = maxlag - defaultMaxlag;
    i49 = c1->size[0];
    for (loop_ub = 0; loop_ub < i49; loop_ub++) {
      c->data[static_cast<int>((offset + (1.0 + static_cast<double>(loop_ub))))
        - 1] = c1->data[loop_ub];
    }
  } else {
    loop_ub = c1->size[0];
    for (i49 = 0; i49 < loop_ub; i49++) {
      c->data[i49] = c1->data[i49];
    }
  }
}

static void scaleXcorr(double c_data[], int c_size[1], const int x_size[1])
{
  emxArray_real_T *y;
  double L;
  int ndbl;
  int k;
  double apnd;
  double cdiff;
  emxArray_real_T *r41;
  double u0;
  double u1;
  int scaleUnbiased_size[1];
  double scaleUnbiased_data[4408];
  int n;
  emxArray_real_T *r42;
  emxArray_real_T b_c_data;
  emxArray_real_T b_scaleUnbiased_data;
  emxInit_real_T(&y, 2);
  L = (static_cast<double>(c_size[0]) - 1.0) / 2.0;
  if (L < -L) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else if (std::floor(-L) == -L) {
    k = y->size[0] * y->size[1];
    y->size[0] = 1;
    ndbl = static_cast<int>(std::floor(L - (-L)));
    y->size[1] = ndbl + 1;
    emxEnsureCapacity_real_T(y, k);
    for (k = 0; k <= ndbl; k++) {
      y->data[k] = -L + static_cast<double>(k);
    }
  } else {
    ndbl = static_cast<int>(std::floor((L - (-L)) + 0.5));
    apnd = -L + static_cast<double>(ndbl);
    cdiff = apnd - L;
    u0 = std::abs(-L);
    u1 = std::abs(L);
    if (u0 > u1) {
      u1 = u0;
    }

    if (std::abs(cdiff) < 4.4408920985006262E-16 * u1) {
      ndbl++;
      apnd = L;
    } else if (cdiff > 0.0) {
      apnd = -L + (static_cast<double>(ndbl) - 1.0);
    } else {
      ndbl++;
    }

    if (ndbl >= 0) {
      n = ndbl;
    } else {
      n = 0;
    }

    k = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = n;
    emxEnsureCapacity_real_T(y, k);
    if (n > 0) {
      y->data[0] = -L;
      if (n > 1) {
        y->data[n - 1] = apnd;
        ndbl = (n - 1) / 2;
        for (k = 0; k <= ndbl - 2; k++) {
          y->data[1 + k] = -L + (1.0 + static_cast<double>(k));
          y->data[(n - k) - 2] = apnd - (1.0 + static_cast<double>(k));
        }

        if (ndbl << 1 == n - 1) {
          y->data[ndbl] = (-L + apnd) / 2.0;
        } else {
          y->data[ndbl] = -L + static_cast<double>(ndbl);
          y->data[ndbl + 1] = apnd - static_cast<double>(ndbl);
        }
      }
    }
  }

  emxInit_real_T(&r41, 2);
  c_abs(y, r41);
  scaleUnbiased_size[0] = r41->size[1];
  ndbl = r41->size[1];
  emxFree_real_T(&y);
  for (k = 0; k < ndbl; k++) {
    scaleUnbiased_data[k] = static_cast<double>(x_size[0]) - r41->data[k];
  }

  emxFree_real_T(&r41);
  ndbl = scaleUnbiased_size[0];
  for (k = 0; k < ndbl; k++) {
    if (scaleUnbiased_data[k] <= 0.0) {
      scaleUnbiased_data[k] = 1.0;
    }
  }

  emxInit_real_T(&r42, 1);
  b_c_data.data = &c_data[0];
  b_c_data.size = &c_size[0];
  b_c_data.allocatedSize = -1;
  b_c_data.numDimensions = 1;
  b_c_data.canFreeData = false;
  b_scaleUnbiased_data.data = &scaleUnbiased_data[0];
  b_scaleUnbiased_data.size = &scaleUnbiased_size[0];
  b_scaleUnbiased_data.allocatedSize = 4408;
  b_scaleUnbiased_data.numDimensions = 1;
  b_scaleUnbiased_data.canFreeData = false;
  e_bsxfun(&b_c_data, &b_scaleUnbiased_data, r42);
  c_size[0] = r42->size[0];
  ndbl = r42->size[0];
  for (k = 0; k < ndbl; k++) {
    c_data[k] = r42->data[k];
  }

  emxFree_real_T(&r42);
}

void c_xcorr(const emxArray_real_T *x, emxArray_real_T *c, double lags_data[],
             int lags_size[2])
{
  emxArray_real_T *c1;
  emxArray_real_T *b_c1;
  int i50;
  int loop_ub;
  emxArray_real_T *y;
  double L;
  int ndbl;
  double apnd;
  double cdiff;
  emxArray_real_T *r21;
  double u0;
  double u1;
  int scaleUnbiased_size[1];
  static double scaleUnbiased_data[4408];
  int k;
  short i51;
  short i52;
  emxInit_real_T(&c1, 2);
  emxInit_real_T(&b_c1, 2);
  b_autocorr(x, static_cast<double>(x->size[0]) - 1.0, b_c1);
  i50 = c1->size[0] * c1->size[1];
  c1->size[0] = b_c1->size[0];
  c1->size[1] = b_c1->size[1];
  emxEnsureCapacity_real_T(c1, i50);
  loop_ub = b_c1->size[0] * b_c1->size[1];
  for (i50 = 0; i50 < loop_ub; i50++) {
    c1->data[i50] = b_c1->data[i50];
  }

  emxInit_real_T(&y, 2);
  L = (static_cast<double>(c1->size[0]) - 1.0) / 2.0;
  if (L < -L) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else if (std::floor(-L) == -L) {
    i50 = y->size[0] * y->size[1];
    y->size[0] = 1;
    loop_ub = static_cast<int>(std::floor(L - (-L)));
    y->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(y, i50);
    for (i50 = 0; i50 <= loop_ub; i50++) {
      y->data[i50] = -L + static_cast<double>(i50);
    }
  } else {
    ndbl = static_cast<int>(std::floor((L - (-L)) + 0.5));
    apnd = -L + static_cast<double>(ndbl);
    cdiff = apnd - L;
    u0 = std::abs(-L);
    u1 = std::abs(L);
    if (u0 > u1) {
      u1 = u0;
    }

    if (std::abs(cdiff) < 4.4408920985006262E-16 * u1) {
      ndbl++;
      apnd = L;
    } else if (cdiff > 0.0) {
      apnd = -L + (static_cast<double>(ndbl) - 1.0);
    } else {
      ndbl++;
    }

    if (ndbl >= 0) {
      loop_ub = ndbl;
    } else {
      loop_ub = 0;
    }

    i50 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = loop_ub;
    emxEnsureCapacity_real_T(y, i50);
    if (loop_ub > 0) {
      y->data[0] = -L;
      if (loop_ub > 1) {
        y->data[loop_ub - 1] = apnd;
        ndbl = (loop_ub - 1) / 2;
        for (k = 0; k <= ndbl - 2; k++) {
          y->data[1 + k] = -L + (1.0 + static_cast<double>(k));
          y->data[(loop_ub - k) - 2] = apnd - (1.0 + static_cast<double>(k));
        }

        if (ndbl << 1 == loop_ub - 1) {
          y->data[ndbl] = (-L + apnd) / 2.0;
        } else {
          y->data[ndbl] = -L + static_cast<double>(ndbl);
          y->data[ndbl + 1] = apnd - static_cast<double>(ndbl);
        }
      }
    }
  }

  emxInit_real_T(&r21, 2);
  c_abs(y, r21);
  ndbl = x->size[0];
  scaleUnbiased_size[0] = r21->size[1];
  loop_ub = r21->size[1];
  for (i50 = 0; i50 < loop_ub; i50++) {
    scaleUnbiased_data[i50] = static_cast<double>(ndbl) - r21->data[i50];
  }

  emxFree_real_T(&r21);
  ndbl = scaleUnbiased_size[0];
  for (k = 0; k < ndbl; k++) {
    if (scaleUnbiased_data[k] <= 0.0) {
      scaleUnbiased_data[k] = 1.0;
    }
  }

  i50 = b_c1->size[0] * b_c1->size[1];
  b_c1->size[0] = c1->size[0];
  b_c1->size[1] = c1->size[1];
  emxEnsureCapacity_real_T(b_c1, i50);
  loop_ub = c1->size[0] * c1->size[1];
  for (i50 = 0; i50 < loop_ub; i50++) {
    b_c1->data[i50] = c1->data[i50];
  }

  f_bsxfun(b_c1, scaleUnbiased_data, scaleUnbiased_size, c1);
  i50 = c->size[0] * c->size[1];
  c->size[0] = ((x->size[0] - 1) << 1) + 1;
  c->size[1] = c1->size[1];
  emxEnsureCapacity_real_T(c, i50);
  loop_ub = (((x->size[0] - 1) << 1) + 1) * c1->size[1];
  emxFree_real_T(&b_c1);
  for (i50 = 0; i50 < loop_ub; i50++) {
    c->data[i50] = 0.0;
  }

  loop_ub = c1->size[0];
  ndbl = c1->size[1];
  for (i50 = 0; i50 < ndbl; i50++) {
    for (k = 0; k < loop_ub; k++) {
      c->data[k + c->size[0] * i50] = c1->data[k + c1->size[0] * i50];
    }
  }

  emxFree_real_T(&c1);
  if (x->size[0] - 1 < 1 - x->size[0]) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else {
    i51 = static_cast<short>((1 - x->size[0]));
    i52 = static_cast<short>((x->size[0] - 1));
    i50 = y->size[0] * y->size[1];
    y->size[0] = 1;
    loop_ub = i52 - i51;
    y->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(y, i50);
    for (i50 = 0; i50 <= loop_ub; i50++) {
      y->data[i50] = static_cast<short>((i51 + static_cast<short>(i50)));
    }
  }

  lags_size[0] = 1;
  lags_size[1] = y->size[1];
  loop_ub = y->size[0] * y->size[1];
  for (i50 = 0; i50 < loop_ub; i50++) {
    lags_data[i50] = y->data[i50];
  }

  emxFree_real_T(&y);
}

void d_xcorr(const double x_data[], const int x_size[2], const emxArray_real_T
             *varargin_1, emxArray_real_T *c, emxArray_real_T *lags)
{
  int maxval;
  emxArray_real_T *c1;
  emxArray_real_T *y;
  int ndbl;
  emxArray_real_T b_varargin_1;
  int c_varargin_1[1];
  double L;
  int k;
  double apnd;
  double cdiff;
  emxArray_real_T *scaleUnbiased;
  double u0;
  emxArray_real_T *r26;
  double u1;
  int n;
  emxArray_real_T *b_c1;
  if (125 > varargin_1->size[0] * varargin_1->size[1]) {
    maxval = 124;
  } else {
    maxval = varargin_1->size[0] * varargin_1->size[1] - 1;
  }

  emxInit_real_T(&c1, 1);
  emxInit_real_T(&y, 2);
  ndbl = varargin_1->size[0] * varargin_1->size[1];
  b_varargin_1 = *varargin_1;
  c_varargin_1[0] = ndbl;
  b_varargin_1.size = &c_varargin_1[0];
  b_varargin_1.numDimensions = 1;
  crosscorr(x_data, x_size, &b_varargin_1, static_cast<double>((maxval + 1)) -
            1.0, c1);
  L = (static_cast<double>(c1->size[0]) - 1.0) / 2.0;
  if (L < -L) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else if (std::floor(-L) == -L) {
    k = y->size[0] * y->size[1];
    y->size[0] = 1;
    ndbl = static_cast<int>(std::floor(L - (-L)));
    y->size[1] = ndbl + 1;
    emxEnsureCapacity_real_T(y, k);
    for (k = 0; k <= ndbl; k++) {
      y->data[k] = -L + static_cast<double>(k);
    }
  } else {
    ndbl = static_cast<int>(std::floor((L - (-L)) + 0.5));
    apnd = -L + static_cast<double>(ndbl);
    cdiff = apnd - L;
    u0 = std::abs(-L);
    u1 = std::abs(L);
    if (u0 > u1) {
      u1 = u0;
    }

    if (std::abs(cdiff) < 4.4408920985006262E-16 * u1) {
      ndbl++;
      apnd = L;
    } else if (cdiff > 0.0) {
      apnd = -L + (static_cast<double>(ndbl) - 1.0);
    } else {
      ndbl++;
    }

    if (ndbl >= 0) {
      n = ndbl;
    } else {
      n = 0;
    }

    k = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = n;
    emxEnsureCapacity_real_T(y, k);
    if (n > 0) {
      y->data[0] = -L;
      if (n > 1) {
        y->data[n - 1] = apnd;
        ndbl = (n - 1) / 2;
        for (k = 0; k <= ndbl - 2; k++) {
          y->data[1 + k] = -L + (1.0 + static_cast<double>(k));
          y->data[(n - k) - 2] = apnd - (1.0 + static_cast<double>(k));
        }

        if (ndbl << 1 == n - 1) {
          y->data[ndbl] = (-L + apnd) / 2.0;
        } else {
          y->data[ndbl] = -L + static_cast<double>(ndbl);
          y->data[ndbl + 1] = apnd - static_cast<double>(ndbl);
        }
      }
    }
  }

  emxInit_real_T(&scaleUnbiased, 1);
  emxInit_real_T(&r26, 2);
  c_abs(y, r26);
  k = scaleUnbiased->size[0];
  scaleUnbiased->size[0] = r26->size[1];
  emxEnsureCapacity_real_T(scaleUnbiased, k);
  ndbl = r26->size[1];
  emxFree_real_T(&y);
  for (k = 0; k < ndbl; k++) {
    scaleUnbiased->data[k] = 125.0 - r26->data[k];
  }

  emxFree_real_T(&r26);
  ndbl = scaleUnbiased->size[0];
  for (k = 0; k < ndbl; k++) {
    if (scaleUnbiased->data[k] <= 0.0) {
      scaleUnbiased->data[k] = 1.0;
    }
  }

  emxInit_real_T(&b_c1, 1);
  k = b_c1->size[0];
  b_c1->size[0] = c1->size[0];
  emxEnsureCapacity_real_T(b_c1, k);
  ndbl = c1->size[0];
  for (k = 0; k < ndbl; k++) {
    b_c1->data[k] = c1->data[k];
  }

  e_bsxfun(b_c1, scaleUnbiased, c1);
  k = c->size[0];
  c->size[0] = (maxval << 1) + 1;
  emxEnsureCapacity_real_T(c, k);
  ndbl = maxval << 1;
  emxFree_real_T(&b_c1);
  emxFree_real_T(&scaleUnbiased);
  for (k = 0; k <= ndbl; k++) {
    c->data[k] = 0.0;
  }

  ndbl = c1->size[0];
  for (k = 0; k < ndbl; k++) {
    c->data[k] = c1->data[k];
  }

  emxFree_real_T(&c1);
  if (maxval < -maxval) {
    lags->size[0] = 1;
    lags->size[1] = 0;
  } else {
    k = lags->size[0] * lags->size[1];
    lags->size[0] = 1;
    lags->size[1] = (maxval + maxval) + 1;
    emxEnsureCapacity_real_T(lags, k);
    ndbl = maxval + maxval;
    for (k = 0; k <= ndbl; k++) {
      lags->data[k] = k - maxval;
    }
  }
}

void xcorr(const double x_data[], const int x_size[2], double c_data[], int
           c_size[2], double lags_data[], int lags_size[2])
{
  int x[1];
  double c1_data[625];
  int c1_size[1];
  x[0] = x_size[1];
  b_xcorr(x_data, x, c1_data, c1_size, lags_data, lags_size);
  c_size[0] = 1;
  c_size[1] = c1_size[0];
  if (0 <= c1_size[0] - 1) {
    memcpy(&c_data[0], &c1_data[0], (unsigned int)(c1_size[0] * static_cast<int>
            (sizeof(double))));
  }
}

/* End of code generation (xcorr.cpp) */

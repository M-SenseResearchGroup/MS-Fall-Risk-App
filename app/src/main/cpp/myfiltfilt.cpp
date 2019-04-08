/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * myfiltfilt.cpp
 *
 * Code generation for function 'myfiltfilt'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "myfiltfilt.h"
#include "calc_fall_risk_emxutil.h"
#include "filter.h"
#include "sparse1.h"
#include "sparse.h"
#include <string.h>

/* Function Declarations */
static int div_s32_floor(int numerator, int denominator);

/* Function Definitions */
static int div_s32_floor(int numerator, int denominator)
{
  int quotient;
  unsigned int absNumerator;
  unsigned int absDenominator;
  boolean_T quotientNeedsNegation;
  unsigned int tempAbsQuotient;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }
  } else {
    if (numerator < 0) {
      absNumerator = ~static_cast<unsigned int>(numerator) + 1U;
    } else {
      absNumerator = static_cast<unsigned int>(numerator);
    }

    if (denominator < 0) {
      absDenominator = ~static_cast<unsigned int>(denominator) + 1U;
    } else {
      absDenominator = static_cast<unsigned int>(denominator);
    }

    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }

      quotient = -static_cast<int>(tempAbsQuotient);
    } else {
      quotient = static_cast<int>(tempAbsQuotient);
    }
  }

  return quotient;
}

void myfiltfilt(const double b[3], const double a[3], emxArray_real_T *x,
                emxArray_real_T *y)
{
  boolean_T isRowVec;
  emxArray_real_T *b_x;
  int loop_ub;
  emxArray_real_T *t1_d;
  int i4;
  emxArray_int32_T *t1_colidx;
  emxArray_int32_T *t1_rowidx;
  double dv6[4];
  double zi[2];
  emxArray_real_T *yc5;
  double as;
  double d3;
  int lb;
  double zo[2];
  double b_b[3];
  double b_a[3];
  double xt[6];
  double c_b[3];
  double c_a[3];
  double unusedU0[6];
  double b_zo[2];
  boolean_T b2;
  boolean_T b3;
  unsigned int yc5_idx_0;
  int nx;
  int k;
  int naxpy;
  int j;
  double yc3[6];
  emxArray_real_T *b_y;

  /* FILTFILT Zero-phase forward and reverse digital IIR filtering. */
  /*    Y = FILTFILT(B, A, X) filters the data in vector X with the filter */
  /*    described by vectors A and B to create the filtered data Y.  The filter */
  /*    is described by the difference equation: */
  /*  */
  /*      a(1)*y(n) = b(1)*x(n) + b(2)*x(n-1) + ... + b(nb+1)*x(n-nb) */
  /*                            - a(2)*y(n-1) - ... - a(na+1)*y(n-na) */
  /*  */
  /*    The length of the input X must be more than three times the filter */
  /*    order, defined as max(length(B)-1,length(A)-1). */
  /*  */
  /*    Y = FILTFILT(SOS, G, X) filters the data in vector X with the */
  /*    second-order section (SOS) filter described by the matrix SOS and the */
  /*    vector G.  The coefficients of the SOS matrix must be expressed using */
  /*    an Lx6 matrix where L is the number of second-order sections. The scale */
  /*    values of the filter must be expressed using the vector G. The length */
  /*    of G must be between 1 and L+1, and the length of input X must be more */
  /*    than three times the filter order (input length must be greater than */
  /*    one when the order is zero). You can use filtord(SOS) to get the */
  /*    order of the filter. The SOS matrix should have the following form: */
  /*  */
  /*    SOS = [ b01 b11 b21 a01 a11 a21 */
  /*            b02 b12 b22 a02 a12 a22 */
  /*            ... */
  /*            b0L b1L b2L a0L a1L a2L ] */
  /*  */
  /*    Y = FILTFILT(D, X) filters the data in vector X with the digital filter */
  /*    D. You design a digital filter, D, by calling the <a href="matlab:help designfilt">designfilt</a> function. */
  /*    The length of the input X must be more than three times the filter */
  /*    order. You can use filtord(D) to get the order of the digital filter D. */
  /*  */
  /*    After filtering in the forward direction, the filtered sequence is then */
  /*    reversed and run back through the filter; Y is the time reverse of the */
  /*    output of the second filtering operation.  The result has precisely */
  /*    zero phase distortion, and magnitude modified by the square of the */
  /*    filter's magnitude response. Startup and ending transients are */
  /*    minimized by matching initial conditions. */
  /*  */
  /*    Note that FILTFILT should not be used when the intent of a filter is to */
  /*    modify signal phase, such as differentiators and Hilbert filters. */
  /*  */
  /*    % Example 1: */
  /*    %   Zero-phase filter a noisy ECG waveform using an IIR filter. */
  /*    */
  /*    load noisysignals x;                    % noisy waveform */
  /*    [b,a] = butter(12,0.2,'low');           % IIR filter design */
  /*    y = filtfilt(b,a,x);                    % zero-phase filtering */
  /*    y2 = filter(b,a,x);                     % conventional filtering */
  /*    plot(x,'k-.'); grid on ; hold on */
  /*    plot([y y2],'LineWidth',1.5); */
  /*    legend('Noisy ECG','Zero-phase Filtering','Conventional Filtering'); */
  /*  */
  /*    % Example 2: */
  /*    %   Use the designfilt function to design a highpass IIR digital filter  */
  /*    %   with order 4, passband frequency of 75 KHz, and a passband ripple  */
  /*    %   of 0.2 dB. Sample rate is 200 KHz. Apply zero-phase filtering to a */
  /*    %   vector of data.  */
  /*    */
  /*    D = designfilt('highpassiir', 'FilterOrder', 4, ... */
  /*             'PassbandFrequency', 75e3, 'PassbandRipple', 0.2,... */
  /*             'SampleRate', 200e3); */
  /*  */
  /*    x = rand(1000,1); */
  /*    y = filtfilt(D,x); */
  /*  */
  /*    See also FILTER, SOSFILT. */
  /*    References: */
  /*      [1] Sanjit K. Mitra, Digital Signal Processing, 2nd ed., */
  /*          McGraw-Hill, 2001 */
  /*      [2] Fredrik Gustafsson, Determining the initial states in forward- */
  /*          backward filtering, IEEE Transactions on Signal Processing, */
  /*          pp. 988-992, April 1996, Volume 44, Issue 4 */
  /*    Copyright 1988-2017 The MathWorks, Inc. */
  /*  Only double precision is supported */
  if (x->size[0] == 0) {
    y->size[0] = 0;
    y->size[1] = 0;
  } else {
    /*  If input data is a row vector, convert it to a column */
    isRowVec = (x->size[0] == 1);
    emxInit_real_T(&b_x, 1);
    if (isRowVec) {
      loop_ub = x->size[0] - 1;
      i4 = b_x->size[0];
      b_x->size[0] = loop_ub + 1;
      emxEnsureCapacity_real_T(b_x, i4);
      for (i4 = 0; i4 <= loop_ub; i4++) {
        b_x->data[i4] = x->data[i4];
      }

      i4 = x->size[0];
      x->size[0] = b_x->size[0];
      emxEnsureCapacity_real_T(x, i4);
      loop_ub = b_x->size[0];
      for (i4 = 0; i4 < loop_ub; i4++) {
        x->data[i4] = b_x->data[i4];
      }
    }

    emxInit_real_T(&t1_d, 1);
    emxInit_int32_T(&t1_colidx, 1);
    emxInit_int32_T(&t1_rowidx, 1);

    /*  Parse SOS matrix or coefficients vectors and determine initial conditions */
    /* -------------------------------------------------------------------------- */
    /*  Rules for the first two inputs to represent an SOS filter: */
    /*  b is an Lx6 matrix with L>1 or, */
    /*  b is a 1x6 vector, its 4th element is equal to 1 and a has less than 2 */
    /*  elements.  */
    /* ---------------------------------------------------------------------- */
    /*  b and a are vectors that define the transfer function of the filter */
    /* ---------------------------------------------------------------------- */
    /*  Check coefficients */
    /*  length of edge transients */
    /*  Zero pad shorter coefficient vector as needed */
    /*  Compute initial conditions to remove DC offset at beginning and end of */
    /*  filtered sequence.  Use sparse matrix to solve linear system for initial */
    /*  conditions zi, which is the vector of states for the filter b(z)/a(z) in */
    /*  the state-space formulation of the filter. */
    dv6[0] = 1.0 + a[1];
    dv6[1] = a[2];
    dv6[2] = 1.0;
    dv6[3] = -1.0;
    sparse(dv6, t1_d, t1_colidx, t1_rowidx);
    zi[0] = b[1] - b[0] * a[1];
    zi[1] = b[2] - b[0] * a[2];
    sparse_mldivide(t1_d, t1_colidx, t1_rowidx, zi);

    /*  The non-sparse solution to zi may be computed using: */
    /*       zi = ( eye(nfilt-1) - [-a(2:nfilt), [eye(nfilt-2); ... */
    /*                                            zeros(1,nfilt-2)]] ) \ ... */
    /*           ( b(2:nfilt) - b(1)*a(2:nfilt) ); */
    /*  Filter the data */
    emxFree_int32_T(&t1_rowidx);
    emxFree_int32_T(&t1_colidx);
    emxInit_real_T(&yc5, 1);
    if (x->size[0] < 10000) {
      i4 = yc5->size[0];
      yc5->size[0] = x->size[0];
      emxEnsureCapacity_real_T(yc5, i4);
      loop_ub = x->size[0];
      for (i4 = 0; i4 < loop_ub; i4++) {
        yc5->data[i4] = x->data[i4];
      }

      /* -------------------------------------------------------------------------- */
      /*  Single channel, data explicitly concatenated into one vector */
      as = yc5->data[0];
      as *= 2.0;
      i4 = yc5->size[0] - 1;
      d3 = yc5->data[i4];
      d3 *= 2.0;
      i4 = yc5->size[0] - 2;
      lb = t1_d->size[0];
      t1_d->size[0] = 12 + yc5->size[0];
      emxEnsureCapacity_real_T(t1_d, lb);
      for (lb = 0; lb < 6; lb++) {
        t1_d->data[lb] = as - yc5->data[6 - lb];
      }

      loop_ub = yc5->size[0];
      for (lb = 0; lb < loop_ub; lb++) {
        t1_d->data[lb + 6] = yc5->data[lb];
      }

      for (lb = 0; lb < 6; lb++) {
        t1_d->data[(lb + yc5->size[0]) + 6] = d3 - yc5->data[i4 - lb];
      }

      i4 = yc5->size[0];
      yc5->size[0] = t1_d->size[0];
      emxEnsureCapacity_real_T(yc5, i4);
      loop_ub = t1_d->size[0];
      for (i4 = 0; i4 < loop_ub; i4++) {
        yc5->data[i4] = t1_d->data[i4];
      }

      /*  filter, reverse data, filter again, and reverse data again */
      as = yc5->data[0];
      zo[0] = zi[0] * as;
      zo[1] = zi[1] * as;
      b_b[0] = b[0];
      b_a[0] = a[0];
      b_b[1] = b[1];
      b_a[1] = a[1];
      b_b[2] = b[2];
      b_a[2] = a[2];
      i4 = b_x->size[0];
      b_x->size[0] = yc5->size[0];
      emxEnsureCapacity_real_T(b_x, i4);
      loop_ub = yc5->size[0];
      for (i4 = 0; i4 < loop_ub; i4++) {
        b_x->data[i4] = yc5->data[i4];
      }

      filter(b_b, b_a, b_x, zo, yc5);
      i4 = yc5->size[0] - 1;
      lb = b_x->size[0];
      loop_ub = div_s32_floor(-i4, -1);
      b_x->size[0] = loop_ub + 1;
      emxEnsureCapacity_real_T(b_x, lb);
      for (lb = 0; lb <= loop_ub; lb++) {
        b_x->data[lb] = yc5->data[i4 - lb];
      }

      i4 = yc5->size[0];
      yc5->size[0] = b_x->size[0];
      emxEnsureCapacity_real_T(yc5, i4);
      loop_ub = b_x->size[0];
      for (i4 = 0; i4 < loop_ub; i4++) {
        yc5->data[i4] = b_x->data[i4];
      }

      as = yc5->data[0];
      zo[0] = zi[0] * as;
      zo[1] = zi[1] * as;
      b_b[0] = b[0];
      b_a[0] = a[0];
      b_b[1] = b[1];
      b_a[1] = a[1];
      b_b[2] = b[2];
      b_a[2] = a[2];
      i4 = b_x->size[0];
      b_x->size[0] = yc5->size[0];
      emxEnsureCapacity_real_T(b_x, i4);
      loop_ub = yc5->size[0];
      for (i4 = 0; i4 < loop_ub; i4++) {
        b_x->data[i4] = yc5->data[i4];
      }

      filter(b_b, b_a, b_x, zo, yc5);

      /*  retain reversed central section of y */
      i4 = yc5->size[0] - 7;
      lb = b_x->size[0];
      loop_ub = div_s32_floor(6 - i4, -1);
      b_x->size[0] = loop_ub + 1;
      emxEnsureCapacity_real_T(b_x, lb);
      for (lb = 0; lb <= loop_ub; lb++) {
        b_x->data[lb] = yc5->data[i4 - lb];
      }

      i4 = yc5->size[0];
      yc5->size[0] = b_x->size[0];
      emxEnsureCapacity_real_T(yc5, i4);
      loop_ub = b_x->size[0];
      for (i4 = 0; i4 < loop_ub; i4++) {
        yc5->data[i4] = b_x->data[i4];
      }

      i4 = y->size[0] * y->size[1];
      y->size[0] = yc5->size[0];
      y->size[1] = 1;
      emxEnsureCapacity_real_T(y, i4);
      loop_ub = yc5->size[0];
      for (i4 = 0; i4 < loop_ub; i4++) {
        y->data[i4] = yc5->data[i4];
      }
    } else {
      i4 = yc5->size[0];
      yc5->size[0] = x->size[0];
      emxEnsureCapacity_real_T(yc5, i4);
      loop_ub = x->size[0];
      for (i4 = 0; i4 < loop_ub; i4++) {
        yc5->data[i4] = x->data[i4];
      }

      /* -------------------------------------------------------------------------- */
      /*  Perform filtering of input data with no phase distortion */
      /*  */
      /*  xc: one column of input data */
      /*  yc: one column of output, same dimensions as xc */
      /*  a,b: IIR coefficients, both of same order/length */
      /*  zi: initial states */
      /*  nfact: scalar */
      /*  L: scalar */
      /*  Extrapolate beginning and end of data sequence using reflection. */
      /*  Slopes of original and extrapolated sequences match at end points, */
      /*  reducing transients. */
      /*  */
      /*  yc is length numel(x)+2*nfact */
      /*  */
      /*  We wish to filter the appended sequence: */
      /*  yc = [2*xc(1)-xc(nfact+1:-1:2); xc; 2*xc(end)-xc(end-1:-1:end-nfact)]; */
      /*  */
      /*  We would use the following code: */
      /*  Filter the input forwards then again in the backwards direction */
      /*    yc = filter(b,a,yc,zi*yc(1)); */
      /*    yc = yc(length(yc):-1:1); % reverse the sequence */
      /*  */
      /*  Instead of reallocating and copying, just do filtering in pieces */
      /*  Filter the first part, then xc, then the last part */
      /*  Retain each piece, feeding final states as next initial states */
      /*  Output is yc = [yc1 yc2 yc3] */
      /*  */
      /*  yc2 can be long (matching user input length) */
      /*  yc3 is short (nfilt samples) */
      /*  */
      as = 2.0 * yc5->data[0];
      for (i4 = 0; i4 < 6; i4++) {
        xt[i4] = -yc5->data[6 - i4] + as;
      }

      zo[0] = zi[0] * xt[0];
      zo[1] = zi[1] * xt[0];
      c_b[0] = b[0];
      c_a[0] = a[0];
      b_b[0] = b[0];
      b_a[0] = a[0];
      c_b[1] = b[1];
      c_a[1] = a[1];
      b_b[1] = b[1];
      b_a[1] = a[1];
      c_b[2] = b[2];
      c_a[2] = a[2];
      b_b[2] = b[2];
      b_a[2] = a[2];
      b_filter(c_b, c_a, xt, zo, unusedU0, b_zo);

      /*  yc1 not needed */
      b2 = rtIsInf(a[0]);
      b3 = rtIsNaN(a[0]);
      if ((!b2) && (!b3) && (!(a[0] == 0.0)) && (a[0] != 1.0)) {
        b_b[0] = b[0] / a[0];
        b_b[1] = b[1] / a[0];
        b_b[2] = b[2] / a[0];
        b_a[1] = a[1] / a[0];
        b_a[2] = a[2] / a[0];
        b_a[0] = 1.0;
      }

      yc5_idx_0 = static_cast<unsigned int>(yc5->size[0]);
      i4 = t1_d->size[0];
      t1_d->size[0] = static_cast<int>(yc5_idx_0);
      emxEnsureCapacity_real_T(t1_d, i4);
      nx = yc5->size[0];
      zo[0] = 0.0;
      zo[1] = 0.0;
      t1_d->data[0] = b_zo[0];
      t1_d->data[1] = b_zo[1];
      for (k = 3; k <= nx; k++) {
        t1_d->data[k - 1] = 0.0;
      }

      for (k = 0; k < nx; k++) {
        loop_ub = nx - k;
        if (loop_ub < 3) {
          naxpy = loop_ub;
        } else {
          naxpy = 3;
        }

        for (j = 0; j < naxpy; j++) {
          i4 = k + j;
          t1_d->data[i4] += yc5->data[k] * b_b[j];
        }

        naxpy = loop_ub - 1;
        if (naxpy >= 2) {
          naxpy = 2;
        }

        as = -t1_d->data[k];
        for (j = 0; j < naxpy; j++) {
          i4 = (k + j) + 1;
          t1_d->data[i4] += as * b_a[1 + j];
        }
      }

      lb = yc5->size[0] - 2;
      i4 = yc5->size[0] - 1;
      for (k = lb; k <= i4; k++) {
        loop_ub = nx - k;
        naxpy = 2 - loop_ub;
        for (j = 0; j <= naxpy; j++) {
          zo[j] += yc5->data[k] * b_b[loop_ub + j];
        }
      }

      i4 = yc5->size[0] - 1;
      for (k = lb; k <= i4; k++) {
        loop_ub = nx - k;
        naxpy = 2 - loop_ub;
        for (j = 0; j <= naxpy; j++) {
          zo[j] += -t1_d->data[k] * b_a[loop_ub + j];
        }
      }

      loop_ub = yc5->size[0] - 2;
      as = 2.0 * yc5->data[yc5->size[0] - 1];
      for (i4 = 0; i4 < 6; i4++) {
        xt[i4] = -yc5->data[loop_ub - i4] + as;
      }

      b_b[0] = b[0];
      b_a[0] = a[0];
      b_b[1] = b[1];
      b_a[1] = a[1];
      b_b[2] = b[2];
      b_a[2] = a[2];
      if ((!b2) && (!b3) && (!(a[0] == 0.0)) && (a[0] != 1.0)) {
        b_b[0] = b[0] / a[0];
        b_b[1] = b[1] / a[0];
        b_b[2] = b[2] / a[0];
        b_a[1] = a[1] / a[0];
        b_a[2] = a[2] / a[0];
        b_a[0] = 1.0;
      }

      yc3[0] = zo[0];
      yc3[1] = zo[1];
      yc3[2] = 0.0;
      yc3[3] = 0.0;
      yc3[4] = 0.0;
      yc3[5] = 0.0;
      for (k = 0; k < 6; k++) {
        if (6 - k < 3) {
          naxpy = 5 - k;
        } else {
          naxpy = 2;
        }

        for (j = 0; j <= naxpy; j++) {
          loop_ub = k + j;
          yc3[loop_ub] += xt[k] * b_b[j];
        }

        if (5 - k < 2) {
          naxpy = 4 - k;
        } else {
          naxpy = 1;
        }

        as = -yc3[k];
        for (j = 0; j <= naxpy; j++) {
          loop_ub = (k + j) + 1;
          yc3[loop_ub] += as * b_a[1 + j];
        }
      }

      /*  Reverse the sequence */
      /*    yc = [flipud(yc3) flipud(yc2) flipud(yc1)] */
      /*  which we can do as */
      /*    yc = [yc3(end:-1:1); yc2(end:-1:1); yc1(end:-1:1)]; */
      /*  */
      /*  But we don't do that explicitly.  Instead, we wish to filter this */
      /*  reversed result as in: */
      /*    yc = filter(b,a,yc,zi*yc(1)); */
      /*  where yc(1) is now the last sample of the (unreversed) yc3 */
      /*  */
      /*  Once again, we do this in pieces: */
      as = yc3[5];
      for (i4 = 0; i4 < 6; i4++) {
        xt[i4] = yc3[5 - i4];
      }

      for (i4 = 0; i4 < 6; i4++) {
        yc3[i4] = xt[i4];
      }

      zo[0] = zi[0] * as;
      zo[1] = zi[1] * as;
      b_b[0] = b[0];
      b_a[0] = a[0];
      b_b[1] = b[1];
      b_a[1] = a[1];
      b_b[2] = b[2];
      b_a[2] = a[2];
      b_filter(b_b, b_a, yc3, zo, unusedU0, b_zo);
      i4 = t1_d->size[0] - 1;
      lb = b_x->size[0];
      loop_ub = div_s32_floor(-i4, -1);
      b_x->size[0] = loop_ub + 1;
      emxEnsureCapacity_real_T(b_x, lb);
      for (lb = 0; lb <= loop_ub; lb++) {
        b_x->data[lb] = t1_d->data[i4 - lb];
      }

      i4 = t1_d->size[0];
      t1_d->size[0] = b_x->size[0];
      emxEnsureCapacity_real_T(t1_d, i4);
      loop_ub = b_x->size[0];
      for (i4 = 0; i4 < loop_ub; i4++) {
        t1_d->data[i4] = b_x->data[i4];
      }

      b_b[0] = b[0];
      b_a[0] = a[0];
      b_b[1] = b[1];
      b_a[1] = a[1];
      b_b[2] = b[2];
      b_a[2] = a[2];
      filter(b_b, b_a, t1_d, b_zo, yc5);

      /*  Conceptually restore the sequence by reversing the last pieces */
      /*     yc = yc(length(yc):-1:1); % restore the sequence */
      /*  which is done by */
      /*     yc = [yc6(end:-1:1); yc5(end:-1:1); yc4(end:-1:1)]; */
      /*  */
      /*  However, we only need to retain the reversed central samples of filtered */
      /*  output for the final result: */
      /*     y = yc(nfact+1:end-nfact); */
      /*  */
      /*  which is the reversed yc5 piece only. */
      /*  */
      /*  This means we don't need yc4 or yc6.  We need to compute yc4 only because */
      /*  the final states are needed for yc5 computation.  However, we can omit */
      /*  yc6 entirely in the above filtering step. */
      i4 = yc5->size[0] - 1;
      lb = b_x->size[0];
      loop_ub = div_s32_floor(-i4, -1);
      b_x->size[0] = loop_ub + 1;
      emxEnsureCapacity_real_T(b_x, lb);
      for (lb = 0; lb <= loop_ub; lb++) {
        b_x->data[lb] = yc5->data[i4 - lb];
      }

      i4 = yc5->size[0];
      yc5->size[0] = b_x->size[0];
      emxEnsureCapacity_real_T(yc5, i4);
      loop_ub = b_x->size[0];
      for (i4 = 0; i4 < loop_ub; i4++) {
        yc5->data[i4] = b_x->data[i4];
      }

      i4 = y->size[0] * y->size[1];
      y->size[0] = yc5->size[0];
      y->size[1] = 1;
      emxEnsureCapacity_real_T(y, i4);
      loop_ub = yc5->size[0];
      for (i4 = 0; i4 < loop_ub; i4++) {
        y->data[i4] = yc5->data[i4];
      }
    }

    emxFree_real_T(&b_x);
    emxFree_real_T(&t1_d);
    emxFree_real_T(&yc5);
    if (isRowVec) {
      emxInit_real_T(&b_y, 2);
      loop_ub = y->size[0];
      i4 = b_y->size[0] * b_y->size[1];
      b_y->size[0] = y->size[1];
      b_y->size[1] = y->size[0];
      emxEnsureCapacity_real_T(b_y, i4);
      nx = y->size[0];
      for (i4 = 0; i4 < nx; i4++) {
        k = y->size[1];
        for (lb = 0; lb < k; lb++) {
          b_y->data[lb + b_y->size[0] * i4] = y->data[i4 + y->size[0] * lb];
        }
      }

      i4 = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = loop_ub;
      emxEnsureCapacity_real_T(y, i4);
      for (i4 = 0; i4 < loop_ub; i4++) {
        y->data[i4] = b_y->data[i4];
      }

      emxFree_real_T(&b_y);

      /*  convert back to row if necessary */
    }
  }
}

/* End of code generation (myfiltfilt.cpp) */

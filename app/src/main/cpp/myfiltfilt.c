/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * myfiltfilt.c
 *
 * Code generation for function 'myfiltfilt'
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
#include "myfiltfilt.h"
#include "filter.h"
#include "getFallClass_emxutil.h"
#include "sparse1.h"
#include "sparse.h"

/* Function Declarations */
static void getCoeffsAndInitialConditions(const double b[3], const double a[3],
  double b_b[3], double b_a[3], double zi[2], double *L);

/* Function Definitions */
static void getCoeffsAndInitialConditions(const double b[3], const double a[3],
  double b_b[3], double b_a[3], double zi[2], double *L)
{
  emxArray_real_T *t0_d;
  emxArray_int32_T *t0_colidx;
  emxArray_int32_T *t0_rowidx;
  double dv7[4];

  /* -------------------------------------------------------------------------- */
  /*  Rules for the first two inputs to represent an SOS filter: */
  /*  b is an Lx6 matrix with L>1 or, */
  /*  b is a 1x6 vector, its 4th element is equal to 1 and a has less than 2 */
  /*  elements.  */
  /* ---------------------------------------------------------------------- */
  /*  b and a are vectors that define the transfer function of the filter */
  /* ---------------------------------------------------------------------- */
  *L = 1.0;

  /*  Check coefficients */
  b_b[0] = b[0];
  b_a[0] = a[0];
  b_b[1] = b[1];
  b_a[1] = a[1];
  b_b[2] = b[2];
  b_a[2] = a[2];
  emxInit_real_T(&t0_d, 1);
  emxInit_int32_T(&t0_colidx, 1);
  emxInit_int32_T(&t0_rowidx, 1);

  /*  length of edge transients */
  /*  Zero pad shorter coefficient vector as needed */
  /*  Compute initial conditions to remove DC offset at beginning and end of */
  /*  filtered sequence.  Use sparse matrix to solve linear system for initial */
  /*  conditions zi, which is the vector of states for the filter b(z)/a(z) in */
  /*  the state-space formulation of the filter. */
  dv7[0] = 1.0 + a[1];
  dv7[1] = a[2];
  dv7[2] = 1.0;
  dv7[3] = -1.0;
  sparse(dv7, t0_d, t0_colidx, t0_rowidx);
  zi[0] = b[1] - b[0] * a[1];
  zi[1] = b[2] - b[0] * a[2];
  sparse_mldivide(t0_d, t0_colidx, t0_rowidx, zi);

  /*  The non-sparse solution to zi may be computed using: */
  /*       zi = ( eye(nfilt-1) - [-a(2:nfilt), [eye(nfilt-2); ... */
  /*                                            zeros(1,nfilt-2)]] ) \ ... */
  /*           ( b(2:nfilt) - b(1)*a(2:nfilt) ); */
  emxFree_int32_T(&t0_rowidx);
  emxFree_int32_T(&t0_colidx);
  emxFree_real_T(&t0_d);
}

void myfiltfilt(const double b[3], const double a[3], double x[500])
{
  double b_b[3];
  double b_a[3];
  double zi[2];
  double L;
  double d11;
  int i54;
  double y[512];
  double b_zi[2];
  double c_b[3];
  double c_a[3];
  double b_y[512];

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
  /*  If input data is a row vector, convert it to a column */
  /*  Parse SOS matrix or coefficients vectors and determine initial conditions */
  getCoeffsAndInitialConditions(b, a, b_b, b_a, zi, &L);

  /*  Filter the data */
  /* -------------------------------------------------------------------------- */
  /*  Single channel, data explicitly concatenated into one vector */
  L = 2.0 * x[0];
  d11 = 2.0 * x[499];
  for (i54 = 0; i54 < 6; i54++) {
    y[i54] = L - x[6 - i54];
  }

  memcpy(&y[6], &x[0], 500U * sizeof(double));
  for (i54 = 0; i54 < 6; i54++) {
    y[i54 + 506] = d11 - x[498 - i54];
  }

  /*  filter, reverse data, filter again, and reverse data again */
  b_zi[0] = zi[0] * y[0];
  b_zi[1] = zi[1] * y[0];
  c_b[0] = b_b[0];
  c_a[0] = b_a[0];
  c_b[1] = b_b[1];
  c_a[1] = b_a[1];
  c_b[2] = b_b[2];
  c_a[2] = b_a[2];
  memcpy(&b_y[0], &y[0], sizeof(double) << 9);
  b_filter(c_b, c_a, b_y, b_zi, y);
  for (i54 = 0; i54 < 512; i54++) {
    b_y[i54] = y[511 - i54];
  }

  memcpy(&y[0], &b_y[0], sizeof(double) << 9);
  b_zi[0] = zi[0] * y[0];
  b_zi[1] = zi[1] * y[0];
  c_b[0] = b_b[0];
  c_a[0] = b_a[0];
  c_b[1] = b_b[1];
  c_a[1] = b_a[1];
  c_b[2] = b_b[2];
  c_a[2] = b_a[2];
  memcpy(&b_y[0], &y[0], sizeof(double) << 9);
  b_filter(c_b, c_a, b_y, b_zi, y);

  /*  retain reversed central section of y */
  for (i54 = 0; i54 < 500; i54++) {
    x[i54] = y[505 - i54];
  }
}

/* End of code generation (myfiltfilt.c) */

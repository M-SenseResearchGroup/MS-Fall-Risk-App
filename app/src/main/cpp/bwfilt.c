/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * bwfilt.c
 *
 * Code generation for function 'bwfilt'
 *
 */

/* Include files */
#include <math.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "calibrate.h"
#include "get_calibration.h"
#include "get_classification.h"
#include "get_fall_class.h"
#include "get_features.h"
#include "get_strides.h"
#include "pre_process_feats.h"
#include "bwfilt.h"
#include "filter.h"
#include "getFallClass_emxutil.h"
#include "sparse1.h"
#include "sparse.h"
#include "myButter.h"
#include "myfiltfilt.h"
#include "poly1.h"
#include "mpower.h"
#include "prod.h"
#include "tan.h"

/* Function Definitions */
void b_bwfilt(const double in[500], const emxArray_real_T *cf, double sf, double
              out[500])
{
  emxArray_real_T *V;
  int i46;
  int loop_ub;
  double b_V;
  double re;
  double im;
  creal_T Sp[2];
  creal_T dcv1[2];
  emxArray_real_T *G;
  creal_T y;
  double Sp_re;
  double brm;
  double bim;
  double b_y;
  double c_y;
  creal_T dcv2[3];
  double b_G[3];
  double dv10[3];
  emxInit_real_T(&V, 2);

  /* Reed Gurchiek, 2018 */
  /*    bwfilter uses MATLABs butter function to determine the transfer */
  /*    function coefficients to filter signal(s) in sampled at frequency sf by */
  /*    a specified order according to the specified filter type */
  /*    'low','high','bandpass','bandstop'.  The transfer function is */
  /*    implemented in filtfilt to remove phase shift (i.e. filter is zero lag) */
  /*  */
  /* ---------------------------INPUTS----------------------------------------- */
  /*  */
  /*    in: */
  /*        m x n signal to be filtered.  the longest dimension is considered */
  /*        the time dimension. */
  /*  */
  /*    cf: */
  /*        cutoff frequency.  If vector then type should be bandpass. */
  /*  */
  /*    sf: */
  /*        scalar, sampling frequency in samples/second. */
  /*  */
  /*    type (optional): */
  /*        'low','high','bandpass','bandstop', default = 'low' */
  /*  */
  /*    order (optional): */
  /*        filter order, should be even, default = 4; */
  /*  */
  /* --------------------------OUTPUTS----------------------------------------- */
  /*  */
  /*    out: */
  /*        filtered signal */
  /*  */
  /* -------------------------------------------------------------------------- */
  /*  bwfilt */
  /*  filter type */
  /*  filter order */
  /*  if odd, make even */
  /*  divide by 2 to compensate for filtfilt */
  /*  get transfer fxn coefs */
  /*  [b,a] = butter(order,2*cf/sf,type); (old butter) */
  /*  Digital Butterworth filter, either 2 or 3 outputs */
  /*  Jan Simon, 2014, BSD licence */
  /*  See docs of BUTTER for input and output */
  /*  Fast hack with limited accuracy: Handle with care! */
  /*  Until n=15 the relative difference to Matlab's BUTTER is < 100*eps */
  i46 = V->size[0] * V->size[1];
  V->size[0] = 1;
  V->size[1] = cf->size[1];
  emxEnsureCapacity_real_T(V, i46);
  loop_ub = cf->size[0] * cf->size[1];
  for (i46 = 0; i46 < loop_ub; i46++) {
    V->data[i46] = 2.0 * cf->data[i46] / sf * 1.5707963267948966;
  }

  b_tan(V);
  b_V = V->data[0];

  /*  Bilinear transform: */
  re = b_V * -0.70710678118654746;
  im = b_V * 0.70710678118654757;
  Sp[0].re = re;
  Sp[0].im = im;
  dcv1[0].re = 1.0 - re;
  dcv1[0].im = 0.0 - im;
  re = b_V * -0.70710678118654768;
  im = b_V * -0.70710678118654746;
  dcv1[1].re = 1.0 - re;
  dcv1[1].im = 0.0 - im;
  emxInit_real_T(&G, 2);
  y = prod(dcv1);
  mpower(V, G);
  i46 = G->size[0] * G->size[1];
  loop_ub = G->size[0] * G->size[1];
  G->size[0] = 1;
  emxEnsureCapacity_real_T(G, loop_ub);
  loop_ub = i46 - 1;
  emxFree_real_T(&V);
  for (i46 = 0; i46 <= loop_ub; i46++) {
    b_V = G->data[i46];
    if (y.im == 0.0) {
      b_V /= y.re;
    } else if (y.re == 0.0) {
      if (b_V == 0.0) {
        b_V = 0.0 / y.im;
      } else {
        b_V = 0.0;
      }
    } else {
      brm = fabs(y.re);
      bim = fabs(y.im);
      if (brm > bim) {
        brm = y.im / y.re;
        b_V = (b_V + brm * 0.0) / (y.re + brm * y.im);
      } else if (bim == brm) {
        if (y.re > 0.0) {
          b_y = 0.5;
        } else {
          b_y = -0.5;
        }

        if (y.im > 0.0) {
          c_y = 0.5;
        } else {
          c_y = -0.5;
        }

        b_V = (b_V * b_y + 0.0 * c_y) / brm;
      } else {
        brm = y.re / y.im;
        b_V = brm * b_V / (y.im + brm * y.re);
      }
    }

    G->data[i46] = b_V;
  }

  /*  From Zeros, Poles and Gain to B (numerator) and A (denominator): */
  /*  transpose to adjust for filtfilt? */
  Sp_re = 1.0 + Sp[0].re;
  b_V = 1.0 - Sp[0].re;
  if (0.0 - Sp[0].im == 0.0) {
    if (Sp[0].im == 0.0) {
      Sp[0].re = (1.0 + Sp[0].re) / (1.0 - Sp[0].re);
      Sp[0].im = 0.0;
    } else if (1.0 + Sp[0].re == 0.0) {
      Sp[0].re = 0.0;
      Sp[0].im /= b_V;
    } else {
      Sp[0].re = (1.0 + Sp[0].re) / (1.0 - Sp[0].re);
      Sp[0].im /= b_V;
    }
  } else if (1.0 - Sp[0].re == 0.0) {
    if (1.0 + Sp[0].re == 0.0) {
      Sp[0].re = Sp[0].im / (0.0 - Sp[0].im);
      Sp[0].im = 0.0;
    } else if (Sp[0].im == 0.0) {
      Sp[0].re = 0.0;
      Sp[0].im = -(Sp_re / (0.0 - Sp[0].im));
    } else {
      Sp[0].re = Sp[0].im / (0.0 - Sp[0].im);
      Sp[0].im = -(Sp_re / (0.0 - Sp[0].im));
    }
  } else {
    brm = fabs(1.0 - Sp[0].re);
    bim = fabs(0.0 - Sp[0].im);
    if (brm > bim) {
      brm = (0.0 - Sp[0].im) / (1.0 - Sp[0].re);
      bim = (1.0 - Sp[0].re) + brm * (0.0 - Sp[0].im);
      Sp[0].re = ((1.0 + Sp[0].re) + brm * Sp[0].im) / bim;
      Sp[0].im = (Sp[0].im - brm * Sp_re) / bim;
    } else if (bim == brm) {
      if (1.0 - Sp[0].re > 0.0) {
        b_V = 0.5;
      } else {
        b_V = -0.5;
      }

      if (0.0 - Sp[0].im > 0.0) {
        bim = 0.5;
      } else {
        bim = -0.5;
      }

      Sp[0].re = ((1.0 + Sp[0].re) * b_V + Sp[0].im * bim) / brm;
      Sp[0].im = (Sp[0].im * b_V - Sp_re * bim) / brm;
    } else {
      brm = (1.0 - Sp[0].re) / (0.0 - Sp[0].im);
      bim = (0.0 - Sp[0].im) + brm * (1.0 - Sp[0].re);
      b_V = brm * Sp[0].im - (1.0 + Sp[0].re);
      Sp[0].re = (brm * (1.0 + Sp[0].re) + Sp[0].im) / bim;
      Sp[0].im = b_V / bim;
    }
  }

  if (0.0 - im == 0.0) {
    if (im == 0.0) {
      Sp[1].re = (1.0 + re) / (1.0 - re);
      Sp[1].im = 0.0;
    } else if (1.0 + re == 0.0) {
      Sp[1].re = 0.0;
      Sp[1].im = im / (1.0 - re);
    } else {
      Sp[1].re = (1.0 + re) / (1.0 - re);
      Sp[1].im = im / (1.0 - re);
    }
  } else if (1.0 - re == 0.0) {
    if (1.0 + re == 0.0) {
      Sp[1].re = im / (0.0 - im);
      Sp[1].im = 0.0;
    } else if (im == 0.0) {
      Sp[1].re = 0.0;
      Sp[1].im = -((1.0 + re) / (0.0 - im));
    } else {
      Sp[1].re = im / (0.0 - im);
      Sp[1].im = -((1.0 + re) / (0.0 - im));
    }
  } else {
    brm = fabs(1.0 - re);
    bim = fabs(0.0 - im);
    if (brm > bim) {
      brm = (0.0 - im) / (1.0 - re);
      bim = (1.0 - re) + brm * (0.0 - im);
      Sp[1].re = ((1.0 + re) + brm * im) / bim;
      Sp[1].im = (im - brm * (1.0 + re)) / bim;
    } else if (bim == brm) {
      if (1.0 - re > 0.0) {
        b_V = 0.5;
      } else {
        b_V = -0.5;
      }

      if (0.0 - im > 0.0) {
        bim = 0.5;
      } else {
        bim = -0.5;
      }

      Sp[1].re = ((1.0 + re) * b_V + im * bim) / brm;
      Sp[1].im = (im * b_V - (1.0 + re) * bim) / brm;
    } else {
      brm = (1.0 - re) / (0.0 - im);
      bim = (0.0 - im) + brm * (1.0 - re);
      Sp[1].re = (brm * (1.0 + re) + im) / bim;
      Sp[1].im = (brm * im - (1.0 + re)) / bim;
    }
  }

  poly(Sp, dcv2);
  memcpy(&out[0], &in[0], 500U * sizeof(double));
  b_V = G->data[0];
  emxFree_real_T(&G);
  b_G[0] = b_V;
  dv10[0] = dcv2[0].re;
  b_G[1] = b_V * 2.0;
  dv10[1] = dcv2[1].re;
  b_G[2] = b_V;
  dv10[2] = dcv2[2].re;
  myfiltfilt(b_G, dv10, out);

  /*  filter */
  /*  if c > r; out = out'; end */
}

void bwfilt(const double in[125], double sf, double out[125])
{
  double b[3];
  double a[3];
  emxArray_real_T *t2_d;
  emxArray_int32_T *t2_colidx;
  emxArray_int32_T *t2_rowidx;
  double dv6[4];
  double zi[2];
  double d3;
  double d4;
  int i11;
  double y[137];
  double b_zi[2];
  double b_b[3];
  double b_a[3];
  double b_y[137];

  /* Reed Gurchiek, 2018 */
  /*    bwfilter uses MATLABs butter function to determine the transfer */
  /*    function coefficients to filter signal(s) in sampled at frequency sf by */
  /*    a specified order according to the specified filter type */
  /*    'low','high','bandpass','bandstop'.  The transfer function is */
  /*    implemented in filtfilt to remove phase shift (i.e. filter is zero lag) */
  /*  */
  /* ---------------------------INPUTS----------------------------------------- */
  /*  */
  /*    in: */
  /*        m x n signal to be filtered.  the longest dimension is considered */
  /*        the time dimension. */
  /*  */
  /*    cf: */
  /*        cutoff frequency.  If vector then type should be bandpass. */
  /*  */
  /*    sf: */
  /*        scalar, sampling frequency in samples/second. */
  /*  */
  /*    type (optional): */
  /*        'low','high','bandpass','bandstop', default = 'low' */
  /*  */
  /*    order (optional): */
  /*        filter order, should be even, default = 4; */
  /*  */
  /* --------------------------OUTPUTS----------------------------------------- */
  /*  */
  /*    out: */
  /*        filtered signal */
  /*  */
  /* -------------------------------------------------------------------------- */
  /*  bwfilt */
  /*  filter type */
  /*  filter order */
  /*  if odd, make even */
  /*  divide by 2 to compensate for filtfilt */
  /*  get transfer fxn coefs */
  /*  [b,a] = butter(order,2*cf/sf,type); (old butter) */
  myButter(2.0 / sf, b, a);

  /*  transpose to adjust for filtfilt? */
  memcpy(&out[0], &in[0], 125U * sizeof(double));
  emxInit_real_T(&t2_d, 1);
  emxInit_int32_T(&t2_colidx, 1);
  emxInit_int32_T(&t2_rowidx, 1);

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
  sparse(dv6, t2_d, t2_colidx, t2_rowidx);
  zi[0] = b[1] - b[0] * a[1];
  zi[1] = b[2] - b[0] * a[2];
  sparse_mldivide(t2_d, t2_colidx, t2_rowidx, zi);

  /*  The non-sparse solution to zi may be computed using: */
  /*       zi = ( eye(nfilt-1) - [-a(2:nfilt), [eye(nfilt-2); ... */
  /*                                            zeros(1,nfilt-2)]] ) \ ... */
  /*           ( b(2:nfilt) - b(1)*a(2:nfilt) ); */
  /*  Filter the data */
  /* -------------------------------------------------------------------------- */
  emxFree_int32_T(&t2_rowidx);
  emxFree_int32_T(&t2_colidx);
  emxFree_real_T(&t2_d);

  /*  Single channel, data explicitly concatenated into one vector */
  d3 = 2.0 * out[0];
  d4 = 2.0 * out[124];
  for (i11 = 0; i11 < 6; i11++) {
    y[i11] = d3 - out[6 - i11];
  }

  memcpy(&y[6], &out[0], 125U * sizeof(double));
  for (i11 = 0; i11 < 6; i11++) {
    y[i11 + 131] = d4 - out[123 - i11];
  }

  /*  filter, reverse data, filter again, and reverse data again */
  b_zi[0] = zi[0] * y[0];
  b_zi[1] = zi[1] * y[0];
  b_b[0] = b[0];
  b_a[0] = a[0];
  b_b[1] = b[1];
  b_a[1] = a[1];
  b_b[2] = b[2];
  b_a[2] = a[2];
  memcpy(&b_y[0], &y[0], 137U * sizeof(double));
  filter(b_b, b_a, b_y, b_zi, y);
  for (i11 = 0; i11 < 137; i11++) {
    b_y[i11] = y[136 - i11];
  }

  memcpy(&y[0], &b_y[0], 137U * sizeof(double));
  b_zi[0] = zi[0] * y[0];
  b_zi[1] = zi[1] * y[0];
  b_b[0] = b[0];
  b_a[0] = a[0];
  b_b[1] = b[1];
  b_a[1] = a[1];
  b_b[2] = b[2];
  b_a[2] = a[2];
  memcpy(&b_y[0], &y[0], 137U * sizeof(double));
  filter(b_b, b_a, b_y, b_zi, y);

  /*  retain reversed central section of y */
  for (i11 = 0; i11 < 125; i11++) {
    out[i11] = y[130 - i11];
  }

  /*  filter */
  /*  if c > r; out = out'; end */
}

/* End of code generation (bwfilt.c) */

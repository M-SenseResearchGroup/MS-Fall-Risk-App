/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * bwfilt.cpp
 *
 * Code generation for function 'bwfilt'
 *
 */

/* Include files */
#include <cmath>
#include <string.h>
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "bwfilt.h"
#include "calc_fall_risk_emxutil.h"
#include "myfiltfilt.h"
#include "poly.h"
#include "sparse1.h"
#include "sparse.h"
#include "myButter.h"

/* Function Definitions */
void b_bwfilt(const emxArray_real_T *in, const emxArray_real_T *cf, double sf,
              emxArray_real_T *out)
{
  emxArray_real_T *V;
  int nx;
  int loop_ub;
  double b_V;
  double re;
  double im;
  creal_T Sp[2];
  creal_T x[2];
  double y_re;
  double y_im;
  double d6;
  double brm;
  double bim;
  double b_y_re;
  double b_y_im;
  creal_T dcv1[3];
  double c_V[3];
  double dv10[3];
  emxArray_real_T *b_in;
  emxArray_real_T *r38;
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
  nx = V->size[0] * V->size[1];
  V->size[0] = 1;
  V->size[1] = cf->size[1];
  emxEnsureCapacity_real_T(V, nx);
  loop_ub = cf->size[0] * cf->size[1];
  for (nx = 0; nx < loop_ub; nx++) {
    V->data[nx] = 2.0 * cf->data[nx] / sf * 1.5707963267948966;
  }

  nx = V->size[1];
  for (loop_ub = 0; loop_ub < nx; loop_ub++) {
    V->data[loop_ub] = std::tan(V->data[loop_ub]);
  }

  b_V = V->data[0];

  /*  Bilinear transform: */
  re = b_V * -0.70710678118654746;
  im = b_V * 0.70710678118654757;
  Sp[0].re = re;
  Sp[0].im = im;
  x[0].re = 1.0 - re;
  x[0].im = 0.0 - im;
  re = b_V * -0.70710678118654768;
  im = b_V * -0.70710678118654746;
  y_re = x[0].re * (1.0 - re) - x[0].im * (0.0 - im);
  y_im = x[0].re * (0.0 - im) + x[0].im * (1.0 - re);
  d6 = V->data[0];
  loop_ub = V->size[0] * V->size[1] - 1;
  nx = V->size[0] * V->size[1];
  V->size[0] = 1;
  emxEnsureCapacity_real_T(V, nx);
  for (nx = 0; nx <= loop_ub; nx++) {
    b_V = d6 * V->data[nx];
    if (y_im == 0.0) {
      b_V /= y_re;
    } else if (y_re == 0.0) {
      if (b_V == 0.0) {
        b_V = 0.0 / y_im;
      } else {
        b_V = 0.0;
      }
    } else {
      brm = std::abs(y_re);
      bim = std::abs(y_im);
      if (brm > bim) {
        brm = y_im / y_re;
        b_V = (b_V + brm * 0.0) / (y_re + brm * y_im);
      } else if (bim == brm) {
        if (y_re > 0.0) {
          b_y_re = 0.5;
        } else {
          b_y_re = -0.5;
        }

        if (y_im > 0.0) {
          b_y_im = 0.5;
        } else {
          b_y_im = -0.5;
        }

        b_V = (b_V * b_y_re + 0.0 * b_y_im) / brm;
      } else {
        brm = y_re / y_im;
        b_V = brm * b_V / (y_im + brm * y_re);
      }
    }

    V->data[nx] = b_V;
  }

  /*  From Zeros, Poles and Gain to B (numerator) and A (denominator): */
  /*  transpose to adjust for filtfilt? */
  y_re = 1.0 + Sp[0].re;
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
      Sp[0].im = -(y_re / (0.0 - Sp[0].im));
    } else {
      Sp[0].re = Sp[0].im / (0.0 - Sp[0].im);
      Sp[0].im = -(y_re / (0.0 - Sp[0].im));
    }
  } else {
    brm = std::abs(1.0 - Sp[0].re);
    bim = std::abs(0.0 - Sp[0].im);
    if (brm > bim) {
      brm = (0.0 - Sp[0].im) / (1.0 - Sp[0].re);
      bim = (1.0 - Sp[0].re) + brm * (0.0 - Sp[0].im);
      Sp[0].re = ((1.0 + Sp[0].re) + brm * Sp[0].im) / bim;
      Sp[0].im = (Sp[0].im - brm * y_re) / bim;
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
      Sp[0].im = (Sp[0].im * b_V - y_re * bim) / brm;
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
    brm = std::abs(1.0 - re);
    bim = std::abs(0.0 - im);
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

  poly(Sp, dcv1);
  b_V = V->data[0];
  emxFree_real_T(&V);
  c_V[0] = b_V;
  dv10[0] = dcv1[0].re;
  c_V[1] = b_V * 2.0;
  dv10[1] = dcv1[1].re;
  c_V[2] = b_V;
  dv10[2] = dcv1[2].re;
  emxInit_real_T(&b_in, 1);
  nx = b_in->size[0];
  b_in->size[0] = in->size[1];
  emxEnsureCapacity_real_T(b_in, nx);
  loop_ub = in->size[1];
  for (nx = 0; nx < loop_ub; nx++) {
    b_in->data[nx] = in->data[nx];
  }

  emxInit_real_T(&r38, 2);
  myfiltfilt(c_V, dv10, b_in, r38);
  nx = out->size[0] * out->size[1];
  out->size[0] = r38->size[0];
  out->size[1] = r38->size[1];
  emxEnsureCapacity_real_T(out, nx);
  loop_ub = r38->size[0] * r38->size[1];
  emxFree_real_T(&b_in);
  for (nx = 0; nx < loop_ub; nx++) {
    out->data[nx] = r38->data[nx];
  }

  emxFree_real_T(&r38);

  /*  filter */
  /*  if c > r; out = out'; end */
}

void bwfilt(const double in_data[], const int in_size[2], double sf,
            emxArray_real_T *out)
{
  double b[3];
  double a[3];
  emxArray_real_T *t2_d;
  double b_in_data[313];
  int offset;
  int jp;
  emxArray_real_T *r13;
  emxArray_int32_T *t2_colidx;
  emxArray_int32_T *t2_rowidx;
  int c;
  double y_data[36];
  double dv5[4];
  double zi[2];
  double b_y_data[6];
  double as;
  double y_idx_1;
  double reshapes_f3[6];
  double y[18];
  double b_b[3];
  double b_a[3];
  double b_y1[18];
  boolean_T b0;
  boolean_T b1;
  int k;
  int naxpy;
  int j;
  int y_tmp;
  double c_y_data[36];

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
  emxInit_real_T(&t2_d, 1);
  if (in_size[1] > 1) {
    memcpy(&b_in_data[0], &in_data[0], (unsigned int)(in_size[1] * static_cast<
            int>(sizeof(double))));
    offset = t2_d->size[0];
    t2_d->size[0] = in_size[1];
    emxEnsureCapacity_real_T(t2_d, offset);
    jp = in_size[1];
    for (offset = 0; offset < jp; offset++) {
      t2_d->data[offset] = b_in_data[offset];
    }

    emxInit_real_T(&r13, 2);
    myfiltfilt(b, a, t2_d, r13);
    offset = out->size[0] * out->size[1];
    out->size[0] = r13->size[0];
    out->size[1] = r13->size[1];
    emxEnsureCapacity_real_T(out, offset);
    jp = r13->size[0] * r13->size[1];
    for (offset = 0; offset < jp; offset++) {
      out->data[offset] = r13->data[offset];
    }

    emxFree_real_T(&r13);
  } else {
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
    if (in_size[1] == 0) {
      jp = 0;
      c = 0;
    } else {
      emxInit_int32_T(&t2_colidx, 1);
      emxInit_int32_T(&t2_rowidx, 1);

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
      /*  input data too short */
      /*          error(message('signal:filtfilt:InvalidDimensionsDataShortForFiltOrder',num2str(nfact))); */
      /*  Zero pad shorter coefficient vector as needed */
      /*  Compute initial conditions to remove DC offset at beginning and end of */
      /*  filtered sequence.  Use sparse matrix to solve linear system for initial */
      /*  conditions zi, which is the vector of states for the filter b(z)/a(z) in */
      /*  the state-space formulation of the filter. */
      dv5[0] = 1.0 + a[1];
      dv5[1] = a[2];
      dv5[2] = 1.0;
      dv5[3] = -1.0;
      sparse(dv5, t2_d, t2_colidx, t2_rowidx);
      zi[0] = b[1] - b[0] * a[1];
      zi[1] = b[2] - b[0] * a[2];
      sparse_mldivide(t2_d, t2_colidx, t2_rowidx, zi);

      /*  The non-sparse solution to zi may be computed using: */
      /*       zi = ( eye(nfilt-1) - [-a(2:nfilt), [eye(nfilt-2); ... */
      /*                                            zeros(1,nfilt-2)]] ) \ ... */
      /*           ( b(2:nfilt) - b(1)*a(2:nfilt) ); */
      /*  Filter the data */
      b_y_data[0] = in_data[0];

      /* -------------------------------------------------------------------------- */
      emxFree_int32_T(&t2_rowidx);
      emxFree_int32_T(&t2_colidx);

      /*  Single channel, data explicitly concatenated into one vector */
      as = 2.0 * in_data[0];
      y_idx_1 = 2.0 * in_data[0];
      for (offset = 0; offset < 6; offset++) {
        reshapes_f3[offset] = y_idx_1 - b_y_data[-1 - offset];
        y[3 * offset] = as - b_y_data[6 - offset];
      }

      for (offset = 0; offset < 1; offset++) {
        y[1] = b_y_data[0];
      }

      for (offset = 0; offset < 6; offset++) {
        y[2 + 3 * offset] = reshapes_f3[offset];
      }

      /*  filter, reverse data, filter again, and reverse data again */
      as = zi[0] * y[0];
      y_idx_1 = zi[1] * y[0];
      b_b[0] = b[0];
      b_a[0] = a[0];
      b_b[1] = b[1];
      b_a[1] = a[1];
      b_b[2] = b[2];
      b_a[2] = a[2];
      memcpy(&b_y1[0], &y[0], 18U * sizeof(double));
      b0 = rtIsInf(a[0]);
      b1 = rtIsNaN(a[0]);
      if ((!b0) && (!b1) && (!(a[0] == 0.0)) && (a[0] != 1.0)) {
        b_b[0] = b[0] / a[0];
        b_b[1] = b[1] / a[0];
        b_b[2] = b[2] / a[0];
        b_a[1] = a[1] / a[0];
        b_a[2] = a[2] / a[0];
        b_a[0] = 1.0;
      }

      for (c = 0; c < 6; c++) {
        offset = c * 3;
        y[offset] = as;
        y[offset + 1] = y_idx_1;
        y[offset + 2] = 0.0;
      }

      for (c = 0; c < 6; c++) {
        offset = c * 3;
        for (k = 0; k < 3; k++) {
          jp = (offset + k) + 1;
          if (3 - k < 3) {
            naxpy = 2 - k;
          } else {
            naxpy = 2;
          }

          for (j = 0; j <= naxpy; j++) {
            y_tmp = (jp + j) - 1;
            y[y_tmp] += b_y1[jp - 1] * b_b[j];
          }

          if (2 - k < 2) {
            naxpy = 1 - k;
          } else {
            naxpy = 1;
          }

          as = -y[jp - 1];
          for (j = 0; j <= naxpy; j++) {
            y_tmp = jp + j;
            y[y_tmp] += as * b_a[j + 1];
          }
        }
      }

      b_b[0] = b[0];
      b_a[0] = a[0];
      b_b[1] = b[1];
      b_a[1] = a[1];
      b_b[2] = b[2];
      b_a[2] = a[2];
      if ((!b0) && (!b1) && (!(a[0] == 0.0)) && (a[0] != 1.0)) {
        b_b[0] = b[0] / a[0];
        b_b[1] = b[1] / a[0];
        b_b[2] = b[2] / a[0];
        b_a[1] = a[1] / a[0];
        b_a[2] = a[2] / a[0];
        b_a[0] = 1.0;
      }

      b_y1[0] = zi[0] * y[17];
      b_y1[1] = zi[1] * y[17];
      memset(&b_y1[2], 0, sizeof(double) << 4);
      for (k = 0; k < 18; k++) {
        if (18 - k < 3) {
          naxpy = 17 - k;
        } else {
          naxpy = 2;
        }

        for (j = 0; j <= naxpy; j++) {
          jp = k + j;
          b_y1[jp] += y[17 - k] * b_b[j];
        }

        if (17 - k < 2) {
          naxpy = 16 - k;
        } else {
          naxpy = 1;
        }

        as = -b_y1[k];
        for (j = 0; j <= naxpy; j++) {
          jp = (k + j) + 1;
          b_y1[jp] += as * b_a[1 + j];
        }
      }

      /*  retain reversed central section of y */
      for (offset = 0; offset < 6; offset++) {
        b_y_data[offset] = b_y1[11 - offset];
      }

      memcpy(&c_y_data[0], &b_y_data[0], (unsigned int)(6 * static_cast<int>
              (sizeof(double))));
      jp = 6;
      c = 1;
      memcpy(&y_data[0], &c_y_data[0], (unsigned int)(6 * static_cast<int>
              (sizeof(double))));

      /*  convert back to row if necessary */
    }

    offset = out->size[0] * out->size[1];
    out->size[0] = jp;
    out->size[1] = c;
    emxEnsureCapacity_real_T(out, offset);
    jp *= c;
    for (offset = 0; offset < jp; offset++) {
      out->data[offset] = y_data[offset];
    }
  }

  emxFree_real_T(&t2_d);

  /*  filter */
  /*  if c > r; out = out'; end */
}

/* End of code generation (bwfilt.cpp) */

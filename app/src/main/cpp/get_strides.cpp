/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_strides.cpp
 *
 * Code generation for function 'get_strides'
 *
 */

/* Include files */
#include <cmath>
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "get_strides.h"
#include "nullAssignment.h"
#include "calc_fall_risk_emxutil.h"
#include "crossing0.h"
#include "extrema.h"
#include "bwfilt.h"
#include "welch.h"
#include "mean.h"
#include "psdesttype.h"
#include "myfiltfilt.h"
#include "myButter.h"
#include <string.h>

/* Type Definitions */
typedef struct {
  double f1[63];
  double f3;
  double f4;
} cell_52;

/* Function Definitions */
double get_strides(const emxArray_real_T *thigh_acc, double asf)
{
  double stride_vars;
  emxArray_real_T *b_thigh_acc;
  double b[3];
  double a[3];
  int nxin;
  int i79;
  emxArray_real_T *z5_thigh_acc;
  emxArray_real_T *r30;
  int i;
  emxArray_real_T *c_thigh_acc;
  cell_52 inputArgs;
  char esttype_data[5];
  int esttype_size[2];
  double strideTime0;
  emxArray_creal_T *varargout_1;
  static double freq_data[4096];
  int freq_size[1];
  int b_freq_size[1];
  emxArray_creal_T *fpow;
  boolean_T b_freq_data[4096];
  int nStrides;
  emxArray_real_T *ipow;
  emxArray_creal_T *b_fpow;
  emxArray_boolean_T *b_ipow;
  emxArray_creal_T c_fpow;
  int d_fpow[3];
  emxArray_boolean_T *r31;
  emxArray_real_T *freq;
  emxArray_real_T *stpf;
  emxArray_boolean_T *b_freq;
  emxArray_boolean_T *r32;
  emxArray_real_T *strideStart;
  emxArray_real_T *zstp_thigh_acc;
  emxArray_real_T *c_freq;
  emxArray_real_T *zstr_thigh_acc;
  emxArray_real_T *imax_str;
  emxArray_real_T *imax_stp;
  emxArray_real_T *imin_str;
  emxArray_real_T *imin_stp;
  unsigned int b_i;
  int exitg1;
  emxArray_boolean_T *r33;
  emxArray_int32_T *r34;
  emxArray_int32_T *r35;
  emxArray_int32_T *r36;
  emxArray_int32_T *r37;
  emxArray_real_T *strideEnd;
  emxArray_real_T *dutyCycle;
  boolean_T exitg2;
  double dutyCycle0;
  emxInit_real_T(&b_thigh_acc, 1);

  /*  initialize strideTime (for codegen) */
  stride_vars = 0.0;

  /*  stride time constraints based on speed bins */
  /*  duty cycle constraints (outliers from longitudinal subs) */
  /*  longitudinal acc */
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
  myButter(10.0 / asf, b, a);

  /*  transpose to adjust for filtfilt? */
  nxin = thigh_acc->size[1];
  i79 = b_thigh_acc->size[0];
  b_thigh_acc->size[0] = nxin;
  emxEnsureCapacity_real_T(b_thigh_acc, i79);
  for (i79 = 0; i79 < nxin; i79++) {
    b_thigh_acc->data[i79] = thigh_acc->data[2 + 3 * i79];
  }

  emxInit_real_T(&z5_thigh_acc, 2);
  emxInit_real_T(&r30, 2);
  myfiltfilt(b, a, b_thigh_acc, r30);
  i79 = z5_thigh_acc->size[0] * z5_thigh_acc->size[1];
  z5_thigh_acc->size[0] = r30->size[0];
  z5_thigh_acc->size[1] = r30->size[1];
  emxEnsureCapacity_real_T(z5_thigh_acc, i79);
  nxin = r30->size[0] * r30->size[1];
  emxFree_real_T(&b_thigh_acc);
  for (i79 = 0; i79 < nxin; i79++) {
    z5_thigh_acc->data[i79] = r30->data[i79];
  }

  emxFree_real_T(&r30);

  /*  filter */
  /*  if c > r; out = out'; end */
  /*  get power spectral density */
  /*  expecting a peak at step frequency (most dominant for lower */
  /*  frquencies) and a peak below this for stride freq */
  for (i = 0; i < 63; i++) {
    inputArgs.f1[i] = 1.0;
  }

  emxInit_real_T(&c_thigh_acc, 2);
  psdesttype(esttype_data, esttype_size);
  nxin = thigh_acc->size[1];
  i79 = c_thigh_acc->size[0] * c_thigh_acc->size[1];
  c_thigh_acc->size[0] = 1;
  c_thigh_acc->size[1] = nxin;
  emxEnsureCapacity_real_T(c_thigh_acc, i79);
  for (i79 = 0; i79 < nxin; i79++) {
    c_thigh_acc->data[i79] = thigh_acc->data[2 + 3 * i79];
  }

  strideTime0 = mean(c_thigh_acc);
  nxin = thigh_acc->size[1];
  i79 = c_thigh_acc->size[0] * c_thigh_acc->size[1];
  c_thigh_acc->size[0] = 1;
  c_thigh_acc->size[1] = nxin;
  emxEnsureCapacity_real_T(c_thigh_acc, i79);
  for (i79 = 0; i79 < nxin; i79++) {
    c_thigh_acc->data[i79] = thigh_acc->data[2 + 3 * i79] - strideTime0;
  }

  emxInit_creal_T(&varargout_1, 3);
  b_welch(c_thigh_acc, esttype_data, esttype_size, inputArgs.f1, asf,
          varargout_1, freq_data, freq_size);

  /*  window @ 2 seconds */
  /*  remove frequencies < 0.5 Hz and > 4 Hz */
  b_freq_size[0] = freq_size[0];
  nxin = freq_size[0];
  for (i79 = 0; i79 < nxin; i79++) {
    b_freq_data[i79] = ((freq_data[i79] < 0.5) || (freq_data[i79] > 4.0));
  }

  emxInit_creal_T(&fpow, 2);
  nullAssignment(varargout_1, b_freq_data, b_freq_size, fpow);
  nxin = freq_size[0];
  emxFree_creal_T(&varargout_1);
  for (i79 = 0; i79 < nxin; i79++) {
    b_freq_data[i79] = ((freq_data[i79] < 0.5) || (freq_data[i79] > 4.0));
  }

  nxin = freq_size[0];
  i = -1;
  for (nStrides = 0; nStrides < nxin; nStrides++) {
    if ((nStrides + 1 > freq_size[0]) || (!b_freq_data[nStrides])) {
      i++;
      freq_data[i] = freq_data[nStrides];
    }
  }

  emxInit_real_T(&ipow, 2);
  emxInit_creal_T(&b_fpow, 2);
  emxInit_boolean_T(&b_ipow, 2);

  /*  get peaks and remove endpoints */
  nxin = fpow->size[0];
  i = fpow->size[1];
  c_fpow = *fpow;
  d_fpow[0] = nxin;
  d_fpow[1] = i;
  d_fpow[2] = 1;
  c_fpow.size = &d_fpow[0];
  c_fpow.numDimensions = 1;
  extrema(&c_fpow, b_fpow, ipow);
  i79 = b_ipow->size[0] * b_ipow->size[1];
  b_ipow->size[0] = ipow->size[0];
  b_ipow->size[1] = ipow->size[1];
  emxEnsureCapacity_boolean_T(b_ipow, i79);
  nxin = ipow->size[0] * ipow->size[1];
  for (i79 = 0; i79 < nxin; i79++) {
    b_ipow->data[i79] = (ipow->data[i79] == 1.0);
  }

  c_nullAssignment(ipow, b_ipow);
  i = fpow->size[0];
  emxFree_boolean_T(&b_ipow);
  if ((fpow->size[0] > 0) && ((fpow->size[1] == 0) || (fpow->size[1] >
        fpow->size[0]))) {
    i = fpow->size[1];
  }

  emxInit_boolean_T(&r31, 2);
  i79 = r31->size[0] * r31->size[1];
  r31->size[0] = ipow->size[0];
  r31->size[1] = ipow->size[1];
  emxEnsureCapacity_boolean_T(r31, i79);
  nxin = ipow->size[0] * ipow->size[1];
  for (i79 = 0; i79 < nxin; i79++) {
    r31->data[i79] = (ipow->data[i79] == i);
  }

  emxInit_real_T(&freq, 2);
  c_nullAssignment(ipow, r31);

  /*  get peak frequencies and power */
  i79 = freq->size[0] * freq->size[1];
  freq->size[0] = ipow->size[0];
  freq->size[1] = ipow->size[1];
  emxEnsureCapacity_real_T(freq, i79);
  nxin = ipow->size[0] * ipow->size[1];
  for (i79 = 0; i79 < nxin; i79++) {
    freq->data[i79] = freq_data[static_cast<int>(ipow->data[i79]) - 1];
  }

  i79 = b_fpow->size[0] * b_fpow->size[1];
  b_fpow->size[0] = ipow->size[0];
  b_fpow->size[1] = ipow->size[1];
  emxEnsureCapacity_creal_T(b_fpow, i79);
  nxin = ipow->size[0] * ipow->size[1];
  for (i79 = 0; i79 < nxin; i79++) {
    b_fpow->data[i79] = fpow->data[static_cast<int>(ipow->data[i79]) - 1];
  }

  emxFree_creal_T(&fpow);
  emxInit_real_T(&stpf, 2);

  /*  get max frequency (assume step frequency) */
  i79 = stpf->size[0] * stpf->size[1];
  stpf->size[0] = 1;
  stpf->size[1] = b_fpow->size[1];
  emxEnsureCapacity_real_T(stpf, i79);
  nxin = b_fpow->size[1];
  for (i79 = 0; i79 < nxin; i79++) {
    stpf->data[i79] = freq->data[0];
  }

  emxInit_boolean_T(&b_freq, 2);

  /*  remove this frequency and all above it */
  i79 = b_freq->size[0] * b_freq->size[1];
  b_freq->size[0] = freq->size[0];
  b_freq->size[1] = freq->size[1];
  emxEnsureCapacity_boolean_T(b_freq, i79);
  nxin = freq->size[0] * freq->size[1];
  for (i79 = 0; i79 < nxin; i79++) {
    b_freq->data[i79] = (freq->data[i79] >= stpf->data[i79]);
  }

  emxInit_boolean_T(&r32, 2);
  f_nullAssignment(b_fpow, b_freq);
  i79 = r32->size[0] * r32->size[1];
  r32->size[0] = freq->size[0];
  r32->size[1] = freq->size[1];
  emxEnsureCapacity_boolean_T(r32, i79);
  nxin = freq->size[0] * freq->size[1];
  emxFree_boolean_T(&b_freq);
  for (i79 = 0; i79 < nxin; i79++) {
    r32->data[i79] = (freq->data[i79] >= stpf->data[i79]);
  }

  emxInit_real_T(&strideStart, 2);
  g_nullAssignment(freq, r32);

  /*  assume stride frequency is the maximum remaining */
  i79 = strideStart->size[0] * strideStart->size[1];
  strideStart->size[0] = 1;
  strideStart->size[1] = b_fpow->size[1];
  emxEnsureCapacity_real_T(strideStart, i79);
  nxin = b_fpow->size[1];
  emxFree_boolean_T(&r32);
  emxFree_creal_T(&b_fpow);
  for (i79 = 0; i79 < nxin; i79++) {
    strideStart->data[i79] = 1.0;
  }

  /*  low pass at stepf and strf */
  nxin = thigh_acc->size[1];
  i79 = c_thigh_acc->size[0] * c_thigh_acc->size[1];
  c_thigh_acc->size[0] = 1;
  c_thigh_acc->size[1] = nxin;
  emxEnsureCapacity_real_T(c_thigh_acc, i79);
  for (i79 = 0; i79 < nxin; i79++) {
    c_thigh_acc->data[i79] = thigh_acc->data[2 + 3 * i79];
  }

  emxInit_real_T(&zstp_thigh_acc, 2);
  b_bwfilt(c_thigh_acc, stpf, asf, zstp_thigh_acc);
  nxin = thigh_acc->size[1];
  i79 = c_thigh_acc->size[0] * c_thigh_acc->size[1];
  c_thigh_acc->size[0] = 1;
  c_thigh_acc->size[1] = nxin;
  emxEnsureCapacity_real_T(c_thigh_acc, i79);
  for (i79 = 0; i79 < nxin; i79++) {
    c_thigh_acc->data[i79] = thigh_acc->data[2 + 3 * i79];
  }

  emxInit_real_T(&c_freq, 2);
  i79 = c_freq->size[0] * c_freq->size[1];
  c_freq->size[0] = 1;
  c_freq->size[1] = strideStart->size[1];
  emxEnsureCapacity_real_T(c_freq, i79);
  nxin = strideStart->size[0] * strideStart->size[1];
  for (i79 = 0; i79 < nxin; i79++) {
    c_freq->data[i79] = freq->data[static_cast<int>(strideStart->data[i79]) - 1];
  }

  emxInit_real_T(&zstr_thigh_acc, 2);
  emxInit_real_T(&imax_str, 2);
  emxInit_real_T(&imax_stp, 2);
  emxInit_real_T(&imin_str, 2);
  emxInit_real_T(&imin_stp, 2);
  b_bwfilt(c_thigh_acc, c_freq, asf, zstr_thigh_acc);

  /*  get minima/maxima of stride/step filtered sig */
  d_extrema(zstr_thigh_acc, ipow, imax_str, freq, imin_str);
  d_extrema(zstp_thigh_acc, ipow, imax_stp, freq, imin_stp);
  e_extrema(z5_thigh_acc, ipow, imax_str);

  /*  remove endpoints */
  i79 = r31->size[0] * r31->size[1];
  r31->size[0] = imin_str->size[0];
  r31->size[1] = imin_str->size[1];
  emxEnsureCapacity_boolean_T(r31, i79);
  nxin = imin_str->size[0] * imin_str->size[1];
  emxFree_real_T(&c_freq);
  emxFree_real_T(&c_thigh_acc);
  emxFree_real_T(&freq);
  emxFree_real_T(&ipow);
  for (i79 = 0; i79 < nxin; i79++) {
    r31->data[i79] = (imin_str->data[i79] == 1.0);
  }

  c_nullAssignment(imin_str, r31);
  i79 = r31->size[0] * r31->size[1];
  r31->size[0] = imax_stp->size[0];
  r31->size[1] = imax_stp->size[1];
  emxEnsureCapacity_boolean_T(r31, i79);
  nxin = imax_stp->size[0] * imax_stp->size[1];
  for (i79 = 0; i79 < nxin; i79++) {
    r31->data[i79] = (imax_stp->data[i79] == 1.0);
  }

  c_nullAssignment(imax_stp, r31);
  i79 = r31->size[0] * r31->size[1];
  r31->size[0] = imin_stp->size[0];
  r31->size[1] = imin_stp->size[1];
  emxEnsureCapacity_boolean_T(r31, i79);
  nxin = imin_stp->size[0] * imin_stp->size[1];
  for (i79 = 0; i79 < nxin; i79++) {
    r31->data[i79] = (imin_stp->data[i79] == 1.0);
  }

  c_nullAssignment(imin_stp, r31);
  nxin = zstr_thigh_acc->size[0];
  if (nxin <= 1) {
    nxin = 1;
  }

  if (zstr_thigh_acc->size[0] == 0) {
    i = 0;
  } else {
    i = nxin;
  }

  i79 = r31->size[0] * r31->size[1];
  r31->size[0] = imin_str->size[0];
  r31->size[1] = imin_str->size[1];
  emxEnsureCapacity_boolean_T(r31, i79);
  nxin = imin_str->size[0] * imin_str->size[1];
  for (i79 = 0; i79 < nxin; i79++) {
    r31->data[i79] = (imin_str->data[i79] == i);
  }

  c_nullAssignment(imin_str, r31);
  nxin = zstr_thigh_acc->size[0];
  if (nxin <= 1) {
    nxin = 1;
  }

  if (zstr_thigh_acc->size[0] == 0) {
    i = 0;
  } else {
    i = nxin;
  }

  i79 = r31->size[0] * r31->size[1];
  r31->size[0] = imax_stp->size[0];
  r31->size[1] = imax_stp->size[1];
  emxEnsureCapacity_boolean_T(r31, i79);
  nxin = imax_stp->size[0] * imax_stp->size[1];
  for (i79 = 0; i79 < nxin; i79++) {
    r31->data[i79] = (imax_stp->data[i79] == i);
  }

  c_nullAssignment(imax_stp, r31);
  nxin = zstr_thigh_acc->size[0];
  if (nxin <= 1) {
    nxin = 1;
  }

  if (zstr_thigh_acc->size[0] == 0) {
    i = 0;
  } else {
    i = nxin;
  }

  i79 = r31->size[0] * r31->size[1];
  r31->size[0] = imin_stp->size[0];
  r31->size[1] = imin_stp->size[1];
  emxEnsureCapacity_boolean_T(r31, i79);
  nxin = imin_stp->size[0] * imin_stp->size[1];
  for (i79 = 0; i79 < nxin; i79++) {
    r31->data[i79] = (imin_stp->data[i79] == i);
  }

  c_nullAssignment(imin_stp, r31);
  i79 = r31->size[0] * r31->size[1];
  r31->size[0] = imax_str->size[0];
  r31->size[1] = imax_str->size[1];
  emxEnsureCapacity_boolean_T(r31, i79);
  nxin = imax_str->size[0] * imax_str->size[1];
  for (i79 = 0; i79 < nxin; i79++) {
    r31->data[i79] = (imax_str->data[i79] == 1.0);
  }

  c_nullAssignment(imax_str, r31);
  nxin = zstr_thigh_acc->size[0];
  if (nxin <= 1) {
    nxin = 1;
  }

  if (zstr_thigh_acc->size[0] == 0) {
    i = 0;
  } else {
    i = nxin;
  }

  i79 = r31->size[0] * r31->size[1];
  r31->size[0] = imax_str->size[0];
  r31->size[1] = imax_str->size[1];
  emxEnsureCapacity_boolean_T(r31, i79);
  nxin = imax_str->size[0] * imax_str->size[1];
  for (i79 = 0; i79 < nxin; i79++) {
    r31->data[i79] = (imax_str->data[i79] == i);
  }

  c_nullAssignment(imax_str, r31);

  /*  get instants where z low passed at 5 crosses 1 g */
  i79 = zstr_thigh_acc->size[0] * zstr_thigh_acc->size[1];
  zstr_thigh_acc->size[0] = z5_thigh_acc->size[0];
  zstr_thigh_acc->size[1] = 1;
  emxEnsureCapacity_real_T(zstr_thigh_acc, i79);
  nxin = z5_thigh_acc->size[0] * z5_thigh_acc->size[1];
  for (i79 = 0; i79 < nxin; i79++) {
    zstr_thigh_acc->data[i79] = z5_thigh_acc->data[i79] - 1.0;
  }

  emxFree_real_T(&z5_thigh_acc);
  crossing0(zstr_thigh_acc);

  /*  sometimes false minima identified within stride */
  /*  require minima be within min and max stride times */
  b_i = 1U;
  emxFree_real_T(&zstr_thigh_acc);
  do {
    exitg1 = 0;
    if ((imin_str->size[0] == 0) || (imin_str->size[1] == 0)) {
      i = 0;
    } else {
      i = imin_str->size[1];
    }

    if (static_cast<int>(b_i) <= i - 1) {
      i79 = static_cast<int>(b_i) - 1;
      if ((imin_str->data[static_cast<int>(b_i)] - imin_str->data[i79] < std::
           floor(0.5 * asf)) || (imin_str->data[static_cast<int>(b_i)] -
           imin_str->data[i79] > std::ceil(1.6 * asf))) {
        h_nullAssignment(imin_str, static_cast<int>(b_i) + 1);
      } else {
        b_i = static_cast<unsigned int>((static_cast<int>(b_i) + 1));
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  /*  get stride peaks (max acc during stride) = swing start */
  /*  get one following valley for each stride peak ~ FC */
  /*  for each minima */
  if ((imin_str->size[0] == 0) || (imin_str->size[1] == 0)) {
    i = -1;
  } else {
    i = imin_str->size[1] - 1;
  }

  i79 = stpf->size[0] * stpf->size[1];
  stpf->size[0] = 1;
  stpf->size[1] = i;
  emxEnsureCapacity_real_T(stpf, i79);
  for (i79 = 0; i79 < i; i79++) {
    stpf->data[i79] = 0.0;
  }

  if ((imin_str->size[0] == 0) || (imin_str->size[1] == 0)) {
    i = -1;
  } else {
    i = imin_str->size[1] - 1;
  }

  i79 = strideStart->size[0] * strideStart->size[1];
  strideStart->size[0] = 1;
  strideStart->size[1] = i;
  emxEnsureCapacity_real_T(strideStart, i79);
  for (i79 = 0; i79 < i; i79++) {
    strideStart->data[i79] = 0.0;
  }

  emxInit_boolean_T(&r33, 2);
  emxInit_int32_T(&r34, 1);
  emxInit_int32_T(&r35, 1);
  emxInit_int32_T(&r36, 1);
  emxInit_int32_T(&r37, 1);
  do {
    exitg1 = 0;
    if ((imin_str->size[0] == 0) || (imin_str->size[1] == 0)) {
      i = 0;
    } else {
      i = imin_str->size[1];
    }

    if (1 <= i - 1) {
      /*  get latest zstp peak between current and next str minima */
      i79 = r31->size[0] * r31->size[1];
      r31->size[0] = imax_stp->size[0];
      r31->size[1] = imax_stp->size[1];
      emxEnsureCapacity_boolean_T(r31, i79);
      strideTime0 = imin_str->data[0];
      nxin = imax_stp->size[0] * imax_stp->size[1];
      for (i79 = 0; i79 < nxin; i79++) {
        r31->data[i79] = (imax_stp->data[i79] > strideTime0);
      }

      i79 = r33->size[0] * r33->size[1];
      r33->size[0] = imax_stp->size[0];
      r33->size[1] = imax_stp->size[1];
      emxEnsureCapacity_boolean_T(r33, i79);
      strideTime0 = imin_str->data[1];
      nxin = imax_stp->size[0] * imax_stp->size[1];
      for (i79 = 0; i79 < nxin; i79++) {
        r33->data[i79] = (imax_stp->data[i79] < strideTime0);
      }

      nStrides = r31->size[0] * r31->size[1] - 1;
      nxin = 0;
      for (i = 0; i <= nStrides; i++) {
        if (r31->data[i] && r33->data[i]) {
          nxin++;
        }
      }

      i79 = r34->size[0];
      r34->size[0] = nxin;
      emxEnsureCapacity_int32_T(r34, i79);
      nxin = 0;
      for (i = 0; i <= nStrides; i++) {
        if (r31->data[i] && r33->data[i]) {
          r34->data[nxin] = i + 1;
          nxin++;
        }
      }

      i = r34->size[0];
      if (r34->size[0] <= 2) {
        if (r34->size[0] == 1) {
          strideTime0 = imax_stp->data[r34->data[0] - 1];
        } else if ((imax_stp->data[r34->data[0] - 1] < imax_stp->data[r34->data
                    [1] - 1]) || (rtIsNaN(imax_stp->data[r34->data[0] - 1]) && (
                     !rtIsNaN(imax_stp->data[r34->data[1] - 1])))) {
          strideTime0 = imax_stp->data[r34->data[1] - 1];
        } else {
          strideTime0 = imax_stp->data[r34->data[0] - 1];
        }
      } else {
        if (!rtIsNaN(imax_stp->data[r34->data[0] - 1])) {
          nxin = 1;
        } else {
          nxin = 0;
          nStrides = 2;
          exitg2 = false;
          while ((!exitg2) && (nStrides <= r34->size[0])) {
            if (!rtIsNaN(imax_stp->data[r34->data[nStrides - 1] - 1])) {
              nxin = nStrides;
              exitg2 = true;
            } else {
              nStrides++;
            }
          }
        }

        if (nxin == 0) {
          strideTime0 = imax_stp->data[r34->data[0] - 1];
        } else {
          strideTime0 = imax_stp->data[r34->data[nxin - 1] - 1];
          i79 = nxin + 1;
          for (nStrides = i79; nStrides <= i; nStrides++) {
            if (strideTime0 < imax_stp->data[r34->data[nStrides - 1] - 1]) {
              strideTime0 = imax_stp->data[r34->data[nStrides - 1] - 1];
            }
          }
        }
      }

      /*  if empty then delete */
      /*  check for peak in z5 within last 5 samp */
      i79 = r31->size[0] * r31->size[1];
      r31->size[0] = imax_str->size[0];
      r31->size[1] = imax_str->size[1];
      emxEnsureCapacity_boolean_T(r31, i79);
      nxin = imax_str->size[0] * imax_str->size[1];
      for (i79 = 0; i79 < nxin; i79++) {
        r31->data[i79] = (imax_str->data[i79] > strideTime0 - 5.0);
      }

      i79 = r33->size[0] * r33->size[1];
      r33->size[0] = imax_str->size[0];
      r33->size[1] = imax_str->size[1];
      emxEnsureCapacity_boolean_T(r33, i79);
      nxin = imax_str->size[0] * imax_str->size[1];
      for (i79 = 0; i79 < nxin; i79++) {
        r33->data[i79] = (imax_str->data[i79] < strideTime0);
      }

      nStrides = r31->size[0] * r31->size[1] - 1;
      nxin = 0;
      for (i = 0; i <= nStrides; i++) {
        if (r31->data[i] && r33->data[i]) {
          nxin++;
        }
      }

      i79 = r35->size[0];
      r35->size[0] = nxin;
      emxEnsureCapacity_int32_T(r35, i79);
      nxin = 0;
      for (i = 0; i <= nStrides; i++) {
        if (r31->data[i] && r33->data[i]) {
          r35->data[nxin] = i + 1;
          nxin++;
        }
      }

      if (r35->size[0] == 0) {
        stpf->data[0] = strideTime0 - 1.0;
      } else {
        nStrides = r31->size[0] * r31->size[1] - 1;
        nxin = 0;
        for (i = 0; i <= nStrides; i++) {
          if (r31->data[i] && r33->data[i]) {
            nxin++;
          }
        }

        i79 = r36->size[0];
        r36->size[0] = nxin;
        emxEnsureCapacity_int32_T(r36, i79);
        nxin = 0;
        for (i = 0; i <= nStrides; i++) {
          if (r31->data[i] && r33->data[i]) {
            r36->data[nxin] = i + 1;
            nxin++;
          }
        }

        stpf->data[0] = imax_str->data[r36->data[r36->size[0] - 1] - 1];
      }

      /*  get next valley */
      i79 = r31->size[0] * r31->size[1];
      r31->size[0] = imin_stp->size[0];
      r31->size[1] = imin_stp->size[1];
      emxEnsureCapacity_boolean_T(r31, i79);
      strideTime0 = stpf->data[0];
      nxin = imin_stp->size[0] * imin_stp->size[1];
      for (i79 = 0; i79 < nxin; i79++) {
        r31->data[i79] = (strideTime0 < imin_stp->data[i79]);
      }

      nStrides = r31->size[0] * r31->size[1] - 1;
      nxin = 0;
      for (i = 0; i <= nStrides; i++) {
        if (r31->data[i]) {
          nxin++;
        }
      }

      i79 = r37->size[0];
      r37->size[0] = nxin;
      emxEnsureCapacity_int32_T(r37, i79);
      nxin = 0;
      for (i = 0; i <= nStrides; i++) {
        if (r31->data[i]) {
          r37->data[nxin] = i + 1;
          nxin++;
        }
      }

      /*  if is empty then delete */
      if ((r37->size[0] != 0) && (!(zstp_thigh_acc->data[static_cast<int>
            (imin_stp->data[r37->data[0] - 1]) - 1] >= 1.0))) {
        /*  otherwise save */
        strideStart->data[0] = imin_stp->data[r37->data[0] - 1];

        /*  get next instant where z5 crossed 1g */
        /*  if none then delete */
      } else {
        /*  also require this valley be less than 1g */
      }

      i_nullAssignment(stpf, 1);
      i_nullAssignment(strideStart, 1);
      h_nullAssignment(imin_str, 1);
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  emxFree_boolean_T(&r31);
  emxFree_int32_T(&r37);
  emxFree_int32_T(&r36);
  emxFree_int32_T(&r35);
  emxFree_int32_T(&r34);
  emxFree_boolean_T(&r33);
  emxFree_real_T(&imin_stp);
  emxFree_real_T(&imin_str);
  emxFree_real_T(&imax_stp);
  emxFree_real_T(&imax_str);
  emxFree_real_T(&zstp_thigh_acc);

  /*  if none */
  if (strideStart->size[1] != 0) {
    emxInit_real_T(&strideEnd, 2);

    /*  stride ends are stride starts without first */
    i79 = strideEnd->size[0] * strideEnd->size[1];
    strideEnd->size[0] = 1;
    strideEnd->size[1] = strideStart->size[1];
    emxEnsureCapacity_real_T(strideEnd, i79);
    nxin = strideStart->size[0] * strideStart->size[1];
    for (i79 = 0; i79 < nxin; i79++) {
      strideEnd->data[i79] = strideStart->data[i79];
    }

    emxInit_real_T(&dutyCycle, 2);
    i79 = strideStart->size[1];
    i_nullAssignment(strideStart, i79);
    j_nullAssignment(strideEnd);

    /*  FC before first swing start not identified, delete */
    j_nullAssignment(stpf);

    /*  get stride endpoints and check times */
    nStrides = strideStart->size[1];

    /*   */
    /*      for l = 1:nStrides */
    /*          strideTime(1,l)=0; */
    /*      end */
    /*  %     strideTime = zeros(1,nStrides); */
    i79 = dutyCycle->size[0] * dutyCycle->size[1];
    dutyCycle->size[0] = 1;
    dutyCycle->size[1] = strideStart->size[1];
    emxEnsureCapacity_real_T(dutyCycle, i79);
    nxin = strideStart->size[1];
    for (i79 = 0; i79 < nxin; i79++) {
      dutyCycle->data[i79] = 0.0;
    }

    b_i = 1U;
    while (static_cast<double>(b_i) <= nStrides) {
      /*  get stride time */
      nxin = 0;
      i = static_cast<int>(b_i) - 1;
      strideTime0 = (strideEnd->data[i] - strideStart->data[i]) / asf;

      /*  get duty cycle */
      dutyCycle0 = (stpf->data[i] - strideStart->data[i]) / asf / strideTime0;

      /*  check limits */
      if ((strideTime0 > 1.6) || (strideTime0 < 0.5)) {
        nxin = 1;
      } else {
        if ((dutyCycle0 > 0.73) || (dutyCycle0 < 0.35)) {
          nxin = 1;
        }
      }

      /*  if didn't meet critieria */
      if (nxin != 0) {
        /*  delete stride */
        i_nullAssignment(strideEnd, (int)b_i);
        i_nullAssignment(strideStart, (int)b_i);
        i_nullAssignment(stpf, (int)b_i);

        /* strideTime(i) = []; */
        i_nullAssignment(dutyCycle, (int)b_i);
        nStrides--;

        /*  otherwise save */
      } else {
        stride_vars = strideTime0;
        dutyCycle->data[i] = dutyCycle0;
        b_i++;
      }
    }

    emxFree_real_T(&dutyCycle);
    emxFree_real_T(&strideEnd);
  }

  emxFree_real_T(&strideStart);
  emxFree_real_T(&stpf);

  /*  Compute stride vars */
  /*  figure;  */
  /*  hold on; */
  /*  plot(z.thigh_acc,'color',[0.6,0.6,0.6]); */
  /*  plot(strideStart,zstp.thigh_acc(strideStart),'o','color','g'); */
  /*  plot(strideEnd,zstp.thigh_acc(strideEnd),'o','color','r'); */
  /*  plot(swingStart,zstp.thigh_acc(swingStart),'o','color',[.6,.6,.6]); */
  /*  plot(zstp.thigh_acc,'b'); */
  return stride_vars;
}

/* End of code generation (get_strides.cpp) */

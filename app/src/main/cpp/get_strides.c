/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_strides.c
 *
 * Code generation for function 'get_strides'
 *
 */

/* Include files */
#include <math.h>
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
#include "mean.h"
#include "crossing0.h"
#include "extrema.h"
#include "bwfilt.h"
#include "pwelch.h"
#include "myfiltfilt.h"
#include "myButter.h"
#include <string.h>

/* Function Definitions */
double get_strides(const double thigh_acc[1500], double asf)
{
  double stride_vars;
  emxArray_real_T *strideTime;
  int i35;
  double b[3];
  double a[3];
  double z5_thigh_acc[500];
  double strideTime0;
  double b_thigh_acc[500];
  emxArray_creal_T *fpow;
  static double freq_data[4096];
  int freq_size[1];
  int b_freq_size[1];
  int loop_ub;
  emxArray_creal_T *b_fpow;
  boolean_T b_freq_data[4096];
  emxArray_real_T *ipow;
  emxArray_creal_T *c_fpow;
  emxArray_boolean_T *b_ipow;
  int deleteStride;
  int nStrides;
  emxArray_creal_T d_fpow;
  int e_fpow[3];
  emxArray_boolean_T *r9;
  emxArray_real_T *freq;
  emxArray_real_T *stpf;
  emxArray_boolean_T *b_freq;
  emxArray_boolean_T *r10;
  emxArray_int8_T *indx;
  double zstp_thigh_acc[500];
  emxArray_real_T *imax_str;
  emxArray_real_T *imax_stp;
  emxArray_real_T *imin_str;
  emxArray_real_T *imin_stp;
  emxArray_real_T *unusedU3;
  emxArray_real_T *unusedU4;
  double zstr_thigh_acc[500];
  int imin_str_size[2];
  emxArray_boolean_T imin_str_data;
  boolean_T b_imin_str_data[12285];
  emxArray_boolean_T c_imin_str_data;
  emxArray_boolean_T d_imin_str_data;
  emxArray_boolean_T e_imin_str_data;
  emxArray_boolean_T f_imin_str_data;
  emxArray_boolean_T g_imin_str_data;
  emxArray_boolean_T h_imin_str_data;
  emxArray_boolean_T i_imin_str_data;
  int i;
  int exitg1;
  emxArray_real_T *swingStart;
  emxArray_real_T *strideStart;
  emxArray_real_T *varargin_1;
  boolean_T tmp_data[12285];
  emxArray_real_T *strideEnd;
  boolean_T b_tmp_data[12285];
  int trueCount;
  short c_tmp_data[12285];
  boolean_T exitg2;
  emxArray_real_T *dutyCycle;
  emxArray_real_T *r11;
  double dutyCycle0;
  short d_tmp_data[12285];
  short e_tmp_data[12285];
  emxInit_real_T(&strideTime, 2);

  /* strideTime "variable is not fully defined on some execution paths", */
  /* therefore define it zero here in case --> for matlab coder */
  i35 = strideTime->size[0] * strideTime->size[1];
  strideTime->size[0] = 1;
  strideTime->size[1] = 1;
  emxEnsureCapacity_real_T(strideTime, i35);
  strideTime->data[0] = 0.0;

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
  for (i35 = 0; i35 < 500; i35++) {
    z5_thigh_acc[i35] = thigh_acc[2 + 3 * i35];
  }

  myfiltfilt(b, a, z5_thigh_acc);

  /*  filter */
  /*  if c > r; out = out'; end */
  /*  get power spectral density */
  /*  expecting a peak at step frequency (most dominant for lower */
  /*  frquencies) and a peak below this for stride freq */
  for (i35 = 0; i35 < 500; i35++) {
    b_thigh_acc[i35] = thigh_acc[2 + 3 * i35];
  }

  strideTime0 = c_mean(b_thigh_acc);
  for (i35 = 0; i35 < 500; i35++) {
    b_thigh_acc[i35] = thigh_acc[2 + 3 * i35] - strideTime0;
  }

  emxInit_creal_T(&fpow, 3);
  c_pwelch(b_thigh_acc, asf, fpow, freq_data, freq_size);

  /*  window @ 2 seconds */
  /*  remove frequencies < 0.5 Hz and > 4 Hz */
  b_freq_size[0] = freq_size[0];
  loop_ub = freq_size[0];
  for (i35 = 0; i35 < loop_ub; i35++) {
    b_freq_data[i35] = ((freq_data[i35] < 0.5) || (freq_data[i35] > 4.0));
  }

  emxInit_creal_T(&b_fpow, 2);
  nullAssignment(fpow, b_freq_data, b_freq_size, b_fpow);
  b_freq_size[0] = freq_size[0];
  loop_ub = freq_size[0];
  emxFree_creal_T(&fpow);
  for (i35 = 0; i35 < loop_ub; i35++) {
    b_freq_data[i35] = ((freq_data[i35] < 0.5) || (freq_data[i35] > 4.0));
  }

  emxInit_real_T(&ipow, 2);
  emxInit_creal_T(&c_fpow, 2);
  emxInit_boolean_T(&b_ipow, 2);
  e_nullAssignment(freq_data, freq_size, b_freq_data, b_freq_size);

  /*  get peaks and remove endpoints */
  deleteStride = b_fpow->size[0];
  nStrides = b_fpow->size[1];
  d_fpow = *b_fpow;
  e_fpow[0] = deleteStride;
  e_fpow[1] = nStrides;
  e_fpow[2] = 1;
  d_fpow.size = &e_fpow[0];
  d_fpow.numDimensions = 1;
  extrema(&d_fpow, c_fpow, ipow);
  i35 = b_ipow->size[0] * b_ipow->size[1];
  b_ipow->size[0] = ipow->size[0];
  b_ipow->size[1] = ipow->size[1];
  emxEnsureCapacity_boolean_T(b_ipow, i35);
  loop_ub = ipow->size[0] * ipow->size[1];
  for (i35 = 0; i35 < loop_ub; i35++) {
    b_ipow->data[i35] = (ipow->data[i35] == 1.0);
  }

  c_nullAssignment(ipow, b_ipow);
  deleteStride = b_fpow->size[0];
  emxFree_boolean_T(&b_ipow);
  if ((b_fpow->size[0] > 0) && ((b_fpow->size[1] == 0) || (b_fpow->size[1] >
        b_fpow->size[0]))) {
    deleteStride = b_fpow->size[1];
  }

  emxInit_boolean_T(&r9, 2);
  i35 = r9->size[0] * r9->size[1];
  r9->size[0] = ipow->size[0];
  r9->size[1] = ipow->size[1];
  emxEnsureCapacity_boolean_T(r9, i35);
  loop_ub = ipow->size[0] * ipow->size[1];
  for (i35 = 0; i35 < loop_ub; i35++) {
    r9->data[i35] = (ipow->data[i35] == deleteStride);
  }

  emxInit_real_T(&freq, 2);
  c_nullAssignment(ipow, r9);

  /*  get peak frequencies and power */
  i35 = freq->size[0] * freq->size[1];
  freq->size[0] = ipow->size[0];
  freq->size[1] = ipow->size[1];
  emxEnsureCapacity_real_T(freq, i35);
  loop_ub = ipow->size[0] * ipow->size[1];
  emxFree_boolean_T(&r9);
  for (i35 = 0; i35 < loop_ub; i35++) {
    freq->data[i35] = freq_data[(int)ipow->data[i35] - 1];
  }

  i35 = c_fpow->size[0] * c_fpow->size[1];
  c_fpow->size[0] = ipow->size[0];
  c_fpow->size[1] = ipow->size[1];
  emxEnsureCapacity_creal_T(c_fpow, i35);
  loop_ub = ipow->size[0] * ipow->size[1];
  for (i35 = 0; i35 < loop_ub; i35++) {
    c_fpow->data[i35] = b_fpow->data[(int)ipow->data[i35] - 1];
  }

  emxFree_creal_T(&b_fpow);
  emxInit_real_T(&stpf, 2);

  /*  get max frequency (assume step frequency) */
  i35 = stpf->size[0] * stpf->size[1];
  stpf->size[0] = 1;
  stpf->size[1] = c_fpow->size[1];
  emxEnsureCapacity_real_T(stpf, i35);
  loop_ub = c_fpow->size[1];
  for (i35 = 0; i35 < loop_ub; i35++) {
    stpf->data[i35] = freq->data[0];
  }

  emxInit_boolean_T(&b_freq, 2);

  /*  remove this frequency and all above it */
  i35 = b_freq->size[0] * b_freq->size[1];
  b_freq->size[0] = freq->size[0];
  b_freq->size[1] = freq->size[1];
  emxEnsureCapacity_boolean_T(b_freq, i35);
  loop_ub = freq->size[0] * freq->size[1];
  for (i35 = 0; i35 < loop_ub; i35++) {
    b_freq->data[i35] = (freq->data[i35] >= stpf->data[i35]);
  }

  emxInit_boolean_T(&r10, 2);
  f_nullAssignment(c_fpow, b_freq);
  i35 = r10->size[0] * r10->size[1];
  r10->size[0] = freq->size[0];
  r10->size[1] = freq->size[1];
  emxEnsureCapacity_boolean_T(r10, i35);
  loop_ub = freq->size[0] * freq->size[1];
  emxFree_boolean_T(&b_freq);
  for (i35 = 0; i35 < loop_ub; i35++) {
    r10->data[i35] = (freq->data[i35] >= stpf->data[i35]);
  }

  emxInit_int8_T(&indx, 2);
  g_nullAssignment(freq, r10);

  /*  assume stride frequency is the maximum remaining */
  i35 = indx->size[0] * indx->size[1];
  indx->size[0] = 1;
  indx->size[1] = c_fpow->size[1];
  emxEnsureCapacity_int8_T(indx, i35);
  loop_ub = c_fpow->size[1];
  emxFree_boolean_T(&r10);
  emxFree_creal_T(&c_fpow);
  for (i35 = 0; i35 < loop_ub; i35++) {
    indx->data[i35] = 1;
  }

  /*  low pass at stepf and strf */
  for (i35 = 0; i35 < 500; i35++) {
    b_thigh_acc[i35] = thigh_acc[2 + 3 * i35];
  }

  b_bwfilt(b_thigh_acc, stpf, asf, zstp_thigh_acc);
  for (i35 = 0; i35 < 500; i35++) {
    b_thigh_acc[i35] = thigh_acc[2 + 3 * i35];
  }

  i35 = stpf->size[0] * stpf->size[1];
  stpf->size[0] = 1;
  stpf->size[1] = indx->size[1];
  emxEnsureCapacity_real_T(stpf, i35);
  loop_ub = indx->size[0] * indx->size[1];
  for (i35 = 0; i35 < loop_ub; i35++) {
    stpf->data[i35] = freq->data[indx->data[i35] - 1];
  }

  emxFree_int8_T(&indx);
  emxFree_real_T(&freq);
  emxInit_real_T(&imax_str, 2);
  emxInit_real_T(&imax_stp, 2);
  emxInit_real_T(&imin_str, 2);
  emxInit_real_T(&imin_stp, 2);
  emxInit_real_T(&unusedU3, 2);
  emxInit_real_T(&unusedU4, 2);
  b_bwfilt(b_thigh_acc, stpf, asf, zstr_thigh_acc);

  /*  get minima/maxima of stride/step filtered sig */
  /* clear imax; */
  d_extrema(zstr_thigh_acc, unusedU3, imax_str, unusedU4, imin_str);
  d_extrema(zstp_thigh_acc, unusedU3, imax_stp, unusedU4, imin_stp);
  e_extrema(z5_thigh_acc, unusedU3, imax_str);

  /*  remove endpoints */
  i35 = ipow->size[0] * ipow->size[1];
  ipow->size[0] = imin_str->size[0];
  ipow->size[1] = imin_str->size[1];
  emxEnsureCapacity_real_T(ipow, i35);
  loop_ub = imin_str->size[0] * imin_str->size[1];
  emxFree_real_T(&unusedU4);
  emxFree_real_T(&unusedU3);
  emxFree_real_T(&stpf);
  for (i35 = 0; i35 < loop_ub; i35++) {
    ipow->data[i35] = imin_str->data[i35];
  }

  imin_str_size[0] = imin_str->size[0];
  imin_str_size[1] = imin_str->size[1];
  loop_ub = imin_str->size[0] * imin_str->size[1];
  for (i35 = 0; i35 < loop_ub; i35++) {
    b_imin_str_data[i35] = (imin_str->data[i35] == 1.0);
  }

  imin_str_data.data = &b_imin_str_data[0];
  imin_str_data.size = &imin_str_size[0];
  imin_str_data.allocatedSize = 12285;
  imin_str_data.numDimensions = 2;
  imin_str_data.canFreeData = false;
  c_nullAssignment(ipow, &imin_str_data);
  i35 = imin_str->size[0] * imin_str->size[1];
  imin_str->size[0] = ipow->size[0];
  imin_str->size[1] = ipow->size[1];
  emxEnsureCapacity_real_T(imin_str, i35);
  loop_ub = ipow->size[0] * ipow->size[1];
  for (i35 = 0; i35 < loop_ub; i35++) {
    imin_str->data[i35] = ipow->data[i35];
  }

  i35 = ipow->size[0] * ipow->size[1];
  ipow->size[0] = imax_stp->size[0];
  ipow->size[1] = imax_stp->size[1];
  emxEnsureCapacity_real_T(ipow, i35);
  loop_ub = imax_stp->size[0] * imax_stp->size[1];
  for (i35 = 0; i35 < loop_ub; i35++) {
    ipow->data[i35] = imax_stp->data[i35];
  }

  imin_str_size[0] = imax_stp->size[0];
  imin_str_size[1] = imax_stp->size[1];
  loop_ub = imax_stp->size[0] * imax_stp->size[1];
  for (i35 = 0; i35 < loop_ub; i35++) {
    b_imin_str_data[i35] = (imax_stp->data[i35] == 1.0);
  }

  c_imin_str_data.data = &b_imin_str_data[0];
  c_imin_str_data.size = &imin_str_size[0];
  c_imin_str_data.allocatedSize = 12285;
  c_imin_str_data.numDimensions = 2;
  c_imin_str_data.canFreeData = false;
  c_nullAssignment(ipow, &c_imin_str_data);
  i35 = imax_stp->size[0] * imax_stp->size[1];
  imax_stp->size[0] = ipow->size[0];
  imax_stp->size[1] = ipow->size[1];
  emxEnsureCapacity_real_T(imax_stp, i35);
  loop_ub = ipow->size[0] * ipow->size[1];
  for (i35 = 0; i35 < loop_ub; i35++) {
    imax_stp->data[i35] = ipow->data[i35];
  }

  i35 = ipow->size[0] * ipow->size[1];
  ipow->size[0] = imin_stp->size[0];
  ipow->size[1] = imin_stp->size[1];
  emxEnsureCapacity_real_T(ipow, i35);
  loop_ub = imin_stp->size[0] * imin_stp->size[1];
  for (i35 = 0; i35 < loop_ub; i35++) {
    ipow->data[i35] = imin_stp->data[i35];
  }

  imin_str_size[0] = imin_stp->size[0];
  imin_str_size[1] = imin_stp->size[1];
  loop_ub = imin_stp->size[0] * imin_stp->size[1];
  for (i35 = 0; i35 < loop_ub; i35++) {
    b_imin_str_data[i35] = (imin_stp->data[i35] == 1.0);
  }

  d_imin_str_data.data = &b_imin_str_data[0];
  d_imin_str_data.size = &imin_str_size[0];
  d_imin_str_data.allocatedSize = 12285;
  d_imin_str_data.numDimensions = 2;
  d_imin_str_data.canFreeData = false;
  c_nullAssignment(ipow, &d_imin_str_data);
  i35 = imin_stp->size[0] * imin_stp->size[1];
  imin_stp->size[0] = ipow->size[0];
  imin_stp->size[1] = ipow->size[1];
  emxEnsureCapacity_real_T(imin_stp, i35);
  loop_ub = ipow->size[0] * ipow->size[1];
  for (i35 = 0; i35 < loop_ub; i35++) {
    imin_stp->data[i35] = ipow->data[i35];
  }

  i35 = ipow->size[0] * ipow->size[1];
  ipow->size[0] = imin_str->size[0];
  ipow->size[1] = imin_str->size[1];
  emxEnsureCapacity_real_T(ipow, i35);
  loop_ub = imin_str->size[0] * imin_str->size[1];
  for (i35 = 0; i35 < loop_ub; i35++) {
    ipow->data[i35] = imin_str->data[i35];
  }

  imin_str_size[0] = imin_str->size[0];
  imin_str_size[1] = imin_str->size[1];
  loop_ub = imin_str->size[0] * imin_str->size[1];
  for (i35 = 0; i35 < loop_ub; i35++) {
    b_imin_str_data[i35] = (imin_str->data[i35] == 500.0);
  }

  e_imin_str_data.data = &b_imin_str_data[0];
  e_imin_str_data.size = &imin_str_size[0];
  e_imin_str_data.allocatedSize = 12285;
  e_imin_str_data.numDimensions = 2;
  e_imin_str_data.canFreeData = false;
  c_nullAssignment(ipow, &e_imin_str_data);
  i35 = imin_str->size[0] * imin_str->size[1];
  imin_str->size[0] = ipow->size[0];
  imin_str->size[1] = ipow->size[1];
  emxEnsureCapacity_real_T(imin_str, i35);
  loop_ub = ipow->size[0] * ipow->size[1];
  for (i35 = 0; i35 < loop_ub; i35++) {
    imin_str->data[i35] = ipow->data[i35];
  }

  i35 = ipow->size[0] * ipow->size[1];
  ipow->size[0] = imax_stp->size[0];
  ipow->size[1] = imax_stp->size[1];
  emxEnsureCapacity_real_T(ipow, i35);
  loop_ub = imax_stp->size[0] * imax_stp->size[1];
  for (i35 = 0; i35 < loop_ub; i35++) {
    ipow->data[i35] = imax_stp->data[i35];
  }

  imin_str_size[0] = imax_stp->size[0];
  imin_str_size[1] = imax_stp->size[1];
  loop_ub = imax_stp->size[0] * imax_stp->size[1];
  for (i35 = 0; i35 < loop_ub; i35++) {
    b_imin_str_data[i35] = (imax_stp->data[i35] == 500.0);
  }

  f_imin_str_data.data = &b_imin_str_data[0];
  f_imin_str_data.size = &imin_str_size[0];
  f_imin_str_data.allocatedSize = 12285;
  f_imin_str_data.numDimensions = 2;
  f_imin_str_data.canFreeData = false;
  c_nullAssignment(ipow, &f_imin_str_data);
  i35 = imax_stp->size[0] * imax_stp->size[1];
  imax_stp->size[0] = ipow->size[0];
  imax_stp->size[1] = ipow->size[1];
  emxEnsureCapacity_real_T(imax_stp, i35);
  loop_ub = ipow->size[0] * ipow->size[1];
  for (i35 = 0; i35 < loop_ub; i35++) {
    imax_stp->data[i35] = ipow->data[i35];
  }

  i35 = ipow->size[0] * ipow->size[1];
  ipow->size[0] = imin_stp->size[0];
  ipow->size[1] = imin_stp->size[1];
  emxEnsureCapacity_real_T(ipow, i35);
  loop_ub = imin_stp->size[0] * imin_stp->size[1];
  for (i35 = 0; i35 < loop_ub; i35++) {
    ipow->data[i35] = imin_stp->data[i35];
  }

  imin_str_size[0] = imin_stp->size[0];
  imin_str_size[1] = imin_stp->size[1];
  loop_ub = imin_stp->size[0] * imin_stp->size[1];
  for (i35 = 0; i35 < loop_ub; i35++) {
    b_imin_str_data[i35] = (imin_stp->data[i35] == 500.0);
  }

  g_imin_str_data.data = &b_imin_str_data[0];
  g_imin_str_data.size = &imin_str_size[0];
  g_imin_str_data.allocatedSize = 12285;
  g_imin_str_data.numDimensions = 2;
  g_imin_str_data.canFreeData = false;
  c_nullAssignment(ipow, &g_imin_str_data);
  i35 = imin_stp->size[0] * imin_stp->size[1];
  imin_stp->size[0] = ipow->size[0];
  imin_stp->size[1] = ipow->size[1];
  emxEnsureCapacity_real_T(imin_stp, i35);
  loop_ub = ipow->size[0] * ipow->size[1];
  for (i35 = 0; i35 < loop_ub; i35++) {
    imin_stp->data[i35] = ipow->data[i35];
  }

  i35 = ipow->size[0] * ipow->size[1];
  ipow->size[0] = imax_str->size[0];
  ipow->size[1] = imax_str->size[1];
  emxEnsureCapacity_real_T(ipow, i35);
  loop_ub = imax_str->size[0] * imax_str->size[1];
  for (i35 = 0; i35 < loop_ub; i35++) {
    ipow->data[i35] = imax_str->data[i35];
  }

  imin_str_size[0] = imax_str->size[0];
  imin_str_size[1] = imax_str->size[1];
  loop_ub = imax_str->size[0] * imax_str->size[1];
  for (i35 = 0; i35 < loop_ub; i35++) {
    b_imin_str_data[i35] = (imax_str->data[i35] == 1.0);
  }

  h_imin_str_data.data = &b_imin_str_data[0];
  h_imin_str_data.size = &imin_str_size[0];
  h_imin_str_data.allocatedSize = 12285;
  h_imin_str_data.numDimensions = 2;
  h_imin_str_data.canFreeData = false;
  c_nullAssignment(ipow, &h_imin_str_data);
  i35 = imax_str->size[0] * imax_str->size[1];
  imax_str->size[0] = ipow->size[0];
  imax_str->size[1] = ipow->size[1];
  emxEnsureCapacity_real_T(imax_str, i35);
  loop_ub = ipow->size[0] * ipow->size[1];
  for (i35 = 0; i35 < loop_ub; i35++) {
    imax_str->data[i35] = ipow->data[i35];
  }

  i35 = ipow->size[0] * ipow->size[1];
  ipow->size[0] = imax_str->size[0];
  ipow->size[1] = imax_str->size[1];
  emxEnsureCapacity_real_T(ipow, i35);
  loop_ub = imax_str->size[0] * imax_str->size[1];
  for (i35 = 0; i35 < loop_ub; i35++) {
    ipow->data[i35] = imax_str->data[i35];
  }

  imin_str_size[0] = imax_str->size[0];
  imin_str_size[1] = imax_str->size[1];
  loop_ub = imax_str->size[0] * imax_str->size[1];
  for (i35 = 0; i35 < loop_ub; i35++) {
    b_imin_str_data[i35] = (imax_str->data[i35] == 500.0);
  }

  i_imin_str_data.data = &b_imin_str_data[0];
  i_imin_str_data.size = &imin_str_size[0];
  i_imin_str_data.allocatedSize = 12285;
  i_imin_str_data.numDimensions = 2;
  i_imin_str_data.canFreeData = false;
  c_nullAssignment(ipow, &i_imin_str_data);
  i35 = imax_str->size[0] * imax_str->size[1];
  imax_str->size[0] = ipow->size[0];
  imax_str->size[1] = ipow->size[1];
  emxEnsureCapacity_real_T(imax_str, i35);
  loop_ub = ipow->size[0] * ipow->size[1];
  for (i35 = 0; i35 < loop_ub; i35++) {
    imax_str->data[i35] = ipow->data[i35];
  }

  emxFree_real_T(&ipow);

  /*  get instants where z low passed at 5 crosses 1 g */
  for (i35 = 0; i35 < 500; i35++) {
    z5_thigh_acc[i35]--;
  }

  crossing0(z5_thigh_acc);

  /*  sometimes false minima identified within stride */
  /*  require minima be within min and max stride times */
  i = 1;
  do {
    exitg1 = 0;
    if ((imin_str->size[0] == 0) || (imin_str->size[1] == 0)) {
      deleteStride = 0;
    } else {
      deleteStride = imin_str->size[1];
    }

    if (i <= deleteStride - 1) {
      if ((imin_str->data[i] - imin_str->data[i - 1] < floor(0.5 * asf)) ||
          (imin_str->data[i] - imin_str->data[i - 1] > ceil(1.6 * asf))) {
        h_nullAssignment(imin_str, i + 1);
      } else {
        i++;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  /*  get stride peaks (max acc during stride) = swing start */
  /*  get one following valley for each stride peak ~ FC */
  /*  for each minima */
  if ((imin_str->size[0] == 0) || (imin_str->size[1] == 0)) {
    deleteStride = -1;
  } else {
    deleteStride = imin_str->size[1] - 1;
  }

  emxInit_real_T(&swingStart, 2);
  i35 = swingStart->size[0] * swingStart->size[1];
  swingStart->size[0] = 1;
  swingStart->size[1] = deleteStride;
  emxEnsureCapacity_real_T(swingStart, i35);
  for (i35 = 0; i35 < deleteStride; i35++) {
    swingStart->data[i35] = 0.0;
  }

  if ((imin_str->size[0] == 0) || (imin_str->size[1] == 0)) {
    deleteStride = -1;
  } else {
    deleteStride = imin_str->size[1] - 1;
  }

  emxInit_real_T(&strideStart, 2);
  i35 = strideStart->size[0] * strideStart->size[1];
  strideStart->size[0] = 1;
  strideStart->size[1] = deleteStride;
  emxEnsureCapacity_real_T(strideStart, i35);
  for (i35 = 0; i35 < deleteStride; i35++) {
    strideStart->data[i35] = 0.0;
  }

  emxInit_real_T(&varargin_1, 1);
  do {
    exitg1 = 0;
    if ((imin_str->size[0] == 0) || (imin_str->size[1] == 0)) {
      deleteStride = 0;
    } else {
      deleteStride = imin_str->size[1];
    }

    if (1 <= deleteStride - 1) {
      /*  get latest zstp peak between current and next str minima */
      deleteStride = imax_stp->size[0];
      nStrides = imax_stp->size[1];
      strideTime0 = imin_str->data[0];
      loop_ub = imax_stp->size[0] * imax_stp->size[1];
      for (i35 = 0; i35 < loop_ub; i35++) {
        tmp_data[i35] = (imax_stp->data[i35] > strideTime0);
      }

      strideTime0 = imin_str->data[1];
      loop_ub = imax_stp->size[0] * imax_stp->size[1];
      for (i35 = 0; i35 < loop_ub; i35++) {
        b_tmp_data[i35] = (imax_stp->data[i35] < strideTime0);
      }

      deleteStride = deleteStride * nStrides - 1;
      trueCount = 0;
      for (i = 0; i <= deleteStride; i++) {
        if (tmp_data[i] && b_tmp_data[i]) {
          trueCount++;
        }
      }

      nStrides = 0;
      for (i = 0; i <= deleteStride; i++) {
        if (tmp_data[i] && b_tmp_data[i]) {
          c_tmp_data[nStrides] = (short)(i + 1);
          nStrides++;
        }
      }

      i35 = varargin_1->size[0];
      varargin_1->size[0] = trueCount;
      emxEnsureCapacity_real_T(varargin_1, i35);
      for (i35 = 0; i35 < trueCount; i35++) {
        varargin_1->data[i35] = imax_stp->data[c_tmp_data[i35] - 1];
      }

      if (trueCount <= 2) {
        if (trueCount == 1) {
          strideTime0 = imax_stp->data[c_tmp_data[0] - 1];
        } else {
          i35 = c_tmp_data[0] - 1;
          deleteStride = c_tmp_data[1] - 1;
          if ((imax_stp->data[i35] < imax_stp->data[deleteStride]) || (rtIsNaN
               (imax_stp->data[i35]) && (!rtIsNaN(imax_stp->data[deleteStride]))))
          {
            strideTime0 = imax_stp->data[deleteStride];
          } else {
            strideTime0 = imax_stp->data[i35];
          }
        }
      } else {
        if (!rtIsNaN(varargin_1->data[0])) {
          nStrides = 1;
        } else {
          nStrides = 0;
          loop_ub = 2;
          exitg2 = false;
          while ((!exitg2) && (loop_ub <= trueCount)) {
            if (!rtIsNaN(varargin_1->data[loop_ub - 1])) {
              nStrides = loop_ub;
              exitg2 = true;
            } else {
              loop_ub++;
            }
          }
        }

        if (nStrides == 0) {
          strideTime0 = imax_stp->data[c_tmp_data[0] - 1];
        } else {
          strideTime0 = imax_stp->data[c_tmp_data[nStrides - 1] - 1];
          i35 = nStrides + 1;
          for (loop_ub = i35; loop_ub <= trueCount; loop_ub++) {
            deleteStride = c_tmp_data[loop_ub - 1] - 1;
            if (strideTime0 < imax_stp->data[deleteStride]) {
              strideTime0 = imax_stp->data[deleteStride];
            }
          }
        }
      }

      /*  if empty then delete */
      /*  check for peak in z5 within last 5 samp */
      deleteStride = imax_str->size[0];
      nStrides = imax_str->size[1];
      loop_ub = imax_str->size[0] * imax_str->size[1];
      for (i35 = 0; i35 < loop_ub; i35++) {
        tmp_data[i35] = (imax_str->data[i35] > strideTime0 - 5.0);
      }

      loop_ub = imax_str->size[0] * imax_str->size[1];
      for (i35 = 0; i35 < loop_ub; i35++) {
        b_tmp_data[i35] = (imax_str->data[i35] < strideTime0);
      }

      deleteStride = deleteStride * nStrides - 1;
      trueCount = 0;
      for (i = 0; i <= deleteStride; i++) {
        if (tmp_data[i] && b_tmp_data[i]) {
          trueCount++;
        }
      }

      if (trueCount == 0) {
        swingStart->data[0] = strideTime0 - 1.0;
      } else {
        trueCount = 0;
        for (i = 0; i <= deleteStride; i++) {
          if (tmp_data[i] && b_tmp_data[i]) {
            trueCount++;
          }
        }

        nStrides = 0;
        for (i = 0; i <= deleteStride; i++) {
          if (tmp_data[i] && b_tmp_data[i]) {
            d_tmp_data[nStrides] = (short)(i + 1);
            nStrides++;
          }
        }

        swingStart->data[0] = imax_str->data[d_tmp_data[trueCount - 1] - 1];
      }

      /*  get next valley */
      deleteStride = imin_stp->size[0];
      nStrides = imin_stp->size[1];
      strideTime0 = swingStart->data[0];
      loop_ub = imin_stp->size[0] * imin_stp->size[1];
      for (i35 = 0; i35 < loop_ub; i35++) {
        tmp_data[i35] = (strideTime0 < imin_stp->data[i35]);
      }

      deleteStride = deleteStride * nStrides - 1;
      trueCount = 0;
      for (i = 0; i <= deleteStride; i++) {
        if (tmp_data[i]) {
          trueCount++;
        }
      }

      nStrides = 0;
      for (i = 0; i <= deleteStride; i++) {
        if (tmp_data[i]) {
          e_tmp_data[nStrides] = (short)(i + 1);
          nStrides++;
        }
      }

      /*  if is empty then delete */
      if (trueCount != 0) {
        i35 = e_tmp_data[0] - 1;
        if (!(zstp_thigh_acc[(int)imin_stp->data[i35] - 1] >= 1.0)) {
          /*  otherwise save */
          strideStart->data[0] = imin_stp->data[i35];

          /*  get next instant where z5 crossed 1g */
          /*  if none then delete */
        }
      } else {
        /*  also require this valley be less than 1g */
      }

      i_nullAssignment(swingStart, 1);
      i_nullAssignment(strideStart, 1);
      h_nullAssignment(imin_str, 1);
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  emxFree_real_T(&varargin_1);
  emxFree_real_T(&imin_stp);
  emxFree_real_T(&imin_str);
  emxFree_real_T(&imax_stp);
  emxFree_real_T(&imax_str);

  /*  if none */
  if (strideStart->size[1] != 0) {
    emxInit_real_T(&strideEnd, 2);

    /*  stride ends are stride starts without first */
    i35 = strideEnd->size[0] * strideEnd->size[1];
    strideEnd->size[0] = 1;
    strideEnd->size[1] = strideStart->size[1];
    emxEnsureCapacity_real_T(strideEnd, i35);
    loop_ub = strideStart->size[0] * strideStart->size[1];
    for (i35 = 0; i35 < loop_ub; i35++) {
      strideEnd->data[i35] = strideStart->data[i35];
    }

    i35 = strideStart->size[1];
    i_nullAssignment(strideStart, i35);
    j_nullAssignment(strideEnd);

    /*  FC before first swing start not identified, delete */
    j_nullAssignment(swingStart);

    /*  get stride endpoints and check times */
    nStrides = strideStart->size[1];
    i35 = strideTime->size[0] * strideTime->size[1];
    strideTime->size[0] = 1;
    strideTime->size[1] = strideStart->size[1];
    emxEnsureCapacity_real_T(strideTime, i35);
    loop_ub = strideStart->size[1];
    for (i35 = 0; i35 < loop_ub; i35++) {
      strideTime->data[i35] = 0.0;
    }

    emxInit_real_T(&dutyCycle, 2);
    i35 = dutyCycle->size[0] * dutyCycle->size[1];
    dutyCycle->size[0] = 1;
    dutyCycle->size[1] = strideStart->size[1];
    emxEnsureCapacity_real_T(dutyCycle, i35);
    loop_ub = strideStart->size[1];
    for (i35 = 0; i35 < loop_ub; i35++) {
      dutyCycle->data[i35] = 0.0;
    }

    i = 1;
    emxInit_real_T(&r11, 2);
    while (i <= nStrides) {
      /*  get stride time */
      deleteStride = 0;
      strideTime0 = (strideEnd->data[i - 1] - strideStart->data[i - 1]) / asf;

      /*  get duty cycle */
      dutyCycle0 = (swingStart->data[i - 1] - strideStart->data[i - 1]) / asf /
        strideTime0;

      /*  check limits */
      if ((strideTime0 > 1.6) || (strideTime0 < 0.5)) {
        deleteStride = 1;
      } else {
        if ((dutyCycle0 > 0.73) || (dutyCycle0 < 0.35)) {
          deleteStride = 1;
        }
      }

      /*  if didn't meet critieria */
      if (deleteStride != 0) {
        /*  delete stride */
        i_nullAssignment(strideEnd, i);
        i_nullAssignment(strideStart, i);
        i_nullAssignment(swingStart, i);
        i35 = r11->size[0] * r11->size[1];
        r11->size[0] = 1;
        r11->size[1] = strideTime->size[1];
        emxEnsureCapacity_real_T(r11, i35);
        loop_ub = strideTime->size[0] * strideTime->size[1];
        for (i35 = 0; i35 < loop_ub; i35++) {
          r11->data[i35] = strideTime->data[i35];
        }

        i_nullAssignment(r11, i);
        i35 = strideTime->size[0] * strideTime->size[1];
        strideTime->size[0] = 1;
        strideTime->size[1] = r11->size[1];
        emxEnsureCapacity_real_T(strideTime, i35);
        loop_ub = r11->size[0] * r11->size[1];
        for (i35 = 0; i35 < loop_ub; i35++) {
          strideTime->data[i35] = r11->data[i35];
        }

        i35 = r11->size[0] * r11->size[1];
        r11->size[0] = 1;
        r11->size[1] = dutyCycle->size[1];
        emxEnsureCapacity_real_T(r11, i35);
        loop_ub = dutyCycle->size[0] * dutyCycle->size[1];
        for (i35 = 0; i35 < loop_ub; i35++) {
          r11->data[i35] = dutyCycle->data[i35];
        }

        i_nullAssignment(r11, i);
        i35 = dutyCycle->size[0] * dutyCycle->size[1];
        dutyCycle->size[0] = 1;
        dutyCycle->size[1] = r11->size[1];
        emxEnsureCapacity_real_T(dutyCycle, i35);
        loop_ub = r11->size[0] * r11->size[1];
        for (i35 = 0; i35 < loop_ub; i35++) {
          dutyCycle->data[i35] = r11->data[i35];
        }

        nStrides--;

        /*  otherwise save */
      } else {
        strideTime->data[i - 1] = strideTime0;
        dutyCycle->data[i - 1] = dutyCycle0;
        i++;
      }
    }

    emxFree_real_T(&r11);
    emxFree_real_T(&dutyCycle);
    emxFree_real_T(&strideEnd);
  }

  emxFree_real_T(&strideStart);
  emxFree_real_T(&swingStart);

  /*  Compute stride vars */
  /*  figure;  */
  /*  hold on; */
  /*  plot(z.thigh_acc,'color',[0.6,0.6,0.6]); */
  /*  plot(strideStart,zstp.thigh_acc(strideStart),'o','color','g'); */
  /*  plot(strideEnd,zstp.thigh_acc(strideEnd),'o','color','r'); */
  /*  plot(swingStart,zstp.thigh_acc(swingStart),'o','color',[.6,.6,.6]); */
  /*  plot(zstp.thigh_acc,'b'); */
  stride_vars = mean(strideTime);
  emxFree_real_T(&strideTime);
  return stride_vars;
}

/* End of code generation (get_strides.c) */

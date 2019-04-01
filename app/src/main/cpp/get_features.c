/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_features.c
 *
 * Code generation for function 'get_features'
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
#include "getFallClass_emxutil.h"
#include "extrema.h"
#include "nullAssignment.h"
#include "xcorr.h"
#include "sort1.h"
#include "pwelch.h"
#include "mean.h"
#include "kurtosis.h"
#include "skewness.h"
#include "vvarstd.h"
#include "bwfilt.h"
#include "vecnorm.h"

/* Function Definitions */
void get_features(const double a1[375], const double a2[375], double sf, double
                  feat[106])
{
  int i8;
  double b_a1[125];
  double z1l[125];
  double b_a2[125];
  double z2l[125];
  double c_a1[250];
  double h1[125];
  int a1_tmp;
  double h2[125];
  double h1l[125];
  double h2l[125];
  int i9;
  double minSample;
  double d_a1[125];
  double feat_tmp;
  double c_a2[125];
  double d2;
  emxArray_creal_T *pz1;
  static double acorz1l_data[4096];
  int acorz1l_size[1];
  emxArray_creal_T *pz2;
  static double acorz2l_data[4096];
  int acorz2l_size[1];
  emxArray_creal_T *ph1;
  static double acorh1l_data[4096];
  int acorh1l_size[1];
  emxArray_creal_T *ph2;
  static double acorh2l_data[4096];
  int acorh2l_size[1];
  emxArray_creal_T *pz1l;
  static double fz1l_data[4096];
  int fz1l_size[1];
  emxArray_creal_T *pz2l;
  static double fz2l_data[4096];
  int fz2l_size[1];
  emxArray_creal_T *ph1l;
  static double fh1l_data[4096];
  emxArray_creal_T *ph2l;
  emxArray_creal_T *pz1m;
  emxArray_creal_T *b_pz1m;
  emxArray_real_T *ipz1m;
  static double fh2l_data[4096];
  emxArray_real_T *p;
  static int iidx_data[12285];
  int iidx_size[2];
  emxArray_creal_T *pz2m;
  emxArray_real_T *ip;
  emxArray_creal_T *ph1m;
  emxArray_real_T *r0;
  emxArray_creal_T *ph2m;
  emxArray_real_T *r1;
  emxArray_creal_T *pz1lm;
  emxArray_real_T *r2;
  emxArray_real_T *pz1lmw;
  emxArray_creal_T *pz2lm;
  emxArray_real_T *r3;
  emxArray_real_T *pz2lmw;
  emxArray_creal_T *ph1lm;
  emxArray_real_T *r4;
  emxArray_real_T *ph1lmw;
  emxArray_creal_T *ph2lm;
  emxArray_real_T *r5;
  emxArray_real_T *ph2lmw;
  int i10;
  double c1[249];
  double lags[249];
  int acorz1_tmp_size[2];
  int acorz1_size[2];
  int acorz1_tmp_data[248];
  double acorz1_data[249];
  int lz1_size[2];
  double lz1_data[249];
  int acorz2_size[2];
  double acorz2_data[249];
  int lz2_size[2];
  double lz2_data[249];
  int acorh1_size[2];
  double acorh1_data[249];
  int lh1_size[2];
  double lh1_data[249];
  int acorh2_size[2];
  double acorh2_data[249];
  int lh2_size[2];
  emxArray_real_T *r6;
  double lh2_data[249];
  int tmp_size[2];
  emxArray_int32_T tmp_data;
  int b_tmp_data[124];
  int lz1l_size[2];
  double lz1l_data[249];
  int b_tmp_size[2];
  emxArray_int32_T c_tmp_data;
  int d_tmp_data[124];
  int lz2l_size[2];
  double lz2l_data[249];
  int c_tmp_size[2];
  emxArray_int32_T e_tmp_data;
  int f_tmp_data[124];
  int lh1l_size[2];
  double lh1l_data[249];
  int d_tmp_size[2];
  emxArray_int32_T g_tmp_data;
  int h_tmp_data[124];
  int lh2l_size[2];
  double lh2l_data[249];
  int b_acorz1_size[2];
  int e_tmp_size[2];
  emxArray_int32_T i_tmp_data;
  int j_tmp_data[124];
  int f_tmp_size[2];
  emxArray_int32_T k_tmp_data;
  int l_tmp_data[124];

  /*  input: */
  /*    a1 - calibrated thigh accelerometer data (3,n) */
  /*    a2 - calibrated chest accelerometer data (3,n) */
  /*        n - number of samples in 1 window */
  /*    fs - sampling rate */
  /*  output: */
  /*    feat - feature vector   */
  /*  initialization */
  /* window index */
  /*  window data and extract signals */
  for (i8 = 0; i8 < 125; i8++) {
    b_a1[i8] = a1[2 + 3 * i8];
  }

  bwfilt(b_a1, sf, z1l);
  for (i8 = 0; i8 < 125; i8++) {
    b_a2[i8] = a2[2 + 3 * i8];
  }

  bwfilt(b_a2, sf, z2l);
  for (i8 = 0; i8 < 125; i8++) {
    a1_tmp = i8 << 1;
    c_a1[a1_tmp] = a1[3 * i8];
    c_a1[1 + a1_tmp] = a1[1 + 3 * i8];
  }

  vecnorm(c_a1, h1);
  for (i8 = 0; i8 < 125; i8++) {
    a1_tmp = i8 << 1;
    c_a1[a1_tmp] = a2[3 * i8];
    c_a1[1 + a1_tmp] = a2[1 + 3 * i8];
  }

  vecnorm(c_a1, h2);
  bwfilt(h1, sf, h1l);
  bwfilt(h2, sf, h2l);

  /*  raw z/horizontal acc mean, variance, skewness, kurtosis */
  for (i8 = 0; i8 < 125; i8++) {
    i9 = 2 + 3 * i8;
    b_a1[i8] = a1[i9];
    b_a2[i8] = a2[i9];
    d_a1[i8] = a1[i9];
    c_a2[i8] = a2[i9];
  }

  feat[0] = b_mean(b_a1);
  feat[1] = b_mean(b_a2);
  minSample = b_mean(h1);
  feat[2] = minSample;
  feat_tmp = b_mean(h2);
  feat[3] = feat_tmp;
  feat[4] = vvarstd(d_a1);
  feat[5] = vvarstd(c_a2);
  feat[6] = vvarstd(h1);
  feat[7] = vvarstd(h2);
  for (i8 = 0; i8 < 125; i8++) {
    a1_tmp = 2 + 3 * i8;
    b_a1[i8] = a1[a1_tmp];
    b_a2[i8] = a2[a1_tmp];
  }

  feat[8] = skewness(b_a1);
  feat[9] = skewness(b_a2);
  feat[10] = skewness(h1);
  feat[11] = skewness(h2);
  for (i8 = 0; i8 < 125; i8++) {
    a1_tmp = 2 + 3 * i8;
    b_a1[i8] = a1[a1_tmp];
    b_a2[i8] = a2[a1_tmp];
  }

  feat[12] = kurtosis(b_a1);
  feat[13] = kurtosis(b_a2);
  feat[14] = kurtosis(h1);
  feat[15] = kurtosis(h2);

  /*  low pass z/horizontal acc variance, skewness, kurtosis (no mean, should = raw) */
  feat[16] = vvarstd(z1l);
  feat[17] = vvarstd(z2l);
  feat[18] = vvarstd(h1l);
  feat[19] = vvarstd(h2l);
  feat[20] = skewness(z1l);
  feat[21] = skewness(z2l);
  feat[22] = skewness(h1l);
  feat[23] = skewness(h2l);
  feat[24] = kurtosis(z1l);
  feat[25] = kurtosis(z2l);
  feat[26] = kurtosis(h1l);
  feat[27] = kurtosis(h2l);

  /*  unbiased raw z/horizontal spectral power density estimate */
  for (i8 = 0; i8 < 125; i8++) {
    b_a1[i8] = a1[2 + 3 * i8];
  }

  d2 = b_mean(b_a1);
  for (i8 = 0; i8 < 125; i8++) {
    b_a1[i8] = a1[2 + 3 * i8] - d2;
  }

  emxInit_creal_T(&pz1, 3);
  pwelch(b_a1, sf, pz1, acorz1l_data, acorz1l_size);
  for (i8 = 0; i8 < 125; i8++) {
    b_a2[i8] = a2[2 + 3 * i8];
  }

  d2 = b_mean(b_a2);
  for (i8 = 0; i8 < 125; i8++) {
    b_a2[i8] = a2[2 + 3 * i8] - d2;
  }

  emxInit_creal_T(&pz2, 3);
  pwelch(b_a2, sf, pz2, acorz2l_data, acorz2l_size);
  for (i8 = 0; i8 < 125; i8++) {
    b_a1[i8] = h1[i8] - minSample;
  }

  emxInit_creal_T(&ph1, 3);
  pwelch(b_a1, sf, ph1, acorh1l_data, acorh1l_size);
  for (i8 = 0; i8 < 125; i8++) {
    b_a1[i8] = h2[i8] - feat_tmp;
  }

  emxInit_creal_T(&ph2, 3);
  pwelch(b_a1, sf, ph2, acorh2l_data, acorh2l_size);

  /*  unbiased low pass z/horizontal spectral power density estimate */
  d2 = b_mean(z1l);
  for (i8 = 0; i8 < 125; i8++) {
    d_a1[i8] = z1l[i8] - d2;
  }

  emxInit_creal_T(&pz1l, 3);
  b_pwelch(d_a1, sf, pz1l, fz1l_data, fz1l_size);
  d2 = b_mean(z2l);
  for (i8 = 0; i8 < 125; i8++) {
    d_a1[i8] = z2l[i8] - d2;
  }

  emxInit_creal_T(&pz2l, 3);
  b_pwelch(d_a1, sf, pz2l, fz2l_data, fz2l_size);
  d2 = b_mean(h1l);
  for (i8 = 0; i8 < 125; i8++) {
    d_a1[i8] = h1l[i8] - d2;
  }

  emxInit_creal_T(&ph1l, 3);
  b_pwelch(d_a1, sf, ph1l, fh1l_data, fz2l_size);
  d2 = b_mean(h2l);
  for (i8 = 0; i8 < 125; i8++) {
    d_a1[i8] = h2l[i8] - d2;
  }

  emxInit_creal_T(&ph2l, 3);
  emxInit_creal_T(&pz1m, 2);
  emxInit_creal_T(&b_pz1m, 2);
  emxInit_real_T(&ipz1m, 2);
  b_pwelch(d_a1, sf, ph2l, fh2l_data, fz2l_size);

  /*  most dominant frequencies for raw and the power density there */
  extrema(pz1, b_pz1m, ipz1m);
  i8 = pz1m->size[0] * pz1m->size[1];
  pz1m->size[0] = b_pz1m->size[0];
  pz1m->size[1] = b_pz1m->size[1];
  emxEnsureCapacity_creal_T(pz1m, i8);
  a1_tmp = b_pz1m->size[0] * b_pz1m->size[1];
  emxFree_creal_T(&pz1);
  for (i8 = 0; i8 < a1_tmp; i8++) {
    pz1m->data[i8] = b_pz1m->data[i8];
  }

  emxInit_real_T(&p, 2);
  sort(pz1m, iidx_data, iidx_size);
  i8 = p->size[0] * p->size[1];
  p->size[0] = iidx_size[0];
  p->size[1] = iidx_size[1];
  emxEnsureCapacity_real_T(p, i8);
  a1_tmp = iidx_size[0] * iidx_size[1];
  for (i8 = 0; i8 < a1_tmp; i8++) {
    p->data[i8] = ipz1m->data[iidx_data[i8] - 1];
  }

  emxInit_creal_T(&pz2m, 2);
  extrema(pz2, b_pz1m, ipz1m);
  i8 = pz2m->size[0] * pz2m->size[1];
  pz2m->size[0] = b_pz1m->size[0];
  pz2m->size[1] = b_pz1m->size[1];
  emxEnsureCapacity_creal_T(pz2m, i8);
  a1_tmp = b_pz1m->size[0] * b_pz1m->size[1];
  emxFree_creal_T(&pz2);
  for (i8 = 0; i8 < a1_tmp; i8++) {
    pz2m->data[i8] = b_pz1m->data[i8];
  }

  emxInit_real_T(&ip, 2);
  sort(pz2m, iidx_data, iidx_size);
  i8 = ip->size[0] * ip->size[1];
  ip->size[0] = iidx_size[0];
  ip->size[1] = iidx_size[1];
  emxEnsureCapacity_real_T(ip, i8);
  a1_tmp = iidx_size[0] * iidx_size[1];
  for (i8 = 0; i8 < a1_tmp; i8++) {
    ip->data[i8] = ipz1m->data[iidx_data[i8] - 1];
  }

  emxInit_creal_T(&ph1m, 2);
  extrema(ph1, b_pz1m, ipz1m);
  i8 = ph1m->size[0] * ph1m->size[1];
  ph1m->size[0] = b_pz1m->size[0];
  ph1m->size[1] = b_pz1m->size[1];
  emxEnsureCapacity_creal_T(ph1m, i8);
  a1_tmp = b_pz1m->size[0] * b_pz1m->size[1];
  emxFree_creal_T(&ph1);
  for (i8 = 0; i8 < a1_tmp; i8++) {
    ph1m->data[i8] = b_pz1m->data[i8];
  }

  emxInit_real_T(&r0, 2);
  sort(ph1m, iidx_data, iidx_size);
  i8 = r0->size[0] * r0->size[1];
  r0->size[0] = iidx_size[0];
  r0->size[1] = iidx_size[1];
  emxEnsureCapacity_real_T(r0, i8);
  a1_tmp = iidx_size[0] * iidx_size[1];
  for (i8 = 0; i8 < a1_tmp; i8++) {
    r0->data[i8] = ipz1m->data[iidx_data[i8] - 1];
  }

  emxInit_creal_T(&ph2m, 2);
  extrema(ph2, b_pz1m, ipz1m);
  i8 = ph2m->size[0] * ph2m->size[1];
  ph2m->size[0] = b_pz1m->size[0];
  ph2m->size[1] = b_pz1m->size[1];
  emxEnsureCapacity_creal_T(ph2m, i8);
  a1_tmp = b_pz1m->size[0] * b_pz1m->size[1];
  emxFree_creal_T(&ph2);
  for (i8 = 0; i8 < a1_tmp; i8++) {
    ph2m->data[i8] = b_pz1m->data[i8];
  }

  emxInit_real_T(&r1, 2);
  sort(ph2m, iidx_data, iidx_size);
  i8 = r1->size[0] * r1->size[1];
  r1->size[0] = iidx_size[0];
  r1->size[1] = iidx_size[1];
  emxEnsureCapacity_real_T(r1, i8);
  a1_tmp = iidx_size[0] * iidx_size[1];
  for (i8 = 0; i8 < a1_tmp; i8++) {
    r1->data[i8] = ipz1m->data[iidx_data[i8] - 1];
  }

  emxInit_creal_T(&pz1lm, 2);

  /*  most dominant frequencies for lowpass and the power density there */
  extrema(pz1l, b_pz1m, ipz1m);
  i8 = pz1lm->size[0] * pz1lm->size[1];
  pz1lm->size[0] = b_pz1m->size[0];
  pz1lm->size[1] = b_pz1m->size[1];
  emxEnsureCapacity_creal_T(pz1lm, i8);
  a1_tmp = b_pz1m->size[0] * b_pz1m->size[1];
  emxFree_creal_T(&pz1l);
  for (i8 = 0; i8 < a1_tmp; i8++) {
    pz1lm->data[i8] = b_pz1m->data[i8];
  }

  emxInit_real_T(&r2, 2);
  sort(pz1lm, iidx_data, iidx_size);
  i8 = r2->size[0] * r2->size[1];
  r2->size[0] = iidx_size[0];
  r2->size[1] = iidx_size[1];
  emxEnsureCapacity_real_T(r2, i8);
  a1_tmp = iidx_size[0] * iidx_size[1];
  for (i8 = 0; i8 < a1_tmp; i8++) {
    r2->data[i8] = ipz1m->data[iidx_data[i8] - 1];
  }

  emxInit_real_T(&pz1lmw, 2);
  i8 = pz1lmw->size[0] * pz1lmw->size[1];
  pz1lmw->size[0] = r2->size[0];
  pz1lmw->size[1] = r2->size[1];
  emxEnsureCapacity_real_T(pz1lmw, i8);
  a1_tmp = r2->size[0] * r2->size[1];
  for (i8 = 0; i8 < a1_tmp; i8++) {
    pz1lmw->data[i8] = fz1l_data[(int)r2->data[i8] - 1];
  }

  emxInit_creal_T(&pz2lm, 2);
  extrema(pz2l, b_pz1m, ipz1m);
  i8 = pz2lm->size[0] * pz2lm->size[1];
  pz2lm->size[0] = b_pz1m->size[0];
  pz2lm->size[1] = b_pz1m->size[1];
  emxEnsureCapacity_creal_T(pz2lm, i8);
  a1_tmp = b_pz1m->size[0] * b_pz1m->size[1];
  emxFree_creal_T(&pz2l);
  for (i8 = 0; i8 < a1_tmp; i8++) {
    pz2lm->data[i8] = b_pz1m->data[i8];
  }

  emxInit_real_T(&r3, 2);
  sort(pz2lm, iidx_data, iidx_size);
  i8 = r3->size[0] * r3->size[1];
  r3->size[0] = iidx_size[0];
  r3->size[1] = iidx_size[1];
  emxEnsureCapacity_real_T(r3, i8);
  a1_tmp = iidx_size[0] * iidx_size[1];
  for (i8 = 0; i8 < a1_tmp; i8++) {
    r3->data[i8] = ipz1m->data[iidx_data[i8] - 1];
  }

  emxInit_real_T(&pz2lmw, 2);
  i8 = pz2lmw->size[0] * pz2lmw->size[1];
  pz2lmw->size[0] = r3->size[0];
  pz2lmw->size[1] = r3->size[1];
  emxEnsureCapacity_real_T(pz2lmw, i8);
  a1_tmp = r3->size[0] * r3->size[1];
  for (i8 = 0; i8 < a1_tmp; i8++) {
    pz2lmw->data[i8] = fz2l_data[(int)r3->data[i8] - 1];
  }

  emxInit_creal_T(&ph1lm, 2);
  extrema(ph1l, b_pz1m, ipz1m);
  i8 = ph1lm->size[0] * ph1lm->size[1];
  ph1lm->size[0] = b_pz1m->size[0];
  ph1lm->size[1] = b_pz1m->size[1];
  emxEnsureCapacity_creal_T(ph1lm, i8);
  a1_tmp = b_pz1m->size[0] * b_pz1m->size[1];
  emxFree_creal_T(&ph1l);
  for (i8 = 0; i8 < a1_tmp; i8++) {
    ph1lm->data[i8] = b_pz1m->data[i8];
  }

  emxInit_real_T(&r4, 2);
  sort(ph1lm, iidx_data, iidx_size);
  i8 = r4->size[0] * r4->size[1];
  r4->size[0] = iidx_size[0];
  r4->size[1] = iidx_size[1];
  emxEnsureCapacity_real_T(r4, i8);
  a1_tmp = iidx_size[0] * iidx_size[1];
  for (i8 = 0; i8 < a1_tmp; i8++) {
    r4->data[i8] = ipz1m->data[iidx_data[i8] - 1];
  }

  emxInit_real_T(&ph1lmw, 2);
  i8 = ph1lmw->size[0] * ph1lmw->size[1];
  ph1lmw->size[0] = r4->size[0];
  ph1lmw->size[1] = r4->size[1];
  emxEnsureCapacity_real_T(ph1lmw, i8);
  a1_tmp = r4->size[0] * r4->size[1];
  for (i8 = 0; i8 < a1_tmp; i8++) {
    ph1lmw->data[i8] = fh1l_data[(int)r4->data[i8] - 1];
  }

  emxInit_creal_T(&ph2lm, 2);
  extrema(ph2l, b_pz1m, ipz1m);
  i8 = ph2lm->size[0] * ph2lm->size[1];
  ph2lm->size[0] = b_pz1m->size[0];
  ph2lm->size[1] = b_pz1m->size[1];
  emxEnsureCapacity_creal_T(ph2lm, i8);
  a1_tmp = b_pz1m->size[0] * b_pz1m->size[1];
  emxFree_creal_T(&ph2l);
  for (i8 = 0; i8 < a1_tmp; i8++) {
    ph2lm->data[i8] = b_pz1m->data[i8];
  }

  emxFree_creal_T(&b_pz1m);
  emxInit_real_T(&r5, 2);
  sort(ph2lm, iidx_data, iidx_size);
  i8 = r5->size[0] * r5->size[1];
  r5->size[0] = iidx_size[0];
  r5->size[1] = iidx_size[1];
  emxEnsureCapacity_real_T(r5, i8);
  a1_tmp = iidx_size[0] * iidx_size[1];
  for (i8 = 0; i8 < a1_tmp; i8++) {
    r5->data[i8] = ipz1m->data[iidx_data[i8] - 1];
  }

  emxFree_real_T(&ipz1m);
  emxInit_real_T(&ph2lmw, 2);
  i8 = ph2lmw->size[0] * ph2lmw->size[1];
  ph2lmw->size[0] = r5->size[0];
  ph2lmw->size[1] = r5->size[1];
  emxEnsureCapacity_real_T(ph2lmw, i8);
  a1_tmp = r5->size[0] * r5->size[1];
  for (i8 = 0; i8 < a1_tmp; i8++) {
    ph2lmw->data[i8] = fh2l_data[(int)r5->data[i8] - 1];
  }

  /*  include top 3 in feature set for raw */
  i8 = p->size[0];
  i9 = p->size[0];
  feat[28] = pz1m->data[0].re;
  feat[29] = acorz1l_data[(int)p->data[0] - 1];
  feat[30] = pz1m->data[1].re;
  feat[31] = acorz1l_data[(int)p->data[p->size[0] * (1 / i8)] - 1];
  feat[32] = pz1m->data[2].re;
  feat[33] = acorz1l_data[(int)p->data[p->size[0] * (2 / i9)] - 1];
  i8 = ip->size[0];
  i9 = ip->size[0];
  feat[34] = pz2m->data[0].re;
  feat[35] = acorz2l_data[(int)ip->data[0] - 1];
  feat[36] = pz2m->data[1].re;
  feat[37] = acorz2l_data[(int)ip->data[ip->size[0] * (1 / i8)] - 1];
  feat[38] = pz2m->data[2].re;
  feat[39] = acorz2l_data[(int)ip->data[ip->size[0] * (2 / i9)] - 1];
  i8 = r0->size[0];
  i9 = r0->size[0];
  feat[40] = ph1m->data[0].re;
  feat[41] = acorh1l_data[(int)r0->data[0] - 1];
  feat[42] = ph1m->data[1].re;
  feat[43] = acorh1l_data[(int)r0->data[r0->size[0] * (1 / i8)] - 1];
  feat[44] = ph1m->data[2].re;
  feat[45] = acorh1l_data[(int)r0->data[r0->size[0] * (2 / i9)] - 1];
  i8 = r1->size[0];
  i9 = r1->size[0];
  feat[46] = ph2m->data[0].re;
  feat[47] = acorh2l_data[(int)r1->data[0] - 1];
  feat[48] = ph2m->data[1].re;
  feat[49] = acorh2l_data[(int)r1->data[r1->size[0] * (1 / i8)] - 1];
  feat[50] = ph2m->data[2].re;
  feat[51] = acorh2l_data[(int)r1->data[r1->size[0] * (2 / i9)] - 1];

  /*  include top 3 in feature set for lowpass */
  emxFree_real_T(&r1);
  emxFree_real_T(&r0);
  emxFree_creal_T(&ph2m);
  emxFree_creal_T(&ph1m);
  emxFree_creal_T(&pz2m);
  emxFree_creal_T(&pz1m);
  if ((pz1lm->size[0] == 0) || (pz1lm->size[1] == 0)) {
    a1_tmp = 0;
  } else {
    a1_tmp = pz1lm->size[1];
  }

  if (a1_tmp < 3) {
    i8 = pz1lm->size[0] * pz1lm->size[1];
    if (i8 + 1 > 3) {
      i8 = 0;
      i9 = -1;
    } else {
      i9 = 2;
    }

    a1_tmp = (i9 - i8) + 1;
    for (i9 = 0; i9 < a1_tmp; i9++) {
      i10 = i8 + i9;
      pz1lm->data[i10].re = 0.0;
      pz1lm->data[i10].im = 0.0;
    }

    i8 = r2->size[0] * r2->size[1];
    if (i8 + 1 > 3) {
      i8 = 0;
      i9 = -1;
    } else {
      i9 = 2;
    }

    a1_tmp = (i9 - i8) + 1;
    for (i9 = 0; i9 < a1_tmp; i9++) {
      pz1lmw->data[i8 + i9] = 0.0;
    }
  }

  emxFree_real_T(&r2);
  if ((pz2lm->size[0] == 0) || (pz2lm->size[1] == 0)) {
    a1_tmp = 0;
  } else {
    a1_tmp = pz2lm->size[1];
  }

  if (a1_tmp < 3) {
    i8 = pz2lm->size[0] * pz2lm->size[1];
    if (i8 + 1 > 3) {
      i8 = 0;
      i9 = -1;
    } else {
      i9 = 2;
    }

    a1_tmp = (i9 - i8) + 1;
    for (i9 = 0; i9 < a1_tmp; i9++) {
      i10 = i8 + i9;
      pz2lm->data[i10].re = 0.0;
      pz2lm->data[i10].im = 0.0;
    }

    i8 = r3->size[0] * r3->size[1];
    if (i8 + 1 > 3) {
      i8 = 0;
      i9 = -1;
    } else {
      i9 = 2;
    }

    a1_tmp = (i9 - i8) + 1;
    for (i9 = 0; i9 < a1_tmp; i9++) {
      pz2lmw->data[i8 + i9] = 0.0;
    }
  }

  emxFree_real_T(&r3);
  if ((ph1lm->size[0] == 0) || (ph1lm->size[1] == 0)) {
    a1_tmp = 0;
  } else {
    a1_tmp = ph1lm->size[1];
  }

  if (a1_tmp < 3) {
    i8 = ph1lm->size[0] * ph1lm->size[1];
    if (i8 + 1 > 3) {
      i8 = 0;
      i9 = -1;
    } else {
      i9 = 2;
    }

    a1_tmp = (i9 - i8) + 1;
    for (i9 = 0; i9 < a1_tmp; i9++) {
      i10 = i8 + i9;
      ph1lm->data[i10].re = 0.0;
      ph1lm->data[i10].im = 0.0;
    }

    i8 = r4->size[0] * r4->size[1];
    if (i8 + 1 > 3) {
      i8 = 0;
      i9 = -1;
    } else {
      i9 = 2;
    }

    a1_tmp = (i9 - i8) + 1;
    for (i9 = 0; i9 < a1_tmp; i9++) {
      ph1lmw->data[i8 + i9] = 0.0;
    }
  }

  emxFree_real_T(&r4);
  if ((ph2lm->size[0] == 0) || (ph2lm->size[1] == 0)) {
    a1_tmp = 0;
  } else {
    a1_tmp = ph2lm->size[1];
  }

  if (a1_tmp < 3) {
    i8 = ph2lm->size[0] * ph2lm->size[1];
    if (i8 + 1 > 3) {
      i8 = 0;
      i9 = -1;
    } else {
      i9 = 2;
    }

    a1_tmp = (i9 - i8) + 1;
    for (i9 = 0; i9 < a1_tmp; i9++) {
      i10 = i8 + i9;
      ph2lm->data[i10].re = 0.0;
      ph2lm->data[i10].im = 0.0;
    }

    i8 = r5->size[0] * r5->size[1];
    if (i8 + 1 > 3) {
      i8 = 0;
      i9 = -1;
    } else {
      i9 = 2;
    }

    a1_tmp = (i9 - i8) + 1;
    for (i9 = 0; i9 < a1_tmp; i9++) {
      ph2lmw->data[i8 + i9] = 0.0;
    }
  }

  emxFree_real_T(&r5);
  feat[52] = pz1lm->data[0].re;
  feat[53] = pz1lmw->data[0];
  feat[54] = pz1lm->data[1].re;
  feat[55] = pz1lmw->data[1];
  feat[56] = pz1lm->data[2].re;
  feat[57] = pz1lmw->data[2];
  feat[58] = pz2lm->data[0].re;
  feat[59] = pz2lmw->data[0];
  feat[60] = pz2lm->data[1].re;
  feat[61] = pz2lmw->data[1];
  feat[62] = pz2lm->data[2].re;
  feat[63] = pz2lmw->data[2];
  feat[64] = ph1lm->data[0].re;
  feat[65] = ph1lmw->data[0];
  feat[66] = ph1lm->data[1].re;
  feat[67] = ph1lmw->data[1];
  feat[68] = ph1lm->data[2].re;
  feat[69] = ph1lmw->data[2];
  feat[70] = ph2lm->data[0].re;
  feat[71] = ph2lmw->data[0];
  feat[72] = ph2lm->data[1].re;
  feat[73] = ph2lmw->data[1];
  feat[74] = ph2lm->data[2].re;
  feat[75] = ph2lmw->data[2];

  /*  autocorrelation of raw signals */
  emxFree_real_T(&ph2lmw);
  emxFree_creal_T(&ph2lm);
  emxFree_real_T(&ph1lmw);
  emxFree_creal_T(&ph1lm);
  emxFree_real_T(&pz2lmw);
  emxFree_creal_T(&pz2lm);
  emxFree_real_T(&pz1lmw);
  emxFree_creal_T(&pz1lm);
  for (i8 = 0; i8 < 125; i8++) {
    d_a1[i8] = a1[2 + 3 * i8];
  }

  xcorr(d_a1, c1, lags);
  acorz1_tmp_size[0] = 1;
  acorz1_tmp_size[1] = 124;
  for (i8 = 0; i8 < 124; i8++) {
    acorz1_tmp_data[i8] = 1 + i8;
  }

  acorz1_size[0] = 1;
  acorz1_size[1] = 249;
  memcpy(&acorz1_data[0], &c1[0], 249U * sizeof(double));
  d_nullAssignment(acorz1_data, acorz1_size, acorz1_tmp_data, acorz1_tmp_size);
  lz1_size[0] = 1;
  lz1_size[1] = 249;
  for (i8 = 0; i8 < 249; i8++) {
    lz1_data[i8] = lags[i8] / sf;
  }

  d_nullAssignment(lz1_data, lz1_size, acorz1_tmp_data, acorz1_tmp_size);
  for (i8 = 0; i8 < 125; i8++) {
    c_a2[i8] = a2[2 + 3 * i8];
  }

  xcorr(c_a2, c1, lags);
  acorz2_size[0] = 1;
  acorz2_size[1] = 249;
  memcpy(&acorz2_data[0], &c1[0], 249U * sizeof(double));
  d_nullAssignment(acorz2_data, acorz2_size, acorz1_tmp_data, acorz1_tmp_size);
  lz2_size[0] = 1;
  lz2_size[1] = 249;
  for (i8 = 0; i8 < 249; i8++) {
    lz2_data[i8] = lags[i8] / sf;
  }

  d_nullAssignment(lz2_data, lz2_size, acorz1_tmp_data, acorz1_tmp_size);
  xcorr(h1, c1, lags);
  acorh1_size[0] = 1;
  acorh1_size[1] = 249;
  memcpy(&acorh1_data[0], &c1[0], 249U * sizeof(double));
  d_nullAssignment(acorh1_data, acorh1_size, acorz1_tmp_data, acorz1_tmp_size);
  lh1_size[0] = 1;
  lh1_size[1] = 249;
  for (i8 = 0; i8 < 249; i8++) {
    lh1_data[i8] = lags[i8] / sf;
  }

  d_nullAssignment(lh1_data, lh1_size, acorz1_tmp_data, acorz1_tmp_size);
  xcorr(h2, c1, lags);
  acorh2_size[0] = 1;
  acorh2_size[1] = 249;
  memcpy(&acorh2_data[0], &c1[0], 249U * sizeof(double));
  d_nullAssignment(acorh2_data, acorh2_size, acorz1_tmp_data, acorz1_tmp_size);
  lh2_size[0] = 1;
  lh2_size[1] = 249;
  for (i8 = 0; i8 < 249; i8++) {
    lh2_data[i8] = lags[i8] / sf;
  }

  emxInit_real_T(&r6, 1);
  d_nullAssignment(lh2_data, lh2_size, acorz1_tmp_data, acorz1_tmp_size);

  /*  autocorrelation of lowpass signals */
  xcorr(z1l, c1, lags);
  i8 = r6->size[0];
  r6->size[0] = 249;
  emxEnsureCapacity_real_T(r6, i8);
  for (i8 = 0; i8 < 249; i8++) {
    r6->data[i8] = c1[i8];
  }

  tmp_size[0] = 1;
  tmp_size[1] = 124;
  for (i8 = 0; i8 < 124; i8++) {
    b_tmp_data[i8] = 1 + i8;
  }

  tmp_data.data = &b_tmp_data[0];
  tmp_data.size = &tmp_size[0];
  tmp_data.allocatedSize = 124;
  tmp_data.numDimensions = 2;
  tmp_data.canFreeData = false;
  b_nullAssignment(r6, &tmp_data);
  acorz1l_size[0] = r6->size[0];
  a1_tmp = r6->size[0];
  for (i8 = 0; i8 < a1_tmp; i8++) {
    acorz1l_data[i8] = r6->data[i8];
  }

  lz1l_size[0] = 1;
  lz1l_size[1] = 249;
  for (i8 = 0; i8 < 249; i8++) {
    lz1l_data[i8] = lags[i8] / sf;
  }

  d_nullAssignment(lz1l_data, lz1l_size, acorz1_tmp_data, acorz1_tmp_size);
  xcorr(z2l, c1, lags);
  i8 = r6->size[0];
  r6->size[0] = 249;
  emxEnsureCapacity_real_T(r6, i8);
  for (i8 = 0; i8 < 249; i8++) {
    r6->data[i8] = c1[i8];
  }

  b_tmp_size[0] = 1;
  b_tmp_size[1] = 124;
  for (i8 = 0; i8 < 124; i8++) {
    d_tmp_data[i8] = 1 + i8;
  }

  c_tmp_data.data = &d_tmp_data[0];
  c_tmp_data.size = &b_tmp_size[0];
  c_tmp_data.allocatedSize = 124;
  c_tmp_data.numDimensions = 2;
  c_tmp_data.canFreeData = false;
  b_nullAssignment(r6, &c_tmp_data);
  acorz2l_size[0] = r6->size[0];
  a1_tmp = r6->size[0];
  for (i8 = 0; i8 < a1_tmp; i8++) {
    acorz2l_data[i8] = r6->data[i8];
  }

  lz2l_size[0] = 1;
  lz2l_size[1] = 249;
  for (i8 = 0; i8 < 249; i8++) {
    lz2l_data[i8] = lags[i8] / sf;
  }

  d_nullAssignment(lz2l_data, lz2l_size, acorz1_tmp_data, acorz1_tmp_size);
  xcorr(h1l, c1, lags);
  i8 = r6->size[0];
  r6->size[0] = 249;
  emxEnsureCapacity_real_T(r6, i8);
  for (i8 = 0; i8 < 249; i8++) {
    r6->data[i8] = c1[i8];
  }

  c_tmp_size[0] = 1;
  c_tmp_size[1] = 124;
  for (i8 = 0; i8 < 124; i8++) {
    f_tmp_data[i8] = 1 + i8;
  }

  e_tmp_data.data = &f_tmp_data[0];
  e_tmp_data.size = &c_tmp_size[0];
  e_tmp_data.allocatedSize = 124;
  e_tmp_data.numDimensions = 2;
  e_tmp_data.canFreeData = false;
  b_nullAssignment(r6, &e_tmp_data);
  acorh1l_size[0] = r6->size[0];
  a1_tmp = r6->size[0];
  for (i8 = 0; i8 < a1_tmp; i8++) {
    acorh1l_data[i8] = r6->data[i8];
  }

  lh1l_size[0] = 1;
  lh1l_size[1] = 249;
  for (i8 = 0; i8 < 249; i8++) {
    lh1l_data[i8] = lags[i8] / sf;
  }

  d_nullAssignment(lh1l_data, lh1l_size, acorz1_tmp_data, acorz1_tmp_size);
  xcorr(h2l, c1, lags);
  i8 = r6->size[0];
  r6->size[0] = 249;
  emxEnsureCapacity_real_T(r6, i8);
  for (i8 = 0; i8 < 249; i8++) {
    r6->data[i8] = c1[i8];
  }

  d_tmp_size[0] = 1;
  d_tmp_size[1] = 124;
  for (i8 = 0; i8 < 124; i8++) {
    h_tmp_data[i8] = 1 + i8;
  }

  g_tmp_data.data = &h_tmp_data[0];
  g_tmp_data.size = &d_tmp_size[0];
  g_tmp_data.allocatedSize = 124;
  g_tmp_data.numDimensions = 2;
  g_tmp_data.canFreeData = false;
  b_nullAssignment(r6, &g_tmp_data);
  acorh2l_size[0] = r6->size[0];
  a1_tmp = r6->size[0];
  for (i8 = 0; i8 < a1_tmp; i8++) {
    acorh2l_data[i8] = r6->data[i8];
  }

  lh2l_size[0] = 1;
  lh2l_size[1] = 249;
  for (i8 = 0; i8 < 249; i8++) {
    lh2l_data[i8] = lags[i8] / sf;
  }

  d_nullAssignment(lh2l_data, lh2l_size, acorz1_tmp_data, acorz1_tmp_size);

  /*  get height at 0 lag and height/lag at first peak for raw */
  /*  require first peak be at least 0.3 s past 0 */
  minSample = floor(0.3 * sf);
  if (minSample > acorz1_size[1]) {
    i8 = 1;
    i9 = 0;
  } else {
    i8 = (int)minSample;
    i9 = acorz1_size[1];
  }

  b_acorz1_size[0] = 1;
  a1_tmp = i9 - i8;
  b_acorz1_size[1] = a1_tmp + 1;
  for (i9 = 0; i9 <= a1_tmp; i9++) {
    c1[i9] = acorz1_data[(i8 + i9) - 1];
  }

  b_extrema(c1, b_acorz1_size, p, ip);
  i8 = ip->size[0] * ip->size[1];
  i9 = ip->size[0] * ip->size[1];
  emxEnsureCapacity_real_T(ip, i9);
  a1_tmp = i8 - 1;
  for (i8 = 0; i8 <= a1_tmp; i8++) {
    ip->data[i8] = (ip->data[i8] + minSample) - 1.0;
  }

  feat[76] = acorz1_data[0];
  feat[77] = p->data[0];
  feat[78] = lz1_data[(int)ip->data[0] - 1];
  if (minSample > acorz2_size[1]) {
    i8 = 1;
    i9 = 0;
  } else {
    i8 = (int)minSample;
    i9 = acorz2_size[1];
  }

  b_acorz1_size[0] = 1;
  a1_tmp = i9 - i8;
  b_acorz1_size[1] = a1_tmp + 1;
  for (i9 = 0; i9 <= a1_tmp; i9++) {
    c1[i9] = acorz2_data[(i8 + i9) - 1];
  }

  b_extrema(c1, b_acorz1_size, p, ip);
  i8 = ip->size[0] * ip->size[1];
  i9 = ip->size[0] * ip->size[1];
  emxEnsureCapacity_real_T(ip, i9);
  a1_tmp = i8 - 1;
  for (i8 = 0; i8 <= a1_tmp; i8++) {
    ip->data[i8] = (ip->data[i8] + minSample) - 1.0;
  }

  feat[79] = acorz2_data[0];
  feat[80] = p->data[0];
  feat[81] = lz2_data[(int)ip->data[0] - 1];
  if (minSample > acorh1_size[1]) {
    i8 = 1;
    i9 = 0;
  } else {
    i8 = (int)minSample;
    i9 = acorh1_size[1];
  }

  b_acorz1_size[0] = 1;
  a1_tmp = i9 - i8;
  b_acorz1_size[1] = a1_tmp + 1;
  for (i9 = 0; i9 <= a1_tmp; i9++) {
    c1[i9] = acorh1_data[(i8 + i9) - 1];
  }

  b_extrema(c1, b_acorz1_size, p, ip);
  i8 = ip->size[0] * ip->size[1];
  i9 = ip->size[0] * ip->size[1];
  emxEnsureCapacity_real_T(ip, i9);
  a1_tmp = i8 - 1;
  for (i8 = 0; i8 <= a1_tmp; i8++) {
    ip->data[i8] = (ip->data[i8] + minSample) - 1.0;
  }

  feat[82] = acorh1_data[0];
  feat[83] = p->data[0];
  feat[84] = lh1_data[(int)ip->data[0] - 1];
  if (minSample > acorh2_size[1]) {
    i8 = 1;
    i9 = 0;
  } else {
    i8 = (int)minSample;
    i9 = acorh2_size[1];
  }

  b_acorz1_size[0] = 1;
  a1_tmp = i9 - i8;
  b_acorz1_size[1] = a1_tmp + 1;
  for (i9 = 0; i9 <= a1_tmp; i9++) {
    c1[i9] = acorh2_data[(i8 + i9) - 1];
  }

  b_extrema(c1, b_acorz1_size, p, ip);
  i8 = ip->size[0] * ip->size[1];
  i9 = ip->size[0] * ip->size[1];
  emxEnsureCapacity_real_T(ip, i9);
  a1_tmp = i8 - 1;
  for (i8 = 0; i8 <= a1_tmp; i8++) {
    ip->data[i8] = (ip->data[i8] + minSample) - 1.0;
  }

  feat[85] = acorh2_data[0];
  feat[86] = p->data[0];
  feat[87] = lh2_data[(int)ip->data[0] - 1];

  /*  get height at 0 lag and height/lag at first peak for lowpass */
  if (minSample > acorz1l_size[0]) {
    i8 = 1;
    i9 = 0;
  } else {
    i8 = (int)minSample;
    i9 = acorz1l_size[0];
  }

  a1_tmp = i9 - i8;
  fz1l_size[0] = a1_tmp + 1;
  for (i9 = 0; i9 <= a1_tmp; i9++) {
    fz1l_data[i9] = acorz1l_data[(i8 + i9) - 1];
  }

  c_extrema(fz1l_data, fz1l_size, p, ip);
  i8 = ip->size[0] * ip->size[1];
  i9 = ip->size[0] * ip->size[1];
  emxEnsureCapacity_real_T(ip, i9);
  a1_tmp = i8 - 1;
  for (i8 = 0; i8 <= a1_tmp; i8++) {
    ip->data[i8] = (ip->data[i8] + minSample) - 1.0;
  }

  feat[88] = acorz1l_data[0];
  feat[89] = p->data[0];
  feat[90] = lz1l_data[(int)ip->data[0] - 1];
  if (minSample > acorz2l_size[0]) {
    i8 = 1;
    i9 = 0;
  } else {
    i8 = (int)minSample;
    i9 = acorz2l_size[0];
  }

  a1_tmp = i9 - i8;
  fz1l_size[0] = a1_tmp + 1;
  for (i9 = 0; i9 <= a1_tmp; i9++) {
    fz1l_data[i9] = acorz2l_data[(i8 + i9) - 1];
  }

  c_extrema(fz1l_data, fz1l_size, p, ip);
  i8 = ip->size[0] * ip->size[1];
  i9 = ip->size[0] * ip->size[1];
  emxEnsureCapacity_real_T(ip, i9);
  a1_tmp = i8 - 1;
  for (i8 = 0; i8 <= a1_tmp; i8++) {
    ip->data[i8] = (ip->data[i8] + minSample) - 1.0;
  }

  feat[91] = acorz2l_data[0];
  feat[92] = p->data[0];
  feat[93] = lz2l_data[(int)ip->data[0] - 1];
  if (minSample > acorh1l_size[0]) {
    i8 = 1;
    i9 = 0;
  } else {
    i8 = (int)minSample;
    i9 = acorh1l_size[0];
  }

  a1_tmp = i9 - i8;
  fz1l_size[0] = a1_tmp + 1;
  for (i9 = 0; i9 <= a1_tmp; i9++) {
    fz1l_data[i9] = acorh1l_data[(i8 + i9) - 1];
  }

  c_extrema(fz1l_data, fz1l_size, p, ip);
  i8 = ip->size[0] * ip->size[1];
  i9 = ip->size[0] * ip->size[1];
  emxEnsureCapacity_real_T(ip, i9);
  a1_tmp = i8 - 1;
  for (i8 = 0; i8 <= a1_tmp; i8++) {
    ip->data[i8] = (ip->data[i8] + minSample) - 1.0;
  }

  feat[94] = acorh1l_data[0];
  feat[95] = p->data[0];
  feat[96] = lh1l_data[(int)ip->data[0] - 1];
  if (minSample > acorh2l_size[0]) {
    i8 = 1;
    i9 = 0;
  } else {
    i8 = (int)minSample;
    i9 = acorh2l_size[0];
  }

  a1_tmp = i9 - i8;
  fz1l_size[0] = a1_tmp + 1;
  for (i9 = 0; i9 <= a1_tmp; i9++) {
    fz1l_data[i9] = acorh2l_data[(i8 + i9) - 1];
  }

  c_extrema(fz1l_data, fz1l_size, p, ip);
  i8 = ip->size[0] * ip->size[1];
  i9 = ip->size[0] * ip->size[1];
  emxEnsureCapacity_real_T(ip, i9);
  a1_tmp = i8 - 1;
  for (i8 = 0; i8 <= a1_tmp; i8++) {
    ip->data[i8] = (ip->data[i8] + minSample) - 1.0;
  }

  feat[97] = acorh2l_data[0];
  feat[98] = p->data[0];
  feat[99] = lh2l_data[(int)ip->data[0] - 1];

  /*  cross correlation of lowpass sigs z1l-z2l, h2l-h2l */
  b_xcorr(z1l, z2l, c1, lags);
  i8 = r6->size[0];
  r6->size[0] = 249;
  emxEnsureCapacity_real_T(r6, i8);
  for (i8 = 0; i8 < 249; i8++) {
    r6->data[i8] = c1[i8];
  }

  e_tmp_size[0] = 1;
  e_tmp_size[1] = 124;
  for (i8 = 0; i8 < 124; i8++) {
    j_tmp_data[i8] = 1 + i8;
  }

  i_tmp_data.data = &j_tmp_data[0];
  i_tmp_data.size = &e_tmp_size[0];
  i_tmp_data.allocatedSize = 124;
  i_tmp_data.numDimensions = 2;
  i_tmp_data.canFreeData = false;
  b_nullAssignment(r6, &i_tmp_data);
  acorz1l_size[0] = r6->size[0];
  a1_tmp = r6->size[0];
  for (i8 = 0; i8 < a1_tmp; i8++) {
    acorz1l_data[i8] = r6->data[i8];
  }

  acorz1_size[0] = 1;
  acorz1_size[1] = 249;
  for (i8 = 0; i8 < 249; i8++) {
    acorz1_data[i8] = lags[i8] / sf;
  }

  d_nullAssignment(acorz1_data, acorz1_size, acorz1_tmp_data, acorz1_tmp_size);
  b_xcorr(h1l, h2l, c1, lags);
  i8 = r6->size[0];
  r6->size[0] = 249;
  emxEnsureCapacity_real_T(r6, i8);
  for (i8 = 0; i8 < 249; i8++) {
    r6->data[i8] = c1[i8];
  }

  f_tmp_size[0] = 1;
  f_tmp_size[1] = 124;
  for (i8 = 0; i8 < 124; i8++) {
    l_tmp_data[i8] = 1 + i8;
  }

  k_tmp_data.data = &l_tmp_data[0];
  k_tmp_data.size = &f_tmp_size[0];
  k_tmp_data.allocatedSize = 124;
  k_tmp_data.numDimensions = 2;
  k_tmp_data.canFreeData = false;
  b_nullAssignment(r6, &k_tmp_data);
  acorz2l_size[0] = r6->size[0];
  a1_tmp = r6->size[0];
  for (i8 = 0; i8 < a1_tmp; i8++) {
    acorz2l_data[i8] = r6->data[i8];
  }

  emxFree_real_T(&r6);
  lz1_size[0] = 1;
  lz1_size[1] = 249;
  for (i8 = 0; i8 < 249; i8++) {
    lz1_data[i8] = lags[i8] / sf;
  }

  d_nullAssignment(lz1_data, lz1_size, acorz1_tmp_data, acorz1_tmp_size);

  /*  get correlation at 0 lag and correlation/lag at first peak */
  /*  require first peak be at least 0.3 s past 0 */
  if (minSample > acorz1l_size[0]) {
    i8 = 1;
    i9 = 0;
  } else {
    i8 = (int)minSample;
    i9 = acorz1l_size[0];
  }

  a1_tmp = i9 - i8;
  fz1l_size[0] = a1_tmp + 1;
  for (i9 = 0; i9 <= a1_tmp; i9++) {
    fz1l_data[i9] = acorz1l_data[(i8 + i9) - 1];
  }

  c_extrema(fz1l_data, fz1l_size, p, ip);
  i8 = ip->size[0] * ip->size[1];
  i9 = ip->size[0] * ip->size[1];
  emxEnsureCapacity_real_T(ip, i9);
  a1_tmp = i8 - 1;
  for (i8 = 0; i8 <= a1_tmp; i8++) {
    ip->data[i8] = (ip->data[i8] + minSample) - 1.0;
  }

  feat[100] = acorz1l_data[0];
  feat[101] = p->data[0];
  feat[102] = acorz1_data[(int)ip->data[0] - 1];
  if (minSample > acorz2l_size[0]) {
    i8 = 1;
    i9 = 0;
  } else {
    i8 = (int)minSample;
    i9 = acorz2l_size[0];
  }

  a1_tmp = i9 - i8;
  fz1l_size[0] = a1_tmp + 1;
  for (i9 = 0; i9 <= a1_tmp; i9++) {
    fz1l_data[i9] = acorz2l_data[(i8 + i9) - 1];
  }

  c_extrema(fz1l_data, fz1l_size, p, ip);
  i8 = ip->size[0] * ip->size[1];
  i9 = ip->size[0] * ip->size[1];
  emxEnsureCapacity_real_T(ip, i9);
  a1_tmp = i8 - 1;
  for (i8 = 0; i8 <= a1_tmp; i8++) {
    ip->data[i8] = (ip->data[i8] + minSample) - 1.0;
  }

  feat[103] = acorz2l_data[0];
  feat[104] = p->data[0];
  feat[105] = lz1_data[(int)ip->data[0] - 1];
  emxFree_real_T(&p);
  emxFree_real_T(&ip);
}

/* End of code generation (get_features.c) */

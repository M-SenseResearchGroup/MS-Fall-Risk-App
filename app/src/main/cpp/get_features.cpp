/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_features.cpp
 *
 * Code generation for function 'get_features'
 *
 */

/* Include files */
#include <cmath>
#include <string.h>
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "get_features.h"
#include "calc_fall_risk_emxutil.h"
#include "extrema.h"
#include "nullAssignment.h"
#include "xcorr.h"
#include "sort1.h"
#include "pwelch.h"
#include "rectwin.h"
#include "mean.h"
#include "kurtosis.h"
#include "skewness.h"
#include "var.h"
#include "bwfilt.h"
#include "vecnorm.h"

/* Function Definitions */
void get_features(const double a1_data[], const double a2_data[], const int
                  a2_size[2], double sf, double feat[106])
{
  int a1_size[2];
  int i2;
  emxArray_real_T *h2l;
  double b_a1_data[125];
  int z1l_size[2];
  int loop_ub;
  double z1l_data[125];
  int aa_size[2];
  emxArray_real_T *z2l;
  double aa_data[313];
  int b_a1_size[2];
  double c_a1_data[250];
  double tmp_data[313];
  int tmp_size[2];
  int a1_data_tmp;
  int h1_size[2];
  double h1_data[125];
  int b_a2_size[2];
  double b_a2_data[626];
  double h2_data[313];
  int h2_size[2];
  int h1l_size[2];
  double h1l_data[125];
  emxArray_real_T d_a1_data;
  double d0;
  emxArray_real_T b_aa_data;
  double minSample;
  emxArray_real_T b_h1_data;
  double d1;
  emxArray_real_T b_h2_data;
  double d2;
  double aaaa_data[313];
  emxArray_real_T b_z1l_data;
  emxArray_real_T b_h1l_data;
  double b_tmp_data[313];
  emxArray_real_T c_z1l_data;
  double b_data[1];
  emxArray_real_T c_h1l_data;
  double bbb_data_idx_0;
  emxArray_real_T d_z1l_data;
  emxArray_real_T d_h1l_data;
  double c_tmp_data[125];
  int b_tmp_size[1];
  emxArray_real_T e_a1_data;
  emxArray_real_T *pz1;
  static double fz1_data[4096];
  emxArray_real_T c_aa_data;
  emxArray_real_T *pz2;
  static double fz2_data[4096];
  emxArray_real_T c_h1_data;
  emxArray_real_T *ph1;
  static double fh1_data[4096];
  emxArray_real_T c_h2_data;
  emxArray_real_T *ph2;
  static double fh2_data[4096];
  emxArray_real_T e_z1l_data;
  int b_size[2];
  emxArray_real_T *pz1l;
  static double fz1l_data[4096];
  emxArray_real_T *pz2l;
  static double fz2l_data[4096];
  emxArray_real_T e_h1l_data;
  emxArray_real_T *ph1l;
  static double fh1l_data[4096];
  emxArray_real_T *ph2l;
  emxArray_real_T *pz1m;
  emxArray_real_T *b_pz1m;
  emxArray_real_T *ipz1m;
  static double fh2l_data[4096];
  emxArray_real_T *r2;
  static int iidx_data[12285];
  emxArray_real_T *pz2m;
  emxArray_real_T *r3;
  emxArray_real_T *ph1m;
  emxArray_real_T *r4;
  emxArray_real_T *ph2m;
  emxArray_real_T *r5;
  emxArray_real_T *pz1lm;
  emxArray_real_T *r6;
  emxArray_real_T *pz1lmw;
  emxArray_real_T *pz2lm;
  emxArray_real_T *r7;
  emxArray_real_T *pz2lmw;
  emxArray_real_T *ph1lm;
  emxArray_real_T *r8;
  emxArray_real_T *ph1lmw;
  emxArray_real_T *ph2lm;
  emxArray_real_T *r9;
  emxArray_real_T *ph2lmw;
  int i3;
  double acorz1_data[625];
  static double lh2l_data[4408];
  emxArray_int32_T *acorz1_tmp;
  static double lz1_data[4220];
  emxArray_real_T *lxz;
  int acorz1_size[2];
  double b_acorz1_data[249];
  int c_tmp_size[2];
  emxArray_int32_T d_tmp_data;
  int e_tmp_data[2109];
  double acorz2_data[625];
  int acorz2_size[2];
  static double lz2_data[4408];
  int d_tmp_size[2];
  emxArray_int32_T f_tmp_data;
  int g_tmp_data[312];
  int e_tmp_size[2];
  emxArray_int32_T h_tmp_data;
  int i_tmp_data[2203];
  static double lh1_data[4220];
  int acorh1_size_idx_1;
  double acorh1_data[249];
  emxArray_int32_T j_tmp_data;
  static double lh2_data[4408];
  emxArray_int32_T k_tmp_data;
  emxArray_int32_T l_tmp_data;
  emxArray_real_T *acorz1l;
  emxArray_real_T f_z1l_data;
  emxArray_real_T *acorh2l;
  static double lz1l_data[4220];
  int f_tmp_size[2];
  emxArray_real_T *b_acorz1l;
  int m_tmp_data[124];
  emxArray_int32_T n_tmp_data;
  emxArray_int32_T o_tmp_data;
  static double lz2l_data[4408];
  int lz2l_size[2];
  emxArray_real_T *acorz2l;
  emxArray_int32_T *r10;
  emxArray_int32_T p_tmp_data;
  emxArray_real_T f_h1l_data;
  static double lh1l_data[4220];
  int g_tmp_size[2];
  emxArray_real_T *acorh1l;
  int q_tmp_data[124];
  emxArray_int32_T r_tmp_data;
  emxArray_int32_T s_tmp_data;
  emxArray_int32_T t_tmp_data;
  int b_acorz1_size[2];
  emxArray_real_T *ip;
  double c_acorz1_data[249];
  emxArray_real_T d_acorz1_data;
  int b_acorz2_size[2];
  emxArray_real_T b_acorz2_data;
  double c_acorz2_data[625];
  emxArray_real_T e_acorz1_data;
  emxArray_real_T d_acorz2_data;
  emxArray_real_T *c_acorz1l;
  emxArray_real_T *xz;
  emxArray_real_T *r11;
  emxArray_int32_T *r12;
  emxArray_real_T *lxh;
  emxArray_real_T *xh;
  emxArray_real_T *b_xz;

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
  a1_size[0] = 1;
  a1_size[1] = 125;
  for (i2 = 0; i2 < 125; i2++) {
    b_a1_data[i2] = a1_data[2 + 3 * i2];
  }

  emxInit_real_T(&h2l, 2);
  bwfilt(b_a1_data, a1_size, sf, h2l);
  z1l_size[0] = h2l->size[0];
  z1l_size[1] = h2l->size[1];
  loop_ub = h2l->size[0] * h2l->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    z1l_data[i2] = h2l->data[i2];
  }

  loop_ub = a2_size[1];
  aa_size[0] = 1;
  aa_size[1] = a2_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    aa_data[i2] = a2_data[2 + 3 * i2];
  }

  emxInit_real_T(&z2l, 2);
  bwfilt(aa_data, aa_size, sf, z2l);
  b_a1_size[0] = 2;
  b_a1_size[1] = 125;
  for (i2 = 0; i2 < 125; i2++) {
    a1_data_tmp = i2 << 1;
    c_a1_data[a1_data_tmp] = a1_data[3 * i2];
    c_a1_data[1 + a1_data_tmp] = a1_data[1 + 3 * i2];
  }

  vecnorm(c_a1_data, b_a1_size, tmp_data, tmp_size);
  h1_size[0] = 1;
  h1_size[1] = tmp_size[1];
  a1_data_tmp = tmp_size[0] * tmp_size[1];
  if (0 <= a1_data_tmp - 1) {
    memcpy(&h1_data[0], &tmp_data[0], (unsigned int)(a1_data_tmp * static_cast<
            int>(sizeof(double))));
  }

  loop_ub = a2_size[1];
  b_a2_size[0] = 2;
  b_a2_size[1] = a2_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    a1_data_tmp = i2 << 1;
    b_a2_data[a1_data_tmp] = a2_data[3 * i2];
    b_a2_data[1 + a1_data_tmp] = a2_data[1 + 3 * i2];
  }

  vecnorm(b_a2_data, b_a2_size, h2_data, h2_size);
  bwfilt(h1_data, h1_size, sf, h2l);
  h1l_size[0] = h2l->size[0];
  h1l_size[1] = h2l->size[1];
  loop_ub = h2l->size[0] * h2l->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    h1l_data[i2] = h2l->data[i2];
  }

  bwfilt(h2_data, h2_size, sf, h2l);

  /*  raw z/horizontal acc mean, variance, skewness, kurtosis */
  a1_size[0] = 1;
  a1_size[1] = 125;
  for (i2 = 0; i2 < 125; i2++) {
    b_a1_data[i2] = a1_data[2 + 3 * i2];
  }

  loop_ub = a2_size[1];
  aa_size[0] = 1;
  aa_size[1] = a2_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    aa_data[i2] = a2_data[2 + 3 * i2];
  }

  d_a1_data.data = &b_a1_data[0];
  d_a1_data.size = &a1_size[0];
  d_a1_data.allocatedSize = 125;
  d_a1_data.numDimensions = 2;
  d_a1_data.canFreeData = false;
  d0 = mean(&d_a1_data);
  b_aa_data.data = &aa_data[0];
  b_aa_data.size = &aa_size[0];
  b_aa_data.allocatedSize = 313;
  b_aa_data.numDimensions = 2;
  b_aa_data.canFreeData = false;
  minSample = mean(&b_aa_data);
  b_h1_data.data = &h1_data[0];
  b_h1_data.size = &h1_size[0];
  b_h1_data.allocatedSize = 125;
  b_h1_data.numDimensions = 2;
  b_h1_data.canFreeData = false;
  d1 = mean(&b_h1_data);
  b_h2_data.data = &h2_data[0];
  b_h2_data.size = &h2_size[0];
  b_h2_data.allocatedSize = 313;
  b_h2_data.numDimensions = 2;
  b_h2_data.canFreeData = false;
  d2 = mean(&b_h2_data);
  feat[0] = d0;
  feat[1] = minSample;
  feat[2] = d1;
  feat[3] = d2;
  a1_size[0] = 1;
  a1_size[1] = 125;
  for (i2 = 0; i2 < 125; i2++) {
    b_a1_data[i2] = a1_data[2 + 3 * i2];
  }

  loop_ub = a2_size[1];
  aa_size[0] = 1;
  aa_size[1] = a2_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    aa_data[i2] = a2_data[2 + 3 * i2];
  }

  d0 = var(b_a1_data, a1_size);
  minSample = var(aa_data, aa_size);
  d1 = var(h1_data, h1_size);
  d2 = var(h2_data, h2_size);
  feat[4] = d0;
  feat[5] = minSample;
  feat[6] = d1;
  feat[7] = d2;
  a1_size[0] = 1;
  a1_size[1] = 125;
  for (i2 = 0; i2 < 125; i2++) {
    b_a1_data[i2] = a1_data[2 + 3 * i2];
  }

  loop_ub = a2_size[1];
  aa_size[0] = 1;
  aa_size[1] = a2_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    aa_data[i2] = a2_data[2 + 3 * i2];
  }

  d0 = skewness(b_a1_data, a1_size);
  minSample = skewness(aa_data, aa_size);
  d1 = skewness(h1_data, h1_size);
  d2 = skewness(h2_data, h2_size);
  feat[8] = d0;
  feat[9] = minSample;
  feat[10] = d1;
  feat[11] = d2;
  a1_size[0] = 1;
  a1_size[1] = 125;
  for (i2 = 0; i2 < 125; i2++) {
    b_a1_data[i2] = a1_data[2 + 3 * i2];
  }

  loop_ub = a2_size[1];
  aa_size[0] = 1;
  aa_size[1] = a2_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    aa_data[i2] = a2_data[2 + 3 * i2];
  }

  d0 = kurtosis(b_a1_data, a1_size);
  minSample = kurtosis(aa_data, aa_size);
  d1 = kurtosis(h1_data, h1_size);
  d2 = kurtosis(h2_data, h2_size);
  feat[12] = d0;
  feat[13] = minSample;
  feat[14] = d1;
  feat[15] = d2;

  /*  low pass z/horizontal acc variance, skewness, kurtosis (no mean, should = raw) */
  /* this absurdity is for matlab codegen (c,c++) as they need to be defined as */
  /* single values explicitly, ugh */
  b_var(z2l, aa_data, aa_size);
  b_var(h2l, aaaa_data, b_a1_size);
  b_z1l_data.data = &z1l_data[0];
  b_z1l_data.size = &z1l_size[0];
  b_z1l_data.allocatedSize = 125;
  b_z1l_data.numDimensions = 2;
  b_z1l_data.canFreeData = false;
  b_var(&b_z1l_data, tmp_data, tmp_size);
  b_h1l_data.data = &h1l_data[0];
  b_h1l_data.size = &h1l_size[0];
  b_h1l_data.allocatedSize = 125;
  b_h1l_data.numDimensions = 2;
  b_h1l_data.canFreeData = false;
  b_var(&b_h1l_data, b_tmp_data, tmp_size);
  feat[16] = tmp_data[0];
  feat[17] = aa_data[0];
  feat[18] = b_tmp_data[0];
  feat[19] = aaaa_data[0];
  c_z1l_data.data = &z1l_data[0];
  c_z1l_data.size = &z1l_size[0];
  c_z1l_data.allocatedSize = 125;
  c_z1l_data.numDimensions = 2;
  c_z1l_data.canFreeData = false;
  b_skewness(&c_z1l_data, tmp_data, tmp_size);
  loop_ub = tmp_size[0] * tmp_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_data[0] = tmp_data[i2];
  }

  b_skewness(z2l, aaaa_data, b_a1_size);
  c_h1l_data.data = &h1l_data[0];
  c_h1l_data.size = &h1l_size[0];
  c_h1l_data.allocatedSize = 125;
  c_h1l_data.numDimensions = 2;
  c_h1l_data.canFreeData = false;
  b_skewness(&c_h1l_data, tmp_data, tmp_size);
  loop_ub = tmp_size[0] * tmp_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    bbb_data_idx_0 = tmp_data[i2];
  }

  b_skewness(h2l, aa_data, aa_size);
  feat[20] = b_data[0];
  feat[21] = aaaa_data[0];
  feat[22] = bbb_data_idx_0;
  feat[23] = aa_data[0];
  d_z1l_data.data = &z1l_data[0];
  d_z1l_data.size = &z1l_size[0];
  d_z1l_data.allocatedSize = 125;
  d_z1l_data.numDimensions = 2;
  d_z1l_data.canFreeData = false;
  b_kurtosis(&d_z1l_data, tmp_data, tmp_size);
  loop_ub = tmp_size[0] * tmp_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_data[0] = tmp_data[i2];
  }

  b_kurtosis(z2l, aaaa_data, b_a1_size);
  d_h1l_data.data = &h1l_data[0];
  d_h1l_data.size = &h1l_size[0];
  d_h1l_data.allocatedSize = 125;
  d_h1l_data.numDimensions = 2;
  d_h1l_data.canFreeData = false;
  b_kurtosis(&d_h1l_data, tmp_data, tmp_size);
  loop_ub = tmp_size[0] * tmp_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    bbb_data_idx_0 = tmp_data[i2];
  }

  b_kurtosis(h2l, aa_data, aa_size);
  feat[24] = b_data[0];
  feat[25] = aaaa_data[0];
  feat[26] = bbb_data_idx_0;
  feat[27] = aa_data[0];

  /*  unbiased raw z/horizontal spectral power density estimate */
  rectwin(c_tmp_data, b_tmp_size);
  a1_size[0] = 1;
  a1_size[1] = 125;
  for (i2 = 0; i2 < 125; i2++) {
    b_a1_data[i2] = a1_data[2 + 3 * i2];
  }

  e_a1_data.data = &b_a1_data[0];
  e_a1_data.size = &a1_size[0];
  e_a1_data.allocatedSize = 125;
  e_a1_data.numDimensions = 2;
  e_a1_data.canFreeData = false;
  d0 = mean(&e_a1_data);
  a1_size[0] = 1;
  a1_size[1] = 125;
  for (i2 = 0; i2 < 125; i2++) {
    b_a1_data[i2] = a1_data[2 + 3 * i2] - d0;
  }

  emxInit_creal_T(&pz1, 3);
  pwelch(b_a1_data, a1_size, c_tmp_data, sf, pz1, fz1_data, b_tmp_size);
  rectwin(c_tmp_data, b_tmp_size);
  loop_ub = a2_size[1];
  aa_size[0] = 1;
  aa_size[1] = a2_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    aa_data[i2] = a2_data[2 + 3 * i2];
  }

  c_aa_data.data = &aa_data[0];
  c_aa_data.size = &aa_size[0];
  c_aa_data.allocatedSize = 313;
  c_aa_data.numDimensions = 2;
  c_aa_data.canFreeData = false;
  d0 = mean(&c_aa_data);
  loop_ub = a2_size[1];
  aa_size[0] = 1;
  aa_size[1] = a2_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    aa_data[i2] = a2_data[2 + 3 * i2] - d0;
  }

  emxInit_creal_T(&pz2, 3);
  pwelch(aa_data, aa_size, c_tmp_data, sf, pz2, fz2_data, b_tmp_size);
  rectwin(c_tmp_data, b_tmp_size);
  c_h1_data.data = &h1_data[0];
  c_h1_data.size = &h1_size[0];
  c_h1_data.allocatedSize = 125;
  c_h1_data.numDimensions = 2;
  c_h1_data.canFreeData = false;
  d0 = mean(&c_h1_data);
  a1_size[0] = 1;
  a1_size[1] = 125;
  for (i2 = 0; i2 < 125; i2++) {
    b_a1_data[i2] = h1_data[i2] - d0;
  }

  emxInit_creal_T(&ph1, 3);
  pwelch(b_a1_data, a1_size, c_tmp_data, sf, ph1, fh1_data, b_tmp_size);
  rectwin(c_tmp_data, b_tmp_size);
  c_h2_data.data = &h2_data[0];
  c_h2_data.size = &h2_size[0];
  c_h2_data.allocatedSize = 313;
  c_h2_data.numDimensions = 2;
  c_h2_data.canFreeData = false;
  d0 = mean(&c_h2_data);
  aa_size[0] = 1;
  aa_size[1] = h2_size[1];
  loop_ub = h2_size[0] * h2_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    aa_data[i2] = h2_data[i2] - d0;
  }

  emxInit_creal_T(&ph2, 3);
  pwelch(aa_data, aa_size, c_tmp_data, sf, ph2, fh2_data, b_tmp_size);

  /*  unbiased low pass z/horizontal spectral power density estimate */
  e_z1l_data.data = &z1l_data[0];
  e_z1l_data.size = &z1l_size[0];
  e_z1l_data.allocatedSize = 125;
  e_z1l_data.numDimensions = 2;
  e_z1l_data.canFreeData = false;
  b_mean(&e_z1l_data, tmp_data, tmp_size);
  rectwin(c_tmp_data, b_tmp_size);
  b_size[0] = 125;
  b_size[1] = 1;
  for (i2 = 0; i2 < 125; i2++) {
    b_data[0] = z1l_data[i2] - tmp_data[i2];
  }

  emxInit_creal_T(&pz1l, 3);
  pwelch(b_data, b_size, c_tmp_data, sf, pz1l, fz1l_data, b_tmp_size);
  b_mean(z2l, tmp_data, tmp_size);
  rectwin(c_tmp_data, b_tmp_size);
  aa_size[0] = z2l->size[0];
  aa_size[1] = z2l->size[1];
  loop_ub = z2l->size[0] * z2l->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    aa_data[i2] = z2l->data[i2] - tmp_data[i2];
  }

  emxInit_creal_T(&pz2l, 3);
  pwelch(aa_data, aa_size, c_tmp_data, sf, pz2l, fz2l_data, b_tmp_size);
  e_h1l_data.data = &h1l_data[0];
  e_h1l_data.size = &h1l_size[0];
  e_h1l_data.allocatedSize = 125;
  e_h1l_data.numDimensions = 2;
  e_h1l_data.canFreeData = false;
  b_mean(&e_h1l_data, tmp_data, tmp_size);
  rectwin(c_tmp_data, b_tmp_size);
  b_size[0] = 125;
  b_size[1] = 1;
  for (i2 = 0; i2 < 125; i2++) {
    b_data[0] = h1l_data[i2] - tmp_data[i2];
  }

  emxInit_creal_T(&ph1l, 3);
  pwelch(b_data, b_size, c_tmp_data, sf, ph1l, fh1l_data, b_tmp_size);
  b_mean(h2l, tmp_data, tmp_size);
  rectwin(c_tmp_data, b_tmp_size);
  aa_size[0] = h2l->size[0];
  aa_size[1] = h2l->size[1];
  loop_ub = h2l->size[0] * h2l->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    aa_data[i2] = h2l->data[i2] - tmp_data[i2];
  }

  emxInit_creal_T(&ph2l, 3);
  emxInit_creal_T(&pz1m, 2);
  emxInit_creal_T(&b_pz1m, 2);
  emxInit_real_T(&ipz1m, 2);
  pwelch(aa_data, aa_size, c_tmp_data, sf, ph2l, fh2l_data, b_tmp_size);

  /*  most dominant frequencies for raw and the power density there */
  extrema(pz1, b_pz1m, ipz1m);
  i2 = pz1m->size[0] * pz1m->size[1];
  pz1m->size[0] = b_pz1m->size[0];
  pz1m->size[1] = b_pz1m->size[1];
  emxEnsureCapacity_creal_T(pz1m, i2);
  loop_ub = b_pz1m->size[0] * b_pz1m->size[1];
  emxFree_creal_T(&pz1);
  for (i2 = 0; i2 < loop_ub; i2++) {
    pz1m->data[i2] = b_pz1m->data[i2];
  }

  emxInit_real_T(&r2, 2);
  sort(pz1m, iidx_data, b_a1_size);
  i2 = r2->size[0] * r2->size[1];
  r2->size[0] = b_a1_size[0];
  r2->size[1] = b_a1_size[1];
  emxEnsureCapacity_real_T(r2, i2);
  a1_data_tmp = b_a1_size[0] * b_a1_size[1];
  for (i2 = 0; i2 < a1_data_tmp; i2++) {
    r2->data[i2] = ipz1m->data[iidx_data[i2] - 1];
  }

  emxInit_creal_T(&pz2m, 2);
  extrema(pz2, b_pz1m, ipz1m);
  i2 = pz2m->size[0] * pz2m->size[1];
  pz2m->size[0] = b_pz1m->size[0];
  pz2m->size[1] = b_pz1m->size[1];
  emxEnsureCapacity_creal_T(pz2m, i2);
  loop_ub = b_pz1m->size[0] * b_pz1m->size[1];
  emxFree_creal_T(&pz2);
  for (i2 = 0; i2 < loop_ub; i2++) {
    pz2m->data[i2] = b_pz1m->data[i2];
  }

  emxInit_real_T(&r3, 2);
  sort(pz2m, iidx_data, b_a1_size);
  i2 = r3->size[0] * r3->size[1];
  r3->size[0] = b_a1_size[0];
  r3->size[1] = b_a1_size[1];
  emxEnsureCapacity_real_T(r3, i2);
  loop_ub = b_a1_size[0] * b_a1_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    r3->data[i2] = ipz1m->data[iidx_data[i2] - 1];
  }

  emxInit_creal_T(&ph1m, 2);
  extrema(ph1, b_pz1m, ipz1m);
  i2 = ph1m->size[0] * ph1m->size[1];
  ph1m->size[0] = b_pz1m->size[0];
  ph1m->size[1] = b_pz1m->size[1];
  emxEnsureCapacity_creal_T(ph1m, i2);
  loop_ub = b_pz1m->size[0] * b_pz1m->size[1];
  emxFree_creal_T(&ph1);
  for (i2 = 0; i2 < loop_ub; i2++) {
    ph1m->data[i2] = b_pz1m->data[i2];
  }

  emxInit_real_T(&r4, 2);
  sort(ph1m, iidx_data, b_a1_size);
  i2 = r4->size[0] * r4->size[1];
  r4->size[0] = b_a1_size[0];
  r4->size[1] = b_a1_size[1];
  emxEnsureCapacity_real_T(r4, i2);
  loop_ub = b_a1_size[0] * b_a1_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    r4->data[i2] = ipz1m->data[iidx_data[i2] - 1];
  }

  emxInit_creal_T(&ph2m, 2);
  extrema(ph2, b_pz1m, ipz1m);
  i2 = ph2m->size[0] * ph2m->size[1];
  ph2m->size[0] = b_pz1m->size[0];
  ph2m->size[1] = b_pz1m->size[1];
  emxEnsureCapacity_creal_T(ph2m, i2);
  loop_ub = b_pz1m->size[0] * b_pz1m->size[1];
  emxFree_creal_T(&ph2);
  for (i2 = 0; i2 < loop_ub; i2++) {
    ph2m->data[i2] = b_pz1m->data[i2];
  }

  emxInit_real_T(&r5, 2);
  sort(ph2m, iidx_data, b_a1_size);
  i2 = r5->size[0] * r5->size[1];
  r5->size[0] = b_a1_size[0];
  r5->size[1] = b_a1_size[1];
  emxEnsureCapacity_real_T(r5, i2);
  loop_ub = b_a1_size[0] * b_a1_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    r5->data[i2] = ipz1m->data[iidx_data[i2] - 1];
  }

  emxInit_creal_T(&pz1lm, 2);

  /*  most dominant frequencies for lowpass and the power density there */
  extrema(pz1l, b_pz1m, ipz1m);
  i2 = pz1lm->size[0] * pz1lm->size[1];
  pz1lm->size[0] = b_pz1m->size[0];
  pz1lm->size[1] = b_pz1m->size[1];
  emxEnsureCapacity_creal_T(pz1lm, i2);
  loop_ub = b_pz1m->size[0] * b_pz1m->size[1];
  emxFree_creal_T(&pz1l);
  for (i2 = 0; i2 < loop_ub; i2++) {
    pz1lm->data[i2] = b_pz1m->data[i2];
  }

  emxInit_real_T(&r6, 2);
  sort(pz1lm, iidx_data, b_a1_size);
  i2 = r6->size[0] * r6->size[1];
  r6->size[0] = b_a1_size[0];
  r6->size[1] = b_a1_size[1];
  emxEnsureCapacity_real_T(r6, i2);
  loop_ub = b_a1_size[0] * b_a1_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    r6->data[i2] = ipz1m->data[iidx_data[i2] - 1];
  }

  emxInit_real_T(&pz1lmw, 2);
  i2 = pz1lmw->size[0] * pz1lmw->size[1];
  pz1lmw->size[0] = r6->size[0];
  pz1lmw->size[1] = r6->size[1];
  emxEnsureCapacity_real_T(pz1lmw, i2);
  loop_ub = r6->size[0] * r6->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    pz1lmw->data[i2] = fz1l_data[static_cast<int>(r6->data[i2]) - 1];
  }

  emxInit_creal_T(&pz2lm, 2);
  extrema(pz2l, b_pz1m, ipz1m);
  i2 = pz2lm->size[0] * pz2lm->size[1];
  pz2lm->size[0] = b_pz1m->size[0];
  pz2lm->size[1] = b_pz1m->size[1];
  emxEnsureCapacity_creal_T(pz2lm, i2);
  loop_ub = b_pz1m->size[0] * b_pz1m->size[1];
  emxFree_creal_T(&pz2l);
  for (i2 = 0; i2 < loop_ub; i2++) {
    pz2lm->data[i2] = b_pz1m->data[i2];
  }

  emxInit_real_T(&r7, 2);
  sort(pz2lm, iidx_data, b_a1_size);
  i2 = r7->size[0] * r7->size[1];
  r7->size[0] = b_a1_size[0];
  r7->size[1] = b_a1_size[1];
  emxEnsureCapacity_real_T(r7, i2);
  loop_ub = b_a1_size[0] * b_a1_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    r7->data[i2] = ipz1m->data[iidx_data[i2] - 1];
  }

  emxInit_real_T(&pz2lmw, 2);
  i2 = pz2lmw->size[0] * pz2lmw->size[1];
  pz2lmw->size[0] = r7->size[0];
  pz2lmw->size[1] = r7->size[1];
  emxEnsureCapacity_real_T(pz2lmw, i2);
  loop_ub = r7->size[0] * r7->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    pz2lmw->data[i2] = fz2l_data[static_cast<int>(r7->data[i2]) - 1];
  }

  emxInit_creal_T(&ph1lm, 2);
  extrema(ph1l, b_pz1m, ipz1m);
  i2 = ph1lm->size[0] * ph1lm->size[1];
  ph1lm->size[0] = b_pz1m->size[0];
  ph1lm->size[1] = b_pz1m->size[1];
  emxEnsureCapacity_creal_T(ph1lm, i2);
  loop_ub = b_pz1m->size[0] * b_pz1m->size[1];
  emxFree_creal_T(&ph1l);
  for (i2 = 0; i2 < loop_ub; i2++) {
    ph1lm->data[i2] = b_pz1m->data[i2];
  }

  emxInit_real_T(&r8, 2);
  sort(ph1lm, iidx_data, b_a1_size);
  i2 = r8->size[0] * r8->size[1];
  r8->size[0] = b_a1_size[0];
  r8->size[1] = b_a1_size[1];
  emxEnsureCapacity_real_T(r8, i2);
  loop_ub = b_a1_size[0] * b_a1_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    r8->data[i2] = ipz1m->data[iidx_data[i2] - 1];
  }

  emxInit_real_T(&ph1lmw, 2);
  i2 = ph1lmw->size[0] * ph1lmw->size[1];
  ph1lmw->size[0] = r8->size[0];
  ph1lmw->size[1] = r8->size[1];
  emxEnsureCapacity_real_T(ph1lmw, i2);
  loop_ub = r8->size[0] * r8->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    ph1lmw->data[i2] = fh1l_data[static_cast<int>(r8->data[i2]) - 1];
  }

  emxInit_creal_T(&ph2lm, 2);
  extrema(ph2l, b_pz1m, ipz1m);
  i2 = ph2lm->size[0] * ph2lm->size[1];
  ph2lm->size[0] = b_pz1m->size[0];
  ph2lm->size[1] = b_pz1m->size[1];
  emxEnsureCapacity_creal_T(ph2lm, i2);
  loop_ub = b_pz1m->size[0] * b_pz1m->size[1];
  emxFree_creal_T(&ph2l);
  for (i2 = 0; i2 < loop_ub; i2++) {
    ph2lm->data[i2] = b_pz1m->data[i2];
  }

  emxFree_creal_T(&b_pz1m);
  emxInit_real_T(&r9, 2);
  sort(ph2lm, iidx_data, b_a1_size);
  i2 = r9->size[0] * r9->size[1];
  r9->size[0] = b_a1_size[0];
  r9->size[1] = b_a1_size[1];
  emxEnsureCapacity_real_T(r9, i2);
  loop_ub = b_a1_size[0] * b_a1_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    r9->data[i2] = ipz1m->data[iidx_data[i2] - 1];
  }

  emxInit_real_T(&ph2lmw, 2);
  i2 = ph2lmw->size[0] * ph2lmw->size[1];
  ph2lmw->size[0] = r9->size[0];
  ph2lmw->size[1] = r9->size[1];
  emxEnsureCapacity_real_T(ph2lmw, i2);
  loop_ub = r9->size[0] * r9->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    ph2lmw->data[i2] = fh2l_data[static_cast<int>(r9->data[i2]) - 1];
  }

  /*  include top 3 in feature set for raw */
  i2 = r2->size[0];
  i3 = r2->size[0];
  feat[28] = pz1m->data[0].re;
  feat[29] = fz1_data[static_cast<int>(r2->data[0]) - 1];
  feat[30] = pz1m->data[1].re;
  feat[31] = fz1_data[static_cast<int>(r2->data[r2->size[0] * (1 / i2)]) - 1];
  feat[32] = pz1m->data[2].re;
  feat[33] = fz1_data[static_cast<int>(r2->data[r2->size[0] * (2 / i3)]) - 1];
  i2 = r3->size[0];
  i3 = r3->size[0];
  feat[34] = pz2m->data[0].re;
  feat[35] = fz2_data[static_cast<int>(r3->data[0]) - 1];
  feat[36] = pz2m->data[1].re;
  feat[37] = fz2_data[static_cast<int>(r3->data[r3->size[0] * (1 / i2)]) - 1];
  feat[38] = pz2m->data[2].re;
  feat[39] = fz2_data[static_cast<int>(r3->data[r3->size[0] * (2 / i3)]) - 1];
  i2 = r4->size[0];
  i3 = r4->size[0];
  feat[40] = ph1m->data[0].re;
  feat[41] = fh1_data[static_cast<int>(r4->data[0]) - 1];
  feat[42] = ph1m->data[1].re;
  feat[43] = fh1_data[static_cast<int>(r4->data[r4->size[0] * (1 / i2)]) - 1];
  feat[44] = ph1m->data[2].re;
  feat[45] = fh1_data[static_cast<int>(r4->data[r4->size[0] * (2 / i3)]) - 1];
  i2 = r5->size[0];
  i3 = r5->size[0];
  feat[46] = ph2m->data[0].re;
  feat[47] = fh2_data[static_cast<int>(r5->data[0]) - 1];
  feat[48] = ph2m->data[1].re;
  feat[49] = fh2_data[static_cast<int>(r5->data[r5->size[0] * (1 / i2)]) - 1];
  feat[50] = ph2m->data[2].re;
  feat[51] = fh2_data[static_cast<int>(r5->data[r5->size[0] * (2 / i3)]) - 1];

  /*  include top 3 in feature set for lowpass */
  emxFree_real_T(&r5);
  emxFree_real_T(&r4);
  emxFree_real_T(&r3);
  emxFree_real_T(&r2);
  emxFree_creal_T(&ph2m);
  emxFree_creal_T(&ph1m);
  emxFree_creal_T(&pz2m);
  emxFree_creal_T(&pz1m);
  if ((pz1lm->size[0] == 0) || (pz1lm->size[1] == 0)) {
    a1_data_tmp = 0;
  } else {
    a1_data_tmp = pz1lm->size[1];
  }

  if (a1_data_tmp < 3) {
    i2 = pz1lm->size[0] * pz1lm->size[1] - 1;
    if (i2 + 2 > 3) {
      i2 = -1;
      i3 = -1;
    } else {
      i3 = 2;
    }

    loop_ub = i3 - i2;
    for (i3 = 0; i3 < loop_ub; i3++) {
      a1_data_tmp = (i2 + i3) + 1;
      pz1lm->data[a1_data_tmp].re = 0.0;
      pz1lm->data[a1_data_tmp].im = 0.0;
    }

    i2 = r6->size[0] * r6->size[1] - 1;
    if (i2 + 2 > 3) {
      i2 = -1;
      i3 = -1;
    } else {
      i3 = 2;
    }

    loop_ub = i3 - i2;
    for (i3 = 0; i3 < loop_ub; i3++) {
      pz1lmw->data[(i2 + i3) + 1] = 0.0;
    }
  }

  emxFree_real_T(&r6);
  if ((pz2lm->size[0] == 0) || (pz2lm->size[1] == 0)) {
    a1_data_tmp = 0;
  } else {
    a1_data_tmp = pz2lm->size[1];
  }

  if (a1_data_tmp < 3) {
    i2 = pz2lm->size[0] * pz2lm->size[1] - 1;
    if (i2 + 2 > 3) {
      i2 = -1;
      i3 = -1;
    } else {
      i3 = 2;
    }

    loop_ub = i3 - i2;
    for (i3 = 0; i3 < loop_ub; i3++) {
      a1_data_tmp = (i2 + i3) + 1;
      pz2lm->data[a1_data_tmp].re = 0.0;
      pz2lm->data[a1_data_tmp].im = 0.0;
    }

    i2 = r7->size[0] * r7->size[1] - 1;
    if (i2 + 2 > 3) {
      i2 = -1;
      i3 = -1;
    } else {
      i3 = 2;
    }

    loop_ub = i3 - i2;
    for (i3 = 0; i3 < loop_ub; i3++) {
      pz2lmw->data[(i2 + i3) + 1] = 0.0;
    }
  }

  emxFree_real_T(&r7);
  if ((ph1lm->size[0] == 0) || (ph1lm->size[1] == 0)) {
    a1_data_tmp = 0;
  } else {
    a1_data_tmp = ph1lm->size[1];
  }

  if (a1_data_tmp < 3) {
    i2 = ph1lm->size[0] * ph1lm->size[1] - 1;
    if (i2 + 2 > 3) {
      i2 = -1;
      i3 = -1;
    } else {
      i3 = 2;
    }

    loop_ub = i3 - i2;
    for (i3 = 0; i3 < loop_ub; i3++) {
      a1_data_tmp = (i2 + i3) + 1;
      ph1lm->data[a1_data_tmp].re = 0.0;
      ph1lm->data[a1_data_tmp].im = 0.0;
    }

    i2 = r8->size[0] * r8->size[1] - 1;
    if (i2 + 2 > 3) {
      i2 = -1;
      i3 = -1;
    } else {
      i3 = 2;
    }

    loop_ub = i3 - i2;
    for (i3 = 0; i3 < loop_ub; i3++) {
      ph1lmw->data[(i2 + i3) + 1] = 0.0;
    }
  }

  emxFree_real_T(&r8);
  if ((ph2lm->size[0] == 0) || (ph2lm->size[1] == 0)) {
    a1_data_tmp = 0;
  } else {
    a1_data_tmp = ph2lm->size[1];
  }

  if (a1_data_tmp < 3) {
    i2 = ph2lm->size[0] * ph2lm->size[1] - 1;
    if (i2 + 2 > 3) {
      i2 = -1;
      i3 = -1;
    } else {
      i3 = 2;
    }

    loop_ub = i3 - i2;
    for (i3 = 0; i3 < loop_ub; i3++) {
      a1_data_tmp = (i2 + i3) + 1;
      ph2lm->data[a1_data_tmp].re = 0.0;
      ph2lm->data[a1_data_tmp].im = 0.0;
    }

    i2 = r9->size[0] * r9->size[1] - 1;
    if (i2 + 2 > 3) {
      i2 = -1;
      i3 = -1;
    } else {
      i3 = 2;
    }

    loop_ub = i3 - i2;
    for (i3 = 0; i3 < loop_ub; i3++) {
      ph2lmw->data[(i2 + i3) + 1] = 0.0;
    }
  }

  emxFree_real_T(&r9);
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
  a1_size[0] = 1;
  a1_size[1] = 125;
  emxFree_real_T(&ph2lmw);
  emxFree_creal_T(&ph2lm);
  emxFree_real_T(&ph1lmw);
  emxFree_creal_T(&ph1lm);
  emxFree_real_T(&pz2lmw);
  emxFree_creal_T(&pz2lm);
  emxFree_real_T(&pz1lmw);
  emxFree_creal_T(&pz1lm);
  for (i2 = 0; i2 < 125; i2++) {
    b_a1_data[i2] = a1_data[2 + 3 * i2];
  }

  xcorr(b_a1_data, a1_size, acorz1_data, b_a1_size, lh2l_data, tmp_size);
  a1_data_tmp = tmp_size[0] * tmp_size[1];
  for (i2 = 0; i2 < a1_data_tmp; i2++) {
    lz1_data[i2] = lh2l_data[i2] / sf;
  }

  emxInit_int32_T(&acorz1_tmp, 2);
  i2 = acorz1_tmp->size[0] * acorz1_tmp->size[1];
  acorz1_tmp->size[0] = 1;
  acorz1_tmp->size[1] = 124;
  emxEnsureCapacity_int32_T(acorz1_tmp, i2);
  for (i2 = 0; i2 < 124; i2++) {
    acorz1_tmp->data[i2] = 1 + i2;
  }

  emxInit_real_T(&lxz, 2);
  i2 = lxz->size[0] * lxz->size[1];
  lxz->size[0] = 1;
  lxz->size[1] = b_a1_size[1];
  emxEnsureCapacity_real_T(lxz, i2);
  a1_data_tmp = b_a1_size[0] * b_a1_size[1];
  for (i2 = 0; i2 < a1_data_tmp; i2++) {
    lxz->data[i2] = acorz1_data[i2];
  }

  d_nullAssignment(lxz, acorz1_tmp);
  acorz1_size[0] = 1;
  acorz1_size[1] = lxz->size[1];
  loop_ub = lxz->size[0] * lxz->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_acorz1_data[i2] = lxz->data[i2];
  }

  i2 = lxz->size[0] * lxz->size[1];
  lxz->size[0] = 1;
  lxz->size[1] = tmp_size[1];
  emxEnsureCapacity_real_T(lxz, i2);
  loop_ub = tmp_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    lxz->data[i2] = lz1_data[i2];
  }

  c_tmp_size[0] = 1;
  a1_data_tmp = static_cast<int>(std::floor(((static_cast<double>(tmp_size[1]) +
    1.0) / 2.0 - 1.0) - 1.0));
  c_tmp_size[1] = a1_data_tmp + 1;
  for (i2 = 0; i2 <= a1_data_tmp; i2++) {
    e_tmp_data[i2] = i2 + 1;
  }

  d_tmp_data.data = &e_tmp_data[0];
  d_tmp_data.size = &c_tmp_size[0];
  d_tmp_data.allocatedSize = 2109;
  d_tmp_data.numDimensions = 2;
  d_tmp_data.canFreeData = false;
  d_nullAssignment(lxz, &d_tmp_data);
  loop_ub = lxz->size[0] * lxz->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    lz1_data[i2] = lxz->data[i2];
  }

  loop_ub = a2_size[1];
  aa_size[0] = 1;
  aa_size[1] = a2_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    aa_data[i2] = a2_data[2 + 3 * i2];
  }

  xcorr(aa_data, aa_size, acorz2_data, acorz2_size, lz2_data, b_a1_size);
  loop_ub = b_a1_size[0] * b_a1_size[1] - 1;
  for (i2 = 0; i2 <= loop_ub; i2++) {
    lz2_data[i2] /= sf;
  }

  i2 = lxz->size[0] * lxz->size[1];
  lxz->size[0] = 1;
  lxz->size[1] = acorz2_size[1];
  emxEnsureCapacity_real_T(lxz, i2);
  loop_ub = acorz2_size[0] * acorz2_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    lxz->data[i2] = acorz2_data[i2];
  }

  d0 = (static_cast<double>(acorz2_size[1]) + 1.0) / 2.0 - 1.0;
  d_tmp_size[0] = 1;
  a1_data_tmp = static_cast<int>(std::floor(d0 - 1.0));
  d_tmp_size[1] = a1_data_tmp + 1;
  for (i2 = 0; i2 <= a1_data_tmp; i2++) {
    g_tmp_data[i2] = i2 + 1;
  }

  f_tmp_data.data = &g_tmp_data[0];
  f_tmp_data.size = &d_tmp_size[0];
  f_tmp_data.allocatedSize = 312;
  f_tmp_data.numDimensions = 2;
  f_tmp_data.canFreeData = false;
  d_nullAssignment(lxz, &f_tmp_data);
  acorz2_size[0] = 1;
  acorz2_size[1] = lxz->size[1];
  loop_ub = lxz->size[0] * lxz->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    acorz2_data[i2] = lxz->data[i2];
  }

  i2 = lxz->size[0] * lxz->size[1];
  lxz->size[0] = 1;
  lxz->size[1] = b_a1_size[1];
  emxEnsureCapacity_real_T(lxz, i2);
  loop_ub = b_a1_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    lxz->data[i2] = lz2_data[i2];
  }

  e_tmp_size[0] = 1;
  a1_data_tmp = static_cast<int>(std::floor(((static_cast<double>(b_a1_size[1])
    + 1.0) / 2.0 - 1.0) - 1.0));
  e_tmp_size[1] = a1_data_tmp + 1;
  for (i2 = 0; i2 <= a1_data_tmp; i2++) {
    i_tmp_data[i2] = i2 + 1;
  }

  h_tmp_data.data = &i_tmp_data[0];
  h_tmp_data.size = &e_tmp_size[0];
  h_tmp_data.allocatedSize = 2203;
  h_tmp_data.numDimensions = 2;
  h_tmp_data.canFreeData = false;
  d_nullAssignment(lxz, &h_tmp_data);
  loop_ub = lxz->size[0] * lxz->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    lz2_data[i2] = lxz->data[i2];
  }

  xcorr(h1_data, h1_size, acorz1_data, b_a1_size, lh2l_data, tmp_size);
  loop_ub = tmp_size[0] * tmp_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    lh1_data[i2] = lh2l_data[i2] / sf;
  }

  i2 = lxz->size[0] * lxz->size[1];
  lxz->size[0] = 1;
  lxz->size[1] = b_a1_size[1];
  emxEnsureCapacity_real_T(lxz, i2);
  loop_ub = b_a1_size[0] * b_a1_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    lxz->data[i2] = acorz1_data[i2];
  }

  d_nullAssignment(lxz, acorz1_tmp);
  acorh1_size_idx_1 = lxz->size[1];
  loop_ub = lxz->size[0] * lxz->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    acorh1_data[i2] = lxz->data[i2];
  }

  i2 = lxz->size[0] * lxz->size[1];
  lxz->size[0] = 1;
  lxz->size[1] = tmp_size[1];
  emxEnsureCapacity_real_T(lxz, i2);
  loop_ub = tmp_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    lxz->data[i2] = lh1_data[i2];
  }

  c_tmp_size[0] = 1;
  a1_data_tmp = static_cast<int>(std::floor(((static_cast<double>(tmp_size[1]) +
    1.0) / 2.0 - 1.0) - 1.0));
  c_tmp_size[1] = a1_data_tmp + 1;
  for (i2 = 0; i2 <= a1_data_tmp; i2++) {
    e_tmp_data[i2] = i2 + 1;
  }

  j_tmp_data.data = &e_tmp_data[0];
  j_tmp_data.size = &c_tmp_size[0];
  j_tmp_data.allocatedSize = 2109;
  j_tmp_data.numDimensions = 2;
  j_tmp_data.canFreeData = false;
  d_nullAssignment(lxz, &j_tmp_data);
  loop_ub = lxz->size[0] * lxz->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    lh1_data[i2] = lxz->data[i2];
  }

  xcorr(h2_data, h2_size, acorz1_data, b_a1_size, lh2_data, b_a2_size);
  loop_ub = b_a2_size[0] * b_a2_size[1] - 1;
  for (i2 = 0; i2 <= loop_ub; i2++) {
    lh2_data[i2] /= sf;
  }

  i2 = lxz->size[0] * lxz->size[1];
  lxz->size[0] = 1;
  lxz->size[1] = b_a1_size[1];
  emxEnsureCapacity_real_T(lxz, i2);
  loop_ub = b_a1_size[0] * b_a1_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    lxz->data[i2] = acorz1_data[i2];
  }

  d_tmp_size[0] = 1;
  a1_data_tmp = static_cast<int>(std::floor(((static_cast<double>(b_a1_size[1])
    + 1.0) / 2.0 - 1.0) - 1.0));
  d_tmp_size[1] = a1_data_tmp + 1;
  for (i2 = 0; i2 <= a1_data_tmp; i2++) {
    g_tmp_data[i2] = i2 + 1;
  }

  k_tmp_data.data = &g_tmp_data[0];
  k_tmp_data.size = &d_tmp_size[0];
  k_tmp_data.allocatedSize = 312;
  k_tmp_data.numDimensions = 2;
  k_tmp_data.canFreeData = false;
  d_nullAssignment(lxz, &k_tmp_data);
  b_a1_size[1] = lxz->size[1];
  loop_ub = lxz->size[0] * lxz->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    acorz1_data[i2] = lxz->data[i2];
  }

  i2 = lxz->size[0] * lxz->size[1];
  lxz->size[0] = 1;
  lxz->size[1] = b_a2_size[1];
  emxEnsureCapacity_real_T(lxz, i2);
  loop_ub = b_a2_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    lxz->data[i2] = lh2_data[i2];
  }

  e_tmp_size[0] = 1;
  a1_data_tmp = static_cast<int>(std::floor(((static_cast<double>(b_a2_size[1])
    + 1.0) / 2.0 - 1.0) - 1.0));
  e_tmp_size[1] = a1_data_tmp + 1;
  for (i2 = 0; i2 <= a1_data_tmp; i2++) {
    i_tmp_data[i2] = i2 + 1;
  }

  l_tmp_data.data = &i_tmp_data[0];
  l_tmp_data.size = &e_tmp_size[0];
  l_tmp_data.allocatedSize = 2203;
  l_tmp_data.numDimensions = 2;
  l_tmp_data.canFreeData = false;
  d_nullAssignment(lxz, &l_tmp_data);
  loop_ub = lxz->size[0] * lxz->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    lh2_data[i2] = lxz->data[i2];
  }

  emxInit_real_T(&acorz1l, 2);

  /*  autocorrelation of lowpass signals */
  f_z1l_data.data = &z1l_data[0];
  f_z1l_data.size = &z1l_size[0];
  f_z1l_data.allocatedSize = 125;
  f_z1l_data.numDimensions = 2;
  f_z1l_data.canFreeData = false;
  c_xcorr(&f_z1l_data, acorz1l, lh2l_data, tmp_size);
  loop_ub = tmp_size[0] * tmp_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    lz1l_data[i2] = lh2l_data[i2] / sf;
  }

  emxInit_real_T(&acorh2l, 2);
  i2 = acorh2l->size[0] * acorh2l->size[1];
  acorh2l->size[0] = acorz1l->size[0];
  acorh2l->size[1] = acorz1l->size[1];
  emxEnsureCapacity_real_T(acorh2l, i2);
  loop_ub = acorz1l->size[0] * acorz1l->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    acorh2l->data[i2] = acorz1l->data[i2];
  }

  f_tmp_size[0] = 1;
  f_tmp_size[1] = 124;
  for (i2 = 0; i2 < 124; i2++) {
    m_tmp_data[i2] = 1 + i2;
  }

  emxInit_real_T(&b_acorz1l, 2);
  n_tmp_data.data = &m_tmp_data[0];
  n_tmp_data.size = &f_tmp_size[0];
  n_tmp_data.allocatedSize = 124;
  n_tmp_data.numDimensions = 2;
  n_tmp_data.canFreeData = false;
  e_nullAssignment(acorh2l, &n_tmp_data);
  i2 = b_acorz1l->size[0] * b_acorz1l->size[1];
  b_acorz1l->size[0] = acorh2l->size[0];
  b_acorz1l->size[1] = acorh2l->size[1];
  emxEnsureCapacity_real_T(b_acorz1l, i2);
  loop_ub = acorh2l->size[0] * acorh2l->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_acorz1l->data[i2] = acorh2l->data[i2];
  }

  i2 = lxz->size[0] * lxz->size[1];
  lxz->size[0] = 1;
  lxz->size[1] = tmp_size[1];
  emxEnsureCapacity_real_T(lxz, i2);
  loop_ub = tmp_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    lxz->data[i2] = lz1l_data[i2];
  }

  c_tmp_size[0] = 1;
  a1_data_tmp = static_cast<int>(std::floor(((static_cast<double>(tmp_size[1]) +
    1.0) / 2.0 - 1.0) - 1.0));
  c_tmp_size[1] = a1_data_tmp + 1;
  for (i2 = 0; i2 <= a1_data_tmp; i2++) {
    e_tmp_data[i2] = i2 + 1;
  }

  o_tmp_data.data = &e_tmp_data[0];
  o_tmp_data.size = &c_tmp_size[0];
  o_tmp_data.allocatedSize = 2109;
  o_tmp_data.numDimensions = 2;
  o_tmp_data.canFreeData = false;
  d_nullAssignment(lxz, &o_tmp_data);
  loop_ub = lxz->size[0] * lxz->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    lz1l_data[i2] = lxz->data[i2];
  }

  c_xcorr(z2l, acorz1l, lz2l_data, lz2l_size);
  loop_ub = lz2l_size[0] * lz2l_size[1] - 1;
  for (i2 = 0; i2 <= loop_ub; i2++) {
    lz2l_data[i2] /= sf;
  }

  emxInit_real_T(&acorz2l, 2);
  i2 = acorz2l->size[0] * acorz2l->size[1];
  acorz2l->size[0] = acorz1l->size[0];
  acorz2l->size[1] = acorz1l->size[1];
  emxEnsureCapacity_real_T(acorz2l, i2);
  loop_ub = acorz1l->size[0] * acorz1l->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    acorz2l->data[i2] = acorz1l->data[i2];
  }

  emxInit_int32_T(&r10, 2);
  d0 = (static_cast<double>((acorz1l->size[0] * acorz1l->size[1])) + 1.0) / 2.0
    - 1.0;
  i2 = r10->size[0] * r10->size[1];
  r10->size[0] = 1;
  loop_ub = static_cast<int>(std::floor(d0 - 1.0));
  r10->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(r10, i2);
  for (i2 = 0; i2 <= loop_ub; i2++) {
    r10->data[i2] = i2 + 1;
  }

  e_nullAssignment(acorz2l, r10);
  i2 = lxz->size[0] * lxz->size[1];
  lxz->size[0] = 1;
  lxz->size[1] = lz2l_size[1];
  emxEnsureCapacity_real_T(lxz, i2);
  loop_ub = lz2l_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    lxz->data[i2] = lz2l_data[i2];
  }

  e_tmp_size[0] = 1;
  a1_data_tmp = static_cast<int>(std::floor(((static_cast<double>(lz2l_size[1])
    + 1.0) / 2.0 - 1.0) - 1.0));
  e_tmp_size[1] = a1_data_tmp + 1;
  for (i2 = 0; i2 <= a1_data_tmp; i2++) {
    i_tmp_data[i2] = i2 + 1;
  }

  p_tmp_data.data = &i_tmp_data[0];
  p_tmp_data.size = &e_tmp_size[0];
  p_tmp_data.allocatedSize = 2203;
  p_tmp_data.numDimensions = 2;
  p_tmp_data.canFreeData = false;
  d_nullAssignment(lxz, &p_tmp_data);
  loop_ub = lxz->size[0] * lxz->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    lz2l_data[i2] = lxz->data[i2];
  }

  f_h1l_data.data = &h1l_data[0];
  f_h1l_data.size = &h1l_size[0];
  f_h1l_data.allocatedSize = 125;
  f_h1l_data.numDimensions = 2;
  f_h1l_data.canFreeData = false;
  c_xcorr(&f_h1l_data, acorz1l, lh2l_data, tmp_size);
  loop_ub = tmp_size[0] * tmp_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    lh1l_data[i2] = lh2l_data[i2] / sf;
  }

  i2 = acorh2l->size[0] * acorh2l->size[1];
  acorh2l->size[0] = acorz1l->size[0];
  acorh2l->size[1] = acorz1l->size[1];
  emxEnsureCapacity_real_T(acorh2l, i2);
  loop_ub = acorz1l->size[0] * acorz1l->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    acorh2l->data[i2] = acorz1l->data[i2];
  }

  g_tmp_size[0] = 1;
  g_tmp_size[1] = 124;
  for (i2 = 0; i2 < 124; i2++) {
    q_tmp_data[i2] = 1 + i2;
  }

  emxInit_real_T(&acorh1l, 2);
  r_tmp_data.data = &q_tmp_data[0];
  r_tmp_data.size = &g_tmp_size[0];
  r_tmp_data.allocatedSize = 124;
  r_tmp_data.numDimensions = 2;
  r_tmp_data.canFreeData = false;
  e_nullAssignment(acorh2l, &r_tmp_data);
  i2 = acorh1l->size[0] * acorh1l->size[1];
  acorh1l->size[0] = acorh2l->size[0];
  acorh1l->size[1] = acorh2l->size[1];
  emxEnsureCapacity_real_T(acorh1l, i2);
  loop_ub = acorh2l->size[0] * acorh2l->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    acorh1l->data[i2] = acorh2l->data[i2];
  }

  i2 = lxz->size[0] * lxz->size[1];
  lxz->size[0] = 1;
  lxz->size[1] = tmp_size[1];
  emxEnsureCapacity_real_T(lxz, i2);
  loop_ub = tmp_size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    lxz->data[i2] = lh1l_data[i2];
  }

  c_tmp_size[0] = 1;
  a1_data_tmp = static_cast<int>(std::floor(((static_cast<double>(tmp_size[1]) +
    1.0) / 2.0 - 1.0) - 1.0));
  c_tmp_size[1] = a1_data_tmp + 1;
  for (i2 = 0; i2 <= a1_data_tmp; i2++) {
    e_tmp_data[i2] = i2 + 1;
  }

  s_tmp_data.data = &e_tmp_data[0];
  s_tmp_data.size = &c_tmp_size[0];
  s_tmp_data.allocatedSize = 2109;
  s_tmp_data.numDimensions = 2;
  s_tmp_data.canFreeData = false;
  d_nullAssignment(lxz, &s_tmp_data);
  loop_ub = lxz->size[0] * lxz->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    lh1l_data[i2] = lxz->data[i2];
  }

  c_xcorr(h2l, acorz1l, lh2l_data, tmp_size);
  loop_ub = tmp_size[0] * tmp_size[1] - 1;
  for (i2 = 0; i2 <= loop_ub; i2++) {
    lh2l_data[i2] /= sf;
  }

  i2 = acorh2l->size[0] * acorh2l->size[1];
  acorh2l->size[0] = acorz1l->size[0];
  acorh2l->size[1] = acorz1l->size[1];
  emxEnsureCapacity_real_T(acorh2l, i2);
  loop_ub = acorz1l->size[0] * acorz1l->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    acorh2l->data[i2] = acorz1l->data[i2];
  }

  d0 = (static_cast<double>((acorz1l->size[0] * acorz1l->size[1])) + 1.0) / 2.0
    - 1.0;
  i2 = r10->size[0] * r10->size[1];
  r10->size[0] = 1;
  loop_ub = static_cast<int>(std::floor(d0 - 1.0));
  r10->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(r10, i2);
  emxFree_real_T(&acorz1l);
  for (i2 = 0; i2 <= loop_ub; i2++) {
    r10->data[i2] = i2 + 1;
  }

  e_nullAssignment(acorh2l, r10);
  i2 = lxz->size[0] * lxz->size[1];
  lxz->size[0] = 1;
  lxz->size[1] = tmp_size[1];
  emxEnsureCapacity_real_T(lxz, i2);
  loop_ub = tmp_size[1];
  emxFree_int32_T(&r10);
  for (i2 = 0; i2 < loop_ub; i2++) {
    lxz->data[i2] = lh2l_data[i2];
  }

  e_tmp_size[0] = 1;
  a1_data_tmp = static_cast<int>(std::floor(((static_cast<double>(tmp_size[1]) +
    1.0) / 2.0 - 1.0) - 1.0));
  e_tmp_size[1] = a1_data_tmp + 1;
  for (i2 = 0; i2 <= a1_data_tmp; i2++) {
    i_tmp_data[i2] = i2 + 1;
  }

  t_tmp_data.data = &i_tmp_data[0];
  t_tmp_data.size = &e_tmp_size[0];
  t_tmp_data.allocatedSize = 2203;
  t_tmp_data.numDimensions = 2;
  t_tmp_data.canFreeData = false;
  d_nullAssignment(lxz, &t_tmp_data);
  loop_ub = lxz->size[0] * lxz->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    lh2l_data[i2] = lxz->data[i2];
  }

  /*  get height at 0 lag and height/lag at first peak for raw */
  /*  require first peak be at least 0.3 s past 0 */
  minSample = std::floor(0.3 * sf);
  if (minSample > acorz1_size[1]) {
    i2 = 0;
    i3 = 0;
  } else {
    i2 = static_cast<int>(minSample) - 1;
    i3 = acorz1_size[1];
  }

  b_acorz1_size[0] = 1;
  a1_data_tmp = i3 - i2;
  b_acorz1_size[1] = a1_data_tmp;
  for (i3 = 0; i3 < a1_data_tmp; i3++) {
    c_acorz1_data[i3] = b_acorz1_data[i2 + i3];
  }

  emxInit_real_T(&ip, 2);
  d_acorz1_data.data = &c_acorz1_data[0];
  d_acorz1_data.size = &b_acorz1_size[0];
  d_acorz1_data.allocatedSize = 249;
  d_acorz1_data.numDimensions = 2;
  d_acorz1_data.canFreeData = false;
  b_extrema(&d_acorz1_data, ipz1m, ip);
  i2 = ip->size[0] * ip->size[1];
  i3 = ip->size[0] * ip->size[1];
  emxEnsureCapacity_real_T(ip, i3);
  loop_ub = i2 - 1;
  for (i2 = 0; i2 <= loop_ub; i2++) {
    ip->data[i2] = (ip->data[i2] + minSample) - 1.0;
  }

  feat[76] = b_acorz1_data[0];
  feat[77] = ipz1m->data[0];
  feat[78] = lz1_data[static_cast<int>(ip->data[0]) - 1];
  if (minSample > acorz2_size[1]) {
    i2 = 0;
    i3 = 0;
  } else {
    i2 = static_cast<int>(minSample) - 1;
    i3 = acorz2_size[1];
  }

  b_acorz2_size[0] = 1;
  a1_data_tmp = i3 - i2;
  b_acorz2_size[1] = a1_data_tmp;
  for (i3 = 0; i3 < a1_data_tmp; i3++) {
    c_acorz2_data[i3] = acorz2_data[i2 + i3];
  }

  b_acorz2_data.data = &c_acorz2_data[0];
  b_acorz2_data.size = &b_acorz2_size[0];
  b_acorz2_data.allocatedSize = 625;
  b_acorz2_data.numDimensions = 2;
  b_acorz2_data.canFreeData = false;
  b_extrema(&b_acorz2_data, ipz1m, ip);
  i2 = ip->size[0] * ip->size[1];
  i3 = ip->size[0] * ip->size[1];
  emxEnsureCapacity_real_T(ip, i3);
  loop_ub = i2 - 1;
  for (i2 = 0; i2 <= loop_ub; i2++) {
    ip->data[i2] = (ip->data[i2] + minSample) - 1.0;
  }

  feat[79] = acorz2_data[0];
  feat[80] = ipz1m->data[0];
  feat[81] = lz2_data[static_cast<int>(ip->data[0]) - 1];
  if (minSample > acorh1_size_idx_1) {
    i2 = 0;
    acorh1_size_idx_1 = 0;
  } else {
    i2 = static_cast<int>(minSample) - 1;
  }

  acorz1_size[0] = 1;
  a1_data_tmp = acorh1_size_idx_1 - i2;
  acorz1_size[1] = a1_data_tmp;
  for (i3 = 0; i3 < a1_data_tmp; i3++) {
    b_acorz1_data[i3] = acorh1_data[i2 + i3];
  }

  e_acorz1_data.data = &b_acorz1_data[0];
  e_acorz1_data.size = &acorz1_size[0];
  e_acorz1_data.allocatedSize = 249;
  e_acorz1_data.numDimensions = 2;
  e_acorz1_data.canFreeData = false;
  b_extrema(&e_acorz1_data, ipz1m, ip);
  i2 = ip->size[0] * ip->size[1];
  i3 = ip->size[0] * ip->size[1];
  emxEnsureCapacity_real_T(ip, i3);
  loop_ub = i2 - 1;
  for (i2 = 0; i2 <= loop_ub; i2++) {
    ip->data[i2] = (ip->data[i2] + minSample) - 1.0;
  }

  feat[82] = acorh1_data[0];
  feat[83] = ipz1m->data[0];
  feat[84] = lh1_data[static_cast<int>(ip->data[0]) - 1];
  if (minSample > b_a1_size[1]) {
    i2 = 0;
    i3 = 0;
  } else {
    i2 = static_cast<int>(minSample) - 1;
    i3 = b_a1_size[1];
  }

  acorz2_size[0] = 1;
  a1_data_tmp = i3 - i2;
  acorz2_size[1] = a1_data_tmp;
  for (i3 = 0; i3 < a1_data_tmp; i3++) {
    acorz2_data[i3] = acorz1_data[i2 + i3];
  }

  d_acorz2_data.data = &acorz2_data[0];
  d_acorz2_data.size = &acorz2_size[0];
  d_acorz2_data.allocatedSize = 625;
  d_acorz2_data.numDimensions = 2;
  d_acorz2_data.canFreeData = false;
  b_extrema(&d_acorz2_data, ipz1m, ip);
  i2 = ip->size[0] * ip->size[1];
  i3 = ip->size[0] * ip->size[1];
  emxEnsureCapacity_real_T(ip, i3);
  loop_ub = i2 - 1;
  for (i2 = 0; i2 <= loop_ub; i2++) {
    ip->data[i2] = (ip->data[i2] + minSample) - 1.0;
  }

  feat[85] = acorz1_data[0];
  feat[86] = ipz1m->data[0];
  feat[87] = lh2_data[static_cast<int>(ip->data[0]) - 1];

  /*  get height at 0 lag and height/lag at first peak for lowpass */
  i2 = b_acorz1l->size[0] * b_acorz1l->size[1];
  if (minSample > i2) {
    i3 = 0;
    i2 = 0;
  } else {
    i3 = static_cast<int>(minSample) - 1;
  }

  emxInit_real_T(&c_acorz1l, 2);
  a1_data_tmp = c_acorz1l->size[0] * c_acorz1l->size[1];
  c_acorz1l->size[0] = 1;
  loop_ub = i2 - i3;
  c_acorz1l->size[1] = loop_ub;
  emxEnsureCapacity_real_T(c_acorz1l, a1_data_tmp);
  for (i2 = 0; i2 < loop_ub; i2++) {
    c_acorz1l->data[i2] = b_acorz1l->data[i3 + i2];
  }

  b_extrema(c_acorz1l, ipz1m, ip);
  i2 = ip->size[0] * ip->size[1];
  i3 = ip->size[0] * ip->size[1];
  emxEnsureCapacity_real_T(ip, i3);
  loop_ub = i2 - 1;
  for (i2 = 0; i2 <= loop_ub; i2++) {
    ip->data[i2] = (ip->data[i2] + minSample) - 1.0;
  }

  feat[88] = b_acorz1l->data[0];
  feat[89] = ipz1m->data[0];
  feat[90] = lz1l_data[static_cast<int>(ip->data[0]) - 1];
  i2 = acorz2l->size[0] * acorz2l->size[1];
  emxFree_real_T(&b_acorz1l);
  if (minSample > i2) {
    i3 = 0;
    i2 = 0;
  } else {
    i3 = static_cast<int>(minSample) - 1;
  }

  a1_data_tmp = lxz->size[0] * lxz->size[1];
  lxz->size[0] = 1;
  loop_ub = i2 - i3;
  lxz->size[1] = loop_ub;
  emxEnsureCapacity_real_T(lxz, a1_data_tmp);
  for (i2 = 0; i2 < loop_ub; i2++) {
    lxz->data[i2] = acorz2l->data[i3 + i2];
  }

  b_extrema(lxz, ipz1m, ip);
  i2 = ip->size[0] * ip->size[1];
  i3 = ip->size[0] * ip->size[1];
  emxEnsureCapacity_real_T(ip, i3);
  loop_ub = i2 - 1;
  for (i2 = 0; i2 <= loop_ub; i2++) {
    ip->data[i2] = (ip->data[i2] + minSample) - 1.0;
  }

  feat[91] = acorz2l->data[0];
  feat[92] = ipz1m->data[0];
  feat[93] = lz2l_data[static_cast<int>(ip->data[0]) - 1];
  i2 = acorh1l->size[0] * acorh1l->size[1];
  emxFree_real_T(&acorz2l);
  if (minSample > i2) {
    i3 = 0;
    i2 = 0;
  } else {
    i3 = static_cast<int>(minSample) - 1;
  }

  a1_data_tmp = c_acorz1l->size[0] * c_acorz1l->size[1];
  c_acorz1l->size[0] = 1;
  loop_ub = i2 - i3;
  c_acorz1l->size[1] = loop_ub;
  emxEnsureCapacity_real_T(c_acorz1l, a1_data_tmp);
  for (i2 = 0; i2 < loop_ub; i2++) {
    c_acorz1l->data[i2] = acorh1l->data[i3 + i2];
  }

  b_extrema(c_acorz1l, ipz1m, ip);
  i2 = ip->size[0] * ip->size[1];
  i3 = ip->size[0] * ip->size[1];
  emxEnsureCapacity_real_T(ip, i3);
  loop_ub = i2 - 1;
  emxFree_real_T(&c_acorz1l);
  for (i2 = 0; i2 <= loop_ub; i2++) {
    ip->data[i2] = (ip->data[i2] + minSample) - 1.0;
  }

  feat[94] = acorh1l->data[0];
  feat[95] = ipz1m->data[0];
  feat[96] = lh1l_data[static_cast<int>(ip->data[0]) - 1];
  i2 = acorh2l->size[0] * acorh2l->size[1];
  emxFree_real_T(&acorh1l);
  if (minSample > i2) {
    i3 = 0;
    i2 = 0;
  } else {
    i3 = static_cast<int>(minSample) - 1;
  }

  a1_data_tmp = lxz->size[0] * lxz->size[1];
  lxz->size[0] = 1;
  loop_ub = i2 - i3;
  lxz->size[1] = loop_ub;
  emxEnsureCapacity_real_T(lxz, a1_data_tmp);
  for (i2 = 0; i2 < loop_ub; i2++) {
    lxz->data[i2] = acorh2l->data[i3 + i2];
  }

  b_extrema(lxz, ipz1m, ip);
  i2 = ip->size[0] * ip->size[1];
  i3 = ip->size[0] * ip->size[1];
  emxEnsureCapacity_real_T(ip, i3);
  loop_ub = i2 - 1;
  for (i2 = 0; i2 <= loop_ub; i2++) {
    ip->data[i2] = (ip->data[i2] + minSample) - 1.0;
  }

  emxInit_real_T(&xz, 1);
  feat[97] = acorh2l->data[0];
  feat[98] = ipz1m->data[0];
  feat[99] = lh2l_data[static_cast<int>(ip->data[0]) - 1];

  /*  cross correlation of lowpass sigs z1l-z2l, h2l-h2l */
  d_xcorr(z1l_data, z1l_size, z2l, xz, lxz);
  i2 = lxz->size[0] * lxz->size[1];
  i3 = lxz->size[0] * lxz->size[1];
  lxz->size[0] = 1;
  emxEnsureCapacity_real_T(lxz, i3);
  loop_ub = i2 - 1;
  emxFree_real_T(&acorh2l);
  emxFree_real_T(&z2l);
  for (i2 = 0; i2 <= loop_ub; i2++) {
    lxz->data[i2] /= sf;
  }

  emxInit_real_T(&r11, 1);
  i2 = r11->size[0];
  r11->size[0] = xz->size[0];
  emxEnsureCapacity_real_T(r11, i2);
  loop_ub = xz->size[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    r11->data[i2] = xz->data[i2];
  }

  emxInit_int32_T(&r12, 2);
  d0 = (static_cast<double>(xz->size[0]) + 1.0) / 2.0 - 1.0;
  i2 = r12->size[0] * r12->size[1];
  r12->size[0] = 1;
  loop_ub = static_cast<int>(std::floor(d0 - 1.0));
  r12->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(r12, i2);
  for (i2 = 0; i2 <= loop_ub; i2++) {
    r12->data[i2] = i2 + 1;
  }

  b_nullAssignment(r11, r12);
  i2 = xz->size[0];
  xz->size[0] = r11->size[0];
  emxEnsureCapacity_real_T(xz, i2);
  loop_ub = r11->size[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    xz->data[i2] = r11->data[i2];
  }

  d0 = (static_cast<double>(lxz->size[1]) + 1.0) / 2.0 - 1.0;
  i2 = acorz1_tmp->size[0] * acorz1_tmp->size[1];
  acorz1_tmp->size[0] = 1;
  loop_ub = static_cast<int>(std::floor(d0 - 1.0));
  acorz1_tmp->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(acorz1_tmp, i2);
  for (i2 = 0; i2 <= loop_ub; i2++) {
    acorz1_tmp->data[i2] = i2 + 1;
  }

  emxInit_real_T(&lxh, 2);
  emxInit_real_T(&xh, 1);
  d_nullAssignment(lxz, acorz1_tmp);
  d_xcorr(h1l_data, h1l_size, h2l, xh, lxh);
  i2 = lxh->size[0] * lxh->size[1];
  i3 = lxh->size[0] * lxh->size[1];
  lxh->size[0] = 1;
  emxEnsureCapacity_real_T(lxh, i3);
  loop_ub = i2 - 1;
  emxFree_real_T(&h2l);
  for (i2 = 0; i2 <= loop_ub; i2++) {
    lxh->data[i2] /= sf;
  }

  i2 = r11->size[0];
  r11->size[0] = xh->size[0];
  emxEnsureCapacity_real_T(r11, i2);
  loop_ub = xh->size[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    r11->data[i2] = xh->data[i2];
  }

  d0 = (static_cast<double>(xh->size[0]) + 1.0) / 2.0 - 1.0;
  i2 = r12->size[0] * r12->size[1];
  r12->size[0] = 1;
  loop_ub = static_cast<int>(std::floor(d0 - 1.0));
  r12->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(r12, i2);
  for (i2 = 0; i2 <= loop_ub; i2++) {
    r12->data[i2] = i2 + 1;
  }

  b_nullAssignment(r11, r12);
  i2 = xh->size[0];
  xh->size[0] = r11->size[0];
  emxEnsureCapacity_real_T(xh, i2);
  loop_ub = r11->size[0];
  emxFree_int32_T(&r12);
  for (i2 = 0; i2 < loop_ub; i2++) {
    xh->data[i2] = r11->data[i2];
  }

  emxFree_real_T(&r11);
  d0 = (static_cast<double>(lxh->size[1]) + 1.0) / 2.0 - 1.0;
  i2 = acorz1_tmp->size[0] * acorz1_tmp->size[1];
  acorz1_tmp->size[0] = 1;
  loop_ub = static_cast<int>(std::floor(d0 - 1.0));
  acorz1_tmp->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(acorz1_tmp, i2);
  for (i2 = 0; i2 <= loop_ub; i2++) {
    acorz1_tmp->data[i2] = i2 + 1;
  }

  d_nullAssignment(lxh, acorz1_tmp);

  /*  get correlation at 0 lag and correlation/lag at first peak */
  /*  require first peak be at least 0.3 s past 0 */
  emxFree_int32_T(&acorz1_tmp);
  if (minSample > xz->size[0]) {
    i2 = 0;
    i3 = 0;
  } else {
    i2 = static_cast<int>(minSample) - 1;
    i3 = xz->size[0];
  }

  emxInit_real_T(&b_xz, 1);
  a1_data_tmp = b_xz->size[0];
  loop_ub = i3 - i2;
  b_xz->size[0] = loop_ub;
  emxEnsureCapacity_real_T(b_xz, a1_data_tmp);
  for (i3 = 0; i3 < loop_ub; i3++) {
    b_xz->data[i3] = xz->data[i2 + i3];
  }

  c_extrema(b_xz, ipz1m, ip);
  i2 = ip->size[0] * ip->size[1];
  i3 = ip->size[0] * ip->size[1];
  emxEnsureCapacity_real_T(ip, i3);
  loop_ub = i2 - 1;
  emxFree_real_T(&b_xz);
  for (i2 = 0; i2 <= loop_ub; i2++) {
    ip->data[i2] = (ip->data[i2] + minSample) - 1.0;
  }

  feat[100] = xz->data[0];
  feat[101] = ipz1m->data[0];
  feat[102] = lxz->data[static_cast<int>(ip->data[0]) - 1];
  emxFree_real_T(&lxz);
  if (minSample > xh->size[0]) {
    i2 = 0;
    i3 = 0;
  } else {
    i2 = static_cast<int>(minSample) - 1;
    i3 = xh->size[0];
  }

  a1_data_tmp = xz->size[0];
  loop_ub = i3 - i2;
  xz->size[0] = loop_ub;
  emxEnsureCapacity_real_T(xz, a1_data_tmp);
  for (i3 = 0; i3 < loop_ub; i3++) {
    xz->data[i3] = xh->data[i2 + i3];
  }

  c_extrema(xz, ipz1m, ip);
  i2 = ip->size[0] * ip->size[1];
  i3 = ip->size[0] * ip->size[1];
  emxEnsureCapacity_real_T(ip, i3);
  loop_ub = i2 - 1;
  emxFree_real_T(&xz);
  for (i2 = 0; i2 <= loop_ub; i2++) {
    ip->data[i2] = (ip->data[i2] + minSample) - 1.0;
  }

  feat[103] = xh->data[0];
  feat[104] = ipz1m->data[0];
  feat[105] = lxh->data[static_cast<int>(ip->data[0]) - 1];
  emxFree_real_T(&ipz1m);
  emxFree_real_T(&xh);
  emxFree_real_T(&lxh);
  emxFree_real_T(&ip);
}

/* End of code generation (get_features.cpp) */

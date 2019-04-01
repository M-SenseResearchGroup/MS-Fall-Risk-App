/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_getFallClass_api.h
 *
 * Code generation for function '_coder_getFallClass_api'
 *
 */

#ifndef _CODER_GETFALLCLASS_API_H
#define _CODER_GETFALLCLASS_API_H

/* Include files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_getFallClass_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void calibrate(real_T x[375], real_T r[9], real_T g, real_T y[375]);
extern void calibrate_api(const mxArray * const prhs[3], int32_T nlhs, const
  mxArray *plhs[1]);
extern void getFallClass_atexit(void);
extern void getFallClass_initialize(void);
extern void getFallClass_terminate(void);
extern void getFallClass_xil_shutdown(void);
extern void getFallClass_xil_terminate(void);
extern void get_calibration(real_T a[939], real_T n, real_T r[9], real_T *g);
extern void get_calibration_api(const mxArray * const prhs[2], int32_T nlhs,
  const mxArray *plhs[2]);
extern void get_classification(real_T feats[106], real_T *label, real_T score[2]);
extern void get_classification_api(const mxArray * const prhs[1], int32_T nlhs,
  const mxArray *plhs[2]);
extern real_T get_fall_class(real_T feat);
extern void get_fall_class_api(const mxArray * const prhs[1], int32_T nlhs,
  const mxArray *plhs[1]);
extern void get_features(real_T a1[375], real_T a2[375], real_T sf, real_T feat
  [106]);
extern void get_features_api(const mxArray * const prhs[3], int32_T nlhs, const
  mxArray *plhs[1]);
extern real_T get_strides(real_T thigh_acc[1500], real_T asf);
extern void get_strides_api(const mxArray * const prhs[2], int32_T nlhs, const
  mxArray *plhs[1]);
extern void pre_process_feats(real_T feats1[106], real_T mu[106], real_T sigma
  [106], real_T pc[742], real_T feats[7]);
extern void pre_process_feats_api(const mxArray * const prhs[4], int32_T nlhs,
  const mxArray *plhs[1]);

#endif

/* End of code generation (_coder_getFallClass_api.h) */

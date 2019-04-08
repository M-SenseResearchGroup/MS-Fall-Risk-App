/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_calc_fall_risk_api.h
 *
 * Code generation for function '_coder_calc_fall_risk_api'
 *
 */

#ifndef _CODER_CALC_FALL_RISK_API_H
#define _CODER_CALC_FALL_RISK_API_H

/* Include files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_calc_fall_risk_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void calc_fall_risk(real_T a_thigh1[375], real_T a_chest1_data[], int32_T
  a_chest1_size[2], real_T a_thigh2[375], real_T a_chest2[375], real_T a_thigh3
  [375], real_T a_chest3[375], real_T a_thigh4[375], real_T a_chest4[375],
  real_T r_thigh[9], real_T g_thigh, real_T r_chest[9], real_T g_chest, real_T
  fs, real_T win_sz, real_T *classify, real_T *wrt_str);
extern void calc_fall_risk_api(const mxArray * const prhs[16], int32_T nlhs,
  const mxArray *plhs[2]);
extern void calc_fall_risk_atexit(void);
extern void calc_fall_risk_initialize(void);
extern void calc_fall_risk_terminate(void);
extern void calc_fall_risk_xil_shutdown(void);
extern void calc_fall_risk_xil_terminate(void);
extern void get_calibration(real_T a[939], real_T n, real_T r[9], real_T *g);
extern void get_calibration_api(const mxArray * const prhs[2], int32_T nlhs,
  const mxArray *plhs[2]);

#endif

/* End of code generation (_coder_calc_fall_risk_api.h) */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_calc_fall_risk_api.c
 *
 * Code generation for function '_coder_calc_fall_risk_api'
 *
 */

/* Include files */
#include "tmwtypes.h"
#include "_coder_calc_fall_risk_api.h"
#include "_coder_calc_fall_risk_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131482U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "calc_fall_risk",                    /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[375];
static const mxArray *b_emlrt_marshallOut(const real_T u[9]);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *a_chest1,
  const char_T *identifier, real_T **y_data, int32_T y_size[2]);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[2]);
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *r_thigh,
  const char_T *identifier))[9];
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *a_thigh1,
  const char_T *identifier))[375];
static const mxArray *emlrt_marshallOut(const real_T u);
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[9];
static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *g_thigh,
  const char_T *identifier);
static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *thigh_buffer,
  const char_T *identifier);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *a, const
  char_T *identifier))[939];
static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[939];
static real_T (*m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[375];
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[2]);
static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[9];
static real_T p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static real_T (*r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[939];

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[375]
{
  real_T (*y)[375];
  y = m_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static const mxArray *b_emlrt_marshallOut(const real_T u[9])
{
  const mxArray *y;
  const mxArray *m1;
  static const int32_T iv0[2] = { 0, 0 };

  static const int32_T iv1[2] = { 3, 3 };

  y = NULL;
  m1 = emlrtCreateNumericArray(2, iv0, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m1, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m1, *(int32_T (*)[2])&iv1[0], 2);
  emlrtAssign(&y, m1);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *a_chest1,
  const char_T *identifier, real_T **y_data, int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  real_T *r0;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(a_chest1), &thisId, &r0, y_size);
  *y_data = r0;
  emlrtDestroyArray(&a_chest1);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[2])
{
  real_T *r1;
  n_emlrt_marshallIn(sp, emlrtAlias(u), parentId, &r1, y_size);
  *y_data = r1;
  emlrtDestroyArray(&u);
}

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *r_thigh,
  const char_T *identifier))[9]
{
  real_T (*y)[9];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(r_thigh), &thisId);
  emlrtDestroyArray(&r_thigh);
  return y;
}
  static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *a_thigh1,
  const char_T *identifier))[375]
{
  real_T (*y)[375];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(a_thigh1), &thisId);
  emlrtDestroyArray(&a_thigh1);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m0;
  y = NULL;
  m0 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m0);
  return y;
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[9]
{
  real_T (*y)[9];
  y = o_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *g_thigh,
  const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = h_emlrt_marshallIn(sp, emlrtAlias(g_thigh), &thisId);
  emlrtDestroyArray(&g_thigh);
  return y;
}

static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = p_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *thigh_buffer,
  const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  j_emlrt_marshallIn(sp, emlrtAlias(thigh_buffer), &thisId);
  emlrtDestroyArray(&thigh_buffer);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  q_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *a, const
  char_T *identifier))[939]
{
  real_T (*y)[939];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = l_emlrt_marshallIn(sp, emlrtAlias(a), &thisId);
  emlrtDestroyArray(&a);
  return y;
}
  static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[939]
{
  real_T (*y)[939];
  y = r_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[375]
{
  real_T (*ret)[375];
  static const int32_T dims[2] = { 3, 125 };

  emlrtCheckBuiltInR2012b(sp, (const emlrtMsgIdentifier *)msgId, src, "double",
    false, 2U, *(int32_T (*)[2])&dims[0]);
  ret = (real_T (*)[375])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[2])
{
  static const int32_T dims[2] = { 3, 313 };

  const boolean_T bv0[2] = { false, true };

  int32_T iv2[2];
  emlrtCheckVsBuiltInR2012b(sp, (const emlrtMsgIdentifier *)msgId, src, "double",
    false, 2U, *(int32_T (*)[2])&dims[0], (boolean_T *)&bv0[0], iv2);
  ret_size[0] = iv2[0];
  ret_size[1] = iv2[1];
  *ret_data = (real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[9]
{
  real_T (*ret)[9];
  static const int32_T dims[2] = { 3, 3 };

  emlrtCheckBuiltInR2012b(sp, (const emlrtMsgIdentifier *)msgId, src, "double",
    false, 2U, *(int32_T (*)[2])&dims[0]);
  ret = (real_T (*)[9])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, (const emlrtMsgIdentifier *)msgId, src, "double",
    false, 0U, (int32_T *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  static const int32_T dims[2] = { 0, 0 };

  emlrtCheckBuiltInR2012b(sp, (const emlrtMsgIdentifier *)msgId, src, "double",
    false, 2U, *(int32_T (*)[2])&dims[0]);
  emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

static real_T (*r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[939]
{
  real_T (*ret)[939];
  static const int32_T dims[2] = { 3, 313 };

  emlrtCheckBuiltInR2012b(sp, (const emlrtMsgIdentifier *)msgId, src, "double",
    false, 2U, *(int32_T (*)[2])&dims[0]);
  ret = (real_T (*)[939])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  void calc_fall_risk_api(const mxArray * const prhs[16], int32_T nlhs, const
  mxArray *plhs[2])
{
  real_T (*a_thigh1)[375];
  real_T (*a_chest1_data)[939];
  int32_T a_chest1_size[2];
  real_T (*a_thigh2)[375];
  real_T (*a_chest2)[375];
  real_T (*a_thigh3)[375];
  real_T (*a_chest3)[375];
  real_T (*a_thigh4)[375];
  real_T (*a_chest4)[375];
  real_T (*r_thigh)[9];
  real_T g_thigh;
  real_T (*r_chest)[9];
  real_T g_chest;
  real_T fs;
  real_T win_sz;
  real_T classify;
  real_T wrt_str;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Marshall function inputs */
  a_thigh1 = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "a_thigh1");
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "a_chest1", (real_T **)
                     &a_chest1_data, a_chest1_size);
  a_thigh2 = emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "a_thigh2");
  a_chest2 = emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "a_chest2");
  a_thigh3 = emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "a_thigh3");
  a_chest3 = emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "a_chest3");
  a_thigh4 = emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "a_thigh4");
  a_chest4 = emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "a_chest4");
  r_thigh = e_emlrt_marshallIn(&st, emlrtAlias(prhs[8]), "r_thigh");
  g_thigh = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[9]), "g_thigh");
  r_chest = e_emlrt_marshallIn(&st, emlrtAlias(prhs[10]), "r_chest");
  g_chest = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[11]), "g_chest");
  fs = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[12]), "fs");
  win_sz = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[13]), "win_sz");
  i_emlrt_marshallIn(&st, emlrtAlias(prhs[14]), "thigh_buffer");
  i_emlrt_marshallIn(&st, emlrtAlias(prhs[15]), "chest_buffer");

  /* Invoke the target function */
  calc_fall_risk(*a_thigh1, *a_chest1_data, a_chest1_size, *a_thigh2, *a_chest2,
                 *a_thigh3, *a_chest3, *a_thigh4, *a_chest4, *r_thigh, g_thigh, *
                 r_chest, g_chest, fs, win_sz, &classify, &wrt_str);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(classify);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(wrt_str);
  }
}

void calc_fall_risk_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  calc_fall_risk_xil_terminate();
  calc_fall_risk_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void calc_fall_risk_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

void calc_fall_risk_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void get_calibration_api(const mxArray * const prhs[2], int32_T nlhs, const
  mxArray *plhs[2])
{
  real_T (*r)[9];
  real_T (*a)[939];
  real_T n;
  real_T g;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  r = (real_T (*)[9])mxMalloc(sizeof(real_T [9]));

  /* Marshall function inputs */
  a = k_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "a");
  n = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "n");

  /* Invoke the target function */
  get_calibration(*a, n, *r, &g);

  /* Marshall function outputs */
  plhs[0] = b_emlrt_marshallOut(*r);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(g);
  }
}

/* End of code generation (_coder_calc_fall_risk_api.c) */

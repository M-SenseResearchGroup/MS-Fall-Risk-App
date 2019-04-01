/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_getFallClass_api.c
 *
 * Code generation for function '_coder_getFallClass_api'
 *
 */

/* Include files */
#include "tmwtypes.h"
#include "_coder_getFallClass_api.h"
#include "_coder_getFallClass_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131482U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "getFallClass",                      /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[375];
static const mxArray *b_emlrt_marshallOut(const real_T u[9]);
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *r, const
  char_T *identifier))[9];
static const mxArray *c_emlrt_marshallOut(const real_T u);
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[9];
static const mxArray *d_emlrt_marshallOut(const real_T u[2]);
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *g, const
  char_T *identifier);
static const mxArray *e_emlrt_marshallOut(const real_T u[106]);
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *x, const
  char_T *identifier))[375];
static const mxArray *emlrt_marshallOut(const real_T u[375]);
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static const mxArray *f_emlrt_marshallOut(const real_T u[7]);
static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *a, const
  char_T *identifier))[939];
static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[939];
static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *feats,
  const char_T *identifier))[106];
static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[106];
static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *thigh_acc, const char_T *identifier))[1500];
static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[1500];
static real_T (*m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *pc,
  const char_T *identifier))[742];
static real_T (*n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[742];
static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[375];
static real_T (*p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[9];
static real_T q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static real_T (*r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[939];
static real_T (*s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[106];
static real_T (*t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[1500];
static real_T (*u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[742];

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[375]
{
  real_T (*y)[375];
  y = o_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static const mxArray *b_emlrt_marshallOut(const real_T u[9])
{
  const mxArray *y;
  const mxArray *m1;
  static const int32_T iv2[2] = { 0, 0 };

  static const int32_T iv3[2] = { 3, 3 };

  y = NULL;
  m1 = emlrtCreateNumericArray(2, iv2, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m1, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m1, iv3, 2);
  emlrtAssign(&y, m1);
  return y;
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *r, const
  char_T *identifier))[9]
{
  real_T (*y)[9];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(r), &thisId);
  emlrtDestroyArray(&r);
  return y;
}
  static const mxArray *c_emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m2;
  y = NULL;
  m2 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m2);
  return y;
}

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[9]
{
  real_T (*y)[9];
  y = p_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static const mxArray *d_emlrt_marshallOut(const real_T u[2])
{
  const mxArray *y;
  const mxArray *m3;
  static const int32_T iv4[2] = { 0, 0 };

  static const int32_T iv5[2] = { 1, 2 };

  y = NULL;
  m3 = emlrtCreateNumericArray(2, iv4, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m3, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m3, iv5, 2);
  emlrtAssign(&y, m3);
  return y;
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *g, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(g), &thisId);
  emlrtDestroyArray(&g);
  return y;
}

static const mxArray *e_emlrt_marshallOut(const real_T u[106])
{
  const mxArray *y;
  const mxArray *m4;
  static const int32_T iv6[1] = { 0 };

  static const int32_T iv7[1] = { 106 };

  y = NULL;
  m4 = emlrtCreateNumericArray(1, iv6, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m4, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m4, iv7, 1);
  emlrtAssign(&y, m4);
  return y;
}

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *x, const
  char_T *identifier))[375]
{
  real_T (*y)[375];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(x), &thisId);
  emlrtDestroyArray(&x);
  return y;
}
  static const mxArray *emlrt_marshallOut(const real_T u[375])
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[2] = { 0, 0 };

  static const int32_T iv1[2] = { 3, 125 };

  y = NULL;
  m0 = emlrtCreateNumericArray(2, iv0, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m0, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m0, iv1, 2);
  emlrtAssign(&y, m0);
  return y;
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = q_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *f_emlrt_marshallOut(const real_T u[7])
{
  const mxArray *y;
  const mxArray *m5;
  static const int32_T iv8[1] = { 0 };

  static const int32_T iv9[1] = { 7 };

  y = NULL;
  m5 = emlrtCreateNumericArray(1, iv8, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m5, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m5, iv9, 1);
  emlrtAssign(&y, m5);
  return y;
}

static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *a, const
  char_T *identifier))[939]
{
  real_T (*y)[939];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = h_emlrt_marshallIn(sp, emlrtAlias(a), &thisId);
  emlrtDestroyArray(&a);
  return y;
}
  static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[939]
{
  real_T (*y)[939];
  y = r_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *feats,
  const char_T *identifier))[106]
{
  real_T (*y)[106];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = j_emlrt_marshallIn(sp, emlrtAlias(feats), &thisId);
  emlrtDestroyArray(&feats);
  return y;
}
  static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[106]
{
  real_T (*y)[106];
  y = s_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *thigh_acc, const char_T *identifier))[1500]
{
  real_T (*y)[1500];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = l_emlrt_marshallIn(sp, emlrtAlias(thigh_acc), &thisId);
  emlrtDestroyArray(&thigh_acc);
  return y;
}
  static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[1500]
{
  real_T (*y)[1500];
  y = t_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *pc,
  const char_T *identifier))[742]
{
  real_T (*y)[742];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = n_emlrt_marshallIn(sp, emlrtAlias(pc), &thisId);
  emlrtDestroyArray(&pc);
  return y;
}
  static real_T (*n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[742]
{
  real_T (*y)[742];
  y = u_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[375]
{
  real_T (*ret)[375];
  static const int32_T dims[2] = { 3, 125 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[375])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T (*p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[9]
{
  real_T (*ret)[9];
  static const int32_T dims[2] = { 3, 3 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[9])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[939]
{
  real_T (*ret)[939];
  static const int32_T dims[2] = { 3, 313 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[939])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T (*s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[106]
{
  real_T (*ret)[106];
  static const int32_T dims[1] = { 106 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  ret = (real_T (*)[106])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[1500]
{
  real_T (*ret)[1500];
  static const int32_T dims[2] = { 3, 500 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[1500])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T (*u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[742]
{
  real_T (*ret)[742];
  static const int32_T dims[2] = { 106, 7 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[742])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void calibrate_api(const mxArray * const prhs[3], int32_T nlhs, const mxArray
                   *plhs[1])
{
  real_T (*y)[375];
  real_T (*x)[375];
  real_T (*r)[9];
  real_T g;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;
  y = (real_T (*)[375])mxMalloc(sizeof(real_T [375]));

  /* Marshall function inputs */
  x = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "x");
  r = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "r");
  g = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "g");

  /* Invoke the target function */
  calibrate(*x, *r, g, *y);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*y);
}

void getFallClass_atexit(void)
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
  getFallClass_xil_terminate();
  getFallClass_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void getFallClass_initialize(void)
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

void getFallClass_terminate(void)
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
  a = g_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "a");
  n = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "n");

  /* Invoke the target function */
  get_calibration(*a, n, *r, &g);

  /* Marshall function outputs */
  plhs[0] = b_emlrt_marshallOut(*r);
  if (nlhs > 1) {
    plhs[1] = c_emlrt_marshallOut(g);
  }
}

void get_classification_api(const mxArray * const prhs[1], int32_T nlhs, const
  mxArray *plhs[2])
{
  real_T (*score)[2];
  real_T (*feats)[106];
  real_T label;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  score = (real_T (*)[2])mxMalloc(sizeof(real_T [2]));

  /* Marshall function inputs */
  feats = i_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "feats");

  /* Invoke the target function */
  get_classification(*feats, &label, *score);

  /* Marshall function outputs */
  plhs[0] = c_emlrt_marshallOut(label);
  if (nlhs > 1) {
    plhs[1] = d_emlrt_marshallOut(*score);
  }
}

void get_fall_class_api(const mxArray * const prhs[1], int32_T nlhs, const
  mxArray *plhs[1])
{
  real_T feat;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;

  /* Marshall function inputs */
  feat = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "feat");

  /* Invoke the target function */
  feat = get_fall_class(feat);

  /* Marshall function outputs */
  plhs[0] = c_emlrt_marshallOut(feat);
}

void get_features_api(const mxArray * const prhs[3], int32_T nlhs, const mxArray
                      *plhs[1])
{
  real_T (*feat)[106];
  real_T (*a1)[375];
  real_T (*a2)[375];
  real_T sf;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;
  feat = (real_T (*)[106])mxMalloc(sizeof(real_T [106]));

  /* Marshall function inputs */
  a1 = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "a1");
  a2 = emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "a2");
  sf = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "sf");

  /* Invoke the target function */
  get_features(*a1, *a2, sf, *feat);

  /* Marshall function outputs */
  plhs[0] = e_emlrt_marshallOut(*feat);
}

void get_strides_api(const mxArray * const prhs[2], int32_T nlhs, const mxArray *
                     plhs[1])
{
  real_T (*thigh_acc)[1500];
  real_T asf;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;

  /* Marshall function inputs */
  thigh_acc = k_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "thigh_acc");
  asf = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "asf");

  /* Invoke the target function */
  asf = get_strides(*thigh_acc, asf);

  /* Marshall function outputs */
  plhs[0] = c_emlrt_marshallOut(asf);
}

void pre_process_feats_api(const mxArray * const prhs[4], int32_T nlhs, const
  mxArray *plhs[1])
{
  real_T (*feats)[7];
  real_T (*feats1)[106];
  real_T (*mu)[106];
  real_T (*sigma)[106];
  real_T (*pc)[742];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;
  feats = (real_T (*)[7])mxMalloc(sizeof(real_T [7]));

  /* Marshall function inputs */
  feats1 = i_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "feats1");
  mu = i_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "mu");
  sigma = i_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "sigma");
  pc = m_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "pc");

  /* Invoke the target function */
  pre_process_feats(*feats1, *mu, *sigma, *pc, *feats);

  /* Marshall function outputs */
  plhs[0] = f_emlrt_marshallOut(*feats);
}

/* End of code generation (_coder_getFallClass_api.c) */

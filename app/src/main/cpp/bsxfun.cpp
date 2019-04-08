/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * bsxfun.cpp
 *
 * Code generation for function 'bsxfun'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "bsxfun.h"
#include "calc_fall_risk_emxutil.h"
#include <string.h>

/* Function Definitions */
void b_bsxfun(const emxArray_real_T *a, const double b_data[], const int b_size
              [2], emxArray_real_T *c)
{
  short csz_idx_0;
  short csz_idx_1;
  int i9;
  int acoef;
  int bcoef;
  int k;
  int varargin_2;
  int varargin_3;
  int b_acoef;
  int i10;
  int b_k;
  csz_idx_0 = static_cast<short>(a->size[0]);
  if (b_size[1] == 1) {
    csz_idx_1 = static_cast<short>(a->size[1]);
  } else if (a->size[1] == 1) {
    csz_idx_1 = static_cast<short>(b_size[1]);
  } else if (a->size[1] == b_size[1]) {
    csz_idx_1 = static_cast<short>(a->size[1]);
  } else if (b_size[1] < a->size[1]) {
    csz_idx_1 = static_cast<short>(b_size[1]);
  } else {
    csz_idx_1 = static_cast<short>(a->size[1]);
  }

  i9 = c->size[0] * c->size[1];
  c->size[0] = csz_idx_0;
  c->size[1] = csz_idx_1;
  emxEnsureCapacity_real_T(c, i9);
  if ((c->size[0] != 0) && (c->size[1] != 0)) {
    acoef = (a->size[1] != 1);
    bcoef = (b_size[1] != 1);
    i9 = c->size[1] - 1;
    for (k = 0; k <= i9; k++) {
      varargin_2 = acoef * k;
      varargin_3 = bcoef * k;
      b_acoef = (a->size[0] != 1);
      i10 = c->size[0] - 1;
      for (b_k = 0; b_k <= i10; b_k++) {
        c->data[b_k + c->size[0] * k] = a->data[b_acoef * b_k + a->size[0] *
          varargin_2] - b_data[varargin_3];
      }
    }
  }
}

void bsxfun(const double a_data[], const int a_size[2], double b, double c_data[],
            int c_size[2])
{
  int acoef;
  int i7;
  int k;
  c_size[0] = 1;
  c_size[1] = static_cast<short>(a_size[1]);
  if (static_cast<short>(a_size[1]) != 0) {
    acoef = (a_size[1] != 1);
    i7 = static_cast<short>(a_size[1]) - 1;
    for (k = 0; k <= i7; k++) {
      c_data[k] = a_data[acoef * k] - b;
    }
  }
}

void c_bsxfun(const double a_data[], const int a_size[1], double c_data[], int
              c_size[1])
{
  signed char csz_idx_0;
  int acoef;
  int i18;
  int k;
  if (a_size[0] == 1) {
    csz_idx_0 = 125;
    c_size[0] = 125;
  } else {
    if (a_size[0] == 125) {
      csz_idx_0 = 125;
    } else if (125 < a_size[0]) {
      csz_idx_0 = 125;
    } else {
      csz_idx_0 = static_cast<signed char>(a_size[0]);
    }

    if (a_size[0] == 125) {
      c_size[0] = 125;
    } else if (125 < a_size[0]) {
      c_size[0] = 125;
    } else {
      c_size[0] = static_cast<signed char>(a_size[0]);
    }
  }

  if (csz_idx_0 != 0) {
    acoef = (a_size[0] != 1);
    i18 = csz_idx_0 - 1;
    for (k = 0; k <= i18; k++) {
      c_data[k] = a_data[acoef * k];
    }
  }
}

void d_bsxfun(const double a_data[], const int a_size[2], double c_data[], int
              c_size[2])
{
  signed char csz_idx_0;
  int acoef;
  int i34;
  int k;
  if (a_size[0] == 1) {
    csz_idx_0 = 125;
    c_size[0] = 125;
  } else {
    if (a_size[0] == 125) {
      csz_idx_0 = 125;
    } else if (125 < a_size[0]) {
      csz_idx_0 = 125;
    } else {
      csz_idx_0 = static_cast<signed char>(a_size[0]);
    }

    if (a_size[0] == 125) {
      c_size[0] = 125;
    } else if (125 < a_size[0]) {
      c_size[0] = 125;
    } else {
      c_size[0] = static_cast<signed char>(a_size[0]);
    }
  }

  c_size[1] = 1;
  if (csz_idx_0 != 0) {
    acoef = (a_size[0] != 1);
    i34 = csz_idx_0 - 1;
    for (k = 0; k <= i34; k++) {
      c_data[k] = a_data[acoef * k];
    }
  }
}

void e_bsxfun(const emxArray_real_T *a, const emxArray_real_T *b,
              emxArray_real_T *c)
{
  int csz_idx_0;
  int acoef;
  int i48;
  int k;
  csz_idx_0 = b->size[0];
  acoef = a->size[0];
  if (csz_idx_0 < acoef) {
    acoef = csz_idx_0;
  }

  if (b->size[0] == 1) {
    csz_idx_0 = a->size[0];
  } else if (a->size[0] == 1) {
    csz_idx_0 = b->size[0];
  } else if (a->size[0] == b->size[0]) {
    csz_idx_0 = a->size[0];
  } else {
    csz_idx_0 = acoef;
  }

  i48 = c->size[0];
  c->size[0] = csz_idx_0;
  emxEnsureCapacity_real_T(c, i48);
  if (c->size[0] != 0) {
    acoef = (a->size[0] != 1);
    csz_idx_0 = (b->size[0] != 1);
    i48 = c->size[0] - 1;
    for (k = 0; k <= i48; k++) {
      c->data[k] = a->data[acoef * k] / b->data[csz_idx_0 * k];
    }
  }
}

void f_bsxfun(const emxArray_real_T *a, const double b_data[], const int b_size
              [1], emxArray_real_T *c)
{
  int csz_idx_0;
  int csz_idx_1;
  int i67;
  int varargin_2;
  int acoef;
  int bcoef;
  int i68;
  int k;
  csz_idx_0 = b_size[0];
  csz_idx_1 = a->size[0];
  if (csz_idx_0 < csz_idx_1) {
    csz_idx_1 = csz_idx_0;
  }

  if (b_size[0] == 1) {
    csz_idx_0 = a->size[0];
  } else if (a->size[0] == 1) {
    csz_idx_0 = b_size[0];
  } else if (a->size[0] == b_size[0]) {
    csz_idx_0 = a->size[0];
  } else {
    csz_idx_0 = csz_idx_1;
  }

  csz_idx_1 = a->size[1];
  i67 = c->size[0] * c->size[1];
  c->size[0] = csz_idx_0;
  c->size[1] = csz_idx_1;
  emxEnsureCapacity_real_T(c, i67);
  if ((c->size[0] != 0) && (c->size[1] != 0)) {
    csz_idx_0 = (a->size[1] != 1);
    i67 = c->size[1] - 1;
    for (csz_idx_1 = 0; csz_idx_1 <= i67; csz_idx_1++) {
      varargin_2 = csz_idx_0 * csz_idx_1;
      acoef = (a->size[0] != 1);
      bcoef = (b_size[0] != 1);
      i68 = c->size[0] - 1;
      for (k = 0; k <= i68; k++) {
        c->data[k + c->size[0] * csz_idx_1] = a->data[acoef * k + a->size[0] *
          varargin_2] / b_data[bcoef * k];
      }
    }
  }
}

void g_bsxfun(const emxArray_real_T *a, double c[63])
{
  int acoef;
  int k;
  acoef = (a->size[0] != 1);
  for (k = 0; k < 63; k++) {
    c[k] = a->data[acoef * k];
  }
}

/* End of code generation (bsxfun.cpp) */

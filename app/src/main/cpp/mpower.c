/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mpower.c
 *
 * Code generation for function 'mpower'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calibrate.h"
#include "get_calibration.h"
#include "get_classification.h"
#include "get_fall_class.h"
#include "get_features.h"
#include "get_strides.h"
#include "pre_process_feats.h"
#include "mpower.h"
#include "getFallClass_emxutil.h"
#include <string.h>

/* Function Definitions */
void mpower(const emxArray_real_T *a, emxArray_real_T *c)
{
  int i47;
  double b_a;
  int loop_ub;
  i47 = c->size[0] * c->size[1];
  c->size[0] = 1;
  c->size[1] = a->size[1];
  emxEnsureCapacity_real_T(c, i47);
  b_a = a->data[0];
  loop_ub = a->size[0] * a->size[1];
  for (i47 = 0; i47 < loop_ub; i47++) {
    c->data[i47] = b_a * a->data[i47];
  }
}

/* End of code generation (mpower.c) */

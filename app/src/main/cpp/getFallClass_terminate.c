/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * getFallClass_terminate.c
 *
 * Code generation for function 'getFallClass_terminate'
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
#include "getFallClass_terminate.h"
#include "getFallClass_data.h"
#include <string.h>

/* Function Definitions */
void getFallClass_terminate(void)
{
  omp_destroy_nest_lock(&emlrtNestLockGlobal);
}

/* End of code generation (getFallClass_terminate.c) */

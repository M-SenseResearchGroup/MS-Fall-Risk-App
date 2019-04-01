/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nonSingletonDim.c
 *
 * Code generation for function 'nonSingletonDim'
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
#include "nonSingletonDim.h"
#include <string.h>

/* Function Definitions */
int nonSingletonDim(const emxArray_creal_T *x)
{
  int dim;
  dim = 2;
  if (x->size[0] != 1) {
    dim = 1;
  }

  return dim;
}

/* End of code generation (nonSingletonDim.c) */

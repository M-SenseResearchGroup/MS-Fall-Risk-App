/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sortIdx.c
 *
 * Code generation for function 'sortIdx'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "calibrate.h"
#include "get_calibration.h"
#include "get_classification.h"
#include "get_fall_class.h"
#include "get_features.h"
#include "get_strides.h"
#include "pre_process_feats.h"
#include "sortIdx.h"
#include "mergesort.h"

/* Function Definitions */
void sortIdx(emxArray_creal_T *x, int idx_data[], int idx_size[1])
{
  short unnamed_idx_0;
  int i53;
  unnamed_idx_0 = (short)x->size[0];
  idx_size[0] = unnamed_idx_0;
  if (0 <= unnamed_idx_0 - 1) {
    memset(&idx_data[0], 0, (unsigned int)(unnamed_idx_0 * (int)sizeof(int)));
  }

  if (x->size[0] != 0) {
    i53 = x->size[0];
    b_mergesort(idx_data, x, i53);
  }
}

/* End of code generation (sortIdx.c) */

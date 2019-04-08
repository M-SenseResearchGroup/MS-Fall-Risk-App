/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sortIdx.cpp
 *
 * Code generation for function 'sortIdx'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "sortIdx.h"
#include "mergesort.h"

/* Function Definitions */
void sortIdx(emxArray_creal_T *x, int idx_data[], int idx_size[1])
{
  short unnamed_idx_0;
  int i104;
  unnamed_idx_0 = static_cast<short>(x->size[0]);
  idx_size[0] = unnamed_idx_0;
  if (0 <= unnamed_idx_0 - 1) {
    memset(&idx_data[0], 0, (unsigned int)(unnamed_idx_0 * static_cast<int>
            (sizeof(int))));
  }

  if (x->size[0] != 0) {
    i104 = x->size[0];
    b_mergesort(idx_data, x, i104);
  }
}

/* End of code generation (sortIdx.cpp) */

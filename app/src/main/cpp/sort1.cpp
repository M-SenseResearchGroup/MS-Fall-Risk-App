/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sort1.cpp
 *
 * Code generation for function 'sort1'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "sort1.h"
#include "calc_fall_risk_emxutil.h"
#include "sortIdx.h"
#include "nonSingletonDim.h"
#include <string.h>

/* Function Definitions */
void sort(emxArray_creal_T *x, int idx_data[], int idx_size[2])
{
  emxArray_creal_T *vwork;
  int dim;
  int vlen;
  short x_idx_0;
  int i103;
  short x_idx_1;
  int vstride;
  int k;
  int npages;
  int i;
  int pageoffset;
  int j;
  static int iidx_data[12285];
  int iidx_size[1];
  emxInit_creal_T(&vwork, 1);
  dim = nonSingletonDim(x) - 1;
  vlen = x->size[dim] - 1;
  x_idx_0 = static_cast<short>(x->size[dim]);
  i103 = vwork->size[0];
  vwork->size[0] = x_idx_0;
  emxEnsureCapacity_creal_T(vwork, i103);
  x_idx_0 = static_cast<short>(x->size[0]);
  x_idx_1 = static_cast<short>(x->size[1]);
  idx_size[0] = x_idx_0;
  idx_size[1] = x_idx_1;
  vstride = 1;
  for (k = 0; k < dim; k++) {
    vstride *= x->size[0];
  }

  npages = 1;
  i103 = dim + 2;
  for (k = i103; k < 3; k++) {
    npages *= x->size[1];
  }

  dim = x->size[dim] * vstride;
  for (i = 0; i < npages; i++) {
    pageoffset = i * dim;
    for (j = 0; j < vstride; j++) {
      for (k = 0; k <= vlen; k++) {
        vwork->data[k] = x->data[pageoffset + k * vstride];
      }

      sortIdx(vwork, iidx_data, iidx_size);
      for (k = 0; k <= vlen; k++) {
        i103 = pageoffset + k * vstride;
        x->data[i103] = vwork->data[k];
        idx_data[i103] = iidx_data[k];
      }
    }
  }

  emxFree_creal_T(&vwork);
}

/* End of code generation (sort1.cpp) */

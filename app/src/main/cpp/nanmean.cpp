/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nanmean.cpp
 *
 * Code generation for function 'nanmean'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "nanmean.h"
#include <string.h>

/* Function Definitions */
void b_nanmean(const emxArray_real_T *varargin_1, double y_data[], int y_size[2])
{
  short sz_idx_1;
  int vlen;
  int npages;
  int ixstart;
  int ix;
  int n;
  int iy;
  int i;
  double s;
  sz_idx_1 = static_cast<short>(varargin_1->size[1]);
  y_size[0] = 1;
  y_size[1] = sz_idx_1;
  if ((varargin_1->size[0] == 0) || (varargin_1->size[1] == 0)) {
    y_size[0] = 1;
    ixstart = sz_idx_1;
    for (n = 0; n < ixstart; n++) {
      y_data[n] = rtNaN;
    }
  } else {
    vlen = varargin_1->size[0];
    npages = varargin_1->size[1];
    ix = -1;
    iy = -1;
    for (i = 0; i < npages; i++) {
      ixstart = ix + 1;
      ix++;
      if (!rtIsNaN(varargin_1->data[ixstart])) {
        s = varargin_1->data[ixstart];
        n = 1;
      } else {
        s = 0.0;
        n = 0;
      }

      for (ixstart = 2; ixstart <= vlen; ixstart++) {
        ix++;
        if (!rtIsNaN(varargin_1->data[ix])) {
          s += varargin_1->data[ix];
          n++;
        }
      }

      if (n == 0) {
        s = rtNaN;
      } else {
        s /= static_cast<double>(n);
      }

      iy++;
      y_data[iy] = s;
    }
  }
}

double nanmean(const double varargin_1_data[], const int varargin_1_size[2])
{
  double y;
  int vlen;
  int c;
  int k;
  if (varargin_1_size[1] == 0) {
    y = rtNaN;
  } else {
    vlen = varargin_1_size[1];
    y = 0.0;
    c = 0;
    for (k = 0; k < vlen; k++) {
      if (!rtIsNaN(varargin_1_data[k])) {
        y += varargin_1_data[k];
        c++;
      }
    }

    if (c == 0) {
      y = rtNaN;
    } else {
      y /= static_cast<double>(c);
    }
  }

  return y;
}

/* End of code generation (nanmean.cpp) */

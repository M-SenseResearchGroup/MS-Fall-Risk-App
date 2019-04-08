/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nan_sum_or_mean.cpp
 *
 * Code generation for function 'nan_sum_or_mean'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "nan_sum_or_mean.h"

/* Function Definitions */
void b_nan_sum_or_mean(const emxArray_real_T *x, double y_data[], int y_size[2],
  int c_data[], int c_size[2])
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
  sz_idx_1 = static_cast<short>(x->size[1]);
  y_size[0] = 1;
  y_size[1] = sz_idx_1;
  c_size[0] = 1;
  c_size[1] = sz_idx_1;
  if (0 <= sz_idx_1 - 1) {
    memset(&c_data[0], 0, (unsigned int)(sz_idx_1 * static_cast<int>(sizeof(int))));
  }

  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    y_size[0] = 1;
    ixstart = sz_idx_1;
    for (n = 0; n < ixstart; n++) {
      y_data[n] = rtNaN;
    }
  } else {
    vlen = x->size[0];
    npages = x->size[1];
    ix = -1;
    iy = -1;
    for (i = 0; i < npages; i++) {
      ixstart = ix + 1;
      ix++;
      if (!rtIsNaN(x->data[ixstart])) {
        s = x->data[ixstart];
        n = 1;
      } else {
        s = 0.0;
        n = 0;
      }

      for (ixstart = 2; ixstart <= vlen; ixstart++) {
        ix++;
        if (!rtIsNaN(x->data[ix])) {
          s += x->data[ix];
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
      c_data[iy] = n;
    }
  }
}

void nan_sum_or_mean(const double x_data[], const int x_size[2], double *y, int *
                     c)
{
  int vlen;
  int k;
  *c = 0;
  if (x_size[1] == 0) {
    *y = rtNaN;
  } else {
    vlen = x_size[1];
    *y = 0.0;
    for (k = 0; k < vlen; k++) {
      if (!rtIsNaN(x_data[k])) {
        *y += x_data[k];
        (*c)++;
      }
    }

    if (*c == 0) {
      *y = rtNaN;
    } else {
      *y /= static_cast<double>(*c);
    }
  }
}

/* End of code generation (nan_sum_or_mean.cpp) */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * var.cpp
 *
 * Code generation for function 'var'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "var.h"
#include "vvarstd.h"

/* Function Definitions */
void b_var(const emxArray_real_T *x, double y_data[], int y_size[2])
{
  short szy_idx_1;
  int nx;
  int npages;
  short outsize_idx_0;
  int p;
  int loop_ub;
  int tunableEnvironment_idx_0;
  int xv_size[1];
  double xv_data[313];
  int k;
  szy_idx_1 = static_cast<short>(x->size[1]);
  y_size[0] = 1;
  y_size[1] = szy_idx_1;
  if (0 <= szy_idx_1 - 1) {
    memset(&y_data[0], 0, (unsigned int)(szy_idx_1 * static_cast<int>(sizeof
             (double))));
  }

  nx = x->size[0];
  npages = x->size[1];
  if (0 <= npages - 1) {
    outsize_idx_0 = static_cast<short>(nx);
    loop_ub = static_cast<short>(nx);
  }

  for (p = 0; p < npages; p++) {
    tunableEnvironment_idx_0 = p * nx + 1;
    xv_size[0] = outsize_idx_0;
    if (0 <= loop_ub - 1) {
      memset(&xv_data[0], 0, (unsigned int)(loop_ub * static_cast<int>(sizeof
               (double))));
    }

    for (k = 0; k < nx; k++) {
      xv_data[k] = x->data[(tunableEnvironment_idx_0 + k) - 1];
    }

    y_data[p] = vvarstd(xv_data, xv_size, x->size[0]);
  }
}

double var(const double x_data[], const int x_size[2])
{
  int x[1];
  x[0] = x_size[1];
  return vvarstd(x_data, x, x_size[1]);
}

/* End of code generation (var.cpp) */

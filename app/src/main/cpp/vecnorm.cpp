/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * vecnorm.cpp
 *
 * Code generation for function 'vecnorm'
 *
 */

/* Include files */
#include <cmath>
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "vecnorm.h"
#include <string.h>

/* Function Definitions */
void vecnorm(const double x_data[], const int x_size[2], double y_data[], int
             y_size[2])
{
  int ncols;
  int j;
  int ix0;
  double y;
  double scale;
  int kend;
  int k;
  double absxk;
  double t;
  ncols = x_size[1];
  y_size[0] = 1;
  y_size[1] = static_cast<short>(x_size[1]);
  for (j = 0; j < ncols; j++) {
    ix0 = j << 1;
    y = 0.0;
    scale = 3.3121686421112381E-170;
    kend = ix0 + 2;
    for (k = ix0 + 1; k <= kend; k++) {
      absxk = std::abs(x_data[k - 1]);
      if (absxk > scale) {
        t = scale / absxk;
        y = 1.0 + y * t * t;
        scale = absxk;
      } else {
        t = absxk / scale;
        y += t * t;
      }
    }

    y_data[j] = scale * std::sqrt(y);
  }
}

/* End of code generation (vecnorm.cpp) */

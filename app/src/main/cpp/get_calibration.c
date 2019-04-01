/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_calibration.c
 *
 * Code generation for function 'get_calibration'
 *
 */

/* Include files */
#include <math.h>
#include "rt_nonfinite.h"
#include "calibrate.h"
#include "get_calibration.h"
#include "get_classification.h"
#include "get_fall_class.h"
#include "get_features.h"
#include "get_strides.h"
#include "pre_process_feats.h"
#include "norm.h"
#include "mean.h"
#include "staticndx.h"
#include <string.h>

/* Function Definitions */
void get_calibration(const double a[939], double n, double r[9], double *g)
{
  double i[2];
  int i2;
  int xoffset;
  int ncols;
  int y_size[2];
  emxArray_real_T y_data;
  double b_y_data[313];
  int ix0;
  double angle;
  double scale;
  int kend;
  int k;
  double absxk;
  double y[3];
  double t;
  double axis[3];
  static const double v2[3] = { 0.0, 0.0, 1.0 };

  signed char I3[9];
  double r_tmp[9];

  /*  input:  */
  /*    a - data from standing calibration */
  /*    n - number of consecutive samples to consider */
  /*  output: */
  /*    r - sensor to body dcm */
  /*    g - gravity magnitude */
  /*  get most still period */
  staticndx(a, n, i);

  /*  get gravity offset */
  if (i[0] > i[1]) {
    i2 = 0;
    xoffset = 0;
  } else {
    i2 = (int)i[0] - 1;
    xoffset = (int)i[1];
  }

  xoffset -= i2;
  ncols = xoffset - 1;
  y_size[0] = 1;
  y_size[1] = (short)xoffset;
  for (xoffset = 0; xoffset <= ncols; xoffset++) {
    ix0 = xoffset * 3;
    angle = 0.0;
    scale = 3.3121686421112381E-170;
    kend = ix0 + 3;
    for (k = ix0 + 1; k <= kend; k++) {
      absxk = fabs(a[(k - 1) % 3 + 3 * (i2 + (k - 1) / 3)]);
      if (absxk > scale) {
        t = scale / absxk;
        angle = 1.0 + angle * t * t;
        scale = absxk;
      } else {
        t = absxk / scale;
        angle += t * t;
      }
    }

    b_y_data[xoffset] = scale * sqrt(angle);
  }

  y_data.data = &b_y_data[0];
  y_data.size = &y_size[0];
  y_data.allocatedSize = 313;
  y_data.numDimensions = 2;
  y_data.canFreeData = false;
  *g = mean(&y_data);

  /*  get sensor to body dcm */
  y[0] = a[0];
  y[1] = a[1];
  y[2] = a[2];
  for (k = 0; k < 312; k++) {
    xoffset = (k + 1) * 3;
    y[0] += a[xoffset];
    y[1] += a[xoffset + 1];
    y[2] += a[xoffset + 2];
  }

  axis[0] = a[0];
  axis[1] = a[1];
  axis[2] = a[2];
  for (k = 0; k < 312; k++) {
    xoffset = (k + 1) * 3;
    axis[0] += a[xoffset];
    axis[1] += a[xoffset + 1];
    axis[2] += a[xoffset + 2];
  }

  axis[0] /= 313.0;
  axis[1] /= 313.0;
  axis[2] /= 313.0;
  angle = b_norm(axis);
  y[0] = y[0] / 313.0 / angle;
  y[1] = y[1] / 313.0 / angle;
  y[2] = y[2] / 313.0 / angle;

  /* Reed Gurchiek, 2017 */
  /*    getrot finds the rotation operator of type 'type' which takes v  */
  /*    measured in frame 1 (v1) and expresses it in frame 2 (v2) if v2 is a  */
  /*    3-dimensional vector.  Otherwise, it constructs an angle-axis */
  /*    rotator where v1 is the axis and v2 is the angle if v2 is */
  /*    1-dimensional.  In this case, consider the axis (in frame 1) and angle */
  /*    that one would use to rotate frame 1 to align with frame 2 */
  /*  */
  /* -----------------------------INPUTS--------------------------------------- */
  /*  */
  /*    v1, v2: */
  /*        vectors 1 and 2. 3xn matrix of column vectors. v1 is v measured in */
  /*        frame 1 and v2 is v measured in frame 2. */
  /*        OR */
  /*        rotation axis (v1: 3xn matrix of column vectors with unit norm) and */
  /*        rotation angle (v2: 1xn array of rotation angles) */
  /*  */
  /*    type: */
  /*        string specifying type of rotation operator.  Either 'dcm' for */
  /*        direction cosine matrix or 'q' for quaternion. */
  /*  */
  /* ----------------------------OUTPUTS--------------------------------------- */
  /*  */
  /*    r: */
  /*        rotation operator which takes v1 to v2 of type 'type' or described */
  /*        by the axis-angle combo v1 & v2. */
  /*  */
  /* -------------------------------------------------------------------------- */
  /*  getrot */
  /* verify proper inputs */
  /* if v2 is a vector */
  /* get axis of rotation */
  axis[0] = 0.0 * y[2] - y[1];
  axis[1] = y[0] - 0.0 * y[2];
  axis[2] = 0.0 * y[1] - 0.0 * y[0];
  angle = b_norm(axis);

  /* get angle */
  axis[0] /= angle;
  axis[1] /= angle;
  axis[2] /= angle;
  angle = acos(((0.0 * y[0] + 0.0 * y[1]) + y[2]) / (b_norm(v2) * b_norm(y)));

  /* if v2 is 1D array of angles */
  /* if quaternion */
  /* construct dcm (euler formula: R(n,a) = I - s(a)*[nx] + (1-c(a))*[nx]^2) */
  for (i2 = 0; i2 < 9; i2++) {
    I3[i2] = 0;
  }

  I3[0] = 1;
  I3[4] = 1;
  I3[8] = 1;

  /* Reed Gurchiek, 2017 */
  /*    skew takes a 3xn matrix of column vectors and returns a 3x3xn skew */
  /*    symmetric matrix for each column vector in V such that Vx(3,3,i)*p = */
  /*    cross(V(:,i),p). */
  /*  */
  /* ---------------------------------INPUTS----------------------------------- */
  /*  */
  /*    V: */
  /*        3xn matrix of column vectors. */
  /*  */
  /* --------------------------------OUTPUTS----------------------------------- */
  /*  */
  /*    Vx: */
  /*        3x3xn skew symmetric matrices. */
  /*  */
  /* -------------------------------------------------------------------------- */
  /*  skew */
  /* verify proper inputs */
  /* for each vector */
  /* get skew */
  r_tmp[0] = 0.0;
  r_tmp[3] = -axis[2];
  r_tmp[6] = axis[1];
  r_tmp[1] = axis[2];
  r_tmp[4] = 0.0;
  r_tmp[7] = -axis[0];
  r_tmp[2] = -axis[1];
  r_tmp[5] = axis[0];
  r_tmp[8] = 0.0;
  scale = sin(angle);
  angle = cos(angle);
  for (i2 = 0; i2 < 3; i2++) {
    for (xoffset = 0; xoffset < 3; xoffset++) {
      ix0 = i2 + 3 * xoffset;
      r[ix0] = ((double)I3[ix0] - scale * r_tmp[ix0]) + (((1.0 - angle) *
        r_tmp[i2] * r_tmp[3 * xoffset] + (1.0 - angle) * r_tmp[i2 + 3] * r_tmp[1
        + 3 * xoffset]) + (1.0 - angle) * r_tmp[i2 + 6] * r_tmp[2 + 3 * xoffset]);
    }
  }
}

/* End of code generation (get_calibration.c) */

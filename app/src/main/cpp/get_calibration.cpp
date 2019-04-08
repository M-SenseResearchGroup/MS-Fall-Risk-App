/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_calibration.cpp
 *
 * Code generation for function 'get_calibration'
 *
 */

/* Include files */
#include <cmath>
#include <string.h>
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "norm.h"
#include "mean.h"
#include "calc_fall_risk_emxutil.h"
#include "vvarstd.h"

/* Function Definitions */
void get_calibration(const double a[939], double n, double r[9], double *g)
{
  int i97;
  emxArray_real_T *variance;
  int i98;
  double d[939];
  int k;
  emxArray_real_T *tv;
  double i_idx_1;
  int vstride;
  int p;
  int xoffset;
  int ncols;
  double y[3];
  short tunableEnvironment_idx_0;
  int xv_size[1];
  double xv_data[313];
  int b_k;
  boolean_T exitg1;
  int y_size[2];
  emxArray_real_T y_data;
  double b_y_data[313];
  double scale;
  double absxk;
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
  /* Reed Gurchiek, 2017 */
  /*    staticndx finds the start and end indices of the interval of length */
  /*    nsamples with the smallest variance for the data in data. */
  /*  */
  /* ------------------------------INPUTS-------------------------------------- */
  /*  */
  /*    data: */
  /*        m x n matrix.  staticndx assumes the largest dimension (m or n) */
  /*        represents indices of observations for different variables, the */
  /*        number of which is equal to the lesser dimension (m or n).  The */
  /*        larger must be greater than nsamples */
  /*  */
  /*    nsamples: */
  /*        the number of samples in the static interval desired */
  /*  */
  /* ------------------------------OUTPUTS------------------------------------- */
  /*  */
  /*    indices: */
  /*        1 x 2.  indices(1) = start index.  indices(2) = end index. */
  /*  */
  /* -------------------------------------------------------------------------- */
  /*  staticndx */
  /* get dims */
  /* determine dimension of observation indices and number of observations */
  /* verify correct input */
  /* if observation indices are columns */
  /* force time/observation series to be column arrays */
  for (i97 = 0; i97 < 3; i97++) {
    for (i98 = 0; i98 < 313; i98++) {
      d[i98 + 313 * i97] = a[i97 + 3 * i98];
    }
  }

  emxInit_real_T(&variance, 2);

  /* get number of variables */
  /* if observation indices are rows     */
  /* determine number of intervals of length nsamples */
  /* for each interval of length nsamples */
  i97 = static_cast<int>(((313.0 - n) + 1.0));
  i98 = variance->size[0] * variance->size[1];
  variance->size[0] = i97;
  variance->size[1] = 3;
  emxEnsureCapacity_real_T(variance, i98);
  for (k = 0; k < i97; k++) {
    /* get variance of each variable for each interval of length nsamples */
    i_idx_1 = ((1.0 + static_cast<double>(k)) + n) - 1.0;
    if (1.0 + static_cast<double>(k) > i_idx_1) {
      i98 = -1;
      vstride = -1;
    } else {
      i98 = k - 1;
      vstride = static_cast<int>(i_idx_1) - 1;
    }

    xoffset = vstride - i98;
    ncols = static_cast<short>(xoffset);
    for (p = 0; p < 3; p++) {
      y[p] = 0.0;
      tunableEnvironment_idx_0 = static_cast<short>((p * xoffset + 1));
      xv_size[0] = static_cast<short>(xoffset);
      if (0 <= ncols - 1) {
        memset(&xv_data[0], 0, (unsigned int)(ncols * static_cast<int>(sizeof
                 (double))));
      }

      for (b_k = 0; b_k < xoffset; b_k++) {
        vstride = tunableEnvironment_idx_0 + b_k;
        xv_data[b_k] = d[((i98 + (vstride - 1) % xoffset) + 313 * ((vstride - 1)
          / xoffset)) + 1];
      }

      y[p] = vvarstd(xv_data, xv_size, xoffset);
    }

    variance->data[k] = y[0];
    variance->data[k + variance->size[0]] = y[1];
    variance->data[k + (variance->size[0] << 1)] = y[2];
  }

  emxInit_real_T(&tv, 1);

  /* get total variance for each interval */
  vstride = variance->size[0];
  i97 = tv->size[0];
  tv->size[0] = variance->size[0];
  emxEnsureCapacity_real_T(tv, i97);
  for (p = 0; p < vstride; p++) {
    tv->data[p] = variance->data[p];
  }

  for (p = 0; p < vstride; p++) {
    tv->data[p] += variance->data[vstride + p];
  }

  xoffset = 2 * vstride;
  for (p = 0; p < vstride; p++) {
    tv->data[p] += variance->data[xoffset + p];
  }

  emxFree_real_T(&variance);

  /* get starting index for the most static interval */
  vstride = tv->size[0];
  if (tv->size[0] <= 2) {
    if ((tv->data[0] > tv->data[1]) || (rtIsNaN(tv->data[0]) && (!rtIsNaN
          (tv->data[1])))) {
      xoffset = 2;
    } else {
      xoffset = 1;
    }
  } else {
    if (!rtIsNaN(tv->data[0])) {
      xoffset = 1;
    } else {
      xoffset = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= tv->size[0])) {
        if (!rtIsNaN(tv->data[k - 1])) {
          xoffset = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (xoffset == 0) {
      xoffset = 1;
    } else {
      i_idx_1 = tv->data[xoffset - 1];
      i97 = xoffset + 1;
      for (k = i97; k <= vstride; k++) {
        if (i_idx_1 > tv->data[k - 1]) {
          i_idx_1 = tv->data[k - 1];
          xoffset = k;
        }
      }
    }
  }

  emxFree_real_T(&tv);

  /* get ending index for most static interval */
  i_idx_1 = (static_cast<double>(xoffset) + n) - 1.0;

  /*  get gravity offset */
  if (xoffset > i_idx_1) {
    i97 = 0;
    i98 = 0;
  } else {
    i97 = xoffset - 1;
    i98 = static_cast<int>(i_idx_1);
  }

  vstride = i98 - i97;
  ncols = vstride - 1;
  y_size[0] = 1;
  y_size[1] = static_cast<short>(vstride);
  for (p = 0; p <= ncols; p++) {
    vstride = p * 3;
    i_idx_1 = 0.0;
    scale = 3.3121686421112381E-170;
    xoffset = vstride + 3;
    for (k = vstride + 1; k <= xoffset; k++) {
      absxk = std::abs(a[(k - 1) % 3 + 3 * (i97 + (k - 1) / 3)]);
      if (absxk > scale) {
        t = scale / absxk;
        i_idx_1 = 1.0 + i_idx_1 * t * t;
        scale = absxk;
      } else {
        t = absxk / scale;
        i_idx_1 += t * t;
      }
    }

    b_y_data[p] = scale * std::sqrt(i_idx_1);
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
  i_idx_1 = b_norm(axis);
  y[0] = y[0] / 313.0 / i_idx_1;
  y[1] = y[1] / 313.0 / i_idx_1;
  y[2] = y[2] / 313.0 / i_idx_1;

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
  i_idx_1 = b_norm(axis);

  /* get angle */
  axis[0] /= i_idx_1;
  axis[1] /= i_idx_1;
  axis[2] /= i_idx_1;
  i_idx_1 = std::acos(((0.0 * y[0] + 0.0 * y[1]) + y[2]) / (b_norm(v2) * b_norm
    (y)));

  /* if v2 is 1D array of angles */
  /* if quaternion */
  /* construct dcm (euler formula: R(n,a) = I - s(a)*[nx] + (1-c(a))*[nx]^2) */
  for (i97 = 0; i97 < 9; i97++) {
    I3[i97] = 0;
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
  scale = std::sin(i_idx_1);
  i_idx_1 = std::cos(i_idx_1);
  for (i97 = 0; i97 < 3; i97++) {
    for (i98 = 0; i98 < 3; i98++) {
      vstride = i97 + 3 * i98;
      r[vstride] = (static_cast<double>(I3[vstride]) - scale * r_tmp[vstride]) +
        (((1.0 - i_idx_1) * r_tmp[i97] * r_tmp[3 * i98] + (1.0 - i_idx_1) *
          r_tmp[i97 + 3] * r_tmp[1 + 3 * i98]) + (1.0 - i_idx_1) * r_tmp[i97 + 6]
         * r_tmp[2 + 3 * i98]);
    }
  }
}

/* End of code generation (get_calibration.cpp) */

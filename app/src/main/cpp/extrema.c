/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * extrema.c
 *
 * Code generation for function 'extrema'
 *
 */

/* Include files */
#include <math.h>
#include "rt_nonfinite.h"
#include <string.h>
#include "calibrate.h"
#include "get_calibration.h"
#include "get_classification.h"
#include "get_fall_class.h"
#include "get_features.h"
#include "get_strides.h"
#include "pre_process_feats.h"
#include "extrema.h"
#include "getFallClass_emxutil.h"
#include "nullAssignment.h"
#include "sign.h"
#include "ifWhileCond.h"
#include "any.h"
#include "diff.h"
#include "sign1.h"

/* Function Definitions */
void b_extrema(const double x_data[], const int x_size[2], emxArray_real_T
               *b_max, emxArray_real_T *imax)
{
  double d_data[248];
  int d_size[2];
  int i31;
  int idx;
  emxArray_real_T *imin;
  int loop_ub_tmp;
  int nx;
  boolean_T b_x_data[249];
  int ii_size_idx_1;
  int ii;
  boolean_T exitg1;
  unsigned char ii_data[249];
  int first_size[2];
  double first_data[249];
  int tmp_size[2];
  int tmp_data[248];
  int last_size[2];
  double last_data[249];
  int b_x_size[2];
  emxArray_real_T *y;
  double b_d_data[249];
  int i32;
  int imaxFirst_size_idx_0;
  int imaxFirst_size_idx_1;
  double imaxFirst_data[248];
  emxArray_real_T *b_y;
  int imaxLast_size_idx_0;
  int iminLast_size_idx_1;
  int imaxLast_size_idx_1;
  double iminLast_data[4096];
  double imaxLast_data[4096];
  double maxct;
  double minct;
  int direction0_size[2];
  double direction0_data[249];
  double constant;
  double direction;
  unsigned char input_sizes_idx_1;
  cell_wrap_43 reshapes[3];
  double ndbl;
  double apnd;
  double cdiff;
  emxArray_real_T *result;
  int result_size[2];
  emxArray_boolean_T result_data;
  boolean_T b_result_data[4592];
  emxArray_real_T *b_result;
  unsigned char b_input_sizes_idx_1;
  unsigned char c_input_sizes_idx_1;
  int b_result_size[2];
  boolean_T c_result_data[4592];
  emxArray_boolean_T d_result_data;

  /* Reed Gurchiek, */
  /*    extrema finds local minima and maxima of the vector x */
  /*  */
  /* ---------------------------INPUTS----------------------------------------- */
  /*  */
  /*    x: */
  /*        n-element array for which the local minima and maxima will be found */
  /*  */
  /* --------------------------OUTPUTS----------------------------------------- */
  /*  */
  /*    max,imax: */
  /*        local maxima values (max) and their indices (imax) */
  /*  */
  /*    min,imin: */
  /*        local minima values (min) and their indices (imin) */
  /*  */
  /* -------------------------------------------------------------------------- */
  /*  extrema */
  /* initialize */
  b_max->size[0] = 0;
  b_max->size[1] = 0;
  imax->size[0] = 0;
  imax->size[1] = 0;

  /* get differences */
  b_diff(x_data, x_size, d_data, d_size);

  /* get extrema if any nonzero changes */
  if (c_any(d_data, d_size)) {
    /* allocation */
    i31 = imax->size[0] * imax->size[1];
    imax->size[0] = 1;
    imax->size[1] = d_size[1];
    emxEnsureCapacity_real_T(imax, i31);
    idx = d_size[1];
    for (i31 = 0; i31 < idx; i31++) {
      imax->data[i31] = 0.0;
    }

    emxInit_real_T(&imin, 2);
    i31 = imin->size[0] * imin->size[1];
    imin->size[0] = 1;
    imin->size[1] = d_size[1];
    emxEnsureCapacity_real_T(imin, i31);
    idx = d_size[1];
    for (i31 = 0; i31 < idx; i31++) {
      imin->data[i31] = 0.0;
    }

    /* endpoints are always local extrema */
    loop_ub_tmp = x_size[0] * x_size[1];
    for (i31 = 0; i31 < loop_ub_tmp; i31++) {
      b_x_data[i31] = (x_data[i31] != x_data[0]);
    }

    nx = x_size[1];
    idx = 0;
    ii_size_idx_1 = x_size[1];
    ii = 0;
    exitg1 = false;
    while ((!exitg1) && (ii <= nx - 1)) {
      if (b_x_data[ii]) {
        idx++;
        ii_data[idx - 1] = (unsigned char)(ii + 1);
        if (idx >= nx) {
          exitg1 = true;
        } else {
          ii++;
        }
      } else {
        ii++;
      }
    }

    if (x_size[1] == 1) {
      if (idx == 0) {
        ii_size_idx_1 = 0;
      }
    } else if (1 > idx) {
      ii_size_idx_1 = 0;
    } else {
      ii_size_idx_1 = idx;
    }

    first_size[0] = 1;
    first_size[1] = ii_size_idx_1;
    for (i31 = 0; i31 < ii_size_idx_1; i31++) {
      first_data[i31] = ii_data[i31];
    }

    idx = ii_size_idx_1 - 2;
    tmp_size[0] = 1;
    tmp_size[1] = ii_size_idx_1 - 1;
    for (i31 = 0; i31 <= idx; i31++) {
      tmp_data[i31] = 2 + i31;
    }

    d_nullAssignment(first_data, first_size, tmp_data, tmp_size);
    for (i31 = 0; i31 < loop_ub_tmp; i31++) {
      b_x_data[i31] = (x_data[i31] != x_data[x_size[1] - 1]);
    }

    nx = x_size[1];
    idx = 0;
    ii_size_idx_1 = x_size[1];
    ii = 0;
    exitg1 = false;
    while ((!exitg1) && (ii <= nx - 1)) {
      if (b_x_data[ii]) {
        idx++;
        ii_data[idx - 1] = (unsigned char)(ii + 1);
        if (idx >= nx) {
          exitg1 = true;
        } else {
          ii++;
        }
      } else {
        ii++;
      }
    }

    if (x_size[1] == 1) {
      if (idx == 0) {
        ii_size_idx_1 = 0;
      }
    } else if (1 > idx) {
      ii_size_idx_1 = 0;
    } else {
      ii_size_idx_1 = idx;
    }

    last_size[0] = 1;
    last_size[1] = ii_size_idx_1;
    for (i31 = 0; i31 < ii_size_idx_1; i31++) {
      last_data[i31] = ii_data[i31];
    }

    idx = ii_size_idx_1 - 2;
    tmp_size[0] = 1;
    tmp_size[1] = ii_size_idx_1 - 1;
    for (i31 = 0; i31 <= idx; i31++) {
      tmp_data[i31] = 1 + i31;
    }

    d_nullAssignment(last_data, last_size, tmp_data, tmp_size);
    b_x_size[0] = 1;
    b_x_size[1] = first_size[1];
    loop_ub_tmp = first_size[0] * first_size[1];
    for (i31 = 0; i31 < loop_ub_tmp; i31++) {
      b_x_data[i31] = (x_data[0] < x_data[(int)first_data[i31] - 1]);
    }

    emxInit_real_T(&y, 2);
    if (c_ifWhileCond(b_x_data, b_x_size)) {
      for (i31 = 0; i31 < loop_ub_tmp; i31++) {
        b_d_data[i31] = first_data[i31] - 1.0;
      }

      if ((unsigned char)b_d_data[0] < 1) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else {
        i31 = y->size[0] * y->size[1];
        y->size[0] = 1;
        i32 = (unsigned char)b_d_data[0];
        y->size[1] = i32;
        emxEnsureCapacity_real_T(y, i31);
        nx = i32 - 1;
        for (i31 = 0; i31 <= nx; i31++) {
          y->data[i31] = 1.0 + (double)i31;
        }
      }

      d_size[1] = y->size[1];
      idx = y->size[0] * y->size[1];
      for (i31 = 0; i31 < idx; i31++) {
        d_data[i31] = y->data[i31];
      }

      imaxFirst_size_idx_0 = 0;
      imaxFirst_size_idx_1 = 0;
    } else {
      d_size[1] = 0;
      for (i31 = 0; i31 < loop_ub_tmp; i31++) {
        b_d_data[i31] = first_data[i31] - 1.0;
      }

      if ((unsigned char)b_d_data[0] < 1) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else {
        i31 = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = (unsigned char)b_d_data[0];
        emxEnsureCapacity_real_T(y, i31);
        idx = (unsigned char)b_d_data[0] - 1;
        for (i31 = 0; i31 <= idx; i31++) {
          y->data[i31] = 1.0 + (double)i31;
        }
      }

      imaxFirst_size_idx_0 = 1;
      imaxFirst_size_idx_1 = y->size[1];
      idx = y->size[0] * y->size[1];
      for (i31 = 0; i31 < idx; i31++) {
        imaxFirst_data[i31] = y->data[i31];
      }
    }

    emxFree_real_T(&y);
    b_x_size[0] = 1;
    b_x_size[1] = last_size[1];
    nx = last_size[0] * last_size[1];
    for (i31 = 0; i31 < nx; i31++) {
      b_x_data[i31] = (x_data[x_size[1] - 1] < x_data[(int)last_data[i31] - 1]);
    }

    emxInit_real_T(&b_y, 2);
    if (c_ifWhileCond(b_x_data, b_x_size)) {
      for (i31 = 0; i31 < nx; i31++) {
        b_d_data[i31] = last_data[i31] + 1.0;
      }

      if (x_size[1] < (unsigned char)b_d_data[0]) {
        b_y->size[0] = 1;
        b_y->size[1] = 0;
      } else {
        i31 = b_y->size[0] * b_y->size[1];
        b_y->size[0] = 1;
        b_y->size[1] = (x_size[1] - (unsigned char)b_d_data[0]) + 1;
        emxEnsureCapacity_real_T(b_y, i31);
        idx = x_size[1] - (unsigned char)b_d_data[0];
        for (i31 = 0; i31 <= idx; i31++) {
          b_y->data[i31] = (unsigned int)(unsigned char)b_d_data[0] + i31;
        }
      }

      iminLast_size_idx_1 = b_y->size[1];
      idx = b_y->size[0] * b_y->size[1];
      for (i31 = 0; i31 < idx; i31++) {
        iminLast_data[i31] = b_y->data[i31];
      }

      imaxLast_size_idx_0 = 0;
      imaxLast_size_idx_1 = 0;
    } else {
      for (i31 = 0; i31 < nx; i31++) {
        b_d_data[i31] = last_data[i31] + 1.0;
      }

      if (x_size[1] < (unsigned char)b_d_data[0]) {
        b_y->size[0] = 1;
        b_y->size[1] = 0;
      } else {
        i31 = b_y->size[0] * b_y->size[1];
        b_y->size[0] = 1;
        idx = x_size[1] - (unsigned char)b_d_data[0];
        b_y->size[1] = idx + 1;
        emxEnsureCapacity_real_T(b_y, i31);
        for (i31 = 0; i31 <= idx; i31++) {
          b_y->data[i31] = (unsigned int)(unsigned char)b_d_data[0] + i31;
        }
      }

      imaxLast_size_idx_0 = 1;
      imaxLast_size_idx_1 = b_y->size[1];
      idx = b_y->size[0] * b_y->size[1];
      for (i31 = 0; i31 < idx; i31++) {
        imaxLast_data[i31] = b_y->data[i31];
      }

      iminLast_size_idx_1 = 0;
    }

    /* for each element */
    maxct = 0.0;
    minct = 0.0;
    for (i31 = 0; i31 < loop_ub_tmp; i31++) {
      b_d_data[i31] = x_data[(int)first_data[i31] - 2];
    }

    direction0_size[0] = 1;
    direction0_size[1] = first_size[1];
    for (i31 = 0; i31 < loop_ub_tmp; i31++) {
      direction0_data[i31] = x_data[(int)first_data[i31] - 1] - b_d_data[i31];
    }

    d_sign(direction0_data, direction0_size);
    constant = 0.0;

    /* the following is to convert k bounds to scalar for matlab coder */
    idx = loop_ub_tmp - 1;
    for (i31 = 0; i31 <= idx; i31++) {
      first_data[i31]++;
    }

    idx = nx - 1;
    for (i31 = 0; i31 <= idx; i31++) {
      last_data[i31]++;
    }

    i31 = (int)first_data[0];
    i32 = (int)last_data[0] - i31;
    for (ii_size_idx_1 = 0; ii_size_idx_1 <= i32; ii_size_idx_1++) {
      idx = i31 + ii_size_idx_1;

      /* current trajectory */
      direction = x_data[idx - 1] - x_data[idx - 2];
      e_sign(&direction);

      /* if no change */
      if (direction == 0.0) {
        constant++;

        /* otherwise */
      } else {
        /* The following is also for matlab coder, to identify that */
        /* direction 0 is a scalar */
        /* if local minimum */
        if ((direction == 1.0) && (direction0_data[0] == -1.0)) {
          /* update min/imin */
          minct = (minct + 1.0) + constant;
          ndbl = minct - constant;
          if (ndbl > minct) {
            loop_ub_tmp = 1;
          } else {
            loop_ub_tmp = (int)ndbl;
          }

          constant = ((double)idx - 1.0) - constant;
          if ((double)idx - 1.0 < constant) {
            b_y->size[0] = 1;
            b_y->size[1] = 0;
          } else if (rtIsInf(constant) && (constant == (double)idx - 1.0)) {
            nx = b_y->size[0] * b_y->size[1];
            b_y->size[0] = 1;
            b_y->size[1] = 1;
            emxEnsureCapacity_real_T(b_y, nx);
            b_y->data[0] = rtNaN;
          } else if (constant == constant) {
            nx = b_y->size[0] * b_y->size[1];
            b_y->size[0] = 1;
            idx = (int)(((double)idx - 1.0) - constant);
            b_y->size[1] = idx + 1;
            emxEnsureCapacity_real_T(b_y, nx);
            for (nx = 0; nx <= idx; nx++) {
              b_y->data[nx] = constant + (double)nx;
            }
          } else {
            ndbl = floor((((double)idx - 1.0) - constant) + 0.5);
            apnd = constant + ndbl;
            cdiff = apnd - ((double)idx - 1.0);
            if (fabs(cdiff) < 4.4408920985006262E-16 * fmax(fabs(constant), idx
                 - 1)) {
              ndbl++;
              apnd = (double)idx - 1.0;
            } else if (cdiff > 0.0) {
              apnd = constant + (ndbl - 1.0);
            } else {
              ndbl++;
            }

            if (ndbl >= 0.0) {
              ii = (int)ndbl;
            } else {
              ii = 0;
            }

            nx = b_y->size[0] * b_y->size[1];
            b_y->size[0] = 1;
            b_y->size[1] = ii;
            emxEnsureCapacity_real_T(b_y, nx);
            if (ii > 0) {
              b_y->data[0] = constant;
              if (ii > 1) {
                b_y->data[ii - 1] = apnd;
                nx = (ii - 1) / 2;
                for (idx = 0; idx <= nx - 2; idx++) {
                  b_y->data[1 + idx] = constant + (1.0 + (double)idx);
                  b_y->data[(ii - idx) - 2] = apnd - (1.0 + (double)idx);
                }

                if (nx << 1 == ii - 1) {
                  b_y->data[nx] = (constant + apnd) / 2.0;
                } else {
                  b_y->data[nx] = constant + (double)nx;
                  b_y->data[nx + 1] = apnd - (double)nx;
                }
              }
            }
          }

          idx = b_y->size[1];
          for (nx = 0; nx < idx; nx++) {
            imin->data[(loop_ub_tmp + nx) - 1] = b_y->data[nx];
          }

          /* if local maximum */
        } else {
          if ((direction == -1.0) && (direction0_data[0] == 1.0)) {
            /* update max/imax */
            maxct = (maxct + 1.0) + constant;
            ndbl = maxct - constant;
            if (ndbl > maxct) {
              loop_ub_tmp = 1;
            } else {
              loop_ub_tmp = (int)ndbl;
            }

            constant = ((double)idx - 1.0) - constant;
            if ((double)idx - 1.0 < constant) {
              b_y->size[0] = 1;
              b_y->size[1] = 0;
            } else if (rtIsInf(constant) && (constant == (double)idx - 1.0)) {
              nx = b_y->size[0] * b_y->size[1];
              b_y->size[0] = 1;
              b_y->size[1] = 1;
              emxEnsureCapacity_real_T(b_y, nx);
              b_y->data[0] = rtNaN;
            } else if (constant == constant) {
              nx = b_y->size[0] * b_y->size[1];
              b_y->size[0] = 1;
              idx = (int)(((double)idx - 1.0) - constant);
              b_y->size[1] = idx + 1;
              emxEnsureCapacity_real_T(b_y, nx);
              for (nx = 0; nx <= idx; nx++) {
                b_y->data[nx] = constant + (double)nx;
              }
            } else {
              ndbl = floor((((double)idx - 1.0) - constant) + 0.5);
              apnd = constant + ndbl;
              cdiff = apnd - ((double)idx - 1.0);
              if (fabs(cdiff) < 4.4408920985006262E-16 * fmax(fabs(constant),
                   idx - 1)) {
                ndbl++;
                apnd = (double)idx - 1.0;
              } else if (cdiff > 0.0) {
                apnd = constant + (ndbl - 1.0);
              } else {
                ndbl++;
              }

              if (ndbl >= 0.0) {
                ii = (int)ndbl;
              } else {
                ii = 0;
              }

              nx = b_y->size[0] * b_y->size[1];
              b_y->size[0] = 1;
              b_y->size[1] = ii;
              emxEnsureCapacity_real_T(b_y, nx);
              if (ii > 0) {
                b_y->data[0] = constant;
                if (ii > 1) {
                  b_y->data[ii - 1] = apnd;
                  nx = (ii - 1) / 2;
                  for (idx = 0; idx <= nx - 2; idx++) {
                    b_y->data[1 + idx] = constant + (1.0 + (double)idx);
                    b_y->data[(ii - idx) - 2] = apnd - (1.0 + (double)idx);
                  }

                  if (nx << 1 == ii - 1) {
                    b_y->data[nx] = (constant + apnd) / 2.0;
                  } else {
                    b_y->data[nx] = constant + (double)nx;
                    b_y->data[nx + 1] = apnd - (double)nx;
                  }
                }
              }
            }

            idx = b_y->size[1];
            for (nx = 0; nx < idx; nx++) {
              imax->data[(loop_ub_tmp + nx) - 1] = b_y->data[nx];
            }
          }
        }

        /* current trajectory is next iteration previous */
        direction0_data[0] = direction;

        /* no consecutive constant */
        constant = 0.0;
      }
    }

    emxFree_real_T(&b_y);

    /* finish */
    if ((imaxFirst_size_idx_0 != 0) && (imaxFirst_size_idx_1 != 0)) {
      input_sizes_idx_1 = (unsigned char)imaxFirst_size_idx_1;
    } else {
      input_sizes_idx_1 = 0U;
    }

    emxInitMatrix_cell_wrap_43(reshapes);
    i31 = reshapes[0].f1->size[0] * reshapes[0].f1->size[1];
    reshapes[0].f1->size[0] = 1;
    reshapes[0].f1->size[1] = input_sizes_idx_1;
    emxEnsureCapacity_real_T(reshapes[0].f1, i31);
    idx = input_sizes_idx_1;
    for (i31 = 0; i31 < idx; i31++) {
      reshapes[0].f1->data[i31] = imaxFirst_data[i31];
    }

    if (imax->size[1] != 0) {
      input_sizes_idx_1 = (unsigned char)imax->size[1];
    } else {
      input_sizes_idx_1 = 0U;
    }

    i31 = reshapes[1].f1->size[0] * reshapes[1].f1->size[1];
    reshapes[1].f1->size[0] = 1;
    reshapes[1].f1->size[1] = input_sizes_idx_1;
    emxEnsureCapacity_real_T(reshapes[1].f1, i31);
    idx = input_sizes_idx_1;
    for (i31 = 0; i31 < idx; i31++) {
      reshapes[1].f1->data[i31] = imax->data[i31];
    }

    if ((imaxLast_size_idx_0 != 0) && (imaxLast_size_idx_1 != 0)) {
      input_sizes_idx_1 = (unsigned char)imaxLast_size_idx_1;
    } else {
      input_sizes_idx_1 = 0U;
    }

    i31 = reshapes[2].f1->size[0] * reshapes[2].f1->size[1];
    reshapes[2].f1->size[0] = 1;
    reshapes[2].f1->size[1] = input_sizes_idx_1;
    emxEnsureCapacity_real_T(reshapes[2].f1, i31);
    idx = input_sizes_idx_1;
    for (i31 = 0; i31 < idx; i31++) {
      reshapes[2].f1->data[i31] = imaxLast_data[i31];
    }

    emxInit_real_T(&result, 2);
    i31 = result->size[0] * result->size[1];
    result->size[0] = reshapes[0].f1->size[0];
    result->size[1] = (reshapes[0].f1->size[1] + reshapes[1].f1->size[1]) +
      reshapes[2].f1->size[1];
    emxEnsureCapacity_real_T(result, i31);
    idx = reshapes[0].f1->size[1];
    for (i31 = 0; i31 < idx; i31++) {
      nx = reshapes[0].f1->size[0];
      for (i32 = 0; i32 < nx; i32++) {
        result->data[i32 + result->size[0] * i31] = reshapes[0].f1->data[i32 +
          reshapes[0].f1->size[0] * i31];
      }
    }

    idx = reshapes[1].f1->size[1];
    for (i31 = 0; i31 < idx; i31++) {
      nx = reshapes[1].f1->size[0];
      for (i32 = 0; i32 < nx; i32++) {
        result->data[i32 + result->size[0] * (i31 + reshapes[0].f1->size[1])] =
          reshapes[1].f1->data[i32 + reshapes[1].f1->size[0] * i31];
      }
    }

    idx = reshapes[2].f1->size[1];
    for (i31 = 0; i31 < idx; i31++) {
      nx = reshapes[2].f1->size[0];
      for (i32 = 0; i32 < nx; i32++) {
        result->data[i32 + result->size[0] * ((i31 + reshapes[0].f1->size[1]) +
          reshapes[1].f1->size[1])] = reshapes[2].f1->data[i32 + reshapes[2].
          f1->size[0] * i31];
      }
    }

    emxFreeMatrix_cell_wrap_43(reshapes);
    result_size[0] = result->size[0];
    result_size[1] = result->size[1];
    idx = result->size[0] * result->size[1];
    for (i31 = 0; i31 < idx; i31++) {
      b_result_data[i31] = (result->data[i31] == 0.0);
    }

    result_data.data = &b_result_data[0];
    result_data.size = &result_size[0];
    result_data.allocatedSize = 4592;
    result_data.numDimensions = 2;
    result_data.canFreeData = false;
    c_nullAssignment(result, &result_data);
    i31 = imax->size[0] * imax->size[1];
    imax->size[0] = result->size[0];
    imax->size[1] = result->size[1];
    emxEnsureCapacity_real_T(imax, i31);
    idx = result->size[0] * result->size[1];
    for (i31 = 0; i31 < idx; i31++) {
      imax->data[i31] = result->data[i31];
    }

    i31 = b_max->size[0] * b_max->size[1];
    b_max->size[0] = imax->size[0];
    b_max->size[1] = imax->size[1];
    emxEnsureCapacity_real_T(b_max, i31);
    idx = imax->size[0] * imax->size[1];
    for (i31 = 0; i31 < idx; i31++) {
      b_max->data[i31] = x_data[(int)imax->data[i31] - 1];
    }

    emxInit_real_T(&b_result, 2);
    if (d_size[1] != 0) {
      input_sizes_idx_1 = (unsigned char)d_size[1];
    } else {
      input_sizes_idx_1 = 0U;
    }

    if (imin->size[1] != 0) {
      b_input_sizes_idx_1 = (unsigned char)imin->size[1];
    } else {
      b_input_sizes_idx_1 = 0U;
    }

    if (iminLast_size_idx_1 != 0) {
      c_input_sizes_idx_1 = (unsigned char)iminLast_size_idx_1;
    } else {
      c_input_sizes_idx_1 = 0U;
    }

    if (d_size[1] != 0) {
      nx = (unsigned char)d_size[1];
    } else {
      nx = 0;
    }

    i31 = b_result->size[0] * b_result->size[1];
    b_result->size[0] = 1;
    b_result->size[1] = (input_sizes_idx_1 + b_input_sizes_idx_1) +
      c_input_sizes_idx_1;
    emxEnsureCapacity_real_T(b_result, i31);
    idx = input_sizes_idx_1;
    for (i31 = 0; i31 < idx; i31++) {
      for (i32 = 0; i32 < 1; i32++) {
        b_result->data[i31] = d_data[i31];
      }
    }

    idx = b_input_sizes_idx_1;
    for (i31 = 0; i31 < idx; i31++) {
      for (i32 = 0; i32 < 1; i32++) {
        b_result->data[i31 + nx] = imin->data[i31];
      }
    }

    emxFree_real_T(&imin);
    idx = c_input_sizes_idx_1;
    for (i31 = 0; i31 < idx; i31++) {
      for (i32 = 0; i32 < 1; i32++) {
        b_result->data[(i31 + nx) + b_input_sizes_idx_1] = iminLast_data[i31];
      }
    }

    i31 = result->size[0] * result->size[1];
    result->size[0] = 1;
    result->size[1] = b_result->size[1];
    emxEnsureCapacity_real_T(result, i31);
    idx = b_result->size[0] * b_result->size[1];
    for (i31 = 0; i31 < idx; i31++) {
      result->data[i31] = b_result->data[i31];
    }

    b_result_size[0] = 1;
    b_result_size[1] = b_result->size[1];
    idx = b_result->size[0] * b_result->size[1];
    for (i31 = 0; i31 < idx; i31++) {
      c_result_data[i31] = (b_result->data[i31] == 0.0);
    }

    emxFree_real_T(&b_result);
    d_result_data.data = &c_result_data[0];
    d_result_data.size = &b_result_size[0];
    d_result_data.allocatedSize = 4592;
    d_result_data.numDimensions = 2;
    d_result_data.canFreeData = false;
    c_nullAssignment(result, &d_result_data);
    emxFree_real_T(&result);
  }
}

void c_extrema(const double x_data[], const int x_size[1], emxArray_real_T
               *b_max, emxArray_real_T *imax)
{
  static double d_data[4095];
  int d_size[1];
  int i33;
  int idx;
  emxArray_real_T *imin;
  int b_x_size[1];
  int nx;
  boolean_T b_x_data[4096];
  int ii_size_idx_0;
  int ii;
  boolean_T exitg1;
  short ii_data[4096];
  emxArray_real_T *d;
  static double first_data[4096];
  int tmp_size[2];
  emxArray_int32_T tmp_data;
  int b_tmp_data[4095];
  int first_size_idx_0;
  static double last_data[4096];
  emxArray_int32_T c_tmp_data;
  emxArray_boolean_T c_x_data;
  emxArray_real_T *y;
  int iminFirst_size_idx_1;
  int imaxFirst_size_idx_1;
  static double iminFirst_data[4095];
  static double imaxFirst_data[4095];
  emxArray_boolean_T d_x_data;
  emxArray_real_T *b_y;
  double ndbl;
  double apnd;
  double cdiff;
  double absa;
  int imaxLast_size_idx_0;
  int iminLast_size_idx_1;
  int imaxLast_size_idx_1;
  double iminLast_data[4095];
  double imaxLast_data[4095];
  double maxct;
  double minct;
  int direction0_size[1];
  static double d_tmp_data[4096];
  static double direction0_data[4096];
  int k;
  double b_k;
  double direction;
  short input_sizes_idx_1;
  cell_wrap_43 reshapes[3];
  emxArray_real_T *result;
  int result_size[2];
  emxArray_boolean_T result_data;
  boolean_T b_result_data[12285];
  emxArray_real_T *b_result;
  short b_input_sizes_idx_1;
  short c_input_sizes_idx_1;
  int b_result_size[2];
  boolean_T c_result_data[12285];
  emxArray_boolean_T d_result_data;

  /* Reed Gurchiek, */
  /*    extrema finds local minima and maxima of the vector x */
  /*  */
  /* ---------------------------INPUTS----------------------------------------- */
  /*  */
  /*    x: */
  /*        n-element array for which the local minima and maxima will be found */
  /*  */
  /* --------------------------OUTPUTS----------------------------------------- */
  /*  */
  /*    max,imax: */
  /*        local maxima values (max) and their indices (imax) */
  /*  */
  /*    min,imin: */
  /*        local minima values (min) and their indices (imin) */
  /*  */
  /* -------------------------------------------------------------------------- */
  /*  extrema */
  /* initialize */
  b_max->size[0] = 0;
  b_max->size[1] = 0;
  imax->size[0] = 0;
  imax->size[1] = 0;

  /* get differences */
  c_diff(x_data, x_size, d_data, d_size);

  /* get extrema if any nonzero changes */
  if (d_any(d_data, d_size)) {
    /* allocation */
    i33 = imax->size[0] * imax->size[1];
    imax->size[0] = 1;
    imax->size[1] = d_size[0];
    emxEnsureCapacity_real_T(imax, i33);
    idx = d_size[0];
    for (i33 = 0; i33 < idx; i33++) {
      imax->data[i33] = 0.0;
    }

    emxInit_real_T(&imin, 2);
    i33 = imin->size[0] * imin->size[1];
    imin->size[0] = 1;
    imin->size[1] = d_size[0];
    emxEnsureCapacity_real_T(imin, i33);
    idx = d_size[0];
    for (i33 = 0; i33 < idx; i33++) {
      imin->data[i33] = 0.0;
    }

    /* endpoints are always local extrema */
    b_x_size[0] = x_size[0];
    idx = x_size[0];
    for (i33 = 0; i33 < idx; i33++) {
      b_x_data[i33] = (x_data[i33] != x_data[0]);
    }

    nx = b_x_size[0];
    idx = 0;
    ii_size_idx_0 = b_x_size[0];
    ii = 0;
    exitg1 = false;
    while ((!exitg1) && (ii <= nx - 1)) {
      if (b_x_data[ii]) {
        idx++;
        ii_data[idx - 1] = (short)(ii + 1);
        if (idx >= nx) {
          exitg1 = true;
        } else {
          ii++;
        }
      } else {
        ii++;
      }
    }

    if (b_x_size[0] == 1) {
      if (idx == 0) {
        ii_size_idx_0 = 0;
      }
    } else if (1 > idx) {
      ii_size_idx_0 = 0;
    } else {
      ii_size_idx_0 = idx;
    }

    for (i33 = 0; i33 < ii_size_idx_0; i33++) {
      first_data[i33] = ii_data[i33];
    }

    emxInit_real_T(&d, 1);
    i33 = d->size[0];
    d->size[0] = ii_size_idx_0;
    emxEnsureCapacity_real_T(d, i33);
    for (i33 = 0; i33 < ii_size_idx_0; i33++) {
      d->data[i33] = first_data[i33];
    }

    idx = ii_size_idx_0 - 2;
    tmp_size[0] = 1;
    tmp_size[1] = ii_size_idx_0 - 1;
    for (i33 = 0; i33 <= idx; i33++) {
      b_tmp_data[i33] = 2 + i33;
    }

    tmp_data.data = &b_tmp_data[0];
    tmp_data.size = &tmp_size[0];
    tmp_data.allocatedSize = 4095;
    tmp_data.numDimensions = 2;
    tmp_data.canFreeData = false;
    b_nullAssignment(d, &tmp_data);
    first_size_idx_0 = d->size[0];
    idx = d->size[0];
    for (i33 = 0; i33 < idx; i33++) {
      first_data[i33] = d->data[i33];
    }

    b_x_size[0] = x_size[0];
    idx = x_size[0];
    for (i33 = 0; i33 < idx; i33++) {
      b_x_data[i33] = (x_data[i33] != x_data[x_size[0] - 1]);
    }

    nx = b_x_size[0];
    idx = 0;
    ii_size_idx_0 = b_x_size[0];
    ii = 0;
    exitg1 = false;
    while ((!exitg1) && (ii <= nx - 1)) {
      if (b_x_data[ii]) {
        idx++;
        ii_data[idx - 1] = (short)(ii + 1);
        if (idx >= nx) {
          exitg1 = true;
        } else {
          ii++;
        }
      } else {
        ii++;
      }
    }

    if (b_x_size[0] == 1) {
      if (idx == 0) {
        ii_size_idx_0 = 0;
      }
    } else if (1 > idx) {
      ii_size_idx_0 = 0;
    } else {
      ii_size_idx_0 = idx;
    }

    for (i33 = 0; i33 < ii_size_idx_0; i33++) {
      last_data[i33] = ii_data[i33];
    }

    i33 = d->size[0];
    d->size[0] = ii_size_idx_0;
    emxEnsureCapacity_real_T(d, i33);
    for (i33 = 0; i33 < ii_size_idx_0; i33++) {
      d->data[i33] = last_data[i33];
    }

    idx = ii_size_idx_0 - 2;
    tmp_size[0] = 1;
    tmp_size[1] = ii_size_idx_0 - 1;
    for (i33 = 0; i33 <= idx; i33++) {
      b_tmp_data[i33] = 1 + i33;
    }

    c_tmp_data.data = &b_tmp_data[0];
    c_tmp_data.size = &tmp_size[0];
    c_tmp_data.allocatedSize = 4095;
    c_tmp_data.numDimensions = 2;
    c_tmp_data.canFreeData = false;
    b_nullAssignment(d, &c_tmp_data);
    nx = d->size[0];
    idx = d->size[0];
    for (i33 = 0; i33 < idx; i33++) {
      last_data[i33] = d->data[i33];
    }

    b_x_size[0] = first_size_idx_0;
    for (i33 = 0; i33 < first_size_idx_0; i33++) {
      b_x_data[i33] = (x_data[0] < x_data[(int)first_data[i33] - 1]);
    }

    c_x_data.data = &b_x_data[0];
    c_x_data.size = &b_x_size[0];
    c_x_data.allocatedSize = 4096;
    c_x_data.numDimensions = 1;
    c_x_data.canFreeData = false;
    emxInit_real_T(&y, 2);
    if (b_ifWhileCond(&c_x_data)) {
      i33 = d->size[0];
      d->size[0] = first_size_idx_0;
      emxEnsureCapacity_real_T(d, i33);
      for (i33 = 0; i33 < first_size_idx_0; i33++) {
        d->data[i33] = first_data[i33] - 1.0;
      }

      if (rtIsNaN(d->data[0])) {
        i33 = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(y, i33);
        y->data[0] = rtNaN;
      } else if (d->data[0] < 1.0) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else {
        i33 = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = (int)floor(d->data[0] - 1.0) + 1;
        emxEnsureCapacity_real_T(y, i33);
        idx = (int)floor(d->data[0] - 1.0);
        for (i33 = 0; i33 <= idx; i33++) {
          y->data[i33] = 1.0 + (double)i33;
        }
      }

      iminFirst_size_idx_1 = y->size[1];
      idx = y->size[0] * y->size[1];
      for (i33 = 0; i33 < idx; i33++) {
        iminFirst_data[i33] = y->data[i33];
      }

      ii_size_idx_0 = 0;
      imaxFirst_size_idx_1 = 0;
    } else {
      iminFirst_size_idx_1 = 0;
      i33 = d->size[0];
      d->size[0] = first_size_idx_0;
      emxEnsureCapacity_real_T(d, i33);
      for (i33 = 0; i33 < first_size_idx_0; i33++) {
        d->data[i33] = first_data[i33] - 1.0;
      }

      if (rtIsNaN(d->data[0])) {
        i33 = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(y, i33);
        y->data[0] = rtNaN;
      } else if (d->data[0] < 1.0) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else {
        i33 = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = (int)floor(d->data[0] - 1.0) + 1;
        emxEnsureCapacity_real_T(y, i33);
        idx = (int)floor(d->data[0] - 1.0);
        for (i33 = 0; i33 <= idx; i33++) {
          y->data[i33] = 1.0 + (double)i33;
        }
      }

      ii_size_idx_0 = 1;
      imaxFirst_size_idx_1 = y->size[1];
      idx = y->size[0] * y->size[1];
      for (i33 = 0; i33 < idx; i33++) {
        imaxFirst_data[i33] = y->data[i33];
      }
    }

    emxFree_real_T(&y);
    b_x_size[0] = nx;
    for (i33 = 0; i33 < nx; i33++) {
      b_x_data[i33] = (x_data[x_size[0] - 1] < x_data[(int)last_data[i33] - 1]);
    }

    d_x_data.data = &b_x_data[0];
    d_x_data.size = &b_x_size[0];
    d_x_data.allocatedSize = 4096;
    d_x_data.numDimensions = 1;
    d_x_data.canFreeData = false;
    emxInit_real_T(&b_y, 2);
    if (b_ifWhileCond(&d_x_data)) {
      i33 = d->size[0];
      d->size[0] = nx;
      emxEnsureCapacity_real_T(d, i33);
      for (i33 = 0; i33 < nx; i33++) {
        d->data[i33] = last_data[i33] + 1.0;
      }

      if (rtIsNaN(d->data[0])) {
        i33 = b_y->size[0] * b_y->size[1];
        b_y->size[0] = 1;
        b_y->size[1] = 1;
        emxEnsureCapacity_real_T(b_y, i33);
        b_y->data[0] = rtNaN;
      } else if (x_size[0] < d->data[0]) {
        b_y->size[0] = 1;
        b_y->size[1] = 0;
      } else if (floor(d->data[0]) == d->data[0]) {
        i33 = b_y->size[0] * b_y->size[1];
        b_y->size[0] = 1;
        b_y->size[1] = (int)floor((double)x_size[0] - d->data[0]) + 1;
        emxEnsureCapacity_real_T(b_y, i33);
        idx = (int)floor((double)x_size[0] - d->data[0]);
        for (i33 = 0; i33 <= idx; i33++) {
          b_y->data[i33] = d->data[0] + (double)i33;
        }
      } else {
        ndbl = floor(((double)x_size[0] - d->data[0]) + 0.5);
        apnd = d->data[0] + ndbl;
        cdiff = apnd - (double)x_size[0];
        absa = d->data[0];
        if (fabs(cdiff) < 4.4408920985006262E-16 * fmax(absa, x_size[0])) {
          ndbl++;
          apnd = x_size[0];
        } else if (cdiff > 0.0) {
          apnd = d->data[0] + (ndbl - 1.0);
        } else {
          ndbl++;
        }

        if (ndbl >= 0.0) {
          ii = (int)ndbl;
        } else {
          ii = 0;
        }

        i33 = b_y->size[0] * b_y->size[1];
        b_y->size[0] = 1;
        b_y->size[1] = ii;
        emxEnsureCapacity_real_T(b_y, i33);
        if (ii > 0) {
          b_y->data[0] = d->data[0];
          if (ii > 1) {
            b_y->data[ii - 1] = apnd;
            idx = (ii - 1) / 2;
            for (k = 0; k <= idx - 2; k++) {
              b_y->data[1 + k] = d->data[0] + (1.0 + (double)k);
              b_y->data[(ii - k) - 2] = apnd - (1.0 + (double)k);
            }

            if (idx << 1 == ii - 1) {
              b_y->data[idx] = (d->data[0] + apnd) / 2.0;
            } else {
              b_y->data[idx] = d->data[0] + (double)idx;
              b_y->data[idx + 1] = apnd - (double)idx;
            }
          }
        }
      }

      iminLast_size_idx_1 = b_y->size[1];
      idx = b_y->size[0] * b_y->size[1];
      for (i33 = 0; i33 < idx; i33++) {
        iminLast_data[i33] = b_y->data[i33];
      }

      imaxLast_size_idx_0 = 0;
      imaxLast_size_idx_1 = 0;
    } else {
      i33 = d->size[0];
      d->size[0] = nx;
      emxEnsureCapacity_real_T(d, i33);
      for (i33 = 0; i33 < nx; i33++) {
        d->data[i33] = last_data[i33] + 1.0;
      }

      if (rtIsNaN(d->data[0])) {
        i33 = b_y->size[0] * b_y->size[1];
        b_y->size[0] = 1;
        b_y->size[1] = 1;
        emxEnsureCapacity_real_T(b_y, i33);
        b_y->data[0] = rtNaN;
      } else if (x_size[0] < d->data[0]) {
        b_y->size[0] = 1;
        b_y->size[1] = 0;
      } else if (floor(d->data[0]) == d->data[0]) {
        i33 = b_y->size[0] * b_y->size[1];
        b_y->size[0] = 1;
        b_y->size[1] = (int)floor((double)x_size[0] - d->data[0]) + 1;
        emxEnsureCapacity_real_T(b_y, i33);
        idx = (int)floor((double)x_size[0] - d->data[0]);
        for (i33 = 0; i33 <= idx; i33++) {
          b_y->data[i33] = d->data[0] + (double)i33;
        }
      } else {
        ndbl = floor(((double)x_size[0] - d->data[0]) + 0.5);
        apnd = d->data[0] + ndbl;
        cdiff = apnd - (double)x_size[0];
        absa = d->data[0];
        if (fabs(cdiff) < 4.4408920985006262E-16 * fmax(absa, x_size[0])) {
          ndbl++;
          apnd = x_size[0];
        } else if (cdiff > 0.0) {
          apnd = d->data[0] + (ndbl - 1.0);
        } else {
          ndbl++;
        }

        if (ndbl >= 0.0) {
          ii = (int)ndbl;
        } else {
          ii = 0;
        }

        i33 = b_y->size[0] * b_y->size[1];
        b_y->size[0] = 1;
        b_y->size[1] = ii;
        emxEnsureCapacity_real_T(b_y, i33);
        if (ii > 0) {
          b_y->data[0] = d->data[0];
          if (ii > 1) {
            b_y->data[ii - 1] = apnd;
            idx = (ii - 1) / 2;
            for (k = 0; k <= idx - 2; k++) {
              b_y->data[1 + k] = d->data[0] + (1.0 + (double)k);
              b_y->data[(ii - k) - 2] = apnd - (1.0 + (double)k);
            }

            if (idx << 1 == ii - 1) {
              b_y->data[idx] = (d->data[0] + apnd) / 2.0;
            } else {
              b_y->data[idx] = d->data[0] + (double)idx;
              b_y->data[idx + 1] = apnd - (double)idx;
            }
          }
        }
      }

      imaxLast_size_idx_0 = 1;
      imaxLast_size_idx_1 = b_y->size[1];
      idx = b_y->size[0] * b_y->size[1];
      for (i33 = 0; i33 < idx; i33++) {
        imaxLast_data[i33] = b_y->data[i33];
      }

      iminLast_size_idx_1 = 0;
    }

    emxFree_real_T(&d);

    /* for each element */
    maxct = 0.0;
    minct = 0.0;
    for (i33 = 0; i33 < first_size_idx_0; i33++) {
      d_tmp_data[i33] = x_data[(int)(first_data[i33] - 1.0) - 1];
    }

    direction0_size[0] = first_size_idx_0;
    for (i33 = 0; i33 < first_size_idx_0; i33++) {
      direction0_data[i33] = x_data[(int)first_data[i33] - 1] - d_tmp_data[i33];
    }

    f_sign(direction0_data, direction0_size);
    absa = 0.0;

    /* the following is to convert k bounds to scalar for matlab coder */
    for (i33 = 0; i33 < first_size_idx_0; i33++) {
      first_data[i33]++;
    }

    for (i33 = 0; i33 < nx; i33++) {
      last_data[i33]++;
    }

    i33 = (int)(last_data[0] + (1.0 - first_data[0]));
    for (k = 0; k < i33; k++) {
      b_k = first_data[0] + (double)k;

      /* current trajectory */
      direction = x_data[(int)b_k - 1] - x_data[(int)(b_k - 1.0) - 1];
      e_sign(&direction);

      /* if no change */
      if (direction == 0.0) {
        absa++;

        /* otherwise */
      } else {
        /* The following is also for matlab coder, to identify that */
        /* direction 0 is a scalar */
        /* if local minimum */
        if ((direction == 1.0) && (direction0_data[0] == -1.0)) {
          /* update min/imin */
          minct = (minct + 1.0) + absa;
          ndbl = minct - absa;
          if (ndbl > minct) {
            first_size_idx_0 = 1;
          } else {
            first_size_idx_0 = (int)ndbl;
          }

          absa = (b_k - 1.0) - absa;
          if (rtIsNaN(absa) || rtIsNaN(b_k - 1.0)) {
            nx = b_y->size[0] * b_y->size[1];
            b_y->size[0] = 1;
            b_y->size[1] = 1;
            emxEnsureCapacity_real_T(b_y, nx);
            b_y->data[0] = rtNaN;
          } else if (b_k - 1.0 < absa) {
            b_y->size[0] = 1;
            b_y->size[1] = 0;
          } else if (rtIsInf(absa) && (absa == b_k - 1.0)) {
            nx = b_y->size[0] * b_y->size[1];
            b_y->size[0] = 1;
            b_y->size[1] = 1;
            emxEnsureCapacity_real_T(b_y, nx);
            b_y->data[0] = rtNaN;
          } else if (floor(absa) == absa) {
            nx = b_y->size[0] * b_y->size[1];
            b_y->size[0] = 1;
            idx = (int)floor((b_k - 1.0) - absa);
            b_y->size[1] = idx + 1;
            emxEnsureCapacity_real_T(b_y, nx);
            for (nx = 0; nx <= idx; nx++) {
              b_y->data[nx] = absa + (double)nx;
            }
          } else {
            ndbl = floor(((b_k - 1.0) - absa) + 0.5);
            apnd = absa + ndbl;
            cdiff = apnd - (b_k - 1.0);
            if (fabs(cdiff) < 4.4408920985006262E-16 * fmax(fabs(absa), b_k -
                 1.0)) {
              ndbl++;
              apnd = b_k - 1.0;
            } else if (cdiff > 0.0) {
              apnd = absa + (ndbl - 1.0);
            } else {
              ndbl++;
            }

            if (ndbl >= 0.0) {
              ii = (int)ndbl;
            } else {
              ii = 0;
            }

            nx = b_y->size[0] * b_y->size[1];
            b_y->size[0] = 1;
            b_y->size[1] = ii;
            emxEnsureCapacity_real_T(b_y, nx);
            if (ii > 0) {
              b_y->data[0] = absa;
              if (ii > 1) {
                b_y->data[ii - 1] = apnd;
                idx = (ii - 1) / 2;
                for (nx = 0; nx <= idx - 2; nx++) {
                  b_y->data[1 + nx] = absa + (1.0 + (double)nx);
                  b_y->data[(ii - nx) - 2] = apnd - (1.0 + (double)nx);
                }

                if (idx << 1 == ii - 1) {
                  b_y->data[idx] = (absa + apnd) / 2.0;
                } else {
                  b_y->data[idx] = absa + (double)idx;
                  b_y->data[idx + 1] = apnd - (double)idx;
                }
              }
            }
          }

          idx = b_y->size[1];
          for (nx = 0; nx < idx; nx++) {
            imin->data[(first_size_idx_0 + nx) - 1] = b_y->data[nx];
          }

          /* if local maximum */
        } else {
          if ((direction == -1.0) && (direction0_data[0] == 1.0)) {
            /* update max/imax */
            maxct = (maxct + 1.0) + absa;
            ndbl = maxct - absa;
            if (ndbl > maxct) {
              first_size_idx_0 = 1;
            } else {
              first_size_idx_0 = (int)ndbl;
            }

            absa = (b_k - 1.0) - absa;
            if (rtIsNaN(absa) || rtIsNaN(b_k - 1.0)) {
              nx = b_y->size[0] * b_y->size[1];
              b_y->size[0] = 1;
              b_y->size[1] = 1;
              emxEnsureCapacity_real_T(b_y, nx);
              b_y->data[0] = rtNaN;
            } else if (b_k - 1.0 < absa) {
              b_y->size[0] = 1;
              b_y->size[1] = 0;
            } else if (rtIsInf(absa) && (absa == b_k - 1.0)) {
              nx = b_y->size[0] * b_y->size[1];
              b_y->size[0] = 1;
              b_y->size[1] = 1;
              emxEnsureCapacity_real_T(b_y, nx);
              b_y->data[0] = rtNaN;
            } else if (floor(absa) == absa) {
              nx = b_y->size[0] * b_y->size[1];
              b_y->size[0] = 1;
              idx = (int)floor((b_k - 1.0) - absa);
              b_y->size[1] = idx + 1;
              emxEnsureCapacity_real_T(b_y, nx);
              for (nx = 0; nx <= idx; nx++) {
                b_y->data[nx] = absa + (double)nx;
              }
            } else {
              ndbl = floor(((b_k - 1.0) - absa) + 0.5);
              apnd = absa + ndbl;
              cdiff = apnd - (b_k - 1.0);
              if (fabs(cdiff) < 4.4408920985006262E-16 * fmax(fabs(absa), b_k -
                   1.0)) {
                ndbl++;
                apnd = b_k - 1.0;
              } else if (cdiff > 0.0) {
                apnd = absa + (ndbl - 1.0);
              } else {
                ndbl++;
              }

              if (ndbl >= 0.0) {
                ii = (int)ndbl;
              } else {
                ii = 0;
              }

              nx = b_y->size[0] * b_y->size[1];
              b_y->size[0] = 1;
              b_y->size[1] = ii;
              emxEnsureCapacity_real_T(b_y, nx);
              if (ii > 0) {
                b_y->data[0] = absa;
                if (ii > 1) {
                  b_y->data[ii - 1] = apnd;
                  idx = (ii - 1) / 2;
                  for (nx = 0; nx <= idx - 2; nx++) {
                    b_y->data[1 + nx] = absa + (1.0 + (double)nx);
                    b_y->data[(ii - nx) - 2] = apnd - (1.0 + (double)nx);
                  }

                  if (idx << 1 == ii - 1) {
                    b_y->data[idx] = (absa + apnd) / 2.0;
                  } else {
                    b_y->data[idx] = absa + (double)idx;
                    b_y->data[idx + 1] = apnd - (double)idx;
                  }
                }
              }
            }

            idx = b_y->size[1];
            for (nx = 0; nx < idx; nx++) {
              imax->data[(first_size_idx_0 + nx) - 1] = b_y->data[nx];
            }
          }
        }

        /* current trajectory is next iteration previous */
        direction0_data[0] = direction;

        /* no consecutive constant */
        absa = 0.0;
      }
    }

    emxFree_real_T(&b_y);

    /* finish */
    if ((ii_size_idx_0 != 0) && (imaxFirst_size_idx_1 != 0)) {
      input_sizes_idx_1 = (short)imaxFirst_size_idx_1;
    } else {
      input_sizes_idx_1 = 0;
    }

    emxInitMatrix_cell_wrap_43(reshapes);
    i33 = reshapes[0].f1->size[0] * reshapes[0].f1->size[1];
    reshapes[0].f1->size[0] = 1;
    reshapes[0].f1->size[1] = input_sizes_idx_1;
    emxEnsureCapacity_real_T(reshapes[0].f1, i33);
    idx = input_sizes_idx_1;
    for (i33 = 0; i33 < idx; i33++) {
      reshapes[0].f1->data[i33] = imaxFirst_data[i33];
    }

    if (imax->size[1] != 0) {
      input_sizes_idx_1 = (short)imax->size[1];
    } else {
      input_sizes_idx_1 = 0;
    }

    i33 = reshapes[1].f1->size[0] * reshapes[1].f1->size[1];
    reshapes[1].f1->size[0] = 1;
    reshapes[1].f1->size[1] = input_sizes_idx_1;
    emxEnsureCapacity_real_T(reshapes[1].f1, i33);
    idx = input_sizes_idx_1;
    for (i33 = 0; i33 < idx; i33++) {
      reshapes[1].f1->data[i33] = imax->data[i33];
    }

    if ((imaxLast_size_idx_0 != 0) && (imaxLast_size_idx_1 != 0)) {
      input_sizes_idx_1 = (short)imaxLast_size_idx_1;
    } else {
      input_sizes_idx_1 = 0;
    }

    i33 = reshapes[2].f1->size[0] * reshapes[2].f1->size[1];
    reshapes[2].f1->size[0] = 1;
    reshapes[2].f1->size[1] = input_sizes_idx_1;
    emxEnsureCapacity_real_T(reshapes[2].f1, i33);
    idx = input_sizes_idx_1;
    for (i33 = 0; i33 < idx; i33++) {
      reshapes[2].f1->data[i33] = imaxLast_data[i33];
    }

    emxInit_real_T(&result, 2);
    i33 = result->size[0] * result->size[1];
    result->size[0] = reshapes[0].f1->size[0];
    result->size[1] = (reshapes[0].f1->size[1] + reshapes[1].f1->size[1]) +
      reshapes[2].f1->size[1];
    emxEnsureCapacity_real_T(result, i33);
    idx = reshapes[0].f1->size[1];
    for (i33 = 0; i33 < idx; i33++) {
      nx = reshapes[0].f1->size[0];
      for (first_size_idx_0 = 0; first_size_idx_0 < nx; first_size_idx_0++) {
        result->data[first_size_idx_0 + result->size[0] * i33] = reshapes[0].
          f1->data[first_size_idx_0 + reshapes[0].f1->size[0] * i33];
      }
    }

    idx = reshapes[1].f1->size[1];
    for (i33 = 0; i33 < idx; i33++) {
      nx = reshapes[1].f1->size[0];
      for (first_size_idx_0 = 0; first_size_idx_0 < nx; first_size_idx_0++) {
        result->data[first_size_idx_0 + result->size[0] * (i33 + reshapes[0].
          f1->size[1])] = reshapes[1].f1->data[first_size_idx_0 + reshapes[1].
          f1->size[0] * i33];
      }
    }

    idx = reshapes[2].f1->size[1];
    for (i33 = 0; i33 < idx; i33++) {
      nx = reshapes[2].f1->size[0];
      for (first_size_idx_0 = 0; first_size_idx_0 < nx; first_size_idx_0++) {
        result->data[first_size_idx_0 + result->size[0] * ((i33 + reshapes[0].
          f1->size[1]) + reshapes[1].f1->size[1])] = reshapes[2].f1->
          data[first_size_idx_0 + reshapes[2].f1->size[0] * i33];
      }
    }

    emxFreeMatrix_cell_wrap_43(reshapes);
    result_size[0] = result->size[0];
    result_size[1] = result->size[1];
    idx = result->size[0] * result->size[1];
    for (i33 = 0; i33 < idx; i33++) {
      b_result_data[i33] = (result->data[i33] == 0.0);
    }

    result_data.data = &b_result_data[0];
    result_data.size = &result_size[0];
    result_data.allocatedSize = 12285;
    result_data.numDimensions = 2;
    result_data.canFreeData = false;
    c_nullAssignment(result, &result_data);
    i33 = imax->size[0] * imax->size[1];
    imax->size[0] = result->size[0];
    imax->size[1] = result->size[1];
    emxEnsureCapacity_real_T(imax, i33);
    idx = result->size[0] * result->size[1];
    for (i33 = 0; i33 < idx; i33++) {
      imax->data[i33] = result->data[i33];
    }

    i33 = b_max->size[0] * b_max->size[1];
    b_max->size[0] = imax->size[0];
    b_max->size[1] = imax->size[1];
    emxEnsureCapacity_real_T(b_max, i33);
    idx = imax->size[0] * imax->size[1];
    for (i33 = 0; i33 < idx; i33++) {
      b_max->data[i33] = x_data[(int)imax->data[i33] - 1];
    }

    emxInit_real_T(&b_result, 2);
    if (iminFirst_size_idx_1 != 0) {
      input_sizes_idx_1 = (short)iminFirst_size_idx_1;
    } else {
      input_sizes_idx_1 = 0;
    }

    if (imin->size[1] != 0) {
      b_input_sizes_idx_1 = (short)imin->size[1];
    } else {
      b_input_sizes_idx_1 = 0;
    }

    if (iminLast_size_idx_1 != 0) {
      c_input_sizes_idx_1 = (short)iminLast_size_idx_1;
    } else {
      c_input_sizes_idx_1 = 0;
    }

    if (iminFirst_size_idx_1 != 0) {
      nx = (short)iminFirst_size_idx_1;
    } else {
      nx = 0;
    }

    i33 = b_result->size[0] * b_result->size[1];
    b_result->size[0] = 1;
    b_result->size[1] = (input_sizes_idx_1 + b_input_sizes_idx_1) +
      c_input_sizes_idx_1;
    emxEnsureCapacity_real_T(b_result, i33);
    idx = input_sizes_idx_1;
    for (i33 = 0; i33 < idx; i33++) {
      for (first_size_idx_0 = 0; first_size_idx_0 < 1; first_size_idx_0++) {
        b_result->data[i33] = iminFirst_data[i33];
      }
    }

    idx = b_input_sizes_idx_1;
    for (i33 = 0; i33 < idx; i33++) {
      for (first_size_idx_0 = 0; first_size_idx_0 < 1; first_size_idx_0++) {
        b_result->data[i33 + nx] = imin->data[i33];
      }
    }

    emxFree_real_T(&imin);
    idx = c_input_sizes_idx_1;
    for (i33 = 0; i33 < idx; i33++) {
      for (first_size_idx_0 = 0; first_size_idx_0 < 1; first_size_idx_0++) {
        b_result->data[(i33 + nx) + b_input_sizes_idx_1] = iminLast_data[i33];
      }
    }

    i33 = result->size[0] * result->size[1];
    result->size[0] = 1;
    result->size[1] = b_result->size[1];
    emxEnsureCapacity_real_T(result, i33);
    idx = b_result->size[0] * b_result->size[1];
    for (i33 = 0; i33 < idx; i33++) {
      result->data[i33] = b_result->data[i33];
    }

    b_result_size[0] = 1;
    b_result_size[1] = b_result->size[1];
    idx = b_result->size[0] * b_result->size[1];
    for (i33 = 0; i33 < idx; i33++) {
      c_result_data[i33] = (b_result->data[i33] == 0.0);
    }

    emxFree_real_T(&b_result);
    d_result_data.data = &c_result_data[0];
    d_result_data.size = &b_result_size[0];
    d_result_data.allocatedSize = 12285;
    d_result_data.numDimensions = 2;
    d_result_data.canFreeData = false;
    c_nullAssignment(result, &d_result_data);
    emxFree_real_T(&result);
  }
}

void d_extrema(const double x[500], emxArray_real_T *b_max, emxArray_real_T
               *imax, emxArray_real_T *b_min, emxArray_real_T *imin)
{
  double dv11[499];
  int i48;
  int i;
  int idx;
  boolean_T b_x[500];
  boolean_T exitg1;
  emxArray_real_T *d;
  short ii_data[500];
  int nm1d2;
  int tmp_size[2];
  emxArray_int32_T tmp_data;
  int b_tmp_data[499];
  int first_size_idx_0;
  static double first_data[4096];
  emxArray_int32_T c_tmp_data;
  int x_size[1];
  static double last_data[4096];
  emxArray_boolean_T x_data;
  boolean_T b_x_data[4096];
  emxArray_real_T *y;
  int iminFirst_size_idx_1;
  int imaxFirst_size_idx_0;
  int imaxFirst_size_idx_1;
  double iminFirst_data[499];
  double imaxFirst_data[499];
  emxArray_boolean_T c_x_data;
  static double a_data[4096];
  int n;
  double iminLast_data[499];
  double ndbl;
  double apnd;
  int imaxLast_size_idx_0;
  int imaxLast_size_idx_1;
  double imaxLast_data[499];
  double maxct;
  double minct;
  int direction0_size[1];
  int k;
  static double direction0_data[4096];
  double constant;
  emxArray_real_T *r12;
  double b_k;
  double direction;
  short input_sizes_idx_1;
  cell_wrap_43 reshapes[3];
  double cdiff;
  emxArray_real_T *result;
  int result_size[2];
  emxArray_boolean_T result_data;
  boolean_T b_result_data[5094];
  emxArray_real_T *b_result;
  short b_input_sizes_idx_1;
  int b_result_size[2];
  boolean_T c_result_data[5094];
  emxArray_boolean_T d_result_data;

  /* Reed Gurchiek, */
  /*    extrema finds local minima and maxima of the vector x */
  /*  */
  /* ---------------------------INPUTS----------------------------------------- */
  /*  */
  /*    x: */
  /*        n-element array for which the local minima and maxima will be found */
  /*  */
  /* --------------------------OUTPUTS----------------------------------------- */
  /*  */
  /*    max,imax: */
  /*        local maxima values (max) and their indices (imax) */
  /*  */
  /*    min,imin: */
  /*        local minima values (min) and their indices (imin) */
  /*  */
  /* -------------------------------------------------------------------------- */
  /*  extrema */
  /* initialize */
  b_max->size[0] = 0;
  b_max->size[1] = 0;
  b_min->size[0] = 0;
  b_min->size[1] = 0;
  imax->size[0] = 0;
  imax->size[1] = 0;
  imin->size[0] = 0;
  imin->size[1] = 0;

  /* get differences */
  /* get extrema if any nonzero changes */
  d_diff(x, dv11);
  if (e_any(dv11)) {
    /* allocation */
    i48 = imax->size[0] * imax->size[1];
    imax->size[0] = 1;
    imax->size[1] = 499;
    emxEnsureCapacity_real_T(imax, i48);
    for (i48 = 0; i48 < 499; i48++) {
      imax->data[i48] = 0.0;
    }

    i48 = imin->size[0] * imin->size[1];
    imin->size[0] = 1;
    imin->size[1] = 499;
    emxEnsureCapacity_real_T(imin, i48);
    for (i48 = 0; i48 < 499; i48++) {
      imin->data[i48] = 0.0;
    }

    /* endpoints are always local extrema */
    for (i = 0; i < 500; i++) {
      b_x[i] = (x[i] != x[0]);
    }

    idx = 0;
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i < 500)) {
      if (b_x[i]) {
        idx++;
        ii_data[idx - 1] = (short)(i + 1);
        if (idx >= 500) {
          exitg1 = true;
        } else {
          i++;
        }
      } else {
        i++;
      }
    }

    if (1 > idx) {
      idx = 0;
    }

    emxInit_real_T(&d, 1);
    i48 = d->size[0];
    d->size[0] = idx;
    emxEnsureCapacity_real_T(d, i48);
    for (i48 = 0; i48 < idx; i48++) {
      d->data[i48] = ii_data[i48];
    }

    nm1d2 = idx - 2;
    tmp_size[0] = 1;
    tmp_size[1] = idx - 1;
    for (i48 = 0; i48 <= nm1d2; i48++) {
      b_tmp_data[i48] = 2 + i48;
    }

    tmp_data.data = &b_tmp_data[0];
    tmp_data.size = &tmp_size[0];
    tmp_data.allocatedSize = 499;
    tmp_data.numDimensions = 2;
    tmp_data.canFreeData = false;
    b_nullAssignment(d, &tmp_data);
    first_size_idx_0 = d->size[0];
    nm1d2 = d->size[0];
    for (i48 = 0; i48 < nm1d2; i48++) {
      first_data[i48] = d->data[i48];
    }

    for (i = 0; i < 500; i++) {
      b_x[i] = (x[i] != x[499]);
    }

    idx = 0;
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i < 500)) {
      if (b_x[i]) {
        idx++;
        ii_data[idx - 1] = (short)(i + 1);
        if (idx >= 500) {
          exitg1 = true;
        } else {
          i++;
        }
      } else {
        i++;
      }
    }

    if (1 > idx) {
      idx = 0;
    }

    i48 = d->size[0];
    d->size[0] = idx;
    emxEnsureCapacity_real_T(d, i48);
    for (i48 = 0; i48 < idx; i48++) {
      d->data[i48] = ii_data[i48];
    }

    nm1d2 = idx - 2;
    tmp_size[0] = 1;
    tmp_size[1] = idx - 1;
    for (i48 = 0; i48 <= nm1d2; i48++) {
      b_tmp_data[i48] = 1 + i48;
    }

    c_tmp_data.data = &b_tmp_data[0];
    c_tmp_data.size = &tmp_size[0];
    c_tmp_data.allocatedSize = 499;
    c_tmp_data.numDimensions = 2;
    c_tmp_data.canFreeData = false;
    b_nullAssignment(d, &c_tmp_data);
    idx = d->size[0];
    nm1d2 = d->size[0];
    for (i48 = 0; i48 < nm1d2; i48++) {
      last_data[i48] = d->data[i48];
    }

    x_size[0] = first_size_idx_0;
    for (i48 = 0; i48 < first_size_idx_0; i48++) {
      b_x_data[i48] = (x[0] < x[(int)first_data[i48] - 1]);
    }

    x_data.data = &b_x_data[0];
    x_data.size = &x_size[0];
    x_data.allocatedSize = 4096;
    x_data.numDimensions = 1;
    x_data.canFreeData = false;
    emxInit_real_T(&y, 2);
    if (b_ifWhileCond(&x_data)) {
      i48 = d->size[0];
      d->size[0] = first_size_idx_0;
      emxEnsureCapacity_real_T(d, i48);
      for (i48 = 0; i48 < first_size_idx_0; i48++) {
        d->data[i48] = first_data[i48] - 1.0;
      }

      if (rtIsNaN(d->data[0])) {
        i48 = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(y, i48);
        y->data[0] = rtNaN;
      } else if (d->data[0] < 1.0) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else {
        i48 = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = (int)floor(d->data[0] - 1.0) + 1;
        emxEnsureCapacity_real_T(y, i48);
        nm1d2 = (int)floor(d->data[0] - 1.0);
        for (i48 = 0; i48 <= nm1d2; i48++) {
          y->data[i48] = 1.0 + (double)i48;
        }
      }

      iminFirst_size_idx_1 = y->size[1];
      nm1d2 = y->size[0] * y->size[1];
      for (i48 = 0; i48 < nm1d2; i48++) {
        iminFirst_data[i48] = y->data[i48];
      }

      imaxFirst_size_idx_0 = 0;
      imaxFirst_size_idx_1 = 0;
    } else {
      iminFirst_size_idx_1 = 0;
      i48 = d->size[0];
      d->size[0] = first_size_idx_0;
      emxEnsureCapacity_real_T(d, i48);
      for (i48 = 0; i48 < first_size_idx_0; i48++) {
        d->data[i48] = first_data[i48] - 1.0;
      }

      if (rtIsNaN(d->data[0])) {
        i48 = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(y, i48);
        y->data[0] = rtNaN;
      } else if (d->data[0] < 1.0) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else {
        i48 = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = (int)floor(d->data[0] - 1.0) + 1;
        emxEnsureCapacity_real_T(y, i48);
        nm1d2 = (int)floor(d->data[0] - 1.0);
        for (i48 = 0; i48 <= nm1d2; i48++) {
          y->data[i48] = 1.0 + (double)i48;
        }
      }

      imaxFirst_size_idx_0 = 1;
      imaxFirst_size_idx_1 = y->size[1];
      nm1d2 = y->size[0] * y->size[1];
      for (i48 = 0; i48 < nm1d2; i48++) {
        imaxFirst_data[i48] = y->data[i48];
      }
    }

    emxFree_real_T(&d);
    emxFree_real_T(&y);
    x_size[0] = idx;
    for (i48 = 0; i48 < idx; i48++) {
      b_x_data[i48] = (x[499] < x[(int)last_data[i48] - 1]);
    }

    c_x_data.data = &b_x_data[0];
    c_x_data.size = &x_size[0];
    c_x_data.allocatedSize = 4096;
    c_x_data.numDimensions = 1;
    c_x_data.canFreeData = false;
    if (b_ifWhileCond(&c_x_data)) {
      for (i48 = 0; i48 < idx; i48++) {
        a_data[i48] = last_data[i48] + 1.0;
      }

      if (rtIsNaN(a_data[0])) {
        n = 1;
        iminLast_data[0] = rtNaN;
      } else if (500.0 < a_data[0]) {
        n = 0;
      } else if (floor(a_data[0]) == a_data[0]) {
        i = (int)floor(500.0 - a_data[0]);
        n = i + 1;
        for (i48 = 0; i48 <= i; i48++) {
          iminLast_data[i48] = a_data[0] + (double)i48;
        }
      } else {
        ndbl = floor((500.0 - a_data[0]) + 0.5);
        apnd = a_data[0] + ndbl;
        if (fabs(apnd - 500.0) < 4.4408920985006262E-16 * fmax(a_data[0], 500.0))
        {
          ndbl++;
          apnd = 500.0;
        } else if (apnd - 500.0 > 0.0) {
          apnd = a_data[0] + (ndbl - 1.0);
        } else {
          ndbl++;
        }

        n = (int)ndbl;
        if (n > 0) {
          iminLast_data[0] = a_data[0];
          if (n > 1) {
            iminLast_data[n - 1] = apnd;
            nm1d2 = (n - 1) / 2;
            for (k = 0; k <= nm1d2 - 2; k++) {
              iminLast_data[1 + k] = a_data[0] + (1.0 + (double)k);
              iminLast_data[(n - k) - 2] = apnd - (1.0 + (double)k);
            }

            if (nm1d2 << 1 == n - 1) {
              iminLast_data[nm1d2] = (a_data[0] + apnd) / 2.0;
            } else {
              iminLast_data[nm1d2] = a_data[0] + (double)nm1d2;
              iminLast_data[nm1d2 + 1] = apnd - (double)nm1d2;
            }
          }
        }
      }

      imaxLast_size_idx_0 = 0;
      imaxLast_size_idx_1 = 0;
    } else {
      for (i48 = 0; i48 < idx; i48++) {
        a_data[i48] = last_data[i48] + 1.0;
      }

      if (rtIsNaN(a_data[0])) {
        n = 1;
        iminLast_data[0] = rtNaN;
      } else if (500.0 < a_data[0]) {
        n = 0;
      } else if (floor(a_data[0]) == a_data[0]) {
        n = (int)floor(500.0 - a_data[0]) + 1;
        nm1d2 = (int)floor(500.0 - a_data[0]);
        for (i48 = 0; i48 <= nm1d2; i48++) {
          iminLast_data[i48] = a_data[0] + (double)i48;
        }
      } else {
        ndbl = floor((500.0 - a_data[0]) + 0.5);
        apnd = a_data[0] + ndbl;
        if (fabs(apnd - 500.0) < 4.4408920985006262E-16 * fmax(a_data[0], 500.0))
        {
          ndbl++;
          apnd = 500.0;
        } else if (apnd - 500.0 > 0.0) {
          apnd = a_data[0] + (ndbl - 1.0);
        } else {
          ndbl++;
        }

        n = (int)ndbl;
        if (n > 0) {
          iminLast_data[0] = a_data[0];
          if (n > 1) {
            iminLast_data[n - 1] = apnd;
            nm1d2 = (n - 1) / 2;
            for (k = 0; k <= nm1d2 - 2; k++) {
              iminLast_data[1 + k] = a_data[0] + (1.0 + (double)k);
              iminLast_data[(n - k) - 2] = apnd - (1.0 + (double)k);
            }

            if (nm1d2 << 1 == n - 1) {
              iminLast_data[nm1d2] = (a_data[0] + apnd) / 2.0;
            } else {
              iminLast_data[nm1d2] = a_data[0] + (double)nm1d2;
              iminLast_data[nm1d2 + 1] = apnd - (double)nm1d2;
            }
          }
        }
      }

      imaxLast_size_idx_0 = 1;
      imaxLast_size_idx_1 = n;
      if (0 <= n - 1) {
        memcpy(&imaxLast_data[0], &iminLast_data[0], (unsigned int)(n * (int)
                sizeof(double)));
      }

      n = 0;
    }

    /* for each element */
    maxct = 0.0;
    minct = 0.0;
    for (i48 = 0; i48 < first_size_idx_0; i48++) {
      a_data[i48] = x[(int)(first_data[i48] - 1.0) - 1];
    }

    direction0_size[0] = first_size_idx_0;
    for (i48 = 0; i48 < first_size_idx_0; i48++) {
      direction0_data[i48] = x[(int)first_data[i48] - 1] - a_data[i48];
    }

    f_sign(direction0_data, direction0_size);
    constant = 0.0;

    /* the following is to convert k bounds to scalar for matlab coder */
    for (i48 = 0; i48 < first_size_idx_0; i48++) {
      first_data[i48]++;
    }

    for (i48 = 0; i48 < idx; i48++) {
      last_data[i48]++;
    }

    i48 = (int)(last_data[0] + (1.0 - first_data[0]));
    emxInit_real_T(&r12, 2);
    for (k = 0; k < i48; k++) {
      b_k = first_data[0] + (double)k;

      /* current trajectory */
      direction = x[(int)b_k - 1] - x[(int)(b_k - 1.0) - 1];
      e_sign(&direction);

      /* if no change */
      if (direction == 0.0) {
        constant++;

        /* otherwise */
      } else {
        /* The following is also for matlab coder, to identify that */
        /* direction 0 is a scalar */
        /* if local minimum */
        if ((direction == 1.0) && (direction0_data[0] == -1.0)) {
          /* update min/imin */
          minct = (minct + 1.0) + constant;
          ndbl = minct - constant;
          if (ndbl > minct) {
            first_size_idx_0 = 1;
          } else {
            first_size_idx_0 = (int)ndbl;
          }

          constant = (b_k - 1.0) - constant;
          if (rtIsNaN(constant) || rtIsNaN(b_k - 1.0)) {
            i = r12->size[0] * r12->size[1];
            r12->size[0] = 1;
            r12->size[1] = 1;
            emxEnsureCapacity_real_T(r12, i);
            r12->data[0] = rtNaN;
          } else if (b_k - 1.0 < constant) {
            r12->size[0] = 1;
            r12->size[1] = 0;
          } else if (rtIsInf(constant) && (constant == b_k - 1.0)) {
            i = r12->size[0] * r12->size[1];
            r12->size[0] = 1;
            r12->size[1] = 1;
            emxEnsureCapacity_real_T(r12, i);
            r12->data[0] = rtNaN;
          } else if (floor(constant) == constant) {
            i = r12->size[0] * r12->size[1];
            r12->size[0] = 1;
            nm1d2 = (int)floor((b_k - 1.0) - constant);
            r12->size[1] = nm1d2 + 1;
            emxEnsureCapacity_real_T(r12, i);
            for (i = 0; i <= nm1d2; i++) {
              r12->data[i] = constant + (double)i;
            }
          } else {
            ndbl = floor(((b_k - 1.0) - constant) + 0.5);
            apnd = constant + ndbl;
            cdiff = apnd - (b_k - 1.0);
            if (fabs(cdiff) < 4.4408920985006262E-16 * fmax(fabs(constant), b_k
                 - 1.0)) {
              ndbl++;
              apnd = b_k - 1.0;
            } else if (cdiff > 0.0) {
              apnd = constant + (ndbl - 1.0);
            } else {
              ndbl++;
            }

            if (ndbl >= 0.0) {
              idx = (int)ndbl;
            } else {
              idx = 0;
            }

            i = r12->size[0] * r12->size[1];
            r12->size[0] = 1;
            r12->size[1] = idx;
            emxEnsureCapacity_real_T(r12, i);
            if (idx > 0) {
              r12->data[0] = constant;
              if (idx > 1) {
                r12->data[idx - 1] = apnd;
                nm1d2 = (idx - 1) / 2;
                for (i = 0; i <= nm1d2 - 2; i++) {
                  r12->data[1 + i] = constant + (1.0 + (double)i);
                  r12->data[(idx - i) - 2] = apnd - (1.0 + (double)i);
                }

                if (nm1d2 << 1 == idx - 1) {
                  r12->data[nm1d2] = (constant + apnd) / 2.0;
                } else {
                  r12->data[nm1d2] = constant + (double)nm1d2;
                  r12->data[nm1d2 + 1] = apnd - (double)nm1d2;
                }
              }
            }
          }

          nm1d2 = r12->size[1];
          for (i = 0; i < nm1d2; i++) {
            imin->data[(first_size_idx_0 + i) - 1] = r12->data[i];
          }

          /* if local maximum */
        } else {
          if ((direction == -1.0) && (direction0_data[0] == 1.0)) {
            /* update max/imax */
            maxct = (maxct + 1.0) + constant;
            ndbl = maxct - constant;
            if (ndbl > maxct) {
              first_size_idx_0 = 1;
            } else {
              first_size_idx_0 = (int)ndbl;
            }

            constant = (b_k - 1.0) - constant;
            if (rtIsNaN(constant) || rtIsNaN(b_k - 1.0)) {
              i = r12->size[0] * r12->size[1];
              r12->size[0] = 1;
              r12->size[1] = 1;
              emxEnsureCapacity_real_T(r12, i);
              r12->data[0] = rtNaN;
            } else if (b_k - 1.0 < constant) {
              r12->size[0] = 1;
              r12->size[1] = 0;
            } else if (rtIsInf(constant) && (constant == b_k - 1.0)) {
              i = r12->size[0] * r12->size[1];
              r12->size[0] = 1;
              r12->size[1] = 1;
              emxEnsureCapacity_real_T(r12, i);
              r12->data[0] = rtNaN;
            } else if (floor(constant) == constant) {
              i = r12->size[0] * r12->size[1];
              r12->size[0] = 1;
              nm1d2 = (int)floor((b_k - 1.0) - constant);
              r12->size[1] = nm1d2 + 1;
              emxEnsureCapacity_real_T(r12, i);
              for (i = 0; i <= nm1d2; i++) {
                r12->data[i] = constant + (double)i;
              }
            } else {
              ndbl = floor(((b_k - 1.0) - constant) + 0.5);
              apnd = constant + ndbl;
              cdiff = apnd - (b_k - 1.0);
              if (fabs(cdiff) < 4.4408920985006262E-16 * fmax(fabs(constant),
                   b_k - 1.0)) {
                ndbl++;
                apnd = b_k - 1.0;
              } else if (cdiff > 0.0) {
                apnd = constant + (ndbl - 1.0);
              } else {
                ndbl++;
              }

              if (ndbl >= 0.0) {
                idx = (int)ndbl;
              } else {
                idx = 0;
              }

              i = r12->size[0] * r12->size[1];
              r12->size[0] = 1;
              r12->size[1] = idx;
              emxEnsureCapacity_real_T(r12, i);
              if (idx > 0) {
                r12->data[0] = constant;
                if (idx > 1) {
                  r12->data[idx - 1] = apnd;
                  nm1d2 = (idx - 1) / 2;
                  for (i = 0; i <= nm1d2 - 2; i++) {
                    r12->data[1 + i] = constant + (1.0 + (double)i);
                    r12->data[(idx - i) - 2] = apnd - (1.0 + (double)i);
                  }

                  if (nm1d2 << 1 == idx - 1) {
                    r12->data[nm1d2] = (constant + apnd) / 2.0;
                  } else {
                    r12->data[nm1d2] = constant + (double)nm1d2;
                    r12->data[nm1d2 + 1] = apnd - (double)nm1d2;
                  }
                }
              }
            }

            nm1d2 = r12->size[1];
            for (i = 0; i < nm1d2; i++) {
              imax->data[(first_size_idx_0 + i) - 1] = r12->data[i];
            }
          }
        }

        /* current trajectory is next iteration previous */
        direction0_data[0] = direction;

        /* no consecutive constant */
        constant = 0.0;
      }
    }

    emxFree_real_T(&r12);

    /* finish */
    if ((imaxFirst_size_idx_0 != 0) && (imaxFirst_size_idx_1 != 0)) {
      input_sizes_idx_1 = (short)imaxFirst_size_idx_1;
    } else {
      input_sizes_idx_1 = 0;
    }

    emxInitMatrix_cell_wrap_43(reshapes);
    i48 = reshapes[0].f1->size[0] * reshapes[0].f1->size[1];
    reshapes[0].f1->size[0] = 1;
    reshapes[0].f1->size[1] = input_sizes_idx_1;
    emxEnsureCapacity_real_T(reshapes[0].f1, i48);
    nm1d2 = input_sizes_idx_1;
    for (i48 = 0; i48 < nm1d2; i48++) {
      reshapes[0].f1->data[i48] = imaxFirst_data[i48];
    }

    i48 = reshapes[1].f1->size[0] * reshapes[1].f1->size[1];
    reshapes[1].f1->size[0] = 1;
    reshapes[1].f1->size[1] = 499;
    emxEnsureCapacity_real_T(reshapes[1].f1, i48);
    for (i48 = 0; i48 < 499; i48++) {
      reshapes[1].f1->data[i48] = imax->data[i48];
    }

    if ((imaxLast_size_idx_0 != 0) && (imaxLast_size_idx_1 != 0)) {
      input_sizes_idx_1 = (short)imaxLast_size_idx_1;
    } else {
      input_sizes_idx_1 = 0;
    }

    i48 = reshapes[2].f1->size[0] * reshapes[2].f1->size[1];
    reshapes[2].f1->size[0] = 1;
    reshapes[2].f1->size[1] = input_sizes_idx_1;
    emxEnsureCapacity_real_T(reshapes[2].f1, i48);
    nm1d2 = input_sizes_idx_1;
    for (i48 = 0; i48 < nm1d2; i48++) {
      reshapes[2].f1->data[i48] = imaxLast_data[i48];
    }

    emxInit_real_T(&result, 2);
    i48 = result->size[0] * result->size[1];
    result->size[0] = reshapes[0].f1->size[0];
    result->size[1] = (reshapes[0].f1->size[1] + reshapes[1].f1->size[1]) +
      reshapes[2].f1->size[1];
    emxEnsureCapacity_real_T(result, i48);
    nm1d2 = reshapes[0].f1->size[1];
    for (i48 = 0; i48 < nm1d2; i48++) {
      i = reshapes[0].f1->size[0];
      for (first_size_idx_0 = 0; first_size_idx_0 < i; first_size_idx_0++) {
        result->data[first_size_idx_0 + result->size[0] * i48] = reshapes[0].
          f1->data[first_size_idx_0 + reshapes[0].f1->size[0] * i48];
      }
    }

    nm1d2 = reshapes[1].f1->size[1];
    for (i48 = 0; i48 < nm1d2; i48++) {
      i = reshapes[1].f1->size[0];
      for (first_size_idx_0 = 0; first_size_idx_0 < i; first_size_idx_0++) {
        result->data[first_size_idx_0 + result->size[0] * (i48 + reshapes[0].
          f1->size[1])] = reshapes[1].f1->data[first_size_idx_0 + reshapes[1].
          f1->size[0] * i48];
      }
    }

    nm1d2 = reshapes[2].f1->size[1];
    for (i48 = 0; i48 < nm1d2; i48++) {
      i = reshapes[2].f1->size[0];
      for (first_size_idx_0 = 0; first_size_idx_0 < i; first_size_idx_0++) {
        result->data[first_size_idx_0 + result->size[0] * ((i48 + reshapes[0].
          f1->size[1]) + reshapes[1].f1->size[1])] = reshapes[2].f1->
          data[first_size_idx_0 + reshapes[2].f1->size[0] * i48];
      }
    }

    emxFreeMatrix_cell_wrap_43(reshapes);
    result_size[0] = result->size[0];
    result_size[1] = result->size[1];
    nm1d2 = result->size[0] * result->size[1];
    for (i48 = 0; i48 < nm1d2; i48++) {
      b_result_data[i48] = (result->data[i48] == 0.0);
    }

    result_data.data = &b_result_data[0];
    result_data.size = &result_size[0];
    result_data.allocatedSize = 5094;
    result_data.numDimensions = 2;
    result_data.canFreeData = false;
    c_nullAssignment(result, &result_data);
    i48 = imax->size[0] * imax->size[1];
    imax->size[0] = result->size[0];
    imax->size[1] = result->size[1];
    emxEnsureCapacity_real_T(imax, i48);
    nm1d2 = result->size[0] * result->size[1];
    for (i48 = 0; i48 < nm1d2; i48++) {
      imax->data[i48] = result->data[i48];
    }

    i48 = b_max->size[0] * b_max->size[1];
    b_max->size[0] = imax->size[0];
    b_max->size[1] = imax->size[1];
    emxEnsureCapacity_real_T(b_max, i48);
    nm1d2 = imax->size[0] * imax->size[1];
    for (i48 = 0; i48 < nm1d2; i48++) {
      b_max->data[i48] = x[(int)imax->data[i48] - 1];
    }

    emxInit_real_T(&b_result, 2);
    if (iminFirst_size_idx_1 != 0) {
      input_sizes_idx_1 = (short)iminFirst_size_idx_1;
    } else {
      input_sizes_idx_1 = 0;
    }

    if (n != 0) {
      b_input_sizes_idx_1 = (short)n;
    } else {
      b_input_sizes_idx_1 = 0;
    }

    if (iminFirst_size_idx_1 != 0) {
      i = (short)iminFirst_size_idx_1;
    } else {
      i = 0;
    }

    i48 = b_result->size[0] * b_result->size[1];
    b_result->size[0] = 1;
    b_result->size[1] = (input_sizes_idx_1 + b_input_sizes_idx_1) + 499;
    emxEnsureCapacity_real_T(b_result, i48);
    nm1d2 = input_sizes_idx_1;
    for (i48 = 0; i48 < nm1d2; i48++) {
      for (first_size_idx_0 = 0; first_size_idx_0 < 1; first_size_idx_0++) {
        b_result->data[i48] = iminFirst_data[i48];
      }
    }

    for (i48 = 0; i48 < 499; i48++) {
      for (first_size_idx_0 = 0; first_size_idx_0 < 1; first_size_idx_0++) {
        b_result->data[i48 + i] = imin->data[i48];
      }
    }

    nm1d2 = b_input_sizes_idx_1;
    for (i48 = 0; i48 < nm1d2; i48++) {
      for (first_size_idx_0 = 0; first_size_idx_0 < 1; first_size_idx_0++) {
        b_result->data[(i48 + i) + 499] = iminLast_data[i48];
      }
    }

    i48 = result->size[0] * result->size[1];
    result->size[0] = 1;
    result->size[1] = b_result->size[1];
    emxEnsureCapacity_real_T(result, i48);
    nm1d2 = b_result->size[0] * b_result->size[1];
    for (i48 = 0; i48 < nm1d2; i48++) {
      result->data[i48] = b_result->data[i48];
    }

    b_result_size[0] = 1;
    b_result_size[1] = b_result->size[1];
    nm1d2 = b_result->size[0] * b_result->size[1];
    for (i48 = 0; i48 < nm1d2; i48++) {
      c_result_data[i48] = (b_result->data[i48] == 0.0);
    }

    emxFree_real_T(&b_result);
    d_result_data.data = &c_result_data[0];
    d_result_data.size = &b_result_size[0];
    d_result_data.allocatedSize = 5094;
    d_result_data.numDimensions = 2;
    d_result_data.canFreeData = false;
    c_nullAssignment(result, &d_result_data);
    i48 = imin->size[0] * imin->size[1];
    imin->size[0] = result->size[0];
    imin->size[1] = result->size[1];
    emxEnsureCapacity_real_T(imin, i48);
    nm1d2 = result->size[0] * result->size[1];
    for (i48 = 0; i48 < nm1d2; i48++) {
      imin->data[i48] = result->data[i48];
    }

    emxFree_real_T(&result);
    i48 = b_min->size[0] * b_min->size[1];
    b_min->size[0] = imin->size[0];
    b_min->size[1] = imin->size[1];
    emxEnsureCapacity_real_T(b_min, i48);
    nm1d2 = imin->size[0] * imin->size[1];
    for (i48 = 0; i48 < nm1d2; i48++) {
      b_min->data[i48] = x[(int)imin->data[i48] - 1];
    }
  }
}

void e_extrema(const double x[500], emxArray_real_T *b_max, emxArray_real_T
               *imax)
{
  double dv12[499];
  int i49;
  emxArray_real_T *imin;
  int i;
  int idx;
  boolean_T b_x[500];
  boolean_T exitg1;
  emxArray_real_T *d;
  short ii_data[500];
  int nm1d2;
  int tmp_size[2];
  emxArray_int32_T tmp_data;
  int b_tmp_data[499];
  int first_size_idx_0;
  static double first_data[4096];
  emxArray_int32_T c_tmp_data;
  int x_size[1];
  static double last_data[4096];
  emxArray_boolean_T x_data;
  boolean_T b_x_data[4096];
  emxArray_real_T *y;
  int iminFirst_size_idx_1;
  int imaxFirst_size_idx_0;
  int imaxFirst_size_idx_1;
  double iminFirst_data[499];
  double imaxFirst_data[499];
  emxArray_boolean_T c_x_data;
  static double a_data[4096];
  int n;
  double iminLast_data[499];
  double ndbl;
  double apnd;
  int imaxLast_size_idx_0;
  int imaxLast_size_idx_1;
  double imaxLast_data[499];
  double maxct;
  double minct;
  int direction0_size[1];
  int k;
  static double direction0_data[4096];
  double constant;
  emxArray_real_T *r13;
  double b_k;
  double direction;
  short input_sizes_idx_1;
  cell_wrap_43 reshapes[3];
  double cdiff;
  emxArray_real_T *result;
  int result_size[2];
  emxArray_boolean_T result_data;
  boolean_T b_result_data[5094];
  emxArray_real_T *b_result;
  short b_input_sizes_idx_1;
  int b_result_size[2];
  boolean_T c_result_data[5094];
  emxArray_boolean_T d_result_data;

  /* Reed Gurchiek, */
  /*    extrema finds local minima and maxima of the vector x */
  /*  */
  /* ---------------------------INPUTS----------------------------------------- */
  /*  */
  /*    x: */
  /*        n-element array for which the local minima and maxima will be found */
  /*  */
  /* --------------------------OUTPUTS----------------------------------------- */
  /*  */
  /*    max,imax: */
  /*        local maxima values (max) and their indices (imax) */
  /*  */
  /*    min,imin: */
  /*        local minima values (min) and their indices (imin) */
  /*  */
  /* -------------------------------------------------------------------------- */
  /*  extrema */
  /* initialize */
  b_max->size[0] = 0;
  b_max->size[1] = 0;
  imax->size[0] = 0;
  imax->size[1] = 0;

  /* get differences */
  /* get extrema if any nonzero changes */
  d_diff(x, dv12);
  if (e_any(dv12)) {
    /* allocation */
    i49 = imax->size[0] * imax->size[1];
    imax->size[0] = 1;
    imax->size[1] = 499;
    emxEnsureCapacity_real_T(imax, i49);
    for (i49 = 0; i49 < 499; i49++) {
      imax->data[i49] = 0.0;
    }

    emxInit_real_T(&imin, 2);
    i49 = imin->size[0] * imin->size[1];
    imin->size[0] = 1;
    imin->size[1] = 499;
    emxEnsureCapacity_real_T(imin, i49);
    for (i49 = 0; i49 < 499; i49++) {
      imin->data[i49] = 0.0;
    }

    /* endpoints are always local extrema */
    for (i = 0; i < 500; i++) {
      b_x[i] = (x[i] != x[0]);
    }

    idx = 0;
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i < 500)) {
      if (b_x[i]) {
        idx++;
        ii_data[idx - 1] = (short)(i + 1);
        if (idx >= 500) {
          exitg1 = true;
        } else {
          i++;
        }
      } else {
        i++;
      }
    }

    if (1 > idx) {
      idx = 0;
    }

    emxInit_real_T(&d, 1);
    i49 = d->size[0];
    d->size[0] = idx;
    emxEnsureCapacity_real_T(d, i49);
    for (i49 = 0; i49 < idx; i49++) {
      d->data[i49] = ii_data[i49];
    }

    nm1d2 = idx - 2;
    tmp_size[0] = 1;
    tmp_size[1] = idx - 1;
    for (i49 = 0; i49 <= nm1d2; i49++) {
      b_tmp_data[i49] = 2 + i49;
    }

    tmp_data.data = &b_tmp_data[0];
    tmp_data.size = &tmp_size[0];
    tmp_data.allocatedSize = 499;
    tmp_data.numDimensions = 2;
    tmp_data.canFreeData = false;
    b_nullAssignment(d, &tmp_data);
    first_size_idx_0 = d->size[0];
    nm1d2 = d->size[0];
    for (i49 = 0; i49 < nm1d2; i49++) {
      first_data[i49] = d->data[i49];
    }

    for (i = 0; i < 500; i++) {
      b_x[i] = (x[i] != x[499]);
    }

    idx = 0;
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i < 500)) {
      if (b_x[i]) {
        idx++;
        ii_data[idx - 1] = (short)(i + 1);
        if (idx >= 500) {
          exitg1 = true;
        } else {
          i++;
        }
      } else {
        i++;
      }
    }

    if (1 > idx) {
      idx = 0;
    }

    i49 = d->size[0];
    d->size[0] = idx;
    emxEnsureCapacity_real_T(d, i49);
    for (i49 = 0; i49 < idx; i49++) {
      d->data[i49] = ii_data[i49];
    }

    nm1d2 = idx - 2;
    tmp_size[0] = 1;
    tmp_size[1] = idx - 1;
    for (i49 = 0; i49 <= nm1d2; i49++) {
      b_tmp_data[i49] = 1 + i49;
    }

    c_tmp_data.data = &b_tmp_data[0];
    c_tmp_data.size = &tmp_size[0];
    c_tmp_data.allocatedSize = 499;
    c_tmp_data.numDimensions = 2;
    c_tmp_data.canFreeData = false;
    b_nullAssignment(d, &c_tmp_data);
    idx = d->size[0];
    nm1d2 = d->size[0];
    for (i49 = 0; i49 < nm1d2; i49++) {
      last_data[i49] = d->data[i49];
    }

    x_size[0] = first_size_idx_0;
    for (i49 = 0; i49 < first_size_idx_0; i49++) {
      b_x_data[i49] = (x[0] < x[(int)first_data[i49] - 1]);
    }

    x_data.data = &b_x_data[0];
    x_data.size = &x_size[0];
    x_data.allocatedSize = 4096;
    x_data.numDimensions = 1;
    x_data.canFreeData = false;
    emxInit_real_T(&y, 2);
    if (b_ifWhileCond(&x_data)) {
      i49 = d->size[0];
      d->size[0] = first_size_idx_0;
      emxEnsureCapacity_real_T(d, i49);
      for (i49 = 0; i49 < first_size_idx_0; i49++) {
        d->data[i49] = first_data[i49] - 1.0;
      }

      if (rtIsNaN(d->data[0])) {
        i49 = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(y, i49);
        y->data[0] = rtNaN;
      } else if (d->data[0] < 1.0) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else {
        i49 = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = (int)floor(d->data[0] - 1.0) + 1;
        emxEnsureCapacity_real_T(y, i49);
        nm1d2 = (int)floor(d->data[0] - 1.0);
        for (i49 = 0; i49 <= nm1d2; i49++) {
          y->data[i49] = 1.0 + (double)i49;
        }
      }

      iminFirst_size_idx_1 = y->size[1];
      nm1d2 = y->size[0] * y->size[1];
      for (i49 = 0; i49 < nm1d2; i49++) {
        iminFirst_data[i49] = y->data[i49];
      }

      imaxFirst_size_idx_0 = 0;
      imaxFirst_size_idx_1 = 0;
    } else {
      iminFirst_size_idx_1 = 0;
      i49 = d->size[0];
      d->size[0] = first_size_idx_0;
      emxEnsureCapacity_real_T(d, i49);
      for (i49 = 0; i49 < first_size_idx_0; i49++) {
        d->data[i49] = first_data[i49] - 1.0;
      }

      if (rtIsNaN(d->data[0])) {
        i49 = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(y, i49);
        y->data[0] = rtNaN;
      } else if (d->data[0] < 1.0) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else {
        i49 = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = (int)floor(d->data[0] - 1.0) + 1;
        emxEnsureCapacity_real_T(y, i49);
        nm1d2 = (int)floor(d->data[0] - 1.0);
        for (i49 = 0; i49 <= nm1d2; i49++) {
          y->data[i49] = 1.0 + (double)i49;
        }
      }

      imaxFirst_size_idx_0 = 1;
      imaxFirst_size_idx_1 = y->size[1];
      nm1d2 = y->size[0] * y->size[1];
      for (i49 = 0; i49 < nm1d2; i49++) {
        imaxFirst_data[i49] = y->data[i49];
      }
    }

    emxFree_real_T(&d);
    emxFree_real_T(&y);
    x_size[0] = idx;
    for (i49 = 0; i49 < idx; i49++) {
      b_x_data[i49] = (x[499] < x[(int)last_data[i49] - 1]);
    }

    c_x_data.data = &b_x_data[0];
    c_x_data.size = &x_size[0];
    c_x_data.allocatedSize = 4096;
    c_x_data.numDimensions = 1;
    c_x_data.canFreeData = false;
    if (b_ifWhileCond(&c_x_data)) {
      for (i49 = 0; i49 < idx; i49++) {
        a_data[i49] = last_data[i49] + 1.0;
      }

      if (rtIsNaN(a_data[0])) {
        n = 1;
        iminLast_data[0] = rtNaN;
      } else if (500.0 < a_data[0]) {
        n = 0;
      } else if (floor(a_data[0]) == a_data[0]) {
        i = (int)floor(500.0 - a_data[0]);
        n = i + 1;
        for (i49 = 0; i49 <= i; i49++) {
          iminLast_data[i49] = a_data[0] + (double)i49;
        }
      } else {
        ndbl = floor((500.0 - a_data[0]) + 0.5);
        apnd = a_data[0] + ndbl;
        if (fabs(apnd - 500.0) < 4.4408920985006262E-16 * fmax(a_data[0], 500.0))
        {
          ndbl++;
          apnd = 500.0;
        } else if (apnd - 500.0 > 0.0) {
          apnd = a_data[0] + (ndbl - 1.0);
        } else {
          ndbl++;
        }

        n = (int)ndbl;
        if (n > 0) {
          iminLast_data[0] = a_data[0];
          if (n > 1) {
            iminLast_data[n - 1] = apnd;
            nm1d2 = (n - 1) / 2;
            for (k = 0; k <= nm1d2 - 2; k++) {
              iminLast_data[1 + k] = a_data[0] + (1.0 + (double)k);
              iminLast_data[(n - k) - 2] = apnd - (1.0 + (double)k);
            }

            if (nm1d2 << 1 == n - 1) {
              iminLast_data[nm1d2] = (a_data[0] + apnd) / 2.0;
            } else {
              iminLast_data[nm1d2] = a_data[0] + (double)nm1d2;
              iminLast_data[nm1d2 + 1] = apnd - (double)nm1d2;
            }
          }
        }
      }

      imaxLast_size_idx_0 = 0;
      imaxLast_size_idx_1 = 0;
    } else {
      for (i49 = 0; i49 < idx; i49++) {
        a_data[i49] = last_data[i49] + 1.0;
      }

      if (rtIsNaN(a_data[0])) {
        n = 1;
        iminLast_data[0] = rtNaN;
      } else if (500.0 < a_data[0]) {
        n = 0;
      } else if (floor(a_data[0]) == a_data[0]) {
        n = (int)floor(500.0 - a_data[0]) + 1;
        nm1d2 = (int)floor(500.0 - a_data[0]);
        for (i49 = 0; i49 <= nm1d2; i49++) {
          iminLast_data[i49] = a_data[0] + (double)i49;
        }
      } else {
        ndbl = floor((500.0 - a_data[0]) + 0.5);
        apnd = a_data[0] + ndbl;
        if (fabs(apnd - 500.0) < 4.4408920985006262E-16 * fmax(a_data[0], 500.0))
        {
          ndbl++;
          apnd = 500.0;
        } else if (apnd - 500.0 > 0.0) {
          apnd = a_data[0] + (ndbl - 1.0);
        } else {
          ndbl++;
        }

        n = (int)ndbl;
        if (n > 0) {
          iminLast_data[0] = a_data[0];
          if (n > 1) {
            iminLast_data[n - 1] = apnd;
            nm1d2 = (n - 1) / 2;
            for (k = 0; k <= nm1d2 - 2; k++) {
              iminLast_data[1 + k] = a_data[0] + (1.0 + (double)k);
              iminLast_data[(n - k) - 2] = apnd - (1.0 + (double)k);
            }

            if (nm1d2 << 1 == n - 1) {
              iminLast_data[nm1d2] = (a_data[0] + apnd) / 2.0;
            } else {
              iminLast_data[nm1d2] = a_data[0] + (double)nm1d2;
              iminLast_data[nm1d2 + 1] = apnd - (double)nm1d2;
            }
          }
        }
      }

      imaxLast_size_idx_0 = 1;
      imaxLast_size_idx_1 = n;
      if (0 <= n - 1) {
        memcpy(&imaxLast_data[0], &iminLast_data[0], (unsigned int)(n * (int)
                sizeof(double)));
      }

      n = 0;
    }

    /* for each element */
    maxct = 0.0;
    minct = 0.0;
    for (i49 = 0; i49 < first_size_idx_0; i49++) {
      a_data[i49] = x[(int)(first_data[i49] - 1.0) - 1];
    }

    direction0_size[0] = first_size_idx_0;
    for (i49 = 0; i49 < first_size_idx_0; i49++) {
      direction0_data[i49] = x[(int)first_data[i49] - 1] - a_data[i49];
    }

    f_sign(direction0_data, direction0_size);
    constant = 0.0;

    /* the following is to convert k bounds to scalar for matlab coder */
    for (i49 = 0; i49 < first_size_idx_0; i49++) {
      first_data[i49]++;
    }

    for (i49 = 0; i49 < idx; i49++) {
      last_data[i49]++;
    }

    i49 = (int)(last_data[0] + (1.0 - first_data[0]));
    emxInit_real_T(&r13, 2);
    for (k = 0; k < i49; k++) {
      b_k = first_data[0] + (double)k;

      /* current trajectory */
      direction = x[(int)b_k - 1] - x[(int)(b_k - 1.0) - 1];
      e_sign(&direction);

      /* if no change */
      if (direction == 0.0) {
        constant++;

        /* otherwise */
      } else {
        /* The following is also for matlab coder, to identify that */
        /* direction 0 is a scalar */
        /* if local minimum */
        if ((direction == 1.0) && (direction0_data[0] == -1.0)) {
          /* update min/imin */
          minct = (minct + 1.0) + constant;
          ndbl = minct - constant;
          if (ndbl > minct) {
            first_size_idx_0 = 1;
          } else {
            first_size_idx_0 = (int)ndbl;
          }

          constant = (b_k - 1.0) - constant;
          if (rtIsNaN(constant) || rtIsNaN(b_k - 1.0)) {
            i = r13->size[0] * r13->size[1];
            r13->size[0] = 1;
            r13->size[1] = 1;
            emxEnsureCapacity_real_T(r13, i);
            r13->data[0] = rtNaN;
          } else if (b_k - 1.0 < constant) {
            r13->size[0] = 1;
            r13->size[1] = 0;
          } else if (rtIsInf(constant) && (constant == b_k - 1.0)) {
            i = r13->size[0] * r13->size[1];
            r13->size[0] = 1;
            r13->size[1] = 1;
            emxEnsureCapacity_real_T(r13, i);
            r13->data[0] = rtNaN;
          } else if (floor(constant) == constant) {
            i = r13->size[0] * r13->size[1];
            r13->size[0] = 1;
            nm1d2 = (int)floor((b_k - 1.0) - constant);
            r13->size[1] = nm1d2 + 1;
            emxEnsureCapacity_real_T(r13, i);
            for (i = 0; i <= nm1d2; i++) {
              r13->data[i] = constant + (double)i;
            }
          } else {
            ndbl = floor(((b_k - 1.0) - constant) + 0.5);
            apnd = constant + ndbl;
            cdiff = apnd - (b_k - 1.0);
            if (fabs(cdiff) < 4.4408920985006262E-16 * fmax(fabs(constant), b_k
                 - 1.0)) {
              ndbl++;
              apnd = b_k - 1.0;
            } else if (cdiff > 0.0) {
              apnd = constant + (ndbl - 1.0);
            } else {
              ndbl++;
            }

            if (ndbl >= 0.0) {
              idx = (int)ndbl;
            } else {
              idx = 0;
            }

            i = r13->size[0] * r13->size[1];
            r13->size[0] = 1;
            r13->size[1] = idx;
            emxEnsureCapacity_real_T(r13, i);
            if (idx > 0) {
              r13->data[0] = constant;
              if (idx > 1) {
                r13->data[idx - 1] = apnd;
                nm1d2 = (idx - 1) / 2;
                for (i = 0; i <= nm1d2 - 2; i++) {
                  r13->data[1 + i] = constant + (1.0 + (double)i);
                  r13->data[(idx - i) - 2] = apnd - (1.0 + (double)i);
                }

                if (nm1d2 << 1 == idx - 1) {
                  r13->data[nm1d2] = (constant + apnd) / 2.0;
                } else {
                  r13->data[nm1d2] = constant + (double)nm1d2;
                  r13->data[nm1d2 + 1] = apnd - (double)nm1d2;
                }
              }
            }
          }

          nm1d2 = r13->size[1];
          for (i = 0; i < nm1d2; i++) {
            imin->data[(first_size_idx_0 + i) - 1] = r13->data[i];
          }

          /* if local maximum */
        } else {
          if ((direction == -1.0) && (direction0_data[0] == 1.0)) {
            /* update max/imax */
            maxct = (maxct + 1.0) + constant;
            ndbl = maxct - constant;
            if (ndbl > maxct) {
              first_size_idx_0 = 1;
            } else {
              first_size_idx_0 = (int)ndbl;
            }

            constant = (b_k - 1.0) - constant;
            if (rtIsNaN(constant) || rtIsNaN(b_k - 1.0)) {
              i = r13->size[0] * r13->size[1];
              r13->size[0] = 1;
              r13->size[1] = 1;
              emxEnsureCapacity_real_T(r13, i);
              r13->data[0] = rtNaN;
            } else if (b_k - 1.0 < constant) {
              r13->size[0] = 1;
              r13->size[1] = 0;
            } else if (rtIsInf(constant) && (constant == b_k - 1.0)) {
              i = r13->size[0] * r13->size[1];
              r13->size[0] = 1;
              r13->size[1] = 1;
              emxEnsureCapacity_real_T(r13, i);
              r13->data[0] = rtNaN;
            } else if (floor(constant) == constant) {
              i = r13->size[0] * r13->size[1];
              r13->size[0] = 1;
              nm1d2 = (int)floor((b_k - 1.0) - constant);
              r13->size[1] = nm1d2 + 1;
              emxEnsureCapacity_real_T(r13, i);
              for (i = 0; i <= nm1d2; i++) {
                r13->data[i] = constant + (double)i;
              }
            } else {
              ndbl = floor(((b_k - 1.0) - constant) + 0.5);
              apnd = constant + ndbl;
              cdiff = apnd - (b_k - 1.0);
              if (fabs(cdiff) < 4.4408920985006262E-16 * fmax(fabs(constant),
                   b_k - 1.0)) {
                ndbl++;
                apnd = b_k - 1.0;
              } else if (cdiff > 0.0) {
                apnd = constant + (ndbl - 1.0);
              } else {
                ndbl++;
              }

              if (ndbl >= 0.0) {
                idx = (int)ndbl;
              } else {
                idx = 0;
              }

              i = r13->size[0] * r13->size[1];
              r13->size[0] = 1;
              r13->size[1] = idx;
              emxEnsureCapacity_real_T(r13, i);
              if (idx > 0) {
                r13->data[0] = constant;
                if (idx > 1) {
                  r13->data[idx - 1] = apnd;
                  nm1d2 = (idx - 1) / 2;
                  for (i = 0; i <= nm1d2 - 2; i++) {
                    r13->data[1 + i] = constant + (1.0 + (double)i);
                    r13->data[(idx - i) - 2] = apnd - (1.0 + (double)i);
                  }

                  if (nm1d2 << 1 == idx - 1) {
                    r13->data[nm1d2] = (constant + apnd) / 2.0;
                  } else {
                    r13->data[nm1d2] = constant + (double)nm1d2;
                    r13->data[nm1d2 + 1] = apnd - (double)nm1d2;
                  }
                }
              }
            }

            nm1d2 = r13->size[1];
            for (i = 0; i < nm1d2; i++) {
              imax->data[(first_size_idx_0 + i) - 1] = r13->data[i];
            }
          }
        }

        /* current trajectory is next iteration previous */
        direction0_data[0] = direction;

        /* no consecutive constant */
        constant = 0.0;
      }
    }

    emxFree_real_T(&r13);

    /* finish */
    if ((imaxFirst_size_idx_0 != 0) && (imaxFirst_size_idx_1 != 0)) {
      input_sizes_idx_1 = (short)imaxFirst_size_idx_1;
    } else {
      input_sizes_idx_1 = 0;
    }

    emxInitMatrix_cell_wrap_43(reshapes);
    i49 = reshapes[0].f1->size[0] * reshapes[0].f1->size[1];
    reshapes[0].f1->size[0] = 1;
    reshapes[0].f1->size[1] = input_sizes_idx_1;
    emxEnsureCapacity_real_T(reshapes[0].f1, i49);
    nm1d2 = input_sizes_idx_1;
    for (i49 = 0; i49 < nm1d2; i49++) {
      reshapes[0].f1->data[i49] = imaxFirst_data[i49];
    }

    i49 = reshapes[1].f1->size[0] * reshapes[1].f1->size[1];
    reshapes[1].f1->size[0] = 1;
    reshapes[1].f1->size[1] = 499;
    emxEnsureCapacity_real_T(reshapes[1].f1, i49);
    for (i49 = 0; i49 < 499; i49++) {
      reshapes[1].f1->data[i49] = imax->data[i49];
    }

    if ((imaxLast_size_idx_0 != 0) && (imaxLast_size_idx_1 != 0)) {
      input_sizes_idx_1 = (short)imaxLast_size_idx_1;
    } else {
      input_sizes_idx_1 = 0;
    }

    i49 = reshapes[2].f1->size[0] * reshapes[2].f1->size[1];
    reshapes[2].f1->size[0] = 1;
    reshapes[2].f1->size[1] = input_sizes_idx_1;
    emxEnsureCapacity_real_T(reshapes[2].f1, i49);
    nm1d2 = input_sizes_idx_1;
    for (i49 = 0; i49 < nm1d2; i49++) {
      reshapes[2].f1->data[i49] = imaxLast_data[i49];
    }

    emxInit_real_T(&result, 2);
    i49 = result->size[0] * result->size[1];
    result->size[0] = reshapes[0].f1->size[0];
    result->size[1] = (reshapes[0].f1->size[1] + reshapes[1].f1->size[1]) +
      reshapes[2].f1->size[1];
    emxEnsureCapacity_real_T(result, i49);
    nm1d2 = reshapes[0].f1->size[1];
    for (i49 = 0; i49 < nm1d2; i49++) {
      i = reshapes[0].f1->size[0];
      for (first_size_idx_0 = 0; first_size_idx_0 < i; first_size_idx_0++) {
        result->data[first_size_idx_0 + result->size[0] * i49] = reshapes[0].
          f1->data[first_size_idx_0 + reshapes[0].f1->size[0] * i49];
      }
    }

    nm1d2 = reshapes[1].f1->size[1];
    for (i49 = 0; i49 < nm1d2; i49++) {
      i = reshapes[1].f1->size[0];
      for (first_size_idx_0 = 0; first_size_idx_0 < i; first_size_idx_0++) {
        result->data[first_size_idx_0 + result->size[0] * (i49 + reshapes[0].
          f1->size[1])] = reshapes[1].f1->data[first_size_idx_0 + reshapes[1].
          f1->size[0] * i49];
      }
    }

    nm1d2 = reshapes[2].f1->size[1];
    for (i49 = 0; i49 < nm1d2; i49++) {
      i = reshapes[2].f1->size[0];
      for (first_size_idx_0 = 0; first_size_idx_0 < i; first_size_idx_0++) {
        result->data[first_size_idx_0 + result->size[0] * ((i49 + reshapes[0].
          f1->size[1]) + reshapes[1].f1->size[1])] = reshapes[2].f1->
          data[first_size_idx_0 + reshapes[2].f1->size[0] * i49];
      }
    }

    emxFreeMatrix_cell_wrap_43(reshapes);
    result_size[0] = result->size[0];
    result_size[1] = result->size[1];
    nm1d2 = result->size[0] * result->size[1];
    for (i49 = 0; i49 < nm1d2; i49++) {
      b_result_data[i49] = (result->data[i49] == 0.0);
    }

    result_data.data = &b_result_data[0];
    result_data.size = &result_size[0];
    result_data.allocatedSize = 5094;
    result_data.numDimensions = 2;
    result_data.canFreeData = false;
    c_nullAssignment(result, &result_data);
    i49 = imax->size[0] * imax->size[1];
    imax->size[0] = result->size[0];
    imax->size[1] = result->size[1];
    emxEnsureCapacity_real_T(imax, i49);
    nm1d2 = result->size[0] * result->size[1];
    for (i49 = 0; i49 < nm1d2; i49++) {
      imax->data[i49] = result->data[i49];
    }

    i49 = b_max->size[0] * b_max->size[1];
    b_max->size[0] = imax->size[0];
    b_max->size[1] = imax->size[1];
    emxEnsureCapacity_real_T(b_max, i49);
    nm1d2 = imax->size[0] * imax->size[1];
    for (i49 = 0; i49 < nm1d2; i49++) {
      b_max->data[i49] = x[(int)imax->data[i49] - 1];
    }

    emxInit_real_T(&b_result, 2);
    if (iminFirst_size_idx_1 != 0) {
      input_sizes_idx_1 = (short)iminFirst_size_idx_1;
    } else {
      input_sizes_idx_1 = 0;
    }

    if (n != 0) {
      b_input_sizes_idx_1 = (short)n;
    } else {
      b_input_sizes_idx_1 = 0;
    }

    if (iminFirst_size_idx_1 != 0) {
      i = (short)iminFirst_size_idx_1;
    } else {
      i = 0;
    }

    i49 = b_result->size[0] * b_result->size[1];
    b_result->size[0] = 1;
    b_result->size[1] = (input_sizes_idx_1 + b_input_sizes_idx_1) + 499;
    emxEnsureCapacity_real_T(b_result, i49);
    nm1d2 = input_sizes_idx_1;
    for (i49 = 0; i49 < nm1d2; i49++) {
      for (first_size_idx_0 = 0; first_size_idx_0 < 1; first_size_idx_0++) {
        b_result->data[i49] = iminFirst_data[i49];
      }
    }

    for (i49 = 0; i49 < 499; i49++) {
      for (first_size_idx_0 = 0; first_size_idx_0 < 1; first_size_idx_0++) {
        b_result->data[i49 + i] = imin->data[i49];
      }
    }

    emxFree_real_T(&imin);
    nm1d2 = b_input_sizes_idx_1;
    for (i49 = 0; i49 < nm1d2; i49++) {
      for (first_size_idx_0 = 0; first_size_idx_0 < 1; first_size_idx_0++) {
        b_result->data[(i49 + i) + 499] = iminLast_data[i49];
      }
    }

    i49 = result->size[0] * result->size[1];
    result->size[0] = 1;
    result->size[1] = b_result->size[1];
    emxEnsureCapacity_real_T(result, i49);
    nm1d2 = b_result->size[0] * b_result->size[1];
    for (i49 = 0; i49 < nm1d2; i49++) {
      result->data[i49] = b_result->data[i49];
    }

    b_result_size[0] = 1;
    b_result_size[1] = b_result->size[1];
    nm1d2 = b_result->size[0] * b_result->size[1];
    for (i49 = 0; i49 < nm1d2; i49++) {
      c_result_data[i49] = (b_result->data[i49] == 0.0);
    }

    emxFree_real_T(&b_result);
    d_result_data.data = &c_result_data[0];
    d_result_data.size = &b_result_size[0];
    d_result_data.allocatedSize = 5094;
    d_result_data.numDimensions = 2;
    d_result_data.canFreeData = false;
    c_nullAssignment(result, &d_result_data);
    emxFree_real_T(&result);
  }
}

void extrema(const emxArray_creal_T *x, emxArray_creal_T *b_max, emxArray_real_T
             *imax)
{
  emxArray_creal_T *d;
  boolean_T tmp_data[4096];
  int tmp_size[3];
  int n;
  int i26;
  emxArray_real_T *imin;
  emxArray_boolean_T *b_x;
  creal_T direction;
  int loop_ub;
  emxArray_int32_T *ii;
  int nx;
  int idx;
  int nm1d2;
  boolean_T exitg1;
  emxArray_real_T *first;
  emxArray_int32_T *r7;
  emxArray_real_T *last;
  emxArray_boolean_T *c_x;
  emxArray_real_T *iminFirst;
  emxArray_real_T *imaxFirst;
  emxArray_real_T *y;
  int i27;
  emxArray_real_T *b_y;
  int imaxLast_size_idx_0;
  int iminLast_size_idx_1;
  int imaxLast_size_idx_1;
  static double iminLast_data[4095];
  double imaxLast_data[4095];
  emxArray_creal_T *r8;
  double maxct;
  double minct;
  emxArray_creal_T *direction0;
  double constant;
  int k;
  short input_sizes_idx_1;
  cell_wrap_43 reshapes[3];
  boolean_T guard1 = false;
  boolean_T b_direction0;
  double ndbl;
  double apnd;
  double cdiff;
  emxArray_boolean_T *result;
  emxArray_real_T *b_result;
  short b_input_sizes_idx_1;
  emxInit_creal_T(&d, 3);

  /* Reed Gurchiek, */
  /*    extrema finds local minima and maxima of the vector x */
  /*  */
  /* ---------------------------INPUTS----------------------------------------- */
  /*  */
  /*    x: */
  /*        n-element array for which the local minima and maxima will be found */
  /*  */
  /* --------------------------OUTPUTS----------------------------------------- */
  /*  */
  /*    max,imax: */
  /*        local maxima values (max) and their indices (imax) */
  /*  */
  /*    min,imin: */
  /*        local minima values (min) and their indices (imin) */
  /*  */
  /* -------------------------------------------------------------------------- */
  /*  extrema */
  /* initialize */
  b_max->size[0] = 0;
  b_max->size[1] = 0;
  imax->size[0] = 0;
  imax->size[1] = 0;

  /* get differences */
  diff(x, d);

  /* get extrema if any nonzero changes */
  b_any(d, tmp_data, tmp_size);
  if (ifWhileCond(tmp_data, tmp_size)) {
    /* allocation */
    n = d->size[0];
    if ((d->size[0] > 0) && ((d->size[1] == 0) || (d->size[1] > d->size[0]))) {
      n = d->size[1];
    }

    i26 = imax->size[0] * imax->size[1];
    imax->size[0] = 1;
    imax->size[1] = n;
    emxEnsureCapacity_real_T(imax, i26);
    for (i26 = 0; i26 < n; i26++) {
      imax->data[i26] = 0.0;
    }

    n = d->size[0];
    if ((d->size[0] > 0) && ((d->size[1] == 0) || (d->size[1] > d->size[0]))) {
      n = d->size[1];
    }

    emxInit_real_T(&imin, 2);
    i26 = imin->size[0] * imin->size[1];
    imin->size[0] = 1;
    imin->size[1] = n;
    emxEnsureCapacity_real_T(imin, i26);
    for (i26 = 0; i26 < n; i26++) {
      imin->data[i26] = 0.0;
    }

    emxInit_boolean_T(&b_x, 3);

    /* endpoints are always local extrema */
    i26 = b_x->size[0] * b_x->size[1] * b_x->size[2];
    b_x->size[0] = x->size[0];
    b_x->size[1] = x->size[1];
    b_x->size[2] = 1;
    emxEnsureCapacity_boolean_T(b_x, i26);
    direction = x->data[0];
    loop_ub = x->size[0] * x->size[1] * x->size[2];
    for (i26 = 0; i26 < loop_ub; i26++) {
      b_x->data[i26] = ((x->data[i26].re != direction.re) || (x->data[i26].im !=
        direction.im));
    }

    emxInit_int32_T(&ii, 1);
    nx = b_x->size[0] * b_x->size[1];
    idx = 0;
    i26 = ii->size[0];
    ii->size[0] = nx;
    emxEnsureCapacity_int32_T(ii, i26);
    nm1d2 = 0;
    exitg1 = false;
    while ((!exitg1) && (nm1d2 <= nx - 1)) {
      if (b_x->data[nm1d2]) {
        idx++;
        ii->data[idx - 1] = nm1d2 + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          nm1d2++;
        }
      } else {
        nm1d2++;
      }
    }

    if (nx == 1) {
      if (idx == 0) {
        ii->size[0] = 0;
      }
    } else if (1 > idx) {
      ii->size[0] = 0;
    } else {
      i26 = ii->size[0];
      ii->size[0] = idx;
      emxEnsureCapacity_int32_T(ii, i26);
    }

    emxInit_real_T(&first, 1);
    i26 = first->size[0];
    first->size[0] = ii->size[0];
    emxEnsureCapacity_real_T(first, i26);
    loop_ub = ii->size[0];
    for (i26 = 0; i26 < loop_ub; i26++) {
      first->data[i26] = ii->data[i26];
    }

    emxInit_int32_T(&r7, 2);
    loop_ub = first->size[0] - 2;
    i26 = r7->size[0] * r7->size[1];
    r7->size[0] = 1;
    r7->size[1] = loop_ub + 1;
    emxEnsureCapacity_int32_T(r7, i26);
    for (i26 = 0; i26 <= loop_ub; i26++) {
      r7->data[i26] = 2 + i26;
    }

    b_nullAssignment(first, r7);
    i26 = b_x->size[0] * b_x->size[1] * b_x->size[2];
    b_x->size[0] = x->size[0];
    b_x->size[1] = x->size[1];
    b_x->size[2] = 1;
    emxEnsureCapacity_boolean_T(b_x, i26);
    direction = x->data[x->size[0] * x->size[1] - 1];
    loop_ub = x->size[0] * x->size[1] * x->size[2];
    for (i26 = 0; i26 < loop_ub; i26++) {
      b_x->data[i26] = ((x->data[i26].re != direction.re) || (x->data[i26].im !=
        direction.im));
    }

    nx = b_x->size[0] * b_x->size[1];
    idx = 0;
    i26 = ii->size[0];
    ii->size[0] = nx;
    emxEnsureCapacity_int32_T(ii, i26);
    nm1d2 = 0;
    exitg1 = false;
    while ((!exitg1) && (nm1d2 <= nx - 1)) {
      if (b_x->data[nm1d2]) {
        idx++;
        ii->data[idx - 1] = nm1d2 + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          nm1d2++;
        }
      } else {
        nm1d2++;
      }
    }

    emxFree_boolean_T(&b_x);
    if (nx == 1) {
      if (idx == 0) {
        ii->size[0] = 0;
      }
    } else if (1 > idx) {
      ii->size[0] = 0;
    } else {
      i26 = ii->size[0];
      ii->size[0] = idx;
      emxEnsureCapacity_int32_T(ii, i26);
    }

    emxInit_real_T(&last, 1);
    i26 = last->size[0];
    last->size[0] = ii->size[0];
    emxEnsureCapacity_real_T(last, i26);
    loop_ub = ii->size[0];
    for (i26 = 0; i26 < loop_ub; i26++) {
      last->data[i26] = ii->data[i26];
    }

    loop_ub = last->size[0] - 2;
    i26 = r7->size[0] * r7->size[1];
    r7->size[0] = 1;
    r7->size[1] = loop_ub + 1;
    emxEnsureCapacity_int32_T(r7, i26);
    for (i26 = 0; i26 <= loop_ub; i26++) {
      r7->data[i26] = 1 + i26;
    }

    emxInit_boolean_T(&c_x, 1);
    b_nullAssignment(last, r7);
    direction = x->data[0];
    i26 = c_x->size[0];
    c_x->size[0] = first->size[0];
    emxEnsureCapacity_boolean_T(c_x, i26);
    loop_ub = first->size[0];
    emxFree_int32_T(&r7);
    for (i26 = 0; i26 < loop_ub; i26++) {
      c_x->data[i26] = (direction.re < x->data[(int)first->data[i26] - 1].re);
    }

    emxInit_real_T(&iminFirst, 2);
    emxInit_real_T(&imaxFirst, 2);
    if (b_ifWhileCond(c_x)) {
      i26 = ii->size[0];
      ii->size[0] = first->size[0];
      emxEnsureCapacity_int32_T(ii, i26);
      loop_ub = first->size[0];
      for (i26 = 0; i26 < loop_ub; i26++) {
        ii->data[i26] = (int)first->data[i26] - 1;
      }

      if (ii->data[0] < 1) {
        iminFirst->size[0] = 1;
        iminFirst->size[1] = 0;
      } else {
        i26 = ii->data[0];
        i27 = iminFirst->size[0] * iminFirst->size[1];
        iminFirst->size[0] = 1;
        loop_ub = (int)((double)i26 - 1.0);
        iminFirst->size[1] = loop_ub + 1;
        emxEnsureCapacity_real_T(iminFirst, i27);
        for (i26 = 0; i26 <= loop_ub; i26++) {
          iminFirst->data[i26] = 1.0 + (double)i26;
        }
      }

      imaxFirst->size[0] = 0;
      imaxFirst->size[1] = 0;
    } else {
      emxInit_real_T(&y, 2);
      iminFirst->size[0] = 1;
      iminFirst->size[1] = 0;
      i26 = ii->size[0];
      ii->size[0] = first->size[0];
      emxEnsureCapacity_int32_T(ii, i26);
      loop_ub = first->size[0];
      for (i26 = 0; i26 < loop_ub; i26++) {
        ii->data[i26] = (int)first->data[i26] - 1;
      }

      if (ii->data[0] < 1) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else {
        i26 = ii->data[0];
        i27 = y->size[0] * y->size[1];
        y->size[0] = 1;
        loop_ub = (int)((double)i26 - 1.0);
        y->size[1] = loop_ub + 1;
        emxEnsureCapacity_real_T(y, i27);
        for (i26 = 0; i26 <= loop_ub; i26++) {
          y->data[i26] = 1.0 + (double)i26;
        }
      }

      i26 = imaxFirst->size[0] * imaxFirst->size[1];
      imaxFirst->size[0] = 1;
      imaxFirst->size[1] = y->size[1];
      emxEnsureCapacity_real_T(imaxFirst, i26);
      loop_ub = y->size[0] * y->size[1];
      for (i26 = 0; i26 < loop_ub; i26++) {
        imaxFirst->data[i26] = y->data[i26];
      }

      emxFree_real_T(&y);
    }

    direction = x->data[x->size[0] * x->size[1] - 1];
    i26 = c_x->size[0];
    c_x->size[0] = last->size[0];
    emxEnsureCapacity_boolean_T(c_x, i26);
    loop_ub = last->size[0];
    for (i26 = 0; i26 < loop_ub; i26++) {
      c_x->data[i26] = (direction.re < x->data[(int)last->data[i26] - 1].re);
    }

    emxInit_real_T(&b_y, 2);
    if (b_ifWhileCond(c_x)) {
      n = x->size[0];
      if ((x->size[0] > 0) && ((x->size[1] == 0) || (x->size[1] > x->size[0])))
      {
        n = x->size[1];
      }

      i26 = ii->size[0];
      ii->size[0] = last->size[0];
      emxEnsureCapacity_int32_T(ii, i26);
      loop_ub = last->size[0];
      for (i26 = 0; i26 < loop_ub; i26++) {
        ii->data[i26] = (int)last->data[i26] + 1;
      }

      if (n < ii->data[0]) {
        b_y->size[0] = 1;
        b_y->size[1] = 0;
      } else {
        i26 = ii->data[0];
        i27 = b_y->size[0] * b_y->size[1];
        b_y->size[0] = 1;
        loop_ub = (int)((double)n - (double)i26);
        b_y->size[1] = loop_ub + 1;
        emxEnsureCapacity_real_T(b_y, i27);
        for (i27 = 0; i27 <= loop_ub; i27++) {
          b_y->data[i27] = (double)i26 + (double)i27;
        }
      }

      iminLast_size_idx_1 = b_y->size[1];
      loop_ub = b_y->size[0] * b_y->size[1];
      for (i26 = 0; i26 < loop_ub; i26++) {
        iminLast_data[i26] = b_y->data[i26];
      }

      imaxLast_size_idx_0 = 0;
      imaxLast_size_idx_1 = 0;
    } else {
      n = x->size[0];
      if ((x->size[0] > 0) && ((x->size[1] == 0) || (x->size[1] > x->size[0])))
      {
        n = x->size[1];
      }

      i26 = ii->size[0];
      ii->size[0] = last->size[0];
      emxEnsureCapacity_int32_T(ii, i26);
      loop_ub = last->size[0];
      for (i26 = 0; i26 < loop_ub; i26++) {
        ii->data[i26] = (int)last->data[i26] + 1;
      }

      if (n < ii->data[0]) {
        b_y->size[0] = 1;
        b_y->size[1] = 0;
      } else {
        i26 = ii->data[0];
        i27 = b_y->size[0] * b_y->size[1];
        b_y->size[0] = 1;
        loop_ub = (int)((double)n - (double)i26);
        b_y->size[1] = loop_ub + 1;
        emxEnsureCapacity_real_T(b_y, i27);
        for (i27 = 0; i27 <= loop_ub; i27++) {
          b_y->data[i27] = (double)i26 + (double)i27;
        }
      }

      imaxLast_size_idx_0 = 1;
      imaxLast_size_idx_1 = b_y->size[1];
      loop_ub = b_y->size[0] * b_y->size[1];
      for (i26 = 0; i26 < loop_ub; i26++) {
        imaxLast_data[i26] = b_y->data[i26];
      }

      iminLast_size_idx_1 = 0;
    }

    emxFree_boolean_T(&c_x);
    emxFree_int32_T(&ii);
    emxInit_creal_T(&r8, 1);

    /* for each element */
    maxct = 0.0;
    minct = 0.0;
    i26 = r8->size[0];
    r8->size[0] = first->size[0];
    emxEnsureCapacity_creal_T(r8, i26);
    loop_ub = first->size[0];
    for (i26 = 0; i26 < loop_ub; i26++) {
      r8->data[i26] = x->data[(int)first->data[i26] - 2];
    }

    emxInit_creal_T(&direction0, 1);
    i26 = direction0->size[0];
    direction0->size[0] = first->size[0];
    emxEnsureCapacity_creal_T(direction0, i26);
    loop_ub = first->size[0];
    for (i26 = 0; i26 < loop_ub; i26++) {
      direction0->data[i26].re = x->data[(int)first->data[i26] - 1].re -
        r8->data[i26].re;
      direction0->data[i26].im = x->data[(int)first->data[i26] - 1].im -
        r8->data[i26].im;
    }

    emxFree_creal_T(&r8);
    b_sign(direction0);
    constant = 0.0;

    /* the following is to convert k bounds to scalar for matlab coder */
    i26 = first->size[0];
    emxEnsureCapacity_real_T(first, i26);
    loop_ub = first->size[0];
    for (i26 = 0; i26 < loop_ub; i26++) {
      first->data[i26]++;
    }

    i26 = last->size[0];
    emxEnsureCapacity_real_T(last, i26);
    loop_ub = last->size[0];
    for (i26 = 0; i26 < loop_ub; i26++) {
      last->data[i26]++;
    }

    i26 = (int)(last->data[0] + (1.0 - first->data[0]));
    emxFree_real_T(&last);
    for (k = 0; k < i26; k++) {
      nx = (int)first->data[0] + k;

      /* current trajectory */
      direction.re = x->data[nx - 1].re - x->data[nx - 2].re;
      direction.im = x->data[nx - 1].im - x->data[nx - 2].im;
      c_sign(&direction);

      /* if no change */
      if ((direction.re == 0.0) && (direction.im == 0.0)) {
        constant++;

        /* otherwise */
      } else {
        /* The following is also for matlab coder, to identify that */
        /* direction 0 is a scalar */
        /* if local minimum */
        guard1 = false;
        if ((direction.re == 1.0) && (direction.im == 0.0)) {
          b_direction0 = ((direction0->data[0].re == -1.0) && (direction0->data
            [0].im == 0.0));
          if (b_direction0) {
            /* update min/imin */
            minct = (minct + 1.0) + constant;
            ndbl = minct - constant;
            if (ndbl > minct) {
              i27 = 1;
            } else {
              i27 = (int)ndbl;
            }

            constant = ((double)nx - 1.0) - constant;
            if ((double)nx - 1.0 < constant) {
              b_y->size[0] = 1;
              b_y->size[1] = 0;
            } else if (rtIsInf(constant) && (constant == (double)nx - 1.0)) {
              idx = b_y->size[0] * b_y->size[1];
              b_y->size[0] = 1;
              b_y->size[1] = 1;
              emxEnsureCapacity_real_T(b_y, idx);
              b_y->data[0] = rtNaN;
            } else if (constant == constant) {
              idx = b_y->size[0] * b_y->size[1];
              b_y->size[0] = 1;
              loop_ub = (int)(((double)nx - 1.0) - constant);
              b_y->size[1] = loop_ub + 1;
              emxEnsureCapacity_real_T(b_y, idx);
              for (idx = 0; idx <= loop_ub; idx++) {
                b_y->data[idx] = constant + (double)idx;
              }
            } else {
              ndbl = floor((((double)nx - 1.0) - constant) + 0.5);
              apnd = constant + ndbl;
              cdiff = apnd - ((double)nx - 1.0);
              if (fabs(cdiff) < 4.4408920985006262E-16 * fmax(fabs(constant), nx
                   - 1)) {
                ndbl++;
                apnd = (double)nx - 1.0;
              } else if (cdiff > 0.0) {
                apnd = constant + (ndbl - 1.0);
              } else {
                ndbl++;
              }

              if (ndbl >= 0.0) {
                n = (int)ndbl;
              } else {
                n = 0;
              }

              idx = b_y->size[0] * b_y->size[1];
              b_y->size[0] = 1;
              b_y->size[1] = n;
              emxEnsureCapacity_real_T(b_y, idx);
              if (n > 0) {
                b_y->data[0] = constant;
                if (n > 1) {
                  b_y->data[n - 1] = apnd;
                  nm1d2 = (n - 1) / 2;
                  for (nx = 0; nx <= nm1d2 - 2; nx++) {
                    b_y->data[1 + nx] = constant + (1.0 + (double)nx);
                    b_y->data[(n - nx) - 2] = apnd - (1.0 + (double)nx);
                  }

                  if (nm1d2 << 1 == n - 1) {
                    b_y->data[nm1d2] = (constant + apnd) / 2.0;
                  } else {
                    b_y->data[nm1d2] = constant + (double)nm1d2;
                    b_y->data[nm1d2 + 1] = apnd - (double)nm1d2;
                  }
                }
              }
            }

            loop_ub = b_y->size[1];
            for (idx = 0; idx < loop_ub; idx++) {
              imin->data[(i27 + idx) - 1] = b_y->data[idx];
            }

            /* if local maximum */
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1 && ((direction.re == -1.0) && (direction.im == 0.0))) {
          b_direction0 = ((direction0->data[0].re == 1.0) && (direction0->data[0]
            .im == 0.0));
          if (b_direction0) {
            /* update max/imax */
            maxct = (maxct + 1.0) + constant;
            ndbl = maxct - constant;
            if (ndbl > maxct) {
              i27 = 1;
            } else {
              i27 = (int)ndbl;
            }

            constant = ((double)nx - 1.0) - constant;
            if ((double)nx - 1.0 < constant) {
              b_y->size[0] = 1;
              b_y->size[1] = 0;
            } else if (rtIsInf(constant) && (constant == (double)nx - 1.0)) {
              idx = b_y->size[0] * b_y->size[1];
              b_y->size[0] = 1;
              b_y->size[1] = 1;
              emxEnsureCapacity_real_T(b_y, idx);
              b_y->data[0] = rtNaN;
            } else if (constant == constant) {
              idx = b_y->size[0] * b_y->size[1];
              b_y->size[0] = 1;
              loop_ub = (int)(((double)nx - 1.0) - constant);
              b_y->size[1] = loop_ub + 1;
              emxEnsureCapacity_real_T(b_y, idx);
              for (idx = 0; idx <= loop_ub; idx++) {
                b_y->data[idx] = constant + (double)idx;
              }
            } else {
              ndbl = floor((((double)nx - 1.0) - constant) + 0.5);
              apnd = constant + ndbl;
              cdiff = apnd - ((double)nx - 1.0);
              if (fabs(cdiff) < 4.4408920985006262E-16 * fmax(fabs(constant), nx
                   - 1)) {
                ndbl++;
                apnd = (double)nx - 1.0;
              } else if (cdiff > 0.0) {
                apnd = constant + (ndbl - 1.0);
              } else {
                ndbl++;
              }

              if (ndbl >= 0.0) {
                n = (int)ndbl;
              } else {
                n = 0;
              }

              idx = b_y->size[0] * b_y->size[1];
              b_y->size[0] = 1;
              b_y->size[1] = n;
              emxEnsureCapacity_real_T(b_y, idx);
              if (n > 0) {
                b_y->data[0] = constant;
                if (n > 1) {
                  b_y->data[n - 1] = apnd;
                  nm1d2 = (n - 1) / 2;
                  for (nx = 0; nx <= nm1d2 - 2; nx++) {
                    b_y->data[1 + nx] = constant + (1.0 + (double)nx);
                    b_y->data[(n - nx) - 2] = apnd - (1.0 + (double)nx);
                  }

                  if (nm1d2 << 1 == n - 1) {
                    b_y->data[nm1d2] = (constant + apnd) / 2.0;
                  } else {
                    b_y->data[nm1d2] = constant + (double)nm1d2;
                    b_y->data[nm1d2 + 1] = apnd - (double)nm1d2;
                  }
                }
              }
            }

            loop_ub = b_y->size[1];
            for (idx = 0; idx < loop_ub; idx++) {
              imax->data[(i27 + idx) - 1] = b_y->data[idx];
            }
          }
        }

        /* current trajectory is next iteration previous */
        i27 = direction0->size[0];
        direction0->size[0] = 1;
        emxEnsureCapacity_creal_T(direction0, i27);
        direction0->data[0] = direction;

        /* no consecutive constant */
        constant = 0.0;
      }
    }

    emxFree_real_T(&b_y);
    emxFree_creal_T(&direction0);
    emxFree_real_T(&first);

    /* finish */
    if ((imaxFirst->size[0] != 0) && (imaxFirst->size[1] != 0)) {
      nx = imaxFirst->size[1];
    } else {
      nx = 0;
    }

    if (imax->size[1] != 0) {
      input_sizes_idx_1 = (short)imax->size[1];
    } else {
      input_sizes_idx_1 = 0;
    }

    emxInitMatrix_cell_wrap_43(reshapes);
    i26 = reshapes[1].f1->size[0] * reshapes[1].f1->size[1];
    reshapes[1].f1->size[0] = 1;
    reshapes[1].f1->size[1] = input_sizes_idx_1;
    emxEnsureCapacity_real_T(reshapes[1].f1, i26);
    loop_ub = input_sizes_idx_1;
    for (i26 = 0; i26 < loop_ub; i26++) {
      reshapes[1].f1->data[i26] = imax->data[i26];
    }

    if ((imaxLast_size_idx_0 != 0) && (imaxLast_size_idx_1 != 0)) {
      input_sizes_idx_1 = (short)imaxLast_size_idx_1;
    } else {
      input_sizes_idx_1 = 0;
    }

    i26 = reshapes[2].f1->size[0] * reshapes[2].f1->size[1];
    reshapes[2].f1->size[0] = 1;
    reshapes[2].f1->size[1] = input_sizes_idx_1;
    emxEnsureCapacity_real_T(reshapes[2].f1, i26);
    loop_ub = input_sizes_idx_1;
    for (i26 = 0; i26 < loop_ub; i26++) {
      reshapes[2].f1->data[i26] = imaxLast_data[i26];
    }

    i26 = imax->size[0] * imax->size[1];
    imax->size[0] = 1;
    imax->size[1] = (nx + reshapes[1].f1->size[1]) + reshapes[2].f1->size[1];
    emxEnsureCapacity_real_T(imax, i26);
    for (i26 = 0; i26 < nx; i26++) {
      for (i27 = 0; i27 < 1; i27++) {
        imax->data[imax->size[0] * i26] = imaxFirst->data[imaxFirst->size[0] *
          i26];
      }
    }

    emxFree_real_T(&imaxFirst);
    loop_ub = reshapes[1].f1->size[1];
    for (i26 = 0; i26 < loop_ub; i26++) {
      nm1d2 = reshapes[1].f1->size[0];
      for (i27 = 0; i27 < nm1d2; i27++) {
        imax->data[i27 + imax->size[0] * (i26 + nx)] = reshapes[1].f1->data[i27
          + reshapes[1].f1->size[0] * i26];
      }
    }

    loop_ub = reshapes[2].f1->size[1];
    for (i26 = 0; i26 < loop_ub; i26++) {
      nm1d2 = reshapes[2].f1->size[0];
      for (i27 = 0; i27 < nm1d2; i27++) {
        imax->data[i27 + imax->size[0] * ((i26 + nx) + reshapes[1].f1->size[1])]
          = reshapes[2].f1->data[i27 + reshapes[2].f1->size[0] * i26];
      }
    }

    emxFreeMatrix_cell_wrap_43(reshapes);
    emxInit_boolean_T(&result, 2);
    i26 = result->size[0] * result->size[1];
    result->size[0] = imax->size[0];
    result->size[1] = imax->size[1];
    emxEnsureCapacity_boolean_T(result, i26);
    loop_ub = imax->size[0] * imax->size[1];
    for (i26 = 0; i26 < loop_ub; i26++) {
      result->data[i26] = (imax->data[i26] == 0.0);
    }

    c_nullAssignment(imax, result);
    i26 = b_max->size[0] * b_max->size[1];
    b_max->size[0] = imax->size[0];
    b_max->size[1] = imax->size[1];
    emxEnsureCapacity_creal_T(b_max, i26);
    loop_ub = imax->size[0] * imax->size[1];
    for (i26 = 0; i26 < loop_ub; i26++) {
      b_max->data[i26] = x->data[(int)imax->data[i26] - 1];
    }

    emxInit_real_T(&b_result, 2);
    if (iminFirst->size[1] != 0) {
      nx = iminFirst->size[1];
    } else {
      nx = 0;
    }

    if (imin->size[1] != 0) {
      input_sizes_idx_1 = (short)imin->size[1];
    } else {
      input_sizes_idx_1 = 0;
    }

    if (iminLast_size_idx_1 != 0) {
      b_input_sizes_idx_1 = (short)iminLast_size_idx_1;
    } else {
      b_input_sizes_idx_1 = 0;
    }

    i26 = b_result->size[0] * b_result->size[1];
    b_result->size[0] = 1;
    b_result->size[1] = (nx + input_sizes_idx_1) + b_input_sizes_idx_1;
    emxEnsureCapacity_real_T(b_result, i26);
    for (i26 = 0; i26 < nx; i26++) {
      for (i27 = 0; i27 < 1; i27++) {
        b_result->data[i26] = iminFirst->data[i26];
      }
    }

    emxFree_real_T(&iminFirst);
    loop_ub = input_sizes_idx_1;
    for (i26 = 0; i26 < loop_ub; i26++) {
      for (i27 = 0; i27 < 1; i27++) {
        b_result->data[i26 + nx] = imin->data[i26];
      }
    }

    loop_ub = b_input_sizes_idx_1;
    for (i26 = 0; i26 < loop_ub; i26++) {
      for (i27 = 0; i27 < 1; i27++) {
        b_result->data[(i26 + nx) + input_sizes_idx_1] = iminLast_data[i26];
      }
    }

    i26 = imin->size[0] * imin->size[1];
    imin->size[0] = 1;
    imin->size[1] = b_result->size[1];
    emxEnsureCapacity_real_T(imin, i26);
    loop_ub = b_result->size[0] * b_result->size[1];
    for (i26 = 0; i26 < loop_ub; i26++) {
      imin->data[i26] = b_result->data[i26];
    }

    i26 = result->size[0] * result->size[1];
    result->size[0] = 1;
    result->size[1] = b_result->size[1];
    emxEnsureCapacity_boolean_T(result, i26);
    loop_ub = b_result->size[0] * b_result->size[1];
    for (i26 = 0; i26 < loop_ub; i26++) {
      result->data[i26] = (b_result->data[i26] == 0.0);
    }

    emxFree_real_T(&b_result);
    c_nullAssignment(imin, result);
    emxFree_boolean_T(&result);
    emxFree_real_T(&imin);
  }

  emxFree_creal_T(&d);
}

/* End of code generation (extrema.c) */

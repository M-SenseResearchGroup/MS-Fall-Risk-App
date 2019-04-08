/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * extrema.cpp
 *
 * Code generation for function 'extrema'
 *
 */

/* Include files */
#include <cmath>
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "extrema.h"
#include "calc_fall_risk_emxutil.h"
#include "nullAssignment.h"
#include "sign.h"
#include "ifWhileCond.h"
#include "any1.h"
#include "diff.h"
#include "sign1.h"
#include <string.h>

/* Function Definitions */
void b_extrema(const emxArray_real_T *x, emxArray_real_T *b_max, emxArray_real_T
               *imax)
{
  emxArray_real_T *d;
  int i69;
  int input_sizes_idx_1;
  emxArray_real_T *imin;
  emxArray_boolean_T *b_x;
  double constant;
  emxArray_int32_T *ii;
  int nx;
  int idx;
  boolean_T exitg1;
  emxArray_real_T *first;
  emxArray_real_T *last;
  emxArray_real_T *iminFirst;
  emxArray_real_T *imaxFirst;
  emxArray_real_T *direction0;
  int i70;
  emxArray_real_T *iminLast;
  emxArray_real_T *imaxLast;
  unsigned int u0;
  double maxct;
  double minct;
  int k;
  unsigned int b_k;
  double direction;
  cell_wrap_26 reshapes[3];
  double ndbl;
  double apnd;
  double cdiff;
  double b_u0;
  double u1;
  emxArray_boolean_T *b_d;
  emxInit_real_T(&d, 2);

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
  /* UPDATED */
  /* initialize */
  b_max->size[0] = 0;
  b_max->size[1] = 0;
  imax->size[0] = 0;
  imax->size[1] = 0;

  /* get differences */
  b_diff(x, d);

  /* get extrema if any nonzero changes */
  if (c_any(d)) {
    /* allocation */
    i69 = imax->size[0] * imax->size[1];
    imax->size[0] = 1;
    imax->size[1] = d->size[1];
    emxEnsureCapacity_real_T(imax, i69);
    input_sizes_idx_1 = d->size[1];
    for (i69 = 0; i69 < input_sizes_idx_1; i69++) {
      imax->data[i69] = 0.0;
    }

    emxInit_real_T(&imin, 2);
    i69 = imin->size[0] * imin->size[1];
    imin->size[0] = 1;
    imin->size[1] = d->size[1];
    emxEnsureCapacity_real_T(imin, i69);
    input_sizes_idx_1 = d->size[1];
    for (i69 = 0; i69 < input_sizes_idx_1; i69++) {
      imin->data[i69] = 0.0;
    }

    emxInit_boolean_T(&b_x, 2);

    /* endpoints are always local extrema */
    i69 = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = x->size[1];
    emxEnsureCapacity_boolean_T(b_x, i69);
    constant = x->data[0];
    input_sizes_idx_1 = x->size[0] * x->size[1];
    for (i69 = 0; i69 < input_sizes_idx_1; i69++) {
      b_x->data[i69] = (x->data[i69] != constant);
    }

    emxInit_int32_T(&ii, 2);
    nx = b_x->size[1];
    idx = 0;
    i69 = ii->size[0] * ii->size[1];
    ii->size[0] = 1;
    ii->size[1] = b_x->size[1];
    emxEnsureCapacity_int32_T(ii, i69);
    input_sizes_idx_1 = 0;
    exitg1 = false;
    while ((!exitg1) && (input_sizes_idx_1 <= nx - 1)) {
      if (b_x->data[input_sizes_idx_1]) {
        idx++;
        ii->data[idx - 1] = input_sizes_idx_1 + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          input_sizes_idx_1++;
        }
      } else {
        input_sizes_idx_1++;
      }
    }

    if (b_x->size[1] == 1) {
      if (idx == 0) {
        ii->size[0] = 1;
        ii->size[1] = 0;
      }
    } else if (1 > idx) {
      ii->size[1] = 0;
    } else {
      i69 = ii->size[0] * ii->size[1];
      ii->size[1] = idx;
      emxEnsureCapacity_int32_T(ii, i69);
    }

    emxInit_real_T(&first, 2);
    i69 = first->size[0] * first->size[1];
    first->size[0] = 1;
    first->size[1] = ii->size[1];
    emxEnsureCapacity_real_T(first, i69);
    input_sizes_idx_1 = ii->size[0] * ii->size[1];
    for (i69 = 0; i69 < input_sizes_idx_1; i69++) {
      first->data[i69] = ii->data[i69];
    }

    input_sizes_idx_1 = first->size[1] - 2;
    i69 = ii->size[0] * ii->size[1];
    ii->size[0] = 1;
    ii->size[1] = input_sizes_idx_1 + 1;
    emxEnsureCapacity_int32_T(ii, i69);
    for (i69 = 0; i69 <= input_sizes_idx_1; i69++) {
      ii->data[i69] = 2 + i69;
    }

    d_nullAssignment(first, ii);
    i69 = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = x->size[1];
    emxEnsureCapacity_boolean_T(b_x, i69);
    constant = x->data[x->size[1] - 1];
    input_sizes_idx_1 = x->size[0] * x->size[1];
    for (i69 = 0; i69 < input_sizes_idx_1; i69++) {
      b_x->data[i69] = (x->data[i69] != constant);
    }

    nx = b_x->size[1];
    idx = 0;
    i69 = ii->size[0] * ii->size[1];
    ii->size[0] = 1;
    ii->size[1] = b_x->size[1];
    emxEnsureCapacity_int32_T(ii, i69);
    input_sizes_idx_1 = 0;
    exitg1 = false;
    while ((!exitg1) && (input_sizes_idx_1 <= nx - 1)) {
      if (b_x->data[input_sizes_idx_1]) {
        idx++;
        ii->data[idx - 1] = input_sizes_idx_1 + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          input_sizes_idx_1++;
        }
      } else {
        input_sizes_idx_1++;
      }
    }

    if (b_x->size[1] == 1) {
      if (idx == 0) {
        ii->size[0] = 1;
        ii->size[1] = 0;
      }
    } else if (1 > idx) {
      ii->size[1] = 0;
    } else {
      i69 = ii->size[0] * ii->size[1];
      ii->size[1] = idx;
      emxEnsureCapacity_int32_T(ii, i69);
    }

    emxInit_real_T(&last, 2);
    i69 = last->size[0] * last->size[1];
    last->size[0] = 1;
    last->size[1] = ii->size[1];
    emxEnsureCapacity_real_T(last, i69);
    input_sizes_idx_1 = ii->size[0] * ii->size[1];
    for (i69 = 0; i69 < input_sizes_idx_1; i69++) {
      last->data[i69] = ii->data[i69];
    }

    input_sizes_idx_1 = last->size[1] - 2;
    i69 = ii->size[0] * ii->size[1];
    ii->size[0] = 1;
    ii->size[1] = input_sizes_idx_1 + 1;
    emxEnsureCapacity_int32_T(ii, i69);
    for (i69 = 0; i69 <= input_sizes_idx_1; i69++) {
      ii->data[i69] = 1 + i69;
    }

    d_nullAssignment(last, ii);
    constant = x->data[0];
    i69 = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = first->size[1];
    emxEnsureCapacity_boolean_T(b_x, i69);
    input_sizes_idx_1 = first->size[0] * first->size[1];
    emxFree_int32_T(&ii);
    for (i69 = 0; i69 < input_sizes_idx_1; i69++) {
      b_x->data[i69] = (constant < x->data[static_cast<int>(first->data[i69]) -
                        1]);
    }

    emxInit_real_T(&iminFirst, 2);
    emxInit_real_T(&imaxFirst, 2);
    emxInit_real_T(&direction0, 2);
    if (c_ifWhileCond(b_x)) {
      i69 = d->size[0] * d->size[1];
      d->size[0] = 1;
      d->size[1] = first->size[1];
      emxEnsureCapacity_real_T(d, i69);
      input_sizes_idx_1 = first->size[0] * first->size[1];
      for (i69 = 0; i69 < input_sizes_idx_1; i69++) {
        d->data[i69] = first->data[i69] - 1.0;
      }

      if (static_cast<int>(d->data[0]) < 1) {
        iminFirst->size[0] = 1;
        iminFirst->size[1] = 0;
      } else {
        i69 = static_cast<int>(d->data[0]);
        i70 = iminFirst->size[0] * iminFirst->size[1];
        iminFirst->size[0] = 1;
        input_sizes_idx_1 = i69 - 1;
        iminFirst->size[1] = input_sizes_idx_1 + 1;
        emxEnsureCapacity_real_T(iminFirst, i70);
        for (i69 = 0; i69 <= input_sizes_idx_1; i69++) {
          iminFirst->data[i69] = 1.0 + static_cast<double>(i69);
        }
      }

      imaxFirst->size[0] = 0;
      imaxFirst->size[1] = 0;
    } else {
      iminFirst->size[0] = 1;
      iminFirst->size[1] = 0;
      i69 = d->size[0] * d->size[1];
      d->size[0] = 1;
      d->size[1] = first->size[1];
      emxEnsureCapacity_real_T(d, i69);
      input_sizes_idx_1 = first->size[0] * first->size[1];
      for (i69 = 0; i69 < input_sizes_idx_1; i69++) {
        d->data[i69] = first->data[i69] - 1.0;
      }

      if (static_cast<int>(d->data[0]) < 1) {
        direction0->size[0] = 1;
        direction0->size[1] = 0;
      } else {
        i69 = static_cast<int>(d->data[0]);
        i70 = direction0->size[0] * direction0->size[1];
        direction0->size[0] = 1;
        input_sizes_idx_1 = i69 - 1;
        direction0->size[1] = input_sizes_idx_1 + 1;
        emxEnsureCapacity_real_T(direction0, i70);
        for (i69 = 0; i69 <= input_sizes_idx_1; i69++) {
          direction0->data[i69] = 1.0 + static_cast<double>(i69);
        }
      }

      i69 = imaxFirst->size[0] * imaxFirst->size[1];
      imaxFirst->size[0] = 1;
      imaxFirst->size[1] = direction0->size[1];
      emxEnsureCapacity_real_T(imaxFirst, i69);
      input_sizes_idx_1 = direction0->size[0] * direction0->size[1];
      for (i69 = 0; i69 < input_sizes_idx_1; i69++) {
        imaxFirst->data[i69] = direction0->data[i69];
      }
    }

    constant = x->data[x->size[1] - 1];
    i69 = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = last->size[1];
    emxEnsureCapacity_boolean_T(b_x, i69);
    input_sizes_idx_1 = last->size[0] * last->size[1];
    for (i69 = 0; i69 < input_sizes_idx_1; i69++) {
      b_x->data[i69] = (constant < x->data[static_cast<int>(last->data[i69]) - 1]);
    }

    emxInit_real_T(&iminLast, 2);
    emxInit_real_T(&imaxLast, 2);
    if (c_ifWhileCond(b_x)) {
      i69 = d->size[0] * d->size[1];
      d->size[0] = 1;
      d->size[1] = last->size[1];
      emxEnsureCapacity_real_T(d, i69);
      input_sizes_idx_1 = last->size[0] * last->size[1];
      for (i69 = 0; i69 < input_sizes_idx_1; i69++) {
        d->data[i69] = last->data[i69] + 1.0;
      }

      if (static_cast<unsigned int>(x->size[1]) < static_cast<unsigned int>
          (d->data[0])) {
        iminLast->size[0] = 1;
        iminLast->size[1] = 0;
      } else {
        u0 = static_cast<unsigned int>(d->data[0]);
        i69 = x->size[1];
        i70 = iminLast->size[0] * iminLast->size[1];
        iminLast->size[0] = 1;
        input_sizes_idx_1 = i69 - static_cast<int>(u0);
        iminLast->size[1] = input_sizes_idx_1 + 1;
        emxEnsureCapacity_real_T(iminLast, i70);
        for (i69 = 0; i69 <= input_sizes_idx_1; i69++) {
          iminLast->data[i69] = static_cast<double>(u0) + static_cast<double>
            (i69);
        }
      }

      imaxLast->size[0] = 0;
      imaxLast->size[1] = 0;
    } else {
      i69 = d->size[0] * d->size[1];
      d->size[0] = 1;
      d->size[1] = last->size[1];
      emxEnsureCapacity_real_T(d, i69);
      input_sizes_idx_1 = last->size[0] * last->size[1];
      for (i69 = 0; i69 < input_sizes_idx_1; i69++) {
        d->data[i69] = last->data[i69] + 1.0;
      }

      if (static_cast<unsigned int>(x->size[1]) < static_cast<unsigned int>
          (d->data[0])) {
        direction0->size[0] = 1;
        direction0->size[1] = 0;
      } else {
        u0 = static_cast<unsigned int>(d->data[0]);
        i69 = x->size[1];
        i70 = direction0->size[0] * direction0->size[1];
        direction0->size[0] = 1;
        input_sizes_idx_1 = i69 - static_cast<int>(u0);
        direction0->size[1] = input_sizes_idx_1 + 1;
        emxEnsureCapacity_real_T(direction0, i70);
        for (i69 = 0; i69 <= input_sizes_idx_1; i69++) {
          direction0->data[i69] = static_cast<double>(u0) + static_cast<double>
            (i69);
        }
      }

      i69 = imaxLast->size[0] * imaxLast->size[1];
      imaxLast->size[0] = 1;
      imaxLast->size[1] = direction0->size[1];
      emxEnsureCapacity_real_T(imaxLast, i69);
      input_sizes_idx_1 = direction0->size[0] * direction0->size[1];
      for (i69 = 0; i69 < input_sizes_idx_1; i69++) {
        imaxLast->data[i69] = direction0->data[i69];
      }

      iminLast->size[0] = 1;
      iminLast->size[1] = 0;
    }

    emxFree_boolean_T(&b_x);

    /* for each element */
    maxct = 0.0;
    minct = 0.0;
    i69 = d->size[0] * d->size[1];
    d->size[0] = 1;
    d->size[1] = first->size[1];
    emxEnsureCapacity_real_T(d, i69);
    input_sizes_idx_1 = first->size[0] * first->size[1];
    for (i69 = 0; i69 < input_sizes_idx_1; i69++) {
      d->data[i69] = x->data[static_cast<int>(first->data[i69]) - 2];
    }

    i69 = direction0->size[0] * direction0->size[1];
    direction0->size[0] = 1;
    direction0->size[1] = first->size[1];
    emxEnsureCapacity_real_T(direction0, i69);
    input_sizes_idx_1 = first->size[0] * first->size[1];
    for (i69 = 0; i69 < input_sizes_idx_1; i69++) {
      direction0->data[i69] = x->data[static_cast<int>(first->data[i69]) - 1] -
        d->data[i69];
    }

    d_sign(direction0);
    constant = 0.0;
    u0 = static_cast<unsigned int>(first->data[0]) + 1U;
    i69 = static_cast<int>(((last->data[0] + 1.0) + (1.0 - static_cast<double>
      (u0))));
    emxFree_real_T(&last);
    emxFree_real_T(&first);
    for (k = 0; k < i69; k++) {
      b_k = u0 + k;

      /* current trajectory */
      input_sizes_idx_1 = static_cast<int>(b_k) - 1;
      direction = x->data[input_sizes_idx_1] - x->data[static_cast<int>(b_k) - 2];
      e_sign(&direction);

      /* if no change */
      if (direction == 0.0) {
        constant++;

        /* otherwise */
      } else {
        /* if local minimum */
        if ((direction == 1.0) && (direction0->data[0] == -1.0)) {
          /* update min/imin */
          minct = (minct + 1.0) + constant;
          ndbl = minct - constant;
          if (ndbl > minct) {
            i70 = 1;
          } else {
            i70 = static_cast<int>(ndbl);
          }

          constant = (static_cast<double>(b_k) - 1.0) - constant;
          if (static_cast<double>(b_k) - 1.0 < constant) {
            d->size[0] = 1;
            d->size[1] = 0;
          } else if (rtIsInf(constant) && (constant == static_cast<double>(b_k)
                      - 1.0)) {
            nx = d->size[0] * d->size[1];
            d->size[0] = 1;
            d->size[1] = 1;
            emxEnsureCapacity_real_T(d, nx);
            d->data[0] = rtNaN;
          } else if (constant == constant) {
            nx = d->size[0] * d->size[1];
            d->size[0] = 1;
            input_sizes_idx_1 = static_cast<int>(((static_cast<double>(b_k) -
              1.0) - constant));
            d->size[1] = input_sizes_idx_1 + 1;
            emxEnsureCapacity_real_T(d, nx);
            for (nx = 0; nx <= input_sizes_idx_1; nx++) {
              d->data[nx] = constant + static_cast<double>(nx);
            }
          } else {
            ndbl = std::floor(((static_cast<double>(b_k) - 1.0) - constant) +
                              0.5);
            apnd = constant + ndbl;
            cdiff = apnd - (static_cast<double>(b_k) - 1.0);
            b_u0 = std::abs(constant);
            u1 = input_sizes_idx_1;
            if (b_u0 > u1) {
              u1 = b_u0;
            }

            if (std::abs(cdiff) < 4.4408920985006262E-16 * u1) {
              ndbl++;
              apnd = static_cast<double>(b_k) - 1.0;
            } else if (cdiff > 0.0) {
              apnd = constant + (ndbl - 1.0);
            } else {
              ndbl++;
            }

            if (ndbl >= 0.0) {
              input_sizes_idx_1 = static_cast<int>(ndbl);
            } else {
              input_sizes_idx_1 = 0;
            }

            nx = d->size[0] * d->size[1];
            d->size[0] = 1;
            d->size[1] = input_sizes_idx_1;
            emxEnsureCapacity_real_T(d, nx);
            if (input_sizes_idx_1 > 0) {
              d->data[0] = constant;
              if (input_sizes_idx_1 > 1) {
                d->data[input_sizes_idx_1 - 1] = apnd;
                nx = (input_sizes_idx_1 - 1) / 2;
                for (idx = 0; idx <= nx - 2; idx++) {
                  d->data[1 + idx] = constant + (1.0 + static_cast<double>(idx));
                  d->data[(input_sizes_idx_1 - idx) - 2] = apnd - (1.0 +
                    static_cast<double>(idx));
                }

                if (nx << 1 == input_sizes_idx_1 - 1) {
                  d->data[nx] = (constant + apnd) / 2.0;
                } else {
                  d->data[nx] = constant + static_cast<double>(nx);
                  d->data[nx + 1] = apnd - static_cast<double>(nx);
                }
              }
            }
          }

          input_sizes_idx_1 = d->size[1];
          for (nx = 0; nx < input_sizes_idx_1; nx++) {
            imin->data[(i70 + nx) - 1] = d->data[nx];
          }

          /* if local maximum */
        } else {
          if ((direction == -1.0) && (direction0->data[0] == 1.0)) {
            /* update max/imax */
            maxct = (maxct + 1.0) + constant;
            ndbl = maxct - constant;
            if (ndbl > maxct) {
              i70 = 1;
            } else {
              i70 = static_cast<int>(ndbl);
            }

            constant = (static_cast<double>(b_k) - 1.0) - constant;
            if (static_cast<double>(b_k) - 1.0 < constant) {
              d->size[0] = 1;
              d->size[1] = 0;
            } else if (rtIsInf(constant) && (constant == static_cast<double>(b_k)
                        - 1.0)) {
              nx = d->size[0] * d->size[1];
              d->size[0] = 1;
              d->size[1] = 1;
              emxEnsureCapacity_real_T(d, nx);
              d->data[0] = rtNaN;
            } else if (constant == constant) {
              nx = d->size[0] * d->size[1];
              d->size[0] = 1;
              input_sizes_idx_1 = static_cast<int>(((static_cast<double>(b_k) -
                1.0) - constant));
              d->size[1] = input_sizes_idx_1 + 1;
              emxEnsureCapacity_real_T(d, nx);
              for (nx = 0; nx <= input_sizes_idx_1; nx++) {
                d->data[nx] = constant + static_cast<double>(nx);
              }
            } else {
              ndbl = std::floor(((static_cast<double>(b_k) - 1.0) - constant) +
                                0.5);
              apnd = constant + ndbl;
              cdiff = apnd - (static_cast<double>(b_k) - 1.0);
              b_u0 = std::abs(constant);
              u1 = static_cast<int>(b_k) - 1;
              if (b_u0 > u1) {
                u1 = b_u0;
              }

              if (std::abs(cdiff) < 4.4408920985006262E-16 * u1) {
                ndbl++;
                apnd = static_cast<double>(b_k) - 1.0;
              } else if (cdiff > 0.0) {
                apnd = constant + (ndbl - 1.0);
              } else {
                ndbl++;
              }

              if (ndbl >= 0.0) {
                input_sizes_idx_1 = static_cast<int>(ndbl);
              } else {
                input_sizes_idx_1 = 0;
              }

              nx = d->size[0] * d->size[1];
              d->size[0] = 1;
              d->size[1] = input_sizes_idx_1;
              emxEnsureCapacity_real_T(d, nx);
              if (input_sizes_idx_1 > 0) {
                d->data[0] = constant;
                if (input_sizes_idx_1 > 1) {
                  d->data[input_sizes_idx_1 - 1] = apnd;
                  nx = (input_sizes_idx_1 - 1) / 2;
                  for (idx = 0; idx <= nx - 2; idx++) {
                    d->data[1 + idx] = constant + (1.0 + static_cast<double>(idx));
                    d->data[(input_sizes_idx_1 - idx) - 2] = apnd - (1.0 +
                      static_cast<double>(idx));
                  }

                  if (nx << 1 == input_sizes_idx_1 - 1) {
                    d->data[nx] = (constant + apnd) / 2.0;
                  } else {
                    d->data[nx] = constant + static_cast<double>(nx);
                    d->data[nx + 1] = apnd - static_cast<double>(nx);
                  }
                }
              }
            }

            input_sizes_idx_1 = d->size[1];
            for (nx = 0; nx < input_sizes_idx_1; nx++) {
              imax->data[(i70 + nx) - 1] = d->data[nx];
            }
          }
        }

        /* current trajectory is next iteration previous */
        i70 = direction0->size[0] * direction0->size[1];
        direction0->size[0] = 1;
        direction0->size[1] = 1;
        emxEnsureCapacity_real_T(direction0, i70);
        direction0->data[0] = direction;

        /* no consecutive constant */
        constant = 0.0;
      }
    }

    emxFree_real_T(&direction0);

    /* finish */
    if ((imaxFirst->size[0] != 0) && (imaxFirst->size[1] != 0)) {
      input_sizes_idx_1 = imaxFirst->size[1];
    } else {
      input_sizes_idx_1 = 0;
    }

    emxInitMatrix_cell_wrap_261(reshapes);
    i69 = reshapes[0].f1->size[0] * reshapes[0].f1->size[1];
    reshapes[0].f1->size[0] = 1;
    reshapes[0].f1->size[1] = input_sizes_idx_1;
    emxEnsureCapacity_real_T(reshapes[0].f1, i69);
    for (i69 = 0; i69 < input_sizes_idx_1; i69++) {
      reshapes[0].f1->data[i69] = imaxFirst->data[i69];
    }

    emxFree_real_T(&imaxFirst);
    if (imax->size[1] != 0) {
      input_sizes_idx_1 = imax->size[1];
    } else {
      input_sizes_idx_1 = 0;
    }

    i69 = reshapes[1].f1->size[0] * reshapes[1].f1->size[1];
    reshapes[1].f1->size[0] = 1;
    reshapes[1].f1->size[1] = input_sizes_idx_1;
    emxEnsureCapacity_real_T(reshapes[1].f1, i69);
    for (i69 = 0; i69 < input_sizes_idx_1; i69++) {
      reshapes[1].f1->data[i69] = imax->data[i69];
    }

    if ((imaxLast->size[0] != 0) && (imaxLast->size[1] != 0)) {
      nx = imaxLast->size[1];
    } else {
      nx = 0;
    }

    i69 = imax->size[0] * imax->size[1];
    imax->size[0] = reshapes[0].f1->size[0];
    imax->size[1] = (reshapes[0].f1->size[1] + reshapes[1].f1->size[1]) + nx;
    emxEnsureCapacity_real_T(imax, i69);
    input_sizes_idx_1 = reshapes[0].f1->size[1];
    for (i69 = 0; i69 < input_sizes_idx_1; i69++) {
      idx = reshapes[0].f1->size[0];
      for (i70 = 0; i70 < idx; i70++) {
        imax->data[i70 + imax->size[0] * i69] = reshapes[0].f1->data[i70 +
          reshapes[0].f1->size[0] * i69];
      }
    }

    input_sizes_idx_1 = reshapes[1].f1->size[1];
    for (i69 = 0; i69 < input_sizes_idx_1; i69++) {
      idx = reshapes[1].f1->size[0];
      for (i70 = 0; i70 < idx; i70++) {
        imax->data[i70 + imax->size[0] * (i69 + reshapes[0].f1->size[1])] =
          reshapes[1].f1->data[i70 + reshapes[1].f1->size[0] * i69];
      }
    }

    for (i69 = 0; i69 < nx; i69++) {
      for (i70 = 0; i70 < 1; i70++) {
        imax->data[imax->size[0] * ((i69 + reshapes[0].f1->size[1]) + reshapes[1]
          .f1->size[1])] = imaxLast->data[imaxLast->size[0] * i69];
      }
    }

    emxFreeMatrix_cell_wrap_261(reshapes);
    emxInit_boolean_T(&b_d, 2);
    i69 = b_d->size[0] * b_d->size[1];
    b_d->size[0] = imax->size[0];
    b_d->size[1] = imax->size[1];
    emxEnsureCapacity_boolean_T(b_d, i69);
    input_sizes_idx_1 = imax->size[0] * imax->size[1];
    for (i69 = 0; i69 < input_sizes_idx_1; i69++) {
      b_d->data[i69] = (imax->data[i69] == 0.0);
    }

    c_nullAssignment(imax, b_d);
    i69 = b_max->size[0] * b_max->size[1];
    b_max->size[0] = imax->size[0];
    b_max->size[1] = imax->size[1];
    emxEnsureCapacity_real_T(b_max, i69);
    input_sizes_idx_1 = imax->size[0] * imax->size[1];
    for (i69 = 0; i69 < input_sizes_idx_1; i69++) {
      b_max->data[i69] = x->data[static_cast<int>(imax->data[i69]) - 1];
    }

    if (iminFirst->size[1] != 0) {
      input_sizes_idx_1 = iminFirst->size[1];
    } else {
      input_sizes_idx_1 = 0;
    }

    if (imin->size[1] != 0) {
      nx = imin->size[1];
    } else {
      nx = 0;
    }

    if (iminLast->size[1] != 0) {
      idx = iminLast->size[1];
    } else {
      idx = 0;
    }

    i69 = d->size[0] * d->size[1];
    d->size[0] = 1;
    d->size[1] = (input_sizes_idx_1 + nx) + idx;
    emxEnsureCapacity_real_T(d, i69);
    for (i69 = 0; i69 < input_sizes_idx_1; i69++) {
      for (i70 = 0; i70 < 1; i70++) {
        d->data[i69] = iminFirst->data[i69];
      }
    }

    emxFree_real_T(&iminFirst);
    for (i69 = 0; i69 < nx; i69++) {
      for (i70 = 0; i70 < 1; i70++) {
        d->data[i69 + input_sizes_idx_1] = imin->data[i69];
      }
    }

    emxFree_real_T(&imin);
    for (i69 = 0; i69 < idx; i69++) {
      for (i70 = 0; i70 < 1; i70++) {
        d->data[(i69 + input_sizes_idx_1) + nx] = iminLast->data[i69];
      }
    }

    emxFree_real_T(&iminLast);
    i69 = imaxLast->size[0] * imaxLast->size[1];
    imaxLast->size[0] = 1;
    imaxLast->size[1] = d->size[1];
    emxEnsureCapacity_real_T(imaxLast, i69);
    input_sizes_idx_1 = d->size[0] * d->size[1];
    for (i69 = 0; i69 < input_sizes_idx_1; i69++) {
      imaxLast->data[i69] = d->data[i69];
    }

    i69 = b_d->size[0] * b_d->size[1];
    b_d->size[0] = 1;
    b_d->size[1] = d->size[1];
    emxEnsureCapacity_boolean_T(b_d, i69);
    input_sizes_idx_1 = d->size[0] * d->size[1];
    for (i69 = 0; i69 < input_sizes_idx_1; i69++) {
      b_d->data[i69] = (d->data[i69] == 0.0);
    }

    c_nullAssignment(imaxLast, b_d);
    emxFree_boolean_T(&b_d);
    emxFree_real_T(&imaxLast);
  }

  emxFree_real_T(&d);
}

void c_extrema(const emxArray_real_T *x, emxArray_real_T *b_max, emxArray_real_T
               *imax)
{
  emxArray_real_T *d;
  int i74;
  int ndbl;
  emxArray_real_T *imin;
  emxArray_boolean_T *b_x;
  double constant;
  emxArray_int32_T *ii;
  int nx;
  int idx;
  boolean_T exitg1;
  emxArray_real_T *first;
  emxArray_real_T *b_d;
  emxArray_int32_T *r29;
  emxArray_real_T *last;
  emxArray_real_T *iminFirst;
  emxArray_real_T *imaxFirst;
  emxArray_real_T *y;
  emxArray_real_T *iminLast;
  emxArray_real_T *imaxLast;
  int apnd;
  int absb;
  emxArray_real_T *direction0;
  double maxct;
  double minct;
  double direction;
  cell_wrap_26 reshapes[3];
  double b_ndbl;
  double b_apnd;
  double cdiff;
  double u0;
  double u1;
  emxArray_boolean_T *b_y;
  emxInit_real_T(&d, 1);

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
  /* UPDATED */
  /* initialize */
  b_max->size[0] = 0;
  b_max->size[1] = 0;
  imax->size[0] = 0;
  imax->size[1] = 0;

  /* get differences */
  c_diff(x, d);

  /* get extrema if any nonzero changes */
  if (d_any(d)) {
    /* allocation */
    i74 = imax->size[0] * imax->size[1];
    imax->size[0] = 1;
    imax->size[1] = d->size[0];
    emxEnsureCapacity_real_T(imax, i74);
    ndbl = d->size[0];
    for (i74 = 0; i74 < ndbl; i74++) {
      imax->data[i74] = 0.0;
    }

    emxInit_real_T(&imin, 2);
    i74 = imin->size[0] * imin->size[1];
    imin->size[0] = 1;
    imin->size[1] = d->size[0];
    emxEnsureCapacity_real_T(imin, i74);
    ndbl = d->size[0];
    for (i74 = 0; i74 < ndbl; i74++) {
      imin->data[i74] = 0.0;
    }

    emxInit_boolean_T(&b_x, 1);

    /* endpoints are always local extrema */
    constant = x->data[0];
    i74 = b_x->size[0];
    b_x->size[0] = x->size[0];
    emxEnsureCapacity_boolean_T(b_x, i74);
    ndbl = x->size[0];
    for (i74 = 0; i74 < ndbl; i74++) {
      b_x->data[i74] = (x->data[i74] != constant);
    }

    emxInit_int32_T(&ii, 1);
    nx = b_x->size[0];
    idx = 0;
    i74 = ii->size[0];
    ii->size[0] = b_x->size[0];
    emxEnsureCapacity_int32_T(ii, i74);
    ndbl = 0;
    exitg1 = false;
    while ((!exitg1) && (ndbl <= nx - 1)) {
      if (b_x->data[ndbl]) {
        idx++;
        ii->data[idx - 1] = ndbl + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          ndbl++;
        }
      } else {
        ndbl++;
      }
    }

    if (b_x->size[0] == 1) {
      if (idx == 0) {
        ii->size[0] = 0;
      }
    } else if (1 > idx) {
      ii->size[0] = 0;
    } else {
      i74 = ii->size[0];
      ii->size[0] = idx;
      emxEnsureCapacity_int32_T(ii, i74);
    }

    emxInit_real_T(&first, 1);
    i74 = first->size[0];
    first->size[0] = ii->size[0];
    emxEnsureCapacity_real_T(first, i74);
    ndbl = ii->size[0];
    for (i74 = 0; i74 < ndbl; i74++) {
      first->data[i74] = ii->data[i74];
    }

    emxInit_real_T(&b_d, 1);
    i74 = b_d->size[0];
    b_d->size[0] = first->size[0];
    emxEnsureCapacity_real_T(b_d, i74);
    ndbl = first->size[0];
    for (i74 = 0; i74 < ndbl; i74++) {
      b_d->data[i74] = first->data[i74];
    }

    emxInit_int32_T(&r29, 2);
    ndbl = first->size[0] - 2;
    i74 = r29->size[0] * r29->size[1];
    r29->size[0] = 1;
    r29->size[1] = ndbl + 1;
    emxEnsureCapacity_int32_T(r29, i74);
    for (i74 = 0; i74 <= ndbl; i74++) {
      r29->data[i74] = 2 + i74;
    }

    b_nullAssignment(b_d, r29);
    i74 = first->size[0];
    first->size[0] = b_d->size[0];
    emxEnsureCapacity_real_T(first, i74);
    ndbl = b_d->size[0];
    for (i74 = 0; i74 < ndbl; i74++) {
      first->data[i74] = b_d->data[i74];
    }

    constant = x->data[x->size[0] - 1];
    i74 = b_x->size[0];
    b_x->size[0] = x->size[0];
    emxEnsureCapacity_boolean_T(b_x, i74);
    ndbl = x->size[0];
    for (i74 = 0; i74 < ndbl; i74++) {
      b_x->data[i74] = (x->data[i74] != constant);
    }

    nx = b_x->size[0];
    idx = 0;
    i74 = ii->size[0];
    ii->size[0] = b_x->size[0];
    emxEnsureCapacity_int32_T(ii, i74);
    ndbl = 0;
    exitg1 = false;
    while ((!exitg1) && (ndbl <= nx - 1)) {
      if (b_x->data[ndbl]) {
        idx++;
        ii->data[idx - 1] = ndbl + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          ndbl++;
        }
      } else {
        ndbl++;
      }
    }

    if (b_x->size[0] == 1) {
      if (idx == 0) {
        ii->size[0] = 0;
      }
    } else if (1 > idx) {
      ii->size[0] = 0;
    } else {
      i74 = ii->size[0];
      ii->size[0] = idx;
      emxEnsureCapacity_int32_T(ii, i74);
    }

    emxInit_real_T(&last, 1);
    i74 = last->size[0];
    last->size[0] = ii->size[0];
    emxEnsureCapacity_real_T(last, i74);
    ndbl = ii->size[0];
    for (i74 = 0; i74 < ndbl; i74++) {
      last->data[i74] = ii->data[i74];
    }

    emxFree_int32_T(&ii);
    i74 = b_d->size[0];
    b_d->size[0] = last->size[0];
    emxEnsureCapacity_real_T(b_d, i74);
    ndbl = last->size[0];
    for (i74 = 0; i74 < ndbl; i74++) {
      b_d->data[i74] = last->data[i74];
    }

    ndbl = last->size[0] - 2;
    i74 = r29->size[0] * r29->size[1];
    r29->size[0] = 1;
    r29->size[1] = ndbl + 1;
    emxEnsureCapacity_int32_T(r29, i74);
    for (i74 = 0; i74 <= ndbl; i74++) {
      r29->data[i74] = 1 + i74;
    }

    b_nullAssignment(b_d, r29);
    i74 = last->size[0];
    last->size[0] = b_d->size[0];
    emxEnsureCapacity_real_T(last, i74);
    ndbl = b_d->size[0];
    emxFree_int32_T(&r29);
    for (i74 = 0; i74 < ndbl; i74++) {
      last->data[i74] = b_d->data[i74];
    }

    constant = x->data[0];
    i74 = b_x->size[0];
    b_x->size[0] = first->size[0];
    emxEnsureCapacity_boolean_T(b_x, i74);
    ndbl = first->size[0];
    for (i74 = 0; i74 < ndbl; i74++) {
      b_x->data[i74] = (constant < x->data[static_cast<int>(first->data[i74]) -
                        1]);
    }

    emxInit_real_T(&iminFirst, 2);
    emxInit_real_T(&imaxFirst, 2);
    emxInit_real_T(&y, 2);
    if (b_ifWhileCond(b_x)) {
      i74 = b_d->size[0];
      b_d->size[0] = first->size[0];
      emxEnsureCapacity_real_T(b_d, i74);
      ndbl = first->size[0];
      for (i74 = 0; i74 < ndbl; i74++) {
        b_d->data[i74] = first->data[i74] - 1.0;
      }

      if (b_d->data[0] < 1.0) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else {
        i74 = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = static_cast<int>(std::floor(b_d->data[0] - 1.0)) + 1;
        emxEnsureCapacity_real_T(y, i74);
        ndbl = static_cast<int>(std::floor(b_d->data[0] - 1.0));
        for (i74 = 0; i74 <= ndbl; i74++) {
          y->data[i74] = 1.0 + static_cast<double>(i74);
        }
      }

      i74 = iminFirst->size[0] * iminFirst->size[1];
      iminFirst->size[0] = 1;
      iminFirst->size[1] = y->size[1];
      emxEnsureCapacity_real_T(iminFirst, i74);
      ndbl = y->size[0] * y->size[1];
      for (i74 = 0; i74 < ndbl; i74++) {
        iminFirst->data[i74] = y->data[i74];
      }

      imaxFirst->size[0] = 0;
      imaxFirst->size[1] = 0;
    } else {
      iminFirst->size[0] = 1;
      iminFirst->size[1] = 0;
      i74 = b_d->size[0];
      b_d->size[0] = first->size[0];
      emxEnsureCapacity_real_T(b_d, i74);
      ndbl = first->size[0];
      for (i74 = 0; i74 < ndbl; i74++) {
        b_d->data[i74] = first->data[i74] - 1.0;
      }

      if (b_d->data[0] < 1.0) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else {
        i74 = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = static_cast<int>(std::floor(b_d->data[0] - 1.0)) + 1;
        emxEnsureCapacity_real_T(y, i74);
        ndbl = static_cast<int>(std::floor(b_d->data[0] - 1.0));
        for (i74 = 0; i74 <= ndbl; i74++) {
          y->data[i74] = 1.0 + static_cast<double>(i74);
        }
      }

      i74 = imaxFirst->size[0] * imaxFirst->size[1];
      imaxFirst->size[0] = 1;
      imaxFirst->size[1] = y->size[1];
      emxEnsureCapacity_real_T(imaxFirst, i74);
      ndbl = y->size[0] * y->size[1];
      for (i74 = 0; i74 < ndbl; i74++) {
        imaxFirst->data[i74] = y->data[i74];
      }
    }

    constant = x->data[x->size[0] - 1];
    i74 = b_x->size[0];
    b_x->size[0] = last->size[0];
    emxEnsureCapacity_boolean_T(b_x, i74);
    ndbl = last->size[0];
    for (i74 = 0; i74 < ndbl; i74++) {
      b_x->data[i74] = (constant < x->data[static_cast<int>(last->data[i74]) - 1]);
    }

    emxInit_real_T(&iminLast, 2);
    emxInit_real_T(&imaxLast, 2);
    if (b_ifWhileCond(b_x)) {
      i74 = b_d->size[0];
      b_d->size[0] = last->size[0];
      emxEnsureCapacity_real_T(b_d, i74);
      ndbl = last->size[0];
      for (i74 = 0; i74 < ndbl; i74++) {
        b_d->data[i74] = last->data[i74] + 1.0;
      }

      if (x->size[0] < static_cast<int>(b_d->data[0])) {
        iminLast->size[0] = 1;
        iminLast->size[1] = 0;
      } else if (b_d->data[0] == b_d->data[0]) {
        i74 = x->size[0];
        apnd = iminLast->size[0] * iminLast->size[1];
        iminLast->size[0] = 1;
        iminLast->size[1] = static_cast<int>(std::floor(static_cast<double>(i74)
          - b_d->data[0])) + 1;
        emxEnsureCapacity_real_T(iminLast, apnd);
        ndbl = static_cast<int>(std::floor(static_cast<double>(i74) - b_d->data
          [0]));
        for (i74 = 0; i74 <= ndbl; i74++) {
          iminLast->data[i74] = b_d->data[0] + static_cast<double>(i74);
        }
      } else {
        ndbl = static_cast<int>(std::floor((static_cast<double>(x->size[0]) -
          b_d->data[0]) + 0.5));
        apnd = static_cast<int>(b_d->data[0]) + ndbl;
        nx = apnd - x->size[0];
        idx = static_cast<int>(b_d->data[0]);
        absb = x->size[0];
        if (idx > absb) {
          absb = idx;
        }

        if (std::abs((double)nx) < 4.4408920985006262E-16 * static_cast<double>
            (absb)) {
          ndbl++;
          apnd = x->size[0];
        } else if (nx > 0) {
          apnd = (static_cast<int>(b_d->data[0]) + ndbl) - 1;
        } else {
          ndbl++;
        }

        if (ndbl >= 0) {
        } else {
          ndbl = 0;
        }

        i74 = iminLast->size[0] * iminLast->size[1];
        iminLast->size[0] = 1;
        iminLast->size[1] = ndbl;
        emxEnsureCapacity_real_T(iminLast, i74);
        if (ndbl > 0) {
          iminLast->data[0] = b_d->data[0];
          if (ndbl > 1) {
            iminLast->data[ndbl - 1] = apnd;
            nx = (ndbl - 1) / 2;
            for (absb = 0; absb <= nx - 2; absb++) {
              iminLast->data[1 + absb] = b_d->data[0] + (1.0 + static_cast<
                double>(absb));
              iminLast->data[(ndbl - absb) - 2] = (apnd - absb) - 1;
            }

            if (nx << 1 == ndbl - 1) {
              iminLast->data[nx] = (b_d->data[0] + static_cast<double>(apnd)) /
                2.0;
            } else {
              iminLast->data[nx] = b_d->data[0] + static_cast<double>(nx);
              iminLast->data[nx + 1] = apnd - nx;
            }
          }
        }
      }

      imaxLast->size[0] = 0;
      imaxLast->size[1] = 0;
    } else {
      i74 = b_d->size[0];
      b_d->size[0] = last->size[0];
      emxEnsureCapacity_real_T(b_d, i74);
      ndbl = last->size[0];
      for (i74 = 0; i74 < ndbl; i74++) {
        b_d->data[i74] = last->data[i74] + 1.0;
      }

      if (x->size[0] < static_cast<int>(b_d->data[0])) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else if (b_d->data[0] == b_d->data[0]) {
        i74 = x->size[0];
        apnd = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = static_cast<int>(std::floor(static_cast<double>(i74) -
          b_d->data[0])) + 1;
        emxEnsureCapacity_real_T(y, apnd);
        ndbl = static_cast<int>(std::floor(static_cast<double>(i74) - b_d->data
          [0]));
        for (i74 = 0; i74 <= ndbl; i74++) {
          y->data[i74] = b_d->data[0] + static_cast<double>(i74);
        }
      } else {
        ndbl = static_cast<int>(std::floor((static_cast<double>(x->size[0]) -
          b_d->data[0]) + 0.5));
        apnd = static_cast<int>(b_d->data[0]) + ndbl;
        nx = apnd - x->size[0];
        idx = static_cast<int>(b_d->data[0]);
        absb = x->size[0];
        if (idx > absb) {
          absb = idx;
        }

        if (std::abs((double)nx) < 4.4408920985006262E-16 * static_cast<double>
            (absb)) {
          ndbl++;
          apnd = x->size[0];
        } else if (nx > 0) {
          apnd = (static_cast<int>(b_d->data[0]) + ndbl) - 1;
        } else {
          ndbl++;
        }

        if (ndbl >= 0) {
        } else {
          ndbl = 0;
        }

        i74 = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = ndbl;
        emxEnsureCapacity_real_T(y, i74);
        if (ndbl > 0) {
          y->data[0] = b_d->data[0];
          if (ndbl > 1) {
            y->data[ndbl - 1] = apnd;
            nx = (ndbl - 1) / 2;
            for (absb = 0; absb <= nx - 2; absb++) {
              y->data[1 + absb] = b_d->data[0] + (1.0 + static_cast<double>(absb));
              y->data[(ndbl - absb) - 2] = (apnd - absb) - 1;
            }

            if (nx << 1 == ndbl - 1) {
              y->data[nx] = (b_d->data[0] + static_cast<double>(apnd)) / 2.0;
            } else {
              y->data[nx] = b_d->data[0] + static_cast<double>(nx);
              y->data[nx + 1] = apnd - nx;
            }
          }
        }
      }

      i74 = imaxLast->size[0] * imaxLast->size[1];
      imaxLast->size[0] = 1;
      imaxLast->size[1] = y->size[1];
      emxEnsureCapacity_real_T(imaxLast, i74);
      ndbl = y->size[0] * y->size[1];
      for (i74 = 0; i74 < ndbl; i74++) {
        imaxLast->data[i74] = y->data[i74];
      }

      iminLast->size[0] = 1;
      iminLast->size[1] = 0;
    }

    emxFree_boolean_T(&b_x);
    emxInit_real_T(&direction0, 1);

    /* for each element */
    maxct = 0.0;
    minct = 0.0;
    i74 = direction0->size[0];
    direction0->size[0] = first->size[0];
    emxEnsureCapacity_real_T(direction0, i74);
    ndbl = first->size[0];
    for (i74 = 0; i74 < ndbl; i74++) {
      direction0->data[i74] = x->data[static_cast<int>(first->data[i74]) - 2];
    }

    i74 = b_d->size[0];
    b_d->size[0] = first->size[0];
    emxEnsureCapacity_real_T(b_d, i74);
    ndbl = first->size[0];
    for (i74 = 0; i74 < ndbl; i74++) {
      b_d->data[i74] = x->data[static_cast<int>(first->data[i74]) - 1] -
        direction0->data[i74];
    }

    f_sign(b_d);
    i74 = direction0->size[0];
    direction0->size[0] = b_d->size[0];
    emxEnsureCapacity_real_T(direction0, i74);
    ndbl = b_d->size[0];
    for (i74 = 0; i74 < ndbl; i74++) {
      direction0->data[i74] = b_d->data[i74];
    }

    emxFree_real_T(&b_d);
    constant = 0.0;
    i74 = static_cast<int>(((last->data[0] + 1.0) + (1.0 - (first->data[0] + 1.0))));
    emxFree_real_T(&last);
    for (absb = 0; absb < i74; absb++) {
      idx = (static_cast<int>(first->data[0]) + absb) + 1;

      /* current trajectory */
      direction = x->data[idx - 1] - x->data[idx - 2];
      e_sign(&direction);

      /* if no change */
      if (direction == 0.0) {
        constant++;

        /* otherwise */
      } else {
        /* if local minimum */
        if ((direction == 1.0) && (direction0->data[0] == -1.0)) {
          /* update min/imin */
          minct = (minct + 1.0) + constant;
          b_ndbl = minct - constant;
          if (b_ndbl > minct) {
            apnd = 1;
          } else {
            apnd = static_cast<int>(b_ndbl);
          }

          constant = (static_cast<double>(idx) - 1.0) - constant;
          if (static_cast<double>(idx) - 1.0 < constant) {
            y->size[0] = 1;
            y->size[1] = 0;
          } else if (rtIsInf(constant) && (constant == static_cast<double>(idx)
                      - 1.0)) {
            nx = y->size[0] * y->size[1];
            y->size[0] = 1;
            y->size[1] = 1;
            emxEnsureCapacity_real_T(y, nx);
            y->data[0] = rtNaN;
          } else if (constant == constant) {
            nx = y->size[0] * y->size[1];
            y->size[0] = 1;
            ndbl = static_cast<int>(((static_cast<double>(idx) - 1.0) - constant));
            y->size[1] = ndbl + 1;
            emxEnsureCapacity_real_T(y, nx);
            for (nx = 0; nx <= ndbl; nx++) {
              y->data[nx] = constant + static_cast<double>(nx);
            }
          } else {
            b_ndbl = std::floor(((static_cast<double>(idx) - 1.0) - constant) +
                                0.5);
            b_apnd = constant + b_ndbl;
            cdiff = b_apnd - (static_cast<double>(idx) - 1.0);
            u0 = std::abs(constant);
            u1 = idx - 1;
            if (u0 > u1) {
              u1 = u0;
            }

            if (std::abs(cdiff) < 4.4408920985006262E-16 * u1) {
              b_ndbl++;
              b_apnd = static_cast<double>(idx) - 1.0;
            } else if (cdiff > 0.0) {
              b_apnd = constant + (b_ndbl - 1.0);
            } else {
              b_ndbl++;
            }

            if (b_ndbl >= 0.0) {
              ndbl = static_cast<int>(b_ndbl);
            } else {
              ndbl = 0;
            }

            nx = y->size[0] * y->size[1];
            y->size[0] = 1;
            y->size[1] = ndbl;
            emxEnsureCapacity_real_T(y, nx);
            if (ndbl > 0) {
              y->data[0] = constant;
              if (ndbl > 1) {
                y->data[ndbl - 1] = b_apnd;
                nx = (ndbl - 1) / 2;
                for (idx = 0; idx <= nx - 2; idx++) {
                  y->data[1 + idx] = constant + (1.0 + static_cast<double>(idx));
                  y->data[(ndbl - idx) - 2] = b_apnd - (1.0 + static_cast<double>
                    (idx));
                }

                if (nx << 1 == ndbl - 1) {
                  y->data[nx] = (constant + b_apnd) / 2.0;
                } else {
                  y->data[nx] = constant + static_cast<double>(nx);
                  y->data[nx + 1] = b_apnd - static_cast<double>(nx);
                }
              }
            }
          }

          ndbl = y->size[1];
          for (nx = 0; nx < ndbl; nx++) {
            imin->data[(apnd + nx) - 1] = y->data[nx];
          }

          /* if local maximum */
        } else {
          if ((direction == -1.0) && (direction0->data[0] == 1.0)) {
            /* update max/imax */
            maxct = (maxct + 1.0) + constant;
            b_ndbl = maxct - constant;
            if (b_ndbl > maxct) {
              apnd = 1;
            } else {
              apnd = static_cast<int>(b_ndbl);
            }

            constant = (static_cast<double>(idx) - 1.0) - constant;
            if (static_cast<double>(idx) - 1.0 < constant) {
              y->size[0] = 1;
              y->size[1] = 0;
            } else if (rtIsInf(constant) && (constant == static_cast<double>(idx)
                        - 1.0)) {
              nx = y->size[0] * y->size[1];
              y->size[0] = 1;
              y->size[1] = 1;
              emxEnsureCapacity_real_T(y, nx);
              y->data[0] = rtNaN;
            } else if (constant == constant) {
              nx = y->size[0] * y->size[1];
              y->size[0] = 1;
              ndbl = static_cast<int>(((static_cast<double>(idx) - 1.0) -
                constant));
              y->size[1] = ndbl + 1;
              emxEnsureCapacity_real_T(y, nx);
              for (nx = 0; nx <= ndbl; nx++) {
                y->data[nx] = constant + static_cast<double>(nx);
              }
            } else {
              b_ndbl = std::floor(((static_cast<double>(idx) - 1.0) - constant)
                                  + 0.5);
              b_apnd = constant + b_ndbl;
              cdiff = b_apnd - (static_cast<double>(idx) - 1.0);
              u0 = std::abs(constant);
              u1 = idx - 1;
              if (u0 > u1) {
                u1 = u0;
              }

              if (std::abs(cdiff) < 4.4408920985006262E-16 * u1) {
                b_ndbl++;
                b_apnd = static_cast<double>(idx) - 1.0;
              } else if (cdiff > 0.0) {
                b_apnd = constant + (b_ndbl - 1.0);
              } else {
                b_ndbl++;
              }

              if (b_ndbl >= 0.0) {
                ndbl = static_cast<int>(b_ndbl);
              } else {
                ndbl = 0;
              }

              nx = y->size[0] * y->size[1];
              y->size[0] = 1;
              y->size[1] = ndbl;
              emxEnsureCapacity_real_T(y, nx);
              if (ndbl > 0) {
                y->data[0] = constant;
                if (ndbl > 1) {
                  y->data[ndbl - 1] = b_apnd;
                  nx = (ndbl - 1) / 2;
                  for (idx = 0; idx <= nx - 2; idx++) {
                    y->data[1 + idx] = constant + (1.0 + static_cast<double>(idx));
                    y->data[(ndbl - idx) - 2] = b_apnd - (1.0 + static_cast<
                      double>(idx));
                  }

                  if (nx << 1 == ndbl - 1) {
                    y->data[nx] = (constant + b_apnd) / 2.0;
                  } else {
                    y->data[nx] = constant + static_cast<double>(nx);
                    y->data[nx + 1] = b_apnd - static_cast<double>(nx);
                  }
                }
              }
            }

            ndbl = y->size[1];
            for (nx = 0; nx < ndbl; nx++) {
              imax->data[(apnd + nx) - 1] = y->data[nx];
            }
          }
        }

        /* current trajectory is next iteration previous */
        apnd = direction0->size[0];
        direction0->size[0] = 1;
        emxEnsureCapacity_real_T(direction0, apnd);
        direction0->data[0] = direction;

        /* no consecutive constant */
        constant = 0.0;
      }
    }

    emxFree_real_T(&direction0);
    emxFree_real_T(&first);

    /* finish */
    if ((imaxFirst->size[0] != 0) && (imaxFirst->size[1] != 0)) {
      nx = imaxFirst->size[1];
    } else {
      nx = 0;
    }

    emxInitMatrix_cell_wrap_261(reshapes);
    i74 = reshapes[0].f1->size[0] * reshapes[0].f1->size[1];
    reshapes[0].f1->size[0] = 1;
    reshapes[0].f1->size[1] = nx;
    emxEnsureCapacity_real_T(reshapes[0].f1, i74);
    for (i74 = 0; i74 < nx; i74++) {
      reshapes[0].f1->data[i74] = imaxFirst->data[i74];
    }

    emxFree_real_T(&imaxFirst);
    if (imax->size[1] != 0) {
      nx = imax->size[1];
    } else {
      nx = 0;
    }

    i74 = reshapes[1].f1->size[0] * reshapes[1].f1->size[1];
    reshapes[1].f1->size[0] = 1;
    reshapes[1].f1->size[1] = nx;
    emxEnsureCapacity_real_T(reshapes[1].f1, i74);
    for (i74 = 0; i74 < nx; i74++) {
      reshapes[1].f1->data[i74] = imax->data[i74];
    }

    if ((imaxLast->size[0] != 0) && (imaxLast->size[1] != 0)) {
      nx = imaxLast->size[1];
    } else {
      nx = 0;
    }

    i74 = imax->size[0] * imax->size[1];
    imax->size[0] = reshapes[0].f1->size[0];
    imax->size[1] = (reshapes[0].f1->size[1] + reshapes[1].f1->size[1]) + nx;
    emxEnsureCapacity_real_T(imax, i74);
    ndbl = reshapes[0].f1->size[1];
    for (i74 = 0; i74 < ndbl; i74++) {
      idx = reshapes[0].f1->size[0];
      for (apnd = 0; apnd < idx; apnd++) {
        imax->data[apnd + imax->size[0] * i74] = reshapes[0].f1->data[apnd +
          reshapes[0].f1->size[0] * i74];
      }
    }

    ndbl = reshapes[1].f1->size[1];
    for (i74 = 0; i74 < ndbl; i74++) {
      idx = reshapes[1].f1->size[0];
      for (apnd = 0; apnd < idx; apnd++) {
        imax->data[apnd + imax->size[0] * (i74 + reshapes[0].f1->size[1])] =
          reshapes[1].f1->data[apnd + reshapes[1].f1->size[0] * i74];
      }
    }

    for (i74 = 0; i74 < nx; i74++) {
      for (apnd = 0; apnd < 1; apnd++) {
        imax->data[imax->size[0] * ((i74 + reshapes[0].f1->size[1]) + reshapes[1]
          .f1->size[1])] = imaxLast->data[imaxLast->size[0] * i74];
      }
    }

    emxFreeMatrix_cell_wrap_261(reshapes);
    emxInit_boolean_T(&b_y, 2);
    i74 = b_y->size[0] * b_y->size[1];
    b_y->size[0] = imax->size[0];
    b_y->size[1] = imax->size[1];
    emxEnsureCapacity_boolean_T(b_y, i74);
    ndbl = imax->size[0] * imax->size[1];
    for (i74 = 0; i74 < ndbl; i74++) {
      b_y->data[i74] = (imax->data[i74] == 0.0);
    }

    c_nullAssignment(imax, b_y);
    i74 = b_max->size[0] * b_max->size[1];
    b_max->size[0] = imax->size[0];
    b_max->size[1] = imax->size[1];
    emxEnsureCapacity_real_T(b_max, i74);
    ndbl = imax->size[0] * imax->size[1];
    for (i74 = 0; i74 < ndbl; i74++) {
      b_max->data[i74] = x->data[static_cast<int>(imax->data[i74]) - 1];
    }

    if (iminFirst->size[1] != 0) {
      nx = iminFirst->size[1];
    } else {
      nx = 0;
    }

    if (imin->size[1] != 0) {
      idx = imin->size[1];
    } else {
      idx = 0;
    }

    if (iminLast->size[1] != 0) {
      ndbl = iminLast->size[1];
    } else {
      ndbl = 0;
    }

    i74 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (nx + idx) + ndbl;
    emxEnsureCapacity_real_T(y, i74);
    for (i74 = 0; i74 < nx; i74++) {
      for (apnd = 0; apnd < 1; apnd++) {
        y->data[i74] = iminFirst->data[i74];
      }
    }

    emxFree_real_T(&iminFirst);
    for (i74 = 0; i74 < idx; i74++) {
      for (apnd = 0; apnd < 1; apnd++) {
        y->data[i74 + nx] = imin->data[i74];
      }
    }

    emxFree_real_T(&imin);
    for (i74 = 0; i74 < ndbl; i74++) {
      for (apnd = 0; apnd < 1; apnd++) {
        y->data[(i74 + nx) + idx] = iminLast->data[i74];
      }
    }

    emxFree_real_T(&iminLast);
    i74 = imaxLast->size[0] * imaxLast->size[1];
    imaxLast->size[0] = 1;
    imaxLast->size[1] = y->size[1];
    emxEnsureCapacity_real_T(imaxLast, i74);
    ndbl = y->size[0] * y->size[1];
    for (i74 = 0; i74 < ndbl; i74++) {
      imaxLast->data[i74] = y->data[i74];
    }

    i74 = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = y->size[1];
    emxEnsureCapacity_boolean_T(b_y, i74);
    ndbl = y->size[0] * y->size[1];
    for (i74 = 0; i74 < ndbl; i74++) {
      b_y->data[i74] = (y->data[i74] == 0.0);
    }

    emxFree_real_T(&y);
    c_nullAssignment(imaxLast, b_y);
    emxFree_boolean_T(&b_y);
    emxFree_real_T(&imaxLast);
  }

  emxFree_real_T(&d);
}

void d_extrema(const emxArray_real_T *x, emxArray_real_T *b_max, emxArray_real_T
               *imax, emxArray_real_T *b_min, emxArray_real_T *imin)
{
  emxArray_real_T *d;
  boolean_T tmp_data[1];
  int tmp_size[2];
  emxArray_boolean_T b_tmp_data;
  int input_sizes_idx_1;
  int i93;
  emxArray_boolean_T *b_x;
  double absa;
  int loop_ub;
  emxArray_int32_T *ii;
  int nx;
  int idx;
  boolean_T exitg1;
  emxArray_real_T *first;
  emxArray_int32_T *r39;
  emxArray_real_T *last;
  emxArray_boolean_T *c_x;
  emxArray_real_T *iminFirst;
  emxArray_real_T *imaxFirst;
  emxArray_real_T *y;
  emxArray_real_T *b_d;
  emxArray_real_T *iminLast;
  emxArray_real_T *imaxLast;
  double ndbl;
  double apnd;
  double cdiff;
  double u1;
  double maxct;
  double minct;
  emxArray_real_T *direction0;
  int k;
  double b_k;
  double direction;
  cell_wrap_26 reshapes[3];
  double u0;
  int i94;
  emxArray_boolean_T *b_y;
  emxInit_real_T(&d, 2);

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
  /* UPDATED */
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
  d_diff(x, d);

  /* get extrema if any nonzero changes */
  e_any(d, tmp_data, tmp_size);
  b_tmp_data.data = &tmp_data[0];
  b_tmp_data.size = &tmp_size[0];
  b_tmp_data.allocatedSize = 1;
  b_tmp_data.numDimensions = 2;
  b_tmp_data.canFreeData = false;
  if (c_ifWhileCond(&b_tmp_data)) {
    /* allocation */
    input_sizes_idx_1 = d->size[0];
    if (input_sizes_idx_1 <= 1) {
      input_sizes_idx_1 = 1;
    }

    if (d->size[0] == 0) {
      input_sizes_idx_1 = 0;
    }

    i93 = imax->size[0] * imax->size[1];
    imax->size[0] = 1;
    imax->size[1] = input_sizes_idx_1;
    emxEnsureCapacity_real_T(imax, i93);
    for (i93 = 0; i93 < input_sizes_idx_1; i93++) {
      imax->data[i93] = 0.0;
    }

    input_sizes_idx_1 = d->size[0];
    if (input_sizes_idx_1 <= 1) {
      input_sizes_idx_1 = 1;
    }

    if (d->size[0] == 0) {
      input_sizes_idx_1 = 0;
    }

    i93 = imin->size[0] * imin->size[1];
    imin->size[0] = 1;
    imin->size[1] = input_sizes_idx_1;
    emxEnsureCapacity_real_T(imin, i93);
    for (i93 = 0; i93 < input_sizes_idx_1; i93++) {
      imin->data[i93] = 0.0;
    }

    emxInit_boolean_T(&b_x, 2);

    /* endpoints are always local extrema */
    i93 = b_x->size[0] * b_x->size[1];
    b_x->size[0] = x->size[0];
    b_x->size[1] = 1;
    emxEnsureCapacity_boolean_T(b_x, i93);
    absa = x->data[0];
    loop_ub = x->size[0] * x->size[1];
    for (i93 = 0; i93 < loop_ub; i93++) {
      b_x->data[i93] = (x->data[i93] != absa);
    }

    emxInit_int32_T(&ii, 1);
    nx = b_x->size[0];
    idx = 0;
    i93 = ii->size[0];
    ii->size[0] = b_x->size[0];
    emxEnsureCapacity_int32_T(ii, i93);
    input_sizes_idx_1 = 0;
    exitg1 = false;
    while ((!exitg1) && (input_sizes_idx_1 <= nx - 1)) {
      if (b_x->data[input_sizes_idx_1]) {
        idx++;
        ii->data[idx - 1] = input_sizes_idx_1 + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          input_sizes_idx_1++;
        }
      } else {
        input_sizes_idx_1++;
      }
    }

    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      i93 = ii->size[0];
      ii->size[0] = idx;
      emxEnsureCapacity_int32_T(ii, i93);
    }

    emxInit_real_T(&first, 1);
    i93 = first->size[0];
    first->size[0] = ii->size[0];
    emxEnsureCapacity_real_T(first, i93);
    loop_ub = ii->size[0];
    for (i93 = 0; i93 < loop_ub; i93++) {
      first->data[i93] = ii->data[i93];
    }

    emxInit_int32_T(&r39, 2);
    loop_ub = first->size[0] - 2;
    i93 = r39->size[0] * r39->size[1];
    r39->size[0] = 1;
    r39->size[1] = loop_ub + 1;
    emxEnsureCapacity_int32_T(r39, i93);
    for (i93 = 0; i93 <= loop_ub; i93++) {
      r39->data[i93] = 2 + i93;
    }

    b_nullAssignment(first, r39);
    i93 = b_x->size[0] * b_x->size[1];
    b_x->size[0] = x->size[0];
    b_x->size[1] = 1;
    emxEnsureCapacity_boolean_T(b_x, i93);
    absa = x->data[x->size[0] - 1];
    loop_ub = x->size[0] * x->size[1];
    for (i93 = 0; i93 < loop_ub; i93++) {
      b_x->data[i93] = (x->data[i93] != absa);
    }

    nx = b_x->size[0];
    idx = 0;
    i93 = ii->size[0];
    ii->size[0] = b_x->size[0];
    emxEnsureCapacity_int32_T(ii, i93);
    input_sizes_idx_1 = 0;
    exitg1 = false;
    while ((!exitg1) && (input_sizes_idx_1 <= nx - 1)) {
      if (b_x->data[input_sizes_idx_1]) {
        idx++;
        ii->data[idx - 1] = input_sizes_idx_1 + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          input_sizes_idx_1++;
        }
      } else {
        input_sizes_idx_1++;
      }
    }

    emxFree_boolean_T(&b_x);
    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      i93 = ii->size[0];
      ii->size[0] = idx;
      emxEnsureCapacity_int32_T(ii, i93);
    }

    emxInit_real_T(&last, 1);
    i93 = last->size[0];
    last->size[0] = ii->size[0];
    emxEnsureCapacity_real_T(last, i93);
    loop_ub = ii->size[0];
    for (i93 = 0; i93 < loop_ub; i93++) {
      last->data[i93] = ii->data[i93];
    }

    emxFree_int32_T(&ii);
    loop_ub = last->size[0] - 2;
    i93 = r39->size[0] * r39->size[1];
    r39->size[0] = 1;
    r39->size[1] = loop_ub + 1;
    emxEnsureCapacity_int32_T(r39, i93);
    for (i93 = 0; i93 <= loop_ub; i93++) {
      r39->data[i93] = 1 + i93;
    }

    emxInit_boolean_T(&c_x, 1);
    b_nullAssignment(last, r39);
    absa = x->data[0];
    i93 = c_x->size[0];
    c_x->size[0] = first->size[0];
    emxEnsureCapacity_boolean_T(c_x, i93);
    loop_ub = first->size[0];
    emxFree_int32_T(&r39);
    for (i93 = 0; i93 < loop_ub; i93++) {
      c_x->data[i93] = (absa < x->data[static_cast<int>(first->data[i93]) - 1]);
    }

    emxInit_real_T(&iminFirst, 2);
    emxInit_real_T(&imaxFirst, 2);
    emxInit_real_T(&y, 2);
    emxInit_real_T(&b_d, 1);
    if (b_ifWhileCond(c_x)) {
      i93 = b_d->size[0];
      b_d->size[0] = first->size[0];
      emxEnsureCapacity_real_T(b_d, i93);
      loop_ub = first->size[0];
      for (i93 = 0; i93 < loop_ub; i93++) {
        b_d->data[i93] = first->data[i93] - 1.0;
      }

      if (rtIsNaN(b_d->data[0])) {
        i93 = iminFirst->size[0] * iminFirst->size[1];
        iminFirst->size[0] = 1;
        iminFirst->size[1] = 1;
        emxEnsureCapacity_real_T(iminFirst, i93);
        iminFirst->data[0] = rtNaN;
      } else if (b_d->data[0] < 1.0) {
        iminFirst->size[0] = 1;
        iminFirst->size[1] = 0;
      } else {
        i93 = iminFirst->size[0] * iminFirst->size[1];
        iminFirst->size[0] = 1;
        iminFirst->size[1] = static_cast<int>(std::floor(b_d->data[0] - 1.0)) +
          1;
        emxEnsureCapacity_real_T(iminFirst, i93);
        loop_ub = static_cast<int>(std::floor(b_d->data[0] - 1.0));
        for (i93 = 0; i93 <= loop_ub; i93++) {
          iminFirst->data[i93] = 1.0 + static_cast<double>(i93);
        }
      }

      imaxFirst->size[0] = 0;
      imaxFirst->size[1] = 0;
    } else {
      iminFirst->size[0] = 1;
      iminFirst->size[1] = 0;
      i93 = b_d->size[0];
      b_d->size[0] = first->size[0];
      emxEnsureCapacity_real_T(b_d, i93);
      loop_ub = first->size[0];
      for (i93 = 0; i93 < loop_ub; i93++) {
        b_d->data[i93] = first->data[i93] - 1.0;
      }

      if (rtIsNaN(b_d->data[0])) {
        i93 = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(y, i93);
        y->data[0] = rtNaN;
      } else if (b_d->data[0] < 1.0) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else {
        i93 = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = static_cast<int>(std::floor(b_d->data[0] - 1.0)) + 1;
        emxEnsureCapacity_real_T(y, i93);
        loop_ub = static_cast<int>(std::floor(b_d->data[0] - 1.0));
        for (i93 = 0; i93 <= loop_ub; i93++) {
          y->data[i93] = 1.0 + static_cast<double>(i93);
        }
      }

      i93 = imaxFirst->size[0] * imaxFirst->size[1];
      imaxFirst->size[0] = 1;
      imaxFirst->size[1] = y->size[1];
      emxEnsureCapacity_real_T(imaxFirst, i93);
      loop_ub = y->size[0] * y->size[1];
      for (i93 = 0; i93 < loop_ub; i93++) {
        imaxFirst->data[i93] = y->data[i93];
      }
    }

    absa = x->data[x->size[0] - 1];
    i93 = c_x->size[0];
    c_x->size[0] = last->size[0];
    emxEnsureCapacity_boolean_T(c_x, i93);
    loop_ub = last->size[0];
    for (i93 = 0; i93 < loop_ub; i93++) {
      c_x->data[i93] = (absa < x->data[static_cast<int>(last->data[i93]) - 1]);
    }

    emxInit_real_T(&iminLast, 2);
    emxInit_real_T(&imaxLast, 2);
    if (b_ifWhileCond(c_x)) {
      input_sizes_idx_1 = x->size[0];
      if (input_sizes_idx_1 <= 1) {
        input_sizes_idx_1 = 1;
      }

      if (x->size[0] == 0) {
        input_sizes_idx_1 = 0;
      }

      i93 = b_d->size[0];
      b_d->size[0] = last->size[0];
      emxEnsureCapacity_real_T(b_d, i93);
      loop_ub = last->size[0];
      for (i93 = 0; i93 < loop_ub; i93++) {
        b_d->data[i93] = last->data[i93] + 1.0;
      }

      if (rtIsNaN(b_d->data[0])) {
        i93 = iminLast->size[0] * iminLast->size[1];
        iminLast->size[0] = 1;
        iminLast->size[1] = 1;
        emxEnsureCapacity_real_T(iminLast, i93);
        iminLast->data[0] = rtNaN;
      } else if (input_sizes_idx_1 < b_d->data[0]) {
        iminLast->size[0] = 1;
        iminLast->size[1] = 0;
      } else if (std::floor(b_d->data[0]) == b_d->data[0]) {
        i93 = iminLast->size[0] * iminLast->size[1];
        iminLast->size[0] = 1;
        iminLast->size[1] = static_cast<int>(std::floor(static_cast<double>
          (input_sizes_idx_1) - b_d->data[0])) + 1;
        emxEnsureCapacity_real_T(iminLast, i93);
        loop_ub = static_cast<int>(std::floor(static_cast<double>
          (input_sizes_idx_1) - b_d->data[0]));
        for (i93 = 0; i93 <= loop_ub; i93++) {
          iminLast->data[i93] = b_d->data[0] + static_cast<double>(i93);
        }
      } else {
        ndbl = std::floor((static_cast<double>(input_sizes_idx_1) - b_d->data[0])
                          + 0.5);
        apnd = b_d->data[0] + ndbl;
        cdiff = apnd - static_cast<double>(input_sizes_idx_1);
        absa = b_d->data[0];
        u1 = input_sizes_idx_1;
        if (absa > u1) {
          u1 = absa;
        }

        if (std::abs(cdiff) < 4.4408920985006262E-16 * u1) {
          ndbl++;
          apnd = input_sizes_idx_1;
        } else if (cdiff > 0.0) {
          apnd = b_d->data[0] + (ndbl - 1.0);
        } else {
          ndbl++;
        }

        if (ndbl >= 0.0) {
          input_sizes_idx_1 = static_cast<int>(ndbl);
        } else {
          input_sizes_idx_1 = 0;
        }

        i93 = iminLast->size[0] * iminLast->size[1];
        iminLast->size[0] = 1;
        iminLast->size[1] = input_sizes_idx_1;
        emxEnsureCapacity_real_T(iminLast, i93);
        if (input_sizes_idx_1 > 0) {
          iminLast->data[0] = b_d->data[0];
          if (input_sizes_idx_1 > 1) {
            iminLast->data[input_sizes_idx_1 - 1] = apnd;
            nx = (input_sizes_idx_1 - 1) / 2;
            for (k = 0; k <= nx - 2; k++) {
              iminLast->data[1 + k] = b_d->data[0] + (1.0 + static_cast<double>
                (k));
              iminLast->data[(input_sizes_idx_1 - k) - 2] = apnd - (1.0 +
                static_cast<double>(k));
            }

            if (nx << 1 == input_sizes_idx_1 - 1) {
              iminLast->data[nx] = (b_d->data[0] + apnd) / 2.0;
            } else {
              iminLast->data[nx] = b_d->data[0] + static_cast<double>(nx);
              iminLast->data[nx + 1] = apnd - static_cast<double>(nx);
            }
          }
        }
      }

      imaxLast->size[0] = 0;
      imaxLast->size[1] = 0;
    } else {
      input_sizes_idx_1 = x->size[0];
      if (input_sizes_idx_1 <= 1) {
        input_sizes_idx_1 = 1;
      }

      if (x->size[0] == 0) {
        input_sizes_idx_1 = 0;
      }

      i93 = b_d->size[0];
      b_d->size[0] = last->size[0];
      emxEnsureCapacity_real_T(b_d, i93);
      loop_ub = last->size[0];
      for (i93 = 0; i93 < loop_ub; i93++) {
        b_d->data[i93] = last->data[i93] + 1.0;
      }

      if (rtIsNaN(b_d->data[0])) {
        i93 = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(y, i93);
        y->data[0] = rtNaN;
      } else if (input_sizes_idx_1 < b_d->data[0]) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else if (std::floor(b_d->data[0]) == b_d->data[0]) {
        i93 = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = static_cast<int>(std::floor(static_cast<double>
          (input_sizes_idx_1) - b_d->data[0])) + 1;
        emxEnsureCapacity_real_T(y, i93);
        loop_ub = static_cast<int>(std::floor(static_cast<double>
          (input_sizes_idx_1) - b_d->data[0]));
        for (i93 = 0; i93 <= loop_ub; i93++) {
          y->data[i93] = b_d->data[0] + static_cast<double>(i93);
        }
      } else {
        ndbl = std::floor((static_cast<double>(input_sizes_idx_1) - b_d->data[0])
                          + 0.5);
        apnd = b_d->data[0] + ndbl;
        cdiff = apnd - static_cast<double>(input_sizes_idx_1);
        absa = b_d->data[0];
        u1 = input_sizes_idx_1;
        if (absa > u1) {
          u1 = absa;
        }

        if (std::abs(cdiff) < 4.4408920985006262E-16 * u1) {
          ndbl++;
          apnd = input_sizes_idx_1;
        } else if (cdiff > 0.0) {
          apnd = b_d->data[0] + (ndbl - 1.0);
        } else {
          ndbl++;
        }

        if (ndbl >= 0.0) {
          input_sizes_idx_1 = static_cast<int>(ndbl);
        } else {
          input_sizes_idx_1 = 0;
        }

        i93 = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = input_sizes_idx_1;
        emxEnsureCapacity_real_T(y, i93);
        if (input_sizes_idx_1 > 0) {
          y->data[0] = b_d->data[0];
          if (input_sizes_idx_1 > 1) {
            y->data[input_sizes_idx_1 - 1] = apnd;
            nx = (input_sizes_idx_1 - 1) / 2;
            for (k = 0; k <= nx - 2; k++) {
              y->data[1 + k] = b_d->data[0] + (1.0 + static_cast<double>(k));
              y->data[(input_sizes_idx_1 - k) - 2] = apnd - (1.0 + static_cast<
                double>(k));
            }

            if (nx << 1 == input_sizes_idx_1 - 1) {
              y->data[nx] = (b_d->data[0] + apnd) / 2.0;
            } else {
              y->data[nx] = b_d->data[0] + static_cast<double>(nx);
              y->data[nx + 1] = apnd - static_cast<double>(nx);
            }
          }
        }
      }

      i93 = imaxLast->size[0] * imaxLast->size[1];
      imaxLast->size[0] = 1;
      imaxLast->size[1] = y->size[1];
      emxEnsureCapacity_real_T(imaxLast, i93);
      loop_ub = y->size[0] * y->size[1];
      for (i93 = 0; i93 < loop_ub; i93++) {
        imaxLast->data[i93] = y->data[i93];
      }

      iminLast->size[0] = 1;
      iminLast->size[1] = 0;
    }

    emxFree_boolean_T(&c_x);

    /* for each element */
    maxct = 0.0;
    minct = 0.0;
    i93 = b_d->size[0];
    b_d->size[0] = first->size[0];
    emxEnsureCapacity_real_T(b_d, i93);
    loop_ub = first->size[0];
    for (i93 = 0; i93 < loop_ub; i93++) {
      b_d->data[i93] = x->data[static_cast<int>((first->data[i93] - 1.0)) - 1];
    }

    emxInit_real_T(&direction0, 1);
    i93 = direction0->size[0];
    direction0->size[0] = first->size[0];
    emxEnsureCapacity_real_T(direction0, i93);
    loop_ub = first->size[0];
    for (i93 = 0; i93 < loop_ub; i93++) {
      direction0->data[i93] = x->data[static_cast<int>(first->data[i93]) - 1] -
        b_d->data[i93];
    }

    emxFree_real_T(&b_d);
    f_sign(direction0);
    absa = 0.0;
    i93 = static_cast<int>(((last->data[0] + 1.0) + (1.0 - (first->data[0] + 1.0))));
    emxFree_real_T(&last);
    for (k = 0; k < i93; k++) {
      b_k = (first->data[0] + 1.0) + static_cast<double>(k);

      /* current trajectory */
      direction = x->data[static_cast<int>(b_k) - 1] - x->data[static_cast<int>
        ((b_k - 1.0)) - 1];
      e_sign(&direction);

      /* if no change */
      if (direction == 0.0) {
        absa++;

        /* otherwise */
      } else {
        /* if local minimum */
        if ((direction == 1.0) && (direction0->data[0] == -1.0)) {
          /* update min/imin */
          minct = (minct + 1.0) + absa;
          u0 = minct - absa;
          if (u0 > minct) {
            i94 = 1;
          } else {
            i94 = static_cast<int>(u0);
          }

          absa = (b_k - 1.0) - absa;
          if (rtIsNaN(absa) || rtIsNaN(b_k - 1.0)) {
            nx = y->size[0] * y->size[1];
            y->size[0] = 1;
            y->size[1] = 1;
            emxEnsureCapacity_real_T(y, nx);
            y->data[0] = rtNaN;
          } else if (b_k - 1.0 < absa) {
            y->size[0] = 1;
            y->size[1] = 0;
          } else if (rtIsInf(absa) && (absa == b_k - 1.0)) {
            nx = y->size[0] * y->size[1];
            y->size[0] = 1;
            y->size[1] = 1;
            emxEnsureCapacity_real_T(y, nx);
            y->data[0] = rtNaN;
          } else if (std::floor(absa) == absa) {
            nx = y->size[0] * y->size[1];
            y->size[0] = 1;
            loop_ub = static_cast<int>(std::floor((b_k - 1.0) - absa));
            y->size[1] = loop_ub + 1;
            emxEnsureCapacity_real_T(y, nx);
            for (nx = 0; nx <= loop_ub; nx++) {
              y->data[nx] = absa + static_cast<double>(nx);
            }
          } else {
            ndbl = std::floor(((b_k - 1.0) - absa) + 0.5);
            apnd = absa + ndbl;
            cdiff = apnd - (b_k - 1.0);
            u0 = std::abs(absa);
            u1 = b_k - 1.0;
            if ((u0 > u1) || rtIsNaN(u1)) {
              u1 = u0;
            }

            if (std::abs(cdiff) < 4.4408920985006262E-16 * u1) {
              ndbl++;
              apnd = b_k - 1.0;
            } else if (cdiff > 0.0) {
              apnd = absa + (ndbl - 1.0);
            } else {
              ndbl++;
            }

            if (ndbl >= 0.0) {
              input_sizes_idx_1 = static_cast<int>(ndbl);
            } else {
              input_sizes_idx_1 = 0;
            }

            nx = y->size[0] * y->size[1];
            y->size[0] = 1;
            y->size[1] = input_sizes_idx_1;
            emxEnsureCapacity_real_T(y, nx);
            if (input_sizes_idx_1 > 0) {
              y->data[0] = absa;
              if (input_sizes_idx_1 > 1) {
                y->data[input_sizes_idx_1 - 1] = apnd;
                nx = (input_sizes_idx_1 - 1) / 2;
                for (idx = 0; idx <= nx - 2; idx++) {
                  y->data[1 + idx] = absa + (1.0 + static_cast<double>(idx));
                  y->data[(input_sizes_idx_1 - idx) - 2] = apnd - (1.0 +
                    static_cast<double>(idx));
                }

                if (nx << 1 == input_sizes_idx_1 - 1) {
                  y->data[nx] = (absa + apnd) / 2.0;
                } else {
                  y->data[nx] = absa + static_cast<double>(nx);
                  y->data[nx + 1] = apnd - static_cast<double>(nx);
                }
              }
            }
          }

          loop_ub = y->size[1];
          for (nx = 0; nx < loop_ub; nx++) {
            imin->data[(i94 + nx) - 1] = y->data[nx];
          }

          /* if local maximum */
        } else {
          if ((direction == -1.0) && (direction0->data[0] == 1.0)) {
            /* update max/imax */
            maxct = (maxct + 1.0) + absa;
            u0 = maxct - absa;
            if (u0 > maxct) {
              i94 = 1;
            } else {
              i94 = static_cast<int>(u0);
            }

            absa = (b_k - 1.0) - absa;
            if (rtIsNaN(absa) || rtIsNaN(b_k - 1.0)) {
              nx = y->size[0] * y->size[1];
              y->size[0] = 1;
              y->size[1] = 1;
              emxEnsureCapacity_real_T(y, nx);
              y->data[0] = rtNaN;
            } else if (b_k - 1.0 < absa) {
              y->size[0] = 1;
              y->size[1] = 0;
            } else if (rtIsInf(absa) && (absa == b_k - 1.0)) {
              nx = y->size[0] * y->size[1];
              y->size[0] = 1;
              y->size[1] = 1;
              emxEnsureCapacity_real_T(y, nx);
              y->data[0] = rtNaN;
            } else if (std::floor(absa) == absa) {
              nx = y->size[0] * y->size[1];
              y->size[0] = 1;
              loop_ub = static_cast<int>(std::floor((b_k - 1.0) - absa));
              y->size[1] = loop_ub + 1;
              emxEnsureCapacity_real_T(y, nx);
              for (nx = 0; nx <= loop_ub; nx++) {
                y->data[nx] = absa + static_cast<double>(nx);
              }
            } else {
              ndbl = std::floor(((b_k - 1.0) - absa) + 0.5);
              apnd = absa + ndbl;
              cdiff = apnd - (b_k - 1.0);
              u0 = std::abs(absa);
              u1 = b_k - 1.0;
              if ((u0 > u1) || rtIsNaN(u1)) {
                u1 = u0;
              }

              if (std::abs(cdiff) < 4.4408920985006262E-16 * u1) {
                ndbl++;
                apnd = b_k - 1.0;
              } else if (cdiff > 0.0) {
                apnd = absa + (ndbl - 1.0);
              } else {
                ndbl++;
              }

              if (ndbl >= 0.0) {
                input_sizes_idx_1 = static_cast<int>(ndbl);
              } else {
                input_sizes_idx_1 = 0;
              }

              nx = y->size[0] * y->size[1];
              y->size[0] = 1;
              y->size[1] = input_sizes_idx_1;
              emxEnsureCapacity_real_T(y, nx);
              if (input_sizes_idx_1 > 0) {
                y->data[0] = absa;
                if (input_sizes_idx_1 > 1) {
                  y->data[input_sizes_idx_1 - 1] = apnd;
                  nx = (input_sizes_idx_1 - 1) / 2;
                  for (idx = 0; idx <= nx - 2; idx++) {
                    y->data[1 + idx] = absa + (1.0 + static_cast<double>(idx));
                    y->data[(input_sizes_idx_1 - idx) - 2] = apnd - (1.0 +
                      static_cast<double>(idx));
                  }

                  if (nx << 1 == input_sizes_idx_1 - 1) {
                    y->data[nx] = (absa + apnd) / 2.0;
                  } else {
                    y->data[nx] = absa + static_cast<double>(nx);
                    y->data[nx + 1] = apnd - static_cast<double>(nx);
                  }
                }
              }
            }

            loop_ub = y->size[1];
            for (nx = 0; nx < loop_ub; nx++) {
              imax->data[(i94 + nx) - 1] = y->data[nx];
            }
          }
        }

        /* current trajectory is next iteration previous */
        i94 = direction0->size[0];
        direction0->size[0] = 1;
        emxEnsureCapacity_real_T(direction0, i94);
        direction0->data[0] = direction;

        /* no consecutive constant */
        absa = 0.0;
      }
    }

    emxFree_real_T(&direction0);
    emxFree_real_T(&first);

    /* finish */
    if ((imaxFirst->size[0] != 0) && (imaxFirst->size[1] != 0)) {
      input_sizes_idx_1 = imaxFirst->size[1];
    } else {
      input_sizes_idx_1 = 0;
    }

    emxInitMatrix_cell_wrap_261(reshapes);
    i93 = reshapes[0].f1->size[0] * reshapes[0].f1->size[1];
    reshapes[0].f1->size[0] = 1;
    reshapes[0].f1->size[1] = input_sizes_idx_1;
    emxEnsureCapacity_real_T(reshapes[0].f1, i93);
    for (i93 = 0; i93 < input_sizes_idx_1; i93++) {
      reshapes[0].f1->data[i93] = imaxFirst->data[i93];
    }

    emxFree_real_T(&imaxFirst);
    if (imax->size[1] != 0) {
      input_sizes_idx_1 = imax->size[1];
    } else {
      input_sizes_idx_1 = 0;
    }

    i93 = reshapes[1].f1->size[0] * reshapes[1].f1->size[1];
    reshapes[1].f1->size[0] = 1;
    reshapes[1].f1->size[1] = input_sizes_idx_1;
    emxEnsureCapacity_real_T(reshapes[1].f1, i93);
    for (i93 = 0; i93 < input_sizes_idx_1; i93++) {
      reshapes[1].f1->data[i93] = imax->data[i93];
    }

    if ((imaxLast->size[0] != 0) && (imaxLast->size[1] != 0)) {
      nx = imaxLast->size[1];
    } else {
      nx = 0;
    }

    i93 = imax->size[0] * imax->size[1];
    imax->size[0] = reshapes[0].f1->size[0];
    imax->size[1] = (reshapes[0].f1->size[1] + reshapes[1].f1->size[1]) + nx;
    emxEnsureCapacity_real_T(imax, i93);
    loop_ub = reshapes[0].f1->size[1];
    for (i93 = 0; i93 < loop_ub; i93++) {
      idx = reshapes[0].f1->size[0];
      for (i94 = 0; i94 < idx; i94++) {
        imax->data[i94 + imax->size[0] * i93] = reshapes[0].f1->data[i94 +
          reshapes[0].f1->size[0] * i93];
      }
    }

    loop_ub = reshapes[1].f1->size[1];
    for (i93 = 0; i93 < loop_ub; i93++) {
      idx = reshapes[1].f1->size[0];
      for (i94 = 0; i94 < idx; i94++) {
        imax->data[i94 + imax->size[0] * (i93 + reshapes[0].f1->size[1])] =
          reshapes[1].f1->data[i94 + reshapes[1].f1->size[0] * i93];
      }
    }

    for (i93 = 0; i93 < nx; i93++) {
      for (i94 = 0; i94 < 1; i94++) {
        imax->data[imax->size[0] * ((i93 + reshapes[0].f1->size[1]) + reshapes[1]
          .f1->size[1])] = imaxLast->data[imaxLast->size[0] * i93];
      }
    }

    emxFreeMatrix_cell_wrap_261(reshapes);
    emxFree_real_T(&imaxLast);
    emxInit_boolean_T(&b_y, 2);
    i93 = b_y->size[0] * b_y->size[1];
    b_y->size[0] = imax->size[0];
    b_y->size[1] = imax->size[1];
    emxEnsureCapacity_boolean_T(b_y, i93);
    loop_ub = imax->size[0] * imax->size[1];
    for (i93 = 0; i93 < loop_ub; i93++) {
      b_y->data[i93] = (imax->data[i93] == 0.0);
    }

    c_nullAssignment(imax, b_y);
    i93 = b_max->size[0] * b_max->size[1];
    b_max->size[0] = imax->size[0];
    b_max->size[1] = imax->size[1];
    emxEnsureCapacity_real_T(b_max, i93);
    loop_ub = imax->size[0] * imax->size[1];
    for (i93 = 0; i93 < loop_ub; i93++) {
      b_max->data[i93] = x->data[static_cast<int>(imax->data[i93]) - 1];
    }

    if (iminFirst->size[1] != 0) {
      input_sizes_idx_1 = iminFirst->size[1];
    } else {
      input_sizes_idx_1 = 0;
    }

    if (imin->size[1] != 0) {
      nx = imin->size[1];
    } else {
      nx = 0;
    }

    if (iminLast->size[1] != 0) {
      idx = iminLast->size[1];
    } else {
      idx = 0;
    }

    i93 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (input_sizes_idx_1 + nx) + idx;
    emxEnsureCapacity_real_T(y, i93);
    for (i93 = 0; i93 < input_sizes_idx_1; i93++) {
      for (i94 = 0; i94 < 1; i94++) {
        y->data[i93] = iminFirst->data[i93];
      }
    }

    emxFree_real_T(&iminFirst);
    for (i93 = 0; i93 < nx; i93++) {
      for (i94 = 0; i94 < 1; i94++) {
        y->data[i93 + input_sizes_idx_1] = imin->data[i93];
      }
    }

    for (i93 = 0; i93 < idx; i93++) {
      for (i94 = 0; i94 < 1; i94++) {
        y->data[(i93 + input_sizes_idx_1) + nx] = iminLast->data[i93];
      }
    }

    emxFree_real_T(&iminLast);
    i93 = imin->size[0] * imin->size[1];
    imin->size[0] = 1;
    imin->size[1] = y->size[1];
    emxEnsureCapacity_real_T(imin, i93);
    loop_ub = y->size[0] * y->size[1];
    for (i93 = 0; i93 < loop_ub; i93++) {
      imin->data[i93] = y->data[i93];
    }

    i93 = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = y->size[1];
    emxEnsureCapacity_boolean_T(b_y, i93);
    loop_ub = y->size[0] * y->size[1];
    for (i93 = 0; i93 < loop_ub; i93++) {
      b_y->data[i93] = (y->data[i93] == 0.0);
    }

    emxFree_real_T(&y);
    c_nullAssignment(imin, b_y);
    i93 = b_min->size[0] * b_min->size[1];
    b_min->size[0] = imin->size[0];
    b_min->size[1] = imin->size[1];
    emxEnsureCapacity_real_T(b_min, i93);
    loop_ub = imin->size[0] * imin->size[1];
    emxFree_boolean_T(&b_y);
    for (i93 = 0; i93 < loop_ub; i93++) {
      b_min->data[i93] = x->data[static_cast<int>(imin->data[i93]) - 1];
    }
  }

  emxFree_real_T(&d);
}

void e_extrema(const emxArray_real_T *x, emxArray_real_T *b_max, emxArray_real_T
               *imax)
{
  emxArray_real_T *d;
  boolean_T tmp_data[1];
  int tmp_size[2];
  emxArray_boolean_T b_tmp_data;
  int input_sizes_idx_1;
  int i95;
  emxArray_real_T *imin;
  emxArray_boolean_T *b_x;
  double absa;
  int loop_ub;
  emxArray_int32_T *ii;
  int nx;
  int idx;
  boolean_T exitg1;
  emxArray_real_T *first;
  emxArray_int32_T *r40;
  emxArray_real_T *last;
  emxArray_boolean_T *c_x;
  emxArray_real_T *iminFirst;
  emxArray_real_T *imaxFirst;
  emxArray_real_T *y;
  emxArray_real_T *b_d;
  emxArray_real_T *iminLast;
  emxArray_real_T *imaxLast;
  double ndbl;
  double apnd;
  double cdiff;
  double u1;
  double maxct;
  double minct;
  emxArray_real_T *direction0;
  int k;
  double b_k;
  double direction;
  cell_wrap_26 reshapes[3];
  double u0;
  int i96;
  emxArray_boolean_T *b_y;
  emxInit_real_T(&d, 2);

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
  /* UPDATED */
  /* initialize */
  b_max->size[0] = 0;
  b_max->size[1] = 0;
  imax->size[0] = 0;
  imax->size[1] = 0;

  /* get differences */
  d_diff(x, d);

  /* get extrema if any nonzero changes */
  e_any(d, tmp_data, tmp_size);
  b_tmp_data.data = &tmp_data[0];
  b_tmp_data.size = &tmp_size[0];
  b_tmp_data.allocatedSize = 1;
  b_tmp_data.numDimensions = 2;
  b_tmp_data.canFreeData = false;
  if (c_ifWhileCond(&b_tmp_data)) {
    /* allocation */
    input_sizes_idx_1 = d->size[0];
    if (input_sizes_idx_1 <= 1) {
      input_sizes_idx_1 = 1;
    }

    if (d->size[0] == 0) {
      input_sizes_idx_1 = 0;
    }

    i95 = imax->size[0] * imax->size[1];
    imax->size[0] = 1;
    imax->size[1] = input_sizes_idx_1;
    emxEnsureCapacity_real_T(imax, i95);
    for (i95 = 0; i95 < input_sizes_idx_1; i95++) {
      imax->data[i95] = 0.0;
    }

    input_sizes_idx_1 = d->size[0];
    if (input_sizes_idx_1 <= 1) {
      input_sizes_idx_1 = 1;
    }

    if (d->size[0] == 0) {
      input_sizes_idx_1 = 0;
    }

    emxInit_real_T(&imin, 2);
    i95 = imin->size[0] * imin->size[1];
    imin->size[0] = 1;
    imin->size[1] = input_sizes_idx_1;
    emxEnsureCapacity_real_T(imin, i95);
    for (i95 = 0; i95 < input_sizes_idx_1; i95++) {
      imin->data[i95] = 0.0;
    }

    emxInit_boolean_T(&b_x, 2);

    /* endpoints are always local extrema */
    i95 = b_x->size[0] * b_x->size[1];
    b_x->size[0] = x->size[0];
    b_x->size[1] = 1;
    emxEnsureCapacity_boolean_T(b_x, i95);
    absa = x->data[0];
    loop_ub = x->size[0] * x->size[1];
    for (i95 = 0; i95 < loop_ub; i95++) {
      b_x->data[i95] = (x->data[i95] != absa);
    }

    emxInit_int32_T(&ii, 1);
    nx = b_x->size[0];
    idx = 0;
    i95 = ii->size[0];
    ii->size[0] = b_x->size[0];
    emxEnsureCapacity_int32_T(ii, i95);
    input_sizes_idx_1 = 0;
    exitg1 = false;
    while ((!exitg1) && (input_sizes_idx_1 <= nx - 1)) {
      if (b_x->data[input_sizes_idx_1]) {
        idx++;
        ii->data[idx - 1] = input_sizes_idx_1 + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          input_sizes_idx_1++;
        }
      } else {
        input_sizes_idx_1++;
      }
    }

    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      i95 = ii->size[0];
      ii->size[0] = idx;
      emxEnsureCapacity_int32_T(ii, i95);
    }

    emxInit_real_T(&first, 1);
    i95 = first->size[0];
    first->size[0] = ii->size[0];
    emxEnsureCapacity_real_T(first, i95);
    loop_ub = ii->size[0];
    for (i95 = 0; i95 < loop_ub; i95++) {
      first->data[i95] = ii->data[i95];
    }

    emxInit_int32_T(&r40, 2);
    loop_ub = first->size[0] - 2;
    i95 = r40->size[0] * r40->size[1];
    r40->size[0] = 1;
    r40->size[1] = loop_ub + 1;
    emxEnsureCapacity_int32_T(r40, i95);
    for (i95 = 0; i95 <= loop_ub; i95++) {
      r40->data[i95] = 2 + i95;
    }

    b_nullAssignment(first, r40);
    i95 = b_x->size[0] * b_x->size[1];
    b_x->size[0] = x->size[0];
    b_x->size[1] = 1;
    emxEnsureCapacity_boolean_T(b_x, i95);
    absa = x->data[x->size[0] - 1];
    loop_ub = x->size[0] * x->size[1];
    for (i95 = 0; i95 < loop_ub; i95++) {
      b_x->data[i95] = (x->data[i95] != absa);
    }

    nx = b_x->size[0];
    idx = 0;
    i95 = ii->size[0];
    ii->size[0] = b_x->size[0];
    emxEnsureCapacity_int32_T(ii, i95);
    input_sizes_idx_1 = 0;
    exitg1 = false;
    while ((!exitg1) && (input_sizes_idx_1 <= nx - 1)) {
      if (b_x->data[input_sizes_idx_1]) {
        idx++;
        ii->data[idx - 1] = input_sizes_idx_1 + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          input_sizes_idx_1++;
        }
      } else {
        input_sizes_idx_1++;
      }
    }

    emxFree_boolean_T(&b_x);
    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      i95 = ii->size[0];
      ii->size[0] = idx;
      emxEnsureCapacity_int32_T(ii, i95);
    }

    emxInit_real_T(&last, 1);
    i95 = last->size[0];
    last->size[0] = ii->size[0];
    emxEnsureCapacity_real_T(last, i95);
    loop_ub = ii->size[0];
    for (i95 = 0; i95 < loop_ub; i95++) {
      last->data[i95] = ii->data[i95];
    }

    emxFree_int32_T(&ii);
    loop_ub = last->size[0] - 2;
    i95 = r40->size[0] * r40->size[1];
    r40->size[0] = 1;
    r40->size[1] = loop_ub + 1;
    emxEnsureCapacity_int32_T(r40, i95);
    for (i95 = 0; i95 <= loop_ub; i95++) {
      r40->data[i95] = 1 + i95;
    }

    emxInit_boolean_T(&c_x, 1);
    b_nullAssignment(last, r40);
    absa = x->data[0];
    i95 = c_x->size[0];
    c_x->size[0] = first->size[0];
    emxEnsureCapacity_boolean_T(c_x, i95);
    loop_ub = first->size[0];
    emxFree_int32_T(&r40);
    for (i95 = 0; i95 < loop_ub; i95++) {
      c_x->data[i95] = (absa < x->data[static_cast<int>(first->data[i95]) - 1]);
    }

    emxInit_real_T(&iminFirst, 2);
    emxInit_real_T(&imaxFirst, 2);
    emxInit_real_T(&y, 2);
    emxInit_real_T(&b_d, 1);
    if (b_ifWhileCond(c_x)) {
      i95 = b_d->size[0];
      b_d->size[0] = first->size[0];
      emxEnsureCapacity_real_T(b_d, i95);
      loop_ub = first->size[0];
      for (i95 = 0; i95 < loop_ub; i95++) {
        b_d->data[i95] = first->data[i95] - 1.0;
      }

      if (rtIsNaN(b_d->data[0])) {
        i95 = iminFirst->size[0] * iminFirst->size[1];
        iminFirst->size[0] = 1;
        iminFirst->size[1] = 1;
        emxEnsureCapacity_real_T(iminFirst, i95);
        iminFirst->data[0] = rtNaN;
      } else if (b_d->data[0] < 1.0) {
        iminFirst->size[0] = 1;
        iminFirst->size[1] = 0;
      } else {
        i95 = iminFirst->size[0] * iminFirst->size[1];
        iminFirst->size[0] = 1;
        iminFirst->size[1] = static_cast<int>(std::floor(b_d->data[0] - 1.0)) +
          1;
        emxEnsureCapacity_real_T(iminFirst, i95);
        loop_ub = static_cast<int>(std::floor(b_d->data[0] - 1.0));
        for (i95 = 0; i95 <= loop_ub; i95++) {
          iminFirst->data[i95] = 1.0 + static_cast<double>(i95);
        }
      }

      imaxFirst->size[0] = 0;
      imaxFirst->size[1] = 0;
    } else {
      iminFirst->size[0] = 1;
      iminFirst->size[1] = 0;
      i95 = b_d->size[0];
      b_d->size[0] = first->size[0];
      emxEnsureCapacity_real_T(b_d, i95);
      loop_ub = first->size[0];
      for (i95 = 0; i95 < loop_ub; i95++) {
        b_d->data[i95] = first->data[i95] - 1.0;
      }

      if (rtIsNaN(b_d->data[0])) {
        i95 = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(y, i95);
        y->data[0] = rtNaN;
      } else if (b_d->data[0] < 1.0) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else {
        i95 = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = static_cast<int>(std::floor(b_d->data[0] - 1.0)) + 1;
        emxEnsureCapacity_real_T(y, i95);
        loop_ub = static_cast<int>(std::floor(b_d->data[0] - 1.0));
        for (i95 = 0; i95 <= loop_ub; i95++) {
          y->data[i95] = 1.0 + static_cast<double>(i95);
        }
      }

      i95 = imaxFirst->size[0] * imaxFirst->size[1];
      imaxFirst->size[0] = 1;
      imaxFirst->size[1] = y->size[1];
      emxEnsureCapacity_real_T(imaxFirst, i95);
      loop_ub = y->size[0] * y->size[1];
      for (i95 = 0; i95 < loop_ub; i95++) {
        imaxFirst->data[i95] = y->data[i95];
      }
    }

    absa = x->data[x->size[0] - 1];
    i95 = c_x->size[0];
    c_x->size[0] = last->size[0];
    emxEnsureCapacity_boolean_T(c_x, i95);
    loop_ub = last->size[0];
    for (i95 = 0; i95 < loop_ub; i95++) {
      c_x->data[i95] = (absa < x->data[static_cast<int>(last->data[i95]) - 1]);
    }

    emxInit_real_T(&iminLast, 2);
    emxInit_real_T(&imaxLast, 2);
    if (b_ifWhileCond(c_x)) {
      input_sizes_idx_1 = x->size[0];
      if (input_sizes_idx_1 <= 1) {
        input_sizes_idx_1 = 1;
      }

      if (x->size[0] == 0) {
        input_sizes_idx_1 = 0;
      }

      i95 = b_d->size[0];
      b_d->size[0] = last->size[0];
      emxEnsureCapacity_real_T(b_d, i95);
      loop_ub = last->size[0];
      for (i95 = 0; i95 < loop_ub; i95++) {
        b_d->data[i95] = last->data[i95] + 1.0;
      }

      if (rtIsNaN(b_d->data[0])) {
        i95 = iminLast->size[0] * iminLast->size[1];
        iminLast->size[0] = 1;
        iminLast->size[1] = 1;
        emxEnsureCapacity_real_T(iminLast, i95);
        iminLast->data[0] = rtNaN;
      } else if (input_sizes_idx_1 < b_d->data[0]) {
        iminLast->size[0] = 1;
        iminLast->size[1] = 0;
      } else if (std::floor(b_d->data[0]) == b_d->data[0]) {
        i95 = iminLast->size[0] * iminLast->size[1];
        iminLast->size[0] = 1;
        iminLast->size[1] = static_cast<int>(std::floor(static_cast<double>
          (input_sizes_idx_1) - b_d->data[0])) + 1;
        emxEnsureCapacity_real_T(iminLast, i95);
        loop_ub = static_cast<int>(std::floor(static_cast<double>
          (input_sizes_idx_1) - b_d->data[0]));
        for (i95 = 0; i95 <= loop_ub; i95++) {
          iminLast->data[i95] = b_d->data[0] + static_cast<double>(i95);
        }
      } else {
        ndbl = std::floor((static_cast<double>(input_sizes_idx_1) - b_d->data[0])
                          + 0.5);
        apnd = b_d->data[0] + ndbl;
        cdiff = apnd - static_cast<double>(input_sizes_idx_1);
        absa = b_d->data[0];
        u1 = input_sizes_idx_1;
        if (absa > u1) {
          u1 = absa;
        }

        if (std::abs(cdiff) < 4.4408920985006262E-16 * u1) {
          ndbl++;
          apnd = input_sizes_idx_1;
        } else if (cdiff > 0.0) {
          apnd = b_d->data[0] + (ndbl - 1.0);
        } else {
          ndbl++;
        }

        if (ndbl >= 0.0) {
          input_sizes_idx_1 = static_cast<int>(ndbl);
        } else {
          input_sizes_idx_1 = 0;
        }

        i95 = iminLast->size[0] * iminLast->size[1];
        iminLast->size[0] = 1;
        iminLast->size[1] = input_sizes_idx_1;
        emxEnsureCapacity_real_T(iminLast, i95);
        if (input_sizes_idx_1 > 0) {
          iminLast->data[0] = b_d->data[0];
          if (input_sizes_idx_1 > 1) {
            iminLast->data[input_sizes_idx_1 - 1] = apnd;
            nx = (input_sizes_idx_1 - 1) / 2;
            for (k = 0; k <= nx - 2; k++) {
              iminLast->data[1 + k] = b_d->data[0] + (1.0 + static_cast<double>
                (k));
              iminLast->data[(input_sizes_idx_1 - k) - 2] = apnd - (1.0 +
                static_cast<double>(k));
            }

            if (nx << 1 == input_sizes_idx_1 - 1) {
              iminLast->data[nx] = (b_d->data[0] + apnd) / 2.0;
            } else {
              iminLast->data[nx] = b_d->data[0] + static_cast<double>(nx);
              iminLast->data[nx + 1] = apnd - static_cast<double>(nx);
            }
          }
        }
      }

      imaxLast->size[0] = 0;
      imaxLast->size[1] = 0;
    } else {
      input_sizes_idx_1 = x->size[0];
      if (input_sizes_idx_1 <= 1) {
        input_sizes_idx_1 = 1;
      }

      if (x->size[0] == 0) {
        input_sizes_idx_1 = 0;
      }

      i95 = b_d->size[0];
      b_d->size[0] = last->size[0];
      emxEnsureCapacity_real_T(b_d, i95);
      loop_ub = last->size[0];
      for (i95 = 0; i95 < loop_ub; i95++) {
        b_d->data[i95] = last->data[i95] + 1.0;
      }

      if (rtIsNaN(b_d->data[0])) {
        i95 = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(y, i95);
        y->data[0] = rtNaN;
      } else if (input_sizes_idx_1 < b_d->data[0]) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else if (std::floor(b_d->data[0]) == b_d->data[0]) {
        i95 = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = static_cast<int>(std::floor(static_cast<double>
          (input_sizes_idx_1) - b_d->data[0])) + 1;
        emxEnsureCapacity_real_T(y, i95);
        loop_ub = static_cast<int>(std::floor(static_cast<double>
          (input_sizes_idx_1) - b_d->data[0]));
        for (i95 = 0; i95 <= loop_ub; i95++) {
          y->data[i95] = b_d->data[0] + static_cast<double>(i95);
        }
      } else {
        ndbl = std::floor((static_cast<double>(input_sizes_idx_1) - b_d->data[0])
                          + 0.5);
        apnd = b_d->data[0] + ndbl;
        cdiff = apnd - static_cast<double>(input_sizes_idx_1);
        absa = b_d->data[0];
        u1 = input_sizes_idx_1;
        if (absa > u1) {
          u1 = absa;
        }

        if (std::abs(cdiff) < 4.4408920985006262E-16 * u1) {
          ndbl++;
          apnd = input_sizes_idx_1;
        } else if (cdiff > 0.0) {
          apnd = b_d->data[0] + (ndbl - 1.0);
        } else {
          ndbl++;
        }

        if (ndbl >= 0.0) {
          input_sizes_idx_1 = static_cast<int>(ndbl);
        } else {
          input_sizes_idx_1 = 0;
        }

        i95 = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = input_sizes_idx_1;
        emxEnsureCapacity_real_T(y, i95);
        if (input_sizes_idx_1 > 0) {
          y->data[0] = b_d->data[0];
          if (input_sizes_idx_1 > 1) {
            y->data[input_sizes_idx_1 - 1] = apnd;
            nx = (input_sizes_idx_1 - 1) / 2;
            for (k = 0; k <= nx - 2; k++) {
              y->data[1 + k] = b_d->data[0] + (1.0 + static_cast<double>(k));
              y->data[(input_sizes_idx_1 - k) - 2] = apnd - (1.0 + static_cast<
                double>(k));
            }

            if (nx << 1 == input_sizes_idx_1 - 1) {
              y->data[nx] = (b_d->data[0] + apnd) / 2.0;
            } else {
              y->data[nx] = b_d->data[0] + static_cast<double>(nx);
              y->data[nx + 1] = apnd - static_cast<double>(nx);
            }
          }
        }
      }

      i95 = imaxLast->size[0] * imaxLast->size[1];
      imaxLast->size[0] = 1;
      imaxLast->size[1] = y->size[1];
      emxEnsureCapacity_real_T(imaxLast, i95);
      loop_ub = y->size[0] * y->size[1];
      for (i95 = 0; i95 < loop_ub; i95++) {
        imaxLast->data[i95] = y->data[i95];
      }

      iminLast->size[0] = 1;
      iminLast->size[1] = 0;
    }

    emxFree_boolean_T(&c_x);

    /* for each element */
    maxct = 0.0;
    minct = 0.0;
    i95 = b_d->size[0];
    b_d->size[0] = first->size[0];
    emxEnsureCapacity_real_T(b_d, i95);
    loop_ub = first->size[0];
    for (i95 = 0; i95 < loop_ub; i95++) {
      b_d->data[i95] = x->data[static_cast<int>((first->data[i95] - 1.0)) - 1];
    }

    emxInit_real_T(&direction0, 1);
    i95 = direction0->size[0];
    direction0->size[0] = first->size[0];
    emxEnsureCapacity_real_T(direction0, i95);
    loop_ub = first->size[0];
    for (i95 = 0; i95 < loop_ub; i95++) {
      direction0->data[i95] = x->data[static_cast<int>(first->data[i95]) - 1] -
        b_d->data[i95];
    }

    emxFree_real_T(&b_d);
    f_sign(direction0);
    absa = 0.0;
    i95 = static_cast<int>(((last->data[0] + 1.0) + (1.0 - (first->data[0] + 1.0))));
    emxFree_real_T(&last);
    for (k = 0; k < i95; k++) {
      b_k = (first->data[0] + 1.0) + static_cast<double>(k);

      /* current trajectory */
      direction = x->data[static_cast<int>(b_k) - 1] - x->data[static_cast<int>
        ((b_k - 1.0)) - 1];
      e_sign(&direction);

      /* if no change */
      if (direction == 0.0) {
        absa++;

        /* otherwise */
      } else {
        /* if local minimum */
        if ((direction == 1.0) && (direction0->data[0] == -1.0)) {
          /* update min/imin */
          minct = (minct + 1.0) + absa;
          u0 = minct - absa;
          if (u0 > minct) {
            i96 = 1;
          } else {
            i96 = static_cast<int>(u0);
          }

          absa = (b_k - 1.0) - absa;
          if (rtIsNaN(absa) || rtIsNaN(b_k - 1.0)) {
            nx = y->size[0] * y->size[1];
            y->size[0] = 1;
            y->size[1] = 1;
            emxEnsureCapacity_real_T(y, nx);
            y->data[0] = rtNaN;
          } else if (b_k - 1.0 < absa) {
            y->size[0] = 1;
            y->size[1] = 0;
          } else if (rtIsInf(absa) && (absa == b_k - 1.0)) {
            nx = y->size[0] * y->size[1];
            y->size[0] = 1;
            y->size[1] = 1;
            emxEnsureCapacity_real_T(y, nx);
            y->data[0] = rtNaN;
          } else if (std::floor(absa) == absa) {
            nx = y->size[0] * y->size[1];
            y->size[0] = 1;
            loop_ub = static_cast<int>(std::floor((b_k - 1.0) - absa));
            y->size[1] = loop_ub + 1;
            emxEnsureCapacity_real_T(y, nx);
            for (nx = 0; nx <= loop_ub; nx++) {
              y->data[nx] = absa + static_cast<double>(nx);
            }
          } else {
            ndbl = std::floor(((b_k - 1.0) - absa) + 0.5);
            apnd = absa + ndbl;
            cdiff = apnd - (b_k - 1.0);
            u0 = std::abs(absa);
            u1 = b_k - 1.0;
            if ((u0 > u1) || rtIsNaN(u1)) {
              u1 = u0;
            }

            if (std::abs(cdiff) < 4.4408920985006262E-16 * u1) {
              ndbl++;
              apnd = b_k - 1.0;
            } else if (cdiff > 0.0) {
              apnd = absa + (ndbl - 1.0);
            } else {
              ndbl++;
            }

            if (ndbl >= 0.0) {
              input_sizes_idx_1 = static_cast<int>(ndbl);
            } else {
              input_sizes_idx_1 = 0;
            }

            nx = y->size[0] * y->size[1];
            y->size[0] = 1;
            y->size[1] = input_sizes_idx_1;
            emxEnsureCapacity_real_T(y, nx);
            if (input_sizes_idx_1 > 0) {
              y->data[0] = absa;
              if (input_sizes_idx_1 > 1) {
                y->data[input_sizes_idx_1 - 1] = apnd;
                nx = (input_sizes_idx_1 - 1) / 2;
                for (idx = 0; idx <= nx - 2; idx++) {
                  y->data[1 + idx] = absa + (1.0 + static_cast<double>(idx));
                  y->data[(input_sizes_idx_1 - idx) - 2] = apnd - (1.0 +
                    static_cast<double>(idx));
                }

                if (nx << 1 == input_sizes_idx_1 - 1) {
                  y->data[nx] = (absa + apnd) / 2.0;
                } else {
                  y->data[nx] = absa + static_cast<double>(nx);
                  y->data[nx + 1] = apnd - static_cast<double>(nx);
                }
              }
            }
          }

          loop_ub = y->size[1];
          for (nx = 0; nx < loop_ub; nx++) {
            imin->data[(i96 + nx) - 1] = y->data[nx];
          }

          /* if local maximum */
        } else {
          if ((direction == -1.0) && (direction0->data[0] == 1.0)) {
            /* update max/imax */
            maxct = (maxct + 1.0) + absa;
            u0 = maxct - absa;
            if (u0 > maxct) {
              i96 = 1;
            } else {
              i96 = static_cast<int>(u0);
            }

            absa = (b_k - 1.0) - absa;
            if (rtIsNaN(absa) || rtIsNaN(b_k - 1.0)) {
              nx = y->size[0] * y->size[1];
              y->size[0] = 1;
              y->size[1] = 1;
              emxEnsureCapacity_real_T(y, nx);
              y->data[0] = rtNaN;
            } else if (b_k - 1.0 < absa) {
              y->size[0] = 1;
              y->size[1] = 0;
            } else if (rtIsInf(absa) && (absa == b_k - 1.0)) {
              nx = y->size[0] * y->size[1];
              y->size[0] = 1;
              y->size[1] = 1;
              emxEnsureCapacity_real_T(y, nx);
              y->data[0] = rtNaN;
            } else if (std::floor(absa) == absa) {
              nx = y->size[0] * y->size[1];
              y->size[0] = 1;
              loop_ub = static_cast<int>(std::floor((b_k - 1.0) - absa));
              y->size[1] = loop_ub + 1;
              emxEnsureCapacity_real_T(y, nx);
              for (nx = 0; nx <= loop_ub; nx++) {
                y->data[nx] = absa + static_cast<double>(nx);
              }
            } else {
              ndbl = std::floor(((b_k - 1.0) - absa) + 0.5);
              apnd = absa + ndbl;
              cdiff = apnd - (b_k - 1.0);
              u0 = std::abs(absa);
              u1 = b_k - 1.0;
              if ((u0 > u1) || rtIsNaN(u1)) {
                u1 = u0;
              }

              if (std::abs(cdiff) < 4.4408920985006262E-16 * u1) {
                ndbl++;
                apnd = b_k - 1.0;
              } else if (cdiff > 0.0) {
                apnd = absa + (ndbl - 1.0);
              } else {
                ndbl++;
              }

              if (ndbl >= 0.0) {
                input_sizes_idx_1 = static_cast<int>(ndbl);
              } else {
                input_sizes_idx_1 = 0;
              }

              nx = y->size[0] * y->size[1];
              y->size[0] = 1;
              y->size[1] = input_sizes_idx_1;
              emxEnsureCapacity_real_T(y, nx);
              if (input_sizes_idx_1 > 0) {
                y->data[0] = absa;
                if (input_sizes_idx_1 > 1) {
                  y->data[input_sizes_idx_1 - 1] = apnd;
                  nx = (input_sizes_idx_1 - 1) / 2;
                  for (idx = 0; idx <= nx - 2; idx++) {
                    y->data[1 + idx] = absa + (1.0 + static_cast<double>(idx));
                    y->data[(input_sizes_idx_1 - idx) - 2] = apnd - (1.0 +
                      static_cast<double>(idx));
                  }

                  if (nx << 1 == input_sizes_idx_1 - 1) {
                    y->data[nx] = (absa + apnd) / 2.0;
                  } else {
                    y->data[nx] = absa + static_cast<double>(nx);
                    y->data[nx + 1] = apnd - static_cast<double>(nx);
                  }
                }
              }
            }

            loop_ub = y->size[1];
            for (nx = 0; nx < loop_ub; nx++) {
              imax->data[(i96 + nx) - 1] = y->data[nx];
            }
          }
        }

        /* current trajectory is next iteration previous */
        i96 = direction0->size[0];
        direction0->size[0] = 1;
        emxEnsureCapacity_real_T(direction0, i96);
        direction0->data[0] = direction;

        /* no consecutive constant */
        absa = 0.0;
      }
    }

    emxFree_real_T(&direction0);
    emxFree_real_T(&first);

    /* finish */
    if ((imaxFirst->size[0] != 0) && (imaxFirst->size[1] != 0)) {
      input_sizes_idx_1 = imaxFirst->size[1];
    } else {
      input_sizes_idx_1 = 0;
    }

    emxInitMatrix_cell_wrap_261(reshapes);
    i95 = reshapes[0].f1->size[0] * reshapes[0].f1->size[1];
    reshapes[0].f1->size[0] = 1;
    reshapes[0].f1->size[1] = input_sizes_idx_1;
    emxEnsureCapacity_real_T(reshapes[0].f1, i95);
    for (i95 = 0; i95 < input_sizes_idx_1; i95++) {
      reshapes[0].f1->data[i95] = imaxFirst->data[i95];
    }

    emxFree_real_T(&imaxFirst);
    if (imax->size[1] != 0) {
      input_sizes_idx_1 = imax->size[1];
    } else {
      input_sizes_idx_1 = 0;
    }

    i95 = reshapes[1].f1->size[0] * reshapes[1].f1->size[1];
    reshapes[1].f1->size[0] = 1;
    reshapes[1].f1->size[1] = input_sizes_idx_1;
    emxEnsureCapacity_real_T(reshapes[1].f1, i95);
    for (i95 = 0; i95 < input_sizes_idx_1; i95++) {
      reshapes[1].f1->data[i95] = imax->data[i95];
    }

    if ((imaxLast->size[0] != 0) && (imaxLast->size[1] != 0)) {
      nx = imaxLast->size[1];
    } else {
      nx = 0;
    }

    i95 = imax->size[0] * imax->size[1];
    imax->size[0] = reshapes[0].f1->size[0];
    imax->size[1] = (reshapes[0].f1->size[1] + reshapes[1].f1->size[1]) + nx;
    emxEnsureCapacity_real_T(imax, i95);
    loop_ub = reshapes[0].f1->size[1];
    for (i95 = 0; i95 < loop_ub; i95++) {
      idx = reshapes[0].f1->size[0];
      for (i96 = 0; i96 < idx; i96++) {
        imax->data[i96 + imax->size[0] * i95] = reshapes[0].f1->data[i96 +
          reshapes[0].f1->size[0] * i95];
      }
    }

    loop_ub = reshapes[1].f1->size[1];
    for (i95 = 0; i95 < loop_ub; i95++) {
      idx = reshapes[1].f1->size[0];
      for (i96 = 0; i96 < idx; i96++) {
        imax->data[i96 + imax->size[0] * (i95 + reshapes[0].f1->size[1])] =
          reshapes[1].f1->data[i96 + reshapes[1].f1->size[0] * i95];
      }
    }

    for (i95 = 0; i95 < nx; i95++) {
      for (i96 = 0; i96 < 1; i96++) {
        imax->data[imax->size[0] * ((i95 + reshapes[0].f1->size[1]) + reshapes[1]
          .f1->size[1])] = imaxLast->data[imaxLast->size[0] * i95];
      }
    }

    emxFreeMatrix_cell_wrap_261(reshapes);
    emxInit_boolean_T(&b_y, 2);
    i95 = b_y->size[0] * b_y->size[1];
    b_y->size[0] = imax->size[0];
    b_y->size[1] = imax->size[1];
    emxEnsureCapacity_boolean_T(b_y, i95);
    loop_ub = imax->size[0] * imax->size[1];
    for (i95 = 0; i95 < loop_ub; i95++) {
      b_y->data[i95] = (imax->data[i95] == 0.0);
    }

    c_nullAssignment(imax, b_y);
    i95 = b_max->size[0] * b_max->size[1];
    b_max->size[0] = imax->size[0];
    b_max->size[1] = imax->size[1];
    emxEnsureCapacity_real_T(b_max, i95);
    loop_ub = imax->size[0] * imax->size[1];
    for (i95 = 0; i95 < loop_ub; i95++) {
      b_max->data[i95] = x->data[static_cast<int>(imax->data[i95]) - 1];
    }

    if (iminFirst->size[1] != 0) {
      input_sizes_idx_1 = iminFirst->size[1];
    } else {
      input_sizes_idx_1 = 0;
    }

    if (imin->size[1] != 0) {
      nx = imin->size[1];
    } else {
      nx = 0;
    }

    if (iminLast->size[1] != 0) {
      idx = iminLast->size[1];
    } else {
      idx = 0;
    }

    i95 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (input_sizes_idx_1 + nx) + idx;
    emxEnsureCapacity_real_T(y, i95);
    for (i95 = 0; i95 < input_sizes_idx_1; i95++) {
      for (i96 = 0; i96 < 1; i96++) {
        y->data[i95] = iminFirst->data[i95];
      }
    }

    emxFree_real_T(&iminFirst);
    for (i95 = 0; i95 < nx; i95++) {
      for (i96 = 0; i96 < 1; i96++) {
        y->data[i95 + input_sizes_idx_1] = imin->data[i95];
      }
    }

    emxFree_real_T(&imin);
    for (i95 = 0; i95 < idx; i95++) {
      for (i96 = 0; i96 < 1; i96++) {
        y->data[(i95 + input_sizes_idx_1) + nx] = iminLast->data[i95];
      }
    }

    emxFree_real_T(&iminLast);
    i95 = imaxLast->size[0] * imaxLast->size[1];
    imaxLast->size[0] = 1;
    imaxLast->size[1] = y->size[1];
    emxEnsureCapacity_real_T(imaxLast, i95);
    loop_ub = y->size[0] * y->size[1];
    for (i95 = 0; i95 < loop_ub; i95++) {
      imaxLast->data[i95] = y->data[i95];
    }

    i95 = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = y->size[1];
    emxEnsureCapacity_boolean_T(b_y, i95);
    loop_ub = y->size[0] * y->size[1];
    for (i95 = 0; i95 < loop_ub; i95++) {
      b_y->data[i95] = (y->data[i95] == 0.0);
    }

    emxFree_real_T(&y);
    c_nullAssignment(imaxLast, b_y);
    emxFree_boolean_T(&b_y);
    emxFree_real_T(&imaxLast);
  }

  emxFree_real_T(&d);
}

void extrema(const emxArray_creal_T *x, emxArray_creal_T *b_max, emxArray_real_T
             *imax)
{
  emxArray_creal_T *d;
  boolean_T tmp_data[4096];
  int tmp_size[3];
  int n;
  int i40;
  emxArray_real_T *imin;
  emxArray_boolean_T *b_x;
  creal_T direction;
  int idx;
  emxArray_int32_T *ii;
  int nx;
  int absa;
  boolean_T exitg1;
  emxArray_real_T *first;
  emxArray_real_T *b_d;
  emxArray_int32_T *r15;
  emxArray_real_T *last;
  emxArray_boolean_T *c_x;
  emxArray_real_T *iminFirst;
  emxArray_real_T *imaxFirst;
  emxArray_real_T *y;
  emxArray_real_T *iminLast;
  emxArray_real_T *imaxLast;
  int apnd;
  emxArray_creal_T *r16;
  double maxct;
  double minct;
  emxArray_creal_T *direction0;
  double constant;
  cell_wrap_26 reshapes[3];
  boolean_T guard1 = false;
  boolean_T b_direction0;
  double ndbl;
  short input_sizes_idx_1;
  double b_apnd;
  double cdiff;
  double u0;
  double u1;
  emxArray_boolean_T *b_y;
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
  /* UPDATED */
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

    i40 = imax->size[0] * imax->size[1];
    imax->size[0] = 1;
    imax->size[1] = n;
    emxEnsureCapacity_real_T(imax, i40);
    for (i40 = 0; i40 < n; i40++) {
      imax->data[i40] = 0.0;
    }

    n = d->size[0];
    if ((d->size[0] > 0) && ((d->size[1] == 0) || (d->size[1] > d->size[0]))) {
      n = d->size[1];
    }

    emxInit_real_T(&imin, 2);
    i40 = imin->size[0] * imin->size[1];
    imin->size[0] = 1;
    imin->size[1] = n;
    emxEnsureCapacity_real_T(imin, i40);
    for (i40 = 0; i40 < n; i40++) {
      imin->data[i40] = 0.0;
    }

    emxInit_boolean_T(&b_x, 3);

    /* endpoints are always local extrema */
    i40 = b_x->size[0] * b_x->size[1] * b_x->size[2];
    b_x->size[0] = x->size[0];
    b_x->size[1] = x->size[1];
    b_x->size[2] = 1;
    emxEnsureCapacity_boolean_T(b_x, i40);
    direction = x->data[0];
    idx = x->size[0] * x->size[1] * x->size[2];
    for (i40 = 0; i40 < idx; i40++) {
      b_x->data[i40] = ((x->data[i40].re != direction.re) || (x->data[i40].im !=
        direction.im));
    }

    emxInit_int32_T(&ii, 1);
    nx = b_x->size[0] * b_x->size[1];
    idx = 0;
    i40 = ii->size[0];
    ii->size[0] = nx;
    emxEnsureCapacity_int32_T(ii, i40);
    absa = 0;
    exitg1 = false;
    while ((!exitg1) && (absa <= nx - 1)) {
      if (b_x->data[absa]) {
        idx++;
        ii->data[idx - 1] = absa + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          absa++;
        }
      } else {
        absa++;
      }
    }

    if (nx == 1) {
      if (idx == 0) {
        ii->size[0] = 0;
      }
    } else if (1 > idx) {
      ii->size[0] = 0;
    } else {
      i40 = ii->size[0];
      ii->size[0] = idx;
      emxEnsureCapacity_int32_T(ii, i40);
    }

    emxInit_real_T(&first, 1);
    i40 = first->size[0];
    first->size[0] = ii->size[0];
    emxEnsureCapacity_real_T(first, i40);
    idx = ii->size[0];
    for (i40 = 0; i40 < idx; i40++) {
      first->data[i40] = ii->data[i40];
    }

    emxInit_real_T(&b_d, 1);
    i40 = b_d->size[0];
    b_d->size[0] = first->size[0];
    emxEnsureCapacity_real_T(b_d, i40);
    idx = first->size[0];
    for (i40 = 0; i40 < idx; i40++) {
      b_d->data[i40] = first->data[i40];
    }

    emxInit_int32_T(&r15, 2);
    idx = first->size[0] - 2;
    i40 = r15->size[0] * r15->size[1];
    r15->size[0] = 1;
    r15->size[1] = idx + 1;
    emxEnsureCapacity_int32_T(r15, i40);
    for (i40 = 0; i40 <= idx; i40++) {
      r15->data[i40] = 2 + i40;
    }

    b_nullAssignment(b_d, r15);
    i40 = first->size[0];
    first->size[0] = b_d->size[0];
    emxEnsureCapacity_real_T(first, i40);
    idx = b_d->size[0];
    for (i40 = 0; i40 < idx; i40++) {
      first->data[i40] = b_d->data[i40];
    }

    i40 = b_x->size[0] * b_x->size[1] * b_x->size[2];
    b_x->size[0] = x->size[0];
    b_x->size[1] = x->size[1];
    b_x->size[2] = 1;
    emxEnsureCapacity_boolean_T(b_x, i40);
    direction = x->data[x->size[0] * x->size[1] - 1];
    idx = x->size[0] * x->size[1] * x->size[2];
    for (i40 = 0; i40 < idx; i40++) {
      b_x->data[i40] = ((x->data[i40].re != direction.re) || (x->data[i40].im !=
        direction.im));
    }

    nx = b_x->size[0] * b_x->size[1];
    idx = 0;
    i40 = ii->size[0];
    ii->size[0] = nx;
    emxEnsureCapacity_int32_T(ii, i40);
    absa = 0;
    exitg1 = false;
    while ((!exitg1) && (absa <= nx - 1)) {
      if (b_x->data[absa]) {
        idx++;
        ii->data[idx - 1] = absa + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          absa++;
        }
      } else {
        absa++;
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
      i40 = ii->size[0];
      ii->size[0] = idx;
      emxEnsureCapacity_int32_T(ii, i40);
    }

    emxInit_real_T(&last, 1);
    i40 = last->size[0];
    last->size[0] = ii->size[0];
    emxEnsureCapacity_real_T(last, i40);
    idx = ii->size[0];
    for (i40 = 0; i40 < idx; i40++) {
      last->data[i40] = ii->data[i40];
    }

    emxFree_int32_T(&ii);
    i40 = b_d->size[0];
    b_d->size[0] = last->size[0];
    emxEnsureCapacity_real_T(b_d, i40);
    idx = last->size[0];
    for (i40 = 0; i40 < idx; i40++) {
      b_d->data[i40] = last->data[i40];
    }

    idx = last->size[0] - 2;
    i40 = r15->size[0] * r15->size[1];
    r15->size[0] = 1;
    r15->size[1] = idx + 1;
    emxEnsureCapacity_int32_T(r15, i40);
    for (i40 = 0; i40 <= idx; i40++) {
      r15->data[i40] = 1 + i40;
    }

    b_nullAssignment(b_d, r15);
    i40 = last->size[0];
    last->size[0] = b_d->size[0];
    emxEnsureCapacity_real_T(last, i40);
    idx = b_d->size[0];
    emxFree_int32_T(&r15);
    for (i40 = 0; i40 < idx; i40++) {
      last->data[i40] = b_d->data[i40];
    }

    emxInit_boolean_T(&c_x, 1);
    direction = x->data[0];
    i40 = c_x->size[0];
    c_x->size[0] = first->size[0];
    emxEnsureCapacity_boolean_T(c_x, i40);
    idx = first->size[0];
    for (i40 = 0; i40 < idx; i40++) {
      c_x->data[i40] = (direction.re < x->data[static_cast<int>(first->data[i40])
                        - 1].re);
    }

    emxInit_real_T(&iminFirst, 2);
    emxInit_real_T(&imaxFirst, 2);
    emxInit_real_T(&y, 2);
    if (b_ifWhileCond(c_x)) {
      i40 = b_d->size[0];
      b_d->size[0] = first->size[0];
      emxEnsureCapacity_real_T(b_d, i40);
      idx = first->size[0];
      for (i40 = 0; i40 < idx; i40++) {
        b_d->data[i40] = first->data[i40] - 1.0;
      }

      if (b_d->data[0] < 1.0) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else {
        i40 = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = static_cast<int>(std::floor(b_d->data[0] - 1.0)) + 1;
        emxEnsureCapacity_real_T(y, i40);
        idx = static_cast<int>(std::floor(b_d->data[0] - 1.0));
        for (i40 = 0; i40 <= idx; i40++) {
          y->data[i40] = 1.0 + static_cast<double>(i40);
        }
      }

      i40 = iminFirst->size[0] * iminFirst->size[1];
      iminFirst->size[0] = 1;
      iminFirst->size[1] = y->size[1];
      emxEnsureCapacity_real_T(iminFirst, i40);
      idx = y->size[0] * y->size[1];
      for (i40 = 0; i40 < idx; i40++) {
        iminFirst->data[i40] = y->data[i40];
      }

      imaxFirst->size[0] = 0;
      imaxFirst->size[1] = 0;
    } else {
      iminFirst->size[0] = 1;
      iminFirst->size[1] = 0;
      i40 = b_d->size[0];
      b_d->size[0] = first->size[0];
      emxEnsureCapacity_real_T(b_d, i40);
      idx = first->size[0];
      for (i40 = 0; i40 < idx; i40++) {
        b_d->data[i40] = first->data[i40] - 1.0;
      }

      if (b_d->data[0] < 1.0) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else {
        i40 = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = static_cast<int>(std::floor(b_d->data[0] - 1.0)) + 1;
        emxEnsureCapacity_real_T(y, i40);
        idx = static_cast<int>(std::floor(b_d->data[0] - 1.0));
        for (i40 = 0; i40 <= idx; i40++) {
          y->data[i40] = 1.0 + static_cast<double>(i40);
        }
      }

      i40 = imaxFirst->size[0] * imaxFirst->size[1];
      imaxFirst->size[0] = 1;
      imaxFirst->size[1] = y->size[1];
      emxEnsureCapacity_real_T(imaxFirst, i40);
      idx = y->size[0] * y->size[1];
      for (i40 = 0; i40 < idx; i40++) {
        imaxFirst->data[i40] = y->data[i40];
      }
    }

    direction = x->data[x->size[0] * x->size[1] - 1];
    i40 = c_x->size[0];
    c_x->size[0] = last->size[0];
    emxEnsureCapacity_boolean_T(c_x, i40);
    idx = last->size[0];
    for (i40 = 0; i40 < idx; i40++) {
      c_x->data[i40] = (direction.re < x->data[static_cast<int>(last->data[i40])
                        - 1].re);
    }

    emxInit_real_T(&iminLast, 2);
    emxInit_real_T(&imaxLast, 2);
    if (b_ifWhileCond(c_x)) {
      n = x->size[0];
      if ((x->size[0] > 0) && ((x->size[1] == 0) || (x->size[1] > x->size[0])))
      {
        n = x->size[1];
      }

      i40 = b_d->size[0];
      b_d->size[0] = last->size[0];
      emxEnsureCapacity_real_T(b_d, i40);
      idx = last->size[0];
      for (i40 = 0; i40 < idx; i40++) {
        b_d->data[i40] = last->data[i40] + 1.0;
      }

      if (n < static_cast<int>(b_d->data[0])) {
        iminLast->size[0] = 1;
        iminLast->size[1] = 0;
      } else if (b_d->data[0] == b_d->data[0]) {
        i40 = iminLast->size[0] * iminLast->size[1];
        iminLast->size[0] = 1;
        iminLast->size[1] = static_cast<int>(std::floor(static_cast<double>(n) -
          b_d->data[0])) + 1;
        emxEnsureCapacity_real_T(iminLast, i40);
        idx = static_cast<int>(std::floor(static_cast<double>(n) - b_d->data[0]));
        for (i40 = 0; i40 <= idx; i40++) {
          iminLast->data[i40] = b_d->data[0] + static_cast<double>(i40);
        }
      } else {
        nx = static_cast<int>(std::floor((static_cast<double>(n) - b_d->data[0])
          + 0.5));
        apnd = static_cast<int>(b_d->data[0]) + nx;
        idx = apnd - n;
        absa = static_cast<int>(b_d->data[0]);
        if (absa <= n) {
          absa = n;
        }

        if (std::abs((double)idx) < 4.4408920985006262E-16 * static_cast<double>
            (absa)) {
          nx++;
          apnd = n;
        } else if (idx > 0) {
          apnd = (static_cast<int>(b_d->data[0]) + nx) - 1;
        } else {
          nx++;
        }

        if (nx >= 0) {
          n = nx;
        } else {
          n = 0;
        }

        i40 = iminLast->size[0] * iminLast->size[1];
        iminLast->size[0] = 1;
        iminLast->size[1] = n;
        emxEnsureCapacity_real_T(iminLast, i40);
        if (n > 0) {
          iminLast->data[0] = b_d->data[0];
          if (n > 1) {
            iminLast->data[n - 1] = apnd;
            nx = (n - 1) / 2;
            for (absa = 0; absa <= nx - 2; absa++) {
              iminLast->data[1 + absa] = b_d->data[0] + (1.0 + static_cast<
                double>(absa));
              iminLast->data[(n - absa) - 2] = (apnd - absa) - 1;
            }

            if (nx << 1 == n - 1) {
              iminLast->data[nx] = (b_d->data[0] + static_cast<double>(apnd)) /
                2.0;
            } else {
              iminLast->data[nx] = b_d->data[0] + static_cast<double>(nx);
              iminLast->data[nx + 1] = apnd - nx;
            }
          }
        }
      }

      imaxLast->size[0] = 0;
      imaxLast->size[1] = 0;
    } else {
      n = x->size[0];
      if ((x->size[0] > 0) && ((x->size[1] == 0) || (x->size[1] > x->size[0])))
      {
        n = x->size[1];
      }

      i40 = b_d->size[0];
      b_d->size[0] = last->size[0];
      emxEnsureCapacity_real_T(b_d, i40);
      idx = last->size[0];
      for (i40 = 0; i40 < idx; i40++) {
        b_d->data[i40] = last->data[i40] + 1.0;
      }

      if (n < static_cast<int>(b_d->data[0])) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else if (b_d->data[0] == b_d->data[0]) {
        i40 = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = static_cast<int>(std::floor(static_cast<double>(n) -
          b_d->data[0])) + 1;
        emxEnsureCapacity_real_T(y, i40);
        idx = static_cast<int>(std::floor(static_cast<double>(n) - b_d->data[0]));
        for (i40 = 0; i40 <= idx; i40++) {
          y->data[i40] = b_d->data[0] + static_cast<double>(i40);
        }
      } else {
        nx = static_cast<int>(std::floor((static_cast<double>(n) - b_d->data[0])
          + 0.5));
        apnd = static_cast<int>(b_d->data[0]) + nx;
        idx = apnd - n;
        absa = static_cast<int>(b_d->data[0]);
        if (absa <= n) {
          absa = n;
        }

        if (std::abs((double)idx) < 4.4408920985006262E-16 * static_cast<double>
            (absa)) {
          nx++;
          apnd = n;
        } else if (idx > 0) {
          apnd = (static_cast<int>(b_d->data[0]) + nx) - 1;
        } else {
          nx++;
        }

        if (nx >= 0) {
          n = nx;
        } else {
          n = 0;
        }

        i40 = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = n;
        emxEnsureCapacity_real_T(y, i40);
        if (n > 0) {
          y->data[0] = b_d->data[0];
          if (n > 1) {
            y->data[n - 1] = apnd;
            nx = (n - 1) / 2;
            for (absa = 0; absa <= nx - 2; absa++) {
              y->data[1 + absa] = b_d->data[0] + (1.0 + static_cast<double>(absa));
              y->data[(n - absa) - 2] = (apnd - absa) - 1;
            }

            if (nx << 1 == n - 1) {
              y->data[nx] = (b_d->data[0] + static_cast<double>(apnd)) / 2.0;
            } else {
              y->data[nx] = b_d->data[0] + static_cast<double>(nx);
              y->data[nx + 1] = apnd - nx;
            }
          }
        }
      }

      i40 = imaxLast->size[0] * imaxLast->size[1];
      imaxLast->size[0] = 1;
      imaxLast->size[1] = y->size[1];
      emxEnsureCapacity_real_T(imaxLast, i40);
      idx = y->size[0] * y->size[1];
      for (i40 = 0; i40 < idx; i40++) {
        imaxLast->data[i40] = y->data[i40];
      }

      iminLast->size[0] = 1;
      iminLast->size[1] = 0;
    }

    emxFree_boolean_T(&c_x);
    emxFree_real_T(&b_d);
    emxInit_creal_T(&r16, 1);

    /* for each element */
    maxct = 0.0;
    minct = 0.0;
    i40 = r16->size[0];
    r16->size[0] = first->size[0];
    emxEnsureCapacity_creal_T(r16, i40);
    idx = first->size[0];
    for (i40 = 0; i40 < idx; i40++) {
      r16->data[i40] = x->data[static_cast<int>(first->data[i40]) - 2];
    }

    emxInit_creal_T(&direction0, 1);
    i40 = direction0->size[0];
    direction0->size[0] = first->size[0];
    emxEnsureCapacity_creal_T(direction0, i40);
    idx = first->size[0];
    for (i40 = 0; i40 < idx; i40++) {
      direction0->data[i40].re = x->data[static_cast<int>(first->data[i40]) - 1]
        .re - r16->data[i40].re;
      direction0->data[i40].im = x->data[static_cast<int>(first->data[i40]) - 1]
        .im - r16->data[i40].im;
    }

    emxFree_creal_T(&r16);
    b_sign(direction0);
    constant = 0.0;
    i40 = static_cast<int>(((last->data[0] + 1.0) + (1.0 - (first->data[0] + 1.0))));
    emxFree_real_T(&last);
    for (absa = 0; absa < i40; absa++) {
      idx = (static_cast<int>(first->data[0]) + absa) + 1;

      /* current trajectory */
      direction.re = x->data[idx - 1].re - x->data[idx - 2].re;
      direction.im = x->data[idx - 1].im - x->data[idx - 2].im;
      c_sign(&direction);

      /* if no change */
      if ((direction.re == 0.0) && (direction.im == 0.0)) {
        constant++;

        /* otherwise */
      } else {
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
              apnd = 1;
            } else {
              apnd = static_cast<int>(ndbl);
            }

            constant = (static_cast<double>(idx) - 1.0) - constant;
            if (static_cast<double>(idx) - 1.0 < constant) {
              y->size[0] = 1;
              y->size[1] = 0;
            } else if (rtIsInf(constant) && (constant == static_cast<double>(idx)
                        - 1.0)) {
              nx = y->size[0] * y->size[1];
              y->size[0] = 1;
              y->size[1] = 1;
              emxEnsureCapacity_real_T(y, nx);
              y->data[0] = rtNaN;
            } else if (constant == constant) {
              nx = y->size[0] * y->size[1];
              y->size[0] = 1;
              idx = static_cast<int>(((static_cast<double>(idx) - 1.0) -
                constant));
              y->size[1] = idx + 1;
              emxEnsureCapacity_real_T(y, nx);
              for (nx = 0; nx <= idx; nx++) {
                y->data[nx] = constant + static_cast<double>(nx);
              }
            } else {
              ndbl = std::floor(((static_cast<double>(idx) - 1.0) - constant) +
                                0.5);
              b_apnd = constant + ndbl;
              cdiff = b_apnd - (static_cast<double>(idx) - 1.0);
              u0 = std::abs(constant);
              u1 = idx - 1;
              if (u0 > u1) {
                u1 = u0;
              }

              if (std::abs(cdiff) < 4.4408920985006262E-16 * u1) {
                ndbl++;
                b_apnd = static_cast<double>(idx) - 1.0;
              } else if (cdiff > 0.0) {
                b_apnd = constant + (ndbl - 1.0);
              } else {
                ndbl++;
              }

              if (ndbl >= 0.0) {
                n = static_cast<int>(ndbl);
              } else {
                n = 0;
              }

              nx = y->size[0] * y->size[1];
              y->size[0] = 1;
              y->size[1] = n;
              emxEnsureCapacity_real_T(y, nx);
              if (n > 0) {
                y->data[0] = constant;
                if (n > 1) {
                  y->data[n - 1] = b_apnd;
                  nx = (n - 1) / 2;
                  for (idx = 0; idx <= nx - 2; idx++) {
                    y->data[1 + idx] = constant + (1.0 + static_cast<double>(idx));
                    y->data[(n - idx) - 2] = b_apnd - (1.0 + static_cast<double>
                      (idx));
                  }

                  if (nx << 1 == n - 1) {
                    y->data[nx] = (constant + b_apnd) / 2.0;
                  } else {
                    y->data[nx] = constant + static_cast<double>(nx);
                    y->data[nx + 1] = b_apnd - static_cast<double>(nx);
                  }
                }
              }
            }

            idx = y->size[1];
            for (nx = 0; nx < idx; nx++) {
              imin->data[(apnd + nx) - 1] = y->data[nx];
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
              apnd = 1;
            } else {
              apnd = static_cast<int>(ndbl);
            }

            constant = (static_cast<double>(idx) - 1.0) - constant;
            if (static_cast<double>(idx) - 1.0 < constant) {
              y->size[0] = 1;
              y->size[1] = 0;
            } else if (rtIsInf(constant) && (constant == static_cast<double>(idx)
                        - 1.0)) {
              nx = y->size[0] * y->size[1];
              y->size[0] = 1;
              y->size[1] = 1;
              emxEnsureCapacity_real_T(y, nx);
              y->data[0] = rtNaN;
            } else if (constant == constant) {
              nx = y->size[0] * y->size[1];
              y->size[0] = 1;
              idx = static_cast<int>(((static_cast<double>(idx) - 1.0) -
                constant));
              y->size[1] = idx + 1;
              emxEnsureCapacity_real_T(y, nx);
              for (nx = 0; nx <= idx; nx++) {
                y->data[nx] = constant + static_cast<double>(nx);
              }
            } else {
              ndbl = std::floor(((static_cast<double>(idx) - 1.0) - constant) +
                                0.5);
              b_apnd = constant + ndbl;
              cdiff = b_apnd - (static_cast<double>(idx) - 1.0);
              u0 = std::abs(constant);
              u1 = idx - 1;
              if (u0 > u1) {
                u1 = u0;
              }

              if (std::abs(cdiff) < 4.4408920985006262E-16 * u1) {
                ndbl++;
                b_apnd = static_cast<double>(idx) - 1.0;
              } else if (cdiff > 0.0) {
                b_apnd = constant + (ndbl - 1.0);
              } else {
                ndbl++;
              }

              if (ndbl >= 0.0) {
                n = static_cast<int>(ndbl);
              } else {
                n = 0;
              }

              nx = y->size[0] * y->size[1];
              y->size[0] = 1;
              y->size[1] = n;
              emxEnsureCapacity_real_T(y, nx);
              if (n > 0) {
                y->data[0] = constant;
                if (n > 1) {
                  y->data[n - 1] = b_apnd;
                  nx = (n - 1) / 2;
                  for (idx = 0; idx <= nx - 2; idx++) {
                    y->data[1 + idx] = constant + (1.0 + static_cast<double>(idx));
                    y->data[(n - idx) - 2] = b_apnd - (1.0 + static_cast<double>
                      (idx));
                  }

                  if (nx << 1 == n - 1) {
                    y->data[nx] = (constant + b_apnd) / 2.0;
                  } else {
                    y->data[nx] = constant + static_cast<double>(nx);
                    y->data[nx + 1] = b_apnd - static_cast<double>(nx);
                  }
                }
              }
            }

            idx = y->size[1];
            for (nx = 0; nx < idx; nx++) {
              imax->data[(apnd + nx) - 1] = y->data[nx];
            }
          }
        }

        /* current trajectory is next iteration previous */
        apnd = direction0->size[0];
        direction0->size[0] = 1;
        emxEnsureCapacity_creal_T(direction0, apnd);
        direction0->data[0] = direction;

        /* no consecutive constant */
        constant = 0.0;
      }
    }

    emxFree_creal_T(&direction0);
    emxFree_real_T(&first);

    /* finish */
    if ((imaxFirst->size[0] != 0) && (imaxFirst->size[1] != 0)) {
      absa = imaxFirst->size[1];
    } else {
      absa = 0;
    }

    emxInitMatrix_cell_wrap_261(reshapes);
    i40 = reshapes[0].f1->size[0] * reshapes[0].f1->size[1];
    reshapes[0].f1->size[0] = 1;
    reshapes[0].f1->size[1] = absa;
    emxEnsureCapacity_real_T(reshapes[0].f1, i40);
    for (i40 = 0; i40 < absa; i40++) {
      reshapes[0].f1->data[i40] = imaxFirst->data[i40];
    }

    emxFree_real_T(&imaxFirst);
    if (imax->size[1] != 0) {
      input_sizes_idx_1 = static_cast<short>(imax->size[1]);
    } else {
      input_sizes_idx_1 = 0;
    }

    i40 = reshapes[1].f1->size[0] * reshapes[1].f1->size[1];
    reshapes[1].f1->size[0] = 1;
    reshapes[1].f1->size[1] = input_sizes_idx_1;
    emxEnsureCapacity_real_T(reshapes[1].f1, i40);
    idx = input_sizes_idx_1;
    for (i40 = 0; i40 < idx; i40++) {
      reshapes[1].f1->data[i40] = imax->data[i40];
    }

    if ((imaxLast->size[0] != 0) && (imaxLast->size[1] != 0)) {
      input_sizes_idx_1 = static_cast<short>(imaxLast->size[1]);
    } else {
      input_sizes_idx_1 = 0;
    }

    i40 = imax->size[0] * imax->size[1];
    imax->size[0] = reshapes[0].f1->size[0];
    imax->size[1] = (reshapes[0].f1->size[1] + reshapes[1].f1->size[1]) +
      input_sizes_idx_1;
    emxEnsureCapacity_real_T(imax, i40);
    idx = reshapes[0].f1->size[1];
    for (i40 = 0; i40 < idx; i40++) {
      nx = reshapes[0].f1->size[0];
      for (apnd = 0; apnd < nx; apnd++) {
        imax->data[apnd + imax->size[0] * i40] = reshapes[0].f1->data[apnd +
          reshapes[0].f1->size[0] * i40];
      }
    }

    idx = reshapes[1].f1->size[1];
    for (i40 = 0; i40 < idx; i40++) {
      nx = reshapes[1].f1->size[0];
      for (apnd = 0; apnd < nx; apnd++) {
        imax->data[apnd + imax->size[0] * (i40 + reshapes[0].f1->size[1])] =
          reshapes[1].f1->data[apnd + reshapes[1].f1->size[0] * i40];
      }
    }

    idx = input_sizes_idx_1;
    for (i40 = 0; i40 < idx; i40++) {
      for (apnd = 0; apnd < 1; apnd++) {
        imax->data[imax->size[0] * ((i40 + reshapes[0].f1->size[1]) + reshapes[1]
          .f1->size[1])] = imaxLast->data[imaxLast->size[0] * i40];
      }
    }

    emxFreeMatrix_cell_wrap_261(reshapes);
    emxFree_real_T(&imaxLast);
    emxInit_boolean_T(&b_y, 2);
    i40 = b_y->size[0] * b_y->size[1];
    b_y->size[0] = imax->size[0];
    b_y->size[1] = imax->size[1];
    emxEnsureCapacity_boolean_T(b_y, i40);
    idx = imax->size[0] * imax->size[1];
    for (i40 = 0; i40 < idx; i40++) {
      b_y->data[i40] = (imax->data[i40] == 0.0);
    }

    c_nullAssignment(imax, b_y);
    i40 = b_max->size[0] * b_max->size[1];
    b_max->size[0] = imax->size[0];
    b_max->size[1] = imax->size[1];
    emxEnsureCapacity_creal_T(b_max, i40);
    idx = imax->size[0] * imax->size[1];
    for (i40 = 0; i40 < idx; i40++) {
      b_max->data[i40] = x->data[static_cast<int>(imax->data[i40]) - 1];
    }

    if (iminFirst->size[1] != 0) {
      absa = iminFirst->size[1];
    } else {
      absa = 0;
    }

    if (imin->size[1] != 0) {
      input_sizes_idx_1 = static_cast<short>(imin->size[1]);
    } else {
      input_sizes_idx_1 = 0;
    }

    if (iminLast->size[1] != 0) {
      b_input_sizes_idx_1 = static_cast<short>(iminLast->size[1]);
    } else {
      b_input_sizes_idx_1 = 0;
    }

    i40 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (absa + input_sizes_idx_1) + b_input_sizes_idx_1;
    emxEnsureCapacity_real_T(y, i40);
    for (i40 = 0; i40 < absa; i40++) {
      for (apnd = 0; apnd < 1; apnd++) {
        y->data[i40] = iminFirst->data[i40];
      }
    }

    emxFree_real_T(&iminFirst);
    idx = input_sizes_idx_1;
    for (i40 = 0; i40 < idx; i40++) {
      for (apnd = 0; apnd < 1; apnd++) {
        y->data[i40 + absa] = imin->data[i40];
      }
    }

    idx = b_input_sizes_idx_1;
    for (i40 = 0; i40 < idx; i40++) {
      for (apnd = 0; apnd < 1; apnd++) {
        y->data[(i40 + absa) + input_sizes_idx_1] = iminLast->data[i40];
      }
    }

    emxFree_real_T(&iminLast);
    i40 = imin->size[0] * imin->size[1];
    imin->size[0] = 1;
    imin->size[1] = y->size[1];
    emxEnsureCapacity_real_T(imin, i40);
    idx = y->size[0] * y->size[1];
    for (i40 = 0; i40 < idx; i40++) {
      imin->data[i40] = y->data[i40];
    }

    i40 = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = y->size[1];
    emxEnsureCapacity_boolean_T(b_y, i40);
    idx = y->size[0] * y->size[1];
    for (i40 = 0; i40 < idx; i40++) {
      b_y->data[i40] = (y->data[i40] == 0.0);
    }

    emxFree_real_T(&y);
    c_nullAssignment(imin, b_y);
    emxFree_boolean_T(&b_y);
    emxFree_real_T(&imin);
  }

  emxFree_creal_T(&d);
}

/* End of code generation (extrema.cpp) */

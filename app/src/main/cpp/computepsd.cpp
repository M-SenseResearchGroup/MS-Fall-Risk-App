/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computepsd.cpp
 *
 * Code generation for function 'computepsd'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "computepsd.h"
#include "calc_fall_risk_emxutil.h"
#include "any1.h"
#include "strcmp.h"

/* Variable Definitions */
static const char cv0[10] = { 'r', 'a', 'd', '/', 's', 'a', 'm', 'p', 'l', 'e' };

/* Function Definitions */
void b_computepsd(const emxArray_creal_T *Sxx1, const double w2_data[], const
                  int w2_size[2], const char range[8], double Fs, const char
                  esttype_data[], const int esttype_size[2], emxArray_creal_T
                  *varargout_1, double varargout_2_data[], int varargout_2_size
                  [1], char varargout_3_data[], int varargout_3_size[2])
{
  emxArray_creal_T *Sxx;
  int i28;
  int loop_ub;
  int i29;
  creal_T Sxx_unscaled_data[2049];
  int b_loop_ub;
  int i30;
  creal_T varargin_3_data[1];
  creal_T y_data[2048];
  int result;
  boolean_T empty_non_axis_sizes;
  signed char input_sizes_idx_0;
  short b_input_sizes_idx_0;
  double Sxx_re;
  double Sxx_im;
  signed char sizes_idx_0;
  boolean_T bv2[2];
  creal_T b_Sxx_unscaled_data[1];
  int b_sizes_idx_0;
  emxInit_creal_T(&Sxx, 2);
  if (c_strcmp(range)) {
    loop_ub = Sxx1->size[1];
    for (i28 = 0; i28 < loop_ub; i28++) {
      for (i29 = 0; i29 < 2049; i29++) {
        Sxx_unscaled_data[i29 + 2049 * i28] = Sxx1->data[i29 + Sxx1->size[0] *
          i28];
      }
    }

    loop_ub = Sxx1->size[1] - 1;
    for (i28 = 0; i28 <= loop_ub; i28++) {
      for (i29 = 0; i29 < 2047; i29++) {
        i30 = i29 + 2047 * i28;
        y_data[i30].re = 2.0 * Sxx_unscaled_data[(i29 + 2049 * i28) + 1].re;
        y_data[i30].im = 2.0 * Sxx_unscaled_data[(i29 + 2049 * i28) + 1].im;
      }
    }

    b_loop_ub = Sxx1->size[1] - 1;
    for (i28 = 0; i28 <= b_loop_ub; i28++) {
      varargin_3_data[i28] = Sxx_unscaled_data[2048 + 2049 * i28];
    }

    i28 = Sxx1->size[1];
    if (i28 != 0) {
      result = Sxx1->size[1];
    } else if (loop_ub + 1 != 0) {
      result = 1;
    } else {
      i28 = Sxx1->size[1];
      if (i28 != 0) {
        result = Sxx1->size[1];
      } else {
        i28 = Sxx1->size[1];
        if (i28 > 0) {
          result = Sxx1->size[1];
        } else {
          result = 0;
        }

        if (loop_ub + 1 > result) {
          result = 1;
        }

        i28 = Sxx1->size[1];
        if (i28 > result) {
          result = Sxx1->size[1];
        }
      }
    }

    empty_non_axis_sizes = (result == 0);
    if (empty_non_axis_sizes) {
      input_sizes_idx_0 = 1;
    } else {
      i28 = Sxx1->size[1];
      if (i28 != 0) {
        input_sizes_idx_0 = 1;
      } else {
        input_sizes_idx_0 = 0;
      }
    }

    if (empty_non_axis_sizes || (loop_ub + 1 != 0)) {
      b_input_sizes_idx_0 = 2047;
    } else {
      b_input_sizes_idx_0 = 0;
    }

    if (empty_non_axis_sizes) {
      sizes_idx_0 = 1;
    } else {
      i28 = Sxx1->size[1];
      if (i28 != 0) {
        sizes_idx_0 = 1;
      } else {
        sizes_idx_0 = 0;
      }
    }

    loop_ub = Sxx1->size[1] - 1;
    for (i28 = 0; i28 <= loop_ub; i28++) {
      b_Sxx_unscaled_data[i28] = Sxx_unscaled_data[2049 * i28];
    }

    b_loop_ub = input_sizes_idx_0;
    loop_ub = b_input_sizes_idx_0;
    b_sizes_idx_0 = sizes_idx_0;
    i28 = Sxx->size[0] * Sxx->size[1];
    i29 = input_sizes_idx_0 + b_input_sizes_idx_0;
    Sxx->size[0] = i29 + sizes_idx_0;
    Sxx->size[1] = result;
    emxEnsureCapacity_creal_T(Sxx, i28);
    for (i28 = 0; i28 < result; i28++) {
      for (i30 = 0; i30 < b_loop_ub; i30++) {
        Sxx->data[Sxx->size[0] * i28] = b_Sxx_unscaled_data[input_sizes_idx_0 *
          i28];
      }
    }

    for (i28 = 0; i28 < result; i28++) {
      for (i30 = 0; i30 < loop_ub; i30++) {
        Sxx->data[(i30 + input_sizes_idx_0) + Sxx->size[0] * i28] = y_data[i30 +
          2047 * i28];
      }
    }

    for (i28 = 0; i28 < result; i28++) {
      for (i30 = 0; i30 < b_sizes_idx_0; i30++) {
        Sxx->data[i29 + Sxx->size[0] * i28] = varargin_3_data[sizes_idx_0 * i28];
      }
    }

    varargout_2_size[0] = 2049;
    memcpy(&varargout_2_data[0], &w2_data[0], 2049U * sizeof(double));
  } else {
    i28 = Sxx->size[0] * Sxx->size[1];
    Sxx->size[0] = Sxx1->size[0];
    Sxx->size[1] = Sxx1->size[1];
    emxEnsureCapacity_creal_T(Sxx, i28);
    loop_ub = Sxx1->size[0] * Sxx1->size[1];
    for (i28 = 0; i28 < loop_ub; i28++) {
      Sxx->data[i28] = Sxx1->data[i28];
    }

    varargout_2_size[0] = w2_size[0];
    if (0 <= w2_size[0] - 1) {
      memcpy(&varargout_2_data[0], &w2_data[0], (unsigned int)(w2_size[0] *
              static_cast<int>(sizeof(double))));
    }
  }

  if (!rtIsNaN(Fs)) {
    i28 = varargout_1->size[0] * varargout_1->size[1];
    varargout_1->size[0] = Sxx->size[0];
    varargout_1->size[1] = Sxx->size[1];
    emxEnsureCapacity_creal_T(varargout_1, i28);
    loop_ub = Sxx->size[0] * Sxx->size[1];
    for (i28 = 0; i28 < loop_ub; i28++) {
      Sxx_re = Sxx->data[i28].re;
      Sxx_im = Sxx->data[i28].im;
      if (Sxx_im == 0.0) {
        varargout_1->data[i28].re = Sxx_re / Fs;
        varargout_1->data[i28].im = 0.0;
      } else if (Sxx_re == 0.0) {
        varargout_1->data[i28].re = 0.0;
        varargout_1->data[i28].im = Sxx_im / Fs;
      } else {
        varargout_1->data[i28].re = Sxx_re / Fs;
        varargout_1->data[i28].im = Sxx_im / Fs;
      }
    }

    varargout_3_size[0] = 1;
    varargout_3_size[1] = 2;
    varargout_3_data[0] = 'H';
    varargout_3_data[1] = 'z';
  } else {
    i28 = varargout_1->size[0] * varargout_1->size[1];
    varargout_1->size[0] = Sxx->size[0];
    varargout_1->size[1] = Sxx->size[1];
    emxEnsureCapacity_creal_T(varargout_1, i28);
    loop_ub = Sxx->size[0] * Sxx->size[1];
    for (i28 = 0; i28 < loop_ub; i28++) {
      Sxx_re = Sxx->data[i28].re;
      Sxx_im = Sxx->data[i28].im;
      if (Sxx_im == 0.0) {
        varargout_1->data[i28].re = Sxx_re / 6.2831853071795862;
        varargout_1->data[i28].im = 0.0;
      } else if (Sxx_re == 0.0) {
        varargout_1->data[i28].re = 0.0;
        varargout_1->data[i28].im = Sxx_im / 6.2831853071795862;
      } else {
        varargout_1->data[i28].re = Sxx_re / 6.2831853071795862;
        varargout_1->data[i28].im = Sxx_im / 6.2831853071795862;
      }
    }

    varargout_3_size[0] = 1;
    varargout_3_size[1] = 10;
    for (i28 = 0; i28 < 10; i28++) {
      varargout_3_data[i28] = cv0[i28];
    }
  }

  b_strcmp(esttype_data, esttype_size, bv2);
  if (any(bv2)) {
    i28 = varargout_1->size[0] * varargout_1->size[1];
    varargout_1->size[0] = Sxx->size[0];
    varargout_1->size[1] = Sxx->size[1];
    emxEnsureCapacity_creal_T(varargout_1, i28);
    loop_ub = Sxx->size[0] * Sxx->size[1];
    for (i28 = 0; i28 < loop_ub; i28++) {
      varargout_1->data[i28] = Sxx->data[i28];
    }
  }

  emxFree_creal_T(&Sxx);
}

void computepsd(const double Sxx1_data[], const int Sxx1_size[2], const double
                w2_data[], const int w2_size[2], const char range[8], double Fs,
                const char esttype_data[], const int esttype_size[2], double
                varargout_1_data[], int varargout_1_size[2], double
                varargout_2_data[], int varargout_2_size[1], char
                varargout_3_data[], int varargout_3_size[2])
{
  int Sxx_size_idx_0;
  int loop_ub;
  int result;
  int i22;
  int i23;
  double Sxx_data[4096];
  double Sxx_unscaled_data[2049];
  double y_data[2048];
  double varargin_3_data[1];
  boolean_T empty_non_axis_sizes;
  signed char input_sizes_idx_0;
  short b_input_sizes_idx_0;
  boolean_T bv1[2];
  signed char sizes_idx_0;
  double b_Sxx_unscaled_data[1];
  int c_input_sizes_idx_0;
  int b_sizes_idx_0;
  int Sxx_size_idx_0_tmp;
  if (c_strcmp(range)) {
    loop_ub = Sxx1_size[1];
    for (i22 = 0; i22 < loop_ub; i22++) {
      for (i23 = 0; i23 < 2049; i23++) {
        Sxx_unscaled_data[i23 + 2049 * i22] = Sxx1_data[i23 + Sxx1_size[0] * i22];
      }
    }

    loop_ub = Sxx1_size[1] - 1;
    for (i22 = 0; i22 <= loop_ub; i22++) {
      for (i23 = 0; i23 < 2047; i23++) {
        y_data[i23 + 2047 * i22] = 2.0 * Sxx_unscaled_data[(i23 + 2049 * i22) +
          1];
      }
    }

    loop_ub = Sxx1_size[1] - 1;
    for (i22 = 0; i22 <= loop_ub; i22++) {
      varargin_3_data[i22] = Sxx_unscaled_data[2048 + 2049 * i22];
    }

    if (Sxx1_size[1] != 0) {
      result = Sxx1_size[1];
    } else if (Sxx1_size[1] != 0) {
      result = 1;
    } else {
      result = 0;
      if (Sxx1_size[1] > 0) {
        result = 1;
      }
    }

    empty_non_axis_sizes = (result == 0);
    if (empty_non_axis_sizes || (Sxx1_size[1] != 0)) {
      input_sizes_idx_0 = 1;
    } else {
      input_sizes_idx_0 = 0;
    }

    if (empty_non_axis_sizes || (Sxx1_size[1] != 0)) {
      b_input_sizes_idx_0 = 2047;
    } else {
      b_input_sizes_idx_0 = 0;
    }

    if (empty_non_axis_sizes || (Sxx1_size[1] != 0)) {
      sizes_idx_0 = 1;
    } else {
      sizes_idx_0 = 0;
    }

    loop_ub = Sxx1_size[1] - 1;
    for (i22 = 0; i22 <= loop_ub; i22++) {
      b_Sxx_unscaled_data[i22] = Sxx_unscaled_data[2049 * i22];
    }

    loop_ub = input_sizes_idx_0;
    c_input_sizes_idx_0 = b_input_sizes_idx_0;
    b_sizes_idx_0 = sizes_idx_0;
    Sxx_size_idx_0_tmp = input_sizes_idx_0 + b_input_sizes_idx_0;
    Sxx_size_idx_0 = Sxx_size_idx_0_tmp + sizes_idx_0;
    for (i22 = 0; i22 < result; i22++) {
      for (i23 = 0; i23 < loop_ub; i23++) {
        Sxx_data[Sxx_size_idx_0 * i22] = b_Sxx_unscaled_data[input_sizes_idx_0 *
          i22];
      }
    }

    for (i22 = 0; i22 < result; i22++) {
      for (i23 = 0; i23 < c_input_sizes_idx_0; i23++) {
        Sxx_data[(i23 + input_sizes_idx_0) + Sxx_size_idx_0 * i22] = y_data[i23
          + 2047 * i22];
      }
    }

    for (i22 = 0; i22 < result; i22++) {
      for (i23 = 0; i23 < b_sizes_idx_0; i23++) {
        Sxx_data[Sxx_size_idx_0_tmp + Sxx_size_idx_0 * i22] =
          varargin_3_data[sizes_idx_0 * i22];
      }
    }

    varargout_2_size[0] = 2049;
    memcpy(&varargout_2_data[0], &w2_data[0], 2049U * sizeof(double));
  } else {
    Sxx_size_idx_0 = Sxx1_size[0];
    result = Sxx1_size[1];
    loop_ub = Sxx1_size[0] * Sxx1_size[1];
    if (0 <= loop_ub - 1) {
      memcpy(&Sxx_data[0], &Sxx1_data[0], (unsigned int)(loop_ub * static_cast<
              int>(sizeof(double))));
    }

    varargout_2_size[0] = w2_size[0];
    if (0 <= w2_size[0] - 1) {
      memcpy(&varargout_2_data[0], &w2_data[0], (unsigned int)(w2_size[0] *
              static_cast<int>(sizeof(double))));
    }
  }

  if (!rtIsNaN(Fs)) {
    varargout_1_size[0] = Sxx_size_idx_0;
    varargout_1_size[1] = result;
    loop_ub = Sxx_size_idx_0 * result;
    for (i22 = 0; i22 < loop_ub; i22++) {
      varargout_1_data[i22] = Sxx_data[i22] / Fs;
    }

    varargout_3_size[0] = 1;
    varargout_3_size[1] = 2;
    varargout_3_data[0] = 'H';
    varargout_3_data[1] = 'z';
  } else {
    varargout_1_size[0] = Sxx_size_idx_0;
    varargout_1_size[1] = result;
    loop_ub = Sxx_size_idx_0 * result;
    for (i22 = 0; i22 < loop_ub; i22++) {
      varargout_1_data[i22] = Sxx_data[i22] / 6.2831853071795862;
    }

    varargout_3_size[0] = 1;
    varargout_3_size[1] = 10;
    for (i22 = 0; i22 < 10; i22++) {
      varargout_3_data[i22] = cv0[i22];
    }
  }

  b_strcmp(esttype_data, esttype_size, bv1);
  if (any(bv1)) {
    varargout_1_size[0] = Sxx_size_idx_0;
    varargout_1_size[1] = result;
    loop_ub = Sxx_size_idx_0 * result;
    if (0 <= loop_ub - 1) {
      memcpy(&varargout_1_data[0], &Sxx_data[0], (unsigned int)(loop_ub *
              static_cast<int>(sizeof(double))));
    }
  }
}

/* End of code generation (computepsd.cpp) */

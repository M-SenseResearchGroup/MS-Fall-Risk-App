/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computepsd.c
 *
 * Code generation for function 'computepsd'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "calibrate.h"
#include "get_calibration.h"
#include "get_classification.h"
#include "get_fall_class.h"
#include "get_features.h"
#include "get_strides.h"
#include "pre_process_feats.h"
#include "computepsd.h"
#include "getFallClass_emxutil.h"
#include "any.h"
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
  int i20;
  int loop_ub;
  int i21;
  static creal_T Sxx_unscaled_data[2049];
  int b_loop_ub;
  int i22;
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
    for (i20 = 0; i20 < loop_ub; i20++) {
      for (i21 = 0; i21 < 2049; i21++) {
        Sxx_unscaled_data[i21 + 2049 * i20] = Sxx1->data[i21 + Sxx1->size[0] *
          i20];
      }
    }

    loop_ub = Sxx1->size[1] - 1;
    for (i20 = 0; i20 <= loop_ub; i20++) {
      for (i21 = 0; i21 < 2047; i21++) {
        i22 = i21 + 2047 * i20;
        y_data[i22].re = 2.0 * Sxx_unscaled_data[(i21 + 2049 * i20) + 1].re;
        y_data[i22].im = 2.0 * Sxx_unscaled_data[(i21 + 2049 * i20) + 1].im;
      }
    }

    b_loop_ub = Sxx1->size[1] - 1;
    for (i20 = 0; i20 <= b_loop_ub; i20++) {
      varargin_3_data[i20] = Sxx_unscaled_data[2048 + 2049 * i20];
    }

    i20 = Sxx1->size[1];
    if (i20 != 0) {
      result = Sxx1->size[1];
    } else if (loop_ub + 1 != 0) {
      result = 1;
    } else {
      i20 = Sxx1->size[1];
      if (i20 != 0) {
        result = Sxx1->size[1];
      } else {
        i20 = Sxx1->size[1];
        if (i20 > 0) {
          result = Sxx1->size[1];
        } else {
          result = 0;
        }

        if (loop_ub + 1 > result) {
          result = 1;
        }

        i20 = Sxx1->size[1];
        if (i20 > result) {
          result = Sxx1->size[1];
        }
      }
    }

    empty_non_axis_sizes = (result == 0);
    if (empty_non_axis_sizes) {
      input_sizes_idx_0 = 1;
    } else {
      i20 = Sxx1->size[1];
      if (i20 != 0) {
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
      i20 = Sxx1->size[1];
      if (i20 != 0) {
        sizes_idx_0 = 1;
      } else {
        sizes_idx_0 = 0;
      }
    }

    loop_ub = Sxx1->size[1] - 1;
    for (i20 = 0; i20 <= loop_ub; i20++) {
      b_Sxx_unscaled_data[i20] = Sxx_unscaled_data[2049 * i20];
    }

    b_loop_ub = input_sizes_idx_0;
    loop_ub = b_input_sizes_idx_0;
    b_sizes_idx_0 = sizes_idx_0;
    i20 = Sxx->size[0] * Sxx->size[1];
    i21 = input_sizes_idx_0 + b_input_sizes_idx_0;
    Sxx->size[0] = i21 + sizes_idx_0;
    Sxx->size[1] = result;
    emxEnsureCapacity_creal_T(Sxx, i20);
    for (i20 = 0; i20 < result; i20++) {
      for (i22 = 0; i22 < b_loop_ub; i22++) {
        Sxx->data[Sxx->size[0] * i20] = b_Sxx_unscaled_data[input_sizes_idx_0 *
          i20];
      }
    }

    for (i20 = 0; i20 < result; i20++) {
      for (i22 = 0; i22 < loop_ub; i22++) {
        Sxx->data[(i22 + input_sizes_idx_0) + Sxx->size[0] * i20] = y_data[i22 +
          2047 * i20];
      }
    }

    for (i20 = 0; i20 < result; i20++) {
      for (i22 = 0; i22 < b_sizes_idx_0; i22++) {
        Sxx->data[i21 + Sxx->size[0] * i20] = varargin_3_data[sizes_idx_0 * i20];
      }
    }

    varargout_2_size[0] = 2049;
    memcpy(&varargout_2_data[0], &w2_data[0], 2049U * sizeof(double));
  } else {
    i20 = Sxx->size[0] * Sxx->size[1];
    Sxx->size[0] = Sxx1->size[0];
    Sxx->size[1] = Sxx1->size[1];
    emxEnsureCapacity_creal_T(Sxx, i20);
    loop_ub = Sxx1->size[0] * Sxx1->size[1];
    for (i20 = 0; i20 < loop_ub; i20++) {
      Sxx->data[i20] = Sxx1->data[i20];
    }

    varargout_2_size[0] = w2_size[0];
    if (0 <= w2_size[0] - 1) {
      memcpy(&varargout_2_data[0], &w2_data[0], (unsigned int)(w2_size[0] * (int)
              sizeof(double)));
    }
  }

  if (!rtIsNaN(Fs)) {
    i20 = varargout_1->size[0] * varargout_1->size[1];
    varargout_1->size[0] = Sxx->size[0];
    varargout_1->size[1] = Sxx->size[1];
    emxEnsureCapacity_creal_T(varargout_1, i20);
    loop_ub = Sxx->size[0] * Sxx->size[1];
    for (i20 = 0; i20 < loop_ub; i20++) {
      Sxx_re = Sxx->data[i20].re;
      Sxx_im = Sxx->data[i20].im;
      if (Sxx_im == 0.0) {
        varargout_1->data[i20].re = Sxx_re / Fs;
        varargout_1->data[i20].im = 0.0;
      } else if (Sxx_re == 0.0) {
        varargout_1->data[i20].re = 0.0;
        varargout_1->data[i20].im = Sxx_im / Fs;
      } else {
        varargout_1->data[i20].re = Sxx_re / Fs;
        varargout_1->data[i20].im = Sxx_im / Fs;
      }
    }

    varargout_3_size[0] = 1;
    varargout_3_size[1] = 2;
    varargout_3_data[0] = 'H';
    varargout_3_data[1] = 'z';
  } else {
    i20 = varargout_1->size[0] * varargout_1->size[1];
    varargout_1->size[0] = Sxx->size[0];
    varargout_1->size[1] = Sxx->size[1];
    emxEnsureCapacity_creal_T(varargout_1, i20);
    loop_ub = Sxx->size[0] * Sxx->size[1];
    for (i20 = 0; i20 < loop_ub; i20++) {
      Sxx_re = Sxx->data[i20].re;
      Sxx_im = Sxx->data[i20].im;
      if (Sxx_im == 0.0) {
        varargout_1->data[i20].re = Sxx_re / 6.2831853071795862;
        varargout_1->data[i20].im = 0.0;
      } else if (Sxx_re == 0.0) {
        varargout_1->data[i20].re = 0.0;
        varargout_1->data[i20].im = Sxx_im / 6.2831853071795862;
      } else {
        varargout_1->data[i20].re = Sxx_re / 6.2831853071795862;
        varargout_1->data[i20].im = Sxx_im / 6.2831853071795862;
      }
    }

    varargout_3_size[0] = 1;
    varargout_3_size[1] = 10;
    for (i20 = 0; i20 < 10; i20++) {
      varargout_3_data[i20] = cv0[i20];
    }
  }

  b_strcmp(esttype_data, esttype_size, bv2);
  if (any(bv2)) {
    i20 = varargout_1->size[0] * varargout_1->size[1];
    varargout_1->size[0] = Sxx->size[0];
    varargout_1->size[1] = Sxx->size[1];
    emxEnsureCapacity_creal_T(varargout_1, i20);
    loop_ub = Sxx->size[0] * Sxx->size[1];
    for (i20 = 0; i20 < loop_ub; i20++) {
      varargout_1->data[i20] = Sxx->data[i20];
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
  int i16;
  int i17;
  static double Sxx_data[4096];
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
    for (i16 = 0; i16 < loop_ub; i16++) {
      for (i17 = 0; i17 < 2049; i17++) {
        Sxx_unscaled_data[i17 + 2049 * i16] = Sxx1_data[i17 + Sxx1_size[0] * i16];
      }
    }

    loop_ub = Sxx1_size[1] - 1;
    for (i16 = 0; i16 <= loop_ub; i16++) {
      for (i17 = 0; i17 < 2047; i17++) {
        y_data[i17 + 2047 * i16] = 2.0 * Sxx_unscaled_data[(i17 + 2049 * i16) +
          1];
      }
    }

    loop_ub = Sxx1_size[1] - 1;
    for (i16 = 0; i16 <= loop_ub; i16++) {
      varargin_3_data[i16] = Sxx_unscaled_data[2048 + 2049 * i16];
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
    for (i16 = 0; i16 <= loop_ub; i16++) {
      b_Sxx_unscaled_data[i16] = Sxx_unscaled_data[2049 * i16];
    }

    loop_ub = input_sizes_idx_0;
    c_input_sizes_idx_0 = b_input_sizes_idx_0;
    b_sizes_idx_0 = sizes_idx_0;
    Sxx_size_idx_0_tmp = input_sizes_idx_0 + b_input_sizes_idx_0;
    Sxx_size_idx_0 = Sxx_size_idx_0_tmp + sizes_idx_0;
    for (i16 = 0; i16 < result; i16++) {
      for (i17 = 0; i17 < loop_ub; i17++) {
        Sxx_data[Sxx_size_idx_0 * i16] = b_Sxx_unscaled_data[input_sizes_idx_0 *
          i16];
      }
    }

    for (i16 = 0; i16 < result; i16++) {
      for (i17 = 0; i17 < c_input_sizes_idx_0; i17++) {
        Sxx_data[(i17 + input_sizes_idx_0) + Sxx_size_idx_0 * i16] = y_data[i17
          + 2047 * i16];
      }
    }

    for (i16 = 0; i16 < result; i16++) {
      for (i17 = 0; i17 < b_sizes_idx_0; i17++) {
        Sxx_data[Sxx_size_idx_0_tmp + Sxx_size_idx_0 * i16] =
          varargin_3_data[sizes_idx_0 * i16];
      }
    }

    varargout_2_size[0] = 2049;
    memcpy(&varargout_2_data[0], &w2_data[0], 2049U * sizeof(double));
  } else {
    Sxx_size_idx_0 = Sxx1_size[0];
    result = Sxx1_size[1];
    loop_ub = Sxx1_size[0] * Sxx1_size[1];
    if (0 <= loop_ub - 1) {
      memcpy(&Sxx_data[0], &Sxx1_data[0], (unsigned int)(loop_ub * (int)sizeof
              (double)));
    }

    varargout_2_size[0] = w2_size[0];
    if (0 <= w2_size[0] - 1) {
      memcpy(&varargout_2_data[0], &w2_data[0], (unsigned int)(w2_size[0] * (int)
              sizeof(double)));
    }
  }

  if (!rtIsNaN(Fs)) {
    varargout_1_size[0] = Sxx_size_idx_0;
    varargout_1_size[1] = result;
    loop_ub = Sxx_size_idx_0 * result;
    for (i16 = 0; i16 < loop_ub; i16++) {
      varargout_1_data[i16] = Sxx_data[i16] / Fs;
    }

    varargout_3_size[0] = 1;
    varargout_3_size[1] = 2;
    varargout_3_data[0] = 'H';
    varargout_3_data[1] = 'z';
  } else {
    varargout_1_size[0] = Sxx_size_idx_0;
    varargout_1_size[1] = result;
    loop_ub = Sxx_size_idx_0 * result;
    for (i16 = 0; i16 < loop_ub; i16++) {
      varargout_1_data[i16] = Sxx_data[i16] / 6.2831853071795862;
    }

    varargout_3_size[0] = 1;
    varargout_3_size[1] = 10;
    for (i16 = 0; i16 < 10; i16++) {
      varargout_3_data[i16] = cv0[i16];
    }
  }

  b_strcmp(esttype_data, esttype_size, bv1);
  if (any(bv1)) {
    varargout_1_size[0] = Sxx_size_idx_0;
    varargout_1_size[1] = result;
    loop_ub = Sxx_size_idx_0 * result;
    if (0 <= loop_ub - 1) {
      memcpy(&varargout_1_data[0], &Sxx_data[0], (unsigned int)(loop_ub * (int)
              sizeof(double)));
    }
  }
}

/* End of code generation (computepsd.c) */

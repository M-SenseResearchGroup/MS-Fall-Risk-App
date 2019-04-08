/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * bluesteinSetup.cpp
 *
 * Code generation for function 'bluesteinSetup'
 *
 */

/* Include files */
#include <cmath>
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "bluesteinSetup.h"
#include "calc_fall_risk_emxutil.h"
#include <string.h>

/* Function Definitions */
void b_bluesteinSetup(int nRows, creal_T wwc_data[], int wwc_size[1])
{
  int nInt2m1;
  int idx;
  int rt;
  int nInt2;
  int k;
  int y;
  double nt_im;
  double nt_re;
  nInt2m1 = (nRows + nRows) - 1;
  wwc_size[0] = nInt2m1;
  idx = nRows;
  rt = 0;
  wwc_data[nRows - 1].re = 1.0;
  wwc_data[nRows - 1].im = 0.0;
  nInt2 = nRows << 1;
  for (k = 0; k <= nRows - 2; k++) {
    y = ((1 + k) << 1) - 1;
    if (nInt2 - rt <= y) {
      rt += y - nInt2;
    } else {
      rt += y;
    }

    nt_im = 3.1415926535897931 * static_cast<double>(rt) / static_cast<double>
      (nRows);
    if (nt_im == 0.0) {
      nt_re = 1.0;
      nt_im = 0.0;
    } else {
      nt_re = std::cos(nt_im);
      nt_im = std::sin(nt_im);
    }

    wwc_data[idx - 2].re = nt_re;
    wwc_data[idx - 2].im = -nt_im;
    idx--;
  }

  idx = 0;
  nInt2m1--;
  for (k = nInt2m1; k >= nRows; k--) {
    wwc_data[k] = wwc_data[idx];
    idx++;
  }
}

void bluesteinSetup(int nRows, emxArray_creal_T *wwc)
{
  int nInt2m1;
  int rt;
  int idx;
  int nInt2;
  int k;
  int y;
  double nt_im;
  double nt_re;
  nInt2m1 = (nRows + nRows) - 1;
  rt = wwc->size[0];
  wwc->size[0] = nInt2m1;
  emxEnsureCapacity_creal_T(wwc, rt);
  idx = nRows;
  rt = 0;
  wwc->data[nRows - 1].re = 1.0;
  wwc->data[nRows - 1].im = 0.0;
  nInt2 = nRows << 1;
  for (k = 0; k <= nRows - 2; k++) {
    y = ((1 + k) << 1) - 1;
    if (nInt2 - rt <= y) {
      rt += y - nInt2;
    } else {
      rt += y;
    }

    nt_im = -3.1415926535897931 * static_cast<double>(rt) / static_cast<double>
      (nRows);
    if (nt_im == 0.0) {
      nt_re = 1.0;
      nt_im = 0.0;
    } else {
      nt_re = std::cos(nt_im);
      nt_im = std::sin(nt_im);
    }

    wwc->data[idx - 2].re = nt_re;
    wwc->data[idx - 2].im = -nt_im;
    idx--;
  }

  idx = 0;
  rt = nInt2m1 - 1;
  for (k = rt; k >= nRows; k--) {
    wwc->data[k] = wwc->data[idx];
    idx++;
  }
}

void c_bluesteinSetup(int nRows, emxArray_creal_T *wwc)
{
  int nInt2m1;
  int rt;
  int idx;
  int nInt2;
  int k;
  int y;
  double nt_im;
  double nt_re;
  nInt2m1 = (nRows + nRows) - 1;
  rt = wwc->size[0];
  wwc->size[0] = nInt2m1;
  emxEnsureCapacity_creal_T(wwc, rt);
  idx = nRows;
  rt = 0;
  wwc->data[nRows - 1].re = 1.0;
  wwc->data[nRows - 1].im = 0.0;
  nInt2 = nRows << 1;
  for (k = 0; k <= nRows - 2; k++) {
    y = ((1 + k) << 1) - 1;
    if (nInt2 - rt <= y) {
      rt += y - nInt2;
    } else {
      rt += y;
    }

    nt_im = 3.1415926535897931 * static_cast<double>(rt) / static_cast<double>
      (nRows);
    if (nt_im == 0.0) {
      nt_re = 1.0;
      nt_im = 0.0;
    } else {
      nt_re = std::cos(nt_im);
      nt_im = std::sin(nt_im);
    }

    wwc->data[idx - 2].re = nt_re;
    wwc->data[idx - 2].im = -nt_im;
    idx--;
  }

  idx = 0;
  rt = nInt2m1 - 1;
  for (k = rt; k >= nRows; k--) {
    wwc->data[k] = wwc->data[idx];
    idx++;
  }
}

/* End of code generation (bluesteinSetup.cpp) */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CompactSVM.c
 *
 * Code generation for function 'CompactSVM'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calibrate.h"
#include "get_calibration.h"
#include "get_classification.h"
#include "get_fall_class.h"
#include "get_features.h"
#include "get_strides.h"
#include "pre_process_feats.h"
#include "CompactSVM.h"
#include "Gaussian.h"
#include "dot.h"
#include <string.h>

/* Function Definitions */
double CompactSVM_score(const double obj_Alpha[1342], const double
  obj_SupportVectorsT[9394], const double Xin[7])
{
  double dv4[1342];
  double dv5[1342];
  double d1;
  int i6;
  dot(obj_SupportVectorsT, obj_SupportVectorsT, dv4);
  Gaussian(obj_SupportVectorsT, dv4, Xin, dv5);
  d1 = 0.0;
  for (i6 = 0; i6 < 1342; i6++) {
    d1 += dv5[i6] * obj_Alpha[i6];
  }

  return d1 + -0.54871226567710851;
}

/* End of code generation (CompactSVM.c) */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pre_process_feats.c
 *
 * Code generation for function 'pre_process_feats'
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

/* Function Definitions */
void pre_process_feats(const double feats1[106], const double mu[106], const
  double sigma[106], const double pc[742], double feats[7])
{
  int i;
  double d[11236];
  double z[106];
  int i4;
  double d0;
  int i5;
  double b_pc[742];

  /*  input: */
  /*    feats - features as row vector */
  /*    mu - feature means */
  /*    sigma - feature SDs */
  /*    pc - principal component mappings */
  /*  output: */
  /*    feats - manipulated features */
  for (i = 0; i < 106; i++) {
    z[i] = 1.0 / sigma[i];
  }

  memset(&d[0], 0, 11236U * sizeof(double));
  for (i = 0; i < 106; i++) {
    d[i + 106 * i] = z[i];
  }

  for (i = 0; i < 7; i++) {
    for (i4 = 0; i4 < 106; i4++) {
      d0 = 0.0;
      for (i5 = 0; i5 < 106; i5++) {
        d0 += pc[i5 + 106 * i] * d[i5 + 106 * i4];
      }

      b_pc[i + 7 * i4] = d0;
    }
  }

  for (i = 0; i < 106; i++) {
    z[i] = feats1[i] - mu[i];
  }

  for (i = 0; i < 7; i++) {
    d0 = 0.0;
    for (i4 = 0; i4 < 106; i4++) {
      d0 += b_pc[i + 7 * i4] * z[i4];
    }

    feats[i] = d0;
  }
}

/* End of code generation (pre_process_feats.c) */

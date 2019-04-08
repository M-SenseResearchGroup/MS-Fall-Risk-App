/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pre_process_feats.cpp
 *
 * Code generation for function 'pre_process_feats'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "pre_process_feats.h"

/* Function Definitions */
void pre_process_feats(const double feats_data[], const double mu[106], const
  double sigma[106], const double pc[742], double feats[7])
{
  int i;
  double d[11236];
  double z[106];
  int i75;
  double d4;
  int i76;
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
    for (i75 = 0; i75 < 106; i75++) {
      d4 = 0.0;
      for (i76 = 0; i76 < 106; i76++) {
        d4 += pc[i76 + 106 * i] * d[i76 + 106 * i75];
      }

      b_pc[i + 7 * i75] = d4;
    }
  }

  for (i = 0; i < 106; i++) {
    z[i] = feats_data[i] - mu[i];
  }

  for (i = 0; i < 7; i++) {
    d4 = 0.0;
    for (i75 = 0; i75 < 106; i75++) {
      d4 += b_pc[i + 7 * i75] * z[i75];
    }

    feats[i] = d4;
  }
}

/* End of code generation (pre_process_feats.cpp) */

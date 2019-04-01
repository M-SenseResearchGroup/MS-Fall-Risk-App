/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * crossing0.c
 *
 * Code generation for function 'crossing0'
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
#include "crossing0.h"
#include <string.h>

/* Function Definitions */
void crossing0(const double x[500])
{
  double sgn0;
  int k;
  double sgn;

  /* Reed Gurchiek, */
  /*    crossing0 finds the zero crossings in the 1D array x. */
  /*  */
  /* ---------------------------INPUTS----------------------------------------- */
  /*  */
  /*    x: */
  /*        1D array */
  /*         */
  /*    type0 (optional): */
  /*        cell array, type of zero crossing.   */
  /*            1) 'p2z': positive to zerO */
  /*            2) 'p2n': positive to negative */
  /*            3) 'z2n': zero to negative */
  /*            4) 'n2z': negative to zero */
  /*            5) 'n2p': negative to positive */
  /*            6) 'z2p': zero to positive */
  /*            7) 'all': 1) through 6) */
  /*                -combos allowed (e.g. type = {'p2n' 'n2p'}); */
  /*  */
  /* --------------------------OUTPUTS----------------------------------------- */
  /*  */
  /*    i: */
  /*        1xp array of zero crossing indices */
  /*  */
  /*    type:  */
  /*        1xp cell array of type of crossing associated with the indices in i */
  /*        (see INPUT type for description of names */
  /*  */
  /* -------------------------------------------------------------------------- */
  /*  crossing0 */
  /* type */
  /* for each sample */
  sgn0 = x[0];
  if (x[0] < 0.0) {
    sgn0 = -1.0;
  } else if (x[0] > 0.0) {
    sgn0 = 1.0;
  } else {
    if (x[0] == 0.0) {
      sgn0 = 0.0;
    }
  }

  for (k = 0; k < 499; k++) {
    /* current sign */
    sgn = x[k + 1];
    if (sgn < 0.0) {
      sgn = -1.0;
    } else if (sgn > 0.0) {
      sgn = 1.0;
    } else {
      if (sgn == 0.0) {
        sgn = 0.0;
      }
    }

    /* if crossed */
    if ((sgn != sgn0) && ((!(sgn0 == 1.0)) || (!(sgn == 0.0))) && ((!(sgn0 ==
           1.0)) || (!(sgn == -1.0))) && ((!(sgn0 == 0.0)) || (!(sgn == -1.0))) &&
        ((!(sgn0 == -1.0)) || (!(sgn == 0.0))) && (sgn0 == -1.0) && (sgn == 1.0))
    {
      /* positive to zero */
      abort();
    } else {
      /* positive to negative */
      /* zero to negative */
      /* negative to zero */
      /* negative to positive */
    }

    /* update previous sign */
    sgn0 = sgn;
  }
}

/* End of code generation (crossing0.c) */

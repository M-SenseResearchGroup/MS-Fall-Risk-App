/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * crossing0.cpp
 *
 * Code generation for function 'crossing0'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "crossing0.h"
#include <string.h>

/* Function Definitions */
void crossing0(const emxArray_real_T *x)
{
  double sgn0;
  int n;
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
  sgn0 = x->data[0];
  if (x->data[0] < 0.0) {
    sgn0 = -1.0;
  } else if (x->data[0] > 0.0) {
    sgn0 = 1.0;
  } else {
    if (x->data[0] == 0.0) {
      sgn0 = 0.0;
    }
  }

  if (x->size[0] == 0) {
    n = -2;
  } else if (x->size[0] > 1) {
    n = x->size[0] - 2;
  } else {
    n = -1;
  }

  for (k = 0; k <= n; k++) {
    /* current sign */
    sgn = x->data[1 + k];
    if (x->data[k + 1] < 0.0) {
      sgn = -1.0;
    } else if (x->data[k + 1] > 0.0) {
      sgn = 1.0;
    } else {
      if (x->data[k + 1] == 0.0) {
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

/* End of code generation (crossing0.cpp) */

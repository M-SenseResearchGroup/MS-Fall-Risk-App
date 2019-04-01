/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * myButter.c
 *
 * Code generation for function 'myButter'
 *
 */

/* Include files */
#include <math.h>
#include "rt_nonfinite.h"
#include "calibrate.h"
#include "get_calibration.h"
#include "get_classification.h"
#include "get_fall_class.h"
#include "get_features.h"
#include "get_strides.h"
#include "pre_process_feats.h"
#include "myButter.h"
#include "poly1.h"
#include <string.h>

/* Function Definitions */
void myButter(double W, double Z[3], double P[3])
{
  double V;
  double re;
  double im;
  creal_T Sp[2];
  creal_T x[2];
  double x_re;
  double x_im;
  double brm;
  double bim;
  double b_x_re;
  double b_x_im;
  creal_T dcv0[3];

  /*  Digital Butterworth filter, either 2 or 3 outputs */
  /*  Jan Simon, 2014, BSD licence */
  /*  See docs of BUTTER for input and output */
  /*  Fast hack with limited accuracy: Handle with care! */
  /*  Until n=15 the relative difference to Matlab's BUTTER is < 100*eps */
  V = tan(W * 1.5707963267948966);

  /*  Bilinear transform: */
  re = V * -0.70710678118654746;
  im = V * 0.70710678118654757;
  Sp[0].re = re;
  Sp[0].im = im;
  x[0].re = 1.0 - re;
  x[0].im = 0.0 - im;
  re = V * -0.70710678118654768;
  im = V * -0.70710678118654746;
  x_re = x[0].re * (1.0 - re) - x[0].im * (0.0 - im);
  x_im = x[0].re * (0.0 - im) + x[0].im * (1.0 - re);
  V *= V;
  if (x_im == 0.0) {
    V /= x_re;
  } else if (x_re == 0.0) {
    if (V == 0.0) {
      V = 0.0 / x_im;
    } else {
      V = 0.0;
    }
  } else {
    brm = fabs(x_re);
    bim = fabs(x_im);
    if (brm > bim) {
      brm = x_im / x_re;
      V = (V + brm * 0.0) / (x_re + brm * x_im);
    } else if (bim == brm) {
      if (x_re > 0.0) {
        b_x_re = 0.5;
      } else {
        b_x_re = -0.5;
      }

      if (x_im > 0.0) {
        b_x_im = 0.5;
      } else {
        b_x_im = -0.5;
      }

      V = (V * b_x_re + 0.0 * b_x_im) / brm;
    } else {
      brm = x_re / x_im;
      V = brm * V / (x_im + brm * x_re);
    }
  }

  /*  From Zeros, Poles and Gain to B (numerator) and A (denominator): */
  Z[0] = V;
  Z[1] = V * 2.0;
  Z[2] = V;
  x_re = 1.0 + Sp[0].re;
  V = 1.0 - Sp[0].re;
  if (0.0 - Sp[0].im == 0.0) {
    if (Sp[0].im == 0.0) {
      Sp[0].re = (1.0 + Sp[0].re) / (1.0 - Sp[0].re);
      Sp[0].im = 0.0;
    } else if (1.0 + Sp[0].re == 0.0) {
      Sp[0].re = 0.0;
      Sp[0].im /= V;
    } else {
      Sp[0].re = (1.0 + Sp[0].re) / (1.0 - Sp[0].re);
      Sp[0].im /= V;
    }
  } else if (1.0 - Sp[0].re == 0.0) {
    if (1.0 + Sp[0].re == 0.0) {
      Sp[0].re = Sp[0].im / (0.0 - Sp[0].im);
      Sp[0].im = 0.0;
    } else if (Sp[0].im == 0.0) {
      Sp[0].re = 0.0;
      Sp[0].im = -(x_re / (0.0 - Sp[0].im));
    } else {
      Sp[0].re = Sp[0].im / (0.0 - Sp[0].im);
      Sp[0].im = -(x_re / (0.0 - Sp[0].im));
    }
  } else {
    brm = fabs(1.0 - Sp[0].re);
    bim = fabs(0.0 - Sp[0].im);
    if (brm > bim) {
      brm = (0.0 - Sp[0].im) / (1.0 - Sp[0].re);
      bim = (1.0 - Sp[0].re) + brm * (0.0 - Sp[0].im);
      Sp[0].re = ((1.0 + Sp[0].re) + brm * Sp[0].im) / bim;
      Sp[0].im = (Sp[0].im - brm * x_re) / bim;
    } else if (bim == brm) {
      if (1.0 - Sp[0].re > 0.0) {
        V = 0.5;
      } else {
        V = -0.5;
      }

      if (0.0 - Sp[0].im > 0.0) {
        bim = 0.5;
      } else {
        bim = -0.5;
      }

      Sp[0].re = ((1.0 + Sp[0].re) * V + Sp[0].im * bim) / brm;
      Sp[0].im = (Sp[0].im * V - x_re * bim) / brm;
    } else {
      brm = (1.0 - Sp[0].re) / (0.0 - Sp[0].im);
      bim = (0.0 - Sp[0].im) + brm * (1.0 - Sp[0].re);
      V = brm * Sp[0].im - (1.0 + Sp[0].re);
      Sp[0].re = (brm * (1.0 + Sp[0].re) + Sp[0].im) / bim;
      Sp[0].im = V / bim;
    }
  }

  if (0.0 - im == 0.0) {
    if (im == 0.0) {
      Sp[1].re = (1.0 + re) / (1.0 - re);
      Sp[1].im = 0.0;
    } else if (1.0 + re == 0.0) {
      Sp[1].re = 0.0;
      Sp[1].im = im / (1.0 - re);
    } else {
      Sp[1].re = (1.0 + re) / (1.0 - re);
      Sp[1].im = im / (1.0 - re);
    }
  } else if (1.0 - re == 0.0) {
    if (1.0 + re == 0.0) {
      Sp[1].re = im / (0.0 - im);
      Sp[1].im = 0.0;
    } else if (im == 0.0) {
      Sp[1].re = 0.0;
      Sp[1].im = -((1.0 + re) / (0.0 - im));
    } else {
      Sp[1].re = im / (0.0 - im);
      Sp[1].im = -((1.0 + re) / (0.0 - im));
    }
  } else {
    brm = fabs(1.0 - re);
    bim = fabs(0.0 - im);
    if (brm > bim) {
      brm = (0.0 - im) / (1.0 - re);
      bim = (1.0 - re) + brm * (0.0 - im);
      Sp[1].re = ((1.0 + re) + brm * im) / bim;
      Sp[1].im = (im - brm * (1.0 + re)) / bim;
    } else if (bim == brm) {
      if (1.0 - re > 0.0) {
        V = 0.5;
      } else {
        V = -0.5;
      }

      if (0.0 - im > 0.0) {
        bim = 0.5;
      } else {
        bim = -0.5;
      }

      Sp[1].re = ((1.0 + re) * V + im * bim) / brm;
      Sp[1].im = (im * V - (1.0 + re) * bim) / brm;
    } else {
      brm = (1.0 - re) / (0.0 - im);
      bim = (0.0 - im) + brm * (1.0 - re);
      Sp[1].re = (brm * (1.0 + re) + im) / bim;
      Sp[1].im = (brm * im - (1.0 + re)) / bim;
    }
  }

  poly(Sp, dcv0);
  P[0] = dcv0[0].re;
  P[1] = dcv0[1].re;
  P[2] = dcv0[2].re;
}

/* End of code generation (myButter.c) */

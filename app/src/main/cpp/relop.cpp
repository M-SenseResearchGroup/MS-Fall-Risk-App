/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * relop.cpp
 *
 * Code generation for function 'relop'
 *
 */

/* Include files */
#include <cmath>
#include <math.h>
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "relop.h"
#include <string.h>

/* Function Definitions */
void c_roundOffMitigatedPhaseAnglePr(const creal_T a, const creal_T b, double *x,
  double *y)
{
  if (*x > 0.78539816339744828) {
    if (*x > 2.3561944901923448) {
      *x = -a.im;
      *y = -b.im;
    } else {
      *x = -a.re;
      *y = -b.re;
    }
  } else if (*x > -0.78539816339744828) {
    *x = a.im;
    *y = b.im;
  } else if (*x > -2.3561944901923448) {
    *x = a.re;
    *y = b.re;
  } else {
    *x = -a.im;
    *y = -b.im;
  }
}

boolean_T iseq(double x, double y)
{
  boolean_T p;
  double absxk;
  int exponent;
  absxk = std::abs(y / 2.0);
  if ((!rtIsInf(absxk)) && (!rtIsNaN(absxk))) {
    if (absxk <= 2.2250738585072014E-308) {
      absxk = 4.94065645841247E-324;
    } else {
      frexp(absxk, &exponent);
      absxk = std::ldexp(1.0, exponent - 53);
    }
  } else {
    absxk = rtNaN;
  }

  if ((std::abs(y - x) < absxk) || (rtIsInf(x) && rtIsInf(y) && ((x > 0.0) == (y
         > 0.0)))) {
    p = true;
  } else {
    p = false;
  }

  return p;
}

void roundOffMitigatedAbsProxies(const creal_T a, const creal_T b, double *x,
  double *y)
{
  double absar;
  double absai;
  double absbr;
  double absbi;
  double Ma;
  absar = std::abs(a.re);
  absai = std::abs(a.im);
  absbr = std::abs(b.re);
  absbi = std::abs(b.im);
  if (absar > absai) {
    Ma = absar;
    absar = absai;
  } else {
    Ma = absai;
  }

  if (absbr > absbi) {
    absai = absbr;
    absbr = absbi;
  } else {
    absai = absbi;
  }

  if (Ma > absai) {
    if (absar < absbr) {
      *x = Ma - absai;
      *y = (absar / 2.0 + absbr / 2.0) / (Ma / 2.0 + absai / 2.0) * (absbr -
        absar);
    } else {
      *x = Ma;
      *y = absai;
    }
  } else if (Ma < absai) {
    if (absar > absbr) {
      *y = absai - Ma;
      *x = (absar / 2.0 + absbr / 2.0) / (Ma / 2.0 + absai / 2.0) * (absar -
        absbr);
    } else {
      *x = Ma;
      *y = absai;
    }
  } else {
    *x = absar;
    *y = absbr;
  }
}

/* End of code generation (relop.cpp) */

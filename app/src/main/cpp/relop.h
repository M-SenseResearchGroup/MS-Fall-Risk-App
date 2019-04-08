/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * relop.h
 *
 * Code generation for function 'relop'
 *
 */

#ifndef RELOP_H
#define RELOP_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "calc_fall_risk_types.h"

/* Function Declarations */
extern void c_roundOffMitigatedPhaseAnglePr(const creal_T a, const creal_T b,
  double *x, double *y);
extern boolean_T iseq(double x, double y);
extern void roundOffMitigatedAbsProxies(const creal_T a, const creal_T b, double
  *x, double *y);

#endif

/* End of code generation (relop.h) */

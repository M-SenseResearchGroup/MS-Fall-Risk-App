/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ifWhileCond.h
 *
 * Code generation for function 'ifWhileCond'
 *
 */

#ifndef IFWHILECOND_H
#define IFWHILECOND_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "calc_fall_risk_types.h"

/* Function Declarations */
extern boolean_T b_ifWhileCond(const emxArray_boolean_T *x);
extern boolean_T c_ifWhileCond(const emxArray_boolean_T *x);
extern boolean_T ifWhileCond(const boolean_T x_data[], const int x_size[3]);

#endif

/* End of code generation (ifWhileCond.h) */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_features.h
 *
 * Code generation for function 'get_features'
 *
 */

#ifndef GET_FEATURES_H
#define GET_FEATURES_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "calc_fall_risk_types.h"

/* Function Declarations */
extern void get_features(const double a1_data[], const double a2_data[], const
  int a2_size[2], double sf, double feat[106]);

#endif

/* End of code generation (get_features.h) */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calc_fall_risk.h
 *
 * Code generation for function 'calc_fall_risk'
 *
 */

#ifndef CALC_FALL_RISK_H
#define CALC_FALL_RISK_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "calc_fall_risk_types.h"

/* Function Declarations */
extern void calc_fall_risk(const double a_thigh1[375], const double
  a_chest1_data[], const int a_chest1_size[2], const double a_thigh2[375], const
  double a_chest2[375], const double a_thigh3[375], const double a_chest3[375],
  const double a_thigh4[375], const double a_chest4[375], const double r_thigh[9],
  double g_thigh, const double r_chest[9], double g_chest, double fs, double
  win_sz, double *classify, double *wrt_str);

#endif

/* End of code generation (calc_fall_risk.h) */

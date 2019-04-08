/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calc_fall_risk_terminate.cpp
 *
 * Code generation for function 'calc_fall_risk_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "calc_fall_risk_terminate.h"
#include "calc_fall_risk_data.h"
#include <string.h>

/* Function Definitions */
void calc_fall_risk_terminate()
{
  omp_destroy_nest_lock(&emlrtNestLockGlobal);
}

/* End of code generation (calc_fall_risk_terminate.cpp) */

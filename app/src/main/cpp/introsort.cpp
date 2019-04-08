/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * introsort.cpp
 *
 * Code generation for function 'introsort'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "introsort.h"
#include "insertionsort.h"
#include <string.h>

/* Function Definitions */
void introsort(int x[4], const cell_wrap_3 cmp_tunableEnvironment[2])
{
  insertionsort(x, cmp_tunableEnvironment);
}

/* End of code generation (introsort.cpp) */

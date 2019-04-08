/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * psdesttype.cpp
 *
 * Code generation for function 'psdesttype'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "psdesttype.h"
#include <string.h>

/* Function Definitions */
void psdesttype(char esttype_data[], int esttype_size[2])
{
  esttype_size[0] = 1;
  esttype_size[1] = 3;
  esttype_data[0] = 'p';
  esttype_data[1] = 's';
  esttype_data[2] = 'd';
}

/* End of code generation (psdesttype.cpp) */

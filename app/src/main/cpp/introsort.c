/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * introsort.c
 *
 * Code generation for function 'introsort'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calibrate.h"
#include "get_calibration.h"
#include "get_classification.h"
#include "get_fall_class.h"
#include "get_features.h"
#include "get_strides.h"
#include "pre_process_feats.h"
#include "introsort.h"
#include "insertionsort.h"
#include <string.h>

/* Function Definitions */
void introsort(int x[4], const cell_wrap_28 cmp_tunableEnvironment[2])
{
  insertionsort(x, cmp_tunableEnvironment);
}

/* End of code generation (introsort.c) */

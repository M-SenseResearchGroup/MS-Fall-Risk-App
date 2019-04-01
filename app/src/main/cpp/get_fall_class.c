/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_fall_class.c
 *
 * Code generation for function 'get_fall_class'
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
#include <string.h>

/* Function Definitions */
double get_fall_class(double feat)
{
  double fall_class;

  /*  input: */
  /*    feat - feature vector for making faller vs, non-faller classification */
  /*           (now just stride time) */
  /*  output: */
  /*    fall_class - classification of window as being measured from faller (1) */
  /*                 or non-faller (0) */
  if (feat < 1.1) {
    /*  completely heuristic classification based on stride time */
    fall_class = 0.0;
  } else {
    fall_class = 1.0;
  }

  return fall_class;
}

/* End of code generation (get_fall_class.c) */

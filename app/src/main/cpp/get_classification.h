/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_classification.h
 *
 * Code generation for function 'get_classification'
 *
 */

#ifndef GET_CLASSIFICATION_H
#define GET_CLASSIFICATION_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "getFallClass_types.h"

/* Function Declarations */
extern void get_classification(const double feats[106], double *label, double
  score[2]);

#endif

/* End of code generation (get_classification.h) */

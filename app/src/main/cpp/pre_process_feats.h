/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pre_process_feats.h
 *
 * Code generation for function 'pre_process_feats'
 *
 */

#ifndef PRE_PROCESS_FEATS_H
#define PRE_PROCESS_FEATS_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "getFallClass_types.h"

/* Function Declarations */
extern void pre_process_feats(const double feats1[106], const double mu[106],
  const double sigma[106], const double pc[742], double feats[7]);

#endif

/* End of code generation (pre_process_feats.h) */

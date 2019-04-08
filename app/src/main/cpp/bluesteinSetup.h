/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * bluesteinSetup.h
 *
 * Code generation for function 'bluesteinSetup'
 *
 */

#ifndef BLUESTEINSETUP_H
#define BLUESTEINSETUP_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "calc_fall_risk_types.h"

/* Function Declarations */
extern void b_bluesteinSetup(int nRows, creal_T wwc_data[], int wwc_size[1]);
extern void bluesteinSetup(int nRows, emxArray_creal_T *wwc);
extern void c_bluesteinSetup(int nRows, emxArray_creal_T *wwc);

#endif

/* End of code generation (bluesteinSetup.h) */

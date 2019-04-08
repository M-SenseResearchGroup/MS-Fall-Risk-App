/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * strcmp.h
 *
 * Code generation for function 'strcmp'
 *
 */

#ifndef STRCMP_H
#define STRCMP_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "calc_fall_risk_types.h"

/* Function Declarations */
extern void b_strcmp(const char a_data[], const int a_size[2], boolean_T b_bool
                     [2]);
extern boolean_T c_strcmp(const char a[8]);

#endif

/* End of code generation (strcmp.h) */

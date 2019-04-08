/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * power.h
 *
 * Code generation for function 'power'
 *
 */

#ifndef POWER_H
#define POWER_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "calc_fall_risk_types.h"

/* Function Declarations */
extern void b_power(const double a_data[], const int a_size[1], double y_data[],
                    int y_size[1]);
extern void c_power(const emxArray_real_T *a, emxArray_real_T *y);
extern void power(const double a_data[], const int a_size[2], double y_data[],
                  int y_size[2]);

#endif

/* End of code generation (power.h) */

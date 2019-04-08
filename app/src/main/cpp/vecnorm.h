/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * vecnorm.h
 *
 * Code generation for function 'vecnorm'
 *
 */

#ifndef VECNORM_H
#define VECNORM_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "calc_fall_risk_types.h"

/* Function Declarations */
extern void vecnorm(const double x_data[], const int x_size[2], double y_data[],
                    int y_size[2]);

#endif

/* End of code generation (vecnorm.h) */

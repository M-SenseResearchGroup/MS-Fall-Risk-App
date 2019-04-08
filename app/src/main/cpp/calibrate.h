/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calibrate.h
 *
 * Code generation for function 'calibrate'
 *
 */

#ifndef CALIBRATE_H
#define CALIBRATE_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "calc_fall_risk_types.h"

/* Function Declarations */
extern void calibrate(const double x_data[], const int x_size[2], const double
                      r[9], double g, double y_data[], int y_size[2]);

#endif

/* End of code generation (calibrate.h) */

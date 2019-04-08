/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Gaussian.h
 *
 * Code generation for function 'Gaussian'
 *
 */

#ifndef GAUSSIAN_H
#define GAUSSIAN_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "calc_fall_risk_types.h"

/* Function Declarations */
extern void Gaussian(const double svT[9394], const double svInnerProduct[1342],
                     const double x[7], double kernelProduct[1342]);

#endif

/* End of code generation (Gaussian.h) */

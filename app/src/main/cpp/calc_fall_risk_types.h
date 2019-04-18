/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calc_fall_risk_types.h
 *
 * Code generation for function 'calc_fall_risk'
 *
 */

#ifndef CALC_FALL_RISK_TYPES_H
#define CALC_FALL_RISK_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  double Alpha[1342];
  double Bias;
  double SupportVectorsT[9394];
  double Scale;
  double Order;
  char KernelFunction[8];
  double ClassNames[2];
  int ClassNamesLength[2];
  double Prior[2];
  boolean_T ClassLogicalIndices[2];
  double Cost[4];
  double ScoreTransformArguments[2];
} c_classreg_learning_coder_class;

struct emxArray_real_T
{
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

struct sBkRI2z8EyIABVFEX9ocIJF_tag
{
  emxArray_real_T *f1;
};

typedef sBkRI2z8EyIABVFEX9ocIJF_tag cell_wrap_26;
typedef struct {
  int f1[4];
} cell_wrap_3;

struct emxArray_boolean_T
{
  boolean_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

typedef struct {
  real_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_real_T;

typedef struct {
  uint8_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_uint8_T;

struct emxArray_int32_T
{
  int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif

/* End of code generation (calc_fall_risk_types.h) */

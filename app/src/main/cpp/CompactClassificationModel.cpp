/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CompactClassificationModel.cpp
 *
 * Code generation for function 'CompactClassificationModel'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "CompactClassificationModel.h"
#include <string.h>

/* Function Definitions */
void c_CompactClassificationModel_Co(c_classreg_learning_coder_class *obj)
{
  obj->ClassNames[0] = -1.0;
  obj->ClassNamesLength[0] = 1;
  obj->ClassLogicalIndices[0] = true;
  obj->ClassNames[1] = 1.0;
  obj->ClassNamesLength[1] = 1;
  obj->ClassLogicalIndices[1] = true;
  obj->ScoreTransformArguments[0] = -4.328987;
  obj->ScoreTransformArguments[1] = -0.8446414;
}

/* End of code generation (CompactClassificationModel.cpp) */

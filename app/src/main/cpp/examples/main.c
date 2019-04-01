/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * main.c
 *
 * Code generation for function 'main'
 *
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include files */
#include "rt_nonfinite.h"
#include "calibrate.h"
#include "get_calibration.h"
#include "get_classification.h"
#include "get_fall_class.h"
#include "get_features.h"
#include "get_strides.h"
#include "pre_process_feats.h"
#include "main.h"
#include "getFallClass_terminate.h"
#include "getFallClass_initialize.h"
#include <string.h>

/* Function Declarations */
static void argInit_106x1_real_T(double result[106]);
static void argInit_106x7_real_T(double result[742]);
static void argInit_3x125_real_T(double result[375]);
static void argInit_3x313_real_T(double result[939]);
static void argInit_3x3_real_T(double result[9]);
static void argInit_3x500_real_T(double result[1500]);
static double argInit_real_T(void);
static void main_calibrate(void);
static void main_get_calibration(void);
static void main_get_classification(void);
static void main_get_fall_class(void);
static void main_get_features(void);
static void main_get_strides(void);
static void main_pre_process_feats(void);

/* Function Definitions */
static void argInit_106x1_real_T(double result[106])
{
  int idx0;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 106; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

static void argInit_106x7_real_T(double result[742])
{
  int idx0;
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 106; idx0++) {
    for (idx1 = 0; idx1 < 7; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[idx0 + 106 * idx1] = argInit_real_T();
    }
  }
}

static void argInit_3x125_real_T(double result[375])
{
  int idx0;
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 3; idx0++) {
    for (idx1 = 0; idx1 < 125; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[idx0 + 3 * idx1] = argInit_real_T();
    }
  }
}

static void argInit_3x313_real_T(double result[939])
{
  int idx0;
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 3; idx0++) {
    for (idx1 = 0; idx1 < 313; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[idx0 + 3 * idx1] = argInit_real_T();
    }
  }
}

static void argInit_3x3_real_T(double result[9])
{
  int idx0;
  double result_tmp;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 3; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result_tmp = argInit_real_T();
    result[idx0] = result_tmp;

    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0 + 3] = result_tmp;

    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0 + 6] = argInit_real_T();
  }
}

static void argInit_3x500_real_T(double result[1500])
{
  int idx0;
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 3; idx0++) {
    for (idx1 = 0; idx1 < 500; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[idx0 + 3 * idx1] = argInit_real_T();
    }
  }
}

static double argInit_real_T(void)
{
  return 0.0;
}

static void main_calibrate(void)
{
  double dv13[375];
  double dv14[9];
  double y[375];

  /* Initialize function 'calibrate' input arguments. */
  /* Initialize function input argument 'x'. */
  /* Initialize function input argument 'r'. */
  /* Call the entry-point 'calibrate'. */
  argInit_3x125_real_T(dv13);
  argInit_3x3_real_T(dv14);
  calibrate(dv13, dv14, argInit_real_T(), y);
}

static void main_get_calibration(void)
{
  double dv15[939];
  double r[9];
  double g;

  /* Initialize function 'get_calibration' input arguments. */
  /* Initialize function input argument 'a'. */
  /* Call the entry-point 'get_calibration'. */
  argInit_3x313_real_T(dv15);
  get_calibration(dv15, argInit_real_T(), r, &g);
}

static void main_get_classification(void)
{
  double dv16[106];
  double label;
  double score[2];

  /* Initialize function 'get_classification' input arguments. */
  /* Initialize function input argument 'feats'. */
  /* Call the entry-point 'get_classification'. */
  argInit_106x1_real_T(dv16);
  get_classification(dv16, &label, score);
}

static void main_get_fall_class(void)
{
  double fall_class;

  /* Initialize function 'get_fall_class' input arguments. */
  /* Call the entry-point 'get_fall_class'. */
  fall_class = get_fall_class(argInit_real_T());
}

static void main_get_features(void)
{
  double a1_tmp[375];
  double feat[106];

  /* Initialize function 'get_features' input arguments. */
  /* Initialize function input argument 'a1'. */
  argInit_3x125_real_T(a1_tmp);

  /* Initialize function input argument 'a2'. */
  /* Call the entry-point 'get_features'. */
  get_features(a1_tmp, a1_tmp, argInit_real_T(), feat);
}

static void main_get_strides(void)
{
  double dv17[1500];
  double stride_vars;

  /* Initialize function 'get_strides' input arguments. */
  /* Initialize function input argument 'thigh_acc'. */
  /* Call the entry-point 'get_strides'. */
  argInit_3x500_real_T(dv17);
  stride_vars = get_strides(dv17, argInit_real_T());
}

static void main_pre_process_feats(void)
{
  double feats1_tmp_tmp[106];
  double dv18[742];
  double feats[7];

  /* Initialize function 'pre_process_feats' input arguments. */
  /* Initialize function input argument 'feats1'. */
  argInit_106x1_real_T(feats1_tmp_tmp);

  /* Initialize function input argument 'mu'. */
  /* Initialize function input argument 'sigma'. */
  /* Initialize function input argument 'pc'. */
  /* Call the entry-point 'pre_process_feats'. */
  argInit_106x7_real_T(dv18);
  pre_process_feats(feats1_tmp_tmp, feats1_tmp_tmp, feats1_tmp_tmp, dv18, feats);
}

int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  getFallClass_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_calibrate();
  main_get_calibration();
  main_get_classification();
  main_get_fall_class();
  main_get_features();
  main_get_strides();
  main_pre_process_feats();

  /* Terminate the application.
     You do not need to do this more than one time. */
  getFallClass_terminate();
  return 0;
}

/* End of code generation (main.c) */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * main.cpp
 *
 * Code generation for function 'main'
 *
 */

/*************************************************************************/
/* This automatically generated example C++ main file shows how to call  */
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
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "main.h"
#include "calc_fall_risk_terminate.h"
#include "calc_fall_risk_initialize.h"
#include <string.h>

/* Function Declarations */
static void argInit_3x125_real_T(double result[375]);
static void argInit_3x313_real_T(double result[939]);
static void argInit_3x3_real_T(double result[9]);
static void argInit_3xd313_real_T(double result_data[], int result_size[2]);
static double argInit_real_T();
static void main_calc_fall_risk();
static void main_get_calibration();

/* Function Definitions */
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

static void argInit_3xd313_real_T(double result_data[], int result_size[2])
{
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result_size[0] = 3;
  result_size[1] = 2;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 2; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result_data[3 * idx1] = argInit_real_T();
  }

  for (idx1 = 0; idx1 < 2; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result_data[1 + 3 * idx1] = argInit_real_T();
  }

  for (idx1 = 0; idx1 < 2; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result_data[2 + 3 * idx1] = argInit_real_T();
  }
}

static double argInit_real_T()
{
  return 0.0;
}

static void main_calc_fall_risk()
{
  double a_thigh1_tmp[375];
  double a_chest1_data[939];
  int a_chest1_size[2];
  double a_thigh2[375];
  double a_chest2[375];
  double dv11[375];
  double dv12[375];
  double dv13[375];
  double dv14[375];
  double dv15[9];
  double dv16[9];
  double classify;
  double wrt_str;

  /* Initialize function 'calc_fall_risk' input arguments. */
  /* Initialize function input argument 'a_thigh1'. */
  argInit_3x125_real_T(a_thigh1_tmp);

  /* Initialize function input argument 'a_chest1'. */
  argInit_3xd313_real_T(a_chest1_data, a_chest1_size);

  /* Initialize function input argument 'a_thigh2'. */
  argInit_3x125_real_T(a_thigh2);

  /* Initialize function input argument 'a_chest2'. */
  argInit_3x125_real_T(a_chest2);

  /* Initialize function input argument 'a_thigh3'. */
  /* Initialize function input argument 'a_chest3'. */
  /* Initialize function input argument 'a_thigh4'. */
  /* Initialize function input argument 'a_chest4'. */
  /* Initialize function input argument 'r_thigh'. */
  /* Initialize function input argument 'r_chest'. */
  /* Initialize function input argument 'thigh_buffer'. */
  /* Initialize function input argument 'chest_buffer'. */
  /* Call the entry-point 'calc_fall_risk'. */
  argInit_3x125_real_T(dv11);
  argInit_3x125_real_T(dv12);
  argInit_3x125_real_T(dv13);
  argInit_3x125_real_T(dv14);
  argInit_3x3_real_T(dv15);
  argInit_3x3_real_T(dv16);
  calc_fall_risk(a_thigh1_tmp, a_chest1_data, a_chest1_size, a_thigh2, a_chest2,
                 dv11, dv12, dv13, dv14, dv15, argInit_real_T(), dv16,
                 argInit_real_T(), argInit_real_T(), argInit_real_T(), &classify,
                 &wrt_str);
}

static void main_get_calibration()
{
  double dv17[939];
  double r[9];
  double g;

  /* Initialize function 'get_calibration' input arguments. */
  /* Initialize function input argument 'a'. */
  /* Call the entry-point 'get_calibration'. */
  argInit_3x313_real_T(dv17);
  get_calibration(dv17, argInit_real_T(), r, &g);
}

int main(int, const char * const [])
{
  /* Initialize the application.
     You do not need to do this more than one time. */
  calc_fall_risk_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_calc_fall_risk();
  main_get_calibration();

  /* Terminate the application.
     You do not need to do this more than one time. */
  calc_fall_risk_terminate();
  return 0;
}

/* End of code generation (main.cpp) */

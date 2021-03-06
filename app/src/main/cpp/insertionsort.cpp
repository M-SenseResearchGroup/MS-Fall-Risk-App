/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * insertionsort.cpp
 *
 * Code generation for function 'insertionsort'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "insertionsort.h"
#include <string.h>

/* Function Definitions */
void insertionsort(int x[4], const cell_wrap_3 cmp_tunableEnvironment[2])
{
  int xc;
  int idx;
  boolean_T exitg1;
  int i99;
  xc = x[1] - 1;
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx + 1 >= 1)) {
    i99 = cmp_tunableEnvironment[0].f1[x[idx] - 1];
    if ((cmp_tunableEnvironment[0].f1[xc] < i99) || ((cmp_tunableEnvironment[0].
          f1[xc] == i99) && (cmp_tunableEnvironment[1].f1[xc] <
          cmp_tunableEnvironment[1].f1[x[idx] - 1]))) {
      x[idx + 1] = x[idx];
      idx--;
    } else {
      exitg1 = true;
    }
  }

  x[idx + 1] = xc + 1;
  xc = x[2] - 1;
  idx = 1;
  exitg1 = false;
  while ((!exitg1) && (idx + 1 >= 1)) {
    i99 = cmp_tunableEnvironment[0].f1[x[idx] - 1];
    if ((cmp_tunableEnvironment[0].f1[xc] < i99) || ((cmp_tunableEnvironment[0].
          f1[xc] == i99) && (cmp_tunableEnvironment[1].f1[xc] <
          cmp_tunableEnvironment[1].f1[x[idx] - 1]))) {
      x[idx + 1] = x[idx];
      idx--;
    } else {
      exitg1 = true;
    }
  }

  x[idx + 1] = xc + 1;
  xc = x[3] - 1;
  idx = 2;
  exitg1 = false;
  while ((!exitg1) && (idx + 1 >= 1)) {
    i99 = cmp_tunableEnvironment[0].f1[x[idx] - 1];
    if ((cmp_tunableEnvironment[0].f1[xc] < i99) || ((cmp_tunableEnvironment[0].
          f1[xc] == i99) && (cmp_tunableEnvironment[1].f1[xc] <
          cmp_tunableEnvironment[1].f1[x[idx] - 1]))) {
      x[idx + 1] = x[idx];
      idx--;
    } else {
      exitg1 = true;
    }
  }

  x[idx + 1] = xc + 1;
}

/* End of code generation (insertionsort.cpp) */

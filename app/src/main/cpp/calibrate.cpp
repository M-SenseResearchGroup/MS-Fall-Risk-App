/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calibrate.cpp
 *
 * Code generation for function 'calibrate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "calibrate.h"
#include <string.h>

/* Function Definitions */
void calibrate(const double x_data[], const int x_size[2], const double r[9],
               double g, double y_data[], int y_size[2])
{
  int n;
  int j;
  int coffset;
  int boffset;
  int k;
  int aoffset;
  double temp;

  /*  input: */
  /*    x - data to calibrate */
  /*    r - sensor 2 body dcm */
  /*    g - gravity magnitude */
  /*  output: */
  /*    y - calibrated data */
  n = x_size[1];
  y_size[1] = x_size[1];
  for (j = 0; j < n; j++) {
    coffset = j * 3;
    boffset = j * 3;
    y_data[coffset] = 0.0;
    y_data[coffset + 1] = 0.0;
    y_data[coffset + 2] = 0.0;
    for (k = 0; k < 3; k++) {
      aoffset = k * 3;
      temp = x_data[boffset + k];
      y_data[coffset] += temp * r[aoffset];
      y_data[coffset + 1] += temp * r[aoffset + 1];
      y_data[coffset + 2] += temp * r[aoffset + 2];
    }
  }

  y_size[0] = 3;
  n = 3 * x_size[1] - 1;
  for (j = 0; j <= n; j++) {
    y_data[j] /= g;
  }
}

/* End of code generation (calibrate.cpp) */

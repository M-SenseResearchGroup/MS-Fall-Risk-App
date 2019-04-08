/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * strcmp.cpp
 *
 * Code generation for function 'strcmp'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "strcmp.h"

/* Function Definitions */
void b_strcmp(const char a_data[], const int a_size[2], boolean_T b_bool[2])
{
  int loop_ub;
  char t0_f1_data[8];
  int exitg1;
  static const char cv4[128] = { '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
    '\x06', '\x07', '\x08', '\x09', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e',
    '\x0f', '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17',
    '\x18', '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!',
    '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?',
    '@', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '[', '\\', ']',
    '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{',
    '|', '}', '~', '\x7f' };

  static const char cv5[2] = { 'm', 's' };

  static const char cv6[5] = { 'p', 'o', 'w', 'e', 'r' };

  loop_ub = a_size[0] * a_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&t0_f1_data[0], &a_data[0], (unsigned int)(loop_ub * static_cast<int>
            (sizeof(char))));
  }

  b_bool[0] = false;
  if (a_size[1] == 2) {
    loop_ub = 0;
    do {
      exitg1 = 0;
      if (loop_ub < 2) {
        if (cv4[static_cast<unsigned char>(t0_f1_data[loop_ub])] !=
            cv4[static_cast<int>(cv5[loop_ub])]) {
          exitg1 = 1;
        } else {
          loop_ub++;
        }
      } else {
        b_bool[0] = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  b_bool[1] = false;
  if (a_size[1] == 5) {
    loop_ub = 0;
    do {
      exitg1 = 0;
      if (loop_ub < 5) {
        if (cv4[static_cast<unsigned char>(t0_f1_data[loop_ub])] !=
            cv4[static_cast<int>(cv6[loop_ub])]) {
          exitg1 = 1;
        } else {
          loop_ub++;
        }
      } else {
        b_bool[1] = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
}

boolean_T c_strcmp(const char a[8])
{
  int ret;
  static const char b[8] = { 'o', 'n', 'e', 's', 'i', 'd', 'e', 'd' };

  ret = memcmp(&a[0], &b[0], 8);
  return ret == 0;
}

/* End of code generation (strcmp.cpp) */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sparse1.cpp
 *
 * Code generation for function 'sparse1'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calc_fall_risk.h"
#include "get_calibration.h"
#include "sparse1.h"
#include <string.h>
#include "solve_from_lu.h"
#include "makeCXSparseMatrix.h"
#include "solve_from_qr.h"

/* Type Definitions */
#include "cs.h"

/* Function Definitions */
void sparse_mldivide(const emxArray_real_T *A_d, const emxArray_int32_T
                     *A_colidx, const emxArray_int32_T *A_rowidx, double b[2])
{
  cs_di* cxA;
  cs_dis * S;
  cs_din * N;
  double tol;
  cxA = makeCXSparseMatrix(A_colidx->data[A_colidx->size[0] - 1] - 1, 2, 2,
    &A_colidx->data[0], &A_rowidx->data[0], &A_d->data[0]);
  S = cs_di_sqr(2, cxA, 0);
  N = cs_di_lu(cxA, S, 1);
  cs_di_spfree(cxA);
  if (N == NULL) {
    cs_di_sfree(S);
    cs_di_nfree(N);
    cxA = makeCXSparseMatrix(A_colidx->data[A_colidx->size[0] - 1] - 1, 2, 2,
      &A_colidx->data[0], &A_rowidx->data[0], &A_d->data[0]);
    S = cs_di_sqr(2, cxA, 1);
    N = cs_di_qr(cxA, S);
    cs_di_spfree(cxA);
    qr_rank_di(N, &tol);
    solve_from_qr_di(N, S, (double *)&b[0], 2, 2);
    cs_di_sfree(S);
    cs_di_nfree(N);
  } else {
    solve_from_lu_di(N, S, (double *)&b[0], 2);
    cs_di_sfree(S);
    cs_di_nfree(N);
  }
}

/* End of code generation (sparse1.cpp) */

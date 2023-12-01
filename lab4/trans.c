/*
 * CSE 351 Lab 4 (Caches and Cache-Friendly Code)
 * Part 2 - Optimizing Matrix Transpose
 *
 * Name(s):  
 * NetID(s): 
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[M][N], int B[N][M]);
 * and compute B = A^T.
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1 KiB direct mapped cache with a block size of 32 bytes.
 */

#include <stdio.h>
#include "support/cachelab.h"

int is_transpose(int M, int N, int A[M][N], int B[N][M]);


/*
 * transpose_submit - This is the transpose function that you will be graded
 *     on. Do not change the description string "Transpose submission", as the
 *     driver searches for that string to identify the transpose function to be
 *     graded.
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[M][N], int B[N][M]) {
  if (M == 32) {
    for(int i = 0; i < M; i+=8){
      for(int j = 0; j < N; j+=8){
        for(int ii = i; ii < i+8; ii++){
          int temp1 = A[j][ii];
          int temp2 = A[j+1][ii];
          int temp3 = A[j+2][ii];
          int temp4 = A[j+3][ii];
          int temp5 = A[j+4][ii];
          int temp6 = A[j+5][ii];
          int temp7 = A[j+6][ii];
          int temp8 = A[j+7][ii];

          B[ii][j] = temp1;
          B[ii][j+1] = temp2;
          B[ii][j+2] = temp3;
          B[ii][j+3] = temp4;
          B[ii][j+4] = temp5;
          B[ii][j+5] = temp6;
          B[ii][j+6] = temp7;
          B[ii][j+7] = temp8;
        }
      }
    }
  } else { // M = 64
    int i,j,column;
    for(i = 0; i < M; i+=4){
      for(j = 0; j < N; j+=4){
        for(column = i; column < i+4; column++){
          int temp1 = A[j][column];
          int temp2 = A[j+1][column];
          int temp3 = A[j+2][column];
          int temp4 = A[j+3][column];

          B[column][j] = temp1;
          B[column][j+1] = temp2;
          B[column][j+2] = temp3;
          B[column][j+3] = temp4;
        }
      }
    }
  }
}


// You can define additional transpose functions below. We've defined a simple
// one below to help you get started.

/*
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[M][N], int B[N][M]) {
    int i, j, tmp;

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }

}


/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions() {
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc);

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc);

}


/*
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[M][N], int B[N][M]) {
    int i, j;

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

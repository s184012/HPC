#include <stdlib.h>
#include "matrix_fns.h"

double** dmalloc_2d(int rows, int cols) {
    if (rows <= 0 || cols <= 0) return NULL;
    double **A = malloc(rows * sizeof(double*));
    if (A == NULL) return NULL;
    A[0] = malloc(rows*cols*sizeof(double));
    if (A[0] == NULL) {
        free(A);
        return NULL;
    }
    for (int i = 1; i < rows; i++)
        A[i] = A[0] + i * cols;
    return A;
}

double** dcalloc_2d(int rows, int cols) {
    if (rows <= 0 || cols <= 0) return NULL;
    double **A = malloc(rows * sizeof(double*));
    if (A == NULL) return NULL;
    A[0] = calloc(rows*cols, sizeof(double));
    if (A[0] == NULL) {
        free(A);
        return NULL;
    }
    for (int i = 1; i < rows; i++)
        A[i] = A[0] + i * cols;
    return A;
}

void dfree_2d(double **A) {
    free(A[0]);
    free(A);
}

double** mat_sum(double** A, double** B, int rows, int cols)
{
    double** C = NULL;
    C = dmalloc_2d(rows, cols);
    for (int row = 0; row < rows; ++row){
        for (int col = 0; col < cols; ++col){
            C[row][col] = A[row][col] + B[row][col];
        }
    }
    return C;
}

double* mat_vec(double** A, double* v, int rows, int cols)
{
    double* x = NULL;
    x = malloc(rows * sizeof(double));
    for (int row = 0; row < rows; ++row){
        for (int col = 0; col < cols; ++col){
            x[row] += A[row][col] * v[col];
        }
    }
    return x;
}

double** mat_mat(double** A, double** B, int left_dim, int inner_dim, int right_dim)
{
    double** C = NULL;
    C = dcalloc_2d(left_dim, right_dim);
    for (int m = 0; m < left_dim; ++m){
        for (int n = 0; n < right_dim; ++n){
            for (int k = 0; k < inner_dim; ++k){
                C[m][n] += A[m][k] * B[k][n];
            }
        }
    }

    return C;
}


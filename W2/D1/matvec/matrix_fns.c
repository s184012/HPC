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

double* mat_vec(double** A, double* v, int rows, int cols)
{
    double* x = NULL;
    double sum;
    x = malloc(rows * sizeof(double));
    
    #pragma omp parallel for default(none)\
                shared(rows, cols, A, v, x)\
                private(sum)
    for (int row = 0; row < rows; ++row){
        sum = 0.0;
        for (int col = 0; col < cols; ++col){
            sum += A[row][col] * v[col];
        }
        x[row] = sum;
    }
    return x;
}


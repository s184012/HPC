#ifndef _MATRIX_FNS_
#define _MATRIX_FNS_

double** mat_sum(double** A, double** B, int rows, int cols); // Adds two matrices together
double* mat_vec(double** A, double* v, int rows, int cols); // Matrix vector product
double** mat_mat(double** A, double** B, int left_dim, int inner_dim, int right_dim); // Matrix-matrix product
double** dmalloc_2d(int m, int n); // Allocate space for 2d matrix
double** dcalloc_2d(int rows, int cols); // Allocate space and initialize to 0
void dfree_2d(double** matrix);
#endif
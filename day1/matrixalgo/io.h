#ifndef _IO_
#define _IO_

#include <stdio.h>
int read_vector(double* v, size_t size, const char* filename);
int read_matrix(size_t rows, size_t cols, double** A, const char* filename);
void print_matrix(int rows, int cols, double** A);
void print_vector(double* v, int size);
#endif

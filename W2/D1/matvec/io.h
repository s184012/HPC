#ifndef _IO_
#define _IO_

#include <stdio.h>
double* read_vector(const char* filename, int size);
double** read_matrix(const char* filename, int rows, int cols);
void print_matrix(double** A, int rows, int cols);
void print_vector(double* v, int size);
#endif

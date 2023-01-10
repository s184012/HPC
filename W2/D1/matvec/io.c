#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "matrix_fns.h"

double** read_matrix(const char* filename, int rows, int cols)
{

    FILE *pf;
    pf = fopen (filename, "r");
    if (pf == NULL)
        return NULL;

    double** A;
    A = dmalloc_2d(rows, cols);
    for(size_t i = 0; i < rows; ++i)
    {
        for(size_t j = 0; j < cols; ++j)
            fscanf(pf, "%lf", &A[i][j]);
    }

    fclose (pf); 
    return A; 
}

double* read_vector(const char* filename, int size)
{
    FILE *pf;
    pf = fopen(filename, "r");
    if (pf == NULL)
        return NULL;
    
    double* v;
    v = malloc(size*sizeof(double));
    for (size_t i = 0; i < size; ++i){
        fscanf(pf, "%lf", &v[i]);
    }
    fclose(pf);
    return v;
}

void print_matrix(double** A, int rows, int cols){
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            printf("%.2lf  ", A[i][j]);
        }
        printf("\n");
    }
}

void print_vector(double* v, int size)
{
    for (int i = 0; i < size; ++i)
        printf("%.2lf\n", v[i]);
}


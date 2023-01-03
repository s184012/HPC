#include <stdio.h>
#include <stdlib.h>
#include "io.h"

int read_matrix(size_t rows, size_t cols, double** A, const char* filename)
{

    FILE *pf;
    pf = fopen (filename, "r");
    if (pf == NULL)
        return 0;

    for(size_t i = 0; i < rows; ++i)
    {
        for(size_t j = 0; j < cols; ++j)
            fscanf(pf, "%lf", &A[i][j]);
    }


    fclose (pf); 
    return 1; 
}

int read_vector(double* v, size_t size, const char* filename)
{
    FILE *pf;
    pf = fopen(filename, "r");
    if (pf == NULL)
        return 0;
    
    for (size_t i = 0; i < size; ++i){
        fscanf(pf, "%lf", &v[i]);
    }
    fclose(pf);
}

void print_matrix(int rows, int cols, double** A){
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


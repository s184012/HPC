#include <stdlib.h>
#include "io.h"
#include "matrix_fns.h"
#include "test.h"


int main(int argc, char const *argv[])
{
    const char* filename_A = argv[1];
    const char* filename_B = argv[2];
    const char* filename_v = argv[3];

    char* ptr = NULL;
    long rows=0;
    long cols=0;

    rows = strtol(argv[4], &ptr, 10);
    cols = strtol(argv[5], &ptr, 10);

    double** A;
    double** B;
    double** C;
    double* v;
    double* x;

    A = dmalloc_2d(rows, cols);
    B = dmalloc_2d(rows, cols);
    v = malloc(cols * sizeof(double));
    read_matrix(rows, cols, A, filename_A);
    read_matrix(rows, cols, B, filename_B);
    read_vector(v, cols, filename_v);

    C = mat_sum(A, B, rows, cols);
    x = mat_vec(A, v, rows, cols);

    printf("dim= %ldx%ld\nFilename1 = %s\nFilename2 = %s\n", rows, cols, filename_A, filename_B);
    print_matrix(rows, cols, A);
    print_matrix(rows, cols, B);
    print_matrix(rows, cols, C);
    print_vector(v, cols);
    print_vector(x, rows);

    dfree_2d(B);
    dfree_2d(A);
    dfree_2d(C);

    test_mat_mat();

    return 0;
}

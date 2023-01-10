#include "matrix_fns.h"
#include "io.h"
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if (argc != 5)
        printf("Hey!\n");
        return 1;
    
    double** A;
    double* v;
    int rows, cols;

    rows = strtol(argv[1], NULL, 10);
    cols = strtol(argv[2], NULL, 10);

    A = read_matrix(argv[3], rows, cols);
    v = read_vector(argv[4], cols);

    print_matrix(A, rows, cols);
    return 0;
}

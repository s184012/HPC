#include <stdlib.h>
#include "io.h"
#include "matrix_fns.h"
#include <cblas.h>

int test_mat_mat(void)
{
    double** A = NULL;
    double** B = NULL;
    int m = 3;
    int n = 2;
    int k = 5;

    A = dmalloc_2d(m, k);
    for (int i = 0; i < m; ++i){
        for (size_t j = 0; j < k; j++)
        {
            A[i][j] = 10.0*(i+1) + (j+1);
        }
        
    }

    B = dmalloc_2d(k, n);
    for (int i = 0; i < k; ++i){
        for (size_t j = 0; j < n; j++)
        {
            B[i][j] = 20.0*(i+1) + (j+1);
        }
        
    }

    double** C = NULL;
    C = mat_mat(A, B, m, k, n);

    printf("TEST MAT-MAT\n\n");
    print_matrix(m, n, C);

    dfree_2d(C);
    dfree_2d(B);
    dfree_2d(A);

    return 0;


}


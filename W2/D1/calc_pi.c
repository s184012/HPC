#include <stdlib.h>
#include <stdio.h>
#include <time.h>

double calc_pi(int n);
double integrand(int i, double n_inv);
double sqr(double x);

int main(int argc, char const *argv[])
{
    if (argc != 2)
        return 1;
    
    int n = 0;
    double pi = 0.0;
    time_t tic, toc;


    n = strtol(argv[1], NULL, 10);
    tic = time(NULL);
    pi = calc_pi(n);
    toc = time(NULL);
    printf("%lf\n%lf\n", pi, difftime(toc, tic));
    return 0;
}

double calc_pi(int n)
{
    double sum = 0.0;
    double n_inv = 1/(double)n;
    int i = 0;
    #pragma omp parallel for default(none) \
    shared(n, n_inv) private(i) reduction(+: sum)
    for (i = 1; i <= n; i++)
        sum += integrand(i, n_inv);
    sum *= n_inv;
    return sum;

}

double integrand(int i, double n_inv)
{
    return 4 / (1 + sqr(i-0.5)*sqr(n_inv));
}

double sqr(double x){
    return x * x;
}
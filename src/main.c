#include "prime.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #define PARALLEL

#ifdef PARALLEL
#include <omp.h>
#endif

int main(int argc, char const *argv[])
{
    int range = 20000000;
    int t;
    double time;

    int *primeList;

#ifdef PARALLEL
    time = omp_get_wtime();
#endif
    int primeCount = getPrimeList(range, &primeList);
#ifdef PARALLEL
    time = omp_get_wtime() - time;
    printf("%f\n", time);
#endif

    int diff = 0, pos = 0;

#ifdef PARALLEL
    int threads = 8;
    if (argc == 2)
        threads = atoi(argv[1]);
    time = omp_get_wtime();
#endif
#pragma omp parallel for num_threads(threads) private(t) shared(diff, pos)
    for (int i = 0; i < primeCount - 1; i++)
    {
        t = primeList[i + 1] - primeList[i];
        // #pragma omp critical
        if (t > diff)
        {
            diff = t;
            pos = i;
        }
    }
    /*#else
    for (int i = 0; i < primeCount - 1; i++)
    {
        t = primeList[i + 1] - primeList[i];
        if (t > diff)
        {
            diff = t;
            pos = i;
        }
    }
#endif*/
#ifdef PARALLEL
    time = omp_get_wtime() - time;
    printf("%f\n", time);
#endif

    printf("%d %d\n", primeList[pos], primeList[pos + 1]);

    return 0;
}
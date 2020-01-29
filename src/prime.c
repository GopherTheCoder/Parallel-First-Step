// #include "prime.h"
#include <stdbool.h>
#include <malloc.h>
#include <memory.h>

int getPrimeList(int n, int **list)
{
    int *res = malloc(n / 2 * sizeof(int));
    int primeCount = 0;
    bool *isPrime = malloc(n + 1);
    memset(isPrime, true, n + 1);

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
            res[primeCount++] = i;

        for (int j = 0; j < primeCount; j++)
        {
            if (i * res[j] > n)
                break;
            isPrime[i * res[j]] = false;
            if (i % res[j] == 0)
                break;
        }
    }

    *list = realloc(res, primeCount * sizeof(int));
    return primeCount;
}
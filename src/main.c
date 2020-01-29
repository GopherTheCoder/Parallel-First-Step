#include "prime.h"
#include <malloc.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int range;

    if (argc == 1)
        range = 20000000;
    else if (sscanf(argv[1], "%d", &range) != 1 || range < 3 || range > 20000000)
    {
        printf("Invaild argument! please input a integer between 3 and 20000000.\n");
        return 1;
    }

    int *primeList;
    int primeCount = getPrimeList(range, &primeList);

    int *diffList = malloc((primeCount - 1) * sizeof(int));
    int diff = 0, pos = 0;
    for (int i = 0; i < primeCount - 1; i++)
    {
        int t = primeList[i + 1] - primeList[i];
        if (t > diff)
        {
            diff = t;
            pos = i;
        }
    }

    printf("%d %d\n", primeList[pos], primeList[pos + 1]);

    return 0;
}
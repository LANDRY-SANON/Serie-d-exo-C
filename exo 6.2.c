#include <stdio.h>


int main()
{
    int i,j,n,k, si, sj;
    printf("N: "); scanf("%d", &n);
    for (i = 2; i < n; i++)
    {
        // calcul de si
         si=1;    
        for ( k = 2; k <i; k++)
        {
           
            if (i % k == 0)
               si += k;
        };
           // calcul de sj
        for ( j = i; j < n; j++)
        {
                     sj=1;    
        for ( k = 2; k <j; k++)
        {
           
            if (j % k == 0)
               sj += k;
        };
            if (si != j || sj != i)
                continue;
            printf("(%d, %d)\n", i, j);
        }
    }

}
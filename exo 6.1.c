 
#include <stdio.h>


int main()
{
    int i,j,n, m, sn,q,r;
    printf("entrer la multiplicité: "); scanf("%d", &m);
    printf("nombre a ne pas depasser: "); scanf("%d", &n);
    for (i = 6; i < n; i++)
    {
// calcul de sn
         r=1;    
        for ( j = 2; j <=i; j++)
        {
           
            if (i % j == 0)
               r += j;
        };
     
      q = r / i;
        if (q == m)
            printf("%d\n", i);
    }
  
}
 
#include <stdio.h>

double main()
{
int n;
double q=0.0, pi=2.0;
printf(" precission  :");
scanf("%d",&n);   
  for (int i=0; i<n; ++i) {
    q = sqrt(2.0+q);
    pi *= 2.0/q;
  }
printf("%f  :" ,pi);  
}   

//il es precis au dela de 10^6

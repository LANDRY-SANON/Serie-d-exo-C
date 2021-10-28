 
#include <stdio.h>

double main()
{
int n;
 double p, pi=2.0;
printf("  precision ");
scanf("%d",&n);   
for (int i=2; i<=n; i+=2) 
 pi *= ((p=i)/(i-1))*(p/(i+1));
printf("%f  :" ,pi);  
}   

//il es precis au dela de 10^6

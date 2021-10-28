 
#include <stdio.h>

double main()
{
int n;
double pi=1.0,num=1.0,den=1.0; 
printf("precission :");
scanf("%d",&n);   
  for (int i=1; i<n; ++i) {
    num *= i;
    den *= (2*i+1);
    pi += num/den;
  }
printf("%f  :" ,2*pi);  
}   

  


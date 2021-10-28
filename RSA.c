#include <stdio.h>
 
int pgcd(int a , int b)
{
      int r,x,y;

      if (a>b)
      {
          x=b;
          r=a%b;
      }
      else
      {
          x=a;
          r=b%a;
      }

      while(r!=0)
      {
                 y=x;
                 x=r;
                 r=y%x;          
      }
      printf("%d",x);
      return 0;
}
 

int main()
{
    int        p, q, e,u;
    long long  n, phi;
    printf("P: ");
    scanf("%d", &p);
    printf("Q: ");
    scanf("%d", &q);
    printf("E: ");
    scanf("%d", &e);
    n   = p*q;
    phi = (p-1)*(q-1);

    while (pgcd(e, phi) != 1)
        e++;

    while (u < 0)
        u += phi;
    u %= phi;
    printf("clé publique (%d, %d)\n", e, n);
    printf("clé privée (%d, %d)\n", u, n);}
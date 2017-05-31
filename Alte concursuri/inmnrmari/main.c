#include <stdio.h>

int V[3000],m,n,i,V1[3000];

void putere(int V[3000],long m)
{
  long Trans=0,i;

  for (i=1;i<=V[0];i++) {
      V[i]=V[i]*m+Trans;
      Trans=V[i]/10;
      V[i]%=10;
    }

  while (Trans!=0) {
      V[++V[0]]=Trans%10;
      Trans/=10;
    }
}

void a(int V1[3000])
{
    V1[0]=1;
    V1[1]=2;
    printf("2 la 3001: ");
    for (i=2;i<=3001;++i)
        putere(V1,2);
    for (i=V1[0];i>=1;--i)
        printf("%d",V1[i]);
    printf("\n");
}

int main()
{
    a(V1);
    printf("Introduceti numarul m: ");
    scanf ("%d",&m);
    printf("Introduceti numarul n: ");
    scanf ("%d",&n);

    if (n==0)
            printf("Rezultatul este: 1");

    else {
    V[0]=1;
    V[1]=m;

    for (i=2;i<=n;++i)
        putere(V,m);

    printf("Rezultatul este: ");
    for (i=V[0];i>=1;--i)
        printf("%d",V[i]);
    }

    return 0;
}

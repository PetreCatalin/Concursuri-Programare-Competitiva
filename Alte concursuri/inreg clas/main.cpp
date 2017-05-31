#include <cstdio>
#include <cstring>

using namespace std;

typedef struct{
       char s[100];
       int n1,n2;
       double m;
}nume;

nume a[100],aux;
int i,n,j;

int main()
{
       freopen("inc.in","r",stdin);
       freopen("inc.out","w",stdout);
       scanf("%d",&n);
       for (i=1;i<=n;i++) {
              scanf("%s%d%d",&a[i].s,&a[i].n1,&a[i].n2);
              a[i].m=(a[i].n1+a[i].n2)/2;
       }
       for (i=1;i<=n-1;i++)
              for (j=i+1;j<=n;j++)
              if (a[i].m<a[j].m) {
                     aux=a[i];
                     a[i]=a[j];
                     a[j]=aux;
              }
       for (i=1;i<=n;i++)
       printf("%s\n",a[i].s);

       fclose(stdin);
       fclose(stdout);
    return 0;
}

#include <cstdio>
#include <cstring>

using namespace std;

typedef struct{
       char s[4];
       int n;
}nume;

nume a[200000],aux;
int i,j,x,k;
char s[10];

int main()
{
       freopen("seti.in","r",stdin);
       freopen("seti.out","w",stdout);
       scanf("%s",&s);
       x=0;
       while (!feof(stdin)) {
              x++;
              scanf("%s",&a[x].s);
       }
       --x;
       for (i=1;i<=x;i++)
              for (j=0;j<=strlen(a[i].s)-1;j++)
                     for (k=0;k<=9;k++)
                            if (a[i].s[j]==s[k]) {a[i].n=a[i].n*10+k;break;}
       for (i=1;i<=x-1;i++)
              for (j=i+1;j<=x;j++)
              if (a[i].n>a[j].n) {
                     aux=a[i];
                     a[i]=a[j];
                     a[j]=aux;
              }
       for (i=1;i<=x;i++) {
              for (j=0;j<=3;j++)
              printf("%c",a[i].s[j]);
       printf("\n");
       }
       fclose(stdin);
       fclose(stdout);
    return 0;
}

#include <cstdio>
#include <cstring>

using namespace std;

char s[100];
int i,j,n,m,nr,b[100],a[100][100],maxim;

int main()
{
       freopen ("pentagon.in","r",stdin);
       freopen ("pentagon.out","w",stdout);
       scanf("%d%d",&n,&m);
       for (i=1;i<=n;i++) {
              scanf("%s",&s);
              for (j=0;j<=strlen(s)-1;j++) {
                     if (s[j]=='1')
                     a[i][j+1]=1; else a[i][j]=0;
              }
       }
       for (i=1;i<=m;i++)
       a[n+1][i]=1;
       maxim=0;
       for (i=1;i<=m;i++){
              nr=0;
              for (j=1;j<=n;j++)
                     if (a[j][i]==0)
                     {nr++;        if (a[j+1][i]==1)
                                   {b[nr]++;if (nr>maxim) maxim=nr; nr=0;}
                     }
       }
       for (i=1;i<=maxim;i++)
       if (b[i]!=0) printf("%d %d\n",i ,b[i]);
       fclose(stdin);
       fclose(stdout);
    return 0;
}

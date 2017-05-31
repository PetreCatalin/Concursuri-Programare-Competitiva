#include <cstdio>
#include <cstring>

using namespace std;

char s1[504],s2[504];
long int n,m,i,j,a[504][504];

long int minim(long int x,long int y,long int z)
{
    if (x<=y &&x<=z) return x;
    if (y<=x &&y<=z) return y;
    if (z<=x &&z<=y) return z;
}

int main()
{
    freopen ("siruri2.in","r",stdin);
    freopen ("siruri2.out","w",stdout);
    gets(s1);
    gets(s2);
    n=strlen(s1);
    m=strlen(s2);

    for (i=0;i<=n;i++)
    a[0][i]=i;
    for (i=0;i<=m;i++)
    a[i][0]=i;

    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) {
        if (s1[i-1]==s2[j-1]) a[i][j]=a[i-1][j-1];
        else
        a[i][j]=1+minim(a[i-1][j-1],a[i-1][j],a[i][j-1]);
        }

    printf("%d",a[n][m]);

    fclose(stdin);
    fclose(stdout);
    return 0;
}

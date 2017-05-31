#include <cstdio>
#include <cstring>

using namespace std;

long int n,m,k,a[20005][20005],i,j;
char s1[20005],s2[20005];

long int minim(long int x,long int y,long int z)
{
    if (x<=y &&x<=z) return x;
    if (y<=x&&y<=z) return y;
    if (z<=x &&z<=y) return z;
}

int main()
{
    freopen ("edist.in","r",stdin);
    freopen ("edist.out","w",stdout);
    scanf("%d%d%d\n",&n,&m,&k);
    gets(s1);
    gets(s2);
    for (i=0;i<=strlen(s1);i++)
    a[0][i]=i;
    for (i=0;i<=strlen(s2);i++)
    a[i][0]=i;

    for (i=1;i<=strlen(s1);i++)
        for (j=1;j<=strlen(s2);j++) {
        if (s1[i-1]==s2[j-1]) a[i][j]=a[i-1][j-1];
        else
        a[i][j]=minim(a[i-1][j],a[i][j-1],a[i-1][j-1])+1;
        }

    printf("%d",a[strlen(s1)][strlen(s2)]);

    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include <fstream>
#include <cstring>

using namespace std;

char s[205];
long int nr,a[205],b[205],i,n1,n2,j,m[205][205],v1[205],x,y,k;

long int maxim(long int x,long int y)
{
    if (x>y) return x;
    else
    return y;
}

int main()
{
    freopen("codul.in","r",stdin);
    freopen("codul.out","w",stdout);
        gets(s);
        n1=strlen(s);
        for (i=0;i<=n1-1;i++)
        a[i+1]=s[i]-'0';
        gets(s);
        n2=strlen(s);
        for (i=0;i<=n2-1;i++)
        b[i+1]=s[i]-'0';

    for (i=1;i<=n1;i++)
    for (j=1;j<=n2;j++) {
        if (a[i]==b[j]) m[i][j]=m[i-1][j-1]+1;
        else
        m[i][j]=maxim(m[i][j-1],m[i-1][j]);
    }

    nr=m[n1][n2];k=n1;
    x=n1;y=n2;n1=0;
    while (n1<nr) {
        if (a[x]==b[y]) {n1++;v1[n1]=a[x];--x;--y;}
        else {
        if (m[x-1][y]==m[x][y]) --x;
        else
        if (m[x][y-1]==m[x][y]) --y;
        }
    }

    for (i=1;i<=k;i++) {
        for (j=1;j<=n2;j++)
        printf("%d ",m[i][j]);
        printf("\n");
    }

    for (i=nr;i>=1;--i)
    printf("%d",v1[i]);

    fclose(stdin);
    fclose(stdout);
    return 0;
}

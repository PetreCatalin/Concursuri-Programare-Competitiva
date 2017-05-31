#include <fstream>

using namespace std;

long int maxim(long int x,long int y)
{
    if (x>=y) return x;
    else return y;
}

long int a[100],b[100],x[100][100],i,j,n,m,v1[100],k,nr;

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>n;
    for (i=1;i<=n;i++)
    f>>a[i];
    f>>m;
    for (i=1;i<=m;i++)
    f>>b[i];

    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) {
        if (a[i]==b[j]) x[i][j]=1+x[i-1][j-1];
            else
            x[i][j]=maxim(x[i][j-1],x[i-1][j]);
        }

    g<<x[n][m]<<'\n';

   /* for (i=1;i<=n;i++) {
        for (j=1;j<=m;j++)
        g<<x[i][j]<<' ';
        g<<'\n';
    } */

    i=n;j=m;nr=0;
    while (nr<x[n][m]) {
        if (a[i]==b[j]) {nr++;v1[nr]=a[i];--i;--j;}
        else {
            if (x[i-1][j]==x[i][j]) --i;
            else
            --j;
        }
    }

    for (i=nr;i>=1;--i)
    g<<v1[i]<<' ';

    f.close();
    g.close();
    return 0;
}

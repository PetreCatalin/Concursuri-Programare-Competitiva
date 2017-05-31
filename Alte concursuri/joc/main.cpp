#include <fstream>

using namespace std;

long int i,j,n,m,a[104][104],b[104][104],c[104][104];

long int maxim(long int x,long int y)
{
    if (x>y) return x;
    else
    return y;
}

int main()
{
    ifstream f("joc.in");
    ofstream g("joc.out");
    f>>n>>m;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
        f>>a[i][j];

    for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
    b[i][j]=a[i][j]+maxim(b[i-1][j],b[i][j-1]);

    for (i=1;i<=n;i++)
    for (j=m;j>=1;--j)
    c[i][j]=a[i][j]+maxim(c[i-1][j],c[i][j+1]);

    if (b[n][m]>c[n][1]) {g<<'1'<<' '<<b[n][m];}
    if (b[n][m]<c[n][1]) {g<<'2'<<' '<<c[n][1];}
    if (b[n][m]==c[n][1]) {g<<'3'<<' '<<b[n][m];}

    f.close();
    g.close();
    return 0;
}

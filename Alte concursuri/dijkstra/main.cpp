#include <fstream>

using namespace std;

long int a[100][100],i,j,x,y,c,n,m,v[100];

int main()
{
    ifstream f("dijkstra.in");
    ofstream g("dijkstra.out");
    f>>n>>m;
    for (i=1;i<=m;i++) {
        f>>x>>y>>c;
        a[x][y]=c;
    }
    for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    if (a[i][j]==0) a[i][j]=10000;

    for (i=2;i<=n;i++) {
    if (a[1][i]!=10000) v[i]=a[1][i];
    else
    v[i]=10000;
    }

    for (i=2;i<=n;i++)
    for (j=2;j<=n;j++)
    if (v[j]>v[i]+a[i][j]) v[j]=v[i]+a[i][j];

    for (i=1;i<=n;i++) {
        if (v[i]!=10000) g<<v[i]<<' ';
        else g<<"NU EXISTA DRUM"<<' ';
    }

    f.close();
    g.close();
    return 0;
}

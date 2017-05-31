#include <fstream>

using namespace std;

int m,k,q,i,x,y,put,t,j,n,a[100][100],b1[100][100],s[100][100],b[100][100];

int main()
{
    ifstream f("drumuri3.in");
    ofstream g("drumuri3.out");
    f>>n>>m>>k>>q;

    for (i=1;i<=m;++i) {
        f>>x>>y;
        a[x][y]=1;
        a[y][x]=1;
        b[x][y]=1;
        b[y][x]=1;
        s[x][y]=1;
        s[y][x]=1;
    }

    for (put=2;put<=k-1;++put) {
        for (i=1;i<=n;++i)
            for (j=1;j<=n;++j)
                for (t=1;t<=n;++t)
                b1[i][j]=(b1[i][j]+(a[i][t]*b[t][j])%10007)%10007;

        for (i=1;i<=n;++i)
            for (j=1;j<=n;++j) {
                b[i][j]=b1[i][j];b1[i][j]=0;
                s[i][j]=(s[i][j]+b[i][j])%10007;
            }
    }

   for (i=1;i<=q;++i) {
        f>>x>>y;
        g<<s[x][y]%10007<<'\n';
    }

    f.close();
    g.close();
    return 0;
}

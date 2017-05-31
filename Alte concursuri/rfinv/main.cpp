#include <fstream>

using namespace std;

#define MAX 1000000

long r,t,i,m,n,v1[1255],v2[1255],a[52][52],j,k,ok,b[52][52];

int main()
{
    ifstream f("rfinv.in");
    ofstream g("rfinv.out");
    f>>t;
    for (r=1;r<=t;++r) {
        f>>n>>m;
        for (i=1;i<=m;++i)
            f>>v1[i]>>v2[i];
        for (i=1;i<=n;++i)
            for (j=1;j<=n;++j)
                f>>a[i][j];

        for (i=1;i<=n;++i)
            for (j=1;j<=n;++j)
                if (i!=j &&b[i][j]!=MAX) b[i][j]=MAX;

        for (i=1;i<=m;++i) {
            b[v1[i]][v2[i]]=a[v1[i]][v2[i]];
            b[v2[i]][v1[i]]=a[v2[i]][v1[i]];
        }

        for (k=1;k<=n;++k)
            for (i=1;i<=n;++i)
                for (j=1;j<=n;++j)
                    if (b[i][j]>b[i][k]+b[k][j])
                        b[i][j]=b[i][k]+b[k][j];

        ok=1;
        for (i=1;i<=n;++i)
            for (j=1;j<=n;++j)
                if (b[i][j]!=a[i][j]) {ok=0;break;}

        if (ok==1) g<<"DA"<<'\n';
        else
        g<<"NU"<<'\n';
    }

    f.close();
    g.close();
    return 0;
}

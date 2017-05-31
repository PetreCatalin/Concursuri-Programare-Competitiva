#include <fstream>

using namespace std;

int n,m,ok,i,x,y,viz[255],a[255][255];

void df(int x)
    {
        int i;
        viz[x]=1;
        for (i=1;i<=n;i++)
            if (a[x][i]==1 &&viz[i]==0) df(i);
    }

int main()
{
    ifstream f("daisy.in");
    ofstream g("daisy.out");
    f>>n>>m;
    for (i=1;i<=m;i++) {
        f>>x>>y;
        a[x][y]=1;
        a[y][x]=1;
    }

    df(1);

    ok=0;
    for (i=1;i<=n;i++)
        if (viz[i]==0) {g<<i<<'\n';ok=1;}

    if (ok==0) g<<'0';

    f.close();
    g.close();
    return 0;
}

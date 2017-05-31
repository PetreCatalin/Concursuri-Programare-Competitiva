#include <fstream>

using namespace std;

long int i,j,a[100][100],n,m,v[100],x,y;
bool ok;

void df(int k)
{
    int i;
    v[k]=1;
    for (i=1;i<=n;i++)
        if (a[k][i]==1) {
            a[i][k]=0;
            if (v[i]==1) ok=false;
            if (v[i]==0) df(i);
        }
}

int main()
{
    ifstream f("vc.in");
    ofstream g("vc.out");
    f>>n>>m;
    for (i=1;i<=m;i++) {
        f>>x>>y;
        a[x][y]=1;
        a[y][x]=1;
    }

    ok=true;
    df(1);
    if (ok==true) g<<"nu are cicluri";
    else
    g<<"are cicluri";

    f.close();
    g.close();
    return 0;
}

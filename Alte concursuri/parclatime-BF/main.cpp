#include <fstream>

using namespace std;

bool ok;
long int i,j,x,y,n,m,stiva[1000],st,dr,dr1,viz[1000],a[100][100];

int main()
{
    ifstream f("parclatime.in");
    ofstream g("parclatime.out");
    f>>n>>m;
    for (i=1;i<=m;i++) {
        f>>x>>y;
        a[x][y]=1;
        a[y][x]=1;
    }

    st=1;dr=1;x=0;stiva[1]=1;viz[1]=1;

    ok=true;
    while (ok==true) {
        ok=false;
        dr1=dr;
        x++;
        g<<"nivelul "<<x<<": ";
        for (i=st;i<=dr;i++) g<<stiva[i]<<' ';
        g<<'\n';
    while (st<=dr) {
        y=stiva[st];
        for (i=1;i<=n;i++)
            if (a[y][i]==1 &&viz[i]==0) {
                ok=true;
                viz[i]=1;
                dr1++;
                stiva[dr1]=i;
            }
        st++;
    }
    st=dr+1;
    dr=dr1;
    }


    f.close();
    g.close();
    return 0;
}

//un graf e eulerian daca e conex si gradul oricarui nod este numar par

#include <fstream>

using namespace std;

bool ok,ok1;
long int i,j,x,y,n,m,a[100][100],v[100],nr;

void df(int x)
{
    int i;
    v[x]=1;
    for (i=1;i<=n;i++)
        if (v[i]==0 &&a[x][i]==1) df(i);
}

int main()
{
    ifstream f("ge.in");
    ofstream g("ge.out");
    f>>n>>m;
    for (i=1;i<=m;i++) {
        f>>x>>y;
        a[x][y]=1;
        a[y][x]=1;
    }

    ok=true;
    for (i=1;i<=n;i++) {
        nr=0;
        for (j=1;j<=n;j++)
            if (a[i][j]==1) nr++;
        if (nr%2!=0) {ok=false;break;}
    }

    if (ok!=true) g<<"graful nu e eulerian";
    if (ok==true) {
        ok1=true;
        df(1);
        for (i=1;i<=n;i++)
        if (v[i]==0) {ok1=false;break;} //verificam daca e conex- din 1 a ajuns in toate celelalte noduri
        if (ok1==false) g<<"graful nu e eulerian";
        else
        g<<"graful e eulerian";
    }

    f.close();
    g.close();
    return 0;
}

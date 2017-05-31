//un graf este arbore daca e neorientat,conex si nu are cicluri
//daca un graf este conex si are n(nr de noduri)-1 muchii => nu are cicluri

#include <fstream>

long int i,j,n,m,x,y,a[100][100],v[100];
bool ok;

void df(int k)
{
    int i;
    v[k]=1;
    for (i=1;i<=n;i++)
        if (a[k][i]==1 &&v[i]==0) df(i);
}

using namespace std;

int main()
{
    ifstream f("va.in");
    ofstream g("va.out");
    f>>n>>m;
    for (i=1;i<=m;i++) {
        f>>x>>y;
        a[x][y]=1;
        a[y][x]=1;
    }
    df(1);

    ok=true;
    for (i=1;i<=n;i++)
        if (v[i]!=1) {ok=false;break;}

    if (ok==false) g<<"graful nu e conex =>nu e arbore "<<'\n';
    if (ok==true) {
        g<<"graful e conex"<<'\n';
        if (n-1==m) g<<"graful nu are cicluri =>este arbore"<<'\n';
        else
        g<<"graful are cicluri=>nu este arbore"<<'\n';
    }

    f.close();
    g.close();
    return 0;
}

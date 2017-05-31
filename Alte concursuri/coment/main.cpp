#include <fstream>
#include <vector>

using namespace std;

vector <int> a[102];
long int x,y,n,i,v[102],viz[102],nr;
bool ok;

ifstream f("coment.in");
ofstream g("coment.out");

void df(int x)
{
    int i;
    if (ok==false) {
    if (nr==n) {ok=true;for (i=1;i<=n;i++) g<<v[i]<<' ';}
    for (i=0;i<a[x].size();i++)
        if (viz[a[x][i]]==0) {if (nr!=0) nr++;else nr=2; v[nr]=a[x][i];viz[a[x][i]]=1;df(a[x][i]);}
    viz[v[nr]]=0;
    --nr;
    }
}

int main()
{
    f>>n;
    while (!f.eof()) {
        f>>x>>y;
        a[x].push_back(y);
    }

    ok=false;

    for (i=1;i<=n;i++) {
        if (ok==false) {v[1]=i;viz[i]=1;df(i);}
        else break;
    }


    f.close();
    g.close();
    return 0;
}


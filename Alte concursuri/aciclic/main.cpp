#include <fstream>
#include <vector>

using namespace std;

vector <int> a[100];

long int viz[100],i,j,n,m,t[100],x,y,fiu[100];
bool ok;

inline void df(int x)
{
    int i;
    viz[x]=1;
    for (i=0;i<a[x].size();i++) {
        if (t[x]!=a[x][i] &&viz[a[x][i]]==0) {t[a[x][i]]=x;fiu[x]=a[x][i];df(a[x][i]);}
        if (t[x]!=a[x][i] &&viz[a[x][i]]==1 &&a[x][i]!=fiu[x]) {ok=true;break;}
    }
}

int main()
{
    ifstream f("aciclic.in");
    ofstream g("aciclic.out");
    f>>n>>m;
    for (i=1;i<=n;i++) {
        f>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    ok=false;
    for (i=1;i<=n;i++) {
        if (ok==false) {
            for (j=1;j<=n;j++)
            if (viz[j]!=0) viz[j]=0;
            for (j=1;j<=n;j++)
            if (t[j]!=0) t[j]=0;
            for (j=1;j<=n;j++)
            if (fiu[j]!=0) fiu[j]=0;
            df(i);
        }
    }

    if (ok==true) g<<"are ciclu";
    else
    g<<"nu are ciclu";

    f.close();
    g.close();
    return 0;
}

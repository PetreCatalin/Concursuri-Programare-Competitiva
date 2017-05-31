#include <fstream>
#include <vector>

using namespace std;

vector <long> v[100005];
long i,viz[100005],nr,x,y,n,m,nrc;

inline void df(long x)
{
    long i;
    viz[x]=1;
    for (i=0;i<v[x].size();++i)
        if (viz[v[x][i]]==0) df(v[x][i]);
}

int main()
{
    ifstream f("grarb.in");
    ofstream g("grarb.out");
    f>>n>>m;
    for (i=1;i<=m;++i) {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for (i=1;i<=n;++i)
        if (viz[i]==0) {
            ++nrc;
            df(i);
        }

    g<<m-n+nrc<<'\n';
    g<<nrc-1;

    f.close();
    g.close();
    return 0;
}

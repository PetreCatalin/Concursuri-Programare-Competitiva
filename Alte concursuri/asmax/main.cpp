#include <fstream>
#include <vector>

using namespace std;

long i,n,v[16005],j,x,y,maxim,viz[160005];
vector <long> a[16005];

void df(long x)
{
    long i,nr;
    viz[x]=1;
    for (i=0;i<a[x].size();++i) {
            nr=a[x][i];
        if (viz[nr]==0) {
            df(nr);
        if (v[nr]>0) v[x]+=v[nr];
        }
    }
}

int main()
{
    ifstream f("asmax.in");
    ofstream g("asmax.out");
    f>>n;
    for (i=1;i<=n;++i)
        f>>v[i];

    for (i=1;i<=n-1;++i) {
            f>>x>>y;
            a[x].push_back(y);
            a[y].push_back(x);
    }

    df(1);
    maxim=-1005;
    for (i=1;i<=n;++i)
        if (v[i]>maxim) maxim=v[i];

    g<<maxim;

    f.close();
    g.close();
    return 0;
}

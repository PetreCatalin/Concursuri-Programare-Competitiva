#include <fstream>
#include <vector>

using namespace std;

vector <long> a[1000005];
vector <long> c;
long i,j,nr,n,m,p,x,y,viz[1000005];

int main()
{
    ifstream f("berarii2.in");
    ofstream g("berarii2.out");
    f>>n>>m>>p;
    for (i=1;i<=m;++i) {
        f>>x>>y;
        a[y].push_back(x);
    }

    for (i=1;i<=p;++i) {
        f>>x;
        viz[x]=1;
        c.push_back(x);
        ++nr;
    }

    i=0;
    while(i<c.size()) {
        for (j=0;j<a[c[i]].size();++j)
            if (viz[a[c[i]][j]]==0) {
                ++nr;
                viz[a[c[i]][j]]=1;
                c.push_back(a[c[i]][j]);
            }
        ++i;
    }

    g<<n-nr<<'\n';
    for (i=1;i<=n;++i)
        if (viz[i]==0) g<<i<<'\n';

    f.close();
    g.close();
    return 0;
}

#include <fstream>
#include <algorithm>

using namespace std;

long int n,m,i,vec[200005],arb[200005],s,poz,nr,j;

struct nod {
    long int x;
    long int y;
    long int z;
}v[400005];

inline bool cmp(const nod &a,const nod &b)
{
    return (a.z<b.z);
}

int main()
{
    ifstream f("apm.in");
    ofstream g("apm.out");
    f>>n>>m;
    for (i=1;i<=m;i++)
        f>>v[i].x>>v[i].y>>v[i].z;

    sort(v+1,v+m+1,cmp);

    for (i=1;i<=n;i++)
    arb[i]=i;

    for (i=1;i<=m;i++)
        if (arb[v[i].x]!=arb[v[i].y] &&nr<n-1) {
            nr++;
            s=s+v[i].z;
            poz=arb[v[i].y];
            for (j=1;j<=n;j++)
            if (arb[j]==poz) arb[j]=arb[v[i].x];
            vec[nr]=i;
        }

    g<<s<<'\n';
    g<<n-1<<'\n';
    for (i=1;i<=nr;i++)
    g<<v[vec[i]].x<<' '<<v[vec[i]].y<<'\n';

    f.close();
    g.close();
    return 0;
}

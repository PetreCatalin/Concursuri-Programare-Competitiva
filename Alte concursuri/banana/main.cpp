#include <fstream>
#include <algorithm>

using namespace std;

bool cmp(long x,long y)
{
    return x>y;
}

long a[1005][10005],i,j,maximl,maximc,x,y,nr,k,v[2000005];
long long el,s;

void fill(long x,long y)
{
    a[x][y]=1;
    ++el;
    if (a[x][y-1]==-1) fill(x,y-1);
    if (a[x][y+1]==-1) fill(x,y+1);
    if (a[x-1][y]==-1) fill(x-1,y);
    if (a[x+1][y]==-1) fill(x+1,y);
}

int main()
{
    ifstream f("banana.in");
    ofstream g("banana.out");
    f>>nr>>k;
    for (i=1;i<=nr;++i) {
        f>>x>>y;
        a[x][y]=-1;
        if (x>maximl) maximl=x;
        if (y>maximc) maximc=y;
    }

    nr=0;
    for (i=1;i<=maximl;++i)
        for (j=1;j<=maximc;++j)
        if (a[i][j]==-1) {
            el=0;
            fill(i,j);
            v[++nr]=el;
        }

    sort(v+1,v+nr+1,cmp);
    for (i=1;i<=k;++i)
        s+=v[i];

    g<<s;

    f.close();
    g.close();
    return 0;
}

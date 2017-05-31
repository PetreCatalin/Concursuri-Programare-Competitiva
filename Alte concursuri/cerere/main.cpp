#include <fstream>
#include <vector>

using namespace std;

int i,n,tip[100005],grint[100005],x,y,rad,nrmin[100005],nr,st[100005],vf;
vector <int> nod[100005];

inline void df(int x)
{
    int i,t;
    st[++vf]=x;
    if (tip[x]==0) nrmin[x]=0;
    else
        nrmin[x]=nrmin[st[vf-tip[x]]]+1;

    t=nod[x].size();
    for (i=0;i<t;++i)
        df(nod[x][i]);
    --vf;
}

int main()
{
    ifstream f("cerere.in");
    ofstream g("cerere.out");
    f>>n;
    for (i=1;i<=n;++i)
        f>>tip[i];

    for (i=1;i<=n-1;++i) {
        f>>x>>y;
        if (grint[y]==0) grint[y]=1;
        nod[x].push_back(y);
    }

    for (i=1;i<=n;++i)
        if (grint[i]==0) {tip[i]=0;rad=i;break;}

    vf=0;
    df(rad);

    for (i=1;i<=n;++i)
        g<<nrmin[i]<<' ';

    f.close();
    g.close();
    return 0;
}

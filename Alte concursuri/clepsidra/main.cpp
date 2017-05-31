/*#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

#define mod 666013

long n,m,i,x,y,viz[200005],j,p[200005],rez[200005],niv[200005],ad[200005],nr,k,tata[200005];
vector <long> v[200005];

void tarjan(long nod)
{
    long i,fiu,nr=0;
    if(viz[nod]!=0) return;

    viz[nod]=1;
    ad[nod]=niv[nod];

    for(i=0;i<v[nod].size();++i)
    {
        fiu=v[nod][i];
        if(fiu==tata[nod])
            continue;
        if(viz[fiu]!=0)
        {
            ad[nod]=min(ad[nod],niv[fiu]);
            continue;
        }
        tata[fiu]=nod;
        niv[fiu]=niv[nod]+1;
        tarjan(fiu);

        if(ad[fiu]>=niv[nod]) ++nr;
        ad[nod]=min(ad[nod],ad[fiu]);
    }

    if(tata[nod]!=0) ++nr;
    rez[nod]=nr;
}

int main()
{
    ifstream f("clepsidra.in");
    ofstream g("clepsidra.out");
    f>>n>>m;
    for (i=1;i<=m;++i) {
            f>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
    }

    p[0]=1;
    for (i=1;i<=n;++i)
            p[i]=(p[i-1]*2)%mod;

   niv[1]=1;
   tarjan(1);

    for (i=1;i<=n;++i)
        g<<(p[rez[i]]+mod-2)%mod<<'\n';

    f.close();
    g.close();
    return 0;
} */

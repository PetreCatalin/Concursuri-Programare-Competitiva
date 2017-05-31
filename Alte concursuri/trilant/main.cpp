#include <fstream>
#include <vector>
#include <cstring>
#include <queue>

#define mod 400000000001

using namespace std;

vector <pair <long,long >  > v[100005];
long long i,x,y,z,a,b,c,n,m,viz[100005],d1[100005],d2[100005],d3[100005],k,t,j,t1[1000005],t2[100005],t3[100005],sol[100005],nr,x1,cost;
long long minim;
queue <long long> q;

void bellmanford(long long  d1[],long long  a,long long  tata[])
{
    viz[a]=1;
    while (!q.empty()) {
        k=q.front();
                t=v[k].size();
                for (j=0;j<t;j++)
                    {cost=v[k][j].second;
                    if (d1[v[k][j].first]>d1[k]+cost)  {
                        d1[v[k][j].first]=d1[k]+cost;
                        tata[v[k][j].first]=k;
                        if (viz[v[k][j].first]==0) {viz[v[k][j].first]=1;q.push(v[k][j].first);}
                    }
                    }
                viz[q.front()]=0;
                q.pop();
    }
}

int main()
{
    ifstream f("trilant.in");
    ofstream g("trilant.out");
    f>>n>>m;
    f>>a>>b>>c;
    for (i=1;i<=m;i++) {
        f>>x>>y>>z;
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
    }

    for (i=1;i<=n;++i) {
        if (d1[i]==0) d1[i]=mod;
        if (d2[i]==0) d2[i]=mod;
        if (d3[i]==0) d3[i]=mod;
    }

    d1[a]=0;q.push(a);
    bellmanford(d1,a,t1);
    d2[b]=0;q.push(b);
    bellmanford(d2,b,t2);
    d3[c]=0;q.push(c);
    bellmanford(d3,c,t3);

    minim=mod;
    for (i=1;i<=n;++i)
            if (d1[i]+d2[i]+d3[i]<minim) {minim=d1[i]+d2[i]+d3[i];x=i;}

    g<<minim<<'\n';

    x1=x;
    while (x!=a) {
        sol[++nr]=x;
        x=t1[x];
    }

    sol[++nr]=a;

    g<<nr<<' ';
    for (i=1;i<=nr;++i)
        g<<sol[i]<<' ';
    g<<'\n';

        x=x1;
        nr=0;
      while (x!=b) {
        sol[++nr]=x;
        x=t2[x];
    }

    sol[++nr]=b;

    g<<nr<<' ';
    for (i=1;i<=nr;++i)
        g<<sol[i]<<' ';
    g<<'\n';

    x=x1;
    nr=0;
      while (x!=c) {
        sol[++nr]=x;
        x=t3[x];
    }

    sol[++nr]=c;

    g<<nr<<' ';
    for (i=1;i<=nr;++i)
        g<<sol[i]<<' ';
    g<<'\n';

    f.close();
    g.close();
    return 0;
}

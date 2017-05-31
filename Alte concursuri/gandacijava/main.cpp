#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

int viz[10005],v[10005],st[10005],dr[10005],n,m,e,nr,t,x,y,p,ok,i;
vector <int> gr[10005];

int HopcroftKarp(int nod)
{
   if(viz[nod]) return 0;
   viz[nod]=1;

    for(vector <int>::iterator it=gr[nod].begin();it!=gr[nod].end();++it)
        if(!dr[*it]){
            dr[*it]=nod;
            st[nod]=*it;
            return 1;
        }

    for(vector <int>::iterator it=gr[nod].begin();it!=gr[nod].end();++it)
        if(HopcroftKarp(dr[*it])){
            dr[*it]=nod;
            st[nod]=*it;
            return 1;
        }

    return 0;
}

int main()
{
    ifstream f("java.in");
    ofstream g("java.out");

    f>>t;
    for (p=1;p<=t;++p) {
          f>>m>>n>>e;
    while(e){
        --e;
        f>>x>>y;
        gr[x].push_back(y);
        v[x]=1;
    }

    ok=1;
    while(ok){
        ok=0;
        for(i=1;i<=m;++i)
            if(!st[i])
                if(HopcroftKarp(i)) ok=1;
        memset(viz,0,sizeof(viz));
    }

    nr=0;
    for(i=1;i<=n;++i)
        if(dr[i]) ++nr;
    g<<nr<<"\n";

     for(i=1;i<=m;++i)
        if(v[i]) gr[i].clear();

    memset(v,0,sizeof(v));
    memset(st,0,sizeof(st));
    memset(dr,0,sizeof(dr));
    memset(viz,0,sizeof(viz));
    }

    f.close();
    g.close();
    return 0;
}

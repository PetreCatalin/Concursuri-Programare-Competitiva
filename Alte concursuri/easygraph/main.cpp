#include <fstream>
#include <vector>
#include <cstdio>

using namespace std;

long long k,i,t,x,y,n,m,v[15005],maxim,gr[15005],viz[15005],d[15005],ok,inc,sf,sf1,nr,j;
vector <long> a[15005],c,tr[15005];

int main()
{
  //freopen ("easygraph.in","r",stdin);
  //freopen ("easygraph.out","w",stdout);
  ifstream f("easygraph.in");
  ofstream g("easygraph.out");
    f>>t;
    for (k=1;k<=t;++k) {
            f>>n>>m;
            for (i=1;i<=n;++i) {
                f>>v[i];
                d[i]=v[i];
            }
            for (i=1;i<=m;++i) {
                f>>x>>y;
                ++gr[y];
                a[x].push_back(y);
                tr[y].push_back(x);
            }

            inc=0;sf=-1;
            for (i=1;i<=n;++i)
                if (gr[i]==0) {c.push_back(i);viz[i]=1;++sf;}

            ok=1;sf1=sf;
            while (ok==1) {
                    ok=0;
                    for (i=inc;i<=sf;++i) {
                            nr=c[i];
                            for (j=0;j<a[nr].size();++j) {
                                --gr[a[nr][j]];
                                if (viz[a[nr][j]]==0 &&gr[a[nr][j]]==0) {
                                        ++sf1;
                                        if (ok==0) ok=1;
                                        c.push_back(a[nr][j]);
                                        viz[a[nr][j]]=1;
                                }
                            }
                    }
                    inc=sf+1;
                    sf=sf1;
            }

           for (i=0;i<c.size();++i) {
                nr=c[i];
                maxim=d[nr];
                for (j=0;j<tr[nr].size();++j)
                    if (d[tr[nr][j]]+d[nr]>maxim) maxim=d[tr[nr][j]]+d[nr];
                d[nr]=maxim;
            }

            c.erase(c.begin(),c.end());

            //aici calculam d si dupa c.erase();

            maxim=-1000005;
            for (i=1;i<=n;++i)
                if (d[i]>maxim) maxim=d[i];

            g<<maxim<<"\n";

            for (i=1;i<=n;++i) {
                if (gr[i]!=0) gr[i]=0;
                if (viz[i]!=0) viz[i]=0;
                if (a[i].size()>0) a[i].erase(a[i].begin(),a[i].end());
                if (tr[i].size()>0) tr[i].erase(tr[i].begin(),tr[i].end());
            }
    }

    f.close();
    g.close();
    return 0;
}



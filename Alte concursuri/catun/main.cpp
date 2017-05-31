#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair <long int ,long int >  > v[36005];

long int x,y,z,n,m,k,i,j,fort[36003],dist[36003],d[36003],viz[36003],minim,poz,c,fo[36003],r;
bool ok;

int main()
{
    ifstream f("catun.in");
    ofstream g("catun.out");
    f>>n>>m>>k;
    for (i=1;i<=k;i++) {
        f>>fort[i];
        dist[fort[i]]=-1;
        }
    for (i=1;i<=m;i++) {
        f>>x>>y>>z;
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
    }

    for (i=1;i<=n;i++)
        if(dist[i]!=-1) dist[i]=1000000000;

    for (i=1;i<=k;i++) {
        x=fort[i];
        for (j=1;j<=n;j++)
        if (viz[j]!=0) viz[j]=0;
        for (j=1;j<=n;j++)
        if (d[j]!=1000000000) d[j]=1000000000;
        for (j=0;j<v[x].size();j++)
        d[v[x][j].first]=v[x][j].second;
        ok=true;
        viz[x]=1;
        while (ok==true) {
            minim=1000000000;
            for (j=1;j<=n;j++)
            if (d[j]<minim &&viz[j]==0&&j!=x) {minim=d[j];poz=j;}
            viz[poz]=1;
            if (minim==1000000000) ok=false;

            if (ok==true)
            for (j=1;j<=n;j++) {
                if (viz[j]==0) {
                c=-1;
            for (r=0;r<v[poz].size();r++)
                if (v[poz][r].first==j &&j!=x) {c=v[poz][r].second;if (d[poz]+c<d[j]) d[j]=d[poz]+c; break;}
                }
            }
        }
        for (j=1;j<=n;j++)
        if (d[j]!=1000000000 &&dist[j]>d[j]) {dist[j]=d[j];fo[j]=x;}
    }

    for (i=1;i<=n;i++) {
        if (dist[i]==-1) g<<'0'<<' ';
        else
        g<<fo[i]<<' ';
    }

    f.close();
    g.close();
    return 0;
}

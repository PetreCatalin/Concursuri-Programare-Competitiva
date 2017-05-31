#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair <long int,long int>  > a[50005];
long int i,j,n,m,k,d[50005],x,y,z,viz[50005],minim,c;
bool ok;

int main()
{
    ifstream f("dijkstra.in");
    ofstream g("dijkstra.out");
    f>>n>>m;
    for (i=1;i<=m;i++) {
        f>>x>>y>>z;
        a[x].push_back(make_pair(y,z));
        if (x==1) d[y]=z;
    }

    for (i=2;i<=n;i++)
    if (d[i]==0) d[i]=100000000;

    viz[1]=1;
    ok=true;
    while (ok==true) {
        minim=100000000;
        for (i=2;i<=n;i++)
        if (d[i]<minim &&viz[i]==0) {k=i;minim=d[i];}
        viz[k]=1;
        if (minim==100000000) ok=false;

        for (i=2;i<=n;i++)
            if (viz[i]==0) {
                for (j=0;j<a[k].size();j++)
                if (a[k][j].first==i) {c=a[k][j].second; if (d[i]>d[k]+c) d[i]=d[k]+c;}
            }
    }

        for (i=2;i<=n;i++) {
            if (d[i]==100000000) g<<'0'<<' ';
            else
            g<<d[i]<<' ';
        }

    f.close();
    g.close();
    return 0;
}

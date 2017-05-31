#include <fstream>
#include <vector>

using namespace std;

vector <pair<long,long> > graf[50002];
long n,m,gr,x,y,gre,i,dist[50005],nr,viz[50005],minim,poz,t;

int main()
{
    ifstream f("camionas.in");
    ofstream g("camionas.out");
    f>>n>>m>>gr;

    for (i=1;i<=m;++i) {
        f>>x>>y>>gre;
        if (gre<gr) {
        graf[x].push_back(make_pair(y,1));
        graf[y].push_back(make_pair(x,1));
        }
        else {
        graf[x].push_back(make_pair(y,0));
        graf[y].push_back(make_pair(x,0));
        }
    }

    for (i=2;i<=n;++i)
        dist[i]=100005;

    nr=graf[1].size();
    for (i=0;i<nr;++i)
        dist[graf[1][i].first]=graf[1][i].second;

    nr=0;
    viz[1]=1;
    while (1) {
        minim=100005;
        for (i=2;i<=n;++i)
            if (viz[i]==0 &&dist[i]<minim) {minim=dist[i];poz=i;}
        if (minim==100005) break;
        viz[poz]=1;

        t=graf[poz].size();
        for (i=0;i<t;++i)
            if (dist[graf[poz][i].first]>dist[poz]+graf[poz][i].second)
                dist[graf[poz][i].first]=dist[poz]+graf[poz][i].second;

    }

   // for (i=1;i<=n;i++)
     //  g<<dist[i]<<' ';
    g<<dist[n];

    f.close();
    g.close();
    return 0;
}

#include <fstream>
#include <vector>

using namespace std;

vector <long int> v[1000];
long int n,m,i,x,y,nr,a[1000];

inline void df(long int x)
{
    long int i,poz,j;
    for (i=0;i<v[x].size();i++) {
        v[x].erase(v[x].begin()+i);
        for (j=0;j<v[v[x][i]].size();j++)
        if (v[v[x][i]][j]==x) {poz=j;break;}
        v[v[x][i]].erase(v[v[x][i]].begin()+poz);
        df(i);
    }
    nr++;
    a[nr]=x;
}

int main()
{
    ifstream f("ce.in");
    ofstream g("ce.out");
    f>>n>>m;
    for (i=1;i<=m;i++) {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    nr=0;
    df(1);

    for (i=1;i<=nr;i++)
    g<<a[nr]<<' ';

    f.close();
    g.close();
    return 0;
}

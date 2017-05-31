#include <fstream>
#include <vector>

using namespace std;

vector <long int > a[10005];
long int n,m,x,y,i,viz[10005],nr,vec[10005],maxim,maxim1,poz,poz1;

inline void df(long int x)
{
    long int i;
    viz[x]=nr;
    for (i=0;i<a[x].size();i++)
        if (viz[a[x][i]]==0) df(a[x][i]);
}

int main()
{
    ifstream f("turn1.in");
    ofstream g("turn1.out");
    f>>n>>m;
    for (i=1;i<=m;i++) {
        f>>x>>y;
        if (x!=y) {
            a[x].push_back(y);
            a[y].push_back(x);
        }
    }

    nr=0;
    for (i=1;i<=n;i++)
        if (viz[i]==0) {
            nr++;
            df(i);
        }

    for (i=1;i<=n;i++)
        vec[viz[i]]++;
    for (i=1;i<=nr;i++) {
        if (vec[i]>maxim) {maxim1=maxim;poz1=poz;maxim=vec[i];poz=i;}
        else
        if (vec[i]>maxim1) {maxim1=vec[i];poz1=i;}
    }

    for (i=1;i<=n;i++)
    if (viz[i]==poz) {g<<i<<' ';break;}
    if (poz1==0) g<<'1';
    else
    for (i=1;i<=n;i++)
    if (viz[i]==poz1) {g<<i<<' ';break;}

    f.close();
    g.close();
    return 0;
}

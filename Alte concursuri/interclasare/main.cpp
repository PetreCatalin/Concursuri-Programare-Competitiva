#include <fstream>

using namespace std;

int a[100],b[100],c[100],i,j,n,m,x,y,nr;

int main()
{
    ifstream f("inter.in");
    ofstream g("inter.out");
    f>>n;
    for (i=1;i<=n;i++)
    f>>a[i];
    f>>m;
    for (i=1;i<=m;i++)
    f>>b[i];
    nr=0;x=1;y=1;
    while (x<=n && y<=m) {
           nr++;
           if (a[x]<=b[y]) {c[nr]=a[x];x++;}
           else
           {c[nr]=b[y];y++;}
    }
    for (j=x;j<=n;j++) {
           nr++;
           c[nr]=a[j];
    }
    for (j=y;j<=m;j++) {
           nr++;
           c[nr]=b[j];
    }
    for (i=1;i<=nr;i++)
    g<<c[i]<<" ";
    f.close();
    g.close();
    return 0;
}

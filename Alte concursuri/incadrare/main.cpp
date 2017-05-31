#include <fstream>

using namespace std;

typedef struct {
    double x,y;
}nume;

nume a[100003];
long int n,m,i,nr,xa,xb,ya,yb,j;

int main()
{
    ifstream f("incadrare.in");
    ofstream g("incadrare.out");
    f>>n>>m;
    for (i=1;i<=n;i++)
        f>>a[i].x>>a[i].y;
    for (i=1;i<=m;i++) {
        f>>xa>>ya>>xb>>yb;
        nr=0;
        for (j=1;j<=n;j++)
        if (a[j].x>xa&&a[j].x<xb&&a[j].y>ya&&a[j].y<yb) nr++;
        g<<nr<<'\n';
    }

    f.close();
    g.close();
    return 0;
}

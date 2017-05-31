#include <fstream>

using namespace std;

long int n,i,j,k,a[260][260],d[260][260];

int main()
{
    ifstream f("rf.in");
    ofstream g("rf.out");
    f>>n;
    for (i=1;i<=n;i++)
    for (j=1;j<=n;j++) {
    f>>a[i][j];
    if (i!=j)
    d[i][j]=1;
    }
    for (k=1;k<=n;k++)
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++) {
            if (a[i][k]+a[k][j]<a[i][j] &&i!=j) {a[i][j]=a[i][k]+a[k][j];if (d[i][j]<d[i][k]+d[k][j]) d[i][j]=d[i][k]+d[k][j];}
            else
            if (a[i][k]+a[k][j]==a[i][j] &&i!=j &&d[i][j]<d[i][k]+d[k][j]) d[i][j]=d[i][k]+d[k][j];
            }


    for (i=1;i<=n;i++) {
    for (j=1;j<=n;j++)
    g<<a[i][j]<<' ';
    g<<'\n';
    }


    for (i=1;i<=n;i++) {
    for (j=1;j<=n;j++)
    g<<d[i][j]<<' ';
    g<<'\n';
    }


    f.close();
    g.close();
    return 0;
}

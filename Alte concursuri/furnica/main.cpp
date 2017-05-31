#include <fstream>

using namespace std;

int a[103][103],b[103][103],s,nr,maxim,i,k,n,v[203],j,x,y;

int main()
{
    ifstream f("furnica.in");
    ofstream g("furnica.out");
    f>>n>>k;
    for (i=1;i<=k;i++)
    f>>v[i];
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
        a[i][j]=(i+j)%6;
    s=a[1][1];
    b[1][1]=1;
    x=1;
    y=1;
    for (i=1;i<=k;i++) {
        if (v[i]==1) x=x-1;
        if (v[i]==2) {x=x-1;y++;}
        if (v[i]==3) y++;
        if (v[i]==4) {y++;x++;}
        if (v[i]==5) x++;
        if (v[i]==6) {x++;--y;}
        if (v[i]==7) --y;
        if (v[i]==8) {--x;--y;}
        if (b[x][y]==0)
        s=s+a[x][y];
        b[x][y]++;
    }
    g<<s<<' ';
    nr=0;maxim=0;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++) {
        if (b[i][j]==maxim) nr++;
        if (b[i][j]>maxim) {maxim=b[i][j];nr=1;}
        }
    g<<nr;
    f.close();
    g.close();
    return 0;
}

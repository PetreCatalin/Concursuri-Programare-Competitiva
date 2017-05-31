#include <fstream>

using namespace std;

long int n,m,k,i,x,y,z,j,a[2003][2003],v[2003],sol[2003],t,minim,numar;

int ok(int k)
{
    int i;
    for (i=1;i<k;i++)
        if(sol[k]==sol[i]) return 0;
        return 1;
}

void back(int k)
{
    int i,j;
    if (k>t) {
        numar=a[1][v[sol[1]]];
        for (j=2;j<=t;j++)
            numar=numar+a[v[sol[j-1]]][v[sol[j]]];
        numar=numar+a[v[sol[t]]][n];
        if (numar<minim) minim=numar;
    }
    else
    for (i=1;i<=t;i++) {
        sol[k]=i;
        if (ok(k)) back(k+1);
    }
}

int main()
{
    ifstream f("ubuntzei.in");
    ofstream g("ubuntzei.out");
    f>>n>>m;
    f>>t;
    for (i=1;i<=t;i++)
    f>>v[i];
    for (i=1;i<=m;i++) {
        f>>x>>y>>z;
        a[x][y]=z;
        a[y][x]=z;
    }

    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
        if (a[i][j]==0) a[i][j]=100000005;

    for (x=1;x<=n;x++)
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
            if (a[i][j]>a[i][x]+a[x][j] &&i!=j) a[i][j]=a[i][x]+a[x][j];

    /*for (i=1;i<=n;i++) {
        for (j=1;j<=n;j++)
        g<<a[i][j]<<' ';
        g<<'\n';
    }*/
    if (t!=0) {
    minim=100000000;
    back(1);
    g<<minim;
    }
    else g<<a[1][n];

    f.close();
    g.close();
    return 0;
}

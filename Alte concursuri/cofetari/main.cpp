#include <fstream>

using namespace std;

long int i,j,n,m,pret[100],minim,v[100],prop[100],x,y,a[100][100],sol[100],k;

inline long int ok(int k)
{
    int i;
    for (i=1;i<=k-1;i++)
    if (a[sol[i]][sol[k]]==1) return 0;
    return 1;
}

inline void back(int k)
{
    int i,j,s;
    if (k>m) {
        s=0;
        for (j=1;j<=m;j++)
        s=s+pret[sol[j]]/10*prop[sol[j]];
        if (s<minim) {
            minim=s;
            for (j=1;j<=m;j++)
            v[j]=sol[j];
        }
    }

    else
        for (i=sol[k-1]+1;i<=n;i++) {
            sol[k]=i;
            if (ok(k)) back(k+1);
        }
}

int main()
{
    ifstream f("cofetari.in");
    ofstream g("cofetari.out");
    f>>n;
    for (i=1;i<=n;i++)
    f>>pret[i];
    f>>k;
    for (i=1;i<=k;i++) {
        f>>x>>y;
        a[x][y]=1;
    }
    f>>m;
    for (i=1;i<=m;i++)
    f>>prop[i];

    minim=100000;

    back(1);

    g<<minim<<'\n';
    for (i=1;i<=m;i++)
    g<<v[i]<<' ';


    f.close();
    g.close();
    return 0;
}

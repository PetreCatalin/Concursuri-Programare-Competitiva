#include <fstream>

using namespace std;

typedef struct {
    long int k[100];
    long int n;
}nume;

nume b[100];

long int x,y,a[100][100],i,j,viz[100],nr,numar,n,m;

int main()
{
    ifstream f("turism.in");
    ofstream g("turism.out");
    f>>n>>m;
    for (i=1;i<=m;i++) {
        f>>x>>y;
        a[x][y]=1;
    }

    for (i=1;i<=n;i++)
        if (viz[i]==0) {
            nr++;
        }

    g<<nr<<'\n';
    for (i=1;i<=nr;i++) {
        g<<b[i].n<<' ';
        for (j=1;j<=b[i].n;j++)
            g<<b[i].k[j]<<' ';
        g<<'\n';
    }

    f.close();
    g.close();
    return 0;
}

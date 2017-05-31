#include <fstream>

using namespace std;

long int i,j,a[100][100],n,minim,s,lista[100],nr,x,viz[100];
bool ok;

int main()
{
    ifstream f("prim.in");
    ofstream g("prim.out");
    f>>n;
    for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    f>>a[i][j];

    lista[1]=1;viz[1]=1;nr=1;ok=true;s=0;
    while (ok==true) {
        ok=false;
        minim=100;
        for (i=1;i<=nr;i++)
            for (j=1;j<=n;j++)
            if (a[lista[i]][j]<minim &&a[lista[i]][j]!=0 &&viz[j]==0) {minim=a[lista[i]][j];ok=true;x=j;}
        if (ok==true) {
                        viz[x]=1;nr++;lista[nr]=x;s=s+minim;}
    }

    for (i=1;i<=n;i++)
    g<<lista[i]<<' ';
    g<<'\n';g<<"costul total este "<<s;

    f.close();
    g.close();
    return 0;
}

#include <fstream>

using namespace std;

long int i,j,a[100],x,y,n,nr,s,v[100],k;

int main()
{
    ifstream f("ab.in");
    ofstream g("ab.out");
    f>>n;
    for (i=1;i<=n;i++)
    f>>a[i];
    f>>x>>y;
    s=2;
    nr=1;

    while (s!=n+1) {
        s=s*2;
        nr++;
    }

    g<<"arborele are "<<nr<<" nivele"<<'\n';

    g<<"pe nivelul "<<nr<<" sunt urmatoarele noduri: (frunze) ";
    for (i=(n+1)/2;i<=n;i++)
        g<<a[i]<<' ';
    g<<'\n';

    g<<"tatal lui "<<x<<" este ";
    for (i=1;i<=n;i++)
        if (a[i]==x) {nr=i;break;}
    g<<a[nr/2]<<'\n';
    g<<"fii lui "<<x<<" sunt "<<a[nr*2]<<" si "<<a[nr*2+1]<<'\n';

    g<<"lungimea lantului de la "<<x<<" la "<<y<<" este ";

    nr=1;
    for (i=1;i<=n;i++)
        if (a[i]==y) {v[nr]=y;k=i;break;}
    while  (a[k]!=x) {
        k=k/2;
        nr++;
        v[nr]=a[k];
    }

    g<<nr-1<<'\n'<<"din lant fac parte nodurile ";

    for (i=nr;i>=1;--i)
        g<<v[i]<<' ';
    g<<'\n';

    g<<"traseul urmat este: ";
    for (i=nr-1;i>=1;--i)
        for (j=1;j<=n;j++)
        if (v[i]==a[j]) {
            if (j%2==0) g<<'S'<<' ';
            else
            g<<'D'<<' ';
        }

    f.close();
    g.close();
    return 0;
}

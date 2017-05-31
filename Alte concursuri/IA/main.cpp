#include <fstream>

using namespace std;

int main()
{
    ifstream f("ia.in");
    ofstream g("ia.out");
    int n=5000,i,a[5005][10],v[30],nr=9,j,maxim,poz,rez[5005],k;

    for (j=1;j<=nr;++j)
        for (i=1;i<=n;++i)
            f>>a[i][j];

    for (i=1;i<=5000;++i) {
        for (j=1;j<=nr;++j)
        g<<a[i][j]<<' ';
        g<<'\n';
    }

    for (i=1;i<=5000;++i) {
        for (k=1;k<=10;++k) v[k]=0;
        for (j=1;j<=nr;++j)
            if (a[i][j]>0 &&a[i][j]<=10) ++v[a[i][j]];
        maxim=0;
        for (k=1;k<=10;++k)
        if (v[k]>=maxim) {maxim=v[k];poz=k;}
        if (maxim>0)
        rez[i]=poz;
        else rez[i]=1;
    }

   /* for (i=1;i<=10;++i) v[i]=0;
    g<<"Id,Prediction"<<'\n';
    for (i=1;i<=5000;++i) {
        g<<i<<','<<rez[i]<<'\n';
        ++v[rez[i]];
    }

    for (i=1;i<=10;++i)
       g<<v[i]<<' '; */

    f.close();
    g.close();
    return 0;
}

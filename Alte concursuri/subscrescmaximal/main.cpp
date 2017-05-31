#include <fstream>

using namespace std;

long int n,nr,i,maxim,poz,poz1,v[1000],t[1000],a[1000],vec[1000],j;

int main()
{
    ifstream f("scmax.in");
    ofstream g("scmax.out");
    f>>n;
    for (i=1;i<=n;i++)
        f>>a[i];
    v[1]=1;nr=0;
    for (i=2;i<=n;i++) {
        maxim=0;
        for (j=i-1;j>=1;--j)
        if (a[i]>a[j] &&v[j]>maxim) {maxim=v[j];poz=j;}
        v[i]=maxim+1;
        t[i]=poz;
        if (v[i]>nr) {nr=v[i];poz1=i;}
    }

    g<<nr<<'\n';
    nr=0;
    while (poz1!=0) {
        vec[++nr]=a[poz1];
        poz1=t[poz1];
    }

    for (i=nr;i>=1;--i)
    g<<vec[i]<<' ';

    f.close();
    g.close();
    return 0;
}

#include <fstream>

using namespace std;

long int n,nr,i,j,s[1000000],a[1000000],maxim,maxim1,suma,suma1,numar,k[1000000],v[1000000];

int main()
{
    ifstream f("depozit.in");
    ofstream g("depozit.out");
    f>>n;
    for (i=1;i<=n;i++)
    f>>a[i];
    nr=n;
    while (nr>0) {
        maxim=0;
        for (i=1;i<=n;i++) {
            if (k[i]==0) {
            maxim1=a[i];
            s[a[i]]=i;
        for (j=maxim;j>=1;--j) {
            if (s[j]!=0 &&s[j+a[i]]==0) s[j+a[i]]=i;
            if (j+a[i]>maxim1) maxim1=j+a[i];
            }
        maxim=maxim1;
            }
        }
        for (j=maxim;j>=1;--j)
        if (s[j]!=0 &&j%nr==0) {g<<nr<<' ';suma=j;break;}
        numar=0;suma1=suma;
        while (suma>0) {
            numar++;
            v[numar]=s[suma];
            k[s[suma]]=1;
            suma=suma-a[s[suma]];
        }
        g<<numar<<' ';
        for (i=numar;i>=1;--i)
        g<<v[i]<<' ';
        g<<suma1/nr<<'\n';
        nr=nr-numar;
    }

    f.close();
    g.close();
    return 0;
}

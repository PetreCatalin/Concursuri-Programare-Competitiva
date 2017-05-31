#include <fstream>

using namespace std;

typedef struct {
    long forta;
    long masa;
    double raport;
    long ind;
}prod;

prod a[10005],aux;
long n,i,fort,m,j,v[10005],ok;
double r1,r2;

int main()
{
    ifstream f("sboost.in");
    ofstream g("sboost.out");
    f>>fort>>m>>n;
    for (i=1;i<=n;i++) {
        f>>a[i].forta>>a[i].masa;
        a[i].ind=i;
        a[i].raport=(double) a[i].forta/a[i].masa;
    }

    for (i=1;i<=n-1;i++)
        for (j=i+1;j<=n;j++)
            if (a[i].raport<a[j].raport) {
                aux=a[i];
                a[i]=a[j];
                a[j]=aux;
            }

    r1=(double) fort/m;
    for (i=1;i<=n;i++) {
        fort=fort+a[i].forta;
        m=m+a[i].masa;
        r2=(double) fort/m;
        if (r2>r1) {
            r1=r2;
            v[a[i].ind]=1;
        }
        else
        break;
    }


    ok=0;
    for (i=1;i<=n;i++)
        if (v[i]==1) {g<<i<<'\n';if (ok==0) ok=1;}

    if (ok==0) g<<"NONE";

    f.close();
    g.close();
    return 0;
}

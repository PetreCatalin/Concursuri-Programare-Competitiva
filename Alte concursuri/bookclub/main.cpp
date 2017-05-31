#include <fstream>

using namespace std;

long n,nq,p,i,nr,a[50002][52],intr[12],rasp[12],j,ok;

int main()
{
    ifstream f("bookclub.in");
    ofstream g("bookclub.out");
    f>>n>>nq>>p;
    for (i=1;i<=n;i++)
        for (j=1;j<=nq;j++)
        f>>a[i][j];
    for (i=1;i<=p;i++)
        f>>intr[i]>>rasp[i];

    for (i=1;i<=n;i++) {
        ok=1;
        for (j=1;j<=p;j++)
            if (a[i][intr[j]]!=rasp[j]) {ok=0;break;}
        if (ok==1) nr++;
    }

    g<<nr;

    f.close();
    g.close();
    return 0;
}

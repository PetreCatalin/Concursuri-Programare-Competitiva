#include <fstream>

using namespace std;

long int a[105][105],i,j,x,nr,inc,sf,sf1,k,o,n,viz[105],st[105],numar;

int main()
{
    ifstream f("prieteni3.in");
    ofstream g("prieteni3.out");
    f>>n>>o>>k;
    for (i=1;i<=n;i++) {
        f>>nr;
        for (j=1;j<=nr;j++) {
            f>>x;
            a[i][x]=1;
        }
    }

    st[1]=o;viz[o]=1;
    inc=1;sf=1;nr=0;sf1=1;numar=0;
    while (nr<k) {
        nr++;
        for (i=inc;i<=sf;i++) {
            x=st[i];
            for (j=1;j<=n;j++) {
            if (a[x][j]==1 &&viz[j]==0 &&nr!=k) {viz[j]=1;sf1++;st[sf1]=j;}
            if (nr==k && a[x][j]==1 &&viz[j]==0) {numar++;viz[j]=2;}
            }
        }
        inc=sf+1;
        sf=sf1;
    }

    g<<numar<<'\n';
    for (i=1;i<=n;i++)
    if (viz[i]==2) g<<i<<' ';


    f.close();
    g.close();
    return 0;
}

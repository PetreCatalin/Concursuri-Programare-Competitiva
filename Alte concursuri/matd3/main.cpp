#include <fstream>

using namespace std;

int main()
{
    int a[505][505];
    long int l,c,i,j,s,nr,k,minim,numar,o,q;
    ifstream f("matd3.in");
    ofstream g("matd3.out");
    f>>l>>c;
    for (i=1;i<=l;i++)
        for (j=1;j<=c;j++)
        f>>a[i][j];
    nr=0;
    for (i=1;i<=l;i++)
        for (j=1;j<=c;j++){
            s=a[i][j];
            if (s%3==0) nr++;
            for (k=j-1;k>=1;--k) {
            s=s+a[i][k];
            if (s%3==0) nr++;
            }
        }
    for (i=1;i<=c;i++)
        for (j=1;j<=l;j++){
            s=a[j][i];
            for (k=j-1;k>=1;--k) {
            s=s+a[k][i];
            if (s%3==0) nr++;
            }
        }

    if (l<c) minim=l; else minim=c;
    for (i=1;i<=l-1;i++)
        for (j=1;j<=c-1;j++) {
            numar=2;
            while (numar<=minim) {
                s=0;
                for (o=i;o<=i+numar-1;o++)
                    for (q=j;q<=j+numar-1;q++)
                    s=s+a[o][q];
                if (s%3==0) nr++;
                numar++;
            }
        }



    g<<nr;

    f.close();
    g.close();
    return 0;
}

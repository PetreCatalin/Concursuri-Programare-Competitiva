#include <fstream>

using namespace std;

long int fl,v,i,j,minim,a[100][100],b[100][100],c[100][100],poz,k,x,v1[100];

int main()
{
    ifstream f("flower.in");
    ofstream g("flower.out");
    f>>fl>>v;
    for (i=1;i<=fl;i++)
        for (j=1;j<=v;j++)
        f>>a[i][j];
    for (i=1;i<=v-fl+1;i++)
        b[1][i]=a[1][i];
    for (j=2;j<=fl;j++)
        for (i=j;i<=v-fl+j;i++) {
            minim=0;
            for (k=i-1;k>=1;--k)
            if (minim<a[j][i]+b[j-1][k]) {minim=a[j][i]+b[j-1][k];poz=k;}
            c[j][i]=poz;b[j][i]=minim;
        }

   /* for (i=1;i<=fl;i++) {
        for (j=1;j<=v;j++)
        g<<c[i][j]<<' ';
        g<<'\n';
    } */

    minim=0;
    for (i=fl;i<=v;i++)
        if (b[fl][i]>minim) {minim=b[fl][i];poz=c[fl][i];v1[1]=i;}
    g<<minim<<'\n';

    x=1;k=poz;
    while (x<fl) {
        x++;
        v1[x]=k;
        k=c[fl-x+1][k];
    }

    for (i=fl;i>=1;--i)
    g<<v1[i]<<' ';

    f.close();
    g.close();
    return 0;
}

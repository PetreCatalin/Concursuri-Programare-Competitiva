#include <fstream>

using namespace std;

long int n,i,j,x,a[105][105],y,min1,min2,minim,ii,jj,maxim;

int main()
{
    ifstream f("megascoala.in");
    ofstream g("megascoala.out");
    f>>n;
    for (i=1;i<=n;i++)
    for (j=1;j<=n;j++) {
        f>>a[i][j];
        if (i!=j &&a[i][j]==0) a[i][j]=2000000;
    }

    for (x=1;x<=n;x++)
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
                if (a[i][j]>a[i][x]+a[x][j]) a[i][j]=a[i][x]+a[x][j];

   /* for (i=1;i<=n;i++) {
        for (j=1;j<=n;j++)
        g<<a[i][j]<<' ';
        g<<'\n';
    } */

    minim=1000000;

    for (i=1;i<=n-1;i++)
        for (j=i+1;j<=n;j++) {
        min1=0;
        for (ii=1;ii<=n;ii++) {
            if (a[i][ii]>=2000000 &&a[j][ii]>=2000000) {min1=1000005;break;}
            if (a[i][ii]<a[j][ii]) maxim=a[i][ii];
            else
            maxim=a[j][ii];
            if (maxim>min1) min1=maxim;
        }
        if (min1<minim) {x=i;y=j;minim=min1;}
    }

    g<<x<<' '<<y<<' '<<minim;

    f.close();
    g.close();
    return 0;
}

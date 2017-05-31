#include <fstream>

using namespace std;

long int n,m,i,j,p,r,x,s,maxim,a[505][505],b[505][505],q,poz1,poz2;

int main()
{
    ifstream f("petrol.in");
    ofstream g("petrol.out");
    f>>n>>m;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) {
        f>>a[i][j];
        b[i][j]=a[i][j]+b[i][j-1];
    }
    f>>q;
    for (r=1;r<=q;r++) {
        f>>x;
        maxim=-1000*500-10;
        if (x==1) {
            for (i=1;i<=n;i++)
                for (j=1;j<=m;j++)
                if (a[i][j]>maxim) {maxim=a[i][j];poz1=i;poz2=j;}
        }
        else {
        for (i=1;i<=n-x+1;i++)
            for (j=0;j<=m-x;j++) {
                s=0;
                for (p=i;p<=i+x-1;p++)
                s=s+b[p][j+x]-b[p][j];
                if (s>maxim) {maxim=s;poz1=i;poz2=j+1;}
            }
        }

        g<<maxim<<' '<<poz1<<' '<<poz2<<'\n';
    }

    f.close();
    g.close();
    return 0;
}

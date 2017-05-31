#include <fstream>

using namespace std;

long int d,n,m,x[105],r[105],i,j,a[105][105],b[105],c[105],minim,aux;

int main()
{
    ifstream f("turn.in");
    ofstream g("turn.out");
    f>>d>>n>>m;
    for (i=1;i<=n;i++) {
        f>>x[i];
        if (i==1) {
        for (j=1;j<=d;j++)
        a[1][j]=j*x[i];
        }
    }

    for (i=1;i<=m;i++)
        f>>r[i]>>b[i]>>c[i];
    for (i=1;i<=m-1;i++)
        for (j=i+1;j<=m;j++)
        if (b[i]>b[j]) {
            aux=r[i];
            r[i]=r[j];
            r[j]=aux;
            aux=b[i];
            b[i]=b[j];
            b[j]=aux;
            aux=c[i];
            c[i]=c[j];
            c[j]=aux;
        }

    for (i=1;i<=m;i++) {
            a[c[i]][r[i]]=a[b[i]][r[i]];
            for (j=r[i]+1;j<=d;j++) {
                if (a[c[i]][j]>a[c[i]][r[i]]+(j-r[i])*x[c[i]] ||a[c[i]][j]==0)
               a[c[i]][j]=a[c[i]][r[i]]+(j-r[i])*x[c[i]];
            }
            for (j=1;j<=r[i]-1;j++) {
                if (a[c[i]][j]>a[c[i]][r[i]]+(r[i]-j)*x[c[i]] ||a[c[i]][j]==0)
                a[c[i]][j]=a[c[i]][r[i]]+(r[i]-j)*x[c[i]];
            }
    }


    minim=1000000;
    for (i=1;i<=n;i++)
        if (a[i][d]<minim) minim=a[i][d];

    g<<minim;

    f.close();
    g.close();
    return 0;
}

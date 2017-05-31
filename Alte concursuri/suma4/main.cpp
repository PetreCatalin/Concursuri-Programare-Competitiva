#include <fstream>

using namespace std;

long int i,n,x,k,j,p,m[60][60][60],a[60][60][60],y;

int minim(int a,int b,int c,int d)
{
    int k=2000;
    if (a<k) k=a;
    if (b<k) k=b;
    if (c<k) k=c;
    if (d<k) k=d;
    return k;
}

int main()
{
    ifstream f("suma4.in");
    ofstream g("suma4.out");
    f>>n;
    f>>m[1][1][1];
    x=1;k=1;
    i=2;
    while (i<=n)
        {
            if (i==k*(2*k+1)*(k+1)/6+1) k++;
            for (j=1;j<=k;j++)
                for (p=1;p<=k;p++) {
                f>>m[k][j][p];
                i++;
                }
        }

    for (i=1;i<=10000;i++)
        if (i*(2*i+1)*(i+1)/6==n) {y=i;g<<i<<' ';break;}

   /* for (k=1;k<=i;k++) {
        for (j=1;j<=k;j++) {
            for (p=1;p<=k;p++)
            g<<m[k][j][p]<<' ';
            g<<'\n';
        }
    g<<'\n'<<'\n';
    } */

    k=i;
    for (i=1;i<=k;i++)
        for (j=1;j<=k;j++)
        a[k][i][j]=m[k][i][j];

    k=k-1;
    while (k>=1) {
        for (i=1;i<=k;i++)
            for (j=1;j<=k;j++)
            a[k][i][j]=m[k][i][j]+minim(a[k+1][i][j],a[k+1][i+1][j],a[k+1][i][j+1],a[k+1][i+1][j+1]);
        --k;
    }

    g<<a[1][1][1]<<'\n';
    g<<'1'<<' ';
    k=1;i=1;j=1;
    while (k<y) {
        x=k*(2*k+1)*(k+1)/6;
        k++;
        if (a[k][i][j]==a[k-1][i][j]-m[k-1][i][j]) g<<x+(i-1)*k+j<<' ';
        else
        if (a[k][i][j+1]==a[k-1][i][j]-m[k-1][i][j]) {g<<x+(i-1)*k+j+1<<' ';j++;}
        else
        if (a[k][i+1][j]==a[k-1][i][j]-m[k-1][i][j]) {g<<x+i*k+j<<' ';i++;}
        else
        if (a[k][i+1][j+1]==a[k-1][i][j]-m[k-1][i][j]) {g<<x+i*k+j+1<<' ';j++;i++;}
    }




    f.close();
    g.close();
    return 0;
}

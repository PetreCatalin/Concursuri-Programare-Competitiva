#include <fstream>

using namespace std;

inline long int maxim(long int x,long int y)
{
    if (x>y) return x;
    else
    return y;
}

long int i,j,x,m[140][140],a[140][140],b[140][140],c[140][140],nr1,nr2,n;
int main()
{
    ifstream f("joc.in");
    ofstream g("joc.out");
    f>>n;
    for (i=1;i<=n+1;i++)
    for (j=1;j<=i;j++) {
        f>>x;
        m[i][j]=x;
    }

    a[1][1]=m[1][1];
    for (i=2;i<=n+1;i++)
    for (j=1;j<=i;j++)
    a[i][j]=m[i][j]+maxim(a[i-1][j-1],a[i-1][j]);
    nr1=0;nr2=0;
    for (i=1;i<=n+1;i++)
    if (a[n+1][i]>nr1) {nr1=a[n+1][i];nr2=a[1][1];}

    b[n+1][1]=m[n+1][1];
    for (i=n+1;i>=1;--i)
    for (j=1;j<=i;j++)
    b[i][j]=m[i][j]+maxim(b[i+1][j],b[i][j-1]);
    for (i=1;i<=n+1;i++) {
    if (b[i][i]>nr1) {nr1=b[i][i];nr2=b[n+1][1];}
    else
    if (b[i][i]==nr1 && b[n+1][1]<nr2) nr2=b[n+1][1];
    }

    c[n+1][n+1]=m[n+1][n+1];
    for (i=n+1;i>=1;--i)
    for (j=i;j>=1;--j)
    c[i][j]=m[i][j]+maxim(c[i][j+1],c[i+1][j+1]);
    for (i=1;i<=n+1;i++) {
    if (c[i][1]>nr1) {nr1=c[i][1];nr2=c[n+1][n+1];}
    else
    if (c[i][1]==nr1 &&c[n+1][n+1]<nr2) nr2=c[n+1][n+1];
    }

    g<<nr1<<'\n';
    g<<nr2;


    f.close();
    g.close();
    return 0;
}

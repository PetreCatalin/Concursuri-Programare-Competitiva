#include <fstream>

using namespace std;

long int n,d[505],i,j,k,x,minim,a[505][505];

int main()
{
    ifstream f("podm.in");
    ofstream g("podm.out");
    f>>n;
    for (i=0;i<=n;i++)
    f>>d[i];
    for (i=1;i<=n;i++)
        a[i][i+1]=d[i-1]*d[i]*d[i+1];
    for (x=2;x<=n;x++)
        for (i=1;i<=n-x+1;i++) {
        j=i+x-1;
        minim=1000000;
        for (k=i;k<j;k++)
            if (a[i][k]+a[k+1][j]+d[i-1]*d[k]*d[j]<minim) minim=a[i][k]+a[k+1][j]+d[i-1]*d[k]*d[j];
        a[i][j]=minim;
        }

    g<<a[1][n];
    f.close();
    g.close();
    return 0;
}

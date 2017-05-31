#include <fstream>

using namespace std;

int a[100][100],b[100][100],n,i,j;

int main()
{
    ifstream f("pdt.in");
    ofstream g("pdt.out");
    f>>n;

    for (i=1;i<=n;i++)
        for (j=1;j<=i;j++)
        f>>a[i][j];

    for (i=1;i<=n;i++)
    b[n][i]=a[n][i];

    for (i=n-1;i>=1;--i)
        for (j=1;j<=i;j++) {
        if (b[i+1][j]>=b[i+1][j+1]) b[i][j]=a[i][j]+b[i+1][j];
        else b[i][j]=a[i][j]+b[i+1][j+1];
        }
    g<<b[1][1];
    f.close();
    g.close();
    return 0;
}

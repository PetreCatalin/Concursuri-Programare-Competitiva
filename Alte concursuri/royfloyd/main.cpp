#include <fstream>

using namespace std;

long int n,i,j,k,a[103][103];

int main()
{
    ifstream f("royfloyd.in");
    ofstream g("royfloyd.out");
    f>>n;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++) {
        f>>a[i][j];
        if (a[i][j]==0) a[i][j]=1000000;
        }

    for (k=1;k<=n;k++)
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
            if (a[i][j]>a[i][k]+a[k][j]) a[i][j]=a[i][k]+a[k][j];

    for (i=1;i<=n;i++) {
        for (j=1;j<=n;j++) {
            if (i==j) g<<'0'<<' ';
            else {
                if (a[i][j]==1000000) g<<'0'<<' ';
                else
                g<<a[i][j]<<' ';
            }
        }
        g<<'\n';
    }

    f.close();
    g.close();
    return 0;
}

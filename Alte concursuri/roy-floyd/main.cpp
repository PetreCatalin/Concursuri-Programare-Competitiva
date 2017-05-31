#include <fstream>

using namespace std;

long int d[100][100],i,j,n,k;

int main()
{
    ifstream f("rf.in");
    ofstream g("rf.out");
    f>>n;
    for (i=1;i<=n;i++)
    for (j=1;j<=n;j++) {
        f>>d[i][j];
        if (d[i][j]==0) d[i][j]=10000;
    }

    for (k=1;k<=n;k++)
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
                if (i!=j && d[i][j]>d[i][k]+d[k][j]) d[i][j]=d[i][k]+d[k][j];

    for (i=1;i<=n;i++) {
    for (j=1;j<=n;j++) {
        if (d[i][j]==10000) g<<'0'<<' ';
        else g<<d[i][j]<<' ';
    }
    g<<'\n';
    }

    f.close();
    g.close();
    return 0;
}

#include <fstream>

using namespace std;

ifstream f("parcadancime.in");
ofstream g("parcadancime.out");

long int i,j,n,x,a[100][100],viz[100];

void df(int i)
{
    int k;
    g<<i<<' ';
    viz[i]=1;
    for (k=1;k<=n;k++)
        if (a[i][k]==1 &&viz[k]==0)
        df(k);
}

int main()
{
    f>>n;
    for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    f>>a[i][j];
    df(1);

    f.close();
    g.close();
    return 0;
}

#include <fstream>

using namespace std;

ifstream f("ga.in");
ofstream g("ga.out");

long int n,m,sol[20];
int ok(int k)
{
    int i;
    for (i=1;i<k;i++)
    if (sol[i]==sol[k]) return 0;
    return 1;
}

void back(int k)
{
    int i,j;
    if (k>m) {
        for (j=1;j<=m;j++) g<<sol[j]<<' ';
        g<<'\n';
    }
    else
    for (i=1;i<=n;i++) {
        sol[k]=i;
        if (ok(k)) back(k+1);
    }
}

int main()
{
    f>>n>>m;
    back(1);

    f.close();
    g.close();
    return 0;
}

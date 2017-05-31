#include <fstream>

using namespace std;

long int n,m,nr,numar,i,j,x,y,z,sol[100],a[100][100],s;

ifstream f("izvor.in");
ofstream g("izvor.out");

int ok(int k)
{
    int i;
    for (i=1;i<=k-1;i++)
    if (sol[i]==sol[k]) return 0;
    return 1;
}

void back(int k)
{
    int i,j;
    bool ok1;
    if (k>m) {
        ok1=true;
         if (a[sol[k-1]][sol[1]]==0) ok1=false;
         if (ok1==true) {
             for (j=1;j<=k-2;j++)
             if (a[sol[j]][sol[j+1]]==2) {numar++;break;}
         }
    }
        else
        for (i=1;i<=n;i++)
            if (a[sol[k-1]][i]!=0) {
                sol[k]=i;
                if (ok(k)) back(k+1);
            }
}

int main()
{

    f>>n>>nr>>m;
    for (i=1;i<=nr;i++) {
        f>>x>>y>>z;
        a[x][y]=z+1;
        a[y][x]=z+1;
    }

    for (s=1;s<=n;s++) {
        sol[1]=s;
        back(2);
    }
    g<<numar;

    f.close();
    g.close();
    return 0;
}

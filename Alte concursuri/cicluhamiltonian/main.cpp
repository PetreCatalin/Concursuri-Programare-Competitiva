#include <fstream>
#include <vector>

using namespace std;

vector <long int >a[1000];

long int n,m,x,y,i,sol[1000];

ifstream f("ch.in");
ofstream g("ch.out");

inline long int ok(long int k)
{
    long int i;
    for (i=1;i<=k-1;i++)
    if (sol[i]==sol[k]) return 0;
    bool ok=false;
    for (i=0;i<a[sol[k-1]].size();i++)
        if (a[sol[k-1]][i]==sol[k]) {ok=true;break;}
    if (k==1) ok=true;
    if (ok==false) return 0;
    else
    return 1;
}

inline void back(long int x)
{
    long int i,j;
    if (x>n) {
        for (j=1;j<=n;j++)
        g<<sol[j]<<' ';
        g<<'\n';
    }
    else
    for (i=1;i<=n;i++) {
        sol[x]=i;
        if (ok(x)) back(x+1);
        }
}

int main()
{
    f>>n>>m;
    for (i=1;i<=m;i++) {
        f>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    back(1);

    f.close();
    g.close();
    return 0;
}

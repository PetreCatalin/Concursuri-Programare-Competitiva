#include <fstream>
#include <algorithm>

int  n,i;

struct nod {
    int x;
    int y;
}a[1000];

bool cmp (const nod &a,const nod&b)
{
    if (a.x==b.x) return (a.y<b.y);
    else
    return (a.x<b.x);
}

using namespace std;

int main()
{
    ifstream f("sortalg.in");
    ofstream g("sortalg.out");
    f>>n;
    for (i=1;i<=n;i++)
    f>>a[i].x;
    for (i=1;i<=n;i++)
    f>>a[i].y;
    sort (a+1,a+n+1,cmp);
    for (i=1;i<=n;i++)
    g<<a[i].x<<' ';
    g<<'\n';
    for (i=1;i<=n;i++)
    g<<a[i].y<<' ';

    f.close();
    g.close();
    return 0;
}

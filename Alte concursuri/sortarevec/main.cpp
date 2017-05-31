#include <fstream>
#include <algorithm>

using namespace std;

struct{
    int x,y;
}

bool cmp( struct &a,struct &b)
{
    if (a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}

long int n,i;

int main()
{
    ifstream f("sv.in");
    ofstream g("sv.out");
    f>>n;
    for (i=1;i<=n;i++)
        f>>a[i].x>>a[i].y;

    sort(a+1,a+n+1,cmp);

    f.close();
    g.close();
    return 0;
}

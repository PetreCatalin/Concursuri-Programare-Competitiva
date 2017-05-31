#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;
#define EPS 0.000000001

long n,i,rez,j;

struct per{
    double x;
    double y;
}v[1005];

inline bool cmp(per a,per b)
{
    if (fabs(a.x-b.x)<=EPS)
        return a.y<b.y;
    return a.x<b.x;
}

int cautbin(per a)
{
    int st,dr,mij;
    st=1;dr=n;
    while (st<=dr) {
        mij=(st+dr)/2;
        if (fabs(v[mij].x-a.x)<=EPS &&fabs(v[mij].y-a.y)<=EPS) return 1;
        else
        if (cmp(a,v[mij])) dr=mij-1;
        else
        st=mij+1;
    }
    return 0;
}

int main()
{
    ifstream f("patrate3.in");
    ofstream g("patrate3.out");
    f>>n;
    for (i=1;i<=n;++i)
        f>>v[i].x>>v[i].y;

    sort(v+1,v+n+1,cmp);

    for (i=1;i<=n-1;++i)
        for (j=i+1;j<=n;++j) {
             per pct1, pct2;
            pct1.x = v[i].x + v[i].y - v[j].y;
            pct1.y = v[i].y + v[j].x - v[i].x;
            pct2.x = v[j].x + v[i].y - v[j].y;
            pct2.y = v[j].y + v[j].x - v[i].x;

            if (cautbin(pct1)==1 &&cautbin(pct2)==1) ++rez;
        }

    g<<rez/2;

    f.close();
    g.close();
    return 0;
}

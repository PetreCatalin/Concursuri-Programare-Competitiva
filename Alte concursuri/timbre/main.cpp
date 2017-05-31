#include <cstdio>
#include <algorithm>

struct pereche{
    int x;
    int c;
}a[10005];

inline bool cmp(pereche a,pereche b)
{
    return a.c<b.c;
}

using namespace std;

int n,m,i,k,v[10005];
long cost;

int main()
{
    freopen ("timbre.in","r",stdin);
    freopen ("timbre.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for (i=1;i<=m;++i)
        scanf("%d%d",&a[i].x,&a[i].c);

    sort(a+1,a+m+1,cmp);

    while (n>0) {
        for (i=1;i<=m;++i)
            if (v[i]==0 &&a[i].x>=n) {
                cost+=a[i].c;
                v[i]=1;
                n=n-k;
                break;
            }
    }

    printf("%d",cost);

    fclose(stdin);
    fclose(stdout);
    return 0;
}

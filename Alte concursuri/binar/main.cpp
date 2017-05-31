#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int i,n,m,j,v[2002];
char s[2002][2002];

inline void merge(int st,int dr,int l)
{
    int i,nr=0;
    if (dr<=st) return;
    if (l>n) return;
    for(i=st;i<=dr;++i)
        if(s[l][v[i]]=='0')
    {
        swap(v[i],v[nr+st]);
         ++nr;
    }
    merge(st,nr+st-1,l+1);
    merge(nr+st,dr,l+1);
}

int main()
{
    freopen("binar.in","r",stdin);
    freopen("binar.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (i=0;i<=n;++i)
        gets(s[i]);
    for (i=0;i<=m-1;++i)
        v[i]=i;

    merge(0,m-1,0);

    for (i=0;i<=m-1;++i)
        printf("%d ",v[i]+1);

    fclose(stdin);
    fclose(stdout);
    return 0;
}



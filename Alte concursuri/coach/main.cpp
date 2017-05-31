#include<cstdio>
#include<algorithm>

using namespace std;

long a,b,k,i,j,n,m,t,p,s,d,poz[102],u[102],A[102][102],B[102][102];

struct per
{
    long x,y;
}v[102];

long cmp(per a,per b)
{
        return a.x<b.x;
}

bool royfloyd(long p)
{
    long i,j,k;
    for (i=p;i<=n-1;++i)
        for(j=i+1;j<=n;++j) {
            B[i][j]=A[i][j];
            B[j][i]=A[i][j];
        }

    for (k=p;k<=n;++k) {
            for (i=p;i<=n;++i)
                for(j=p;j<=n;++j)
                    if ((!B[i][j] || B[i][j]>B[i][k]+B[k][j]) && B[i][k] && B[k][j]) B[i][j]=B[i][k]+B[k][j];

        for (i=p;i<=k;++i)
            for (j=p;j<=k;++j)
                if (B[i][j]==t) {
                    printf("%d %d %d %d\n",u[i],u[j],v[p].x,v[k].x);
                    return true;
                }
    }
    return false;
}

int main()
{
    freopen("coach.in","r",stdin);
    freopen("coach.out","w",stdout);
    scanf("%d%d%d",&n,&m,&t);
    for (i=1;i<=n;++i) {
        scanf("%d",&v[i].x);
        v[i].y=i;
    }
    sort(v+1,v+n+1,cmp);

    for (i=1;i<=n;++i) {
        poz[v[i].y]=i;
        u[i]=v[i].y;
    }

    for (i=1;i<=m;++i) {
        scanf("%d%d%d",&a,&b,&k);
        A[poz[a]][poz[b]]=k;
        A[poz[b]][poz[a]]=k;
    }

    for (i=1;i<=n;++i)
        if (royfloyd(i)) return 0;

    fclose(stdin);
    fclose(stdout);
}

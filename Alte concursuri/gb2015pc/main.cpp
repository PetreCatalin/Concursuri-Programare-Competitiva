#include <bits/stdc++.h>

using namespace std;

long long n,m,i,j,a[505][505],b[505][505],q,x,y,xx,yy,nr,k;
char c;

int main()
{
    cin>>n>>m;
    for (i=1;i<=n;++i)
        for (j=1;j<=m;++j) {
            cin>>c;
            if (c=='#') {
                    a[i][j]=-1;
                    b[i][j]=-1;
            }
        }

    for (i=1;i<=n;++i)
        for (j=2;j<=m;++j)
            if (a[i][j-1]!=-1 &&a[i][j]!=-1) a[i][j]=1;

    for (i=2;i<=n;++i)
        for (j=1;j<=m;++j)
        if (b[i-1][j]!=-1 &&b[i][j]!=-1) b[i][j]=1;

    for (i=1;i<=n;++i)
        for (j=1;j<=m;++j) {
        if (a[i][j]==-1) a[i][j]=0;
        if (b[i][j]==-1) b[i][j]=0;
    }

    for (i=1;i<=n;++i)
        for (j=1;j<=m;++j)
        a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];

     for (i=1;i<=n;++i)
        for (j=1;j<=m;++j)
         b[i][j]=b[i][j]+b[i-1][j]+b[i][j-1]-b[i-1][j-1];


    cin>>q;
    for (k=1;k<=q;++k) {
            cin>>x>>y>>xx>>yy;
            ++y;
            nr=a[xx][yy]+a[x-1][y-1]-a[x-1][yy]-a[xx][y-1];
            --y;
            ++x;
            nr=nr+b[xx][yy]+b[x-1][y-1]-b[x-1][yy]-b[xx][y-1];
            cout<<nr<<'\n';
    }

    return 0;
}


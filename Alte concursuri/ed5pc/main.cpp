#include <bits/stdc++.h>

using namespace std;

long long i,j,n,m,nr,x,viz[1002][1002];
char a[1002][1002];

long fill (int x,int y) {
    ++nr;
    viz[x][y]=1;
    if (a[x+1][y]=='.' &&viz[x+1][y]==0) fill(x+1,y);
    if (a[x-1][y]=='.' &&viz[x-1][y]==0) fill(x-1,y);
    if (a[x][y+1]=='.' &&viz[x][y+1]==0) fill(x,y+1);
    if (a[x][y-1]=='.' &&viz[x][y-1]==0) fill(x,y-1);
    return nr;
}

int main()
{
    scanf("%d%d\n",&n,&m);
    for (i=1;i<=n;++i)
        for (j=1;j<=m;++j)
        scanf("%c",&a[i][j]);

    for (i=1;i<=n;++i) {
        for (j=1;j<=m;++j) {
        if (a[i][j]=='.') cout<<a[i][j];
        else {
        nr=0;
        a[i][j]='.';
        x=fill(i,j);
        cout<<x%10;
        a[i][j]='*';
        }
        }
        cout<<'\n';
    }

    return 0;
}

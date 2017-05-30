#include <bits/stdc++.h>

using namespace std;

long n,m,i,nr,j,x,y;

int main()
{
    cin>>n>>m;
    for (i=1;i<=n;++i)
    for (j=1;j<=m;++j) {
        cin>>x>>y;
        if (x==1 ||y==1) ++nr;
    }

    cout<<nr;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

long long n,m,i,j,x,minim,nr,maxim;

int main()
{
    cin>>n>>m;
    for (i=1;i<=n;++i) {
        cin>>x;
        minim=x;
        for (j=2;j<=m;++j) {
            cin>>x;
            if (x<minim) minim=x;
        }
        if (minim>maxim) maxim=minim;
    }

    cout<<maxim;

    return 0;
}

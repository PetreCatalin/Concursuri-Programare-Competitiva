#include <bits/stdc++.h>

using namespace std;

long long n,m,i,x,v[12],rez;

int main()
{
    cin>>n>>m;
    for (i=1;i<=n;++i) {
        cin>>x;
        ++v[x];
    }

    for (i=1;i<=10;++i)
    {
        if (v[i]!=0) {
            n=n-v[i];
            rez=rez+v[i]*n;
        }
    }

    cout<<rez;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

long long n,i,x,v[100005],poz[100005],m=1;

int main()
{
    cin>>n;
    for (i=1;i<=n;++i) {
        cin>>x;
        poz[x]=i;
    }

    v[1]=1;
    for (i=2;i<=n;++i) {
        if (poz[i]>poz[i-1]) {
                v[i]=v[i-1]+1;
                if (v[i]>m) m=v[i];
        }
        else
        v[i]=1;
    }

    cout<<n-m;
            return 0;
}

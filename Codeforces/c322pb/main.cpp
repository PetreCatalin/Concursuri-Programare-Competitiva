#include <bits/stdc++.h>

using namespace std;

long long n,a[100005],i,m,b[100005];

int main()
{
    cin>>n;
    for (i=1;i<=n;++i)
        cin>>a[i];
    m=a[n];
    b[n]=m;
    for (i=n-1;i>=1;--i) {
            if (a[i]>m) m=a[i];
            b[i]=m;
    }

    for (i=1;i<=n;++i)
        if (b[i]==a[i] &&b[i+1]!=b[i]) cout<<'0'<<' ';
        else
        if (b[i]==a[i] &&b[i+1]==b[i]) cout<<'1'<<' ';
        else
        cout<<b[i]-a[i]+1<<' ';
    return 0;

}

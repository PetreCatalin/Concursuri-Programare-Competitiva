#include <bits/stdc++.h>

using namespace std;

long long n,k,i,s[100005],sum,m,nr;

int main()
{
    cin>>n>>k;
    for (i=1;i<=n;++i)
        cin>>s[i];

    if (k>=n) cout<<s[n];
    else {
        nr=n;
        while ((nr-1)<=2*(k-1)) {--nr;--k;}

    m=s[n];
    for (i=1;i<=nr/2;++i) {
        sum=s[i]+s[nr-i+1];
        if (sum>m) m=sum;
    }
    if (s[nr/2+1]>m) m=s[nr/2]+1;

    cout<<m;
    }

    return 0;
}

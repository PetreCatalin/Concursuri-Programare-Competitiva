#include <bits/stdc++.h>

using namespace std;

long long n,h[100005],i,x,ma,mi,nr,a[100005],j;

int main()
{
    cin>>n;
    for (i=1;i<=n;++i) {
        cin>>h[i];
        a[i]=h[i];
    }

    sort(a+1,a+n+1);
    i=1;
    while (i<=n) {
        if (a[i]==h[i]) ++nr;
    else {
        ma=0;
        for (j=i;j<=n;++j) {
            if (h[j]==a[i]) break;
            if (h[j]>ma) ma=h[j];
        }
        while (a[i]!=ma) ++i;
        ++nr;
    }
    ++i;
    }

    cout<<nr;
    return 0;
}

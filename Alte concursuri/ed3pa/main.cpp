#include <bits/stdc++.h>

using namespace std;

long long n,m,i,a[105],nr;

int main()
{
    cin>>n>>m;
    for (i=1;i<=n;++i)
        cin>>a[i];

    sort(a+1,a+n+1);
    while (m>0) {
            ++nr;
            m-=a[n];
            --n;
    }

    cout<<nr;
    return 0;
}

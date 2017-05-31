#include <iostream>
#include <algorithm>

using namespace std;

int n,a[105],i,s,s1;

int main()
{
    cin>>n;
    for (i=1;i<=n;i++) {
        cin>>a[i];
        s=s+a[i];
    }
    sort(a+1,a+n+1);

    for (i=n;i>=1;i=i-1) {
        s1=s1+a[i];
        s=s-a[i];
        if (s1>s) {cout<<n-i+1;break;}
    }

    return 0;
}

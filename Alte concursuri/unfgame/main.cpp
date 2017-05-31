#include <iostream>
#include <algorithm>

using namespace std;

long long i,n,a[100005],nr,s;

int main()
{
    cin>>n;

    if (n==1) {
        cin>>a[1];
        cout<<a[1];
    }
    else {
    for (i=1;i<=n;++i) {
        cin>>a[i];
        if (a[i]<0) ++nr;
        else s+=a[i];
    }

    sort(a+1,a+n+1);

    for (i=2;i<=nr;i+=2)
        s+=a[i];


    cout<<s;
    }

    return 0;
}

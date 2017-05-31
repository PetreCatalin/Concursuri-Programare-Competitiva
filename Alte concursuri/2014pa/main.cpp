#include <iostream>

using namespace std;

long n,a[30005],i,nr,t,poz;

int main()
{
    cin>>n>>t;
    for (i=1;i<=n-1;++i)
        cin>>a[i];
    poz=1;
    while (poz<t)
        poz=poz+a[poz];

    if (poz==t) cout<<"YES";
    else
    cout<<"NO";

    return 0;
}

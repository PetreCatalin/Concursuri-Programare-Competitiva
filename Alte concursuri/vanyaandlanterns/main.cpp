#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

long n,i;
long long v[1003],l,poz;
double maxim,maximinit;

int main()
{
    cin>>n>>l;
    for (i=1;i<=n;++i)
        cin>>v[i];

    sort(v+1,v+n+1);
    maximinit=max(v[1],l-v[n]);
    maxim=0;

    for (i=2;i<=n;++i)
        if (v[i]-v[i-1]>maxim) maxim=v[i]-v[i-1];

        maxim=(double) maxim/2;
        if (maxim>maximinit)
        cout<<setprecision(9)<<(double) maxim;
        else
        cout<<setprecision(9)<<(double) maximinit;

    return 0;
}

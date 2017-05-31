#include <iostream>

using namespace std;

int n,i,v[1005],x,maxim,nr;

int main()
{
    cin>>n;
    for (i=1;i<=n;i++) {
        cin>>x;
        if (v[x]==0) nr++;
        v[x]++;
        if (v[x]>maxim) maxim=v[x];
    }

    cout<<maxim<<' '<<nr;
    return 0;
}

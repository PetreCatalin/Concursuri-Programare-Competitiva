#include <iostream>
#include <algorithm>

using namespace std;

int n,k,v[2005],i,nr;

int main()
{
    cin>>n>>k;
    for (i=1;i<=n;i++)
        cin>>v[i];
    sort(v+1,v+n+1);

    v[n+1]=6;
    v[n+2]=6;
    v[n+3]=6;

    for (i=1;i<=n;i=i+3)
        if (v[i]+k<=5 &&v[i+2]+k<=5) nr++;

    cout<<nr;

    return 0;
}

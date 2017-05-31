#include <iostream>
#include <algorithm>

using namespace std;

long n,k,i,v[2005],nr;

int main()
{
    cin>>n>>k;
    for (i=1;i<=n;++i) {
        cin>>v[i];
        if (v[i]+k<=5) nr++;
    }

    cout<<nr/3;

    return 0;
}

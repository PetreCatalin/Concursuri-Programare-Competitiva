#include <iostream>
#include <algorithm>

using namespace std;

int a[15],i,k,s,nr;

int main()
{
    cin>>k;
    for (i=1;i<=12;i++)
        cin>>a[i];
    if (k==0) cout<<'0';
    else {
        sort(a+1,a+13);
        for (i=12;i>=1;i=i-1) {
            s=s+a[i];
            nr++;
            if (s>=k) {cout<<nr;break;}
        }
        if (s<k) cout<<"-1";
    }

    return 0;
}

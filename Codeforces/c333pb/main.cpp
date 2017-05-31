#include <bits/stdc++.h>

using namespace std;

long long n,a[100005],i,j,ma,mi,r,ok,init,x;

int main()
{
    ifstream f("i.in");
    f>>n;
    for (i=1;i<=n;++i)
        f>>a[i];


       r=1;init=1;
    ma=a[1];mi=a[1];a[0]=-1;
    i=2;
        while (i<=n &&i>0) {
        if (r>=n-init+1) break;
        if (a[i]==mi ||a[i]==ma) {++i;continue;}
        if (a[i]<mi) mi=a[i];
        if (a[i]>ma) ma=a[i];
        if (ma-mi>1) {
            if (i-init>r) r=i-init;
            x=a[i-1];
            --i;
            while (a[i]==x) --i;
            ++i;
            init=i;ma=a[i];mi=a[i];
        }
        else
        ++i;
    }

    if (i==n+1 &&ma-mi<=1 &&n-init+1>r) r=n-init+1;
    cout<<r;

    return 0;
}

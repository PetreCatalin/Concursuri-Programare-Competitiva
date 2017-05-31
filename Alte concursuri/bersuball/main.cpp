#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long n,m,i,j,a[103],b[103],nr,x,y;

int main()
{
    cin>>n;
    for (i=1;i<=n;++i)
        cin>>a[i];
    cin>>m;
    for (j=1;j<=m;++j)
        cin>>b[j];

    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    x=1;y=1;
    while (x<=n &&y<=m) {
            if (abs(a[x]-b[y])<=1) {
                    ++nr;
                    ++x;
                    ++y;
            }
            else
                if (a[x]<b[y]) ++x;
            else
                if (b[y]<a[x]) ++y;
    }

    cout<<nr;

    return 0;
}

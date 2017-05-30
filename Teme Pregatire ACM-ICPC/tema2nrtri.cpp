#include <bits/stdc++.h>

using namespace std;

int n,i,a[805],j,k,nr;

int main()
{
    ifstream f("nrtri.in");
    ofstream g("nrtri.out");
    f>>n;
    for (i=1;i<=n;++i)
        f>>a[i];
    sort(a+1,a+n+1);

    for (i=1;i<=n-2;++i)
        for (j=i+1;j<=n-1;++j)
            for (k=j+1;k<=n;++k)
                if (a[k]>a[i]+a[j]) break;
                else
                ++nr;

    g<<nr;
    f.close();
    g.close();
    return 0;
}

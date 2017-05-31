#include <bits/stdc++.h>

using namespace std;

long long n,b,i,a[100005];

int main()
{
    ifstream f("buget.in");
    ofstream g("buget.out");
    f>>n>>b;
    for (i=1;i<=n;++i)
        f>>a[i];

    sort(a+1,a+n+1);
    for (i=1;i<=n;++i)
    if (b/(n-i+1)>=a[i])
            b=b-a[i];
    else break;

    g<<b/(n-i+1);

    f.close();
    g.close();
    return 0;
}

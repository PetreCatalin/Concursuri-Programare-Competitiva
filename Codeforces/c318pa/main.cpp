#include <bits/stdc++.h>

using namespace std;

int n,i,nr,rez,a[102],ok;

int main()
{
    cin>>n;
    for (i=1;i<=n;++i)
        cin>>a[i];
    nr=a[1];rez=nr;a[1]=0;
    sort(a+1,a+n+1);

    ok=1;
    while (ok==1) {
        ok=0;
        for (i=n;i>=2;--i)
        if (a[i]>=nr) {--a[i];++nr;ok=1;}
    }

    cout<<nr-rez;
    return 0;
}

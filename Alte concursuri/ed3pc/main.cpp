#include <bits/stdc++.h>

using namespace std;

long long n,i,a[100005],nr,nr1,rez,rez2,s;
long double m;

int main()
{
    cin>>n;
    for (i=1;i<=n;++i) {
        cin>>a[i];
        s+=a[i];
    }

    m=(long double) s/n;

    if (m==floor(m)) {
            nr=floor(m);
    for (i=1;i<=n;++i)
            if (a[i]<nr) rez+=nr-a[i];
    cout<<rez;
    }

    else {
        nr=floor(m);
        nr1=nr+1;
        for (i=1;i<=n;++i) {
            if (a[i]<nr) rez+=nr-a[i];
            if (a[i]>nr1) rez2+=a[i]-nr1;
        }
        if (rez>rez2) cout<<rez;
        else
        cout<<rez2;
    }

    return 0;
}

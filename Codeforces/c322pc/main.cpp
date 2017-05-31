#include <bits/stdc++.h>

using namespace std;

long long n,k,i,v[10],rez,x,nr;

int main()
{
    cin>>n>>k;
    for (i=1;i<=n;++i) {
        cin>>x;
        ++v[x%10];
        rez+=x/10;
        nr+=100-x;
    }

    if (k>nr) k=nr;

        for (i=9;i>=1;--i)
        if (v[i]!=0) {
            if (v[i]*(10-i)<=k) {k-=v[i]*(10-i);v[0]+=v[i];rez+=v[i];}
            else
            {
                rez+=k/(10-i);
                k=0;
            }
        }

    rez+=k/10;

    cout<<rez;
    return 0;
}

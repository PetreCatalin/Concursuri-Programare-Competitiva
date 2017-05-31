#include <bits/stdc++.h>

using namespace std;

long n,m,k,i,a[100005],b[100005],cur;

int main()
{
    cin>>n>>m>>k;
    for (i=1;i<=m;++i)
        cin>>a[i]>>b[i];

    cur=k;
    for (i=m;i>=1;--i) {
    if (a[i]==cur) {
        if (a[i-1]==b[i] ||b[i-1]==b[i]) cur=b[i];
        else
        {cout<<i;break;}
    }
    else
    if (b[i]==cur) {
        if (a[i-1]==a[i] ||b[i-1]==a[i]) cur=a[i];
        else
        {
            cout<<i;break;
        }
    }
    }

    return 0;
}

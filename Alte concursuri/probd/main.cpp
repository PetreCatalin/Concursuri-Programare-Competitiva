#include <iostream>

using namespace std;

long n,maxim,x,a[200005],i,nr,j;
int v[1000005],ok;

int main()
{
    cin>>n;
    maxim=0;

    if (n==1) {cin>>x;cout<<'0';}
    else
    if (n==2) {
        cin>>a[1]>>a[2];
        if (a[1]>a[2]) cout<<a[1]%a[2];
        else
        cout<<a[2]%a[1];
    }
    if (n>=3) {
    for (i=1;i<=n;i++) {
        cin>>a[i];
        v[a[i]]=1;
    }

    for (i=1;i<=n;i++) {
        ok=0;
        j=2;
        while (ok==0 &&j<=a[i]/2+1) {
        if (v[a[i]/j+1]==1) {
            ok=1;
            nr=a[i]%(a[i]/j+1);
            if (nr<=maxim) {ok=1;break;}
            if (nr>maxim) maxim=nr;
        }
        j++;
        }
    }
    cout<<maxim;
    }

    return 0;
}

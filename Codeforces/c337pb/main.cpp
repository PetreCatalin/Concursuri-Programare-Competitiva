#include <bits/stdc++.h>

using namespace std;

long long i,n,s,a[200005],minim,poz,maxi,x,init,y;

int main()
{
    cin>>n;
    cin>>a[1];
    minim=a[1];
    for (i=2;i<=n;++i) {
        cin>>a[i];
        if (a[i]<minim) minim=a[i];
    }

    maxi=0;
    for (i=1;i<=n;++i) {
        if (a[i]==minim &&poz==0) {init=i;poz=i;x=i+1;}
        else {
            if (a[i]==minim) {
            if (i-poz>maxi &&i-poz>1) {maxi=i-poz;x=poz+1;y=i-1;}
                poz=i;
            }
        }
    }

    if (init+n-poz>maxi &&init+n-poz>1) {maxi=init+n-poz;x=poz+1;y=init-1;}

    if (maxi==0) {cout<<minim*n;}
    else {
    if (x<=y) {
        for (i=1;i<=n;++i)
        if (x<=i &&i<=y) s+=minim+1;
        else
        s+=minim;
    }

    if (y<x) {
        for (i=1;i<=n;++i)
        if (i<=y ||i>=x) s+=minim+1;
        else
        s+=minim;
    }

    cout<<s;
    }

    return 0;
}

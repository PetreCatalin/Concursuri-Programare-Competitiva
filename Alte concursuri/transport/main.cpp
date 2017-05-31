#include <bits/stdc++.h>

using namespace std;

int n,k,i,a[16005],st,dr,mij;

int ok(int mij) {
    int nrp=0,i=1,s;
        while(nrp<=k&&i<=n) {
            s=0;
            while(s+a[i]<=mij) {
                s+=a[i];
                ++i;
            }
            ++nrp;
        }

    if(nrp<=k) return 1;
    return 0;
}

int main()
{
    ifstream f("transport.in");
    ofstream g("transport.out");
    f>>n>>k;
    for (i=1;i<=n;++i) {
        f>>a[i];
        dr+=a[i];
        if (a[i]>st) st=a[i];
    }

    while(st<dr) {
        mij=(st+dr)/2;
        if(ok(mij)) dr=mij;
        else
            st=mij+1;
    }

    g<<st;
    f.close();
    g.close();
    return 0;
}

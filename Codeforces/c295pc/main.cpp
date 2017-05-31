#include <iostream>

using namespace std;

#define mod 1000000007

long nra,nrc,nrg,nrt,n,i,n1,l;
long long r;
char c;

long long combinari(long n,long k)
{
    long i;
    long long kf=1,rez=1;
    for (i=n-k+1;i<=n;++i)
        rez=(rez*i)%mod;
    for (i=2;i<=k;++i)
        kf=(kf*i)%mod;
    rez=(rez/kf)%mod;
    return rez;
}

int main()
{
    cin>>n;
    for (i=1;i<=n;++i) {
        cin>>c;
        if (c=='A') ++nra;
        if (c=='C') ++nrc;
        if (c=='G') ++nrg;
        if (c=='T') ++nrt;
    }

    n1=n;
    r=1;l=0;
    if (nra!=0) {
    r=combinari(n,nra)%mod;
    n=n-nra;
    ++l;
    }
    if (nrc!=0) {
    r=(r*combinari(n,nrc)%mod)%mod;
    n=n-nrc;
    ++l;
    }
    if (nrg!=0) {
    r=(r*combinari(n,nrg)%mod)%mod;
    n=n-nrg;
    ++l;
    }
    if (nrt!=0) {
    r=(r*combinari(n,nrt)%mod)%mod;
    ++l;
    }

    if (l>1) r=(r+l)%mod;

    cout<<r;
    return 0;
}

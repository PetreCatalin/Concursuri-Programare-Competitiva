#include <fstream>

using namespace std;

#define mod 1000000007

long long power(long long a, long  long b)
{
         if(b == 0) return 1;
         if(b == 1) return a;
         long long temp = power(a, b/2)%mod;
         return ((((long long)temp%mod * temp%mod)%mod) * power(a, b%2))%mod;
}

long long t,i,n,x,nrp,nrimp,nr,nr1,nr2,j;

int main()
{
    ifstream f("azerah.in");
    ofstream g("azerah.out");
    f>>t;
    for (i=1;i<=t;++i) {
        f>>n;
        nrp=0;
        nrimp=0;
        for (j=1;j<=n;++j) {
            f>>x;
            if (x%2==0) ++nrp;
            else
            ++nrimp;
        }

    nr1=0;
    nr2=0;
    if (nrp!=0)
    nr1=(power(2,nrp)-1)%mod;
    if (nrimp!=0)
    nr2=(power(2,nrimp-1)-1)%mod;
    nr=((nr1%mod)*(nr2%mod)%mod);
    nr=(nr1+nr2+nr)%mod;

    g<<nr<<'\n';
    }

    f.close();
    g.close();
    return 0;
}

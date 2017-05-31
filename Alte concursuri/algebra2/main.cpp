#include <fstream>

using namespace std;
#define mod 1000000009

long long n,i,rez,nr,x1,x2;

long long power(long long a, long  long b)
{
         if(b == 0) return 1;
         if(b == 1) return a;
         long long temp = power(a, b/2)%mod;
         return ((((long long)temp%mod * temp%mod)%mod) * power(a, b%2))%mod;
}

int main()
{
    ifstream f("algebra2.in");
    ofstream g("algebra2.out");
    f>>n;
    x1=n;x2=x1+1;
    n=n%mod;
    if (x1%2==0) x1=x1/2;
    else
    x2=x2/2;
    nr=power(n,x1)%mod;
    nr=power(nr,x2)%mod;
    g<<nr;

    f.close();
    g.close();
    return 0;
}

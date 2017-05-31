#include <cstdio>

using namespace std;

long long n,t,i,nr,j,x,y;

int main()
{
    freopen("perechi3.in","r",stdin);
    freopen("perechi3.out","w",stdout);
    scanf("%lld",&t);
    for (i=1;i<=t;++i) {
        scanf("%lld",&n);
        nr=n;
        j=2;
        while (j<=n/2) {
            x=n/j;
            y=n/x;
            nr+=x*(y-j+1);
            j=y+1;
        }
        if (n!=1)
        nr+=(n-n/2);
        printf("%lld\n",nr);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include <fstream>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

long long t,k,n,m,x,i,nr,el;
long long s;
long double prob;

int main()
{
    freopen("mafia.in","r",stdin);
    freopen("mafia.out","w",stdout);
    scanf("%d",&t);
    for (k=1;k<=t;++k) {
        scanf("%lld%lld%lld",&n,&m,&x);
        s=0;
        for (i=1;i<=n;++i) {
            scanf("%lld",&el);
            s+=el;
            if (i==x) nr=el;
        }

        prob=0;
            prob = prob + (long double) ((long double)nr/s);
            prob= (long double)(prob*m);

       cout << setprecision(10) << prob << "\n";
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}



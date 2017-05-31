#include <fstream>
#include <cstring>
#include <cstdio>

using namespace std;

long long dp[(1<<18)+2][19],n;
int p,vn[20],sn;

int main()
{
    int i,j,r;
    freopen("ratphu.in","r",stdin);
    freopen("ratphu.out","w",stdout);
    scanf("%lld %d",&n,&p);
    while(n>0){
        vn[sn++]=n%10;
        n/=10;
    }

    for(i=0;i<sn;++i)
        dp[(1<<i)][vn[i]%p]=1;

    for(i=1;i<(1<<sn);++i)
        for(j=0;j<sn;++j)
            if(!(i&(1<<j)) )
            for(r=0;r<p;++r)
                dp[i+(1<<j)][(r*10+vn[j])%p]+=dp[i][r];

    printf("%lld\n",dp[(1<<sn)-1][0]);

    fclose(stdin);
    fclose(stdout);
    return 0;
}

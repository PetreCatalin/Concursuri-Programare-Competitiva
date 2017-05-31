#include <cstdio>

using namespace std;

char s[1005];
long t,i,nr,rez,n,j;

int main()
{
    freopen ("intrare.in","r",stdin);
    freopen ("iesire.out","w",stdout);
    scanf("%d",&t);
    for (i=1;i<=t;++i) {
            rez=0;n=0;
            scanf("%d",&nr);
            gets(s);
            printf("Case #%d: ",i);
            for (j=1;j<=nr+1;++j) {
                if (s[j]!='0') {
                        if (j-1<=n) n+=(s[j]-'0');
                else
                    {
                        rez+=j-1-n;
                        n+=j-1-n;
                        n+=(s[j]-'0');
                    }
                }
            }
            printf("%d\n",rez);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

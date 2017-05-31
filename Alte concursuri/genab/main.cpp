#include <cstdio>

using namespace std;

int sol[23],n,i,j,poz,k;
bool ok;

int main()
{
    freopen ("genab.in","r",stdin);
    freopen ("genab.out","w",stdout);
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    printf("a");
    printf("\n");
    sol[n]=1;
    poz=n;
    while (poz>0) {
        ok=true;
        for (i=2;i<=n;i++)
        if (sol[i]==1&&sol[i-1]==1) {ok=false;break;}
        if (ok==true) {
        for (i=1;i<=n;i++)
        if (sol[i]==1) printf("b");
        else
        printf("a");
        printf("\n");
        }
        if (poz==n) {
            while (sol[poz]==1) {sol[poz]=0;--poz;}
            sol[poz]=1;
        }
        else
        if (poz!=n) {
            while (sol[poz+1]==0&&poz+1<n+1) poz++;
            sol[poz]=1;
        }
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}

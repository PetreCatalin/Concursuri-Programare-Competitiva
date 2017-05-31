#include <cstdio>

using namespace std;

int n,sol[30];

void back(int k,int nr)
{
    int i,j;
    if (k>n) {for (j=1;j<=k-1;j++) printf("%d ",sol[j]); printf("\n");}
    else {
        for (i=1;i<=nr;i++) {
            sol[k]=i;back(k+1,nr);
        }
        sol[k]=nr+1;back(k+1,nr+1);
    }
}

int main()
{
    freopen ("subm.in","r",stdin);
    freopen ("subm.out","w",stdout);
    scanf("%d",&n);
    back(1,0);

    fclose(stdin);
    fclose(stdout);
    return 0;
}

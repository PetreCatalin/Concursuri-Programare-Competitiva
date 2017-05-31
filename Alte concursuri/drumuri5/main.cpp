#include <cstdio>
#include <vector>

using namespace std;

vector <long long> g[150005],tr[150005],el;
long long i,n,m,x,y,viz[150005],viz1[150005],nr,j;

void df1(int x)
{
    int i;
    viz[x]=1;
    for (i=0;i<g[x].size();++i)
        if (viz[g[x][i]]==0) df1(g[x][i]);
}

void df2(int x)
{
    int i;
    viz1[x]=1;
    for (i=0;i<tr[x].size();++i)
        if (viz1[tr[x][i]]==0) df2(tr[x][i]);
}

int main()
{
    freopen ("drumuri5.in","r",stdin);
    freopen ("drumuri5.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (i=1;i<=m;++i) {
            scanf("%d%d",&x,&y);
            g[x].push_back(y);
            tr[y].push_back(x);
    }

    for (i=1;i<=n;++i) {
        nr=0;
        df1(i);
        df2(i);
        for (j=1;j<=n;++j)
                if (viz[j]==1 || viz1[j]==1) ++nr;
        if (nr==n) el.push_back(i);

        for (j=1;j<=n;++j) {
            if (viz[j]!=0) viz[j]=0;
            if (viz1[j]!=0) viz1[j]=0;
        }
    }

    printf("%d\n",el.size());
    for (i=0;i<el.size();++i)
        printf("%d ",el[i]);

    fclose(stdin);
    fclose(stdout);
    return 0;
}

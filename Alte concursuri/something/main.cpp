#include <cstdio>
#include <vector>

using namespace std;

vector <int> g[100005];
int el,i,x,y,n,m,viz[100005],cul[100005],st[100005],nr,ok;

inline void df(int x,int nr)
{
    int i;
    cul[x]=nr;
    for (i=0;i<g[x].size();++i)
        if (cul[g[x][i]]==0) df(g[x][i],nr);
}

inline void cautciclu(int x)
{
    st[++nr]=x;
    int i;
    for (i=0;i<g[x].size();++i) {
        if (ok==1) return;
        if (g[x][i]!=st[nr-1] &&ok!=1) {
            if (viz[g[x][i]]==0) {
                viz[g[x][i]]=1;
                cautciclu(g[x][i]);
            }
        else {
            el=g[x][i];
            while (st[nr-1]!=el) {
                cul[st[nr]]=1;
                --nr;
            }
            ok=1;
            cul[el]=2;
            cul[st[nr]]=3;
             df(el,2);
             df(st[nr],3);
            return ;
        }
    }
    }
    --nr;
}

int main()
{
    freopen ("something.in","r",stdin);
    freopen ("something.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (i=1;i<=m;++i) {
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    viz[1]=1;
    cautciclu(1);
    if (ok==0) printf("-1");
    else {
        for (i=1;i<=n;++i)
        if (cul[i]==0) cul[i]=1;
    for (i=1;i<=n;++i)
        printf("%d ",cul[i]);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

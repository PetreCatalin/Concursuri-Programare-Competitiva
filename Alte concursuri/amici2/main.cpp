#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

vector <long> v[21005];
long k,i,n,m,j,x,y,viz[21005],maxim,t,nr,nod,c[21005],inc,sf,sf1;

int main()
{
    freopen("amici2.in","r",stdin);
    freopen("amici2.out","w",stdout);
    scanf("%d",&t);
    for (k=1;k<=t;++k) {
        scanf("%d%d",&n,&m);
        for (i=1;i<=m;++i) {
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }

        c[1]=1;
        viz[1]=1;
        inc=1;sf=1;nr=0;maxim=0;sf1=1;

        while (inc<=sf) {
            ++nr;
        for (i=inc;i<=sf;++i) {
            x=c[i];
        for (j=0;j<v[x].size();++j)
            if (viz[v[x][j]]==0) {
                ++sf1;
                c[sf1]=v[x][j];
                viz[v[x][j]]=1;
                if (nr>maxim) {maxim=nr;nod=v[x][j];}
            }
        }
            inc=sf+1;
            sf=sf1;
        }

        memset(viz,0,sizeof(viz));

        c[1]=nod;
        viz[nod]=1;
        inc=1;sf=1;nr=0;maxim=0;sf1=1;

        while (inc<=sf) {
            ++nr;
        for (i=inc;i<=sf;++i) {
            x=c[i];
        for (j=0;j<v[x].size();++j)
            if (viz[v[x][j]]==0) {
                ++sf1;
                c[sf1]=v[x][j];
                viz[v[x][j]]=1;
                if (nr>maxim) maxim=nr;
            }
        }
            inc=sf+1;
            sf=sf1;
        }

        nr=log2(maxim);
        printf("%d\n",nr);

        memset(viz,0,sizeof(viz));

      //  memset(v,0,sizeof(v));
      for (i=1;i<=n;++i)
            v[i].erase(v[i].begin(),v[i].end());
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

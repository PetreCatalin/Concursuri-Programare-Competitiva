#include <fstream>

using namespace std;

#define val 205

int t[val],st[val],c[val][val],viz[val*6],i,n,x,y,j,k,m;

int bf(int s,int d)
{
    int i,j;
    st[(k=1)]=s;
    for(i=0;i<=d;++i)
        viz[i]=0;
    viz[s]=1;

    for(i=1;i<=k;++i)
        for(j=0;j<=d;++j)
            if (c[st[i]][j]>0 && viz[j]==0) {
                viz[j]=1;
                st[++k]=j;
                t[j]=st[i];
                if (j==d) return 1;
            }

    return 0;
}

void flux(int s,int d)
{
    int nod;
    while (bf(s,d)) {
        nod=d;
        while (nod) {
            --c[t[nod]][nod];
            ++c[nod][t[nod]];
            nod=t[nod];
        }
    }
}

int main()
{
    ifstream f("harta.in");
    ofstream g("harta.out");
    f>>n;
    for(i=1;i<=n;++i) {
        f>>x>>y;
        c[0][i]=x;
        c[i+n][2*n+1]=y;
    }

    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            if (i!=j) c[i][j+n]=1;

    flux(0,2*n+1);
    m=0;
    for(i=1;i<=n;++i)
      for(int j=1;j<=n;++j)
        if (i!=j && c[i][j+n]==0) ++m;

    g<<m<<" "<<'\n';
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
           if (i!=j&& c[i][j+n]==0) g<<i<<" "<<j<<'\n';

    f.close();
    g.close();
    return 0;
}

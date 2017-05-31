#include <fstream>
#include <cstring>

using namespace std;

int v1[100005],v2[100005],t,ok;
long n,m,i,j,x,y;

int main()
{
    ifstream f("meciul.in");
    ofstream g("meciul.out");
    f>>t;
    for (i=1;i<=t;++i) {
        f>>n>>m;
        for (j=1;j<=n;++j) {
            if (v1[j]!=0) v1[j]=0;
            if (v2[j]!=0) v2[j]=0;
        }
        for (j=1;j<=m;++j) {
            f>>x>>y;
            ok=0;
            if (x!=y) {
            if (v1[x]==0 &&v1[y]==0) {
                v1[x]=1;v1[y]=2;
                v2[x]=2;v2[y]=1;
                ok=1;
            }
            if (v1[x]!=v1[y]) {
                if (v1[y]==0) {
                if (v1[x]==1) v1[y]=2;
                if (v1[x]==2) v1[y]=1;
                if (v2[x]==2) v2[y]=1;
                if (v2[x]==1) v2[y]=2;
                }

                if (v1[x]==0) {
                if (v1[y]==1) v1[x]=2;
                if (v1[y]==2) v1[x]=1;
                if (v2[y]==1) v2[x]=2;
                if (v2[y]==2) v2[x]=1;
                }
            ok=1;
            }
        }

        if (ok==0) g<<"NO"<<'\n';
        else
        g<<"YES"<<'\n';
        }
    }

    f.close();
    g.close();
    return 0;
}

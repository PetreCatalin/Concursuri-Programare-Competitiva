#include <fstream>

using namespace std;

long long c[5000005],i,n,p,nr;
int v[5000005],t,ok,k,j;
int dx[]={2,3,5,7};

int main()
{
    ifstream f("cifre4.in");
    ofstream g("cifre4.out");
    f>>t;
    for (j=1;j<=t;++j) {
        f>>n>>p;
        c[0]=0;nr=0;

        ok=0;
        for (i=0;i<=nr;++i) {
            for (k=0;k<=3;++k) {
            if (v[(c[i]*10+dx[k])%p]==0) {
                c[++nr]=c[i]*10+dx[k];
                v[c[nr]%p]=1;
            }
            if (c[nr]%p==n) {g<<c[nr]<<'\n';ok=1;break;}
            }
            if (ok==1) break;
        }

        if (i>nr) g<<"-1"<<'\n';

        for (i=0;i<=p-1;++i)
            if (v[i]==1) v[i]=0;
    }

    f.close();
    g.close();
    return 0;
}

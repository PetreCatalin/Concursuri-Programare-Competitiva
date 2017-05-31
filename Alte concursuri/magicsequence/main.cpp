#include <fstream>

using namespace std;

long i,t,n,j,k,ok,ok1;
long long v[20005];

int main()
{
    ifstream f("magicsequence.in");
    ofstream g("magicsequence.out");
    f>>t;
    for (i=1;i<=t;++i) {
        f>>n;
        for (j=1;j<=n;++j)
            f>>v[j];
        ok1=1;
        for (j=2;j<=n;++j) {
            ok=0;
            for (k=j-1;k>=1;--k)
                if (v[k]<v[j]) {ok=1;break;}
            if (ok==0) {
                for (k=j+1;k<=n;++k)
                if (v[k]>v[j]) {ok=1;break;}
            }
            if (ok==0) {ok1=0;break;}
        }

        if (ok1==1) g<<"YES"<<'\n';
        else
        g<<"NO"<<'\n';
    }

    f.close();
    g.close();
    return 0;
}

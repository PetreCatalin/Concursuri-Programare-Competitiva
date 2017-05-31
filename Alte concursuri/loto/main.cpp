#include <fstream>
#include <unordered_set>

using namespace std;

unordered_set <long long> h;

long long a[105],i,n,s,nr,ok,j,k;

int main()
{
    ifstream f("loto.in");
    ofstream g("loto.out");
    f>>n>>s;
    for (i=1;i<=n;++i)
        f>>a[i];

    ok=0;
    for (i=1;i<=n;++i) {
        if (ok==1) break;
        for (j=1;j<=n;++j) {
            if (ok==1) break;
            for (k=1;k<=n;++k) {
                h.insert(a[i]+a[j]+a[k]);
                if (h.find(s-a[i]-a[j]-a[k])!=h.end()) {
                    g<<a[i]<<' '<<a[j]<<' '<<a[k]<<' ';
                    nr=s-a[i]-a[j]-a[k];
                    ok=1;break;
                }
            }
        }
    }

        if (ok==0) g<<"-1";
        else {
            ok=0;
            for (i=1;i<=n;++i) {
                if (ok==1) break;
                for (j=1;j<=n;++j) {
                    if (ok==1) break;
                    for (k=1;k<=n;++k)
                        if (a[i]+a[j]+a[k]==nr) {
                        g<<a[i]<<' '<<a[j]<<' '<<a[k];
                        ok=1;
                        break;
                    }
                }
            }
        }

    f.close();
    g.close();
    return 0;
}


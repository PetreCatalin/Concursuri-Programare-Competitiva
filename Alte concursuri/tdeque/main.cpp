#include <fstream>

using namespace std;

long long t,i,n,j,a[20005];

int main()
{
    ifstream f("magicsequence.in");
    ofstream g("magicsequence.out");
    f>>t;
    for (i=1;i<=t;++i) {
        f>>n;
        for (j=1;j<=n;++j)
            f>>a[j];
        if (a[1]>a[n]) g<<"NO"<<'\n';
        else
        g<<"YES"<<'\n';
    }

    f.close();
    g.close();
    return 0;
}

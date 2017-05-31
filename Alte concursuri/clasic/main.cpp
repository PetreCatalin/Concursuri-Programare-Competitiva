#include <fstream>

using namespace std;

long long t,n,i,s,j,x;

int main()
{
    ifstream f("clasic.in");
    ofstream g("clasic.out");
    f>>t;
    for (i=1;i<=t;++i) {
            f>>n;
            s=0;
            for (j=1;j<=n;++j) {
                f>>x;
                s=s^x;
            }
        g<<s<<'\n';
    }

    f.close();
    g.close();
    return 0;
}

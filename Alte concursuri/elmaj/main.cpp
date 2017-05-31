#include <fstream>
#include <vector>

using namespace std;

#define MOD 666013

long long n,loc,i,maxim,el,x;
vector <long> h[666015];

int main()
{
    ifstream f("elmaj.in");
    ofstream g("elmaj.out");
    f>>n;
    for (i=1;i<=n;++i) {
        f>>x;
        loc=x%MOD;
        if (h[loc].size()==0)
            h[loc].push_back(1);
        else
            ++h[loc][0];
        if (h[loc][0]>maxim) {maxim=h[loc][0];el=x;}
    }

    if (maxim>=n/2+1) g<<el<<' '<<maxim;
    else
    g<<"-1";

    f.close();
    g.close();
    return 0;
}

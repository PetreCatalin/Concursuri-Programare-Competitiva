#include <fstream>

using namespace std;

long long t,n,k,i;

int main()
{
    ifstream f("mere.in");
    ofstream g("mere.out");
    f>>t;
    for (i=1;i<=t;++i) {
        f>>n>>k;
        if (n<k) g<<"Remiza"<<'\n';
        else
        if (n%k==0 &&(n/k)%2==0) g<<"Remiza"<<'\n';
        else
        g<<"Santa Klaus"<<'\n';
    }

    f.close();
    g.close();
    return 0;
}

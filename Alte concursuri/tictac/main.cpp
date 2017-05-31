#include <fstream>
#include <cmath>

using namespace std;

#define EPS 0.001

double h,m,minut;
long long i,n;

int main()
{
    ifstream f("tictac.in");
    ofstream g("tictac.out");
    f>>n;
    for (i=1;i<=n;++i) {
        f>>h>>m;
        minut=(double) m/30;
        while (h>=30) h-=30;
        if (fabs(minut*30-h*12)<EPS) g<<"1\n";
        else
        g<<"0\n";
    }

    f.close();
    g.close();
    return 0;
}

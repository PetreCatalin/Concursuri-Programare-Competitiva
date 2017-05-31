#include <fstream>
#include <cmath>

using namespace std;

double x,t;

int main()
{
    ifstream f("geom.in");
    ofstream g("geom.out");
    f>>t;
    x=cos(t);
    g<<x;

    return 0;
}

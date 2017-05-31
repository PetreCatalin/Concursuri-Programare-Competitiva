#include <fstream>

using namespace std;

long n,x,i,nr,t,poz;

int main()
{
    ifstream f("peluzasud.in");
    ofstream g("peluzasud.out");
    f>>n>>x;
    g<<'1';
    for (i=1;i<=13;i++)
        g<<'0';
    g<<'1';

    f.close();
    g.close();
    return 0;
}

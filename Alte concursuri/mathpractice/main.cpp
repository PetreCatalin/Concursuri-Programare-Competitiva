#include <fstream>
#include <cmath>

using namespace std;

long a,b,nr,put,c,ok;

int main()
{
    ifstream f("mathprac.in");
    ofstream g("mathprac.out");
    f>>a>>b;
    nr=a+1;
    put=pow(2,nr);

    ok=0;
    while (ok==0 &&nr<=62) {
        c=put;
        while (c>=10) c=c/10;
        if (c==b) {ok=1;g<<nr;break;}
        nr++;
        put=put*2;
    }

    if (ok==0) g<<'0';

    f.close();
    g.close();
    return 0;
}

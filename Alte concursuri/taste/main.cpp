#include <fstream>
#include <cmath>

using namespace std;

long long x,y,minim,nr,val,poz,x1,x2;

int main()
{
    ifstream f("taste.in");
    ofstream g("taste.out");
    f>>x>>y;
    nr=1;poz=0;
    minim=pow(10,18);
    while (nr<y) {
        if (x%nr==0) val=x/nr;
        else
        val=x/nr+1;
        if (nr*val>y) break;
        if (poz+val<minim &&nr*val<=y) {
            minim=poz+val;
            x2=poz;
            x1=val;
        }
        ++poz;
        nr<<=1;
    }

    g<<x1<<' '<<x2;

    f.close();
    g.close();
    return 0;
}

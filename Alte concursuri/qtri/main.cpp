#include <fstream>
#include <algorithm>

using namespace std;

long double arie(long double x1,long double y1,long double x2,long double y2,long double x3,long double y3)
{
    long double S;
    S=x1*y2+x2*y3+x3*y1-y2*x3-y3*x1-y1*x2;
    S=labs(S);
    S=(long double) S/2;
    return S;
}

#define EPS 0.000001

long q,i,xa,xb,xc,xd,ya,yb,yc,yd;
long double a1,a2,a3,a;

int main()
{
    ifstream f("qtri.in");
    ofstream g("qtri.out");
    f>>q;

    for (i=1;i<=q;++i) {
        f>>xa>>ya>>xb>>yb>>xc>>yc>>xd>>yd;
        a1=arie(xa,ya,xb,yb,xd,yd);
        a2=arie(xa,ya,xc,yc,xd,yd);
        a3=arie(xb,yb,xc,yc,xd,yd);
        a=arie(xa,ya,xb,yb,xc,yc);
        a1=a1+a2+a3;
        if (labs(a-a1)<EPS) g<<"DA"<<'\n';
        else
        g<<"NU"<<'\n';
    }

    f.close();
    g.close();
    return 0;
}

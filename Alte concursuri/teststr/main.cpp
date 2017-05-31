#include <fstream>

using namespace std;

long n,k,i,minim,maxim,maxim1,x;

int main()
{
    ifstream f("teststr.in");
    ofstream g("teststr.out");
    f>>n>>k;

    minim=1000005;
    maxim=-1;
    for (i=1;i<=k;i++) {
        f>>x;
        if (x>maxim) maxim=x;
        if (x<minim) minim=x;
    }

    maxim1=minim;
    if (n-maxim>maxim1) maxim1=n-maxim;

    g<<maxim1;

    f.close();
    g.close();
    return 0;
}

#include <fstream>

using namespace std;

long a[2000010],i,c,n,minim,maxim,nr,x;

int main()
{
    ifstream f("carti3.in");
    ofstream g("carti3.out");
    f>>n>>c;
    for (i=1;i<=c;++i)
        f>>a[1000000+c-i+1];

    minim=1000001;
    maxim=1000001+c-1;
    for (i=1;i<=n;++i) {
        f>>x;
        if (x==-1) ++nr;
        else {
            if (nr%2==0) {
                ++maxim;
                a[maxim]=x;
            }
            else {
                --minim;
                a[minim]=x;
            }
        }
    }

    if (nr%2==1) {
        for (i=minim;i<=maxim;++i)
            g<<a[i]<<'\n';
    }
    else {
        for (i=maxim;i>=minim;--i)
            g<<a[i]<<'\n';
    }

    f.close();
    g.close();
    return 0;
}

#include <fstream>
#include <cmath>

using namespace std;

long i,m,n,x[500005],y[500005],nr,x1,j;
long long minim,z[500005];
char c;

int main()
{
    ifstream f("invazia.in");
    ofstream g("invazia.out");
    f>>n>>m;
    for (i=1;i<=m;++i) {
        f>>c;
        if (c=='I') {
            ++nr;
            f>>x[nr]>>y[nr]>>z[nr];
        }
        if (c=='R') {
            f>>x1;
            minim=pow(10,9)+1;
            for (j=1;j<=nr;++j)
                if (x1>=x[j] &&x1<=y[j] &&z[j]<minim) minim=z[j];
            if (minim==pow(10,9)+1)
            g<<"GUITZZZ!"<<"\n";
            else
            g<<minim<<"\n";
        }
        if (c=='E')
            --nr;
    }

    f.close();
    g.close();
    return 0;
}

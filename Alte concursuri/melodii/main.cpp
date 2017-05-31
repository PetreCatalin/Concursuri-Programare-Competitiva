#include <fstream>

using namespace std;

long long t,r,v[400005],nr,i,per,x;

int main()
{
    ifstream f("melodii.in");
    ofstream g("melodii.out");
    f>>t>>r;
    v[0]=0;v[1]=1;
    nr=2;
    while (1) {
        v[nr]=(v[nr-2]+v[nr-1])%r;
        if (v[nr]==1 &&v[nr-1]==0) {per=nr-1;break;}
        ++nr;
    }

    for (i=1;i<=t;++i) {
        f>>x;
        g<<v[(1+x)%per]<<'\n';
    }

    f.close();
    g.close();
    return 0;
}

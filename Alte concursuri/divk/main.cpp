#include <fstream>

using namespace std;

long int n,k,a,b,i,s[500005],v[500005],nr,minim,j;

int main()
{
    ifstream f("divk.in");
    ofstream g("divk.out");
    f>>n>>k>>a>>b;
    for (i=1;i<=n;i++) {
        f>>v[i];
        s[i]=v[i]+s[i-1];
    }
    nr=0;
    for (i=a;i<=n;i++) {
        if (i-b<0) minim=0;
        else
        minim=i-b;
        for (j=i-a;j>=minim;--j)
        if ((s[i]-s[j])%k==0) nr++;
    }

    g<<nr;

    f.close();
    g.close();
    return 0;
}

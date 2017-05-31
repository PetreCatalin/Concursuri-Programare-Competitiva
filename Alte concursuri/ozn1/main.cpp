#include <fstream>

using namespace std;

long int n,k,i,x,y,z,t,nr,v[2000005],maxim;

int main()
{
    ifstream f("ozn1.in");
    ofstream g("ozn1.out");

    f>>n>>k;
    for (i=1;i<=n;i++) {
        f>>x>>y>>z>>t>>nr;
        v[x]=v[x]+nr;
        v[z+1]=v[z+1]-nr;
        if (z>maxim) maxim=z;
    }

        for (i=2;i<=maxim;i++)
        v[i]=v[i-1]+v[i];
    for (i=1;i<=k;i++) {
        f>>x;
        g<<v[x]<<'\n';
    }

    f.close();
    g.close();
    return 0;
}

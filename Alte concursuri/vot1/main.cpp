#include <fstream>

using namespace std;

long int n,vec[1005],i,j,x,c[1005],a[1005],viz[1005],nr,inc,sf,sf1,t;
bool ok;

int main()
{
    ifstream f("vot1.in");
    ofstream g("vot1.out");
    f>>n;
    for (i=1;i<=n;i++) {
        f>>a[i];
        vec[a[i]]++;
    }

    nr=0;
    ok=true;
    t=n;
    for (i=1;i<=t;i++)
        if (vec[i]==0) {nr++;c[nr]=i;viz[i]=1;--n;}
    inc=1;sf=nr;sf1=sf;
    while (ok==true) {
        ok=false;
        for (i=inc;i<=sf;i++) {
            vec[a[c[i]]]--;
            if (vec[a[c[i]]]==0) {sf1++;c[sf1]=a[c[i]];ok=true;viz[a[c[i]]]=1;--n;}
        }
        inc=sf+1;
        sf=sf1;
    }

    g<<n<<'\n';
    for (i=1;i<=t;i++)
    if (viz[i]==0) g<<i<<' ';

    f.close();
    g.close();
    return 0;
}

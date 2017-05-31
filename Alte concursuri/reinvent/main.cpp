#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector < long int > a[100005];
long int i,j,n,m,x,k,p,inc,sf,sf1,cart[1030],st[200000000],nr,rad[200000000];
bool ok;

int main()
{
    ifstream f("reinvent.in");
    ofstream g("reinvent.out");
    f>>n>>m>>x;
    for (i=1;i<=m;i++) {
        f>>k>>p;
        a[k].push_back(p);
        a[p].push_back(k);
    }
    inc=0;
    for (i=1;i<=x;i++) {
        f>>k;
        cart[k]=1;
        inc++;
        st[inc]=k;rad[inc]=k;
    }

    nr=0;
    ok=true;
    sf=inc;sf1=inc;
    inc=1;

    while (ok==true) {
        nr++;
        for (i=inc;i<=sf;i++) {
            x=st[i];
            for (j=0;j<a[x].size();j++)
                if (a[x][j]!=rad[i]) {sf1++;st[sf1]=a[x][j];rad[sf1]=rad[i];if (cart[a[x][j]]==1) {ok=false;break;}}
        }
        inc=sf+1;
        sf=sf1;
    }
    g<<nr;


    f.close();
    g.close();
    return 0;
}

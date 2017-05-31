#include <fstream>
#include <vector>

using namespace std;

vector <long int> a[100005];

long int n,i,x,y,nr,st[100005],j,inc,sf,sf1,viz[100005],v[100005];
bool ok;

int main()
{
    ifstream f("nivele2.in");
    ofstream g("nivele2.out");
    f>>n;
    for (i=1;i<=n;i++) {
        f>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    st[1]=1;inc=1;sf=1;sf1=1;ok=true;viz[1]=1;nr=0;
    while (ok==true) {
        ok=false;
        nr++;v[nr]=sf;
        for (i=inc;i<=sf;i++)
            for (j=0;j<a[st[i]].size();j++)
                   if (viz[a[st[i]][j]]==0) {sf1++;st[sf1]=a[st[i]][j];viz[a[st[i]][j]]=1;ok=true;}
        inc=sf+1;
        sf=sf1;
    }

    g<<"nivelul 1: 1"<<'\n';
    for (i=2;i<=nr;i++) {
        g<<"nivelul "<<i<<": ";
        for (j=v[i-1]+1;j<=v[i];j++)
            g<<st[j]<<' ';
        g<<'\n';
    }

    f.close();
    g.close();
    return 0;
}

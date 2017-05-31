#include <fstream>
#include <vector>

using namespace std;

 vector <int> v[7600];
long int st[100000],i,j,vec[7600],x,y,n,m,a,b,inc,sf,sf1,viz[7600],poz[100000],k,nr;
bool ok;

int main()
{

    ifstream f("graf.in");
    ofstream g("graf.out");
    f>>n>>m>>a>>b;
    for (i=1;i<=m;i++) {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    st[1]=a;
    inc=1;sf=1;sf1=1;
    ok=false;viz[a]=1;poz[a]=0;
    while (ok==false) {
        for (i=inc;i<=sf;i++)
            for (j=0;j<v[st[i]].size();j++)
            if (viz[v[st[i]][j]]==0) {sf1++;st[sf1]=v[st[i]][j];poz[sf1]=i;  if (v[st[i]][j]==b) ok=true;}
        inc=sf+1;
        sf=sf1;
        for (i=inc;i<=sf;i++)
        if (viz[st[i]]==0) viz[st[i]]=1;
    }

    nr=0;
    for (i=inc;i<=sf;i++)
        if (st[i]==b) {
            nr++;
            x=poz[i];
            while (x!=0) {
                vec[st[x]]++;
                x=poz[x];
            }
        }

    vec[a]=nr;
    vec[b]=nr;

    for (i=1;i<=n;i++)
        if (vec[i]==nr) k++;

    g<<k<<'\n';
    for (i=1;i<=n;i++)
        if (vec[i]==nr) g<<i<<' ';

    f.close();
    g.close();
    return 0;
}

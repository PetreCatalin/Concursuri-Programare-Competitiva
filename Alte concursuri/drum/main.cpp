#include <fstream>
#include <vector>

using namespace std;

vector <long int > a[100005];
long int x,y,n,m,q,inc,sf,sf1,viz[100005],st[100005],i,j,t[100005],poz;
bool ok;

int main()
{
    ifstream f("drum.in");
    ofstream g("drum.out");
    f>>n>>m>>q;
    for (i=1;i<=m;i++) {
        f>>x>>y;
        a[x].push_back(y);
    }

    inc=1;sf=1;sf1=1;
    st[1]=1;ok=true;viz[1]=1;
    while (ok==true) {
        for (i=inc;i<=sf;i++) {
            x=st[i];
            for (j=0;j<a[x].size();j++) {
            if (viz[a[x][j]]==0) {sf1++;st[sf1]=a[x][j];viz[a[x][j]]=1;t[sf1]=i;}
            if (a[x][j]==n) {ok=false;poz=sf1;break;}
            }
        }
        inc=sf+1;
        sf=sf1;
    }

    for (i=inc;i<=sf;i++)
        if (st[i]==n) {
            poz=i;
            while (poz!=1) {
                if (viz[st[poz]]!=2)
                viz[st[poz]]=2;
                poz=t[poz];
            }
        }
    viz[1]=2;

    for (i=1;i<=q;i++) {
        f>>x;
        if (viz[x]==2) g<<'1';
        else
        g<<'0';
        g<<'\n';
    }

    f.close();
    g.close();
    return 0;
}

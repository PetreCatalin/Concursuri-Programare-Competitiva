#include <fstream>
#include <vector>

using namespace std;

ifstream f("domino.in");
ofstream g("domino.out");

vector <long int> v[50005];
long int i,j,n,m,k,a[50005],b[50005],vec[50005],elem[50005],viz[50005];
bool ok;

inline void df(long int k,long int nr)
{
    long int i,j;
    elem[nr]=k;
    viz[k]=1;
    bool ok1;
    if (nr==n &&ok==false) {
        ok=true;
        g<<'1'<<'\n';
        for (j=1;j<=nr;j++)
            g<<elem[j]<<' '<<vec[j]<<'\n';
    }
    for (i=0;i<v[k].size();i++)
        if (viz[v[k][i]]==0) {
            ok1=false;
            if (b[k]==a[v[k][i]] &&vec[nr]==0 &&ok==false) ok1=true;
            if (b[k]==b[v[k][i]] &&vec[nr]==0 &&ok==false) {vec[nr+1]=1;ok1=true;}
            if (a[k]==a[v[k][i]] &&vec[nr]==1 &&ok==false) ok1=true;
            if (a[k]==b[v[k][i]] &&vec[nr]==1 &&ok==false) {vec[nr+1]=1;ok1=true;}
        if (ok1==true) df(v[k][i],nr+1);
        }
    viz[k]=0;
}

int main()
{
    f>>n;
    for (i=1;i<=n;i++) {
        f>>a[i]>>b[i];
        for (j=i-1;j>=1;--j) {
            ok=false;
            if (a[i]==a[j]) ok=true;
            if (a[i]==b[j]) ok=true;
            if (b[i]==a[j]) ok=true;
            if (b[i]==b[j]) ok=true;
            if (ok==true) {
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }

        ok=false;
        for (i=3;i<=n;i++)
            if (ok==false) {viz[i]=1;df(i,1);}
        if (ok==false) g<<'0';

    f.close();
    g.close();
    return 0;
}

#include <fstream>
#include <vector>

using namespace std;

vector <long int > a[100005];
vector <long int > b[100005];
long int n,m,x,y,i,viz1[100005],viz2[100005],nr,comp[100005],j;

inline void df1(long int x)
{
    long int i;
    viz1[x]=1;
    for (i=0;i<a[x].size();i++)
        if (viz1[a[x][i]]==0) df1(a[x][i]);
}

inline void df2(long int x)
{
    long int i;
    viz2[x]=1;
    for (i=0;i<b[x].size();i++)
        if (viz2[b[x][i]]==0) df2(b[x][i]);
}

int main()
{
    ifstream f("ctc.in");
    ofstream g("ctc.out");
    f>>n>>m;
    for (i=1;i<=m;i++) {
        f>>x>>y;
        a[x].push_back(y);
        b[y].push_back(x);
    }

    nr=0;
    for (i=1;i<=n;i++)
        if (comp[i]==0) {
            nr++;
            df1(i);df2(i);
        for (j=1;j<=n;j++) {
            if (viz1[j]!=0 &&viz2[j]!=0 &&viz1[j]==viz2[j]&&comp[j]==0) comp[j]=nr;
            else {
            if (viz1[j]!=0) viz1[j]=0;
            if (viz2[j]!=0) viz2[j]=0;
            }
        }
        }

    g<<nr<<'\n';
    for (i=1;i<=nr;i++) {
    for (j=1;j<=n;j++)
    if (comp[j]==i) g<<j<<' ';
    g<<'\n';
    }

    f.close();
    g.close();
    return 0;
}

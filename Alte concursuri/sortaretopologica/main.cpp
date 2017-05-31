#include <fstream>
#include <vector>

using namespace std;

vector<int> v[15];
int n,m,x,y,i,j,st[100],viz[100],nr;

void df(int k)
{
    int i;
    viz[k]=1;
    for (i=0;i<v[k].size();i++)
        if (viz[v[k][i]]==0) df(v[k][i]);
    st[++nr]=k;
}

int main()
{
    ifstream f("st.in");
    ofstream g("st.out");
    f>>n>>m;
    for (i=1;i<=m;i++) {
        f>>x>>y;
        v[x].push_back(y);
    }
    nr=0;

    for (i=1;i<=n;i++)
        if (viz[i]==0) df(i);

    for (i=nr;i>=1;--i)
    g<<st[i]<<' ';


    f.close();
    g.close();
    return 0;
}

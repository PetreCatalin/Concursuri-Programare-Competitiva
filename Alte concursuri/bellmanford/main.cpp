#include <fstream>
#include <vector>
using namespace std;
ifstream in("bellmanford.in");
ofstream out("bellmanford.out");

vector <int> a[50001],b[50001];
int d[50001],q[2000000],n,m,i,x,y,z,l,k,j,nrq[50001];
bool ok,inq[50001];
int main()
{
    in>>n>>m;
    for(i=1;i<=m;i++)
    {
        in>>x>>y>>z;
        a[x].push_back(y);
        b[x].push_back(z);
    }
    l=1; k=1;
    d[1]=0; q[1]=1;
    for(i=2;i<=n;i++) d[i]=10000000;
    while (l<=k)
    {
        x=q[l++];
        inq[x] = false;
        for(i=0;i<a[x].size();i++)
        {
            y=a[x][i];
            if(d[x]+b[x][i]<d[y])
            {
                d[y]=d[x]+b[x][i];
                if(!inq[y])
                {
                    ++nrq[y];
                    if(nrq[y] == n)
                    {
                         out<<"Ciclu negativ!";
                         return 0;
                    }
                    k++;
                    q[k]=y;
                }
            }
        }
    }
    ok=true;
        for(i=2;i<=n;i++)
            out<<d[i]<<" ";
    return 0;
}

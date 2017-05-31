#include<cstdio>
#include<list>

using namespace std;

int n,i,j,k,x,y,m;
list <int> v[3];

int main()
{
    freopen("grid.in","r",stdin);
    freopen("grid.out","w",stdout);
    scanf("%d %d",&m,&k);
    list<int>::iterator j,it;
    for(i=1;i<=m;i++)
    v[0].push_back(i),v[1].push_back(m+i),v[2].push_back(2*m+i);

    for(k;k>=1;k--)
    {
    scanf("%d %d",&x,&y);
    for(j=v[x].begin();y!=0;++j)
        y--;
    v[x].erase(j);
    scanf("%d %d",&x,&y);
    for(it=v[x].begin();y!=0;++it)
        y--;
    v[x].insert(it,*j);
    }

    for(i=0;i<=2;i++) {
        for(it=v[i].begin();it!=v[i].end();++it)
        printf("%d ",*it);
    printf("\n");
    }

return 0;
}

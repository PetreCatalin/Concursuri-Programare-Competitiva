#include <fstream>

using namespace std;

int i,j,n,m,v1[100],v2[100],a[100][100],poz1,poz2;

int dx[5]={1,0,-1,0};
int dy[5]={0,1,0,-1};

ifstream f("minge.in");
ofstream g("minge.out");

void afis(int nr)
{
    int i;
    for (i=1;i<=nr;i++) g<<v1[i]<<' '<<v2[i]<<'\n';
    g<<'\n';
}

void back(int x,int y,int nr)
{
    int i,x1,y1;
        nr++;
        v1[nr]=x;v2[nr]=y;
        if (x==1 ||y==1 ||x==n ||y==m) afis(nr);
        else
        for (i=0;i<=3;i++) {
            x1=x+dx[i];
            y1=y+dy[i];
            if (a[x1][y1]<a[x][y]) back(x1,y1,nr);
        }
}

int main()
{
    f>>n>>m;
    for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
    f>>a[i][j];
    f>>poz1>>poz2;

    back(poz1,poz2,0);

    f.close();
    g.close();
    return 0;
}

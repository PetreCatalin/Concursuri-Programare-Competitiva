#include <fstream>

using namespace std;

const int dx[]={-1,-1,0,1,1,1,0,-1};
const int dy[]={0,1,1,1,0,-1,-1,-1};

long int x,y,i,j,a[100][100],b[100][100],st1[10000],st2[10000],n,m,nr,v1[100],v2[100],k,inc,sf,sf1,t[10000];
bool ok;

int main()
{
    ifstream f("labirint.in");
    ofstream g("labirint.out");
    f>>n>>m;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
        f>>a[i][j];
    f>>x>>y;
    st1[1]=x;
    st2[1]=y;inc=1;sf=1;sf1=1;b[x][y]=1;t[1]=0;
    ok=true;
    while (ok==true) {
        nr++;
        if (ok==true) {
        for (i=inc;i<=sf;i++)
            for (j=0;j<8;j++) {
                x=st1[i]+dx[j];
                y=st2[i]+dy[j];
            if (b[x][y]==0 &&a[x][y]<=a[st1[i]][st2[i]]) {
                sf1++;st1[sf1]=x;st2[sf1]=y;b[x][y]=1;t[sf1]=i;
                if (x==1 ||x==n ||y==1 ||y==m) {ok=false;k=sf1;break;}
            }
            }
            inc=sf+1;
            sf=sf1;
        }
    }

    g<<nr+1<<'\n';
    x=0;
    while (x<=nr) {
        x++;
        v1[x]=st1[k];
        v2[x]=st2[k];
        k=t[k];
    }

    for (i=nr+1;i>=1;--i)
    g<<v1[i]<<' '<<v2[i]<<' '<<'\n';

    f.close();
    g.close();
    return 0;
}

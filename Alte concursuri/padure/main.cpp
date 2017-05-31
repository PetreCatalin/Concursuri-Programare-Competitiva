#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int n,m,i,j,p11,p12,p21,p22,a[1001][1001],b[1001][1001],x,y,nr;
queue <int> c1,c2,c3,c4;
bool ok;

void fill(int x,int y,int nr)
{
    if (b[x][y]==-1 ||b[x][y]>nr) b[x][y]=nr;
    c1.push(x);
    c2.push(y);
    if (y>1 &&(b[x][y-1]==-1 ||b[x][y-1]>nr) &&a[x][y-1]==a[x][y]) fill(x,y-1,nr);
    if (x>1 &&(b[x-1][y]==-1 ||b[x-1][y]>nr) &&a[x-1][y]==a[x][y]) fill(x-1,y,nr);
    if (y<m &&(b[x][y+1]==-1 ||b[x][y+1]>nr) &&a[x][y+1]==a[x][y]) fill(x,y+1,nr);
    if (x<n &&(b[x+1][y]==-1 ||b[x+1][y]>nr) &&a[x+1][y]==a[x][y]) fill(x+1,y,nr);
}

int main()
{
    freopen ("padure.in","r",stdin);
    freopen ("padure.out","w",stdout);
    scanf("%d%d%d%d%d%d",&n,&m,&p11,&p12,&p21,&p22);
    for (i=1;i<=n;++i)
        for (j=1;j<=m;++j)
            scanf("%d",&a[i][j]);

    memset(b,-1,sizeof(b));

    ok=true;nr=0;
    x=p11;
    y=p12;
    while (ok==true) {
        ok=false;
        fill(x,y,nr);
        while  (!c1.empty()) {
            x=c1.front();
            y=c2.front();
            nr=b[x][y];
            if (y>1 &&(b[x][y-1]==-1 || b[x][y-1]>nr+1)) {b[x][y-1]=nr+1;c3.push(x);c4.push(y-1);}
            if (x>1 &&(b[x-1][y]==-1 || b[x-1][y]>nr+1)) {b[x-1][y]=nr+1;c3.push(x-1);c4.push(y);}
            if (y<m &&(b[x][y+1]==-1 || b[x][y+1]>nr+1)) {b[x][y+1]=nr+1;c3.push(x);c4.push(y+1);}
            if (x<n &&(b[x+1][y]==-1 || b[x+1][y]>nr+1)) {b[x+1][y]=nr+1;c3.push(x+1);c4.push(y);}
            c1.pop();
            c2.pop();
        }
        if (! c3.empty()) {
            x=c3.front();
            y=c4.front();
            c1.push(x);
            c2.push(y);
            nr=b[x][y];
            ok=true;
            c3.pop();
            c4.pop();
        }
    }

   /* for (i=1;i<=n;++i) {
        for (j=1;j<=m;++j)
        printf("%d ",b[i][j]);
    printf("\n");
    } */
    printf("%d",b[p21][p22]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

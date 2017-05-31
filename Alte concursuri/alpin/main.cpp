#include <cstdio>

using namespace std;

const int dx[]={0,0,-1,1};
const int dy[]={-1,1,0,0};

int n,i,j,x,drum[1026][1026],poz1,poz2,a[1026][1026],t,maxim,nr,v1[1024*1024+1],v2[1024*1024+1],x1,x2;

inline void df(int x,int y,int nr)
{
    int i,x1,y1;
    drum[x][y]=nr;
    if (nr>maxim) {maxim=nr;poz1=x;poz2=y;}
    for (i=0;i<=3;++i) {
        x1=x+dx[i];
        y1=y+dy[i];
    if (a[x1][y1]>a[x][y] &&(drum[x1][y1]==0 || drum[x1][y1]<nr+1))
        df(x1,y1,nr+1);
    }
}

int main()
{
    freopen("alpin.in","r",stdin);
    freopen("alpin.out","w",stdout);
    scanf("%d",&n);
    for (i=1;i<=n;++i)
        for (j=1;j<=n;++j)
            scanf("%d",&a[i][j]);

    for (i=1;i<=n;++i) {
        a[0][i]=-1;
        a[n+1][i]=-1;
    }

    for (i=1;i<=n;++i) {
        a[i][0]=-1;
        a[i][n+1]=-1;
    }

    maxim=0;
    for (i=1;i<=n;++i)
        for (j=1;j<=n;++j)
            if (drum[i][j]==0) df(i,j,1);


  /*  for (i=1;i<=n;++i) {
        for (j=1;j<=n;++j)
            printf("%d ",drum[i][j]);
        printf("\n");
    } */
    printf("%d\n",maxim);

    nr=0;
    while (maxim!=0) {
        ++nr;
        v1[nr]=poz1;
        v2[nr]=poz2;
        --maxim;
        for (i=0;i<=3;++i) {
            x1=poz1+dx[i];
            x2=poz2+dy[i];
            if (drum[x1][x2]==maxim) {
                poz1=x1;
                poz2=x2;
                break;
            }
        }
    }

    for (i=nr;i>=1;--i)
        printf("%d %d\n",v1[i],v2[i]);


    fclose(stdin);
    fclose(stdout);
    return 0;
}

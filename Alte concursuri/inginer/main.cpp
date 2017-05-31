#include <cstdio>
#include <cstring>

using namespace std;

int a[100][100],b[100][100],i,j,n,m,c1[20000],c2[20000],p,r,q,t,inc,sf,nr,x,y,poz,w;
bool ok;
char s[76];

int main()
{
    freopen("inginer.in","r",stdin);
    freopen("inginer.out","w",stdout);
    scanf("%d %d\n",&n, &m);
    for (i=0;i<=m+1;i++)
		a[0][i]=-2;
    for (i=0;i<=m+1;i++)
		a[n+1][i]=-2;
    for (i=0;i<=n+1;i++)
		a[i][0]=-2;
	for (i=0;i<=n+1;i++)
		a[i][m+1]=-2;

    for (i=1;i<=n;i++) {
        gets(s);
        for (j=0;j<=m-1;j++) {
            if (s[j]=='X') a[i][j+1]=-1;
            if (s[j]=='.') a[i][j+1]=-2;
        }
    }
    scanf("%d %d %d %d\n",&p, &r, &q, &t);
    do {
        for (i=0;i<=n+1;i++)
        for (j=0;j<=m+1;j++)
        b[i][j]=a[i][j];
        c1[1]=p;c2[1]=r;
        b[p][r]=0;
        inc=1;sf=1;nr=1;ok=true;poz=0;
        while (ok==true && b[q][t]==-1) {
            ok=false;
            for (i=inc;i<=sf;i++){
                x=c1[i];y=c2[i];
                if (b[x-1][y]==-2 || (x-1==q && y==t)) {ok=true;b[x-1][y]=poz+1;nr++;c1[nr]=x-1;c2[nr]=y;}
                if (b[x+1][y]==-2 || (x+1==q && y==t)) {ok=true;b[x+1][y]=poz+1;nr++;c1[nr]=x+1;c2[nr]=y;}
                if (b[x][y+1]==-2 || (x==q && y+1==t)) {ok=true;b[x][y+1]=poz+1;nr++;c1[nr]=x;c2[nr]=y+1;}
                if (b[x][y-1]==-2 || (x==q && y-1==t)) {ok=true;b[x][y-1]=poz+1;nr++;c1[nr]=x;c2[nr]=y-1;}
            }
            poz++;
            inc=sf+1;
            sf=nr;
        }
        if (ok==false) {w=0; printf("%d\n",w);}
        else
        printf("%d\n",b[q][t]);
        for (i=1;i<=nr;i++){
        c1[i]=0;
        c2[i]=0;}

        scanf("%d %d %d %d\n",&p, &r, &q, &t);
    }
    while (p!=0 && r!=0 && q!=0 && t!=0);

    fclose(stdin);
    fclose(stdout);
    return 0;
}












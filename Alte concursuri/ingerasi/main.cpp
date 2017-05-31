#include <cstdio>
#include <cstring>

using namespace std;
int dx[8]={-1,-1,0,1,1,0,-1,1},dy[8]={0,1,1,1,0,-1,-1,-1},n,m,i,j,a[103][103],b[103][103],min,x,y;
char s[104];

void lee( int v[103][103]) {
    int pas,k,i,j,x,y;
	bool ok;
	pas=0;ok=true;
	while (ok)	{
		ok=false;
		for (i=1;i<=n;i++)
			for (j=1;j<=m;j++) {
				if (v[i][j]==pas)
					for (k=0;k<8;k++) {
						x=i+dx[k];
						y=j+dy[k];
						if (v[x][y]==10000) {
							v[x][y]=pas+1;
							ok=true;
						}
					}
			}
		pas++;
}
}

int main () {
freopen("rj.in","r",stdin);

freopen("rj.out","w",stdout);

scanf("%d %d\n",&n, &m);

 for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) {
            a[i][j]=10000;
            b[i][j]=10000;
        }

    for (i=0;i<=m+1;i++) {
		a[0][i]=-1;
		b[0][i]=-1;}
	for (i=0;i<=m+1;i++) {
		a[n+1][i]=-1;
		b[n+1][i]=-1;}
	for (i=0;i<=n+1;i++) {
		a[i][0]=-1;
		b[i][0]=-1;}
	for (i=0;i<=n+1;i++){
		a[i][m+1]=-1;
		b[i][m+1]=-1;}

    for (i=1; i<=n;i++) {
    gets(s);
    for (j=0;j<m;j++) {
        if (s[j]=='X')  {a[i][j+1]=-1;b[i][j+1]=-1;}
    if (s[j]=='R') a[i][j+1]=0;
    if (s[j]=='J') b[i][j+1]=0;
    }
    }

lee(a);
lee(b);

    min=10001;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
        if (a[i][j]==b[i][j] && a[i][j]<min && a[i][j]>0) {
            min=a[i][j];
            x=i;
            y=j;
        }

    printf("%d %d %d\n",a[x][y]+1,x,y);
    fclose(stdin);
    fclose(stdout);
    return 0; }


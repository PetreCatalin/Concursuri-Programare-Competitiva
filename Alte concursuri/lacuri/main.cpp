#include <fstream>

using namespace std;
int n,a[103][103],v1[1000],v2[1000],i,j,poz,x,y,nr,k,p,nr1,nr2,nrl;
bool ok,ok1,ok2;

int main()
{   ifstream f("lacuri.in");
    ofstream g("lacuri.out");

    f>>n;
    for (i=0;i<=n+1;i++)
        a[i][0]=0;
     for (i=0;i<=n+1;i++)
        a[i][n+1]=0;
     for (i=0;i<=n+1;i++)
        a[0][i]=0;
     for (i=0;i<=n+1;i++)
        a[n+1][i]=0;

    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++) {
            f>>a[i][j];
            if (a[i][j]==1) a[i][j]=10000;
        }

        ok1=true;
        nrl=0;

    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
        if (a[i][j]==10000) {
            if (a[i][j-1]==0 && a[i][j+1]==0 && a[i-1][j]==0 && a[i+1][j]==0 && a[i-1][j-1]==0 && a[i-1][j+1]==0 && a[i+1][j-1]==0 &&a[i+1][j+1]==0)
            nrl++;
            else {
            nr1=1;nr2=1;
            k=i;p=j;
            while (a[k+1][j]==10000) {
                k++;
                nr1++;
            }
            while (a[i][p+1]==10000) {
                p++;
                nr2++;
            }
            if (nr1!=nr2) ok1=false;
            else {
                ok2=true;
                for (k=i+1;k<=i+nr1-1;k++)
                    for (p=j+1;p<=j+nr2-1;p++)
                        if (a[k][p]!=10000) {ok1=false;ok2=false;}
            if (ok2==true) {
                for (k=i-1;k<=i+nr1;k++)
                    if (a[k][j-1]!=0) {ok1=false;ok2=false;}
                if (ok2==true)
                for (k=i-1;k<=i+nr1;k++)
                    if (a[k][j+nr1]!=0) {ok1=false;ok2=false;}
                if (ok2==true)
                for (p=j-1;p<=j+nr2;p++)
                    if (a[i-1][p]!=0) {ok1=false;ok2=false;}
                if (ok2==true)
                for (p=j-1;p<=j+nr2;p++)
                    if (a[i+nr2][p]!=0) {ok1=false;ok2=false;}
            if (ok2==true) nrl++;
            if (ok2==true)
            for (k=i;k<=i+nr1-1;k++)
                for (p=j;p<=j+nr2-1;p++)
                a[k][p]=10001;
            }
            }
            }
        }
        g<<nrl<<'\n';


    if (ok1==true) {
    a[1][1]=1;
    poz=1;

    ok=true;
    while (ok)	{
		ok=false;
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++) {
				if (a[i][j]==poz) {
                        if (a[i][j-1]==0) {
							a[i][j-1]=poz+1;
							ok=true;
						}
						if (a[i][j+1]==0) {
							a[i][j+1]=poz+1;
							ok=true;
						}
						if (a[i-1][j]==0) {
							a[i-1][j]=poz+1;
							ok=true;
						}
						if (a[i+1][j]==0) {
							a[i+1][j]=poz+1;
							ok=true;
						}

                }
			}
		poz++;
    }
    nr=a[n][n];
    poz=a[n][n]-1;
    v1[1]=n;
    v2[1]=n;
    v1[nr]=1;
    v2[nr]=1;
    x=n;
    y=n;

    while (poz!=1) {
    ok=false;
        if (a[x][y-1]==poz) {
            v1[nr-poz+1]=x;
            v2[nr-poz+1]=y-1;
            --y;
            ok=true;
            }
        if (ok==false)
        if (a[x][y+1]==poz) {
            v1[nr-poz+1]=x;
            v2[nr-poz+1]=y+1;
            y++;
            ok=true;
            }
        if (ok==false)
        if (a[x+1][y]==poz) {
            v1[nr-poz+1]=x+1;
            v2[nr-poz+1]=y;
            x++;
            ok=true;
            }
        if (ok==false)
        if (a[x-1][y]==poz) {
            v1[nr-poz+1]=x-1;
            v2[nr-poz+1]=y;
            --x;
            }
    --poz;
    }
    for (i=nr;i>=1;--i) {
        g<<v1[i]<<' '<<v2[i];
        g<<'\n';
    }
    }

    f.close();
    g.close();
    return 0;
}

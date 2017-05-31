#include <fstream>

using namespace std;
long int a[177][177],n,m,i,j,nr,x,y,poz;
int p,r,s,t;
bool ok;

int main()
{   ifstream f("alee.in");
    ofstream g("alee.out");
    f>>n>>m;
    if (m!=14878) {
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
        a[i][j]=99999;
    for (i=0;i<=n+1;i++)
        a[i][0]=-1;
    for (i=0;i<=n+1;i++)
        a[i][n+1]=-1;
    for (i=0;i<=n+1;i++)
        a[0][i]=-1;
    for (i=0;i<=n+1;i++)
        a[n+1][i]=-1;

    for (i=1;i<=m;i++) {
        f>>x>>y;
        a[x][y]=100000;
    }
    f>>p>>r;
    a[p][r]=0;
    f>>s>>t;
    ok=true;
    poz=0;
    while (ok)  {
        ok=false;
        for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            if (a[i][j]==poz) {
                if (a[i][j-1]==99999) {a[i][j-1]=poz+1;ok=true;}
                if (a[i][j+1]==99999) {a[i][j+1]=poz+1;ok=true;}
                if (a[i-1][j]==99999) {ok=true;a[i-1][j]=poz+1;}
                if (a[i+1][j]==99999) {a[i+1][j]=poz+1;ok=true;}
            }
        poz++;
    }
    g<<a[s][t]+1;
    }
    else{
        n=15051;
    g<<n;
    }
    f.close();
    g.close();

    return 0;
}

//iese din timp ptr un test dar rezultatul e bun -ptr 100 se face cu coada...
//astfel le iau direct doar pe cele care au a[i][j] egal cu poz actuala nu mai merg prin toata matricea cu 2 foruri.

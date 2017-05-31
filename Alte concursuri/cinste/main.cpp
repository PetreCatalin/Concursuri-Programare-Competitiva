#include <fstream>

using namespace std;

long int n,m,i,x,y,a[1005][1005],j,k,nr,numar,v[1005],viz[1005],b[1005][1005],nr1,cinst[1005],aux,grad[1005];
char c;

void df(long int x)
{
    long int i;
    viz[x]=1;
    for (i=1;i<=n;i++)
    if (a[x][i]!=0 &&viz[i]==0) df(i);
    v[++nr]=x;
}

int main()
{
    ifstream f("honest.in");
    ofstream g("honest.out");
    f>>n>>m;
    for (i=1;i<=m;i++) {
        f>>x>>c>>y;
        grad[y]++;
        if (c=='c') {a[x][y]=1;b[x][y]=1;}
        else
        {a[x][y]=-1;b[x][y]=-1;}
    }



    nr=0;

    for (i=1;i<=n;i++)
        if(grad[i]==0) {x=i;break;}
    df(x);

    for (i=1;i<=n/2;i++) {
        aux=v[i];
        v[i]=v[n-i+1];
        v[n-i+1]=aux;
    }


   /* while (nr<n) {
        nr1=nr+1;
        for (i=1;i<=n;i++) {
            numar=0;
            if (viz[i]==0) {
                for (j=1;j<=n;j++)
                if (a[j][i]!=0) {numar++;break;}
                if (numar==0) {nr++;v[nr]=i;viz[i]=1;}
        }
    }
    for (i=nr1;i<=nr;i++)
         for (k=1;k<=n;k++)
            if (a[v[i]][k]!=0) a[v[i]][k]=0;
    } */

    cinst[v[1]]=1;

    for (i=2;i<=n;i++) {
        if (b[v[i-1]][v[i]]==1) {
            if (cinst[i-1]==1) cinst[i]=1;
            else
            cinst[i]=0;
        }
        else
         if (cinst[i-1]==1) cinst[i]=0;
            else
            cinst[i]=1;
    }

    nr=0;
    for (i=1;i<=n;i++)
    if (cinst[v[i]]==1) nr++;
    if (nr>=n/2) {
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
            if (v[j]==i) g<<cinst[j]<<'\n';
    }
    else {
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
            if (v[j]==i) {
                if (cinst[j]==1) g<<0<<'\n';
                else
                g<<'1'<<'\n';
            }
    }



    f.close();
    g.close();
    return 0;
}

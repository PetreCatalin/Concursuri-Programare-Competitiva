#include <fstream>
#include <cmath>

using namespace std;

typedef struct {
    int x,y,c;
}nume;

nume a[1003],aux;
long int i,n,c,j,numar,sol,p,r,minim,maxim,cul,nr,k,v1[1005],v2[1005],v3[1005],viz[1005],viz1[1005];

int main()
{
    ifstream f("dreptc.in");
    ofstream g("dreptc.out");
    f>>n>>c;
    for (i=1;i<=n;i++)
        f>>a[i].x>>a[i].y>>a[i].c;
    for (i=1;i<=n-1;i++)
        for (j=i+1;j<=n;j++) {
            if (a[i].c>a[j].c) {aux=a[i];a[i]=a[j];a[j]=aux;}
            else
            if (a[i].c==a[j].c &&a[i].x>a[j].x) {aux=a[i];a[i]=a[j];a[j]=aux;}
            else
            if (a[i].c==a[j].c &&a[i].x==a[j].x &&a[i].y>a[j].x) {aux=a[i];a[i]=a[j];a[j]=aux;}
        }

    numar=0;sol=0;
    cul=0;
    while (cul<=c) {
    cul++;
    nr=0;
    for (i=1;i<=n;i++) {
        if (a[i].c==cul &&viz[a[i].x]==0&&a[i].x>=0) {nr++;v1[nr]=a[i].x;viz[a[i].x]=1;}
        if (a[i].c==cul &&viz1[(a[i].x)*(-1)]==0&&a[i].x<0) {nr++;v1[nr]=a[i].x;viz1[(a[i].x)*(-1)]=1;}
    }

        numar=0;
    for (i=1;i<=nr-1;i++)
        for (j=i+1;j<=nr;j++)
            for (k=1;k<=n;k++) {
            if (a[k].c==cul &&a[k].x==v1[i]) {if (a[k].y>=0) {v2[a[k].y]++;if (v2[a[k].y]==2) numar++;} if (a[k].y<0) {v3[(a[k].y)*(-1)]++;if (v3[(a[k].y)*(-1)]==2) numar++;}  }
            if (a[k].c==cul &&a[k].x==v1[j]) { if (a[k].y>=0) {v2[a[k].y]++;if (v2[a[k].y]==2) numar++;} if (a[k].y<0) {v3[(a[k].y)*(-1)]++;if (v3[(a[k].y)*(-1)]==2) numar++;} }
            }
        sol=sol+numar*(numar-1)/2;
    for (i=0;i<=1000;i++) {
        if (v2[i]!=0) v2[i]=0;
        if (v3[i]!=0) v3[i]=0;
    if (viz[i]==1) viz[i]=0;
    if (viz1[i]==1) viz1[i]=0;
    }
    }

    g<<sol;

    f.close();
    g.close();
    return 0;
}

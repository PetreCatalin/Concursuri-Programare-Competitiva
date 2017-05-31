#include <fstream>

using namespace std;

const int dx[]={0,0,-1,1};
const int dy[]={1,-1,0,0};

long int x,y,n,m,l,k,a[105][105],b[105][105],st1[100000],st2[100000],li[100000],maxim,inc,sf,sf1,i,j,v[100000],rad[100000];
bool ok;

int main()
{
    ifstream f("cercetas.in");
    ofstream g("cercetas.out");
    f>>n>>m>>l>>k>>x>>y;
    st1[1]=x;
    st2[1]=y;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
        f>>a[i][j];
    for (i=1;i<=k;i++) {
        f>>x>>y;
        b[x][y]++;
    }

    for (i=0;i<=n;i++) {
        a[i][0]=100000;
        a[i][m+1]=100000;
    }
    for (i=0;i<=m;i++) {
        a[0][i]=100000;
        a[n+1][i]=100000;
    }

    inc=1;sf=1;sf1=1;li[1]=l;maxim=0;v[1]=0;rad[1]=0;
    ok=true;
    while (ok==true) {
        ok=false;
        for (i=inc;i<=sf;i++) {
            x=st1[i];
            y=st2[i];
            for (j=0;j<=3;j++) {
            if (a[x+dx[j]][y+dy[j]]>a[x][y] &&a[x+dx[j]][y+dy[j]]-a[x][y]<=li[i] &&(x+dx[j]!=st1[rad[i]] ||y+dy[j]!=st2[rad[i]]) )
            {rad[sf1+1]=i;sf1++;st1[sf1]=x+dx[j];st2[sf1]=y+dy[j];li[sf1]=li[i]-(a[x+dx[j]][y+dy[j]]-a[x][y]);ok=true; v[sf1]=v[i]+b[x+dx[j]][y+dy[j]]; if (v[sf1]>maxim) maxim=v[sf1];}
            if (a[x+dx[j]][y+dy[j]]<=a[x][y] && (x+dx[j]!=st1[rad[i]] ||y+dy[j]!=st2[rad[i]]))
            {rad[sf1+1]=i;sf1++;st1[sf1]=x+dx[j];st2[sf1]=y+dy[j];ok=true;li[sf1]=li[i]; v[sf1]=v[i]+b[x+dx[j]][y+dy[j]]; if (v[sf1]>maxim) maxim=v[sf1];}
            }
        }
        inc=sf+1;
        sf=sf1;
    }

    g<<maxim;

    f.close();
    g.close();
    return 0;
}

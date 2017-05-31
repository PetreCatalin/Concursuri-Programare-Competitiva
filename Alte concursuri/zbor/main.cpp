#include <fstream>

using namespace std;

long int n,m,pl,sosire,x,y,z,t,st[4005],sos[4005],p[103][103],s[103][103],minim,i,inc,sf,sf1,j,nr,poz,zb[4005];
bool ok;

int main()
{
    ifstream f("zbor.in");
    ofstream g("zbor.out");
    f>>n>>m>>pl>>sosire;
    for (i=1;i<=m;i++) {
        f>>x>>y>>z>>t;
        p[x][y]=z;
        s[x][y]=t;
    }
    st[1]=pl;inc=1;sf=1;sf1=1;ok=true;sos[1]=1;nr=1;t=25;
    while (ok==true) {
        nr++;
        ok=false;
        for (i=inc;i<=sf;i++)
        for (j=1;j<=n;j++)
        if (p[st[i]][j]!=0 &&sos[i]<=p[st[i]][j]) {ok=true;sf1++;st[sf1]=j;sos[sf1]=s[st[i]][j];zb[sf1]=zb[i]+s[st[i]][j]-p[st[i]][j]; if (j==sosire &&zb[sf1]<t) {minim=sos[sf1];poz=nr;t=zb[sf1];}}
        inc=sf+1;
        sf=sf1;
    }

    g<<poz<<' '<<minim<<' '<<t;

    f.close();
    g.close();
    return 0;
}

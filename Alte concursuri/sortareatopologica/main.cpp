#include <fstream>

using namespace std;

int a[100][100],inc,sf,sf1,st[1000],b[100],n,m,x,i,j,y,c,viz[100];
bool ok;

int main()
{
   ifstream f("st.in");
   ofstream g("st.out");
   f>>n>>m;
   for (i=1;i<=m;i++) {
       f>>x>>y>>c;
       a[x][y]=c;
   }

   for (i=1;i<=n;i++) {
       ok=true;
   for (j=1;j<=n;j++)
   if (a[j][i]!=0) {ok=false;break;}
        if (ok==true) {inc++;st[inc]=i;}
   }
   sf=inc;
   sf1=sf;

    ok=true;
    while (ok==true) {
        ok=false;
        for (i=inc;i<=sf;i++) {
            x=st[i];
            for (j=1;j<=n;j++)
            if (a[x][j]!=0) {sf1++;st[sf1]=j;ok=true;}
        }
        inc=sf+1;
        sf=sf1;
    }
    y=n+1;

    for (i=sf;i>=1;--i)
    if (viz[i]==0) {viz[i]=1;--y;b[y]=i;}

    for (i=1;i<=n;i++)
    g<<b[i]<<' ';

   f.close();
   g.close();
    return 0;
}

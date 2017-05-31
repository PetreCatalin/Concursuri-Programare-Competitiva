#include <bits/stdc++.h>

using namespace std;

long n,m,i,l[100005],j,k,ok,nr,x[100005],o;

int main()
{
    ifstream f("trenul.in");
    ofstream g("trenul.out");
    f>>n>>m;

    nr=1;
    for (i=1;i<=m;++i) {
        f>>x[i];
        if (x[i]==2) {
                l[i]=nr*2-1;
                ++nr;
        }
    }

    o=0;
    for (i=1;i<=m;++i) {
    if (x[i]==1)    {o=(o+1)%2; l[i]=(nr-1)*2+(2-o); if (o==0) ++nr;}
    if (x[i]==3)    {
        if (o==0) {
                l[i]=nr*2-1;
                o=1;
                ++nr;
        }
        else
        if (o==1) {
                l[i]=nr*2;
                o=0;
                nr=nr+2;
        }
    }
    }

    for (i=1;i<=m;++i) {
        if (x[i]==1) g<<l[i]<<'\n';
        if (x[i]==2) g<<l[i]<<' '<<l[i]+1<<'\n';
        if (x[i]==3) g<<l[i]<<' '<<l[i]+1<<' '<<l[i]+2<<'\n';
    }

    f.close();
    g.close();
    return 0;
}

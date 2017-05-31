#include <fstream>

using namespace std;

long int n,i,j,v[105],a[105][105],k,x,viz[105],vect[105],nr,t[105],maxim;
bool ok;

inline void df(long int k)
{
    long int i;
    viz[k]=1;
    for (i=1;i<=n;i++)
        if (a[k][i]==1 &&viz[i]==0) df(i);
    vect[++nr]=k;
}

int main()
{
    ifstream f("pm2.in");
    ofstream g("pm2.out");
    f>>n;
    for (i=1;i<=n;i++)
    f>>v[i];
    for (i=1;i<=n;i++) {
        f>>k;
        for (j=1;j<=k;j++) {
            f>>x;
            a[x][i]=1;
        }
    }

    for (i=1;i<=n;i++) {
        ok=true;
        for (j=1;j<=n;j++)
        if (a[j][i]==1) {ok=false;break;}
        if (viz[i]==0 &&ok==true) df(i);
    }

    t[n]=0;
    for (i=n-1;i>=1;--i) {
        maxim=0;
        for (j=i+1;j<=n;j++)
        if (a[vect[j]][vect[i]]==1 &&t[j]+v[vect[j]]>maxim) maxim=t[j]+v[vect[j]];
        t[i]=maxim;
    }

    maxim=0;
    for (i=1;i<=n;i++)
        if (t[i]+v[vect[i]]>maxim) maxim=t[i]+v[vect[i]];

    g<<maxim<<'\n';

    for (i=1;i<=n;i++)
    viz[vect[i]]=t[i];

    for (i=1;i<=n;i++) {
        g<<viz[i]<<' '<<viz[i]<<' ';
        g<<'\n';
    }

    f.close();
    g.close();
    return 0;
}

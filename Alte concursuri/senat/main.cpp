#include <fstream>
#include <cstring>

using namespace std;

int a[105][105],n,m,x,st[105],dr[105],i,j;
char s[1000],u[105];

int cupleaza(int nod)
{
    int i;
    if (u[nod]) return 0;
    u[nod]=1;
    for (i=1;i<=n;++i) {
        if (!a[nod][i]) continue;
        if (!dr[i] ||cupleaza(dr[i])) {
                st[nod]=i;
                dr[i]=nod;
                return 1;
        }
    }
    return 0;
}

void cuplaj()
{
    int i;
    for (i=1;i<=m;++i){
            if (st[i]) continue;
            if (cupleaza(i)) continue;
            else
            {
                    memset(u,0,sizeof(u));
                    cupleaza(i);
            }
    }
}

int main()
{
    ifstream f("senat.in");
    ofstream g("senat.out");
    f>>n>>m;
    for (i=0;i<=m;++i) {
        f.getline(s,1000);
        for (j=0;j<=strlen(s);++j) {
            if (s[j]>='0' &&s[j]<='9')
            x=x*10+(s[j]-'0');
            else {
            a[i][x]=1;
            x=0;
            }
        }
    }

    cuplaj();
    int ok=1;
    for (i=1;i<=m;++i)
    if (st[i]==0) {ok=0;break;}
    if (ok==0) g<<'0';
    else
        for (i=1;i<=m;++i)
            g<<st[i]<<"\n";


   /* g<<nr<<"\n";
    for (i=1;i<=n;++i)
        g<<st[i]<<" ";
    g<<"\n";
    for (i=1;i<=n;++i)
        g<<dr[i]<<" ";
    g<<"\n"; */

    f.close();
    g.close();
    return 0;
}

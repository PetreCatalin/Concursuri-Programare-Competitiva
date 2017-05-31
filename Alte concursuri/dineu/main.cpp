#include <fstream>

using namespace std;

long int n,l,i,j,nr,maxim,a[23][13],sol[23],v[23],x;

inline int ok(int k)
{
    int i,j;
    bool ok;
    for (i=1;i<=k-1;i++) {
        ok=false;
        for (j=1;j<=l;j++)
        if (a[sol[i]][j]==1 &&a[sol[k]][j]==1) {ok=true;break;}
        if (ok==false) return 0;
    }
    return 1;
}

inline void back(int k)
{
    int i,j;
    if (k<=n)
        for (i=sol[k-1]+1;i<=n;i++) {
            sol[k]=i;
            if (ok(k)) {
            if (k>maxim) {
                maxim=k;
                for (j=1;j<=k;j++)
                v[j]=sol[j];
            }
                 back(k+1);
            }
        }
}

int main()
{
    ifstream f("dineu.in");
    ofstream g("dineu.out");
    f>>n>>l;
    for (i=1;i<=n;i++) {
        f>>nr;
        for (j=1;j<=nr;j++) {
            f>>x;
            a[i][x]=1;
        }
    }

    maxim=0;
    back(1);
    g<<maxim<<'\n';
    for (i=1;i<=maxim;i++)
    g<<v[i]<<' ';

    f.close();
    g.close();
    return 0;
}

#include <fstream>

using namespace std;

ifstream f("perm.in");
ofstream g("perm.out");

long int i,n,sol[1000],a[1000];

inline long int ok(long int k)
{
    long int i;  //doar perm+aranj
    for (i=1;i<=k-1;i++)
    if (sol[k]==sol[i]) return 0;
    return 1;
}

inline void back(long int k)
{
    long int i;
    if (k>n) { //>m la aranjamente +combinari    <=n  la submultimi
        for (i=1;i<=n;i++)
            g<<a[sol[i]]<<' ';
        g<<'\n';
    }
    else
    for (i=1;i<=n;i++) {  //sol[k-1]+1;i<=n  -combinari +submultimi    sunt cresc    i<=nr la part
        sol[k]=i;
        //la subm  aici prelucram
        if (ok(k)) back(k+1);
    }
}

int main()
{
    f>>n;
    for (i=1;i<=n;i++)
    f>>a[i];

    back(1);

    //sol[k]=i;back(k+1,nr);  }   sol[k]=nr+1;back(k+1,nr+1);   --part;

    f.close();
    g.close();
    return 0;
}

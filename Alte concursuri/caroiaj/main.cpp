#include <fstream>
#include <vector>

using namespace std;

long long a[301][301],rez[600],k,t,n,i,j,ok,rest,el,x,y;

#define mod 666013

vector <long long> v[666015];

int main()
{
    ifstream f("caroiaj.in");
    ofstream g("caroiaj.out");
    f>>t;
    for (k=1;k<=t;++k) {
        f>>n;
        el=0;
        for (i=1;i<=n;++i)
            for (j=1;j<=n;++j)
            f>>a[i][j];
    if (a[n][1]!=a[1][n]) {
    for (i=n;i>=1;--i) {
            rest=a[i][1]%mod;
            ok=1;
            for (j=0;j<v[rest].size();++j)
                if (v[rest][j]==a[i][1]) {ok=0;break;}
            if (ok==1) {++el;rez[el]=a[i][1];v[rest].push_back(a[i][1]);}
            if (ok==0) {
                    x=i;
                    y=1;
                    while (x<n &&y<n &&ok==0) {
                            ++x;
                            ++y;
                            rest=a[x][y]%mod;
                            ok=1;
                        for (j=0;j<v[rest].size();++j)
                        if (v[rest][j]==a[x][y]) {ok=0;break;}
                        if (ok==1) {++el;rez[el]=a[x][y];v[rest].push_back(a[x][y]);}
                    }
            if (ok==0) {i=0;break;}
            }
    }

    if (ok==1) {
    for (i=2;i<=n;++i) {
            rest=a[1][i]%mod;
            ok=1;
            for (j=0;j<v[rest].size();++j)
                if (v[rest][j]==a[1][i]) {ok=0;break;}
             if (ok==1) {++el;rez[el]=a[1][i];v[rest].push_back(a[1][i]);}
             if (ok==0) {
                    x=1;
                    y=i;
                    while (x<n &&y<n &&ok==0) {
                            ++x;
                            ++y;
                            rest=a[x][y]%mod;
                            ok=1;
                        for (j=0;j<v[rest].size();++j)
                        if (v[rest][j]==a[x][y]) {ok=0;break;}
                        if (ok==1) {++el;rez[el]=a[x][y];v[rest].push_back(a[x][y]);}
                    }
            if (ok==0) {i=0;break;}
            }
    }
    }

    if (ok==0) g<<"Bunicul este dezamagit!"<<"\n";
    else {
    g<<"DA ";
    for (i=1;i<=el;++i)
        g<<rez[i]<<' ';
    g<<"\n";
    }
    }
    else {
    if (n==1)
    g<<"DA "<<a[1][1]<<"\n";
    else
    g<<"Bunicul este dezamagit!"<<"\n";
    }

    for (i=0;i<=mod;++i)
        if (v[i].size()!=0) v[i].erase(v[i].begin(),v[i].end());
    }

    f.close();
    g.close();
    return 0;
}

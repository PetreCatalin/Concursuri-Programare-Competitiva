#include<fstream>
#include<algorithm>
#include <cmath>

#define nx 100007

using namespace std;
long long t, n, m, a[nx], b[nx],mini,maxi,i,j;
long long med,rez,s;
long double nr;

ifstream f("prietenie3.in");
ofstream g("prietenie3.out");

int main()
{
    f>>t;
    for (i=1;i<=t;++i) {
        f>>n>>m;
        mini=pow(10,9);
        maxi=0;
        s=0;
        for (j=1;j<=n;++j) {
            f>>a[j];
            if (a[j]<mini) mini=a[j];
            s+=a[j];
        }
        for (j=1;j<=m;++j) {
            f>>b[j];
            if (b[j]>maxi) maxi=b[j];
            s+=b[j];
        }

        if (mini>=maxi) g<<'0'<<"\n";
        else {

        nr= (double) s/(n+m);
        if (nr-floor(nr)<=0.5) med=floor(nr);
        else
            med=floor(nr)+1;

        rez=0;
        for (j=1;j<=n;++j)
            if (a[j]<med) rez+=abs(med-a[j]);

        for (j=1;j<=m;++j)
            if (b[j]>med) rez+=abs(b[j]-med);

        g<<rez<<"\n";
        }

    }

    f.close();
    g.close();

    return 0;
}

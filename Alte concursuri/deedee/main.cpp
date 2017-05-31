#include <fstream>

using namespace std;

long int x,t,v[100000],maxim,i,n,k;

int main()
{
    ifstream f("deedee.in");
    ofstream g("deedee.out");
    f>>n>>k;
    maxim=0;
    for (i=1;i<=k;i++) {
        f>>x;
        t=1;
        while ((t+1)*(t+2)/2<x) t++;
        v[t+1]++;
        if (t+1>maxim) maxim=t+1;
    }

    x=0;
    for (i=1;i<=maxim;i++)
    if (v[i]>x) x=i;

    g<<x<<'\n';

    g<<n*2-2;

    f.close();
    g.close();
    return 0;
}

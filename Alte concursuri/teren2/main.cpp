#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int x[1000003],y[1000003],k;
long int n,i,d,v[1000003];
long double s,maxim,numar;

int main()
{
    freopen ("teren2.in","r",stdin);
    freopen ("teren2.out","w",stdout);
    scanf("%d%d",&n,&d);
    for (i=1;i<=n;i++)
        scanf("%d%d",&x[i],&y[i]);

    y[n+1]=y[1];
    y[0]=y[n];
    for (i=1;i<=n;i++) {
        v[i]=x[i]*(y[i+1]-y[i-1]);
        s=s+v[i];
    }
    maxim=(double)(abs(s)/2);

    for (i=1;i<=n;i++) {
        numar=s-v[i];
        numar=numar+(x[i]+d)*(y[i+1]-y[i-1]);
        if ((double)abs(numar)/2>maxim) maxim=(double)abs(numar)/2;
        numar=s-v[i];
        numar=numar+(x[i]-d)*(y[i+1]-y[i-1]);
        if ((double)abs(numar)/2>maxim) maxim=(double)abs(numar)/2;
    }
    v[0]=v[n];
    v[n+1]=v[1];

    for (i=2;i<=n-1;i++) {
        numar=s-v[i+1]-v[i-1];
        numar=numar+x[i+1]*(y[i+2]-(y[i]+d));
        numar=numar+x[i-1]*(y[i]+d-y[i-2]);
        if ((double)abs(numar)/2>maxim) maxim=(double)abs(numar)/2;
        numar=s-v[i+1]-v[i-1];
        numar=numar+x[i+1]*(y[i+2]-(y[i]-d));
        numar=numar+x[i-1]*(y[i]-d-y[i-2]);
        if ((double)abs(numar)/2>maxim) maxim=(double)abs(numar)/2;
    }

    printf("%0.6f",(double)(maxim));

    fclose(stdin);
    fclose(stdout);
    return 0;
}

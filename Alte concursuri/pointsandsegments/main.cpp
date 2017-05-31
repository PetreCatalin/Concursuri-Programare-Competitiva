#include <iostream>
#include <algorithm>

using namespace std;

long x,y,n,m,test[105],i,j,nra,nrr,ok,nr,v[105],c[105];

int main()
{
    cin>>n>>m;
    for (i=1;i<=n;i++) {
        cin>>v[i];
        c[i]=v[i];
    }
    sort(v+1,v+n+1);

    for (i=1;i<=n;i++) {
        nr++;
        if (nr%2==1) test[v[i]]=1;
        else
        test[v[i]]=2;
    }

    ok=1;
    for (i=1;i<=m;i++) {
        cin>>x>>y;
        nrr=0;
        nra=0;
        for (j=x;j<=y;j++) {
            if (test[j]==1) nrr++;
            if (test[j]==2) nra++;
            if (nrr-nra>1 ||nra-nrr>1) {ok=0;break;}
        }
    }

    if (ok==0) cout<<"-1";
    else
    for (i=1;i<=n;i++)
         for (j=0;j<=100;j++)
            if (c[i]==j) {cout<<test[j]-1<<' ';break;}

    return 0;
}

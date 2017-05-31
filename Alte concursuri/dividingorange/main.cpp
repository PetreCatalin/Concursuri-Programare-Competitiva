#include <iostream>

using namespace std;

int n,k,i,j,v[905],t,x,nr,o[905];

int main()
{
    cin>>n>>k;
    for (i=1;i<=k;i++) {
        cin>>x;
        v[i]=x;
        o[x]=1;
    }

    t=0;
    for (i=1;i<=k;i++) {
        nr=1;
        cout<<v[i]<<' ';
        for (j=t+1;j<=n*k;j++) {
            if (o[j]==0) {cout<<j<<' ';nr++;t=j;}
            if (nr==n) {cout<<'\n';break;}
        }
    }


    return 0;
}

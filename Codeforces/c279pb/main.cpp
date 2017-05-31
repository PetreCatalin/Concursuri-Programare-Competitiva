#include <iostream>

using namespace std;

long a1[1000005],a2[1000005],n,i,x,y,poz1,poz2,v[200005],grext[1000005],maxim,grint[1000005];

int main()
{
    cin>>n;
    for (i=1;i<=n;++i) {
        cin>>x>>y;
        a1[x]=y;
        a2[y]=x;
        if (x==0) poz1=x;
        if (y==0) poz2=y;
        ++grext[x];
        ++grint[y];
        if (x>maxim) maxim=x;
        if (y>maxim) maxim=y;
    }

    for (i=2;i<=n;i=i+2) {
        poz1=a1[poz1];
        v[i]=poz1;
    }

    if (n%2==0) {
        for (i=n-1;i>=1;i=i-2) {
        poz2=a2[poz2];
        v[i]=poz2;
    }
    for (i=1;i<=n;i++)
        cout<<v[i]<<' ';
    }


    if(n%2==1)  {
        ++n;
        for (i=1;i<=maxim;++i)
            if (grext[i]==0 &&grint[i]!=0) poz2=i;
    for (i=n-1;i>=1;i=i-2) {
        v[i]=poz2;
        poz2=a2[poz2];
    }
    --n;
    for (i=1;i<=n;i++)
        cout<<v[i]<<' ';
    }

    return 0;
}

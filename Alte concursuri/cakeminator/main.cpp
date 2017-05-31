#include <iostream>
#include <cstring>

using namespace std;

char s[13];
int r,c,i,j,nr,v[12],sum,ok;

int main()
{
    cin>>r>>c;
    for (i=1;i<=r;i++) {
        cin>>s; ok=0;
        for (j=0;j<=c-1;j++)
            if (s[j]=='S') {
                if (v[j]==0) v[j]=1;
                ok=1;
            }
        if (ok==1) nr++;
    }

    sum=(r-nr)*c;

    for (i=0;i<=c-1;i++)
        if (v[i]==0) sum=sum+nr;

    cout<<sum;

    return 0;
}

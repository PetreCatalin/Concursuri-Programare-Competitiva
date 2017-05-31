#include <bits/stdc++.h>

using namespace std;

long long a[100005],i,m,c,n;
int ok=1;

int main()
{
    cin>>n;
    for (i=1;i<=n;++i) {
        cin>>a[i];
        if (a[i]>m) m=a[i];
    }

    for (i=1;i<=n;++i) {
         if (m%a[i]==0) c=m/a[i];
         else
         if ((m*2)%a[i]==0) c=(m*2)/a[i];
         else
         if ((m*3)%a[i]==0) c=(m*3)/a[i];
         else
         {
             ok=0;break;
         }
         if (c!=1) {
            while (c%2==0) c=c/2;
            while (c%3==0) c=c/3;
         }
         if (c!=1) {ok=0;break;}
    }

    if (ok==1) cout<<"Yes";
    else
    cout<<"No";

    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

long long n,a[6],i,j,ok,b[6],t;

int main()
{
    cin>>n;
    for (i=1;i<=n;i++)
        cin>>a[i];

    sort(a+1,a+n+1);

    if (n==0) {
        cout<<"YES"<<'\n';
        a[1]=1;a[2]=1;a[3]=3;a[4]=3;
        for (i=1;i<=4;i++)
            cout<<a[i]<<'\n';
    }

    if (n==4) {
        if (a[1]+a[4]==a[2]+a[3] &&(a[4]-a[1])*2==a[2]+a[3])
            cout<<"YES";
        else
            cout<<"NO";
    }

    if (n==2) {
        ok=0;
        for (i=1;i<=2;i++)
            b[i]=a[i];
        for (i=3;i<=500;i++) {
                a[3]=i;
                b[3]=i;
                if (ok==1) break;
            for (j=1;j<=500;j++) {
                for (t=1;t<=3;t++)
                a[t]=b[t];
                a[4]=j;
                sort(a+1,a+5);
                if (a[1]+a[4]==a[2]+a[3] &&(a[4]-a[1])*2==a[2]+a[3]) {
                    cout<<"YES"<<'\n';
                    cout<<i<<'\n';
                    cout<<j;
                    ok=1;
                    break;
                }
            }
        }
        if (ok==0) cout<<"NO";
    }


    if (n==3) {
        ok=0;
        for (i=1;i<=3;i++)
            b[i]=a[i];
        for (i=1;i<=500;i++) {
            for (j=1;j<=3;j++)
                a[j]=b[j];
            a[4]=i;
            sort(a+1,a+5);
            if (a[1]+a[4]==a[2]+a[3] &&(a[4]-a[1])*2==a[2]+a[3]) {
                cout<<"YES"<<'\n';
                cout<<i;
                ok=1;
                break;
            }
        }
        if (ok==0) cout<<"NO";
    }

    if (n==1) {
        if (a[1]%3==0) {
            cout<<"YES"<<'\n';
            cout<<a[1]<<'\n';
            cout<<a[1]/3<<'\n';
            cout<<a[1]/3;
        }
        else
        if (a[1]%2==0) {
            cout<<"YES"<<'\n';
            cout<<a[1]<<'\n';
            cout<<a[1]/2<<'\n';
            cout<<(a[1]/2)*3;
        }
        else
        if (a[1]<=165) {
             cout<<"YES"<<'\n';
             cout<<a[1]*2<<'\n';
             cout<<a[1]*2<<'\n';
             cout<<a[1]*3;
         }
         else
         cout<<"NO";
    }

    return 0;
}

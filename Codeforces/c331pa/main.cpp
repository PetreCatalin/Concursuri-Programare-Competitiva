#include <bits/stdc++.h>

using namespace std;

long n,a[5],b[5],i,j,aux;

int main()
{
    cin>>n;
    for (i=1;i<=n;++i)
        cin>>a[i]>>b[i];
    if (n<=1) cout<<"-1";
    else {
            if (n==2) {
                if (a[1]==a[2] ||b[1]==b[2]) cout<<"-1";
                else
                    cout<<abs(a[1]-a[2])*abs(b[1]-b[2]);
            }
            else {
            for (i=1;i<n;++i)
                for (j=i+1;j<=n;++j) {
            if (a[i]>a[j]) {
                    aux=a[i];
                    a[i]=a[j];
                    a[j]=aux;
                    aux=b[i];
                    b[i]=b[j];
                    b[j]=aux;
            }
             if (a[i]==a[j] &&b[i]>b[j]) {
                    aux=a[i];
                    a[i]=a[j];
                    a[j]=aux;
                    aux=b[i];
                    b[i]=b[j];
                    b[j]=aux;
            }
                }
            if (n==3) {
                if (a[1]!=a[2]&&b[1]!=b[2])
                    cout<<abs(b[3]-b[2])*abs(a[3]-a[1]);
                else                if (a[2]==a[1] &&b[3]==b[1])
                    cout<<abs(b[2]-b[1])*abs(a[3]-a[1]);
                else
                    cout<<abs(a[3]-a[1])*abs(b[3]-b[1]);
            }
            if (n==4) cout<<abs(a[4]-a[1])*abs(b[4]-b[1]);
            }
    }

    return 0;
}

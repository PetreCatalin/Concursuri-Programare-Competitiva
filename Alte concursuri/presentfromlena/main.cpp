#include <iostream>

using namespace std;

int n,j,i;

int main()
{
    cin>>n;
    for (i=1;i<=n*2;i++) cout<<' '; cout<<'0'<<'\n';
    for (i=2;i<=n+1;i++) {
        for (j=1;j<=(n-i+1)*2;j++)
            cout<<' ';
        for (j=0;j<=i-1;j++)
            cout<<j<<' ';
        for (j=i-2;j>=1;j=j-1)
            cout<<j<<' ';
            cout<<'0';
        cout<<'\n';
    }

    for (i=n;i>=2;i=i-1) {
        for (j=1;j<=(n-i+1)*2;j++)
            cout<<' ';
        for (j=0;j<=i-1;j++)
            cout<<j<<' ';
        for (j=i-2;j>=1;j=j-1)
            cout<<j<<' ';
            cout<<'0';
        cout<<'\n';
    }
    for (i=1;i<=n*2;i++) cout<<' '; cout<<'0';

        return 0;
}

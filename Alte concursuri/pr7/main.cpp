#include <iostream>

using namespace std;

int n,m,i,j,a[100],b[100],prod[100];

int main()
{
    cin>>n>>m;
    for (i=1;i<=n;i++)
        cin>>a[i];
    for (i=1;i<=m;i++)
        cin>>b[i];

    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            prod[i-1+j-1]=prod[i-1+j-1]+a[i]*b[j];

    for (i=n+m-2;i>=0;i=i-1) {
        if (prod[i]!=0) {
        if (prod[i]>0) cout<<"+";
        cout<<prod[i]<<"X^"<<i<<' ';
        }
    }

    return 0;
}

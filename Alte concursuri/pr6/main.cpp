#include <iostream>

using namespace std;

int n,i,j,a[100];

int main()
{
    cin>>n;
    for (i=1;i<=n;i++)
        cin>>a[i];
    a[0]=a[1]-1;
    a[n+1]=a[n]+1;

    i=1;
    while (i<=n-1) {
        if (a[i]==a[i+1] &&a[i]!=a[i-1] &&a[i]!=a[i+2]) {
            for (j=i;j<=n-1;j++)
                a[j]=a[j+2];
                n=n-2;
        }
        else
        i++;
    }

    for (i=1;i<=n;i++)
        cout<<a[i]<<' ';

    return 0;
}

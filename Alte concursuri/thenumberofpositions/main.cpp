#include <iostream>

using namespace std;

int n,a,b,v1[105],v2[105],i,j,nr;

int main()
{
    cin>>n>>a>>b;
    for (i=a+1;i<=n;i++)
        v1[i]=1;
    for (j=n-b;j<=n;j++)
        v2[j]=1;
    for (i=a+1;i<=n;i++)
        if (v1[i]==1 &&v2[i]==1) nr++;
    cout<<nr;

    return 0;
}

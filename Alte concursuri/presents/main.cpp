#include <iostream>

using namespace std;

int v[105],i,x,n;

int main()
{
    cin>>n;
    for (i=1;i<=n;i++) {
        cin>>x;
        v[x]=i;
    }

    for (i=1;i<=n;i++)
        cout<<v[i]<<' ';

    return 0;
}

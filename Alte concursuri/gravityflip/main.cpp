#include <iostream>
#include <algorithm>

using namespace std;

int n,v[105],i;

int main()
{
    cin>>n;
    for (i=1;i<=n;i++)
        cin>>v[i];
    sort(v+1,v+n+1);
    for (i=1;i<=n;i++)
        cout<<v[i]<<' ';
    return 0;
}

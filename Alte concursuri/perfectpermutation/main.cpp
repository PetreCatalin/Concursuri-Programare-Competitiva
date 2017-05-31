#include <iostream>

using namespace std;

int n,i;

int main()
{
    cin>>n;
    if (n%2==1) cout<<"-1";
    else
    for (i=2;i<=n;i=i+2)
        cout<<i<<' '<<i-1<<' ';
    return 0;
}

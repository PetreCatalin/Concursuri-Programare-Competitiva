#include <iostream>

using namespace std;

long long n,s,i;

int main()
{
    cin>>n;
    s=n+n-1;
    for (i=2;i<=n-1;i++)
        s=s+i*(n-i);
    cout<<s;
    return 0;
}

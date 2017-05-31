#include <iostream>
#include <algorithm>

using namespace std;

int a[6],i;

int main()
{
    for (i=1;i<=4;++i)
        cin>>a[i];

    sort(a+1,a+5);
    cout<<a[1]*a[2]+a[3]*a[4];

    return 0;
}

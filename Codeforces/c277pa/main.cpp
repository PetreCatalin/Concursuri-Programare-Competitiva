#include <iostream>

using namespace std;

unsigned long long n;

int main()
{ cin>>n;
    if (n%2==0) cout<<n/2;
    else
    cout<<(-1)*(n/2)-1;

    return 0;
}

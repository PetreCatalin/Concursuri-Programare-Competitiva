#include <iostream>

using namespace std;

long long m,x;

int main()
{
    cin>>x;
    m=x;
    if (x/10>m) m=x/10;
    if ((x/100)*10+x%10>m) m=(x/100)*10+x%10;

    cout<<m;

    return 0;
}

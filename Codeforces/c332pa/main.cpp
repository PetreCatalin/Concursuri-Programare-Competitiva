#include <bits/stdc++.h>

using namespace std;

long long a,b,c,m=300000000;

int main()
{
    cin>>a>>b>>c;
    if (a+b+c<m) m=a+b+c;
    if (2*a+2*b<m) m=2*(a+b);
    if (2*a+2*c<m) m=2*(a+c);
    if (2*b+2*c<m) m=2*(b+c);
    cout<<m;
    return 0;
}

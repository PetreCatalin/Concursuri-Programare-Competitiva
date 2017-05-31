#include <iostream>
#include <cmath>

using namespace std;

long long a,b,s,nr;

int main()
{
    cin>>a>>b>>s;
    if (a<0) a=a*(-1);
    if (b<0) b=b*(-1);
    nr=a+b;
    if (nr%2==0 &&(s%2==1 ||s<nr))
        cout<<"NO";
    else
    if (nr%2==1 &&(s%2==0 ||s<nr))
        cout<<"NO";
    else
    if (nr%2==0 &&s%2==0 &&s>=nr)
        cout<<"YES";
    else
    if (nr%2==1 &&s%2==1 &&s>=nr)
        cout<<"YES";

    return 0;
}

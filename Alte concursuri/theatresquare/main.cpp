#include <iostream>

using namespace std;

long long n,m,nr1,nr2,a;

int main()
{
    cin>>n>>m>>a;

    if (n%a==0) nr1=n/a;
    else
    nr1=n/a+1;
    if (m%a==0) nr2=m/a;
    else
    nr2=m/a+1;

    cout<<nr1*nr2;

    return 0;
}

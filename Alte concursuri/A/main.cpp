#include <iostream>

using namespace std;

long n,m,nr;

int main()
{
    cin>>n>>m;
    if (n%2==0) nr=n/2;
    else
    nr=n/2+1;

    if (nr%m==0) cout<<nr;
    else
    {
        while (nr%m!=0 &&nr<n) nr=nr+1;
        if (nr%m==0) cout<<nr;
            else
            cout<<"-1";
    }

    return 0;
}

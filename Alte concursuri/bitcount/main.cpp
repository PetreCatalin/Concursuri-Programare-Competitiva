#include <iostream>

using namespace std;

int nr,n;

int main()
{
    cin>>n;
    while (n!=0) {
        if (n%2==1) ++nr;
        n=n/2;
    }

    cout<<nr;

    return 0;
}

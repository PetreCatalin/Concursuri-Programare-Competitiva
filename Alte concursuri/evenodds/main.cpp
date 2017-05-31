#include <iostream>

using namespace std;

long long n,k,nr;

int main()
{
    cin>>n>>k;

    if (n%2==0) {
        if (k<=n/2) {
            nr=k*2-1;
            cout<<nr;
        }
        else {
            nr=(k-n/2)*2;
            cout<<nr;
        }
    }

    else {
        if (k<=n/2+1) {
            nr=k*2-1;
            cout<<nr;
        }
        else {
            nr=(k-n/2-1)*2;
            cout<<nr;
        }
    }

    return 0;
}

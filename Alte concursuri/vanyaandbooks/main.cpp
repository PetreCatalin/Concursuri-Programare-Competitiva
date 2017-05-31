#include <iostream>

using namespace std;

long long n,rez,p,nr;

int main()
{
    cin>>n;
    if (n<10) cout<<n;
    else {
            rez=9;
            p=10;
            nr=2;
            while (p*10<=n) {
                rez+=(p*10-p)*nr;
                ++nr;
                p=p*10;
            }
        rez+=(n-p+1)*nr;
        cout<<rez;
    }
    return 0;
}

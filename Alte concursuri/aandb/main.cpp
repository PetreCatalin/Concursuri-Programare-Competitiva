#include <iostream>

using namespace std;

long n,m,t;

int main()
{
    cin>>n>>m;
    while (n>0 &&m>0 &&n+m>=3) {
            if (n<m*2) {
                --n;
                m-=2;
            }
            else {
            n-=2;
            --m;
            }
            ++t;
    }
    cout<<t;

    return 0;
}

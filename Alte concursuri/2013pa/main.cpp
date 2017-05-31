#include <iostream>

using namespace std;

long long a,b,t,nr;

int main()
{
    cin>>a>>b;
    t=a;
    nr=a;
    while (a>=b) {
        nr+=t/b;
        t=a/b+a%b;
        a=t;
    }

    cout<<nr;

    return 0;
}

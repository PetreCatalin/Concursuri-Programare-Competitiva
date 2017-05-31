#include <iostream>

using namespace std;

long long m,a,ok,init[100005];

int main()
{
    cin>>a>>m;

    ok=1;
    init[a%m]=1;
    while (a%m!=0) {
        a=(a+a%m)%m;
        if (init[a%m]==1) break;
        else
        init[a%m]=1;
    }

    if (a%m==0) ok=0;

    if (ok==1) cout<<"No";
    else
    cout<<"Yes";

    return 0;
}

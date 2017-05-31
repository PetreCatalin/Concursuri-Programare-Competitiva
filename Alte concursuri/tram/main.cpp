#include <iostream>

using namespace std;

long n,x,y,maxim,s,i;

int main()
{
    cin>>n;
    for (i=1;i<=n;i++) {
        cin>>x>>y;
        s=s-x+y;
        if (s>maxim) maxim=s;
    }

    cout<<maxim;

    return 0;
}

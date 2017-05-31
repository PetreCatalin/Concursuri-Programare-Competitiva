#include <iostream>

using namespace std;

int nr,x,k,i,n,v[105],t;

int main()
{
    cin>>n>>k;
    for (i=1;i<=n;i++) {
        cin>>v[i];
        if (i==k) nr=v[i];
        if (v[i]==nr) x=i;
    }

    if (nr>0) cout<<x;
    else {
    for (i=1;i<=n;i++)
        if (v[i]>0) t++;
    cout<<t;
    }

    return 0;
}

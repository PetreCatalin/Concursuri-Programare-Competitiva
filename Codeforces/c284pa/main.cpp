#include <iostream>

using namespace std;

long long n,x,a,b,i,nr,rez;

int main()
{
    cin>>n>>x;
    nr=1;
    for (i=1;i<=n;++i) {
        cin>>a>>b;
        while (nr+x<=a) nr+=x;
        rez=rez+b-nr+1;
        nr=b+1;
    }

    cout<<rez;

    return 0;
}

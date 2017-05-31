#include <iostream>

using namespace std;

long n,i,s,v[100005],m,e,nr;

int main()
{
    cin>>n;
    for (i=1;i<=n;++i) {
            cin>>v[i];
            nr=e+v[i-1]-v[i];
            if (nr<=0) {
                    m+=nr*(-1);
                    e=0;
            }
            else
            e=nr;
    }
    cout<<m;
    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int maxim,nr,i,x,ok,nrcifre;
    maxim=0;nr=0;
    cin>>x;
    while (x!=13) {
        ok=1;
        if (x==1) ok=0;
        else {
        for (i=2;i<=floor(sqrt(x));++i)
            if (x%i==0) {ok=0;break;}
        }
        if (ok==1) {++nr;if (x>maxim) maxim=x;}
        cin>>x;
    }

    cout<<nr<<' '<<maxim<<' ';
    nrcifre=0;
    while (maxim!=0) {
            maxim=maxim/10;
            ++nrcifre;
    }
    cout<<nrcifre;

    return 0;
}

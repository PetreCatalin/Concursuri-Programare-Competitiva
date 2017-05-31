#include <iostream>
#include <vector>

using namespace std;

long long n,nr,inc,sf,i,sf1,v[100000];
bool ok;

int main()
{
    cin>>n;
    if (n==4) cout<<'1';
    else
    if (n==7) cout<<'2';
    else {
    nr=2;
    v[1]=4;
    v[2]=7;
    inc=1;
    sf=2;sf1=2;
    ok=true;
    while (ok==true) {
        for (i=inc;i<=sf;++i) {
            ++sf1;
            v[sf1]=v[i]*10+4;
            if (v[sf1]==n) {ok=false;cout<<sf1;break;}
            ++sf1;
            v[sf1]=v[i]*10+7;
            if (v[sf1]==n) {ok=false;cout<<sf1;break;}
        }
        inc=sf+1;
        sf=sf1;
    }
    }
    return 0;
}

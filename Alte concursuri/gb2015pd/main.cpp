#include <bits/stdc++.h>

using namespace std;

long long a,b,x,nr,p,k;

int main()
{
    cin>>a>>b;
    x=1;
    while (x<=a) x*=2;

     p=x;
            --p;
            k=1;
            while (k*2<x &&p-k>=a) {
                    if (p-k>=a &&p-k<=b) ++nr;
                    k*=2;
            }
            x=x*2;

    while (x/2<=b) {
            p=x;
            --p;
            k=1;
            while (k*2<x &&p-k>=a) {
                    if (p-k>=a &&p-k<=b) ++nr;
                    k*=2;
            }
            x=x*2;
    }

    cout<<nr;

    return 0;
}

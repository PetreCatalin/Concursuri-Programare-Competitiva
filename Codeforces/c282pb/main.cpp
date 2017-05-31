#include <iostream>
#include <cmath>

using namespace std;

long long a,b,nr,i,x;

int main()
{
    cin>>a>>b;
    if (a==b) cout<<"infinity";
    else
    if (a<b)
        cout<<'0';
    else {
        nr=a-b;
        for (i=1;i<=trunc(sqrt(nr));++i) {
            if (nr%i==0 &&i>b) ++x;
            if (nr%i==0 &&(nr/i)!=i &&nr/i>b) ++x;
        }
        cout<<x;
    }
    return 0;
}

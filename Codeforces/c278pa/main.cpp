#include <iostream>
#include <algorithm>

using namespace std;

long long n,x,ok,nr,ok1;

int main()
{
    cin>>n;
    x=n;
    ok1=0;
     while (ok1==0) {
         ++n;
         ++nr;
         ok=0;
         x=n;
         while (x!=0) {
             if (x%10==8 ||x%10==-8) {ok=1;ok1=1;break;}
             x=x/10;
         }
     }
     cout<<nr;

    return 0;
}

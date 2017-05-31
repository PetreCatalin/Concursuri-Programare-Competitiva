#include <iostream>

using namespace std;

long long n,nr;

int main()
{
   cin>>n;
   while (n>0) {
       if (n%10==4 ||n%10==7) nr++;
       n=n/10;
   }

   if (nr==4 || nr==7) cout<<"YES";
   else
   cout<<"NO";

    return 0;
}

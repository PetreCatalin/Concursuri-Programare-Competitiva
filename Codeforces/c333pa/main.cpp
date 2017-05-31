#include <iostream>
#include <cmath>

using namespace std;

long long n,bx,m,by,a[100],b[100],i,nr1,nr2;

int main()
{
    cin>>n>>bx;
    for (i=1;i<=n;++i)
        cin>>a[i];
    cin>>m>>by;
    for (i=1;i<=m;++i)
        cin>>b[i];

    for (i=n;i>=1;--i) {
        nr1+=ceil(pow(bx,n-i))*a[i];
        //cout<<pow(bx,n-i)<<'\n';
    }

      for (i=m;i>=1;--i) {
        nr2+=ceil(pow(by,m-i))*b[i];
        //cout<<pow(by,m-i)<<'\n';
      }

    if (nr1==nr2) cout<<'=';
    if (nr1<nr2) cout<<'<';
    if (nr1>nr2) cout<<'>';


    return 0;
}

#include <iostream>

using namespace std;

long n,m,n1,m1,nr,mini,j,x,v[30000];

void sub(long n,long nr)
{
    if (n>1)
    if (v[n-1]>nr+1 ||v[n-1]==0) {
         v[n-1]=nr+1;
        sub(n-1,nr+1);
    }
    if (n<m)
    if (v[n*2]>nr+1 ||v[n*2]==0) {
        v[n*2]=nr+1;
        sub(n*2,nr+1);
    }
    if (n==m &&nr<mini) mini=nr;
}

int main()
{
    cin>>n>>m;
    if (n>=m) cout<<n-m;
    else {
        mini=2000000;
        sub(n,0);
        cout<<mini;
    }
    return 0;
}

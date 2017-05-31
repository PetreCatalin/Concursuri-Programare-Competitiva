#include <iostream>

using namespace std;

int a,b,n,m,nr;

int main()
{
    cin>>n>>m;
    for (a=0;a<=32;a++)
        for (b=0;b<=32;b++) {
        if (a*a+b==n &&a+b*b==m) nr++;
        if (a*a+b>n || a+b*b>m) break;
        }

    cout<<nr;
    return 0;
}

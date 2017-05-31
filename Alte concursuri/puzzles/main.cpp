#include <iostream>
#include <algorithm>

using namespace std;

int n,m,i,minim,a[55];

int main()
{
    cin>>n>>m;
    for (i=1;i<=m;i++)
        cin>>a[i];
    sort(a+1,a+m+1);
    minim=1000;

    for (i=1;i<=m-n+1;i++)
        if (a[i+n-1]-a[i]<minim) minim=a[i+n-1]-a[i];

    cout<<minim;

    return 0;
}

#include <iostream>

using namespace std;

int n,x,y,z,sx,sy,sz,i;

int main()
{
    cin>>n;
    for (i=1;i<=n;i++) {
        cin>>x>>y>>z;
        sx=sx+x;
        sy=sy+y;
        sz=sz+z;
    }

    if (sx==0 &&sy==0 &&sz==0) cout<<"YES";
    else
    cout<<"NO";

    return 0;
}

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

long long n,x,y,i,minx,miny,maxx,maxy,nr,nr1;

int main()
{
    cin>>n;
    cin>>x>>y;
    minx=x;maxx=x;miny=y;maxy=y;
    for (i=2;i<=n;i++) {
        cin>>x>>y;
        if (x<minx) minx=x;
        if (x>maxx) maxx=x;
        if (y>maxy) maxy=y;
        if (y<miny) miny=y;
    }

    nr=abs(minx-maxx);
    nr1=abs(miny-maxy);
    if (nr1>nr) cout<<nr1*nr1;
    else
    cout<<nr*nr;

    return 0;
}

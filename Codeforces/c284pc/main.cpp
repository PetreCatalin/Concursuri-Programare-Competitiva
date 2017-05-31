#include <iostream>
#include <algorithm>

using namespace std;

long long x1,y1,x2,y2,a1,b1,c1,rez,a2,b2,c2,n,i,maxx,maxy,minx,miny;
long double x,y;

int main()
{
    cin>>x1>>y1;
    cin>>x2>>y2;
    a1=y1-y2;
    b1=x2-x1;
    c1=x1*y2-x2*y1;

    maxx=max(x1,x2);
    minx=min(x1,x2);
    maxy=max(y1,y2);
    miny=min(y1,y2);

    cin>>n;
    rez=0;
    for (i=1;i<=n;++i) {
        cin>>a2>>b2>>c2;
        x=(long double) (c2*b1-c1*b2)/(a1*b2-a2*b1);
        if (b1!=0)
        y=( long double) ((-1)*c1-a1*x)/b1;
        else
        y=0;
        if (minx<=x &&miny<=y &&maxx>=x &&maxy>=y) ++rez;
    }

    cout<<rez;
    return 0;
}

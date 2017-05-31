#include <fstream>
#include <cmath>

using namespace std;

long w,h,l1,l2,nr,i,j,x,y,t,k;
long double dist;

int main()
{
    ifstream f("banner.in");
    ofstream g("banner.out");
    f>>w>>h>>l1>>l2;
    for (i=0;i<=w;i++)
        for (j=0;j<=h;j++)
            for (k=0;k<=w;k++)
            if (k!=i)
                for (t=0;t<=h;t++)
                    if (i!=k &&j!=t &&k-i!=t-j &&(k-i)*(-1)!=(t-j)) {
                    x=(k-i)*(k-i);
                    y=(t-j)*(t-j);
                    dist=sqrt(x+y);
                    if (dist>=l1 &&dist<=l2) {nr++;}//g<<i<<' '<<j<<' '<<k<<' '<<t<<'\n';}
                }

    g<<nr/2;

    f.close();
    g.close();
    return 0;
}

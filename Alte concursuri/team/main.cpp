#include <iostream>

using namespace std;

int n,x,nr,p,i,j;

int main()
{
    cin>>n;
    for (i=1;i<=n;i++) {
        nr=0;
        for (j=1;j<=3;j++) {
            cin>>x;
            if (x==1) nr++;
        }
        if (nr>=2) p++;
    }

    cout<<p;

    return 0;
}

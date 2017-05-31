#include <iostream>

using namespace std;

int nr,n,i,v[100],x;

int main()
{
    nr=0;
    cin>>n;
    for (i=1;i<=n;i++) {
        cin>>x;
        nr++;
        if (v[x]==0) v[x]=nr;
            else {
                if (v[x]==nr-1) nr=nr-2;
                else
                {
                    cout<<"NU";break;
                }
            }
    }

    if (nr==0) cout<<"DA";

    return 0;
}

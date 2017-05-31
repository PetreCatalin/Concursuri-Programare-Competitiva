#include <iostream>

using namespace std;

int n,nr,i;
char x,y;

int main()
{
    cin>>n;
    cin>>x;
    for (i=2;i<=n;i++) {
        cin>>y;
        if (y==x) nr++;
        else
        {
            x=y;
        }
    }

    cout<<nr;
    return 0;
}

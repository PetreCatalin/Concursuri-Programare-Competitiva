#include <iostream>

using namespace std;

long n,i,nr,a[305];

int main()
{
    cin>>n;
    for (i=1;i<=n;++i)
        cin>>a[i];

    nr=1;
    while (nr<=n) {
        if (nr!=n) {
            if (a[nr]==0) cout<<"R";
        while (a[nr]!=0) {
            cout<<"P";
            --a[nr];
            cout<<"R";
            if (a[nr+1]!=0) {
                cout<<"P";
                --a[nr+1];
            }
            if (a[nr]!=0)
            cout<<"L";
            else
            ++nr;
        }
        }
        if (nr==n)
            while (a[nr]!=0) {
                cout<<"R";
                cout<<"P";
                --a[nr];
                if (a[nr]!=0)
                cout<<"L";
            }
    }

    return 0;
}

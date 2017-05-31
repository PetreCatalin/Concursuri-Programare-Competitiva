#include <iostream>
#include <cstring>

using namespace std;

char c[100005];
long ok,i,nr;

int main()
{
    ok=0;
        cin>>c; nr=strlen(c)-1;
        for (i=0;i<=nr-1;i++) {
            if (c[i]=='0') {
                if (ok==0) ok=1;
                else
                cout<<c[i];
            }
            if (c[i]=='1') cout<<c[i];
        }

    if (c[nr]=='0' &&ok==1) cout<<'0';
    if (c[nr]=='1' &&ok==1) cout<<'1';

    return 0;
}

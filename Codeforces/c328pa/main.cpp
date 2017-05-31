#include <bits/stdc++.h>

using namespace std;

char x,v[10][10];
int a,b,i,j,nr;
bool ok;

int main()
{
    a=10;
    for (i=1;i<=8;++i)
    for (j=1;j<=8;++j)
            cin>>v[i][j];

    ok=false;
    for (i=1;i<=8;++i) {
        for (j=1;j<=8;++j) {
            if (v[i][j]=='W') {
                    nr=i-1;
                    while (v[nr][j]=='.') --nr;
                    if (nr==0) {a=i-1;ok=true;}
            }
            if (ok==true) break;
        }
    if (ok==true) break;
    }

    ok=false;
    for (i=8;i>=1;--i) {
        for (j=1;j<=8;++j) {
        if (v[i][j]=='B') {
            nr=i+1;
            while (v[nr][j]=='.') ++nr;
            if (nr==9) {b=i;ok=true;}
        }
        if (ok==true) break;
    }
    if (ok==true) break;
    }

    b=8-b;
    if (a<=b) cout<<'A';
    else
    cout<<'B';
    return 0;
}

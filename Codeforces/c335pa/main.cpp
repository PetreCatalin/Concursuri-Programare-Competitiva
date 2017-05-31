#include <bits/stdc++.h>

using namespace std;

long long a,b,c,x,y,z,ok,s;

int main()
{
    cin>>a>>b>>c>>x>>y>>z;
    if (a>=x &&b>=y &&c>=z)
            cout<<"Yes";
    else {
            if (a>x) s+=(a-x)/2;
            if (b>y) s+=(b-y)/2;
            if (c>z) s+=(c-z)/2;

            ok=1;
            if (a<x) {
                if (x-a<=s) s=s-(x-a);
                else
                ok=0;
            }
             if (b<y) {
                if (y-b<=s) s=s-(y-b);
                else
                ok=0;
             }
             if (c<z) {
                if (z-c<=s) s=s-(z-c);
                else
                ok=0;
             }

            if (ok==1) cout<<"Yes";
            else
            cout<<"No";
    }
    return 0;
}


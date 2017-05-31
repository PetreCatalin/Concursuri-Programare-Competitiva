#include <bits/stdc++.h>

using namespace std;

long a,b,nr;

int main()
{
    cin>>a>>b;
    nr=min(a,b);
    cout<<nr<<' ';
    if (a<b) {b-=a;nr=b/2;}
    else
    {a-=b;nr=a/2;}
    cout<<nr;
    return 0;
}

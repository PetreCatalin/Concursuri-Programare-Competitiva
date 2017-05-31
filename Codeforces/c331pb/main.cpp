#include <bits/stdc++.h>

using namespace std;

int i,n,b[200005],nr,x,o,o1,j;

#define mod 1000000000

int main()
{
    ofstream g("out.txt");
    cin>>n;
    g<<n<<'\n';
    for (i=1;i<=n;i++)
        if (i%2==1) g<<mod<<' ';
        else
        g<<mod*(-1)<<' ';
    return 0;
}

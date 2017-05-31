#include <bits/stdc++.h>

using namespace std;

long i,j,k,n,m,maxim,a[101][101],s;

int main()
{


cin>>n;
for (i=1;i<=n;++i)
	for (j=1;j<=n;++j)
	cin>>a[i][j];

for (i=1;i<=n-1;++i)
        s=s+a[i][i+1];

for (i=2;i<=n;++i)
        s=s+a[i][i-1];

cout<<s;


        return 0;
}

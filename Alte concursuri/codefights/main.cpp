#include <bits/stdc++.h>

using namespace std;


int n,i,a[1000];

inline bool cmp(int x,int y)
{
    return x>y;
}

int main()
{
   ifstream f("in.txt");
   ofstream g("out.txt");
   f>>n;
   for (i=1;i<=n;++i)
    f>>a[i];
   sort(a+1,a+n+1,cmp);
   for (i=1;i<=n;++i)
    g<<i<<' '<<a[i]/1000<<'.'<<a[i]%1000<<'\n';
   return 0;
}
